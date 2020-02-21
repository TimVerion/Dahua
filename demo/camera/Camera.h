#include <string>

#include "dhnetsdk.h"

namespace camera
{
class Camera
{
private:
public:
    Camera();
    ~Camera();

    static void CALLBACK DisConnectFunc(LONG lLoginID, char *pchDVRIP,
                                 LONG nDVRPort, DWORD dwUser);
    static void CALLBACK AutoConnectFunc(LONG lLoginID, char *pchDVRIP,
                                  LONG nDVRPort, DWORD dwUser);

    bool Open(std::string ip);
};

} // namespace camera