#include <android-base/logging.h>
#include <hidl/HidlTransportSupport.h>
#include <vendor/example/led/1.0/ILed.h>

using ::android::sp;
using ::android::OK;
using ::android::status_t;
using ::android::hardware::configureRpcThreadpool;
using ::android::hardware::joinRpcThreadpool;
using ::android::hardware::Return;
using ::vendor::example::led::V1_0::ILed;

struct Led : public ILed {
    Return<void> LEDON() override {
        LOG(INFO) << "LEDON() called";
        // 실제 하드웨어 제어가 있다면 여기에
        return {};
    }
};

int main() {
    ::android::base::InitLogging(nullptr, ::android::base::StderrLogger);
    configureRpcThreadpool(1, true);

    sp<Led> service = new Led();
    status_t st = service->registerAsService("default");
    if (st != OK) {
        LOG(ERROR) << "registerAsService failed: " << st;
        return 1;
    }
    LOG(INFO) << "ILed registered as vendor.example.led@1.0::ILed/default";
    joinRpcThreadpool();
    return 0;
}

