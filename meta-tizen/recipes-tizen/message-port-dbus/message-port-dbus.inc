DESCRIPTION = "Message port daemon"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Service"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by libmessage-port
PROVIDES += "libmessage-port"


#PROVIDES by libmessage-port-dev
PROVIDES += "libmessage-port-dev"


#PROVIDES by message-port-tests
PROVIDES += "message-port-tests"


#PROVIDES by message-port
PROVIDES += "message-port"


RDEPENDS = ""
#RDEPENDS of libmessage-port (libmessage-port)
RDEPENDS_libmessage-port += "eglibc"
RDEPENDS_libmessage-port += "message-port-dbus"

#RDEPENDS of libmessage-port-dev (libmessage-port-dev)
RDEPENDS_libmessage-port-dev += "libmessage-port"

#RDEPENDS of message-port-tests (message-port-tests)
RDEPENDS_message-port-tests += "libmessage-port"


DEPENDS = ""
#DEPENDS of libmessage-port
#DEPENDS of message-port
DEPENDS += "dlog"
DEPENDS += "aul"
DEPENDS += "pkgmgr-info"
DEPENDS += "glib-2.0"
DEPENDS += "bundle"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n message-port-1.0.3
 cp -a ${S}/packaging/message-port.manifest .
 mkdir -p m4 > /dev/null
 
 
 
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
  
  
  autotools_do_configure
  oe_runmake -j16
  
  
  
  
}
EXTRA_OECONF += " --enable-tests "

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
 
 mkdir -p ${RPM_BUILD_ROOT}/lib/systemd/system
 cp messageportd.service $RPM_BUILD_ROOT/lib/systemd/system
 
 
 
}

pkg_postinst_libmessage-port() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig

}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    /bin/systemctl enable messageportd.service

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    /bin/systemctl disable messageportd.service

}

pkg_postrm_libmessage-port() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
    # daemon: message-port

}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " libmessage-port "
PACKAGES += " libmessage-port-dev "
PACKAGES += " message-port-tests "
PACKAGES += " message-port "

libmessage-port_files = ""
libmessage-port_files += "AUTHORS COPYING.LIB README"
libmessage-port_files += "${prefix}/lib/libmessage-port.so*"
MANIFESTFILES_libmessage-port = "message-port.manifest"

libmessage-port-dev_files = ""
libmessage-port-dev_files += "${prefix}/lib/pkgconfig/message-port.pc"
libmessage-port-dev_files += "${prefix}/include/*.h"
MANIFESTFILES_libmessage-port-dev = "message-port.manifest"

message-port-tests_files = ""
message-port-tests_files += "${prefix}/bin/msgport-test-app"
message-port-tests_files += "${prefix}/bin/msgport-test-app-cpp"
MANIFESTFILES_message-port-tests = "message-port.manifest"

message-port_files = ""
message-port_files += "${prefix}/bin/messageportd"
message-port_files += "/lib/systemd/system/messageportd.service"

FILES_libmessage-port = "${libmessage-port_files}"
FILES_libmessage-port-dev = "${libmessage-port-dev_files}"
FILES_message-port-tests = "${message-port-tests_files}"
FILES_message-port = "${message-port_files}"

PKG_libmessage-port= "libmessage-port"
PKG_libmessage-port-dev= "libmessage-port-dev"
PKG_message-port-tests= "message-port-tests"
PKG_message-port= "message-port"

require message-port-dbus-extraconf.inc

