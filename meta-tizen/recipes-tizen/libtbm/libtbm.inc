DESCRIPTION = "Tizen Buffer Manager Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libtbm 
PROVIDES += "libtbm"
RPROVIDES_libtbm += "libtbm"

#PROVIDES by libtbm-devel 
PROVIDES += "libtbm-devel"
RPROVIDES_libtbm-devel += "libtbm-devel"
RPROVIDES_libtbm-devel += "libtbm-dev"

RDEPENDS = ""
#RDEPENDS of libtbm-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "pkgconfig(libdrm)"
RDEPENDS_${PN}-devel += "libtbm"


DEPENDS = ""
#DEPENDS of libtbm 
DEPENDS += "pkgconfig(libdrm)"
DEPENDS += "libpthread-stubs"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libtbm.manifest .
 
 
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
         --infodir=/usr/share/info --prefix=/usr \
             CFLAGS="${CFLAGS} -Wall -Werror" LDFLAGS="${LDFLAGS} -Wl,--hash-style=both -Wl,--as-needed"
 
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
 mkdir -p ${D}/usr/share/license
 cp -af COPYING ${D}/usr/share/license/libtbm
 
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
PACKAGES += "libtbm"
PACKAGES += "libtbm-devel"

libtbm_files = ""
libtbm_files += "libtbm.manifest"
libtbm_files += "/usr/share/license/libtbm"
libtbm_files += "/usr/lib/libtbm.so.*"
libtbm_files += "/usr/lib/libdrm_slp.so.*"

libtbm-devel_files = ""
libtbm-devel_files += "libtbm.manifest"
libtbm-devel_files += "/usr/include"
libtbm-devel_files += "/usr/include/tbm_bufmgr.h"
libtbm-devel_files += "/usr/include/tbm_bufmgr_backend.h"
libtbm-devel_files += "/usr/lib/libtbm.so"
libtbm-devel_files += "/usr/lib/libdrm_slp.so"
libtbm-devel_files += "/usr/lib/pkgconfig/libtbm.pc"

FILES_${PN} = "${libtbm_files}"
FILES_${PN}-devel = "${libtbm-devel_files}"

PKG_libtbm= "libtbm"
PKG_libtbm-devel= "libtbm-devel"

require libtbm-extraconf.inc
