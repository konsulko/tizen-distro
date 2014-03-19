DESCRIPTION = "svi library audio data package (SDK)"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Resources"
LICENSE = "Apache License, Version 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by svi-data-sdk 
PROVIDES += "svi-data-sdk"
RPROVIDES_svi-data-sdk += "svi-data-sdk"

RDEPENDS = ""
#RDEPENDS of svi-data-sdk (${PN}-sdk)
RDEPENDS_${PN}-sdk += "coreutils"


DEPENDS = ""
#DEPENDS of svi-data-sdk 
DEPENDS += "cmake"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
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
 
 cp ${S}/packaging/svi-data-sdk.manifest .
 cmake . -DCMAKE_INSTALL_PREFIX=/usr
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}/opt/share/svi/sound/touch
 mkdir -p ${D}/opt/share/svi/sound/operation
 mkdir -p ${D}/opt/share/svi/haptic/default
 mkdir -p ${D}/opt/share/svi/haptic/touch
 
 
}

PACKAGES = ""
PACKAGES += "svi-data-sdk"

svi-data-sdk_files = ""
svi-data-sdk_files += "svi-data-sdk.manifest"
svi-data-sdk_files += "/usr/share/svi/*"
svi-data-sdk_files += "/opt/share/svi/sound/touch"
svi-data-sdk_files += "/opt/share/svi/sound/operation"
svi-data-sdk_files += "/opt/share/svi/haptic/default"
svi-data-sdk_files += "/opt/share/svi/haptic/touch"
svi-data-sdk_files += "svi-data-sdk.manifest"

FILES_${PN} = "${svi-data-sdk_files}"

PKG_svi-data-sdk= "svi-data-sdk"

require svi-data-extraconf.inc
