DESCRIPTION = "Utilities to Manage User and Group Accounts"
HOMEPAGE = "http://www.thkukuk.de/pam/pwdutils/"
SECTION = "Security/Accounts"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

PROVIDES = ""

#PROVIDES by pwdutils-docs  


#PROVIDES by pwdutils 


RDEPENDS = ""

DEPENDS = ""
#DEPENDS of pwdutils 
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "libtool-cross"
DEPENDS += "openssl"
DEPENDS += "libpam"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/pwdutils.manifest .
 
 
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
         --infodir=${infodir} --disable-ldap --libdir=${prefix}/lib --disable-nls --disable-pam_rpasswd
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR=$RPM_BUILD_ROOT
 rm -f $RPM_BUILD_ROOT${prefix}/lib/pwdutils/lib*.so
 #mkdir $RPM_BUILD_ROOT/lib
 #mv $RPM_BUILD_ROOT${prefix}/lib/security $RPM_BUILD_ROOT/lib
 /sbin/ldconfig -n ${prefix}/lib/pwdutils
 rm -f $RPM_BUILD_ROOT${prefix}/lib/pwdutils/*a
 rm -f $RPM_BUILD_ROOT/lib/security/*a
 
 rm -f ${D}/etc/init.d/rpasswdd
 rm -f ${D}/etc/pam.d/rpasswd
 rm -f ${D}/etc/rpasswd.conf
 rm -f ${D}/usr/bin/rpasswd
 rm -f ${D}/usr/sbin/rpasswdd
 ln -sf newgrp $RPM_BUILD_ROOT${prefix}/bin/sg
 install -m 644 $RPM_SOURCE_DIR/useradd.default $RPM_BUILD_ROOT/etc/default/useradd
 echo ".so man8/useradd.8" > $RPM_BUILD_ROOT${mandir}/man8/adduser.8
 
 
 
}

PACKAGES += " pwdutils-docs "

pwdutils-docs_files = ""

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
pwdutils_files += "${prefix}/bin/sg"
pwdutils_files += "${prefix}/sbin/chpasswd"
pwdutils_files += "${prefix}/sbin/groupadd"
pwdutils_files += "${prefix}/sbin/groupdel"
pwdutils_files += "${prefix}/sbin/groupmod"
pwdutils_files += "${prefix}/sbin/grpck"
pwdutils_files += "${prefix}/sbin/grpconv"
pwdutils_files += "${prefix}/sbin/grpunconv"
pwdutils_files += "${prefix}/sbin/pwck"
pwdutils_files += "${prefix}/sbin/pwconv"
pwdutils_files += "${prefix}/sbin/pwunconv"
pwdutils_files += "${prefix}/sbin/useradd"
pwdutils_files += "${prefix}/sbin/userdel"
pwdutils_files += "${prefix}/sbin/usermod"
pwdutils_files += "${prefix}/sbin/vigr"
pwdutils_files += "${prefix}/sbin/vipw"
pwdutils_files += "${prefix}/lib/pwdutils"
pwdutils_files += "${prefix}/lib/pwdutils/liblog_syslog.so.1*"

FILES_${PN}-docs = "${pwdutils-docs_files}"
FILES_${PN} = "${pwdutils_files}"

PKG_pwdutils-docs= "pwdutils-docs"
PKG_pwdutils= "pwdutils"

require pwdutils-extraconf.inc

