DESCRIPTION = "Sound Manager library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

PROVIDES = ""

#PROVIDES by capi-media-sound-manager-dev 


#PROVIDES by capi-media-sound-manager 


RDEPENDS = ""
#RDEPENDS of capi-media-sound-manager-dev (capi-media-${PN}-dev)
RDEPENDS_capi-media-${PN}-dev += "capi-media-sound-manager"


DEPENDS = ""
#DEPENDS of capi-media-sound-manager 
DEPENDS += "libmm-sound"
DEPENDS_append_class-native = " cmake-native"
DEPENDS += "libmm-session"
DEPENDS += "dlog"
DEPENDS += "common"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-media-sound-manager.manifest .
 
 
 
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
 
 MAJORVER=`echo 0.1.1 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DBUILD_SHARED_LIBS:BOOL=ON . -DFULLVER=0.1.1 -DMAJORVER=${MAJORVER}
 
 
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
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 
}

PACKAGES += " capi-media-sound-manager-dev "
PACKAGES += " capi-media-sound-manager "

capi-media-sound-manager-dev_files = ""
capi-media-sound-manager-dev_files += "capi-media-sound-manager.manifest"
capi-media-sound-manager-dev_files += "${prefix}/include/media/sound_manager.h"
capi-media-sound-manager-dev_files += "${prefix}/lib/pkgconfig/*.pc"
capi-media-sound-manager-dev_files += "${prefix}/lib/libcapi-media-sound-manager.so"

capi-media-sound-manager_files = ""
capi-media-sound-manager_files += "capi-media-sound-manager.manifest"
capi-media-sound-manager_files += "${prefix}/lib/libcapi-media-sound-manager.so.*"
capi-media-sound-manager_files += "capi-media-sound-manager.manifest"

FILES_${PN}-dev = "${capi-media-sound-manager-dev_files}"
FILES_${PN} = "${capi-media-sound-manager_files}"

PKG_capi-media-sound-manager-dev= "capi-media-sound-manager-dev"
PKG_capi-media-sound-manager= "capi-media-sound-manager"

require sound-manager-extraconf.inc

