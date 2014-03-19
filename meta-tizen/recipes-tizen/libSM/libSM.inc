DESCRIPTION = "X Session Management library"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libSM-devel 
PROVIDES += "libSM-devel"
RPROVIDES_libSM-devel += "libSM-devel"
RPROVIDES_libSM-devel += "libSM-dev"

#PROVIDES by libSM 
PROVIDES += "libSM"
RPROVIDES_libSM += "libSM"

RDEPENDS = ""
#RDEPENDS of libSM-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libSM"


DEPENDS = ""
#DEPENDS of libSM 
DEPENDS += "pkgconfig(xtrans)"
DEPENDS += "pkgconfig(xorg-macros)"
DEPENDS += "pkgconfig-native"
DEPENDS += "libICE"
DEPENDS += "pkgconfig(uuid)"
DEPENDS += "pkgconfig(xproto)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libSM.manifest .
 
 
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
         --infodir=/usr/share/info --with-libuuid --docdir=/usr/share/doc/packages/libSM --disable-static
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
PACKAGES += "libSM-devel"
PACKAGES += "libSM"

libSM-devel_files = ""
libSM-devel_files += "libSM.manifest"
libSM-devel_files += "/usr/include/X11/*"
libSM-devel_files += "/usr/lib/libSM.so"
libSM-devel_files += "/usr/lib/pkgconfig/sm.pc"
libSM-devel_files += "/usr/share/doc/packages/libSM"

libSM_files = ""
libSM_files += "libSM.manifest"
libSM_files += "/usr/lib/libSM.so.6*"

FILES_${PN}-devel = "${libSM-devel_files}"
FILES_${PN} = "${libSM_files}"

PKG_libSM-devel= "libSM-devel"
PKG_libSM= "libSM"

require libSM-extraconf.inc
