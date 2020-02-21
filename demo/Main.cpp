#include <memory>
#include <iostream>

#include "utils/log/easylogging++.h"

#include "camera/Camera.h"

INITIALIZE_EASYLOGGINGPP

void RollbackHandle(const char *filename, std::size_t size) {}
void initlog()
{
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Format,
                                       "%datetime|%level: %msg [%fbase %line]");
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Filename, "/home/wilson/code/opencv/log/%datetime{%Y%M%d}.log");
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::MaxLogFileSize, "2097152");
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::PerformanceTracking, "false");
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::ToStandardOutput, "false");

    el::Loggers::addFlag(el::LoggingFlag::StrictLogFileSizeCheck);
    el::Loggers::addFlag(el::LoggingFlag::DisableApplicationAbortOnFatalLog);

    el::Helpers::installPreRollOutCallback(RollbackHandle);
}

int HExit()
{
    getchar();
    LOG(INFO) << "===========  program end  ===========";
    return 0;
}

int main(int argc, char const *argv[])
{
    if(false){ std::cout<<el::base::consts::kPerformanceLoggerId<<std::endl; }
    initlog();
    LOG(INFO) << "=====================================";
    LOG(INFO) << "=========== program start ===========";

    camera::Camera came;
    came.Open("192.168.1.122");

    return HExit();
}
