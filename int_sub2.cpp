
#include "ros/ros.h"
#include "std_msgs/String.h"


#include "std_msgs/Int32.h"
#include "std_msgs/Int8.h"
#include "diagnostic_light/Num.h"
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/PoseStamped.h>
#include <sensor_msgs/CameraInfo.h>
#include <iostream>
#include <bitset>
/**
 * This tutorial demonstrates subscribing to a topic using a class method as the callback.
 */

// %Tag(CLASS_WITH_DECLARATION)%
class Listener
{
diagnostic_light::Num cust_msg;
bool *boolean[3];
public:
  void callback(const diagnostic_light::Num::ConstPtr& msg);
};
// %EndTag(CLASS_WITH_DECLARATION)%

void Listener::callback(const diagnostic_light::Num::ConstPtr& msg) 
{
//  ROS_INFO("I heard: [%s]", msg->data.c_str());
  ROS_INFO("I heard: [%d]  --- [%d] ", msg->num, msg->bool3);
  boolean = msg->bool3;
  std::cout <<"First bit"<<boolean[0]<<"2nd bit="<<boolean[1]<<"3rd bit="<< boolean[2] << std::endl;
  
   // std::bitset<(8)> bits(p);
   //  std::cout << bits << std::endl;

     //use operator[] to access individual bits
    // std::cout <<"First bit"<<bits[0]<<"2nd bit="<<bits[1]<<"3rd bit="<< bits[2] << std::endl;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener_class");
  ros::NodeHandle n;

// %Tag(SUBSCRIBER)%
  Listener listener;
  ros::Subscriber sub = n.subscribe("chatter", 1000, &Listener::callback, &listener);
// %EndTag(SUBSCRIBER)%

  ros::spin();

  return 0;
}




