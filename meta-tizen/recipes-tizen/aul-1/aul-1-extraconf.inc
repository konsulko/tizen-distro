SRC_URI += "file://Removing-Ecore-or-EFL-related-packages-depedencies.patch "

RDEPENDS = ""
#RDEPENDS of aul (aul)
RDEPENDS_aul += "eglibc"
RDEPENDS_aul += "systemd"

#RDEPENDS of aul-dev (aul-dev)
RDEPENDS_aul-dev += "aul"


DEPENDS = ""
#DEPENDS of aul 
DEPENDS += "pkgmgr-info"
DEPENDS += "librua"
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "attr"
DEPENDS += "dbus"
DEPENDS += "tizen-platform-config"
DEPENDS += "dlog"
DEPENDS += "xdgmime"
DEPENDS += "ail"
DEPENDS += "bundle"
DEPENDS += "sqlite3"
DEPENDS += "libprivilege-control"
DEPENDS += "app-checker"
DEPENDS += "vconf"
DEPENDS += "privacy-manager"
