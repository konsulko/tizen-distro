DESCRIPTION = "Library for developing the livebox service provider"
HOMEPAGE = "http://nohomepage.org"
SECTION = "HomeTF/Livebox"
LICENSE = "Flora"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libprovider"
PACKAGES += "libprovider-devel"

libprovider_files = ""
libprovider_files += "libprovider.manifest"
libprovider_files += "/usr/lib/*.so*"

libprovider-devel_files = ""
libprovider-devel_files += "libprovider.manifest"
libprovider-devel_files += "/usr/include/provider/provider.h"
libprovider-devel_files += "/usr/include/provider/provider_buffer.h"
libprovider-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${libprovider_files}"
FILES_${PN}-devel = "${libprovider-devel_files}"

PKG_libprovider= "libprovider"
PKG_libprovider-devel= "libprovider-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require provider-rdepends.inc
require provider-depends.inc
require provider-extraconf.inc
