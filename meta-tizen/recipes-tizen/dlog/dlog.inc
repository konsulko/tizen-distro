DESCRIPTION = "Logging service"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libdlog 
PROVIDES += "libdlog"
RPROVIDES_libdlog += "libdlog"

#PROVIDES by dlogutil 
PROVIDES += "dlogutil"
RPROVIDES_dlogutil += "dlogutil"

#PROVIDES by dlog 
PROVIDES += "dlog"
RPROVIDES_dlog += "dlog"

#PROVIDES by libdlog-devel 
PROVIDES += "libdlog-devel"
RPROVIDES_libdlog-devel += "libdlog-devel"
RPROVIDES_libdlog-devel += "libdlog-dev"

RDEPENDS = ""
#RDEPENDS of dlogutil (${PN}util)
RDEPENDS_${PN}util += "libdlog"
RDEPENDS_${PN}util += "/usr/bin/systemctl"

#RDEPENDS of libdlog-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "libdlog"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/dlog.manifest .
 
 
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
   ./autogen.sh --build=${TARGET_SYS} --host=${HOST_SYS} \
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
         --infodir=/usr/share/info
 
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
 --without-systemd-journal
 
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
 mkdir -p ${D}/opt/etc/dump.d/default.d
 cp ${WORKDIR}/dlog-0.4.1/dlog_dump.sh ${D}/opt/etc/dump.d/default.d/dlog_dump.sh
 mkdir -p ${D}/usr/bin/
 cp ${WORKDIR}/dlog-0.4.1/dlogctrl ${D}/usr/bin/dlogctrl
 
 mkdir -p ${D}/lib/systemd/system/basic.target.wants
 mkdir -p ${D}/lib/systemd/system/multi-user.target.wants
 
 install -m 0644 ${S}/packaging/dlog-main.service ${D}/lib/systemd/system
 install -m 0644 ${S}/packaging/dlog-radio.service ${D}/lib/systemd/system
 
 ln -s ../dlog-main.service ${D}/lib/systemd/system/multi-user.target.wants/dlog-main.service
 ln -s ../dlog-radio.service ${D}/lib/systemd/system/multi-user.target.wants/dlog-radio.service
 
 
 
}

PACKAGES = ""
PACKAGES += "libdlog"
PACKAGES += "dlogutil"
PACKAGES += "libdlog-devel"

libdlog_files = ""
libdlog_files += "dlog.manifest"
libdlog_files += "/usr/lib/libdlog.so.*"

dlogutil_files = ""
dlogutil_files += "dlog.manifest"
dlogutil_files += "/lib/systemd/system/dlog-main.service"
dlogutil_files += "/lib/systemd/system/dlog-radio.service"
dlogutil_files += "/lib/systemd/system/multi-user.target.wants/dlog-main.service"
dlogutil_files += "/lib/systemd/system/multi-user.target.wants/dlog-radio.service"

libdlog-devel_files = ""
libdlog-devel_files += "dlog.manifest"
libdlog-devel_files += "/usr/include/dlog/dlog.h"
libdlog-devel_files += "/usr/lib/pkgconfig/dlog.pc"
libdlog-devel_files += "/usr/lib/libdlog.so"

FILES_lib${PN} = "${libdlog_files}"
FILES_${PN}util = "${dlogutil_files}"
FILES_lib${PN}-devel = "${libdlog-devel_files}"

PKG_libdlog= "libdlog"
PKG_dlogutil= "dlogutil"
PKG_libdlog-devel= "libdlog-devel"

require dlog-extraconf.inc
