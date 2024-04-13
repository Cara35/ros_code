#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_srvs/Trigger.h>
#include <turtlesim/Spawn.h>


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "turtles");
    ros::NodeHandle nh;
    ros::Publisher turtle_pub_1 = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
    ros::Publisher turtle_pub_2 = nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel", 10);
    ros::service::waitForService("/spawn");
    ros::ServiceClient add_turtle = nh.serviceClient<turtlesim::Spawn>("/spawn");

    turtlesim::Spawn srv;
    srv.request.x = 8.0; 
    srv.request.y = 4.0; 
    srv.request.name = "turtle2";
    add_turtle.call(srv);
    ROS_INFO("Spawn turtle2 successfully [name:%s]", srv.response.name.c_str());
    ros::Rate loop_rate(10);
    
    while (ros::ok())
    {

            geometry_msgs::Twist vel_msg_1;
            vel_msg_1.linear.x = 0.5;
            vel_msg_1.angular.z = 0.5;
            turtle_pub_1.publish(vel_msg_1);

            geometry_msgs::Twist vel_msg_2;
            vel_msg_2.linear.x = 0.5; 
            vel_msg_2.angular.z = 0.5; 
            turtle_pub_2.publish(vel_msg_2);


            loop_rate.sleep();
    }

    return 0;
}
