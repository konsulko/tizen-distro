BBCLASSEXTEND_append = " nativesdk "

do_configure() {
 sed -i 's@systemd_new=no@systemd_new=yes@' ${S}/configure.ac
 sed -i '/PKG_CHECK_MODULES(/,/)/{s/b/r/p;d}' ${S}/configure.ac
}
