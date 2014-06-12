
SRC_URI += "file://system-auth"


EXTRA_OECONF = "--with-db-uniquename=_pam \
                --disable-nis \
                --disable-regenerate-docu \
                --disable-prelude"

PACKAGECONFIG[audit] = "--enable-audit,--disable-audit,audit,"

pam-dev_files += "${prefix}/include/*"

pam_files += "${prefix}/sbin/*"

pam-dbg_files += "${prefix}/lib/security/.debug/*"
pam-dbg_files += "${prefix}/lib/security/pam_filter/.debug/*"

FILES_pam-dbg += "${pam-dbg_files}"

INSANE_SKIP_${PN} = "pam-modules-extra"

pam-dev_files += "${prefix}/lib/security/pam_unix_acct.so"
pam-dev_files += "${prefix}/lib/security/pam_unix_auth.so"
pam-dev_files += "${prefix}/lib/security/pam_unix_passwd.so"
pam-dev_files += "${prefix}/lib/security/pam_unix_session.so"

do_install_append() {
mkdir -p ${D}${prefix}/include/security

for i in _pam_compat.h \
         _pam_macros.h \
         _pam_types.h \
         pam_appl.h \
         pam_client.h \
         pam_ext.h \
         pam_filter.h \
         pam_misc.h \
         pam_modules.h \
         pam_modutil.h  ;do
    cp ${D}${prefix}/include/${i} ${D}${prefix}/include/security/
done

install -m 0644 ${WORKDIR}/system-auth ${D}${sysconfdir}/pam.d

}

PROVIDES += 'pam'
RPROVIDES_${PN}  += "pam"

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