DESCRIPTION = "X Display Manager Control Protocol library"
HOMEPAGE = "http://www.x.org"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libXdmcp-devel 
PROVIDES += "libXdmcp-devel"
RPROVIDES_libXdmcp-devel += "libXdmcp-devel"
RPROVIDES_libXdmcp-devel += "libXdmcp-dev"

#PROVIDES by libXdmcp 
PROVIDES += "libXdmcp"
RPROVIDES_libXdmcp += "libXdmcp"

RDEPENDS = ""
#RDEPENDS of libXdmcp-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libXdmcp"


DEPENDS = ""
#DEPENDS of libXdmcp 
DEPENDS += "pkgconfig(xproto)"
DEPENDS += "pkgconfig(xorg-macros)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libXdmcp.manifest .
 
 
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
 
 
   rm -rf ${D}/usr/share/info 
   rm -rf ${D}/usr/share/doc/packages 
   rm -rf ${D}/usr/share/doc/libXdmcp 
   rm -rf ${D}/usr/share/doc/libXdmcp-1.1.1 
   rm -rf ${D}/usr/share/gtk-doc 
   rm -rf ${D}/usr/share/doc 
   rm -rf ${D}/usr/share/man 
   find ${D} -regex ".*/man/man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/../man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/man./.*.[0-9]pm" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "libXdmcp-devel"
PACKAGES += "libXdmcp"

libXdmcp-devel_files = ""
libXdmcp-devel_files += "libXdmcp.manifest"
libXdmcp-devel_files += "/usr/include/X11/Xdmcp.h"
libXdmcp-devel_files += "/usr/lib/libXdmcp.so"
libXdmcp-devel_files += "/usr/lib/pkgconfig/xdmcp.pc"

libXdmcp_files = ""
libXdmcp_files += "libXdmcp.manifest"
libXdmcp_files += "/usr/lib/libXdmcp.so.6"
libXdmcp_files += "/usr/lib/libXdmcp.so.6.0.0"

FILES_${PN}-devel = "${libXdmcp-devel_files}"
FILES_${PN} = "${libXdmcp_files}"

PKG_libXdmcp-devel= "libXdmcp-devel"
PKG_libXdmcp= "libXdmcp"

require libXdmcp-extraconf.inc
