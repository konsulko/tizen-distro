DESCRIPTION = "Bluetooth agent packages that support various external profiles"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Network & Connectivity/Bluetooth"
LICENSE = "Apache-2.0"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "bluetooth-agent"

bluetooth-agent_files = ""
bluetooth-agent_files += "bluetooth-agent.manifest"
bluetooth-agent_files += "/usr/bin/bluetooth-map-agent"
bluetooth-agent_files += "/usr/bin/bluetooth-pb-agent"
bluetooth-agent_files += "/usr/bin/bluetooth-hfp-agent"
bluetooth-agent_files += "/usr/share/dbus-1/system-services/org.bluez.pb_agent.service"
bluetooth-agent_files += "/usr/share/dbus-1/services/org.bluez.map_agent.service"
bluetooth-agent_files += "/usr/share/dbus-1/system-services/org.bluez.hfp_agent.service"

FILES_${PN} = "${bluetooth-agent_files}"

PKG_bluetooth-agent= "bluetooth-agent"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require bluetooth-agent-rdepends.inc
require bluetooth-agent-depends.inc
require bluetooth-agent-extraconf.inc
