#include <string>

#include "dhnetsdk.h"

namespace camera
{
class Camera
{
private:
    static void CALLBACK DisConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);
    static void CALLBACK AutoConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);

public:
    Camera();
    ~Camera();

    bool Open(std::string ip);
};

} // namespace camera