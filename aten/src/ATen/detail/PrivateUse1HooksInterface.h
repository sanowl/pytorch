#pragma once

#include <ATen/detail/AcceleratorHooksInterface.h>

#include <c10/core/Allocator.h>
#include <c10/core/Device.h>
#include <c10/core/Storage.h>
#include <c10/util/Exception.h>

C10_DIAGNOSTIC_PUSH_AND_IGNORED_IF_DEFINED("-Wunused-parameter")

namespace at {

struct TORCH_API PrivateUse1HooksInterface : AcceleratorHooksInterface {
#define FAIL_PRIVATEUSE1HOOKS_FUNC(func)                        \
  TORCH_CHECK_NOT_IMPLEMENTED(                                  \
      false,                                                    \
      "You should register `PrivateUse1HooksInterface`",        \
      "by `RegisterPrivateUse1HooksInterface` and implement `", \
      func,                                                     \
      "` at the same time for PrivateUse1.");

  ~PrivateUse1HooksInterface() override = default;

  const at::Generator& getDefaultGenerator(
      c10::DeviceIndex device_index) const override {
    FAIL_PRIVATEUSE1HOOKS_FUNC(__func__);
  }

  Generator getNewGenerator(
      C10_UNUSED DeviceIndex device_index = -1) const override {
    FAIL_PRIVATEUSE1HOOKS_FUNC(__func__);
  }

  at::Device getDeviceFromPtr(void* data) const override {
    FAIL_PRIVATEUSE1HOOKS_FUNC(__func__);
  }

  bool isPinnedPtr(const void* data) const override {
    return false;
  }

  Allocator* getPinnedMemoryAllocator() const override {
    FAIL_PRIVATEUSE1HOOKS_FUNC(__func__);
  }

  bool hasPrimaryContext(DeviceIndex device_index) const override {
    FAIL_PRIVATEUSE1HOOKS_FUNC(__func__);
  }

  void init() const override {
    TORCH_WARN_DEPRECATION(
        "initPrivateUse1() is deprecated. Please implement init() directly instead.")
    initPrivateUse1();
  }

  virtual void initPrivateUse1() const {
    return;
  }

  virtual void resizePrivateUse1Bytes(
      const c10::Storage& storage,
      size_t newsize) const {
    FAIL_PRIVATEUSE1HOOKS_FUNC(__func__);
  }

#undef FAIL_PRIVATEUSE1HOOKS_FUNC
};

struct TORCH_API PrivateUse1HooksArgs {};

TORCH_API void RegisterPrivateUse1HooksInterface(
    at::PrivateUse1HooksInterface* hook_);

TORCH_API bool isPrivateUse1HooksRegistered();

namespace detail {

TORCH_API const at::PrivateUse1HooksInterface& getPrivateUse1Hooks();

} // namespace detail

} // namespace at

C10_DIAGNOSTIC_POP()
