DESCRIPTION = "Certification service"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "SAMSUNG"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "cert-svc-ui"

cert-svc-ui_files = ""
cert-svc-ui_files += "cert-svc-ui.manifest"
cert-svc-ui_files += "/etc/smack/accesses2.d/ug.cert-svc-ui.include"
cert-svc-ui_files += "/usr/ug/lib/libmgr-cert-view.so"
cert-svc-ui_files += "/usr/ug/lib/libug-setting-manage-certificates-efl.so.*"
cert-svc-ui_files += "/usr/ug/lib/libug-setting-manage-certificates-efl.so"
cert-svc-ui_files += "/usr/ug/lib/libug-cert-selection-ug-efl.so*"
cert-svc-ui_files += "/usr/ug/res/locale/*/LC_MESSAGES/*"
cert-svc-ui_files += "/usr/share/license/cert-svc-ui"

FILES_${PN} = "${cert-svc-ui_files}"

PKG_cert-svc-ui= "cert-svc-ui"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require cert-svc-ui-rdepends.inc
require cert-svc-ui-depends.inc
require cert-svc-ui-extraconf.inc
