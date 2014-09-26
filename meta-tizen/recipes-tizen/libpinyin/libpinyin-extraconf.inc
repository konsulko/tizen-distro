DEPENDS_append_class-target += "libpinyin-native"

EXTRA_OEMAKE_class-target += " utils_storage=${STAGING_BINDIR_NATIVE}"
EXTRA_OEMAKE_class-target += " utils_training=${STAGING_BINDIR_NATIVE}"

do_compile() {
    cd ${S}
    LANG=C
    export LANG
    unset DISPLAY
    LD_AS_NEEDED=1; export LD_AS_NEEDED ;

    autotools_do_configure
    oe_runmake -j16
}

