DESCRIPTION = "status library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "TBD"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by status


#PROVIDES by status-dev


RDEPENDS = ""
#RDEPENDS of status (${PN})
RDEPENDS_${PN} += "eglibc"

#RDEPENDS of status-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "status"


DEPENDS = ""
#DEPENDS of status
DEPENDS += "dbus"
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "vconf"
DEPENDS += "dlog"
DEPENDS += "aul"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/status.manifest .
 
 
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
 
 export LDFLAGS+="-Wl,--rpath=${prefix}/lib -Wl,--as-needed"
 
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
         -DBUILD_SHARED_LIBS:BOOL=ON \
         ${EXTRA_OECMAKE} .
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
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}/usr/share/license
 cp -f LICENSE ${D}/usr/share/license/status
 
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    init_vconf()
    {
        vconftool set -t int memory/private/libstatus/music/state 0 -i -g 5000
        vconftool set -t int memory/private/libstatus/radio/state 0 -i -g 5000
        vconftool set -t int memory/private/libstatus/vr/state 0 -i -g 5000
        vconftool set -t int memory/private/libstatus/music/pid -1 -i -g 5000
        vconftool set -t int memory/private/libstatus/radio/pid -1 -i -g 5000
        vconftool set -t int memory/private/libstatus/vr/pid -1 -i -g 5000
        vconftool set -t string memory/private/libstatus/message "" -i -g 5000
    }
    ldconfig
    init_vconf

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " status "
PACKAGES += " status-dev "

status_files = ""
status_files += "status.manifest"
status_files += "${prefix}/lib/*.so*"
status_files += "/usr/share/license/status"

status-dev_files = ""
status-dev_files += "status.manifest"
status-dev_files += "${prefix}/include/status/*.h"
status-dev_files += "${prefix}/lib/pkgconfig/*.pc"

FILES_${PN} = "${status_files}"
FILES_${PN}-dev = "${status-dev_files}"

PKG_status= "status"
PKG_status-dev= "status-dev"

require status-extraconf.inc

