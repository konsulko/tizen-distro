DESCRIPTION = "imc plugin for telephony"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Libraries"
LICENSE = "Apache-2.0"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "tel-plugin-imc"

tel-plugin-imc_files = ""
tel-plugin-imc_files += "tel-plugin-imc.manifest"
tel-plugin-imc_files += "/usr/lib/telephony/plugins/modems/*"
tel-plugin-imc_files += "/tmp/mcc_mnc_oper_list.sql"
tel-plugin-imc_files += "/usr/share/license/tel-plugin-imc"

FILES_${PN} = "${tel-plugin-imc_files}"

PKG_tel-plugin-imc= "tel-plugin-imc"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require tel-plugin-imc-rdepends.inc
require tel-plugin-imc-depends.inc
require tel-plugin-imc-extraconf.inc
