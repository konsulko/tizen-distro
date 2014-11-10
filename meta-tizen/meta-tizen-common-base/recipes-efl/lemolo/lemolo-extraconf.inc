do_configure_prepend() {
    # Set the path to the binary edje_cc otherwise it will search it in the host rootfs
    sed -i 's!@edje_cc@!${STAGING_BINDIR_NATIVE}/edje_cc!g' Makefile.am
}