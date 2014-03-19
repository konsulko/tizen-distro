DESCRIPTION = "X.Org X11 Protocol dri2proto"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "dri2proto"

dri2proto_files = ""
dri2proto_files += "dri2proto.manifest"
dri2proto_files += "/usr/include/X11/extensions/*.h"
dri2proto_files += "/usr/share/pkgconfig/*.pc"

FILES_${PN} = "${dri2proto_files}"

PKG_dri2proto= "dri2proto"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require dri2proto-rdepends.inc
require dri2proto-depends.inc
require dri2proto-extraconf.inc
