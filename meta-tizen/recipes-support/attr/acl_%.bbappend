do_install_append_class-target() {
	sed -i ${D}${libdir}/libacl.la -e \
	    s,^libdir=\'${base_libdir}\'$,libdir=\'${libdir}\',
	    
	rm ${D}${base_libdir}/libacl.a
	rm ${D}${base_libdir}/libacl.la
	rm ${D}${libdir}/libacl.so
	    
}