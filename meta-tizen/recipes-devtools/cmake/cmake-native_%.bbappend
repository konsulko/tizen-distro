FILESEXTRAPATHS_append := "${THISDIR}/files"

SRC_URI += "file://TizenCommon_native.cmake"

do_install_append() {
    mv ${WORKDIR}/TizenCommon_native.cmake ${WORKDIR}/TizenCommon.cmake 
    install -m 644 ${WORKDIR}/TizenCommon.cmake ${D}${datadir}/cmake-${CMAKE_MAJOR_VERSION}/Modules/
}