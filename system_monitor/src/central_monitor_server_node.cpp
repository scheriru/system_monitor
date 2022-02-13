#include "central_monitor_server.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "central_monitor_server_node");
    SystemMonitorServer server;
    ros::Rate loop_rate(200);

    ROS_INFO("Central Monitor Server Node Started.");
    
    while(ros::ok())
    {
        server.run();
        ros::spinOnce();
        loop_rate.sleep();
    }

  return 0;
}