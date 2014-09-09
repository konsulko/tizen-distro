do_install_append_class-target() {
	sed -i ${D}${libdir}/libattr.la -e \
	    s,^libdir=\'${base_libdir}\'$,libdir=\'${libdir}\',
	    
	rm ${D}${base_libdir}/libattr.a
	rm ${D}${base_libdir}/libattr.la
	rm ${D}${libdir}/libattr.so
}