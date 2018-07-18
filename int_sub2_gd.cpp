
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
diagnostic_light::Num cust_msg;
bool *boolean[3], bool1, bool2, bool3;
public:
  void callback(const diagnostic_light::Num::ConstPtr& msg);
};

void Listener::callback(const diagnostic_light::Num::ConstPtr& msg) 
{

	ROS_INFO("I heard: [%d]  --- [%d] ", msg->num, msg->bool3);
	bool1= msg->bool3[0];
	bool2= msg->bool3[1];
	bool3= msg->bool3[2];
	std::cout << bool1 <<" | "<< bool2 <<" | "<<  bool3 <<" | "<<std::endl;

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener_class");
  ros::NodeHandle n;


  Listener listener;
  ros::Subscriber sub = n.subscribe("chatter", 1000, &Listener::callback, &listener);
    while(ros::ok())
        ros::spinOnce();
    return 0;
}




