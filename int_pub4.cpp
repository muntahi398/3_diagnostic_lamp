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
    bool init();
    void pub_data(int num);
private:
    ros::NodeHandle nh_;
    ros::Publisher pub_2;
    diagnostic_light::Num cust_msg;
    ros::Timer timer1;
    void timer_cb();
    int loop_count;
};
node_class::node_class()
{
    loop_count = 0;
    pub_2= (nh_.advertise<diagnostic_light::Num>("chatter", 10));
}

void node_class::timer_cb() {
    ROS_INFO("hi");
    pub_data(loop_count);
    loop_count++;

}

bool node_class::init()
{
    cust_msg.num = 15;
    cust_msg.bool3 = {1,0,1};
    timer1 = nh_.createTimer(ros::Duration(0.1), &node_class::timer_cb, this );

    return True;
}

void node_class::pub_data(int num) {
    cust_msg.num = num;
    pub_2.publish(cust_msg);

}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "node_class");
    node_class this_node;
    bool init_worked = this_node.init();

    if (not init_worked) {
        ROS_ERROR("Could not initialize main class. Exiting.");
        return -1;
    }

    ros::spin();

    return 0;
}

//
// Created by muntahi on 17.07.18.
//

