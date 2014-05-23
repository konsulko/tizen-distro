DESCRIPTION = "System manager interface library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "framework-system"
LICENSE = "APLv2"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by sysman-internal-dev 


#PROVIDES by sysman-dev 


#PROVIDES by sysman 


RDEPENDS = ""
#RDEPENDS of sysman-internal-dev (sysman-internal-dev)
RDEPENDS_sysman-internal-dev += "sysman"

#RDEPENDS of sysman-dev (sysman-dev)
RDEPENDS_sysman-dev += "sysman"


DEPENDS = ""
#DEPENDS of sysman 
DEPENDS += "libdevice-node"
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "vconf"
DEPENDS += "dlog"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
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
         -DCMAKE_INSTALL_PREFIX:PATH=${prefix} \
         -DCMAKE_INSTALL_LIBDIR:PATH=${prefix}/lib \
         -DINCLUDE_INSTALL_DIR:PATH=${prefix}/include \
         -DLIB_INSTALL_DIR:PATH=${prefix}/lib \
         -DSYSCONF_INSTALL_DIR:PATH=${sysconfdir} \
         -DSHARE_INSTALL_PREFIX:PATH=${prefix}/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON .
 
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}${sysconfdir}/rc.d/
 mkdir -p ${D}${sysconfdir}/rc.d/rc3.d/
 mkdir -p ${D}${sysconfdir}/rc.d/rc5.d/
 ln -s ${prefix}/bin/regpmon.sh ${D}${sysconfdir}/rc.d/rc3.d/S99regpmon
 ln -s ${prefix}/bin/regpmon.sh ${D}${sysconfdir}/rc.d/rc5.d/S99regpmon
 
 
 
}

PACKAGES += " sysman-internal-dev "
PACKAGES += " sysman-dev "
PACKAGES += " sysman "

sysman-internal-dev_files = ""
sysman-internal-dev_files += "sysman.manifest"
sysman-internal-dev_files += "${prefix}/include/sysman/sysman-internal.h"

sysman-dev_files = ""
sysman-dev_files += "sysman.manifest"
sysman-dev_files += "${prefix}/include/sysman/sysman.h"
sysman-dev_files += "${prefix}/include/sysman/sysman_managed.h"
sysman-dev_files += "${prefix}/include/sysman/SLP_sysman_PG.h"
sysman-dev_files += "${prefix}/lib/pkgconfig/*.pc"
sysman-dev_files += "${prefix}/lib/*.so"

sysman_files = ""
sysman_files += "sysman.manifest"
sysman_files += "${prefix}/lib/*.so.*"
sysman_files += "${prefix}/bin/*"
sysman_files += "${sysconfdir}/rc.d/init.d/*"
sysman_files += "${sysconfdir}/rc.d/rc3.d/*"
sysman_files += "${sysconfdir}/rc.d/rc5.d/*"

FILES_${PN}-internal-dev = "${sysman-internal-dev_files}"
FILES_${PN}-dev = "${sysman-dev_files}"
FILES_${PN} = "${sysman_files}"

PKG_sysman-internal-dev= "sysman-internal-dev"
PKG_sysman-dev= "sysman-dev"
PKG_sysman= "sysman"

require libslp-sysman-extraconf.inc

