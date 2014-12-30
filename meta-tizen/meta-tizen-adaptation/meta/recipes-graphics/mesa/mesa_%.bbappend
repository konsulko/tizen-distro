SECTION = "Graphics & UI Framework/Hardware Adaptation"

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI += "file://0001-intel:-FixinitialMakeCurrentfordrawablesofmultiscreens.patch"

# Enabling gallium-llvm creates a dependency on llvm.
# meta-openembedded provides that.

PACKAGECONFIG_append = " gallium"
PACKAGECONFIG_append = " gallium-egl"
PACKAGECONFIG_append = " gallium-gbm"
PACKAGECONFIG_append = " gallium-llvm"

DRIDRIVERSTIZEN = "swrast"
DRIDRIVERSTIZEN_append_x86 = ",i965,i915"
DRIDRIVERSTIZEN_append_x86-64 = ",i965,i915"
PACKAGECONFIG[dri] = "--enable-dri --with-dri-drivers=${DRIDRIVERSTIZEN}, --disable-dri, dri2proto libdrm"


GALLIUMDRIVERSTIZEN_append = ",i915"

GALLIUMDRIVERSTIZEN = "swrast"
GALLIUMDRIVERSTIZEN_LLVM33 = ""
GALLIUMDRIVERSTIZEN_LLVM33_ENABLED = "${@base_version_less_or_equal('MESA_LLVM_RELEASE', '3.2', False, len('${GALLIUMDRIVERSTIZEN_LLVM33}') > 0, d)}"
GALLIUMDRIVERSTIZEN_LLVM = "svga,"
GALLIUMDRIVERSTIZEN_append_x86 = "${@bb.utils.contains('PACKAGECONFIG', 'gallium-llvm', ',${GALLIUMDRIVERSTIZEN_LLVM}', '', d)}"
GALLIUMDRIVERSTIZEN_append_x86-64 = "${@bb.utils.contains('PACKAGECONFIG', 'gallium-llvm', ',${GALLIUMDRIVERSTIZEN_LLVM}', '', d)}"
# keep --with-gallium-drivers separate, because when only one of gallium versions is enabled, other 2 were adding --without-gallium-drivers
PACKAGECONFIG[gallium]      = "--with-gallium-drivers=${GALLIUMDRIVERSTIZEN}, --without-gallium-drivers"