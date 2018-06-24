#include "ros/ros.h"

//#include "std_msgs/Int32.h"
#include "std_msgs/Int8.h"
//#include <geometry_msgs/Twist.h>
//#include <geometry_msgs/PoseStamped.h>
//#include <sensor_msgs/CameraInfo.h>
#include <iostream>
#include <bitset>

int p;

void listening(const std_msgs::Int8::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d]", msg->data);
  p=msg->data;
     std::bitset<(8)> bits(p);
     std::cout << bits << std::endl;

     //use operator[] to access individual bits
     std::cout <<"First bit"<<bits[0]<<"2nd bit="<<bits[1]<<"3rd bit="<< bits[2] << std::endl; 
}

int main(int argc, char **argv)

{

    ros::init(argc, argv,"listener");

    ros::NodeHandle node_obj;
    ros::Subscriber nh_;
    nh_ = node_obj.subscribe("/bool3_pub", 3, listening);

    //ros::Publisher number_publisher =node_obj.advertise<std_msgs::Float64>("axis3_robot/joint2_position_controller/command",10);
  //  ros::Publisher number_publisher =node_obj.advertise<std_msgs::Int8>("bool3_pub",10);
    //ros::Publisher number_publisher =node_obj.advertise<std_msgs::Int32>("/numbers",10);

    ros::Rate loop_rate(10);
    
    
    

    float number_count = 0;

  //  while (ros::ok())

//	{
	
//	std_msgs::Int8 msg;

//	msg.data = bool_data; // pos_y+1; //0.3; //number_count;

	//ROS_INFO("%d",msg.data);

//	number_publisher.publish(msg);

	ros::spin();

//	loop_rate.sleep();

	//++number_count;

//	}

return 0;

}
