#include "system_monitor_client_lib.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "client1_node");
    ros::NodeHandle nh;
    ros::Rate loop_rate(1);

    SystemMonitorClientInterface client1(nh, 1);
    
    while(ros::ok())
    {
        client1.reportFatalStatus("lost heartbeat.");
        ros::spinOnce();
        loop_rate.sleep();
    }

  return 0;
}