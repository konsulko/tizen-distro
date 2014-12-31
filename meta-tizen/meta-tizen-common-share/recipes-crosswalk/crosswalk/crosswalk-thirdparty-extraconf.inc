inherit gettext

FILESEXTRAPATHS_prepend := "${THISDIR}/crosswalk:"

# This comes from the chromium recipe:
# http://layers.openembedded.org/layerindex/recipe/4969/
# It allows architecture specific configuration
SRC_URI += "${INCLUDE_GYPI}"
SRC_URI += "${OE_DEFAULTS_GYPI}"

SRC_URI += "file://fix-crosbuild.patch"

INCLUDE_GYPI_i586 = "file://include.gypi"
INCLUDE_GYPI_x86-64 = "file://include.gypi"
INCLUDE_GYPI_arm = "file://include.gypi"
OE_DEFAULTS_GYPI_i586 = "file://oe-defaults.gypi"
OE_DEFAULTS_GYPI_x86-64 = "file://oe-defaults.gypi"
OE_DEFAULTS_GYPI_arm = "file://oe-defaults.gypi"

RDEPENDS_${PN} += "libpulsecommon"

DEPENDS += "yasm-native"

do_compile_prepend() {

    CC_host="gcc"; export CC_host
    CXX_host="g++"; export CXX_host

    LD="${CXX}" export LD
    CC="${CC}" export CC
    CXX="${CXX}" export CXX
    GYP_EXTRA_FLAGS="${GYP_EXTRA_FLAGS} -I${WORKDIR}/oe-defaults.gypi -I${WORKDIR}/include.gypi"
    GYP_EXTRA_FLAGS="${GYP_EXTRA_FLAGS} -Dhost_clang=0 "
}

do_configure() {
}
