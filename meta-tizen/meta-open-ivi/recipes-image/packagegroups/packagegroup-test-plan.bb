SUMMARY = "Test Plan Package Groups"
DESCRIPTION = "Test Plan Package Groups"
LICENSE = "Apache-2.0"

inherit packagegroup

PACKAGES = "\
	packagegroup-test-plan\
	"

RDEPENDS_packagegroup-test-plan = " \
	i2c-tools net-tools usbutils \
	alsa-lib alsa-utils alsa-tools \
	rpm libinput ofono hostapd kernel-module-csr-wifi \
	perf iperf evtest connman \
	bonnie++ ppp \
	"
