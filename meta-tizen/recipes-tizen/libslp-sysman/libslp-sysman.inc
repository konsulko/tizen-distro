DESCRIPTION = "System manager interface library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "framework-system"
LICENSE = "APLv2"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by sysman-internal-devel 
PROVIDES += "sysman-internal-devel"
RPROVIDES_sysman-internal-devel += "sysman-internal-devel"
RPROVIDES_sysman-internal-devel += "sysman-internal-dev"

#PROVIDES by sysman-devel 
PROVIDES += "sysman-devel"
RPROVIDES_sysman-devel += "sysman-devel"
RPROVIDES_sysman-devel += "sysman-dev"

#PROVIDES by sysman 
PROVIDES += "sysman"
RPROVIDES_sysman += "sysman"

RDEPENDS = ""
#RDEPENDS of sysman-internal-devel (sysman-internal-devel)
RDEPENDS_sysman-internal-devel += "sysman"

#RDEPENDS of sysman-devel (sysman-devel)
RDEPENDS_sysman-devel += "sysman"


DEPENDS = ""
#DEPENDS of sysman 
DEPENDS += "pkgconfig(devman_plugin)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "dlog"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 
 
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
 
 cp ${S}/packaging/sysman.manifest .
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export FFLAGS ; 
   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=/usr \
         -DCMAKE_INSTALL_LIBDIR:PATH=/usr/lib \
         -DINCLUDE_INSTALL_DIR:PATH=/usr/include \
         -DLIB_INSTALL_DIR:PATH=/usr/lib \
         -DSYSCONF_INSTALL_DIR:PATH=/etc \
         -DSHARE_INSTALL_PREFIX:PATH=/usr/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON \
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake .
 
 
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
 
 mkdir -p ${D}/etc/rc.d/
 mkdir -p ${D}/etc/rc.d/rc3.d/
 mkdir -p ${D}/etc/rc.d/rc5.d/
 ln -s /usr/bin/regpmon.sh ${D}/etc/rc.d/rc3.d/S99regpmon
 ln -s /usr/bin/regpmon.sh ${D}/etc/rc.d/rc5.d/S99regpmon
 
 
 
}

PACKAGES = ""
PACKAGES += "sysman-internal-devel"
PACKAGES += "sysman-devel"
PACKAGES += "sysman"

sysman-internal-devel_files = ""
sysman-internal-devel_files += "sysman.manifest"
sysman-internal-devel_files += "/usr/include/sysman/sysman-internal.h"

sysman-devel_files = ""
sysman-devel_files += "sysman.manifest"
sysman-devel_files += "/usr/include/sysman/sysman.h"
sysman-devel_files += "/usr/include/sysman/sysman_managed.h"
sysman-devel_files += "/usr/include/sysman/SLP_sysman_PG.h"
sysman-devel_files += "/usr/lib/pkgconfig/*.pc"
sysman-devel_files += "/usr/lib/*.so"

sysman_files = ""
sysman_files += "sysman.manifest"
sysman_files += "/usr/lib/*.so.*"
sysman_files += "/usr/bin/*"
sysman_files += "/etc/rc.d/init.d/*"
sysman_files += "/etc/rc.d/rc3.d/*"
sysman_files += "/etc/rc.d/rc5.d/*"

FILES_${PN}-internal-devel = "${sysman-internal-devel_files}"
FILES_${PN}-devel = "${sysman-devel_files}"
FILES_${PN} = "${sysman_files}"

PKG_sysman-internal-devel= "sysman-internal-devel"
PKG_sysman-devel= "sysman-devel"
PKG_sysman= "sysman"

require libslp-sysman-extraconf.inc
