DESCRIPTION = "The Hangul engine for IBus input platform"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System Environment/Libraries"
LICENSE = "GPLv2+"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "ibus-hangul"

ibus-hangul_files = ""
ibus-hangul_files += "ibus-hangul.manifest"
ibus-hangul_files += "AUTHORS COPYING README"
ibus-hangul_files += "/usr/libexec/ibus-engine-hangul"
ibus-hangul_files += "/usr/libexec/ibus-setup-hangul"
ibus-hangul_files += "/usr/share/ibus-hangul"
ibus-hangul_files += "/usr/share/ibus/component/*"
ibus-hangul_files += "/usr/lib/ibus-hangul/setup/*"
ibus-hangul_files += "/usr/share/applications/ibus-setup-hangul.desktop"
ibus-hangul_files += "/usr/share/icons/hicolor/*/apps/*"

FILES_${PN} = "${ibus-hangul_files}"

PKG_ibus-hangul= "ibus-hangul"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require ibus-hangul-rdepends.inc
require ibus-hangul-depends.inc
require ibus-hangul-extraconf.inc
