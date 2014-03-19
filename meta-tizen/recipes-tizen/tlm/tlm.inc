DESCRIPTION = "Login manager for Tizen"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Service"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by tlm-devel 
PROVIDES += "tlm-devel"
RPROVIDES_tlm-devel += "tlm-devel"
RPROVIDES_tlm-devel += "tlm-dev"

#PROVIDES by tlm 
PROVIDES += "tlm"
RPROVIDES_tlm += "tlm"

#PROVIDES by tlm-doc 
PROVIDES += "tlm-doc"
RPROVIDES_tlm-doc += "tlm-doc"

RDEPENDS = ""
#RDEPENDS of tlm-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "tlm"

#RDEPENDS of tlm (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"

#RDEPENDS of tlm-doc (${PN}-doc)
RDEPENDS_${PN}-doc += "tlm"


DEPENDS = ""
#DEPENDS of tlm 
DEPENDS += "pkgconfig(libgum)"
DEPENDS += "pkgconfig(gio-2.0)"
DEPENDS += "pkgconfig(gmodule-2.0)"
DEPENDS += "pam"
DEPENDS += "pkgconfig(elementary)"
DEPENDS += "pkgconfig(gobject-2.0)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(gio-unix-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n tlm-0.0.2
 
 
 
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
         --infodir=/usr/share/info --enable-gum --enable-examples
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
 cp -a ${S}/packaging/tlm.manifest ${D}/usr/share/tlm.manifest
 
 
 
}

PACKAGES = ""
PACKAGES += "tlm-devel"
PACKAGES += "tlm"
PACKAGES += "tlm-doc"

tlm-devel_files = ""
tlm-devel_files += "/usr/include/tlm/*.h"
tlm-devel_files += "/usr/lib/libtlm*.so"
tlm-devel_files += "/usr/lib/pkgconfig/tlm.pc"
tlm-devel_files += "/usr/bin/tlm-ui"

tlm_files = ""
tlm_files += "/usr/share/tlm.manifest"
tlm_files += "AUTHORS COPYING INSTALL NEWS README"
tlm_files += "/usr/bin/tlm"
tlm_files += "/usr/lib/libtlm*.so.*"
tlm_files += "/usr/lib/tlm/plugins/*.so*"
tlm_files += "/etc/tlm.conf"

tlm-doc_files = ""
tlm-doc_files += "/usr/share/gtk-doc/html/tlm/*"

FILES_${PN}-devel = "${tlm-devel_files}"
FILES_${PN} = "${tlm_files}"
FILES_${PN}-doc = "${tlm-doc_files}"

PKG_tlm-devel= "tlm-devel"
PKG_tlm= "tlm"
PKG_tlm-doc= "tlm-doc"

require tlm-extraconf.inc
