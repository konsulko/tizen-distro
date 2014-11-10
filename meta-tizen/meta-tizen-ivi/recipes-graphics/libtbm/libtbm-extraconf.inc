INSANE_SKIP_${PN} = "dev-so"

do_install_append() {
    # Remove libdrm_slp.so* if arch = x86_64 since those files aren't packaged for x86_64 architectures according to the original spec file
    if [ "${TARGET_ARCH}" == "x86_64" ]
    then
        rm -f ${D}/${prefix}/lib/libdrm_slp.so*
    fi
}

# Those files are only packaged for architectures != x86_64 (see "do_install_append" function)
libtbm_files += "${prefix}/lib/libdrm_slp.so"
libtbm_files += "${prefix}/lib/libdrm_slp.so.1"
libtbm_files += "${prefix}/lib/libdrm_slp.so.1.0.0"
