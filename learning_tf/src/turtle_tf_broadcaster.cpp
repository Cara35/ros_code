



#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <turtlesim/Pose.h>

std::string turtle_name;

void poseCallback(const turtlesim::PoseConstPtr& msg)
{
  //创建tf广播器
  static tf::TransformBroadcaster br;

  //初始化tf数据
  tf::Transform transform;
  transform.setOrigin( tf::Vector3(msg->x, msg->y, 0.0) );
  tf::Quaternion q;//四元数
  q.setRPY(0, 0, msg->theta);
  transform.setRotation(q);

  //广播world与海归坐标系之间的tf数据
  br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", turtle_name));
}

int main(int argc, char *argv[])
{
    //初始化ros节点
    ros::init(argc, argv, "turtle_tf_broadcaster");

    //输入参数作为海归的名字
    if (argc != 2)
    {
        ROS_ERROR("need turtle name as argument");
        return -1;
    }
    turtle_name = argv[1];

    //订阅海归的位姿话题
    ros::NodeHandle node;
    ros::Subscriber sub = node.subscribe(turtle_name + "/pose", 10, &poseCallback);

    //循环等待回调函数
    ros::spin();



    return 0;

}
  

