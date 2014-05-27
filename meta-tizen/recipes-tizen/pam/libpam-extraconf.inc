EXTRA_OECONF = "--with-db-uniquename=_pam \
                --disable-nis \
                --disable-regenerate-docu \
                --disable-prelude"

PACKAGECONFIG[audit] = "--enable-audit,--disable-audit,audit,"

pam-dev_files += "${prefix}/include/*"

pam_files += "${prefix}/sbin/*"

pam-dbg_files += "${prefix}/lib/security/.debug/*"
pam-dbg_files += "${prefix}/lib/security/pam_filter/.debug/*"

FILES_${PN}-dbg += "${pam-dbg_files}"

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

}