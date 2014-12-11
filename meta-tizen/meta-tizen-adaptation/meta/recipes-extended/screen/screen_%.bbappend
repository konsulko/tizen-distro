SECTION = "System/Console"

do_install_append () {
    # Remove screen rule that is not present in Tizen Common
    rm -f ${D}/${sysconfdir}/pam.d/screen
}
