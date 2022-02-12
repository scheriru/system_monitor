#include <chrono>
#include "system_monitor_client_lib.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "client2_node");
    ros::NodeHandle nh;
    ros::Rate loop_rate(0.1);

    SystemMonitorClientInterface client2(nh, 2);
    
    while(ros::ok())
    {
        client2.reportWarningStatus("High temperature detected.");
        usleep(500000);
        client2.reportErrorStatus("No encoder detected.");
        usleep(500000);
        ros::spinOnce();
        loop_rate.sleep();
    }

  return 0;
}