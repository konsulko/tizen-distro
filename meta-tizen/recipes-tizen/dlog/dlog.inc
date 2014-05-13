DESCRIPTION = "Logging service"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

PROVIDES = ""

#PROVIDES by libdlog 


#PROVIDES by dlogutil 


#PROVIDES by dlog 


#PROVIDES by libdlog-dev 


RDEPENDS = ""
#RDEPENDS of dlogutil (${PN}util)
RDEPENDS_${PN}util += "libdlog"
RDEPENDS_${PN}util += "systemd"

#RDEPENDS of libdlog-dev (lib${PN}-dev)
RDEPENDS_lib${PN}-dev += "libdlog"


DEPENDS = ""

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/dlog.manifest .
 
 
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
 
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   ./autogen.sh --build=${TARGET_SYS} --host=${HOST_SYS} \
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
         --infodir=${infodir} --disable-static \
 --without-systemd-journal
 
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
 mkdir -p ${D}/opt/etc/dump.d/default.d
 cp ${WORKDIR}/git/dlog_dump.sh ${D}/opt/etc/dump.d/default.d/dlog_dump.sh
 mkdir -p ${D}/usr/bin/
 cp ${WORKDIR}/git/dlogctrl ${D}/usr/bin/dlogctrl
 
 mkdir -p ${D}/lib/systemd/system/multi-user.target.wants
 
 install -m 0644 ${S}/packaging/dlog-main.service ${D}/lib/systemd/system
 install -m 0644 ${S}/packaging/dlog-radio.service ${D}/lib/systemd/system
 
 ln -s ../dlog-main.service ${D}/lib/systemd/system/multi-user.target.wants/dlog-main.service
 ln -s ../dlog-radio.service ${D}/lib/systemd/system/multi-user.target.wants/dlog-radio.service
 
 
 
}

PACKAGES += " libdlog "
PACKAGES += " dlogutil "
PACKAGES += " libdlog-dev "

libdlog_files = ""
libdlog_files += "dlog.manifest"
libdlog_files += "${prefix}/lib/libdlog.so.*"

dlogutil_files = ""
dlogutil_files += "dlog.manifest"
dlogutil_files += "/opt/etc/dump.d/default.d/dlog_dump.sh"
dlogutil_files += "${prefix}/bin/dlogutil"
dlogutil_files += "${prefix}/bin/dlogctrl"
dlogutil_files += "/lib/systemd/system/dlog-main.service"
dlogutil_files += "/lib/systemd/system/dlog-radio.service"
dlogutil_files += "/lib/systemd/system/multi-user.target.wants/dlog-main.service"
dlogutil_files += "/lib/systemd/system/multi-user.target.wants/dlog-radio.service"

libdlog-dev_files = ""
libdlog-dev_files += "dlog.manifest"
libdlog-dev_files += "${prefix}/include/dlog/dlog.h"
libdlog-dev_files += "${prefix}/lib/pkgconfig/dlog.pc"
libdlog-dev_files += "${prefix}/lib/libdlog.so"

FILES_lib${PN} = "${libdlog_files}"
FILES_${PN}util = "${dlogutil_files}"
FILES_lib${PN}-dev = "${libdlog-dev_files}"

PKG_libdlog= "libdlog"
PKG_dlogutil= "dlogutil"
PKG_libdlog-dev= "libdlog-dev"

require dlog-extraconf.inc

