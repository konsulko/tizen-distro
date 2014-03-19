DESCRIPTION = "Message Port library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Application Framework/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by message-port-devel 
PROVIDES += "message-port-devel"
RPROVIDES_message-port-devel += "message-port-devel"
RPROVIDES_message-port-devel += "message-port-dev"

#PROVIDES by message-port 
PROVIDES += "message-port"
RPROVIDES_message-port += "message-port"
# the PROVIDES rules is ignore "libmessage-port.so.1  "
PROVIDES += "libmessage-port.so.1"
RPROVIDES_message-port += "libmessage-port.so.1"

RDEPENDS = ""
#RDEPENDS of message-port-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "message-port"

#RDEPENDS of message-port (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"
RDEPENDS_${PN} += "chromium"
RDEPENDS_${PN} += "coreutils"


DEPENDS = ""
#DEPENDS of message-port 
DEPENDS += "cmake"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "bundle"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "chromium"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/message-port.manifest .
 
 
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
 
 MAJORVER=`echo 1.2.2.1 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DFULLVER=1.2.2.1 -DMAJORVER=${MAJORVER}
 
 # Call make instruction with smp support
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
 
 
}

PACKAGES = ""
PACKAGES += "message-port-devel"
PACKAGES += "message-port"

message-port-devel_files = ""
message-port-devel_files += "message-port.manifest"
message-port-devel_files += "/usr/include/appfw/*.h"
message-port-devel_files += "/usr/lib/pkgconfig/*.pc"
message-port-devel_files += "/usr/lib/libmessage-port.so"

message-port_files = ""
message-port_files += "message-port.manifest"
message-port_files += "/usr/lib/libmessage-port.so.*"
message-port_files += "message-port.manifest"

FILES_${PN}-devel = "${message-port-devel_files}"
FILES_${PN} = "${message-port_files}"

PKG_message-port-devel= "message-port-devel"
PKG_message-port= "message-port"

require message-port-extraconf.inc
