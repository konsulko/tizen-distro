DESCRIPTION = "Utilities to Manage User and Group Accounts"
HOMEPAGE = "http://www.thkukuk.de/pam/pwdutils/"
SECTION = "Security/Accounts"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by pwdutils-docs  
PROVIDES += "pwdutils-docs "
RPROVIDES_pwdutils-docs  += "pwdutils-docs "

#PROVIDES by pwdutils 
PROVIDES += "pwdutils"
RPROVIDES_pwdutils += "pwdutils"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of pwdutils 
DEPENDS += "libtool-cross"
DEPENDS += "openssl"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "pam"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/pwdutils.manifest .
 
 
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
         --infodir=/usr/share/info --disable-ldap --libdir=/usr/lib --disable-nls --disable-pam_rpasswd
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR=$RPM_BUILD_ROOT
 rm -f $RPM_BUILD_ROOT/usr/lib/pwdutils/lib*.so
 #mkdir $RPM_BUILD_ROOT/lib
 #mv $RPM_BUILD_ROOT/usr/lib/security $RPM_BUILD_ROOT/lib
 /sbin/ldconfig -n /usr/lib/pwdutils
 rm -f $RPM_BUILD_ROOT/usr/lib/pwdutils/*a
 rm -f $RPM_BUILD_ROOT/lib/security/*a
 
 rm -f ${D}/etc/init.d/rpasswdd
 rm -f ${D}/etc/pam.d/rpasswd
 rm -f ${D}/etc/rpasswd.conf
 rm -f ${D}/usr/bin/rpasswd
 rm -f ${D}/usr/sbin/rpasswdd
 ln -sf newgrp $RPM_BUILD_ROOT/usr/bin/sg
 install -m 644 $RPM_SOURCE_DIR/useradd.default $RPM_BUILD_ROOT/etc/default/useradd
 echo ".so man8/useradd.8" > $RPM_BUILD_ROOT/usr/share/man/man8/adduser.8
 
 
 
}

PACKAGES = ""
PACKAGES += "pwdutils-docs"
PACKAGES += "pwdutils"

pwdutils-docs_files = ""
pwdutils-docs_files += "/usr/share/info"
pwdutils-docs_files += "/usr/share/man"

pwdutils_files = ""
pwdutils_files += "pwdutils.manifest"
pwdutils_files += "/etc/login.defs"
pwdutils_files += "/etc/pam.d/chage"
pwdutils_files += "/etc/pam.d/chfn"
pwdutils_files += "/etc/pam.d/chsh"
pwdutils_files += "/etc/pam.d/passwd"
pwdutils_files += "/etc/pam.d/shadow"
pwdutils_files += "/etc/pam.d/useradd"
pwdutils_files += "/etc/default/useradd"
pwdutils_files += "/etc/default/passwd"
pwdutils_files += "/etc/pwdutils"
pwdutils_files += "/etc/pwdutils/logging"
pwdutils_files += "/usr/bin/sg"
pwdutils_files += "/usr/sbin/chpasswd"
pwdutils_files += "/usr/sbin/groupadd"
pwdutils_files += "/usr/sbin/groupdel"
pwdutils_files += "/usr/sbin/groupmod"
pwdutils_files += "/usr/sbin/grpck"
pwdutils_files += "/usr/sbin/grpconv"
pwdutils_files += "/usr/sbin/grpunconv"
pwdutils_files += "/usr/sbin/pwck"
pwdutils_files += "/usr/sbin/pwconv"
pwdutils_files += "/usr/sbin/pwunconv"
pwdutils_files += "/usr/sbin/useradd"
pwdutils_files += "/usr/sbin/userdel"
pwdutils_files += "/usr/sbin/usermod"
pwdutils_files += "/usr/sbin/vigr"
pwdutils_files += "/usr/sbin/vipw"
pwdutils_files += "/usr/lib/pwdutils"
pwdutils_files += "/usr/lib/pwdutils/liblog_syslog.so.1*"

FILES_${PN}-docs = "${pwdutils-docs_files}"
FILES_${PN} = "${pwdutils_files}"

PKG_pwdutils-docs= "pwdutils-docs"
PKG_pwdutils= "pwdutils"

require pwdutils-extraconf.inc
