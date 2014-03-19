DESCRIPTION = "Setting application"
HOMEPAGE = "http://nohomepage.org"
SECTION = "misc"
LICENSE = "Flora License, Version 1"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "org.tizen.setting"

org.tizen.setting_files = ""
org.tizen.setting_files += "settings.manifest"
org.tizen.setting_files += "/usr/apps/org.tizen.setting/bin/setting"
org.tizen.setting_files += "/usr/apps/org.tizen.setting/bin/setting_conf_util"
org.tizen.setting_files += "/opt/data/setting/setting.cfg"
org.tizen.setting_files += "/usr/share/packages/org.tizen.setting.xml"
org.tizen.setting_files += "/opt/etc/smack/accesses.d/org.tizen.setting.rule"
org.tizen.setting_files += "/usr/share/icons/default/small/org.tizen.setting.png"
org.tizen.setting_files += "/opt/share/settings/*"
org.tizen.setting_files += "/usr/apps/org.tizen.setting/res/*"
org.tizen.setting_files += "/usr/apps/org.tizen.setting/lib/*"
org.tizen.setting_files += "/usr/apps/org.tizen.setting/data/*"
org.tizen.setting_files += "/usr/ug/lib/*"
org.tizen.setting_files += "/opt/data/setting/langlist.xml"
org.tizen.setting_files += "/opt/data/setting/plugin-cfg/*"
org.tizen.setting_files += "/opt/data/setting/plugin-xml/*"
org.tizen.setting_files += "/opt/media/Open_Source_Announcement.html"

FILES_${PN} = "${org.tizen.setting_files}"

PKG_org.tizen.setting= "org.tizen.setting"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require settings-rdepends.inc
require settings-depends.inc
require settings-extraconf.inc
