DEFAULT_PREFERENCE = "-1"

include gstreamer1.0.inc

DEPENDS += "libpcap"

LIC_FILES_CHKSUM = "file://COPYING;md5=6762ed442b3822387a51c92d928ead0d \
                    file://gst/gst.h;beginline=1;endline=21;md5=e059138481205ee2c6fc1c079c016d0d"

SRC_URI = "git://git@bitbucket.org/pantoniou/gstreamer.git;protocol=ssh;branch=master"
SRCREV = "${AUTOREV}"

S = "${WORKDIR}/git"

do_configure_prepend() {
	cd ${S}
	./autogen.sh --noconfigure
	cd ${B}
}

