#ifndef YOUR_SOLUTION_SRC_SPIN_SLOW_UPDATE_H_ //checks to see if MACRO already exists
#define YOUR_SOLUTION_SRC_SPIN_SLOW_UPDATE_H_ //start of block to define MACRO (replaces text)

#include "rclcpp/rclcpp.hpp" //needed files
#include "std_msgs/msg/float64_multi_array.hpp" //gets variable
using ArrayMsg = std_msgs::msg::Float64MultiArray; //shortens variable name
//std_msgs is a package, msg is a namespace so var, functions don't get mixed up
class SlowSolution : public rclcpp::Node { //gets the methods in node, :: = look inside
 public:
  SlowSolution();
 private:
  // your code here
  void timer_callback ();
  void topic_callback (const ArrayMsg message); //const value of ArrayMsg?
  ArrayMsg m;
  rclcpp::Subscription<ArrayMsg>::SharedPtr s;
  rclcpp::TimerBase::SharedPtr t;
rclcpp::Publisher<ArrayMsg>::SharedPtr p;
};

#endif //YOUR_SOLUTION_SRC_SPIN_SLOW_UPDATE_H_
//ends block to define MACRO

