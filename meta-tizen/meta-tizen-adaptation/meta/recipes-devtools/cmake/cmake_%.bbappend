SECTION = "Platfrom Development/Tools"

FILESEXTRAPATHS_append := "${THISDIR}/files"

SRC_URI += "file://TizenCommon.cmake"

do_install_append() {
    install -m 644 ${WORKDIR}/TizenCommon.cmake ${D}${datadir}/cmake-${CMAKE_MAJOR_VERSION}/Modules
}