DESCRIPTION = "Enlightened Core X interface library"
HOMEPAGE = "http://www.enlightenment.org"
SECTION = "Graphics/EFL"
LICENSE = "BSD-2-clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by ecore-locale  
PROVIDES += "ecore-locale "
RPROVIDES_ecore-locale  += "ecore-locale "
# the PROVIDES rules is ignore "ecore-lang-all = 1.7.8"
PROVIDES += "ecore-lang-all"
RPROVIDES_ecore-locale  += "ecore-lang-all"

#PROVIDES by ecore 
PROVIDES += "ecore"
RPROVIDES_ecore += "ecore"

#PROVIDES by ecore-devel 
PROVIDES += "ecore-devel"
RPROVIDES_ecore-devel += "ecore-devel"
RPROVIDES_ecore-devel += "ecore-dev"

#PROVIDES by ecore-examples 
PROVIDES += "ecore-examples"
RPROVIDES_ecore-examples += "ecore-examples"

RDEPENDS = ""
#RDEPENDS of ecore-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "ecore"

#RDEPENDS of ecore-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "ecore"

#RDEPENDS of ecore-examples (${PN}-examples)
RDEPENDS_${PN}-examples += "ecore"


DEPENDS = ""
#DEPENDS of ecore 
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "doxygen"
DEPENDS += "pkgconfig(evas)"
DEPENDS += "pkgconfig(wayland-client)"
DEPENDS += "pkgconfig(eet)"
DEPENDS += "pkgconfig(egl)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(glesv2)"
DEPENDS += "libgcrypt-devel"
DEPENDS += "pkgconfig(pixman-1)"
DEPENDS += "pkgconfig(wayland-egl)"
DEPENDS += "pkgconfig(xkbcommon)"
DEPENDS += "curl"
DEPENDS += "pkgconfig(wayland-cursor)"
DEPENDS += "pkgconfig(eina)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/ecore.manifest .
 
 
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
         --infodir=/usr/share/info --enable-build-examples \
     --enable-ecore-wayland \
     --enable-ecore-evas-wayland-egl \
     --disable-ecore-x  \
     --enable-glib-integration-always \
     --disable-static
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
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} ecore
 
 
}

PACKAGES = ""
PACKAGES += "ecore"
PACKAGES += "ecore-devel"
PACKAGES += "ecore-locale"
PACKAGES += "ecore-examples"

ecore_files = ""
ecore_files += "ecore.manifest"
ecore_files += "/usr/lib/libecore*.so.*"
ecore_files += "/usr/lib/ecore/immodules/*.so"

ecore-devel_files = ""
ecore-devel_files += "ecore.manifest"
ecore-devel_files += "/usr/include/ecore-1/*.h"
ecore-devel_files += "/usr/lib/libecore*.so"
ecore-devel_files += "/usr/lib/pkgconfig/ecore.pc"
ecore-devel_files += "/usr/lib/pkgconfig/ecore-*.pc"

ecore-locale_files = ""

ecore-examples_files = ""
ecore-examples_files += "ecore.manifest"
ecore-examples_files += "/usr/lib/ecore/examples/*"

FILES_${PN} = "${ecore_files}"
FILES_${PN}-devel = "${ecore-devel_files}"
FILES_${PN}-locale = "${ecore-locale_files}"
FILES_${PN}-examples = "${ecore-examples_files}"

PKG_ecore= "ecore"
PKG_ecore-devel= "ecore-devel"
PKG_ecore-locale= "ecore-locale"
PKG_ecore-examples= "ecore-examples"

require ecore-extraconf.inc
