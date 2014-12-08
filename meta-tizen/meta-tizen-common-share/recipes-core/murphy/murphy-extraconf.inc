#We should deseable PARALLEL_MAKE only for install
PARALLEL_MAKE = ""

do_install_append() {
    rm -fr ${D}${prefix}/lib/systemd/user
    rm ${D}/usr/lib/libmurphy-plugin-system-monitor*

}

FILES_${PN}-dev += " ${prefix}/include/murphy" 
FILES_${PN}-dbg += " ${prefix}/lib/murphy/plugins/.debug"

murphy-doc_files = ""
murphy-doc_files += "${prefix}/share/doc/murphy/AUTHORS"
murphy-doc_files += "${prefix}/share/doc/murphy/CODING-STYLE"
murphy-doc_files += "${prefix}/share/doc/murphy/ChangeLog"
murphy-doc_files += "${prefix}/share/doc/murphy/NEWS"
murphy-doc_files += "${prefix}/share/doc/murphy/README"

PROVIDES_remove := "${@bb.utils.contains('SYS_CTLR_PROVIDER', 'murphy','',"system-controller",d)}"
RPROVIDES_ico-uxf-homescreen-system-controller_remove :=  "${@bb.utils.contains('SYS_CTLR_PROVIDER', 'murphy','',"system-controller",d)}"
DEPENDS_remove :=  "${@bb.utils.contains('SYS_CTLR_PROVIDER', 'murphy','',"ico-uxf-weston-plugin",d)}"
RDEPENDS_${PN}-system-controller_remove := "${@bb.utils.contains('SYS_CTLR_PROVIDER', 'murphy','',"ico-uxf-homescreen",d)}"

EXTRA_OECONF += "--enable-gpl --enable-pulse --enable-gpl --enable-ecore --enable-gpl --enable-glib --disable-qt --enable-gpl --enable-libdbus --enable-gpl --enable-telephony --enable-resource-asm "


EXTRA_OECONF += "${@bb.utils.contains('SYS_CTLR_PROVIDER', 'murphy','--enable-system-controller',"--disable-system-controller",d)}"
EXTRA_OECONF += " --with-dynamic-plugins=domain-control,system-controller,ivi-resource-manager,resource-asm "

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 # Make sure we have a plugin dir even if all the basic plugins
 # are configured to be built in.
 mkdir -p ${D}${prefix}/lib/murphy/plugins
 
 # Get rid of any *.la files installed by libtool.
 rm -f ${D}${prefix}/lib/*.la
 
 # Clean up also the murphy DB installation.
 rm -f ${D}${prefix}/lib/murphy/*.la
 
 # Generate list of linkedin plugins (depends on the configuration).
 outdir="`pwd`"
 cd ${D} 
 find ./${prefix}/lib -name libmurphy-plugin-*.so* | \
 sed 's#^./*#/#g' > $outdir/filelist.plugins-base 
 cd ${outdir}
 echo "Found the following linked-in plugin files:"
 cat $outdir/filelist.plugins-base | sed 's/^/    /g'
 
 # Generate list of header files, filtering ones that go to subpackages.
 outdir="`pwd`"
 cd ${D}
 find ./${prefix}/include/murphy | \
 grep -E -v '((pulse)|(ecore)|(glib)|(qt))-glue' | \
 sed 's#^./*#/#g' > $outdir/filelist.devel-includes 
 cd ${outdir}
 
 # Replace the default sample/test config files with the packaging ones.
 rm -f ${D}${sysconfdir}/murphy/*
 cp packaging.in/murphy-lua.conf ${D}${sysconfdir}/murphy/murphy.conf
 cp packaging.in/murphy.lua      ${D}${sysconfdir}/murphy/murphy.lua
 
 # Copy plugin configuration files in place.
 mkdir -p ${D}${sysconfdir}/murphy/plugins/amb
 cp packaging.in/amb-config.lua \
 ${D}${sysconfdir}/murphy/plugins/amb/config.lua
 
 # Copy tmpfiles.d config file in place
 mkdir -p ${D}/usr/lib/tmpfiles.d
 cp packaging.in/murphyd.conf ${D}/usr/lib/tmpfiles.d
 
 # Copy the systemd files in place.
 #mkdir -p %{buildroot}%{_unitdir}
 mkdir -p ${D}${prefix}/lib/systemd/user
 cp packaging.in/murphyd.service ${D}${prefix}/lib/systemd/user
 
 mkdir -p ${D}${sysconfdir}/dbus-1/system.d
 sed "s/@TZ_SYS_USER_GROUP@/users/g" \
     packaging.in/org.Murphy.conf.in > packaging.in/org.Murphy.conf
 cp packaging.in/org.Murphy.conf \
     ${D}${sysconfdir}/dbus-1/system.d/org.Murphy.conf
 
 # copy (experimental) GAM resource backend configuration files
 mkdir -p ${D}${sysconfdir}/murphy/gam
 cp packaging.in/gam-*.names packaging.in/gam-*.tree \
     ${D}${sysconfdir}/murphy/gam
 
 
}