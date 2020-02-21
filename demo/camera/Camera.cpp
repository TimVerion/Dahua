#include "Camera.h"

#include "utils/log/easylogging++.h"

namespace camera
{
Camera::Camera()
{
    LOG(INFO) << "init class Camera";
}

Camera::~Camera()
{
    LOG(INFO) << "release class Camera";
}

void CALLBACK Camera::DisConnectFunc(LONG lLoginID, char *pchDVRIP,
                                     LONG nDVRPort, DWORD dwUser)
{
    LOG(INFO) << "Camera disconnect";
}

void CALLBACK Camera::AutoConnectFunc(LONG lLoginID, char *pchDVRIP,
                              LONG nDVRPort, DWORD dwUser)
{
    LOG(INFO) << "Camera disconnect";
}

bool Camera::Open(std::string ip)
{
    LOG(INFO) << "open camera";

    //NET_DEVICEINFO deviceInfo = {0};

    CLIENT_Init(DisConnectFunc, 0);
    CLIENT_SetAutoReconnect(AutoConnectFunc, 0);

    return true;
}
} // namespace camera