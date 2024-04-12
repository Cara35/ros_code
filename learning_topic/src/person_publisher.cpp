
/*

    发布者的四个步骤：

    1、初始化ROS节点
    2、注册节点信息
    3、创建消息数据
    4、发布消息

*/


#include <ros/ros.h>
#include "learning_topic/Person.h"

int main(int argc, char *argv[])
{
    // ROS节点初始化
    ros::init(argc, argv, "person_publisher");

    // 创建节点句柄,用来管理节点的资源
    ros::NodeHandle nh;

    // 创建一个Publisher，发布名为/person_info的topic，消息类型为learning_topic::Person，队列长度10
    ros::Publisher person_info_pub = nh.advertise<learning_topic::Person>("/person_info", 10);

    // 设置循环的频率
    ros::Rate loop_rate(1);

    int count = 0;
    while (ros::ok())
    {
        // 初始化一个learning_topic::Person类型的消息
        learning_topic::Person person_msg;
        person_msg.name = "Cara";
        person_msg.age  =   18;
        person_msg.sex  = learning_topic::Person::female;


        // 发布消息
        person_info_pub.publish(person_msg);
        
        ROS_INFO("Publish Person Info: name:%s, age:%d, sex:%s", person_msg.name.c_str(), person_msg.age, std::to_string(person_msg.sex).c_str());

        // 按照循环频率延迟
        loop_rate.sleep();
    }

    return 0;
}





