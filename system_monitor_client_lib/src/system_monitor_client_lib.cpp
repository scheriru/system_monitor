#include "system_monitor_client_lib.h"
#include "diagnostic_msgs/DiagnosticStatus.h"

class SystemMonitorClientInterface::SystemMonitorClient
{
    public:
        SystemMonitorClient(ros::NodeHandle nh, unsigned int assigned_id);
        void reportFatal(std::string fatal_msg);
        void reportError(std::string error_msg);
        void reportWarning(std::string warning_msg);

    private:
        unsigned int id;
        ros::NodeHandle nh_;
        ros::Publisher pub_to_server_;
        diagnostic_msgs::DiagnosticStatus alert_msg_;

};
SystemMonitorClientInterface::SystemMonitorClient::SystemMonitorClient(ros::NodeHandle nh, unsigned int assigned_id): nh_(nh)
{
    id = assigned_id;
    pub_to_server_ = nh_.advertise<diagnostic_msgs::DiagnosticStatus>("/sysmon/from_client",100);
}

void SystemMonitorClientInterface::SystemMonitorClient::reportFatal(std::string fatal_alert)
{
    alert_msg_.level = 3;
    alert_msg_.hardware_id = std::to_string(id);
    alert_msg_.message = fatal_alert;
    pub_to_server_.publish(alert_msg_);
}

void SystemMonitorClientInterface::SystemMonitorClient::reportError(std::string error_alert)
{
    alert_msg_.level = 2;
    alert_msg_.hardware_id = std::to_string(id);
    alert_msg_.message = error_alert;
    pub_to_server_.publish(alert_msg_);
}

void SystemMonitorClientInterface::SystemMonitorClient::reportWarning(std::string warning_alert)
{
    alert_msg_.level = 1;
    alert_msg_.hardware_id = std::to_string(id);
    alert_msg_.message = warning_alert;
    pub_to_server_.publish(alert_msg_);
}

SystemMonitorClientInterface::SystemMonitorClientInterface(ros::NodeHandle nh, unsigned int id): 
pSystemMonitorClient(new SystemMonitorClient(nh, id))
{
}

SystemMonitorClientInterface::~SystemMonitorClientInterface() = default;

void SystemMonitorClientInterface::reportFatalStatus(std::string fatal_msg)
{
    pSystemMonitorClient->reportFatal(fatal_msg);
}
void SystemMonitorClientInterface::reportErrorStatus(std::string error_msg)
{
    pSystemMonitorClient->reportError(error_msg);
}
void SystemMonitorClientInterface::reportWarningStatus(std::string warning_msg)
{
    pSystemMonitorClient->reportWarning(warning_msg);
}