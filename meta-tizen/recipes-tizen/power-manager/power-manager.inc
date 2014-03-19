DESCRIPTION = "Power manager"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Power Management"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by power-manager 
PROVIDES += "power-manager"
RPROVIDES_power-manager += "power-manager"

RDEPENDS = ""
#RDEPENDS of power-manager (${PN})
RDEPENDS_${PN} += "system-server"
RDEPENDS_${PN} += "/usr/bin/vconftool"


DEPENDS = ""
#DEPENDS of power-manager 
DEPENDS += "cmake"
DEPENDS += "pkgconfig(device-node)"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(sysman)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "libslp-sensor"
DEPENDS += "heynoti"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "devman"

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
 
 cp ${S}/packaging/power-manager.manifest .
 #for real device
 CFLAGS+=" -DX86"
 export CFLAGS
 
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
 
 mkdir -p ${D}/usr/lib/systemd/system/multi-user.target.wants
 install -m 0644 ${S}/packaging/power-manager.service ${D}/usr/lib/systemd/system/power-manager.service
 ln -s ../power-manager.service ${D}/usr/lib/systemd/system/multi-user.target.wants/power-manager.service
 
 
}

PACKAGES = ""
PACKAGES += "power-manager"

power-manager_files = ""
power-manager_files += "power-manager.manifest"
power-manager_files += "/usr/bin/pm_event"
power-manager_files += "/usr/bin/pmctrl"
power-manager_files += "/usr/bin/power_manager"
power-manager_files += "/usr/lib/systemd/system/power-manager.service"
power-manager_files += "/usr/lib/systemd/system/multi-user.target.wants/power-manager.service"
power-manager_files += "/usr/share/power-manager/udev-rules/91-power-manager.rules"

FILES_${PN} = "${power-manager_files}"

PKG_power-manager= "power-manager"

require power-manager-extraconf.inc
