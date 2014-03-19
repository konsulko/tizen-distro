DESCRIPTION = "A Model configuration"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Configuration"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by model-config-generic 
PROVIDES += "model-config-generic"
RPROVIDES_model-config-generic += "model-config-generic"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n model-config-generic-0.0.1
 
 
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
 
 mkdir -p ${D}/etc/config
 cp -f model-config.xml ${D}/etc/config/model-config.xml
 
 
}

PACKAGES = ""
PACKAGES += "model-config-generic"

model-config-generic_files = ""
model-config-generic_files += "model-config.manifest"
model-config-generic_files += "/etc/config/model-config.xml"

FILES_${PN} = "${model-config-generic_files}"

PKG_model-config-generic= "model-config-generic"

require config-extraconf.inc
