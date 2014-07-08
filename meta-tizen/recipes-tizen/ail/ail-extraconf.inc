ail_files += "/usr/dbspace"

SRC_URI_append_class-native = " file://remove-dlog-for-native-build.patch"

RDEPENDS_${PN}_remove_class-native = "systemd-native"
DEPENDS_remove_class-native = "dlog-native"

DEPENDS_class-target += " ail-native"

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
    vconftool set -t string db/ail/ail_info "0" -f -s system::vconf_inhouse
    vconftool set -t string db/menuscreen/desktop "0" -f -s system::vconf_inhouse
    vconftool set -t string db/menu_widget/language "en_US.utf8" -f -s system::vconf_inhouse
    chsmack -a User $D${prefix}/kdb/db/ail
    chsmack -a User $D${prefix}/kdb/db/ail/ail_info
    chsmack -a User $D${prefix}/kdb/db/menuscreen
    chsmack -a User $D${prefix}/kdb/db/menuscreen/desktop
    chsmack -a User $D${prefix}/kdb/db/menu_widget
    chsmack -a User $D${prefix}/kdb/db/menu_widget/language

}