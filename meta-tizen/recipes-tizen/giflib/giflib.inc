DESCRIPTION = "Library for manipulating GIF format image files"
HOMEPAGE = "http://sourceforge.net/projects/giflib/"
SECTION = "System/Libraries"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by giflib 
PROVIDES += "giflib"
RPROVIDES_giflib += "giflib"

#PROVIDES by giflib-utils 
PROVIDES += "giflib-utils"
RPROVIDES_giflib-utils += "giflib-utils"

#PROVIDES by giflib-devel 
PROVIDES += "giflib-devel"
RPROVIDES_giflib-devel += "giflib-devel"
RPROVIDES_giflib-devel += "giflib-dev"

RDEPENDS = ""
#RDEPENDS of giflib-utils (${PN}-utils)
RDEPENDS_${PN}-utils += "giflib"

#RDEPENDS of giflib-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "giflib"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/giflib.manifest .
 
 
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
 
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=x86_64-tizen-linux \
         --program-prefix= \
         --prefix=/usr \
         --exec-prefix=/usr \
         --bindir=/usr/bin \
         --sbindir=/usr/sbin \
         --sysconfdir=/etc \
         --datadir=/usr/share \
         --includedir=/usr/include \
         --libdir=/usr/lib \
         --libexecdir=/usr/libexec \
         --localstatedir=/var \
         --sharedstatedir=/usr/com \
         --mandir=/usr/share/man \
         --infodir=/usr/share/info  \
   --disable-x11
 
 make -j16 all
 
 MAJOR=`echo '4.1.6' | sed 's/\([0-9]\+\)\..*/\1/'`
 gcc -O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -shared -Wl,-soname,libungif.so.$MAJOR -Llib/.libs -lgif -o libungif.so.4.1.6
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 install -m 0755 -p libungif.so.4.1.6 ${D}/usr/lib
 ln -sf libungif.so.4.1.6 ${D}/usr/lib/libungif.so.4
 ln -sf libungif.so.4 ${D}/usr/lib/libungif.so
 
 
 
}

PACKAGES = ""
PACKAGES += "giflib"
PACKAGES += "giflib-utils"
PACKAGES += "giflib-devel"

giflib_files = ""
giflib_files += "giflib.manifest"
giflib_files += "/usr/lib/lib*.so.*"

giflib-utils_files = ""
giflib-utils_files += "giflib.manifest"
giflib-utils_files += "/usr/bin/*"

giflib-devel_files = ""
giflib-devel_files += "giflib.manifest"
giflib-devel_files += "/usr/lib/lib*.so"
giflib-devel_files += "/usr/include/*.h"

FILES_${PN} = "${giflib_files}"
FILES_${PN}-utils = "${giflib-utils_files}"
FILES_${PN}-devel = "${giflib-devel_files}"

PKG_giflib= "giflib"
PKG_giflib-utils= "giflib-utils"
PKG_giflib-devel= "giflib-devel"

require giflib-extraconf.inc
