#EXTRA_OECONF = "--with-db-uniquename=_pam \
#                --includedir=${includedir}/security \
#                --libdir=${base_libdir} \
#                --disable-nis \
#                --disable-regenerate-docu \
#                --disable-prelude"

EXTRA_OECONF = "--with-db-uniquename=_pam \
                --disable-nis \
                --disable-regenerate-docu \
                --disable-prelude"

#CFLAGS_append = " -fPIC "

#inherit autotools gettext pkgconfig

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