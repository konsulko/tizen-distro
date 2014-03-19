DESCRIPTION = "Library for speedy data storage, retrieval, and compression"
HOMEPAGE = "http://www.enlightenment.org/"
SECTION = "Graphics & UI Framework/Libraries"
LICENSE = "BSD-2-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by eet 
PROVIDES += "eet"
RPROVIDES_eet += "eet"

#PROVIDES by eet-devel 
PROVIDES += "eet-devel"
RPROVIDES_eet-devel += "eet-devel"
RPROVIDES_eet-devel += "eet-dev"

#PROVIDES by eet-tools 
PROVIDES += "eet-tools"
RPROVIDES_eet-tools += "eet-tools"
# the PROVIDES rules is ignore "eet-bin  "
PROVIDES += "eet-bin"
RPROVIDES_eet-tools += "eet-bin"

RDEPENDS = ""
#RDEPENDS of eet-tools (${PN}-tools)
RDEPENDS_${PN}-tools += "eet"

#RDEPENDS of eet-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "eet"


DEPENDS = ""
#DEPENDS of eet 
DEPENDS += "doxygen"
DEPENDS += "libjpeg-devel"
DEPENDS += "pkgconfig(openssl)"
DEPENDS += "libgcrypt-devel"
DEPENDS += "pkgconfig(gnutls)"
DEPENDS += "pkgconfig(eina)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/eet.manifest .
 
 
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
PACKAGES += "eet-tools"
PACKAGES += "eet-devel"
PACKAGES += "eet"

eet-tools_files = ""
eet-tools_files += "eet.manifest"
eet-tools_files += "/usr/bin/eet"

eet-devel_files = ""
eet-devel_files += "eet.manifest"
eet-devel_files += "/usr/include/eet-1/*.h"
eet-devel_files += "/usr/lib/*.so"
eet-devel_files += "/usr/lib/pkgconfig/*.pc"
eet-devel_files += "/usr/share/eet/examples/eet-basic.c"
eet-devel_files += "/usr/share/eet/examples/eet-data-cipher_decipher.c"
eet-devel_files += "/usr/share/eet/examples/eet-data-file_descriptor_01.c"
eet-devel_files += "/usr/share/eet/examples/eet-data-file_descriptor_02.c"
eet-devel_files += "/usr/share/eet/examples/eet-data-nested.c"
eet-devel_files += "/usr/share/eet/examples/eet-data-simple.c"
eet-devel_files += "/usr/share/eet/examples/eet-file.c"

eet_files = ""
eet_files += "eet.manifest"
eet_files += "/usr/lib/libeet*.so.*"

FILES_${PN}-tools = "${eet-tools_files}"
FILES_${PN}-devel = "${eet-devel_files}"
FILES_${PN} = "${eet_files}"

PKG_eet-tools= "eet-tools"
PKG_eet-devel= "eet-devel"
PKG_eet= "eet"

require eet-extraconf.inc
