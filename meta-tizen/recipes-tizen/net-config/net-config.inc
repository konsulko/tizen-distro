DESCRIPTION = "TIZEN Network Configuration Module"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Network"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by net-config 
PROVIDES += "net-config"
RPROVIDES_net-config += "net-config"

RDEPENDS = ""
#RDEPENDS of net-config (${PN})
RDEPENDS_${PN} += "systemd"
RDEPENDS_${PN} += "/usr/bin/vconftool"


DEPENDS = ""
#DEPENDS of net-config 
DEPENDS += "libwifi-direct"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(syspopup-caller)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(tapi)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(libsystemd-daemon)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "dbus-glib"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/net-config.manifest .
 
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DCMAKE_INSTALL_PREFIX=/usr
 
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
 
 mkdir -p ${D}/usr/share/dbus-1/system-services
 cp resources/usr/share/dbus-1/services/net.netconfig.service ${D}/usr/share/dbus-1/system-services/net.netconfig.service
 mkdir -p ${D}/etc/dbus-1/system.d
 cp resources/etc/dbus-1/system.d/net-config.conf ${D}/etc/dbus-1/system.d/net-config.conf
 mkdir -p ${D}/opt/etc
 cp resources/opt/etc/resolv.conf ${D}/opt/etc/resolv.conf
 
 # Systemd service file
 mkdir -p ${D}/lib/systemd/system
 cp resources/usr/lib/systemd/system/net-config.service ${D}/lib/systemd/system/net-config.service
 mkdir -p ${D}/lib/systemd/system/multi-user.target.wants/
 ln -s ../net-config.service ${D}/lib/systemd/system/multi-user.target.wants/net-config.service
 
 #License
 mkdir -p ${D}/usr/share/license
 cp LICENSE.APLv2 ${D}/usr/share/license/net-config
 
 
}

PACKAGES = ""
PACKAGES += "net-config"

net-config_files = ""
net-config_files += "net-config.manifest"
net-config_files += "/usr/sbin/*"
net-config_files += "/usr/share/dbus-1/system-services/*"
net-config_files += "/etc/dbus-1/system.d/*"
net-config_files += "/lib/systemd/system/net-config.service"
net-config_files += "/lib/systemd/system/multi-user.target.wants/net-config.service"
net-config_files += "/usr/share/license/net-config"

FILES_${PN} = "${net-config_files}"

PKG_net-config= "net-config"

require net-config-extraconf.inc
