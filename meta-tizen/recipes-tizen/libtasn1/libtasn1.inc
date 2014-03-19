DESCRIPTION = "ASN"
HOMEPAGE = "http://ftp.gnu.org/gnu/libtasn1/"
SECTION = "Security/Crypto Libraries"
LICENSE = "LGPL-2.1+ and GPL-3.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libtasn1-tools 
PROVIDES += "libtasn1-tools"
RPROVIDES_libtasn1-tools += "libtasn1-tools"

#PROVIDES by libtasn1-docs  
PROVIDES += "libtasn1-docs "
RPROVIDES_libtasn1-docs  += "libtasn1-docs "

#PROVIDES by libtasn1 
PROVIDES += "libtasn1"
RPROVIDES_libtasn1 += "libtasn1"

#PROVIDES by libtasn1-devel 
PROVIDES += "libtasn1-devel"
RPROVIDES_libtasn1-devel += "libtasn1-devel"
RPROVIDES_libtasn1-devel += "libtasn1-dev"

RDEPENDS = ""
#RDEPENDS of libtasn1-tools (${PN}-tools)
RDEPENDS_${PN}-tools += "libtasn1"

#RDEPENDS of libtasn1 (${PN})
RDEPENDS_${PN} += "libtasn1-tools"

#RDEPENDS of libtasn1-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libtasn1"


DEPENDS = ""
#DEPENDS of libtasn1 
DEPENDS += "info"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libtasn1.manifest .
 
 
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
PACKAGES += "libtasn1-tools"
PACKAGES += "libtasn1-docs"
PACKAGES += "libtasn1"
PACKAGES += "libtasn1-devel"

libtasn1-tools_files = ""
libtasn1-tools_files += "libtasn1.manifest"
libtasn1-tools_files += "/usr/bin/*"

libtasn1-docs_files = ""
libtasn1-docs_files += "/usr/share/info"
libtasn1-docs_files += "/usr/share/man"

libtasn1_files = ""
libtasn1_files += "libtasn1.manifest"
libtasn1_files += "/usr/lib/*.so.*"

libtasn1-devel_files = ""
libtasn1-devel_files += "libtasn1.manifest"
libtasn1-devel_files += "/usr/include/*.h"
libtasn1-devel_files += "/usr/lib/*.so"
libtasn1-devel_files += "/usr/lib/pkgconfig/libtasn1.pc"

FILES_${PN}-tools = "${libtasn1-tools_files}"
FILES_${PN}-docs = "${libtasn1-docs_files}"
FILES_${PN} = "${libtasn1_files}"
FILES_${PN}-devel = "${libtasn1-devel_files}"

PKG_libtasn1-tools= "libtasn1-tools"
PKG_libtasn1-docs= "libtasn1-docs"
PKG_libtasn1= "libtasn1"
PKG_libtasn1-devel= "libtasn1-devel"

require libtasn1-extraconf.inc
