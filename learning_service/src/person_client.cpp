


#include <ros/ros.h>
#include "learning_service/Person.h"

int main(int argc, char *argv[])
{
    //初始化ros节点
    ros::init(argc,argv,"person_client");

    //创建节点句柄
    ros::NodeHandle node;

    //发现/spawn服务后，创建一个服务客户端，连接名为/spawn的service
    ros::service::waitForService("/show_person");
    ros::ServiceClient person_client = node.serviceClient<learning_service::Person>("/show_person");

    //初始化learning_service::Person的请求数据
    learning_service::Person person_srv;
    person_srv.request.name = "cara";
    person_srv.request.age = 18;
    person_srv.request.sex = learning_service::PersonRequest::female;

    //请求服务调用
    ROS_INFO("Call service to show person[name: %s, age: %d, sex: %d]", person_srv.request.name.c_str(), person_srv.request.age, person_srv.request.sex);
    person_client.call(person_srv);

    //显示服务调用结果
    ROS_INFO("Show person result : %s", person_srv.response.result.c_str());

    return 0;
}
