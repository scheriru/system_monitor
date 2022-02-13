#include <unistd.h>
#include "system_monitor_client_lib.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "client3_node");
    ros::NodeHandle nh;
    ros::Rate loop_rate(1);

    SystemMonitorClientInterface client3(nh, 3);
    ROS_INFO("Client 3 Node Started.");
    
    while(ros::ok())
    {
        client3.reportWarningStatus("Low temperature detected.");
        usleep(500000);
        client3.reportErrorStatus("No camera detected.");
        usleep(500000);
        ros::spinOnce();
        loop_rate.sleep();
    }

  return 0;
}