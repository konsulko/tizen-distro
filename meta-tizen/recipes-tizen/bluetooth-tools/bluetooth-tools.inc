DESCRIPTION = "Bluetooth-tools"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Network & Connectivity/Bluetooth"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by bluetooth-tools-no-firmware 
PROVIDES += "bluetooth-tools-no-firmware"
RPROVIDES_bluetooth-tools-no-firmware += "bluetooth-tools-no-firmware"

#PROVIDES by bluetooth-tools 
PROVIDES += "bluetooth-tools"
RPROVIDES_bluetooth-tools += "bluetooth-tools"

RDEPENDS = ""
#RDEPENDS of bluetooth-tools-no-firmware (${PN}-no-firmware)
RDEPENDS_${PN}-no-firmware += "bluetooth-tools"
RDEPENDS_${PN}-no-firmware += "rfkill"

#RDEPENDS of bluetooth-tools (${PN})
RDEPENDS_${PN} += "tizen-platform-config-tools"


DEPENDS = ""
#DEPENDS of bluetooth-tools 
DEPENDS += "cmake"

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
 
 export CFLAGS+=" -fpie -fvisibility=hidden"
 export LDFLAGS+=" -Wl,--rpath=/usr/lib -Wl,--as-needed -Wl,--unresolved-symbols=ignore-in-shared-libs -pie"
 
 
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
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}/etc/rc.d/rc3.d
 mkdir -p ${D}/etc/rc.d/rc5.d
 ln -s /etc/rc.d/init.d/bluetooth-address ${D}/etc/rc.d/rc3.d/S60bluetooth-address
 ln -s /etc/rc.d/init.d/bluetooth-address ${D}/etc/rc.d/rc5.d/S60bluetooth-address
 
 mkdir -p ${D}/lib/systemd/system/multi-user.target.wants
 install -m 0644 ${S}/packaging/bluetooth-address.service ${D}/lib/systemd/system
 ln -s ../bluetooth-address.service ${D}/lib/systemd/system/multi-user.target.wants/bluetooth-address.service
 
 mkdir -p ${D}/usr/etc/bluetooth/
 install -m 0755 scripts/bt-dev-start.sh ${D}/usr/etc/bluetooth/bt-dev-start.sh
 install -m 0755 scripts/bt-dev-end.sh ${D}/usr/etc/bluetooth/bt-dev-end.sh
 
 
}

PACKAGES = ""
PACKAGES += "bluetooth-tools-no-firmware"
PACKAGES += "bluetooth-tools"

bluetooth-tools-no-firmware_files = ""
bluetooth-tools-no-firmware_files += "bluetooth-tools.manifest"

bluetooth-tools_files = ""
bluetooth-tools_files += "bluetooth-tools.manifest"
bluetooth-tools_files += "/etc/rc.d/init.d/bluetooth-address"
bluetooth-tools_files += "/etc/rc.d/rc3.d/S60bluetooth-address"
bluetooth-tools_files += "/etc/rc.d/rc5.d/S60bluetooth-address"
bluetooth-tools_files += "/lib/systemd/system/multi-user.target.wants/bluetooth-address.service"
bluetooth-tools_files += "/lib/systemd/system/bluetooth-address.service"

FILES_${PN}-no-firmware = "${bluetooth-tools-no-firmware_files}"
FILES_${PN} = "${bluetooth-tools_files}"

PKG_bluetooth-tools-no-firmware= "bluetooth-tools-no-firmware"
PKG_bluetooth-tools= "bluetooth-tools"

require bluetooth-tools-extraconf.inc
