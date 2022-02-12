#include <vector>
#include <string>
#include <ros/ros.h>
#include "system_monitor/SystemStatus.h"
#include "diagnostic_msgs/DiagnosticStatus.h"


class SystemMonitorServer
{
    public:

        SystemMonitorServer();
        void run(void);
        void clientCallback(diagnostic_msgs::DiagnosticStatus client_msg);

    private:
        ros::NodeHandle nh_;
        ros::Publisher pub_error_;
        ros::Publisher pub_fatal_;
        ros::Publisher pub_warning_;
        ros::Subscriber sub_from_client_;
        system_monitor::SystemStatus system_status_msg_;

        unsigned int client_id_;
        std::string alert_msg_;
        uint8_t alert_type_;
        bool alert_flag_;
};
