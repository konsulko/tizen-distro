DESCRIPTION = "PolicyKit Authorization Framework"
HOMEPAGE = "http://www.freedesktop.org/wiki/Software/PolicyKit"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1+"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "polkit-locale"
PACKAGES += "polkit-docs"
PACKAGES += "libpolkit"
PACKAGES += "polkit"
PACKAGES += "typelib-Polkit"
PACKAGES += "polkit-devel"

polkit-locale_files = ""

polkit-docs_files = ""
polkit-docs_files += "/usr/share/info"
polkit-docs_files += "/usr/share/man"

libpolkit_files = ""
libpolkit_files += "/usr/lib/libpolkit-agent-1.so.*"
libpolkit_files += "/usr/lib/libpolkit-gobject-1.so.*"

polkit_files = ""
polkit_files += "/usr/share/dbus-1"
polkit_files += "/usr/share/dbus-1/system-services"
polkit_files += "/usr/share/dbus-1/system-services/org.freedesktop.PolicyKit1.service"
polkit_files += "/usr/share/polkit-1"
polkit_files += "/usr/share/polkit-1/actions"
polkit_files += "/usr/share/polkit-1/actions/org.freedesktop.policykit.policy"
polkit_files += "/etc/dbus-1"
polkit_files += "/etc/dbus-1/system.d"
polkit_files += "/etc/dbus-1/system.d/org.freedesktop.PolicyKit1.conf"
polkit_files += "/etc/pam.d/polkit-1"
polkit_files += "/etc/polkit-1"
polkit_files += "/etc/polkit-1/rules.d/50-default.rules"
polkit_files += "/usr/bin/pkaction"
polkit_files += "/usr/bin/pkcheck"
polkit_files += "/usr/bin/pkttyagent"
polkit_files += "/usr/lib/polkit-1"
polkit_files += "/usr/lib/polkit-1/polkitd"
polkit_files += "/var/lib/polkit"
polkit_files += "/lib/systemd/system/graphical.target.wants/polkit.service"
polkit_files += "/lib/systemd/system/polkit.service"

typelib-Polkit_files = ""
typelib-Polkit_files += "/usr/lib/girepository-1.0/Polkit-1.0.typelib"
typelib-Polkit_files += "/usr/lib/girepository-1.0/PolkitAgent-1.0.typelib"

polkit-devel_files = ""
polkit-devel_files += "/usr/lib/libpolkit-agent-1.so"
polkit-devel_files += "/usr/lib/libpolkit-gobject-1.so"
polkit-devel_files += "/usr/lib/pkgconfig/polkit-agent-1.pc"
polkit-devel_files += "/usr/lib/pkgconfig/polkit-gobject-1.pc"
polkit-devel_files += "/usr/include/polkit-1/"
polkit-devel_files += "/usr/bin/pk-example-frobnicate"
polkit-devel_files += "/usr/share/gir-1.0/*.gir"
polkit-devel_files += "/usr/share/polkit-1/actions/org.freedesktop.policykit.examples.pkexec.policy"

FILES_${PN}-locale = "${polkit-locale_files}"
FILES_${PN}-docs = "${polkit-docs_files}"
FILES_lib${PN} = "${libpolkit_files}"
FILES_${PN} = "${polkit_files}"
FILES_typelib-Polkit = "${typelib-Polkit_files}"
FILES_${PN}-devel = "${polkit-devel_files}"

PKG_polkit-locale= "polkit-locale"
PKG_polkit-docs= "polkit-docs"
PKG_libpolkit= "libpolkit"
PKG_polkit= "polkit"
PKG_typelib-Polkit= "typelib-Polkit"
PKG_polkit-devel= "polkit-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require polkit-rdepends.inc
require polkit-depends.inc
require polkit-extraconf.inc
