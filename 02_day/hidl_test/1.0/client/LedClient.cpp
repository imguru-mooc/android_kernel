#include <iostream>
#include <android-base/logging.h>
#include <hidl/HidlTransportSupport.h>
#include <vendor/example/led/1.0/ILed.h>

using ::vendor::example::led::V1_0::ILed;

int main() {
    auto led = ILed::getService("default");
    if (!led) {
        std::cerr << "ILed service not found\n";
        return 1;
    }
    auto ret = led->LEDON();
    if (!ret.isOk()) {
        std::cerr << "LEDON binder call failed: " << ret.description().c_str() << "\n";
        return 1;
    }
    std::cout << "LEDON called successfully\n";
    return 0;
}

