#include <string>

#include "dhnetsdk.h"

namespace camera
{
class Camera
{
private:
    long _userHandle;
    long _realPlayHandle;

    static void CALLBACK DisConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);
    static void CALLBACK AutoConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);
    static void CALLBACK RealDataCallBackEx2(LLONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, LLONG param, LDWORD dwUser);

public:
    Camera();
    ~Camera();

    bool Open(std::string ip);
};

} // namespace camera