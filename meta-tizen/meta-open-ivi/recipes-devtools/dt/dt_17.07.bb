HOMEPAGE = "http://home.comcast.net/~SCSIguy/SCSI_FAQ/RMiller_Tools/dt.html"
DESCRIPTION = "The Data Test Program (dt) is a generic data test program used to verify proper \
operation of peripherals, file systems, device drivers, or any data stream supported by the \
operating system."

SECTION = "console/tests"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://dt.c;beginline=2;endline=25;md5=6ff977a6c6e7c96097bbd038ac3240f4"

INC_PR = "r0"

SRC_URI = "http://home.comcast.net/~SCSIguy/SCSI_FAQ/RMiller_Tools/ftp/dt/dt-source.tar.gz"
S = "${WORKDIR}/dt.d-WIP"

TARGET_CC_ARCH += "${LDFLAGS}"

do_compile() {
	${MAKE} -f Makefile.linux
}

SRC_URI_append_libc-uclibc = " file://no_aio.patch "

do_install() {
	install -d ${D}${bindir}
	install -m 0755 dt ${D}${bindir}
}

SRC_URI[md5sum] = "fc3373e30868698b90f02cc5fab9aabd"
SRC_URI[sha256sum] = "6a213b8da2b8907c4f1633c3b90229085ac239e4d43aa5879b0123c21f951cab"

