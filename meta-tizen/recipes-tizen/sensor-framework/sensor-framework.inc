DESCRIPTION = "Sensor framework"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Framework/system"
LICENSE = "Apache License, Version 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by sensor-framework 
PROVIDES += "sensor-framework"
RPROVIDES_sensor-framework += "sensor-framework"

RDEPENDS = ""
#RDEPENDS of sensor-framework (${PN})
RDEPENDS_${PN} += "/usr/bin/vconftool"


DEPENDS = ""
#DEPENDS of sensor-framework 
DEPENDS += "libsf-common"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "heynoti"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/sensor-framework.manifest .
 
 
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
 
 cmake . -DCMAKE_INSTALL_PREFIX=/usr -DPLATFORM_ARCH=arch_ia
 
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
 
 mkdir -p ${D}/usr/share/license
 cp LICENSE ${D}/usr/share/license/sensor-framework
 
 mkdir -p ${D}/usr/lib/systemd/system/multi-user.target.wants
 install -m 0644 ${S}/packaging/sensor-framework.service ${D}/usr/lib/systemd/system/
 ln -s ../sensor-framework.service ${D}/usr/lib/systemd/system/multi-user.target.wants/sensor-framework.service
 
 # FIXME: remove initscripts after we start using systemd
 mkdir -p ${D}/etc/rc.d/rc3.d
 mkdir -p ${D}/etc/rc.d/rc4.d
 ln -s ../init.d/sfsvc ${D}/etc/rc.d/rc3.d/S40sfsvc
 ln -s ../init.d/sfsvc ${D}/etc/rc.d/rc4.d/S40sfsvc
 
 
}

PACKAGES = ""
PACKAGES += "sensor-framework"

sensor-framework_files = ""
sensor-framework_files += "sensor-framework.manifest"
sensor-framework_files += "/etc/rc.d/rc3.d/S40sfsvc"
sensor-framework_files += "/etc/rc.d/rc4.d/S40sfsvc"
sensor-framework_files += "/usr/bin/sf_server"
sensor-framework_files += "/usr/lib/systemd/system/sensor-framework.service"
sensor-framework_files += "/usr/lib/systemd/system/multi-user.target.wants/sensor-framework.service"
sensor-framework_files += "/usr/share/license/sensor-framework"

FILES_${PN} = "${sensor-framework_files}"

PKG_sensor-framework= "sensor-framework"

require sensor-framework-extraconf.inc
