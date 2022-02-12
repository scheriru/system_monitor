#include "central_monitor_server.h"

SystemMonitorServer::SystemMonitorServer()
{
    pub_error_ = nh_.advertise<system_monitor::SystemStatus>("/sysmon/error", 100);
    pub_warning_ = nh_.advertise<system_monitor::SystemStatus>("/sysmon/warning", 100);
    pub_fatal_ = nh_.advertise<system_monitor::SystemStatus>("/sysmon/fatal", 100);

    sub_from_client_ = nh_.subscribe("/sysmon/from_client", 100, &SystemMonitorServer::clientCallback, this);

    alert_flag_ = false;
}

void SystemMonitorServer::clientCallback(diagnostic_msgs::DiagnosticStatus client_msg)
{
    alert_flag_ = true;
    alert_type_ = client_msg.level;
    client_id_ = std::stoi(client_msg.hardware_id);
    alert_msg_ = client_msg.message;

}

void SystemMonitorServer::run(void)
{
    if (alert_flag_ == true)
    {
        system_status_msg_.header.stamp = ros::Time::now();
        system_status_msg_.message = "Client " + std::to_string(client_id_) + ": " + alert_msg_;

        if (alert_type_ == 1)
        {
            pub_warning_.publish(system_status_msg_);
        } else if (alert_type_ == 2)
        {
            pub_error_.publish(system_status_msg_);
        } else if (alert_type_ == 3)
        {
            pub_fatal_.publish(system_status_msg_);
        }

        alert_flag_ = false;
    }
 
}


