#include "Camera.h"

#include "utils/log/easylogging++.h"

namespace camera
{

Camera::Camera()
{
    if (false)
    {
        std::cout << el::base::consts::kPerformanceLoggerId << std::endl;
    }
    LOG(INFO) << "init class Camera";
}

Camera::~Camera()
{
    if (_userValue != 0)
    {
        CLIENT_Logout(_userValue);
    }

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
    BOOL bRet = CLIENT_Init(DisConnectFunc, 0);
    if (!bRet)
    {
        LOG(ERROR) << "Initialize SDK failed";
        return false;
    }

    CLIENT_SetAutoReconnect(AutoConnectFunc, 0);

    NET_DEVICEINFO deviceInfo = {0};
    _userValue = CLIENT_Login(ip.c_str(), 37777,
                              "admin", "admin", &deviceInfo);
    if (_userValue == 0)
    {
        LOG(ERROR) << "Camera login failed";
        return false;
    }

    LOG(INFO) << "Camera login success";

    return true;
}
} // namespace camera