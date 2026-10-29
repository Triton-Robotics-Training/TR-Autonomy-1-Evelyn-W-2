#include "spin_slow_update.h"
#include <chrono>
using namespace std::chrono_literals; //is this really needed?


int main(int argc, char *argv[]) {
 rclcpp::init(argc, argv);
 rclcpp::spin(std::make_shared<SlowSolution>());
 rclcpp::shutdown();
 return 0;
}
//no public or private here!
SlowSolution::SlowSolution() : Node("slowsolution") { //constructor for SlowSolution class
//RCLCPP_INFO(this->get_logger(), "Remove this statement from spin_slow_update.cpp");
p = this->create_publisher<ArrayMsg> ("predictedpos", 10); //publish to
s = this->create_subscription<ArrayMsg>("measuredpos", 10, std::bind(&SlowSolution::topic_callback, this, std::placeholders::_1)); //subscribe to
//s2 = this->create_subscription<ArrayMsg>("/spinnything/measuredvel", 10, _1);
t = this->create_wall_timer (500ms, std::bind(&SlowSolution::timer_callback, this));
}


void SlowSolution::timer_callback () //for publisher
{
 p->publish (m);
 //RCLCPP_INFO(this->get_logger(), "Published '%f'", m.data[0]);
}


void SlowSolution::topic_callback (const ArrayMsg message) //for subscriber
{
m = message;
//RCLCPP_INFO(this->get_logger(), "Subscribed to '%f'", m.data[0]);
}
 // your code here






// your code here

