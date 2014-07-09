DESCRIPTION = "Systemd session units"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Configuration"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by user-session-units-enlightenment


#PROVIDES by user-session-units


#PROVIDES by user-session-units-gnome


RDEPENDS = ""
#RDEPENDS of user-session-units-enlightenment (${PN}-enlightenment)
RDEPENDS_${PN}-enlightenment += "user-session-units"

#RDEPENDS of user-session-units-gnome (${PN}-gnome)
RDEPENDS_${PN}-gnome += "user-session-units"


DEPENDS = ""
#DEPENDS of user-session-units
DEPENDS += "systemd"
DEPENDS += "dbus"
DEPENDS += "libpam"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/user-session-units.manifest .
 
 
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
         --infodir=${infodir} --enable-gnome --enable-enlightenment
 oe_runmake -j16
 
 
 
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
 install -m 755 -d ${D}${sysconfdir}/pam.d
 install -m 644 ${S}/packaging/user-session.pam ${D}${sysconfdir}/pam.d/user-session
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " user-session-units-enlightenment "
PACKAGES += " user-session-units "
PACKAGES += " user-session-units-gnome "

user-session-units-enlightenment_files = ""
user-session-units-enlightenment_files += "user-session-units.manifest"
user-session-units-enlightenment_files += "/lib/systemd/user/e17.target"
user-session-units-enlightenment_files += "/lib/systemd/user/enlightenment.service"
user-session-units-enlightenment_files += "/lib/systemd/user/e17.target.wants/enlightenment.service"

user-session-units_files = ""
user-session-units_files += "user-session-units.manifest"
user-session-units_files += "${prefix}/bin/user-session-launch"
user-session-units_files += "/lib/systemd/system/*"
user-session-units_files += "${sysconfdir}/pam.d/user-session"

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

