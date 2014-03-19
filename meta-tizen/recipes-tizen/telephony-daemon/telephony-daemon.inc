DESCRIPTION = "Telephony daemon"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Telephony"
LICENSE = "Apache"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by telephony-daemon 
PROVIDES += "telephony-daemon"
RPROVIDES_telephony-daemon += "telephony-daemon"

RDEPENDS = ""
#RDEPENDS of telephony-daemon (${PN})
RDEPENDS_${PN} += "sys-assert"
RDEPENDS_${PN} += "systemd"


DEPENDS = ""
#DEPENDS of telephony-daemon 
DEPENDS += "systemd"
DEPENDS += "cmake"
DEPENDS += "libtcore"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(gobject-2.0)"
DEPENDS += "pkgconfig(glib-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/telephony-daemon.manifest .
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DVERSION=0.1.13
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
 mkdir -p ${D}/usr/lib/systemd/system/multi-user.target.wants
 ln -s ../telephony.service ${D}/usr/lib/systemd/system/multi-user.target.wants/telephony.service
 mkdir -p ${D}/usr/share/license
 
 
}

PACKAGES = ""
PACKAGES += "telephony-daemon"

telephony-daemon_files = ""
telephony-daemon_files += "telephony-daemon.manifest"
telephony-daemon_files += "/usr/bin/telephony-daemon"
telephony-daemon_files += "/usr/lib/systemd/system/telephony.service"
telephony-daemon_files += "/usr/lib/systemd/system/multi-user.target.wants/telephony.service"
telephony-daemon_files += "/usr/share/license/telephony-daemon"

FILES_${PN} = "${telephony-daemon_files}"

PKG_telephony-daemon= "telephony-daemon"

require telephony-daemon-extraconf.inc
