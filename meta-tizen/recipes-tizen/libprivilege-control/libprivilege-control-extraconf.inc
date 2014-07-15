do_configure() {
 sed -i 's@source /etc/tizen-platform.conf@source ${STAGING_DIR_NATIVE}/etc/tizen-platform.conf@' ${S}/db/updater.sh
}