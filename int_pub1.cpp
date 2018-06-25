#include "ros/ros.h"

#include "std_msgs/Int32.h"
#include "std_msgs/Int8.h"
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/PoseStamped.h>
#include <sensor_msgs/CameraInfo.h>
#include <iostream>

float pos_x, pos_y,pos_z, pos_x1;
//void commandpos(const geometry_msgs::PoseStampedConstPtr& msg)
//{

//pos_x= msg->pose.position.x ; //    ->position->x;
//pos_x1= pos_x;
//pos_y= msg->pose.position.y;
//pos_z= (msg->pose.position.z)*10;

//ros::INFO("hi");
//std::cout<<pos_x<<"	"<<pos_y<<"	"<<pos_z<<"	"<<std::endl;
 
//}

int main(int argc, char **argv)

{

    ros::init(argc, argv,"talker");

    ros::NodeHandle node_obj;
    //ros::Subscriber nh_;
    //nh_ = node_obj.subscribe("/visp_auto_tracker/object_position", 3, commandpos);

    //ros::Publisher number_publisher =node_obj.advertise<std_msgs::Float64>("axis3_robot/joint2_position_controller/command",10);
    ros::Publisher number_publisher =node_obj.advertise<std_msgs::Int8>("bool3_pub",10);
    //ros::Publisher number_publisher =node_obj.advertise<std_msgs::Int32>("/numbers",10);

    ros::Rate loop_rate(10);
    
    //
    unsigned int bool_data = 0;//\0;
    bool bools[8]={0};// = 2;
    bools[0] =1;
    for(int i = 0; i < 8; ++i) bool_data |= ((unsigned int) bools[i]) << i;
    

    float number_count = 0;

    while (ros::ok())

	{
	
	std_msgs::Int8 msg;

	msg.data = bool_data; // pos_y+1; //0.3; //number_count;

	ROS_INFO("%d",msg.data);

	number_publisher.publish(msg);

	ros::spinOnce();

	loop_rate.sleep();

	//++number_count;

	}

return 0;

}
