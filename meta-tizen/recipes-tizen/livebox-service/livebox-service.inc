DESCRIPTION = "Service API for gathering installed livebox information"
HOMEPAGE = "http://nohomepage.org"
SECTION = "HomeTF/Livebox"
LICENSE = "Flora"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "liblivebox-service-devel"
PACKAGES += "liblivebox-service"

liblivebox-service-devel_files = ""
liblivebox-service-devel_files += "liblivebox-service.manifest"
liblivebox-service-devel_files += "liblivebox-service.manifest"
liblivebox-service-devel_files += "/usr/include/livebox-service/livebox-service.h"
liblivebox-service-devel_files += "/usr/include/livebox-service/livebox-errno.h"
liblivebox-service-devel_files += "/usr/lib/pkgconfig/*.pc"

liblivebox-service_files = ""
liblivebox-service_files += "liblivebox-service.manifest"
liblivebox-service_files += "liblivebox-service.manifest"
liblivebox-service_files += "/usr/lib/*.so*"

FILES_${PN}-devel = "${liblivebox-service-devel_files}"
FILES_${PN} = "${liblivebox-service_files}"

PKG_liblivebox-service-devel= "liblivebox-service-devel"
PKG_liblivebox-service= "liblivebox-service"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require livebox-service-rdepends.inc
require livebox-service-depends.inc
require livebox-service-extraconf.inc
