do_compile_prepend()  {
 sed -i "s@-I/usr/include/ico-uxf-weston-plugin@-I${PKG_CONFIG_SYSROOT_DIR}/usr/include/ico-uxf-weston-plugin@g" ${S}/gtforce/Makefile.am
 sed -i "s@-I/usr/include/ico-util@-I${PKG_CONFIG_SYSROOT_DIR}/usr/include/ico-util@g" ${S}/gtforce/Makefile.am
 sed -i "s@-I/usr/include/ico-uxf-weston-plugin@-I${PKG_CONFIG_SYSROOT_DIR}/usr/include/ico-uxf-weston-plugin@g" ${S}/tests/Makefile.am
 
}