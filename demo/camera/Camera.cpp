#include "Camera.h"

#include "utils/log/easylogging++.h"

namespace camera
{

Camera::Camera()
{
    if(false){ std::cout<<el::base::consts::kPerformanceLoggerId<<std::endl; }
    LOG(INFO) << "init class Camera";
}

Camera::~Camera()
{
    CLIENT_Cleanup();

    LOG(INFO) << "release class Camera";
}

void CALLBACK Camera::DisConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser)
{
    LOG(ERROR) << "DisConnectFunc...";
}

void CALLBACK Camera::AutoConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser)
{
    LOG(ERROR) << "AutoConnectFunc...";
}

bool Camera::Open(std::string ip)
{
    //NET_DEVICEINFO deviceInfo = {0};

    BOOL bRet = CLIENT_Init(DisConnectFunc, 0);
    if (!bRet)
    {
        LOG(ERROR) << "Initialize SDK failed";
        return false;
    }

    CLIENT_SetAutoReconnect(AutoConnectFunc, 0);

    LOG(INFO) << "Initialize SDK success";

    return true;
}
} // namespace camera