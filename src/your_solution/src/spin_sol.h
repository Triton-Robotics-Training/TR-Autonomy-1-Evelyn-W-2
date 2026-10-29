#ifndef YOUR_SOLUTION_SRC_SPIN_SOL_H_
#define YOUR_SOLUTION_SRC_SPIN_SOL_H_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
using ArrayMsg = std_msgs::msg::Float64MultiArray;

class SpinSolution : public rclcpp::Node {
 public:
  SpinSolution();
  rclcpp::Duration duration{0,0};
 private:
    // your code here
  void timer_callback ();
  void topic_callback (const ArrayMsg pos); //const value of ArrayMsg?
  void topic_callback2 (const ArrayMsg vel);
  ArrayMsg velocity;
  ArrayMsg position;
  rclcpp::Subscription<ArrayMsg>::SharedPtr s1;
  rclcpp::Subscription<ArrayMsg>::SharedPtr s2;
  rclcpp::TimerBase::SharedPtr t;
  rclcpp::Time current;
  rclcpp::Time past;
  rclcpp::CallbackGroup::SharedPtr timergroup;
  double time;
  double x;
  double y;
  ArrayMsg last;
rclcpp::Publisher<ArrayMsg>::SharedPtr p;
};

#endif //YOUR_SOLUTION_SRC_SPIN_SOL_H_
