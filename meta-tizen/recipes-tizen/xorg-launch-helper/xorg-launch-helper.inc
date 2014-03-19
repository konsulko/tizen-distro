DESCRIPTION = "Xorg service helper"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Graphics/X Window System"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by xorg-launch-helper 
PROVIDES += "xorg-launch-helper"
RPROVIDES_xorg-launch-helper += "xorg-launch-helper"

RDEPENDS = ""
#RDEPENDS of xorg-launch-helper (${PN})
RDEPENDS_${PN} += "/usr/bin/Xorg"


DEPENDS = ""
#DEPENDS of xorg-launch-helper 
DEPENDS += "pkgconfig(systemd)"
DEPENDS += "systemd"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/xorg-launch-helper.manifest .
 
 
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
         --infodir=/usr/share/info
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
 
 # temoprary HW configuration. it should be seperated.
 mkdir -p ${D}/etc/sysconfig
 install -m 644 ${S}/packaging/xorg.conf ${D}/etc/sysconfig/xorg
 install -m 0644 ${S}/packaging/xorg_done.service ${D}/usr/lib/systemd/user/
 ln -sf ../xorg_done.service ${D}/usr/lib/systemd/user/xorg.target.wants
 
 # "-sharevt" option will be removed (only) for Tizen Emulator temporarily
 # by the request from Tizen SDK (kernel) team.
 
 
}

PACKAGES = ""
PACKAGES += "xorg-launch-helper"

xorg-launch-helper_files = ""
xorg-launch-helper_files += "xorg-launch-helper.manifest"
xorg-launch-helper_files += "/usr/bin/xorg-launch-helper"
xorg-launch-helper_files += "/usr/lib/systemd/user/xorg.service"
xorg-launch-helper_files += "/usr/lib/systemd/user/xorg_done.service"
xorg-launch-helper_files += "/usr/lib/systemd/user/xorg.target"
xorg-launch-helper_files += "/usr/lib/systemd/user/xorg.target.wants/xorg.service"
xorg-launch-helper_files += "/usr/lib/systemd/user/xorg.target.wants/xorg_done.service"
xorg-launch-helper_files += "/etc/sysconfig/xorg"

FILES_${PN} = "${xorg-launch-helper_files}"

PKG_xorg-launch-helper= "xorg-launch-helper"

require xorg-launch-helper-extraconf.inc
