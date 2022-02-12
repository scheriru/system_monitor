#include <string>
#include <memory>
#include <ros/ros.h>

class SystemMonitorClientInterface
{
    public:
        SystemMonitorClientInterface(ros::NodeHandle nh, unsigned int id);
        ~SystemMonitorClientInterface();
        void reportFatalStatus(std::string fatal_msg);
        void reportErrorStatus(std::string error_msg);
        void reportWarningStatus(std::string warning_msg);
    private:
        class SystemMonitorClient;
        std::unique_ptr<SystemMonitorClient> pSystemMonitorClient;

};

