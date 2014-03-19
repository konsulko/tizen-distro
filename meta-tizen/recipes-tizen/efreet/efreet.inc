DESCRIPTION = "FreeDesktop"
HOMEPAGE = "http://www.enlightenment.org/"
SECTION = "Graphics/EFL"
LICENSE = "BSD 2-clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by efreet-locale  
PROVIDES += "efreet-locale "
RPROVIDES_efreet-locale  += "efreet-locale "
# the PROVIDES rules is ignore "efreet-lang-all = 1.7.8"
PROVIDES += "efreet-lang-all"
RPROVIDES_efreet-locale  += "efreet-lang-all"

#PROVIDES by efreet-devel 
PROVIDES += "efreet-devel"
RPROVIDES_efreet-devel += "efreet-devel"
RPROVIDES_efreet-devel += "efreet-dev"

#PROVIDES by efreet 
PROVIDES += "efreet"
RPROVIDES_efreet += "efreet"

RDEPENDS = ""
#RDEPENDS of efreet-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "efreet"

#RDEPENDS of efreet-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "efreet"


DEPENDS = ""
#DEPENDS of efreet 
DEPENDS += "pkgconfig(eina)"
DEPENDS += "ecore"
DEPENDS += "doxygen"
DEPENDS += "pkgconfig(ecore-file)"
DEPENDS += "pkgconfig(eet)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/efreet.manifest .
 
 
 
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
         --infodir=/usr/share/info --disable-static \
     --enable-icon-cache
 
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
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} efreet
 
 
}

PACKAGES = ""
PACKAGES += "efreet-locale"
PACKAGES += "efreet-devel"
PACKAGES += "efreet"

efreet-locale_files = ""

efreet-devel_files = ""
efreet-devel_files += "efreet.manifest"
efreet-devel_files += "/usr/include/efreet-1/*.h"
efreet-devel_files += "/usr/lib/*.so"
efreet-devel_files += "/usr/lib/pkgconfig/*.pc"

efreet_files = ""
efreet_files += "efreet.manifest"
efreet_files += "/usr/bin/efreet_*"
efreet_files += "/usr/lib/efreet/*"
efreet_files += "/usr/lib/libefreet*.so.*"
efreet_files += "/usr/share/efreet/*"

FILES_${PN}-locale = "${efreet-locale_files}"
FILES_${PN}-devel = "${efreet-devel_files}"
FILES_${PN} = "${efreet_files}"

PKG_efreet-locale= "efreet-locale"
PKG_efreet-devel= "efreet-devel"
PKG_efreet= "efreet"

require efreet-extraconf.inc
