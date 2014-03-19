DESCRIPTION = "Multimedia Framework system configuration package"
HOMEPAGE = "http://nohomepage.org"
SECTION = "TO_BE/FILLED_IN"
LICENSE = "Apache-2.0"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "mmfw-sysconf-simulator"

mmfw-sysconf-simulator_files = ""
mmfw-sysconf-simulator_files += "/etc/asound.conf"
mmfw-sysconf-simulator_files += "/etc/pulse/*"
mmfw-sysconf-simulator_files += "/usr/etc/*.ini"
mmfw-sysconf-simulator_files += "/usr/etc/gst-openmax.conf"
mmfw-sysconf-simulator_files += "/usr/share/pulseaudio/alsa-mixer/paths/*.conf"
mmfw-sysconf-simulator_files += "/usr/share/pulseaudio/alsa-mixer/paths/*.common"
mmfw-sysconf-simulator_files += "/usr/share/pulseaudio/alsa-mixer/profile-sets/*.conf"

FILES_${PN}-simulator = "${mmfw-sysconf-simulator_files}"

PKG_mmfw-sysconf-simulator= "mmfw-sysconf-simulator"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require mmfw-sysconf-rdepends.inc
require mmfw-sysconf-depends.inc
require mmfw-sysconf-extraconf.inc
