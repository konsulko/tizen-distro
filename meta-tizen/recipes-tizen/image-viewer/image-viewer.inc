DESCRIPTION = "Image Viewer Application v1.0"
HOMEPAGE = "http://nohomepage.org"
SECTION = "misc"
LICENSE = "Flora Software License"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "org.tizen.image-viewer"

org.tizen.image-viewer_files = ""
org.tizen.image-viewer_files += "org.tizen.image-viewer.manifest"
org.tizen.image-viewer_files += "org.tizen.image-viewer.manifest"
org.tizen.image-viewer_files += "/opt/etc/smack/accesses.d/org.tizen.image-viewer.rule"
org.tizen.image-viewer_files += "/usr/apps/org.tizen.image-viewer/*"
org.tizen.image-viewer_files += "/usr/share/icons/default/small/org.tizen.image-viewer.png"
org.tizen.image-viewer_files += "/usr/share/packages/org.tizen.image-viewer.xml"
org.tizen.image-viewer_files += "/usr/share/license/org.tizen.image-viewer"

FILES_${PN} = "${org.tizen.image-viewer_files}"

PKG_org.tizen.image-viewer= "org.tizen.image-viewer"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require image-viewer-rdepends.inc
require image-viewer-depends.inc
require image-viewer-extraconf.inc
