#include <Arduino.h>
#include "barrier/ProtocolUtil.h"
#include "barrier/protocol_types.h"
#include "base/Log.h"

bool hello(barrier::IStream* stream){
    return ProtocolUtil::readf(stream, kMsgHello);
}
