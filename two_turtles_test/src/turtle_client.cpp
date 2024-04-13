#include <ros/ros.h>
#include <turtlesim/Spawn.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>

int main(int argc, char *argv[])
{

    ros::init(argc,argv,"turtle_client");
    ros::NodeHandle node;

    ros::service::waitForService("/spawn");
    ros::ServiceClient add_turtle = node.serviceClient<turtlesim::Spawn>("/spawn");   

    turtlesim::Spawn srv;
    srv.request.x = 2.0;
    srv.request.y = 2.0;
    srv.request.name = "turtle2";
    add_turtle.call (srv);

    ROS_INFO("Spawn turtle successfully [name:%s]",srv.response.name.c_str());
    
    ros::Publisher velocity_publisher = node.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel", 10);
    ros::Rate loop_rate(1);
         
    geometry_msgs::Twist vel_msg;
    vel_msg.linear.x = 0.5;
    vel_msg.angular.z = 0.5;

    while (ros::ok())
    {
        velocity_publisher.publish(vel_msg);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}