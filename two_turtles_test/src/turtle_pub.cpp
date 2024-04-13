#include <ros/ros.h>
#include <geometry_msgs/Twist.h>


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "turtle_pub");
    ros::NodeHandle nh;
    ros::Publisher turtle_one_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
    ros::Rate loop_rate(10);
    int count = 0;
    while (ros::ok())
    {
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x = 0.5;
        vel_msg.angular.z = 0.5;

        turtle_one_pub.publish(vel_msg);
        ROS_INFO("Publish turtle1 command[%0.2f m/s, %0.2f rad/s]", vel_msg.linear.x, vel_msg.angular.z);

        loop_rate.sleep();
    }
    return 0;
}
