
/*

    订阅者的四个步骤：

    1、初始化ROS节点
    2、订阅需要的话题
    3、接受到话题消息进入到回调函数
    4、在回调函数中完成消息的处理

*/



#include <ros/ros.h>
#include "turtlesim/Pose.h"

// 接收到订阅的消息后，会进入回调函数
void poseCallback(const turtlesim::Pose::ConstPtr& msg)
{
    // 将接收到的消息打印出来
    ROS_INFO("Turtle pose: x=%0.6f, y=%0.6f", msg->x, msg->y);
}

int main(int argc, char *argv[])
{
    // 初始化ROS节点
    ros::init(argc, argv, "pose_subscriber");

    // 创建节点句柄
    ros::NodeHandle nh;

    // 创建订阅者，订阅/turtle1/pose话题，注册回调函数poseCallback
    // 通过Subscribe这个类创建一个pose_sub对象
    ros::Subscriber pose_sub = nh.subscribe("/turtle1/pose", 10, poseCallback);

    // 循环等待回调函数
    ros::spin();

    return 0;
}
