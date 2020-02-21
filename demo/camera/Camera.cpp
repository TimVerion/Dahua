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
    if (_userHandle != 0)
    {
        CLIENT_Logout(_userHandle);
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

void CALLBACK Camera::RealDataCallBackEx2(LLONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, LLONG param, LDWORD dwUser)
{
    LOG(INFO)<<"real data buf size: "<<dwBufSize;
}

bool Camera::Open(std::string ip)
{
    BOOL bRet = CLIENT_Init(DisConnectFunc, 0);
    if (!bRet)
    {
        LOG(ERROR) << "Initialize SDK failed";
        return false;
    }
    LOG(INFO) << "Initialize SDK success";

    CLIENT_SetAutoReconnect(AutoConnectFunc, 0);

    NET_DEVICEINFO deviceInfo = {0};
    _userHandle = CLIENT_Login(ip.c_str(), 37777,
                              "admin", "admin", &deviceInfo);
    if (_userHandle == 0)
    {
        LOG(ERROR) << "Camera login failed";
        return false;
    }

    LOG(INFO) << "Camera login success";

    _realPlayHandle = CLIENT_RealPlay(_userHandle, 0, NULL);
    if(_realPlayHandle == 0)
    {
        LOG(ERROR) << "Camera play failed";
        return false;
    }

    CLIENT_SetRealDataCallBackEx2(_realPlayHandle, RealDataCallBackEx2, 0, 0x0f);

    return true;
}
} // namespace camera