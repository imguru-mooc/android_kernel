#ifndef HIDL_GENERATED_VENDOR_EXAMPLE_LED_V1_0_BNHWLED_H
#define HIDL_GENERATED_VENDOR_EXAMPLE_LED_V1_0_BNHWLED_H

#include <vendor/example/led/1.0/IHwLed.h>

namespace vendor {
namespace example {
namespace led {
namespace V1_0 {

struct BnHwLed : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwLed(const ::android::sp<ILed> &_hidl_impl);
    explicit BnHwLed(const ::android::sp<ILed> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwLed();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef ILed Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef ::android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<ILed> getImpl() { return _hidl_mImpl; }
    // Methods from ::vendor::example::led::V1_0::ILed follow.
    static ::android::status_t _hidl_LEDON(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::vendor::example::led::V1_0::ILed follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<ILed> _hidl_mImpl;
};

}  // namespace V1_0
}  // namespace led
}  // namespace example
}  // namespace vendor

#endif  // HIDL_GENERATED_VENDOR_EXAMPLE_LED_V1_0_BNHWLED_H
