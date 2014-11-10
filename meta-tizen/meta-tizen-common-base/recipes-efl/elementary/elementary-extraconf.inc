SRC_URI += "file://Fix_build.patch"

do_configure_prepend() {
    # Fix configure error: "error: required file './ABOUT-NLS' not found"
    sed -i 's/AM_INIT_AUTOMAKE(\[1.6 dist-bzip2\])/AM_INIT_AUTOMAKE(\[1.6 dist-bzip2 foreign\])/' configure.ac
    # prefix returned eolian paths with STAGING_DIR_HOST also use $PKG_CONFIG instead of pkg-config directly
    sed -i "s^DEPS_EOLIAN_FLAGS=\`pkg-config --variable=eolian_flags eo evas edje ecore\`$^DEPS_EOLIAN_FLAGS=\`\$PKG_CONFIG --variable=eolian_flags eo evas edje ecore | sed 's#-I${prefix}#-I${STAGING_DIR_HOST}${prefix}#g'\`^g" ${S}/configure.ac
}

do_install_prepend () {
    for i in `find ${B}/ -name "*.pc" -type f` ; do \
        sed -i -e 's:-L${STAGING_LIBDIR}:-L\$\{libdir\}:g' -e 's:-I${STAGING_LIBDIR}:-I\$\{libdir\}:g' -e 's:-I${STAGING_INCDIR}:-I\$\{includedir\}:g' $i
    done
}

do_install_append () {
    rm -fr ${D}${prefix}/lib/elementary/examples

}

EXTRA_OECONF_append_class-target = "\
    --with-edje-cc=${STAGING_BINDIR_NATIVE}/edje_cc \
    --with-eet-eet=${STAGING_BINDIR_NATIVE}/eet \
    --with-elementary-codegen=${STAGING_BINDIR_NATIVE}/elementary_codegen \
    --with-elm-prefs-cc=${STAGING_BINDIR_NATIVE}/elm_prefs_cc \
    --with-eolian-gen=${STAGING_BINDIR_NATIVE}/eolian_gen \
    --with-binary-edje-cc=${STAGING_BINDIR_NATIVE}/edje_cc \
"
DEPENDS_class-native = "efl-native"
DEPENDS_append_class-target = " elementary-native "
EXTRA_OECONF_class-native = " --disable-static --disable-ecore-wayland --disable-ecore-x --disable-build-examples"

FILES_${PN}-dbg += "${prefix}/lib/elementary/modules/prefs/v-1.9.3/.debug"
FILES_${PN}-dbg += "${prefix}/lib/elementary/modules/datetime_input_ctxpopup/v-1.9.3/.debug"
FILES_${PN}-dbg += "${prefix}/lib/elementary/modules/test_entry/v-1.9.3/.debug"
FILES_${PN}-dbg += "${prefix}/lib/elementary/modules/access_output/v-1.9.3/.debug"
FILES_${PN}-dbg += "${prefix}/lib/elementary/modules/test_map/v-1.9.3/.debug"
FILES_${PN}-dbg += "${prefix}/lib/edje/modules/elm/v-1.9/.debug"
