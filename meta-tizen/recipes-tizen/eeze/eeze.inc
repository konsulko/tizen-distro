DESCRIPTION = "Device Convenience Library"
HOMEPAGE = "http://www.enlightenment.org/"
SECTION = "Graphics/EFL"
LICENSE = "BSD 2-clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by eeze-devel 
PROVIDES += "eeze-devel"
RPROVIDES_eeze-devel += "eeze-devel"
RPROVIDES_eeze-devel += "eeze-dev"

#PROVIDES by eeze 
PROVIDES += "eeze"
RPROVIDES_eeze += "eeze"

RDEPENDS = ""
#RDEPENDS of eeze-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "eeze"


DEPENDS = ""
#DEPENDS of eeze 
DEPENDS += "ecore"
DEPENDS += "pkgconfig(libudev)"
DEPENDS += "doxygen"
DEPENDS += "pkgconfig(udev)"
DEPENDS += "pkgconfig(eina)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/eeze.manifest .
 
 
 
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
PACKAGES += "eeze-devel"
PACKAGES += "eeze"

eeze-devel_files = ""
eeze-devel_files += "eeze.manifest"
eeze-devel_files += "/usr/include/eeze-1/*.h"
eeze-devel_files += "/usr/lib/*.so"
eeze-devel_files += "/usr/lib/pkgconfig/*.pc"

eeze_files = ""
eeze_files += "eeze.manifest"
eeze_files += "/usr/lib/libeeze.so.*"

FILES_${PN}-devel = "${eeze-devel_files}"
FILES_${PN} = "${eeze_files}"

PKG_eeze-devel= "eeze-devel"
PKG_eeze= "eeze"

require eeze-extraconf.inc
