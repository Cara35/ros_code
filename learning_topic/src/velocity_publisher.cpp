
/*

    发布者的四个步骤：

    1、初始化ROS节点
    2、注册节点信息
    3、创建消息数据
    4、发布消息

*/


#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char *argv[])
{
    // ROS节点初始化
    ros::init(argc, argv, "velocity_publisher");// 节点名称,注意不可以重复

    // 创建节点句柄,用来管理节点的资源
    ros::NodeHandle nh;

    // 创建一个Publisher，发布名为/turtle1/cmd_vel的topic，消息的数据类型为geometry_msgs::Twist，话题名为/turtle1/cmd_vel，队列长度10
    ros::Publisher turtle_vel_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    // 设置循环的频率
    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok())
    {
        // 初始化一个Twist类型的消息
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x = 0.5;
        vel_msg.angular.z = 0.5;

        // 发布消息
        turtle_vel_pub.publish(vel_msg);
        ROS_INFO("Publish turtle velocity command[%0.2f m/s, %0.2f rad/s]", vel_msg.linear.x, vel_msg.angular.z);

        // 按照循环频率延迟
        loop_rate.sleep();
    }

    return 0;
}

