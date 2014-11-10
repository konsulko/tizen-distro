SRC_URI += "file://system-auth"

INSANE_SKIP_pam-modules-extra = "dev-so"

PROVIDES += 'libpam'

RPROVIDES_${PN}  += "libpam"
RPROVIDES_${PN} += "libpam-runtime"

RPROVIDES_${PN}-modules-extra += "pam-plugin-faildelay"
RPROVIDES_${PN}-modules-extra += "pam-plugin-securetty"
RPROVIDES_${PN}-modules-extra += "pam-plugin-nologin"
RPROVIDES_${PN}-modules-extra += "pam-plugin-env"
RPROVIDES_${PN}-modules-extra += "pam-plugin-group"
RPROVIDES_${PN}-modules-extra += "pam-plugin-limits"
RPROVIDES_${PN}-modules-extra += "pam-plugin-lastlog"
RPROVIDES_${PN}-modules-extra += "pam-plugin-motd"
RPROVIDES_${PN}-modules-extra += "pam-plugin-mail"
RPROVIDES_${PN}-modules-extra += "pam-plugin-shells"
RPROVIDES_${PN}-modules-extra += "pam-plugin-rootok"
RPROVIDES_${PN}-modules-extra += "pam-plugin-keyinit"
RPROVIDES_${PN}-modules-extra += "pam-plugin-loginuid"

EXTRA_OECONF = " --libdir=${prefix}/lib --includedir=${prefix}/include/security --enable-isadir=../..${prefix}/lib/security --disable-audit --with-db-uniquename=_pam --with-libiconv-prefix=/usr --enable-read-both-confs "
EXTRA_OECONF += "--disable-nis \
                 --disable-regenerate-docu \
                 --disable-prelude"

PACKAGECONFIG[audit] = "--enable-audit,--disable-audit,audit,"

do_compile() {
    cd ${S}
    LANG=C
    export LANG
    unset DISPLAY
    LD_AS_NEEDED=1; export LD_AS_NEEDED ;
    autotools_do_configure
    make  CFLAGS="$CFLAGS -lfl -lcrypt"
}

do_install_append() {
    install -m 0644 ${WORKDIR}/system-auth ${D}${sysconfdir}/pam.d
}

pam_files += "${prefix}/sbin/*"
pam_files += "/var/log"

pam-dbg_files += "${prefix}/lib/security/.debug/*"
pam-dbg_files += "${prefix}/lib/security/pam_filter/.debug/*"

FILES_${PN}-dbg += "${pam-dbg_files}"

pam-dev_files += "${prefix}/include/*"
pam-dev_files += "${prefix}/lib/security/pam_unix_acct.so"
pam-dev_files += "${prefix}/lib/security/pam_unix_auth.so"
pam-dev_files += "${prefix}/lib/security/pam_unix_passwd.so"
pam-dev_files += "${prefix}/lib/security/pam_unix_session.so"

pam-modules-extra_files = ""
pam-modules-extra_files += "pam.manifest"
pam-modules-extra_files += "${prefix}/lib/security/pam_access.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_debug.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_echo.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_exec.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_faildelay.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_filter.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_ftp.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_group.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_issue.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_listfile.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_localuser.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_mail.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_motd.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_pwhistory.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_rhosts.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_shells.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_stress.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_tally.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_time.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_timestamp.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_umask.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_unix_acct.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_unix_auth.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_unix_passwd.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_unix_session.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_warn.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_smack.so"
pam-modules-extra_files += "${prefix}/lib/security/pam_cracklib.so"

do_install_append() {
    mkdir -p $D/var/log
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
    if [ ! -a $D/var/log/faillog ] ; then
        mkdir -p $D/var/log
        /usr/bin/install -m 600 /dev/null $D/var/log/faillog
    fi
    if [ ! -a $D/var/log/tallylog ] ; then
        mkdir -p $D/var/log
        /usr/bin/install -m 600 /dev/null $D/var/log/tallylog
    fi
}
