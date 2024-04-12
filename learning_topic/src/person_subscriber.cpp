
/*

    订阅者的四个步骤：

    1、初始化ROS节点
    2、订阅需要的话题
    3、接受到话题消息进入到回调函数
    4、在回调函数中完成消息的处理

*/

#include <ros/ros.h>
#include "learning_topic/Person.h"

// 接收到订阅的消息后，会进入回调函数
void personInfoCallback(const learning_topic::Person::ConstPtr& msg)
{
    // 将接收到的消息打印出来
    ROS_INFO("Subcribe Person info: name: %s  age: %d  sex: %d", msg->name.c_str(), msg->age, msg->sex);
}

int main(int argc, char *argv[])
{
    // 初始化ROS节点
    ros::init(argc, argv, "person_subscriber");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建订阅者，订阅/turtle1/pose话题，注册回调函数poseCallback
    ros::Subscriber person_info_sub = n.subscribe("/person_info", 10, personInfoCallback);

    // 循环等待回调函数
    ros::spin();

    return 0;
}
