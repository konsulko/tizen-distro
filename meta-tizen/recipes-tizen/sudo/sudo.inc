DESCRIPTION = "Execute some commands as root"
HOMEPAGE = "http://www.sudo.ws/"
SECTION = "System/Base"
LICENSE = "ISC"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by sudo-devel 
PROVIDES += "sudo-devel"
RPROVIDES_sudo-devel += "sudo-devel"
RPROVIDES_sudo-devel += "sudo-dev"

#PROVIDES by sudo 
PROVIDES += "sudo"
RPROVIDES_sudo += "sudo"

#PROVIDES by sudo-locale  
PROVIDES += "sudo-locale "
RPROVIDES_sudo-locale  += "sudo-locale "
# the PROVIDES rules is ignore "sudo-lang-all = 1.8.7"
PROVIDES += "sudo-lang-all"
RPROVIDES_sudo-locale  += "sudo-lang-all"

RDEPENDS = ""
#RDEPENDS of sudo (${PN})
RDEPENDS_${PN} += "coreutils"

#RDEPENDS of sudo-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "sudo"


DEPENDS = ""
#DEPENDS of sudo 
DEPENDS += "groff"
DEPENDS += "pam"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/sudo.manifest .
 
 
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
 
 F_PIE=-fpie
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -Wall $F_PIE -DLDAP_DEPRECATED"
 export LDFLAGS="-pie"
 
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
         --infodir=/usr/share/info \
 --libexecdir=/usr/libexec/sudo \
 --docdir=/usr/share/doc/packages/sudo \
 --with-noexec=/usr/libexec/sudo/sudo_noexec.so \
 --with-pam \
 --with-logfac=auth \
 --without-insults \
 --with-ignore-dot \
 --with-tty-tickets \
 --enable-shell-sets-home \
 --enable-warnings \
 --with-sudoers-mode=0440 \
 --with-env-editor \
 --without-secure-path \
 --with-passprompt='%p\x27s password:' \
 --with-timedir=/var/lib/sudo
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
 install -d -m 755 ${D}/etc/pam.d
 install -m 644 ${S}/packaging/sudo.pamd ${D}/etc/pam.d/sudo
 rm -f ${D}/usr/bin/sudoedit
 ln -sf /usr/bin/sudo ${D}/usr/bin/sudoedit
 rm -f ${D}/usr/share/doc/packages/sudo/sample.pam
 rm -f ${D}/usr/share/doc/packages/sudo/sample.syslog.conf
 rm -f ${D}/usr/share/doc/packages/sudo/schema.OpenLDAP
 rm -f ${D}/usr/libexec/sudo/sudoers.la
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} sudo
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} sudoers
 cat sudoers.lang >> sudo.lang
 
 
}

PACKAGES = ""
PACKAGES += "sudo-devel"
PACKAGES += "sudo"
PACKAGES += "sudo-locale"

sudo-devel_files = ""
sudo-devel_files += "sudo.manifest"
sudo-devel_files += "/usr/include/sudo_plugin.h"

sudo_files = ""
sudo_files += "sudo.manifest"
#Remove rpm attribut "%attr(0440,root,root)"
sudo_files += "/etc/sudoers"
sudo_files += "/etc/sudoers.d"
sudo_files += "/etc/pam.d/sudo"
sudo_files += "/usr/bin/sudoedit"
sudo_files += "/usr/bin/sudoreplay"
sudo_files += "/usr/sbin/visudo"
sudo_files += "/usr/libexec/sudo"
sudo_files += "/usr/share/doc/packages/sudo"
sudo_files += "/usr/share/man/man?/*"

sudo-locale_files = ""

FILES_${PN}-devel = "${sudo-devel_files}"
FILES_${PN} = "${sudo_files}"
FILES_${PN}-locale = "${sudo-locale_files}"

PKG_sudo-devel= "sudo-devel"
PKG_sudo= "sudo"
PKG_sudo-locale= "sudo-locale"

require sudo-extraconf.inc
