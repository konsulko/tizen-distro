DESCRIPTION = "Systemd session units"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Base"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by user-session-units-enlightenment 
PROVIDES += "user-session-units-enlightenment"
RPROVIDES_user-session-units-enlightenment += "user-session-units-enlightenment"

#PROVIDES by user-session-units 
PROVIDES += "user-session-units"
RPROVIDES_user-session-units += "user-session-units"

#PROVIDES by user-session-units-gnome 
PROVIDES += "user-session-units-gnome"
RPROVIDES_user-session-units-gnome += "user-session-units-gnome"

RDEPENDS = ""
#RDEPENDS of user-session-units-enlightenment (${PN}-enlightenment)
RDEPENDS_${PN}-enlightenment += "user-session-units"

#RDEPENDS of user-session-units-gnome (${PN}-gnome)
RDEPENDS_${PN}-gnome += "user-session-units"


DEPENDS = ""
#DEPENDS of user-session-units 
DEPENDS += "pkgconfig(systemd)"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "systemd"
DEPENDS += "pam"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/user-session-units.manifest .
 
 
 
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
         --infodir=/usr/share/info --enable-gnome --enable-enlightenment
 
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
 
 install -m 755 -d ${D}/etc/pam.d
 install -m 644 ${S}/packaging/user-session.pam ${D}/etc/pam.d/user-session
 
 
 
}

PACKAGES = ""
PACKAGES += "user-session-units-enlightenment"
PACKAGES += "user-session-units"
PACKAGES += "user-session-units-gnome"

user-session-units-enlightenment_files = ""
user-session-units-enlightenment_files += "user-session-units.manifest"
user-session-units-enlightenment_files += "/lib/systemd/user/e17.target"
user-session-units-enlightenment_files += "/lib/systemd/user/enlightenment.service"
user-session-units-enlightenment_files += "/lib/systemd/user/e17.target.wants/enlightenment.service"

user-session-units_files = ""
user-session-units_files += "user-session-units.manifest"
user-session-units_files += "/usr/bin/user-session-launch"
user-session-units_files += "/lib/systemd/system/*"
user-session-units_files += "/etc/pam.d/user-session"

user-session-units-gnome_files = ""
user-session-units-gnome_files += "user-session-units.manifest"
user-session-units-gnome_files += "/lib/systemd/user/gnome.target"
user-session-units-gnome_files += "/lib/systemd/user/gnome-session.service"
user-session-units-gnome_files += "/lib/systemd/user/gnome.target.wants/gnome-session.service"

FILES_${PN}-enlightenment = "${user-session-units-enlightenment_files}"
FILES_${PN} = "${user-session-units_files}"
FILES_${PN}-gnome = "${user-session-units-gnome_files}"

PKG_user-session-units-enlightenment= "user-session-units-enlightenment"
PKG_user-session-units= "user-session-units"
PKG_user-session-units-gnome= "user-session-units-gnome"

require user-session-units-extraconf.inc
