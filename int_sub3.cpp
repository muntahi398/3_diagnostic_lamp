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


class Listener
{

ros::NodeHandle n;

diagnostic_light::Num cust_msg;
int p,q; bool bools[3];

public:
  //void callback(const std_msgs::Int8::ConstPtr& msg);
  //void callback(const std_msgs::Int8::ConstPtr& msg);
  
  ros::Subscriber = n.subscribe("chatter", 1000, &Listener::callback, this);
  
  void callback(const std_msgs::Int8::ConstPtr& msg)
  {
  ROS_INFO("I heard: [%d]", msg->data);
  ROS_INFO("I heard: [%d]  --- %d ", cust_msg.num, cust_msg.bool3);
  p=msg->data;
     std::bitset<(8)> bits(p);
     std::cout << bits << std::endl;

     //use operator[] to access individual bits
     std::cout <<"First bit"<<bits[0]<<"2nd bit="<<bits[1]<<"3rd bit="<< bits[2] << std::endl;
   }
  
};

int main(int argc, char **argv) {
    std::cout << "subscribe messages" << std::endl;
    ros::init(argc, argv, "subscribe messages");
    Listener lc;
    ros::spin();
    std::cout << "Stopping the subscribe messages." << std::endl;

    return 0;
}
