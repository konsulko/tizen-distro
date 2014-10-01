# required for pythong binding
export HOST_SYS
export BUILD_SYS
export STAGING_LIBDIR
export STAGING_INCDIR

SRC_URI += "file://remove_ir.patch"

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 install -D ${S}/packaging/gi-find-deps.sh ${D}/usr/share/spec2yocto/macro/gi-find-deps.sh
 install -D ${S}/packaging/gobjectintrospection.attr -m 0644 ${D}/usr/share/spec2yocto/macro/fileattrs/gobjectintrospection.attr

 
 
 
}

FILES_${PN}-dbg += "/usr/lib/gobject-introspection/giscanner/.debug"