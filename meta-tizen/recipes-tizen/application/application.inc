DESCRIPTION = "An Application library in SLP C API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by capi-appfw-application-dev 


#PROVIDES by capi-appfw-application 


RDEPENDS = ""
#RDEPENDS of capi-appfw-application-dev (capi-appfw-${PN}-dev)
RDEPENDS_capi-appfw-${PN}-dev += "capi-appfw-application"


DEPENDS = ""
#DEPENDS of capi-appfw-application 
DEPENDS += "aul-1"
DEPENDS += "sqlite3"
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "notification"
DEPENDS += "tizen-platform-config"
DEPENDS += "app-svc"
DEPENDS += "bundle"
DEPENDS += "app-core"
DEPENDS += "ail"
DEPENDS += "alarm-manager"
DEPENDS += "dlog"
DEPENDS += "elementary"
DEPENDS += "common"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-appfw-application.manifest .
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ; 
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
 LD_AS_NEEDED=1; export LD_AS_NEEDED ; 
 
 MAJORVER=`echo 0.1.0 | awk 'BEGIN {FS="."}{print $1}'`
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export FFLAGS ; 
   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=${prefix} \
         -DCMAKE_INSTALL_LIBDIR:PATH=${prefix}/lib \
         -DINCLUDE_INSTALL_DIR:PATH=${prefix}/include \
         -DLIB_INSTALL_DIR:PATH=${prefix}/lib \
         -DSYSCONF_INSTALL_DIR:PATH=${sysconfdir} \
         -DSHARE_INSTALL_PREFIX:PATH=${prefix}/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON . -DFULLVER=0.1.0 -DMAJORVER=${MAJORVER}
 
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}/usr/share/license
 cp LICENSE ${D}/usr/share/license/capi-appfw-application
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    /sbin/ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    /sbin/ldconfig
}

PACKAGES += " capi-appfw-application-dev "
PACKAGES += " capi-appfw-application "

capi-appfw-application-dev_files = ""
capi-appfw-application-dev_files += "capi-appfw-application.manifest"
capi-appfw-application-dev_files += "${prefix}/include/appfw/*.h"
capi-appfw-application-dev_files += "${prefix}/lib/pkgconfig/*.pc"
capi-appfw-application-dev_files += "${prefix}/lib/libcapi-appfw-application.so"

capi-appfw-application_files = ""
capi-appfw-application_files += "capi-appfw-application.manifest"
capi-appfw-application_files += "${prefix}/lib/libcapi-appfw-application.so.*"
capi-appfw-application_files += "capi-appfw-application.manifest"
capi-appfw-application_files += "/usr/share/license/capi-appfw-application"

FILES_${PN}-dev = "${capi-appfw-application-dev_files}"
FILES_${PN} = "${capi-appfw-application_files}"

PKG_capi-appfw-application-dev= "capi-appfw-application-dev"
PKG_capi-appfw-application= "capi-appfw-application"

require application-extraconf.inc

