#include "spin_sol.h"
#include <chrono>
using namespace std::chrono_literals; //is this really needed?, when do we want smart pointers?

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv); 
  rclcpp::spin(std::make_shared<SpinSolution>());
  rclcpp::shutdown();
  return 0;
}

//your code here
SpinSolution::SpinSolution() : Node("spinsolution") {
  //RCLCPP_INFO(this->get_logger(), "Remove this statement from spin_sol.cpp");
  p = this->create_publisher<ArrayMsg> ("predictedpos", 10); //publish to
  s1 = this->create_subscription<ArrayMsg>("measuredpos", 10, std::bind(&SpinSolution::topic_callback, this, std::placeholders::_1)); //subscribe to
  s2 = this->create_subscription<ArrayMsg>("measuredvel", 10, std::bind(&SpinSolution::topic_callback2, this, std::placeholders::_1));
  t = this->create_wall_timer (5ms, std::bind(&SpinSolution::timer_callback, this));
  position.data = {0, 0};
  velocity.data = {0, 0};
  current = this->get_clock()->now();
 past = this->get_clock ()->now ();
  // your code here
}
void SpinSolution::timer_callback () //for publisher
{

 current = this->get_clock()->now();
 duration = current - past;
 time = duration.seconds ();
 x = position.data[0] + time * velocity.data[0];
 y = position.data[1] + time * velocity.data[1];
 position.data[0] = x;
 position.data[1] = y;
 last.data = {x, y};
 p->publish (last);
 past = current;
 
 //RCLCPP_INFO(this->get_logger(), "Published '%f'", m.data[0]);
}


void SpinSolution::topic_callback (const ArrayMsg pos) //for subscriber
{
position = pos;
//RCLCPP_INFO(this->get_logger(), "Subscribed to '%f'", m.data[0]);
}
void SpinSolution::topic_callback2 (const ArrayMsg vel)
{
velocity = vel;
}
 // your code here
