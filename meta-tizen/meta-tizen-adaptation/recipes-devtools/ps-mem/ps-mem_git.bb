DESCRIPTION = "An utility to accurately report the core memory usage of programs"
HOMEPAGE = "https://github.com/eurogiciel-oss/ps_mem"
SECTION = "System/System Info"
LICENSE = "LGPL-2.1"
SRC_URI = "git://github.com/eurogiciel-oss/ps_mem.git;tag=2ea36ccbad134cccc9ab1ada6aefcaec0f948d94;nobranch=1"

S = "${WORKDIR}/git"
PRIORITY = "10"
LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/LGPL-2.1;md5=1a6d268fd218675ffea8be556788b780"

DEPENDS = "python"

do_install() {
    install -D -m 755 ${S}/ps_mem.py ${D}${prefix}/bin/ps_mem
}

PACKAGES = "${PN}"

FILES_${PN} = "${prefix}/bin/ps_mem"