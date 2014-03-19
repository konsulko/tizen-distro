DESCRIPTION = "Multitouch Protocol Translation Library"
HOMEPAGE = "http://bitmath.org/code/mtdev/"
SECTION = "System/Libraries"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by mtdev 
PROVIDES += "mtdev"
RPROVIDES_mtdev += "mtdev"

#PROVIDES by mtdev-devel 
PROVIDES += "mtdev-devel"
RPROVIDES_mtdev-devel += "mtdev-devel"
RPROVIDES_mtdev-devel += "mtdev-dev"

#PROVIDES by libmtdev 
PROVIDES += "libmtdev"
RPROVIDES_libmtdev += "libmtdev"

RDEPENDS = ""
#RDEPENDS of mtdev-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "libmtdev"


DEPENDS = ""
#DEPENDS of mtdev 
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/mtdev.manifest .
 
 
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
         --infodir=/usr/share/info --disable-static
 make -j16
 
 
 
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
 
 
}

PACKAGES = ""
PACKAGES += "mtdev"
PACKAGES += "mtdev-devel"
PACKAGES += "libmtdev"

mtdev_files = ""
mtdev_files += "mtdev.manifest"
mtdev_files += "COPYING"
mtdev_files += "/usr/bin/*"

mtdev-devel_files = ""
mtdev-devel_files += "mtdev.manifest"
mtdev-devel_files += "/usr/lib/lib*.so"
mtdev-devel_files += "/usr/include/*"
mtdev-devel_files += "/usr/lib/pkgconfig/*.pc"

libmtdev_files = ""
libmtdev_files += "mtdev.manifest"
libmtdev_files += "/usr/lib/lib*.so.*"

FILES_${PN} = "${mtdev_files}"
FILES_${PN}-devel = "${mtdev-devel_files}"
FILES_lib${PN} = "${libmtdev_files}"

PKG_mtdev= "mtdev"
PKG_mtdev-devel= "mtdev-devel"
PKG_libmtdev= "libmtdev"

require mtdev-extraconf.inc
