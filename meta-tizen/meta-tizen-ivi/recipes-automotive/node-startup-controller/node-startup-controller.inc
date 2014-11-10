DESCRIPTION = "GENIVI Node Startup Controller"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Automotive/GENIVI"
LICENSE = "MPL-2.0"
PV = "1.0.2"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by node-startup-controller


#PROVIDES by node-startup-controller-dummy
PROVIDES += "node-startup-controller-dummy"


RDEPENDS = ""
#RDEPENDS of node-startup-controller-dummy (${PN}-dummy)
RDEPENDS_${PN}-dummy += "node-startup-controller"


DEPENDS = ""
#DEPENDS of node-startup-controller
DEPENDS += "systemd"
DEPENDS += "dlt-daemon"
DEPENDS += "zlib"
inherit pkgconfig
DEPENDS += "glib-2.0"
DEPENDS += "python-xml"
DEPENDS_append_class-native = " fdupes-native"
DEPENDS_append_class-target = " fdupes-native"
DEPENDS += "gtk-doc"

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
  
  
  (test -d m4 || mkdir m4) && gtkdocize && autoreconf -ivf
  
  
  autotools_do_configure
  
  oe_runmake ARCH=i586
  
  
  
}
EXTRA_OECONF += " --prefix=/usr --sysconfdir=/etc --enable-debug=no --enable-gtk-doc=no GDBUS_CODEGEN=`which gdbus-codegen`"

do_install() {
 export RPM_BUILD_ROOT=${D}
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
 
 #fdupes ${D}
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " node-startup-controller "
PACKAGES += " node-startup-controller-dummy "

node-startup-controller_files = ""
node-startup-controller_files += "${sysconfdir}/dbus-1/system.d/org.genivi.NodeStartupController1.conf"
node-startup-controller_files += "${prefix}/lib/node-startup-controller-1/legacy-app-handler"
node-startup-controller_files += "${prefix}/lib/node-startup-controller-1/node-startup-controller"
node-startup-controller_files += "${prefix}/lib/systemd/system/node-startup-controller.service"
node-startup-controller_files += "${prefix}/share/dbus-1/system-services/org.genivi.NodeStartupController1.service"
CONFFILES_${PN} = ""
CONFFILES_${PN} += "${sysconfdir}/dbus-1/system.d/org.genivi.NodeStartupController1.conf"

node-startup-controller-dummy_files = ""
node-startup-controller-dummy_files += "${prefix}/lib/node-startup-controller-1/nsm-dummy"
node-startup-controller-dummy_files += "${prefix}/lib/systemd/system/nsm-dummy.service"
node-startup-controller-dummy_files += "${sysconfdir}/dbus-1/system.d/org.genivi.NodeStateManager.conf"
node-startup-controller-dummy_files += "${prefix}/share/dbus-1/system-services/org.genivi.NodeStateManager.Consumer.service"
node-startup-controller-dummy_files += "${prefix}/share/dbus-1/system-services/org.genivi.NodeStateManager.LifecycleControl.service"
CONFFILES_${PN}-dummy = ""
CONFFILES_${PN}-dummy += "${sysconfdir}/dbus-1/system.d/org.genivi.NodeStateManager.conf"

FILES_${PN} = "${node-startup-controller_files}"
FILES_${PN}-dummy = "${node-startup-controller-dummy_files}"

PKG_node-startup-controller= "node-startup-controller"
PKG_node-startup-controller-dummy= "node-startup-controller-dummy"

require node-startup-controller-extraconf.inc

