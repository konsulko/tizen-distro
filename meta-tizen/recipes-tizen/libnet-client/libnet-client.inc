DESCRIPTION = "Network Client library (Shared library)"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Network"
LICENSE = "Flora License"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by libnet-client-dev


#PROVIDES by libnet-client


RDEPENDS = ""
#RDEPENDS of libnet-client-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "libnet-client"

#RDEPENDS of libnet-client (${PN})
RDEPENDS_${PN} += "eglibc"


DEPENDS = ""
#DEPENDS of libnet-client
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "dbus"
DEPENDS += "dlog"
DEPENDS += "glib-2.0"
DEPENDS += "vconf"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libnet-client.manifest .
 
 
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
 
 mkdir -p m4
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=x86_64-tizen-linux \
         --program-prefix= \
         --prefix=${prefix} \
         --exec-prefix=${prefix} \
         --bindir=${prefix}/bin \
         --sbindir=${prefix}/sbin \
         --sysconfdir=${sysconfdir} \
         --datadir=${prefix}/share \
         --includedir=${prefix}/include \
         --libdir=${prefix}/lib \
         --libexecdir=${prefix}/libexec \
         --localstatedir=${localstatedir} \
         --sharedstatedir=${prefix}/com \
         --mandir=${mandir} \
         --infodir=${infodir}
 oe_runmake ${PARALLEL_MAKE}
 
 
 
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
 
 #License
 mkdir -p ${D}${prefix}/share/license
 cp LICENSE.Flora ${D}${prefix}/share/license/libnet-client
 
 #Make test app
 cd test
 mkdir ./lib
 cp -rf ${D}${prefix}/lib/* ./lib/
 ./build.sh
 cd ..
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " libnet-client-dev "
PACKAGES += " libnet-client "

libnet-client-dev_files = ""
libnet-client-dev_files += "libnet-client.manifest"
libnet-client-dev_files += "${prefix}/include/network/*.h"
libnet-client-dev_files += "${prefix}/lib/pkgconfig/network.pc"

libnet-client_files = ""
libnet-client_files += "libnet-client.manifest"
libnet-client_files += "${prefix}/lib/libnetwork.so"
libnet-client_files += "${prefix}/lib/libnetwork.so.0"
libnet-client_files += "${prefix}/lib/libnetwork.so.0.0.0"
libnet-client_files += "${prefix}/share/license/libnet-client"

FILES_${PN}-dev = "${libnet-client-dev_files}"
FILES_${PN} = "${libnet-client_files}"

PKG_libnet-client-dev= "libnet-client-dev"
PKG_libnet-client= "libnet-client"

require libnet-client-extraconf.inc

