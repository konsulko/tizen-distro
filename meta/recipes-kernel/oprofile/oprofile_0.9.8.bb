require oprofile.inc

PR = "${INC_PR}.1"

DEPENDS += "virtual/kernel"

SRC_URI += "${SOURCEFORGE_MIRROR}/${BPN}/${BPN}-${PV}.tar.gz \
            file://0001-Add-rmb-definition-for-AArch64-architecture.patch \
            file://0001-OProfile-doesn-t-build-for-32-bit-ppc-the-operf_util.patch \
            file://0001-Handle-early-perf_events-kernel-without-PERF_RECORD_.patch \
            file://0001-Fix-up-configure-to-handle-architectures-that-do-not.patch \
            file://0001-Change-configure-to-look-for-libpfm4-function-first-.patch"

SRC_URI[md5sum] = "6d127023af1dd1cf24e15411229f3cc8"
SRC_URI[sha256sum] = "ab45900fa1a23e5d5badf3c0a55f26c17efe6e184efcf00b371433751fa761bc"

S = "${WORKDIR}/oprofile-${PV}"

