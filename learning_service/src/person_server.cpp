




#include <ros/ros.h>
#include "learning_service/Person.h"

//service回调函数,输入参数req,输出参数res
bool personCallback(learning_service::Person::Request &req, learning_service::Person::Response &res)
{
    //显示请求数据
    res.result = "ok";
    //设置反馈数据
    return true;
}


int main(int argc, char *argv[])
{
    //ros节点初始化
    ros::init(argc,argv,"person_server");

    //创建节点句柄
    ros::NodeHandle nh;

    //创建一个名字为/show_person的server，注册回调函数personCallback
    ros::ServiceServer person_server = nh.advertiseService("/show_person",personCallback);

    //循环等待回调函数
    ROS_INFO("Ready to show person informaton.");
    ros::spin();


    return 0;
}
