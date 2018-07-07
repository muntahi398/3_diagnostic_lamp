#include "ros/ros.h"
#include "std_msgs/Int8.h"
#include "diagnostic_light/Num.h"
#include <iostream>
#include "std_msgs/String.h"
#include <sstream>
class node_class
{
public:
    node_class();
private:
    ros::NodeHandle nh_;
    ros::Publisher pub_2;
    std_msgs::String msg;
    ros::Rate loop_rate;
    diagnostic_light::Num cust_msg;
};
node_class::node_class():			// so it seems to be initialization list of constructor
    pub_2(nh_.advertise<diagnostic_light::Num>("chatter", 10)),  // Bujhi nai !! egula ki?
    loop_rate(1) 
{
    msg.data = "hello world";
	cust_msg.num = 15;
	cust_msg.bool3 = {1,0,1};
    while(ros::ok())
    {
        //pub_.publish(
        pub_2.publish(cust_msg);
        loop_rate.sleep();
    }
}
int main(int argc, char **argv)
{
    ros::init(argc, argv, "node_class");
    node_class this_node;
    while(ros::ok())
        ros::spinOnce();
    return 0;
}


