DESCRIPTION = "Murphy policy framework"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Service"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by murphy-dev
PROVIDES += "murphy-dev"


#PROVIDES by murphy-ecore
PROVIDES += "murphy-ecore"


#PROVIDES by murphy-pulse
PROVIDES += "murphy-pulse"


#PROVIDES by murphy-doc
PROVIDES += "murphy-doc"


#PROVIDES by murphy


#PROVIDES by murphy-ivi-resource-manager
PROVIDES += "murphy-ivi-resource-manager"


#PROVIDES by murphy-ecore-dev
PROVIDES += "murphy-ecore-dev"


#PROVIDES by murphy-pulse-dev
PROVIDES += "murphy-pulse-dev"


#PROVIDES by murphy-tests
PROVIDES += "murphy-tests"


#PROVIDES by murphy-glib
PROVIDES += "murphy-glib"


#PROVIDES by murphy-glib-dev
PROVIDES += "murphy-glib-dev"


RDEPENDS = ""
#RDEPENDS of murphy-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "json-c"
RDEPENDS_${PN}-dev += "murphy"

#RDEPENDS of murphy-ecore (${PN}-ecore)
RDEPENDS_${PN}-ecore += "murphy"

#RDEPENDS of murphy-pulse (${PN}-pulse)
RDEPENDS_${PN}-pulse += "murphy"

#RDEPENDS of murphy (${PN})
RDEPENDS_${PN} += "libcap-tools"
RDEPENDS_${PN} += "/bin/systemctl"

#RDEPENDS of murphy-ecore-dev (${PN}-ecore-dev)
RDEPENDS_${PN}-ecore-dev += "murphy-ecore"
RDEPENDS_${PN}-ecore-dev += "murphy"

#RDEPENDS of murphy-pulse-dev (${PN}-pulse-dev)
RDEPENDS_${PN}-pulse-dev += "murphy-pulse"
RDEPENDS_${PN}-pulse-dev += "murphy"

#RDEPENDS of murphy-tests (${PN}-tests)
RDEPENDS_${PN}-tests += "murphy"

#RDEPENDS of murphy-glib (${PN}-glib)
RDEPENDS_${PN}-glib += "murphy"

#RDEPENDS of murphy-glib-dev (${PN}-glib-dev)
RDEPENDS_${PN}-glib-dev += "murphy"
RDEPENDS_${PN}-glib-dev += "murphy-glib"


DEPENDS = ""
#DEPENDS of murphy
DEPENDS += "flex"
DEPENDS += "systemd"
DEPENDS += "smack"
DEPENDS += "ofono"
DEPENDS += "json-c"
DEPENDS += "dbus"
DEPENDS += "pulseaudio"
DEPENDS += "glib-2.0"
DEPENDS += "lua"
DEPENDS += "aul"
DEPENDS_append_class-native = " bison-native"
DEPENDS_append_class-target = " bison-native"
DEPENDS += "ecore"
DEPENDS += "libwebsockets"
DEPENDS += "libcap"
DEPENDS += "mesa"
DEPENDS += "audio-session-manager"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
  LANG=C
  export LANG
  unset DISPLAY
  LD_AS_NEEDED=1; export LD_AS_NEEDED ;
  
  
  CONFIG_OPTIONS=""
  DYNAMIC_PLUGINS="domain-control,system-controller,ivi-resource-manager"
  
  CONFIG_OPTIONS="$CONFIG_OPTIONS --enable-gpl --enable-pulse"
  
  CONFIG_OPTIONS="$CONFIG_OPTIONS --enable-gpl --enable-ecore"
  
  CONFIG_OPTIONS="$CONFIG_OPTIONS --enable-gpl --enable-glib"
  
  CONFIG_OPTIONS="$CONFIG_OPTIONS --disable-qt"
  
  CONFIG_OPTIONS="$CONFIG_OPTIONS --enable-gpl --enable-libdbus"
  
  CONFIG_OPTIONS="$CONFIG_OPTIONS --enable-gpl --enable-telephony"
  
  CONFIG_OPTIONS="$CONFIG_OPTIONS --enable-resource-asm"
  DYNAMIC_PLUGINS="$DYNAMIC_PLUGINS,resource-asm"
  
  CONFIG_OPTIONS="$CONFIG_OPTIONS --enable-websockets"
  
  CONFIG_OPTIONS="$CONFIG_OPTIONS --enable-smack"
  
  CONFIG_OPTIONS="$CONFIG_OPTIONS --disable-system-controller"
  
  CONFIG_OPTIONS="$CONFIG_OPTIONS --enable-system-monitor"
  
  NUM_CPUS="`cat /proc/cpuinfo | tr -s '\t' ' ' |   grep '^processor *:' | wc -l`"
  [ -z "$NUM_CPUS" ] && NUM_CPUS=1
  
  ./bootstrap &&   
  autotools_do_configure
  
  
  
}
EXTRA_OECONF += " $CONFIG_OPTIONS --with-dynamic-plugins=$DYNAMIC_PLUGINS && make clean && make -j$(($NUM_CPUS + 1)) $V"

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 rm -rf $RPM_BUILD_ROOT
 
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
 mkdir -p $RPM_BUILD_ROOT${prefix}/lib/murphy/plugins
 
 # Get rid of any *.la files installed by libtool.
 rm -f $RPM_BUILD_ROOT${prefix}/lib/*.la
 
 # Clean up also the murphy DB installation.
 rm -f $RPM_BUILD_ROOT${prefix}/lib/murphy/*.la
 
 # Generate list of linkedin plugins (depends on the configuration).
 outdir="`pwd`"
 pushd $RPM_BUILD_ROOT >& /dev/null && \
 find ./${prefix}/lib -name libmurphy-plugin-*.so* | \
 sed 's#^./*#/#g' > $outdir/filelist.plugins-base && \
 popd >& /dev/null
 echo "Found the following linked-in plugin files:"
 cat $outdir/filelist.plugins-base | sed 's/^/    /g'
 
 # Generate list of header files, filtering ones that go to subpackages.
 outdir="`pwd`"
 pushd $RPM_BUILD_ROOT >& /dev/null && \
 find ./${prefix}/include/murphy | \
 egrep -v '((pulse)|(ecore)|(glib)|(qt))-glue' | \
 sed 's#^./*#/#g' > $outdir/filelist.devel-includes && \
 popd >& /dev/null
 
 # Replace the default sample/test config files with the packaging ones.
 rm -f $RPM_BUILD_ROOT${sysconfdir}/murphy/*
 cp packaging.in/murphy-lua.conf $RPM_BUILD_ROOT${sysconfdir}/murphy/murphy.conf
 cp packaging.in/murphy.lua      $RPM_BUILD_ROOT${sysconfdir}/murphy/murphy.lua
 
 # Copy plugin configuration files in place.
 mkdir -p $RPM_BUILD_ROOT${sysconfdir}/murphy/plugins/amb
 cp packaging.in/amb-config.lua \
 $RPM_BUILD_ROOT${sysconfdir}/murphy/plugins/amb/config.lua
 
 # Copy tmpfiles.d config file in place
 mkdir -p $RPM_BUILD_ROOT/usr/lib/tmpfiles.d
 cp packaging.in/murphyd.conf $RPM_BUILD_ROOT/usr/lib/tmpfiles.d
 
 # Copy the systemd files in place.
 mkdir -p $RPM_BUILD_ROOT/lib/systemd/system
 mkdir -p $RPM_BUILD_ROOT/lib/systemd/user
 cp packaging.in/murphyd.service $RPM_BUILD_ROOT/lib/systemd/system
 
 mkdir -p $RPM_BUILD_ROOT${sysconfdir}/dbus-1/system.d
 cp packaging.in/org.Murphy.conf $RPM_BUILD_ROOT${sysconfdir}/dbus-1/system.d/org.Murphy.conf
 
 # copy the manifest file
 cp -a ${S}/packaging/murphy.manifest $RPM_BUILD_ROOT${prefix}/share/murphy.manifest
 cp -a ${S}/packaging/murphy.manifest $RPM_BUILD_ROOT${prefix}/share/murphy-tests.manifest
 cp -a ${S}/packaging/murphy.manifest $RPM_BUILD_ROOT${prefix}/share/murphy-ivi-resource-manager.manifest
 cp -a ${S}/packaging/murphy.manifest $RPM_BUILD_ROOT${prefix}/share/murphy-glib.manifest
 cp -a ${S}/packaging/murphy.manifest $RPM_BUILD_ROOT${prefix}/share/murphy-pulse.manifest
 cp -a ${S}/packaging/murphy.manifest $RPM_BUILD_ROOT${prefix}/share/murphy-ecore.manifest
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    ldconfig

}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    /bin/systemctl enable murphyd.service
    setcap 'cap_net_admin=+ep' $D${prefix}/bin/murphyd
    ldconfig

}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    ldconfig

}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    ldconfig

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    if [ "$1" = "0" ]; then
    /bin/systemctl disable murphyd.service
    fi
    ldconfig

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    ldconfig

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    ldconfig

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    ldconfig

}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " murphy-dev "
PACKAGES += " murphy-ecore "
PACKAGES += " murphy-pulse "
PACKAGES += " murphy "
PACKAGES += " murphy-ivi-resource-manager "
PACKAGES += " murphy-ecore-dev "
PACKAGES += " murphy-pulse-dev "
PACKAGES += " murphy-tests "
PACKAGES += " murphy-glib "
PACKAGES += " murphy-glib-dev "

murphy-dev_files = ""
murphy-dev_files += "${prefix}/include/murphy-db"
murphy-dev_files += "${prefix}/lib/libmurphy-common.so"
murphy-dev_files += "${prefix}/lib/libmurphy-core.so"
murphy-dev_files += "${prefix}/lib/libmurphy-resolver.so"
murphy-dev_files += "${prefix}/lib/libmurphy-resource.so"
murphy-dev_files += "${prefix}/lib/libmurphy-resource-backend.so"
murphy-dev_files += "${prefix}/lib/libmurphy-lua-utils.so"
murphy-dev_files += "${prefix}/lib/libmurphy-lua-decision.so"
murphy-dev_files += "${prefix}/lib/libmurphy-domain-controller.so"
murphy-dev_files += "${prefix}/lib/murphy/*.so"
murphy-dev_files += "${prefix}/lib/pkgconfig/murphy-common.pc"
murphy-dev_files += "${prefix}/lib/pkgconfig/murphy-core.pc"
murphy-dev_files += "${prefix}/lib/pkgconfig/murphy-resolver.pc"
murphy-dev_files += "${prefix}/lib/pkgconfig/murphy-lua-utils.pc"
murphy-dev_files += "${prefix}/lib/pkgconfig/murphy-lua-decision.pc"
murphy-dev_files += "${prefix}/lib/pkgconfig/murphy-domain-controller.pc"
murphy-dev_files += "${prefix}/lib/pkgconfig/murphy-db.pc"
murphy-dev_files += "${prefix}/lib/pkgconfig/murphy-resource.pc"
murphy-dev_files += "${prefix}/include/breedline"
murphy-dev_files += "${prefix}/lib/libbreedline*.so"
murphy-dev_files += "${prefix}/lib/pkgconfig/breedline*.pc"
murphy-dev_files += "${prefix}/lib/libmurphy-libdbus.so"
murphy-dev_files += "${prefix}/lib/libmurphy-dbus-libdbus.so"
murphy-dev_files += "${prefix}/lib/pkgconfig/murphy-libdbus.pc"
murphy-dev_files += "${prefix}/lib/pkgconfig/murphy-dbus-libdbus.pc"

murphy-ecore_files = ""
murphy-ecore_files += "${prefix}/lib/libmurphy-ecore.so.*"
MANIFESTFILES_${PN}-ecore = "${prefix}/share/murphy-ecore.manifest"

murphy-pulse_files = ""
murphy-pulse_files += "${prefix}/lib/libmurphy-pulse.so.*"
MANIFESTFILES_${PN}-pulse = "${prefix}/share/murphy-pulse.manifest"

murphy-doc_files = ""
murphy-doc_files += "${prefix}/share/doc/packages/../murphy/AUTHORS"
murphy-doc_files += "${prefix}/share/doc/packages/../murphy/CODING-STYLE"
murphy-doc_files += "${prefix}/share/doc/packages/../murphy/ChangeLog"
murphy-doc_files += "${prefix}/share/doc/packages/../murphy/INSTALL"
murphy-doc_files += "${prefix}/share/doc/packages/../murphy/NEWS"
murphy-doc_files += "${prefix}/share/doc/packages/../murphy/README"

murphy_files = ""
murphy_files += "${prefix}/bin/murphyd"
murphy_files += "${sysconfdir}/murphy"
murphy_files += "/lib/systemd/system/murphyd.service"
murphy_files += "/usr/lib/tmpfiles.d/murphyd.conf"
murphy_files += "${prefix}/sbin/asm-bridge"
murphy_files += "${sysconfdir}/dbus-1/system.d"
murphy_files += "${sysconfdir}/dbus-1/system.d/org.Murphy.conf"
murphy_files += "${prefix}/share/murphy"
murphy_files += "${prefix}/lib/libmurphy-common.so.*"
murphy_files += "${prefix}/lib/libmurphy-core.so.*"
murphy_files += "${prefix}/lib/libmurphy-resolver.so.*"
murphy_files += "${prefix}/lib/libmurphy-resource.so.*"
murphy_files += "${prefix}/lib/libmurphy-resource-backend.so.*"
murphy_files += "${prefix}/lib/libmurphy-lua-utils.so.*"
murphy_files += "${prefix}/lib/libmurphy-lua-decision.so.*"
murphy_files += "${prefix}/lib/libmurphy-domain-controller.so.*"
murphy_files += "${prefix}/lib/murphy/*.so.*"
murphy_files += "${prefix}/lib/libbreedline*.so.*"
murphy_files += "${prefix}/lib/libmurphy-libdbus.so.*"
murphy_files += "${prefix}/lib/libmurphy-dbus-libdbus.so.*"
murphy_files += "${prefix}/lib/murphy/plugins/plugin-domain-control.so"
murphy_files += "${prefix}/lib/murphy/plugins/plugin-resource-asm.so"
murphy_files += "${prefix}/lib/murphy/plugins/plugin-resource-native.so"
CONFFILES_${PN} = ""
CONFFILES_${PN} += "${sysconfdir}/murphy"
CONFFILES_${PN} += "${sysconfdir}/dbus-1/system.d/org.Murphy.conf"
MANIFESTFILES_${PN} = "${prefix}/share/murphy.manifest"

murphy-ivi-resource-manager_files = ""
murphy-ivi-resource-manager_files += "${prefix}/lib/murphy/plugins/plugin-ivi-resource-manager.so"
MANIFESTFILES_${PN}-ivi-resource-manager = "${prefix}/share/murphy-ivi-resource-manager.manifest"

murphy-ecore-dev_files = ""
murphy-ecore-dev_files += "${prefix}/include/murphy/common/ecore-glue.h"
murphy-ecore-dev_files += "${prefix}/lib/libmurphy-ecore.so"
murphy-ecore-dev_files += "${prefix}/lib/pkgconfig/murphy-ecore.pc"

murphy-pulse-dev_files = ""
murphy-pulse-dev_files += "${prefix}/include/murphy/common/pulse-glue.h"
murphy-pulse-dev_files += "${prefix}/lib/libmurphy-pulse.so"
murphy-pulse-dev_files += "${prefix}/lib/pkgconfig/murphy-pulse.pc"

murphy-tests_files = ""
murphy-tests_files += "${prefix}/bin/resource-client"
murphy-tests_files += "${prefix}/bin/resource-api-test"
murphy-tests_files += "${prefix}/bin/resource-api-fuzz"
murphy-tests_files += "${prefix}/bin/test-domain-controller"
murphy-tests_files += "${prefix}/bin/murphy-console"
MANIFESTFILES_${PN}-tests = "${prefix}/share/murphy-tests.manifest"

murphy-glib_files = ""
murphy-glib_files += "${prefix}/lib/libmurphy-glib.so.*"
MANIFESTFILES_${PN}-glib = "${prefix}/share/murphy-glib.manifest"

murphy-glib-dev_files = ""
murphy-glib-dev_files += "${prefix}/include/murphy/common/glib-glue.h"
murphy-glib-dev_files += "${prefix}/lib/libmurphy-glib.so"
murphy-glib-dev_files += "${prefix}/lib/pkgconfig/murphy-glib.pc"

FILES_${PN}-dev = "${murphy-dev_files}"
FILES_${PN}-ecore = "${murphy-ecore_files}"
FILES_${PN}-pulse = "${murphy-pulse_files}"
FILES_${PN}-doc = "${murphy-doc_files}"
FILES_${PN} = "${murphy_files}"
FILES_${PN}-ivi-resource-manager = "${murphy-ivi-resource-manager_files}"
FILES_${PN}-ecore-dev = "${murphy-ecore-dev_files}"
FILES_${PN}-pulse-dev = "${murphy-pulse-dev_files}"
FILES_${PN}-tests = "${murphy-tests_files}"
FILES_${PN}-glib = "${murphy-glib_files}"
FILES_${PN}-glib-dev = "${murphy-glib-dev_files}"

PKG_murphy-dev= "murphy-dev"
PKG_murphy-ecore= "murphy-ecore"
PKG_murphy-pulse= "murphy-pulse"
PKG_murphy-doc= "murphy-doc"
PKG_murphy= "murphy"
PKG_murphy-ivi-resource-manager= "murphy-ivi-resource-manager"
PKG_murphy-ecore-dev= "murphy-ecore-dev"
PKG_murphy-pulse-dev= "murphy-pulse-dev"
PKG_murphy-tests= "murphy-tests"
PKG_murphy-glib= "murphy-glib"
PKG_murphy-glib-dev= "murphy-glib-dev"

require murphy-extraconf.inc

