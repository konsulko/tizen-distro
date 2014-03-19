DESCRIPTION = "A SMS/MMS library in Tizen Native API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Messaging/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-messaging-messages 
PROVIDES += "capi-messaging-messages"
RPROVIDES_capi-messaging-messages += "capi-messaging-messages"

#PROVIDES by capi-messaging-messages-devel 
PROVIDES += "capi-messaging-messages-devel"
RPROVIDES_capi-messaging-messages-devel += "capi-messaging-messages-devel"
RPROVIDES_capi-messaging-messages-devel += "capi-messaging-messages-dev"

RDEPENDS = ""
#RDEPENDS of capi-messaging-messages-devel (capi-messaging-${PN}-devel)
RDEPENDS_capi-messaging-${PN}-devel += "capi-messaging-messages"
RDEPENDS_capi-messaging-${PN}-devel += "pkgconfig(capi-base-common)"
RDEPENDS_capi-messaging-${PN}-devel += "pkgconfig(msg-service)"


DEPENDS = ""
#DEPENDS of capi-messaging-messages 
DEPENDS += "pkgconfig(msg-service)"
DEPENDS += "dlog"
DEPENDS += "common"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(capi-appfw-application)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-messaging-messages.manifest .
 
 
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
 
 MAJORVER=`echo 0.1.25 | awk 'BEGIN {FS="."}{print $1}'`
 rm -fr cmake_build_tmp; mkdir cmake_build_tmp
 cd cmake_build_tmp
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export FFLAGS ; 
   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=/usr \
         -DCMAKE_INSTALL_LIBDIR:PATH=/usr/lib \
         -DINCLUDE_INSTALL_DIR:PATH=/usr/include \
         -DLIB_INSTALL_DIR:PATH=/usr/lib \
         -DSYSCONF_INSTALL_DIR:PATH=/etc \
         -DSHARE_INSTALL_PREFIX:PATH=/usr/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON \
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake .. -DFULLVER=0.1.25 -DMAJORVER=${MAJORVER}
 
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 cd cmake_build_tmp
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "capi-messaging-messages"
PACKAGES += "capi-messaging-messages-devel"

capi-messaging-messages_files = ""
capi-messaging-messages_files += "capi-messaging-messages.manifest"
capi-messaging-messages_files += "/usr/lib/libcapi-messaging-messages.so.*"

capi-messaging-messages-devel_files = ""
capi-messaging-messages-devel_files += "capi-messaging-messages.manifest"
capi-messaging-messages-devel_files += "/usr/include/messaging/*.h"
capi-messaging-messages-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-messaging-messages-devel_files += "/usr/lib/libcapi-messaging-messages.so"

FILES_${PN} = "${capi-messaging-messages_files}"
FILES_${PN}-devel = "${capi-messaging-messages-devel_files}"

PKG_capi-messaging-messages= "capi-messaging-messages"
PKG_capi-messaging-messages-devel= "capi-messaging-messages-devel"

require messages-extraconf.inc
