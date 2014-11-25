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

inherit pkgconfig

EXTRA_OECONF += " --libdir=${base_libdir} \
                "

EXTRA_OECONF += " --disable-nis \
                  --disable-regenerate-docu \
                  --disable-prelude \
                "

PACKAGECONFIG[audit] = "--enable-audit,--disable-audit,audit,"


do_install_append() {
    install -m 0644 ${WORKDIR}/system-auth ${D}${sysconfdir}/pam.d
}

pam_files += "${prefix}/sbin/*"
pam_files += "/var/log"

pam-dbg_files += "${base_libdir}/security/.debug/*"
pam-dbg_files += "${base_libdir}/security/pam_filter/.debug/*"

FILES_${PN}-dbg += "${pam-dbg_files}"

pam-dev_files += "${prefix}/include/*"
pam-dev_files += "${base_libdir}/security/pam_unix_acct.so"
pam-dev_files += "${base_libdir}/security/pam_unix_auth.so"
pam-dev_files += "${base_libdir}/security/pam_unix_passwd.so"
pam-dev_files += "${base_libdir}/security/pam_unix_session.so"

pam-modules-extra_files = ""
pam-modules-extra_files += "pam.manifest"
pam-modules-extra_files += "${base_libdir}/security/*.so"


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
