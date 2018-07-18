
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Int8.h"
#include "diagnostic_light/Num.h"
#include <iostream>
#include <bitset>

class Listener {
private:
    ros::NodeHandle n;
    diagnostic_light::Num cust_msg;
    ros::Subscriber sub;
    bool *boolean[3], bool1, bool2, bool3;
    int value;
public:
    void callback(const diagnostic_light::Num::ConstPtr &msg);
    void test();
};

void Listener::callback(const diagnostic_light::Num::ConstPtr &msg) {
    bool1 = msg->bool3[0];
    bool2 = msg->bool3[1];
    bool3 = msg->bool3[2];
    value = msg->num;
    ROS_INFO_STREAM("bools: |" << bool1 << " | " << bool2 << " | " << bool3 );
}
void Listener::test() {
     sub= n.subscribe("chatter", 10, &Listener::callback, this);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "listener_class");
    Listener listener;
    listener.test();
    ros::spin();
    return 0;
}




