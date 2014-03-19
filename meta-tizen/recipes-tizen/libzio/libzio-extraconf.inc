do_patch_append () {
sed -e 's,zioP.h: /usr/include/bzlib.h /usr/include/zlib.h,zioP.h: ${base_prefix}/usr/include/bzlib.h ${base_prefix}/usr/include/zlib.h,' -i Makefile
sed -e 's,zio.h:  zio.h.in /usr/include/stdio.h,zio.h:  zio.h.in ${base_prefix}/usr/include/stdio.h,' -i Makefile
}