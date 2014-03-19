DESCRIPTION = "OpenAL User Toolkit library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "TO_BE/FILLED_IN"
LICENSE = "TO BE FILLED IN"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by freealut-devel 
PROVIDES += "freealut-devel"
RPROVIDES_freealut-devel += "freealut-devel"
RPROVIDES_freealut-devel += "freealut-dev"

#PROVIDES by freealut 
PROVIDES += "freealut"
RPROVIDES_freealut += "freealut"

RDEPENDS = ""
#RDEPENDS of freealut-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "freealut"

#RDEPENDS of freealut (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"


DEPENDS = ""
#DEPENDS of freealut 
DEPENDS += "pkgconfig(openal)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 cp ${S}/packaging/freealut.manifest .
 
 
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
 
 rm -rf ${D}
 
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
PACKAGES += "freealut-devel"
PACKAGES += "freealut"

freealut-devel_files = ""
freealut-devel_files += "freealut.manifest"
freealut-devel_files += "/usr/include/AL/alut.h"
freealut-devel_files += "/usr/lib/libalut.so"
freealut-devel_files += "/usr/lib/pkgconfig/freealut.pc"

freealut_files = ""
freealut_files += "freealut.manifest"
freealut_files += "/usr/bin/freealut-config"
freealut_files += "/usr/lib/libalut.so.*"

FILES_${PN}-devel = "${freealut-devel_files}"
FILES_${PN} = "${freealut_files}"

PKG_freealut-devel= "freealut-devel"
PKG_freealut= "freealut"

require freealut-extraconf.inc
