DESCRIPTION = "Rpm correctness checker - Tizen Trunk configuration"
HOMEPAGE = "http://rpmlint.zarb.org/"
SECTION = "System/Packages"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by rpmlint-tizen 
PROVIDES += "rpmlint-tizen"
RPROVIDES_rpmlint-tizen += "rpmlint-tizen"

#PROVIDES by rpmlint-tizen-strict 
PROVIDES += "rpmlint-tizen-strict"
RPROVIDES_rpmlint-tizen-strict += "rpmlint-tizen-strict"

RDEPENDS = ""
#RDEPENDS of rpmlint-tizen (${PN})
RDEPENDS_${PN} += "rpmlint-mini"


DEPENDS = ""

do_patch() {
 cp ${S}/packaging/COPYING .
 
 
}

do_configure() {
}

do_compile() {
 LANG=C
 export LANG
 unset DISPLAY
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ; 
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
 LD_AS_NEEDED=1; export LD_AS_NEEDED ; 
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 install -m 644 -D ${S}/packaging/config $RPM_BUILD_ROOT/etc/rpmlint/factory.config
 install -m 644 -D ${S}/packaging/config.strict $RPM_BUILD_ROOT/etc/rpmlint/factory-strict.config
 
 
}

PACKAGES = ""
PACKAGES += "rpmlint-tizen"
PACKAGES += "rpmlint-tizen-strict"

rpmlint-tizen_files = ""
rpmlint-tizen_files += "/etc/rpmlint"
rpmlint-tizen_files += "/etc/rpmlint/factory.config"

rpmlint-tizen-strict_files = ""
rpmlint-tizen-strict_files += "/etc/rpmlint"
rpmlint-tizen-strict_files += "/etc/rpmlint/factory-strict.config"

FILES_${PN} = "${rpmlint-tizen_files}"
FILES_${PN}-strict = "${rpmlint-tizen-strict_files}"

PKG_rpmlint-tizen= "rpmlint-tizen"
PKG_rpmlint-tizen-strict= "rpmlint-tizen-strict"

require rpmlint-tizen-extraconf.inc
