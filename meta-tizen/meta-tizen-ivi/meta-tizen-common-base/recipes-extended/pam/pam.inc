DESCRIPTION = "A Security Tool that Provides Authentication for Applications"
HOMEPAGE = "http://www.linux-pam.org/"
SECTION = "Security/Access Control"
LICENSE = "GPL-2.0+ or BSD-3-Clause"
PV = "1.1.6"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by pam-modules-extra
PROVIDES += "pam-modules-extra"


#PROVIDES by pam-docs
PROVIDES += "pam-docs "


#PROVIDES by pam


#PROVIDES by pam-dev
PROVIDES += "pam-dev"


RDEPENDS = ""
#RDEPENDS of pam-modules-extra (${PN}-modules-extra)
RDEPENDS_${PN}-modules-extra += "pam"

#RDEPENDS of pam (${PN})
RDEPENDS_${PN} += "coreutils"
RDEPENDS_${PN} += "glibc"

#RDEPENDS of pam-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "pam"


DEPENDS = ""
#DEPENDS of pam
DEPENDS += "flex"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "zlib"
DEPENDS += "db"
DEPENDS_append_class-native = " automake-native"
DEPENDS_append_class-target = " automake-native"
DEPENDS += "smack"
DEPENDS_append_class-native = " libtool"
DEPENDS_append_class-target = " libtool-cross"
DEPENDS += "net-tools"
DEPENDS_append_class-native = " bison-native"
DEPENDS_append_class-target = " bison-native"
DEPENDS_append_class-native = " autoconf-native"
DEPENDS_append_class-target = " autoconf-native"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Linux-PAM-1.1.6
 cp ${S}/packaging/pam.manifest .
 
 
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
  LD_AS_NEEDED=1; export LD_AS_NEEDED ;
  
  CFLAGS="-fPIC $CFLAGS " ; export CFLAGS
  
  autotools_do_configure
  oe_runmake  CFLAGS="$CFLAGS -lfl -lcrypt"
  
  
  
}
EXTRA_OECONF += " --libdir=${base_libdir} --includedir=${prefix}/include/security --enable-isadir=../..${base_libdir}/security --disable-audit --with-db-uniquename=_pam --with-libiconv-prefix=${prefix} --enable-read-both-confs "

do_install() {
 export RPM_BUILD_ROOT=${D}
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
 
 # RPM uses docs from source tree
 rm -rf ${D}${prefix}/share/doc/Linux-PAM
 # Included in setup package
 rm -f ${D}${sysconfdir}/environment
 
 for phase in auth acct passwd session ; do
 	ln -sf pam_unix.so ${D}${base_libdir}/security/pam_unix_${phase}.so
 done
 
 # Install default pam configuration files
 install -d -m 0755 ${D}${sysconfdir}/pam.d
 install -m 0644 ${S}/packaging/system-auth ${D}${sysconfdir}/pam.d/
 install -m 0644 ${S}/packaging/other ${D}${sysconfdir}/pam.d/
 
 #find_lang Linux-PAM
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
    if [ ! -a ${localstatedir}/log/faillog ] ; then
    	install -m 600 /dev/null ${localstatedir}/log/faillog
    fi
    if [ ! -a ${localstatedir}/log/tallylog ] ; then
    	install -m 600 /dev/null ${localstatedir}/log/tallylog
    fi

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " pam-modules-extra "
PACKAGES += " pam-dev "
PACKAGES += " pam "
PACKAGES += " pam-docs "

pam-modules-extra_files = ""
pam-modules-extra_files += "${base_libdir}/security/pam_access.so"
pam-modules-extra_files += "${base_libdir}/security/pam_debug.so"
pam-modules-extra_files += "${base_libdir}/security/pam_echo.so"
pam-modules-extra_files += "${base_libdir}/security/pam_exec.so"
pam-modules-extra_files += "${base_libdir}/security/pam_faildelay.so"
pam-modules-extra_files += "${base_libdir}/security/pam_filter.so"
pam-modules-extra_files += "${base_libdir}/security/pam_ftp.so"
pam-modules-extra_files += "${base_libdir}/security/pam_group.so"
pam-modules-extra_files += "${base_libdir}/security/pam_issue.so"
pam-modules-extra_files += "${base_libdir}/security/pam_listfile.so"
pam-modules-extra_files += "${base_libdir}/security/pam_localuser.so"
pam-modules-extra_files += "${base_libdir}/security/pam_mail.so"
pam-modules-extra_files += "${base_libdir}/security/pam_motd.so"
pam-modules-extra_files += "${base_libdir}/security/pam_pwhistory.so"
pam-modules-extra_files += "${base_libdir}/security/pam_rhosts.so"
pam-modules-extra_files += "${base_libdir}/security/pam_shells.so"
pam-modules-extra_files += "${base_libdir}/security/pam_stress.so"
pam-modules-extra_files += "${base_libdir}/security/pam_tally.so"
pam-modules-extra_files += "${base_libdir}/security/pam_time.so"
pam-modules-extra_files += "${base_libdir}/security/pam_timestamp.so"
pam-modules-extra_files += "${base_libdir}/security/pam_umask.so"
pam-modules-extra_files += "${base_libdir}/security/pam_unix_acct.so"
pam-modules-extra_files += "${base_libdir}/security/pam_unix_auth.so"
pam-modules-extra_files += "${base_libdir}/security/pam_unix_passwd.so"
pam-modules-extra_files += "${base_libdir}/security/pam_unix_session.so"
pam-modules-extra_files += "${base_libdir}/security/pam_warn.so"
pam-modules-extra_files += "${base_libdir}/security/pam_smack.so"
MANIFESTFILES_${PN}-modules-extra = "pam.manifest"

pam-dev_files = ""
pam-dev_files += "${prefix}/include/security/*"
pam-dev_files += "${base_libdir}/libpam.so"
pam-dev_files += "${base_libdir}/libpam_misc.so"
pam-dev_files += "${base_libdir}/libpamc.so"
pam-dev_files += "${base_libdir}/security/pam_tally2.so"
MANIFESTFILES_${PN}-dev = "pam.manifest"

pam_files = ""
pam_files += "/sbin/pam_tally"
pam_files += "/sbin/pam_tally2"
pam_files += "/sbin/pam_timestamp_check"
pam_files += "/sbin/unix_chkpwd"
pam_files += "/sbin/unix_update"
pam_files += "/sbin/mkhomedir_helper"
pam_files += "${sysconfdir}/security/limits.conf"
pam_files += "${base_libdir}/libpam.so.*"
pam_files += "${base_libdir}/libpam_misc.so.*"
pam_files += "${base_libdir}/libpamc.so.*"
pam_files += "${base_libdir}/security/pam_deny.so"
pam_files += "${base_libdir}/security/pam_env.so"
pam_files += "${base_libdir}/security/pam_keyinit.so"
pam_files += "${base_libdir}/security/pam_limits.so"
pam_files += "${base_libdir}/security/pam_loginuid.so"
pam_files += "${base_libdir}/security/pam_namespace.so"
pam_files += "${base_libdir}/security/pam_nologin.so"
pam_files += "${base_libdir}/security/pam_permit.so"
pam_files += "${base_libdir}/security/pam_lastlog.so"
pam_files += "${base_libdir}/security/pam_rootok.so"
pam_files += "${base_libdir}/security/pam_securetty.so"
pam_files += "${base_libdir}/security/pam_succeed_if.so"
pam_files += "${base_libdir}/security/pam_unix.so"
pam_files += "${base_libdir}/security/pam_wheel.so"
pam_files += "${base_libdir}/security/pam_xauth.so"
pam_files += "${base_libdir}/security/pam_filter"
pam_files += "${base_libdir}/security/pam_mkhomedir.so"
pam_files += "${sysconfdir}/security"
pam_files += "${sysconfdir}/security/access.conf"
pam_files += "${sysconfdir}/security/group.conf"
pam_files += "${sysconfdir}/security/namespace.conf"
pam_files += "${sysconfdir}/security/namespace.init"
pam_files += "${sysconfdir}/security/pam_env.conf"
pam_files += "${sysconfdir}/security/time.conf"
pam_files += "${sysconfdir}/pam.d"
pam_files += "${sysconfdir}/pam.d/system-auth"
pam_files += "${sysconfdir}/pam.d/other"
CONFFILES_${PN} = ""
CONFFILES_${PN} += "${sysconfdir}/security/limits.conf"
CONFFILES_${PN} += "${sysconfdir}/pam.d/system-auth"
CONFFILES_${PN} += "${sysconfdir}/pam.d/other"
MANIFESTFILES_${PN} = "pam.manifest"
DIRFILES_${PN} = ""
DIRFILES_${PN} += "${sysconfdir}/security"
DIRFILES_${PN} += "${sysconfdir}/pam.d"

pam-docs_files = ""

FILES_${PN}-modules-extra = "${pam-modules-extra_files}"
FILES_${PN}-dev = "${pam-dev_files}"
FILES_${PN} = "${pam_files}"
FILES_${PN}-docs = "${pam-docs_files}"

PKG_pam-modules-extra= "pam-modules-extra"
PKG_pam-dev= "pam-dev"
PKG_pam= "pam"
PKG_pam-docs= "pam-docs"

require pam-extraconf.inc

