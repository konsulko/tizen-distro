DESCRIPTION = "Email library in Tizen Native API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Messaging/API"
LICENSE = "Apache-2.0"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "capi-messaging-email"
PACKAGES += "capi-messaging-email-devel"

capi-messaging-email_files = ""
capi-messaging-email_files += "capi-messaging-email.manifest"
capi-messaging-email_files += "/usr/lib/libcapi-messaging-email.so.*"

capi-messaging-email-devel_files = ""
capi-messaging-email-devel_files += "capi-messaging-email.manifest"
capi-messaging-email-devel_files += "/usr/include/messaging/*.h"
capi-messaging-email-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-messaging-email-devel_files += "/usr/lib/libcapi-messaging-email.so"

FILES_${PN} = "${capi-messaging-email_files}"
FILES_${PN}-devel = "${capi-messaging-email-devel_files}"

PKG_capi-messaging-email= "capi-messaging-email"
PKG_capi-messaging-email-devel= "capi-messaging-email-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require email-rdepends.inc
require email-depends.inc
require email-extraconf.inc
