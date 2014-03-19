DESCRIPTION = "X11 Inter-Client Exchange Library"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libICE 
PROVIDES += "libICE"
RPROVIDES_libICE += "libICE"

#PROVIDES by libICE-devel 
PROVIDES += "libICE-devel"
RPROVIDES_libICE-devel += "libICE-devel"
RPROVIDES_libICE-devel += "libICE-dev"

RDEPENDS = ""
#RDEPENDS of libICE-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libICE"


DEPENDS = ""
#DEPENDS of libICE 
DEPENDS += "pkgconfig(xproto)"
DEPENDS += "pkgconfig-native"
DEPENDS += "pkgconfig(xtrans)"
DEPENDS += "pkgconfig(xorg-macros)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libICE.manifest .
 
 
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
         --infodir=/usr/share/info --docdir=/usr/share/doc/packages/libICE --disable-static
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
PACKAGES += "libICE"
PACKAGES += "libICE-devel"

libICE_files = ""
libICE_files += "libICE.manifest"
libICE_files += "/usr/lib/libICE.so.6*"

libICE-devel_files = ""
libICE-devel_files += "libICE.manifest"
libICE-devel_files += "/usr/include/X11/*"
libICE-devel_files += "/usr/lib/libICE.so"
libICE-devel_files += "/usr/lib/pkgconfig/ice.pc"
libICE-devel_files += "/usr/share/doc/packages/libICE"

FILES_${PN} = "${libICE_files}"
FILES_${PN}-devel = "${libICE-devel_files}"

PKG_libICE= "libICE"
PKG_libICE-devel= "libICE-devel"

require libICE-extraconf.inc
