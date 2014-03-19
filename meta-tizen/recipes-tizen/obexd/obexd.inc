DESCRIPTION = "D-Bus service for Obex Client access"
HOMEPAGE = "http://www.bluez.org/"
SECTION = "System/Service"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by obexd-client 
PROVIDES += "obexd-client"
RPROVIDES_obexd-client += "obexd-client"

#PROVIDES by obexd 
PROVIDES += "obexd"
RPROVIDES_obexd += "obexd"

#PROVIDES by obexd-server 
PROVIDES += "obexd-server"
RPROVIDES_obexd-server += "obexd-server"

#PROVIDES by obexd-test 
PROVIDES += "obexd-test"
RPROVIDES_obexd-test += "obexd-test"

RDEPENDS = ""
#RDEPENDS of obexd-client (${PN}-client)
RDEPENDS_${PN}-client += "obexd"

#RDEPENDS of obexd-server (${PN}-server)
RDEPENDS_${PN}-server += "obexd"

#RDEPENDS of obexd-test (${PN}-test)
RDEPENDS_${PN}-test += "python-xml"
RDEPENDS_${PN}-test += "obexd"
RDEPENDS_${PN}-test += "dbus-python"
RDEPENDS_${PN}-test += "python-gobject"


DEPENDS = ""
#DEPENDS of obexd 
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "update-desktop-files"
DEPENDS += "bluez"
DEPENDS += "libtool-cross"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "libical"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/obexd.manifest .
 
 
}

do_configure() {
}

do_compile() {
 LANG=C
 export LANG
 unset DISPLAY
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ; 
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
 LD_AS_NEEDED=1; export LD_AS_NEEDED ; 
 
 autoreconf -f -i
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=x86_64-tizen-linux \
         --program-prefix= \
         --prefix=/usr \
         --exec-prefix=/usr \
         --bindir=/usr/bin \
         --sbindir=/usr/sbin \
         --sysconfdir=/etc \
         --datadir=/usr/share \
         --includedir=/usr/include \
         --libdir=/usr/lib \
         --libexecdir=/usr/libexec \
         --localstatedir=/var \
         --sharedstatedir=/usr/com \
         --mandir=/usr/share/man \
         --infodir=/usr/share/info --libexecdir=/usr/lib/obex --with-phonebook=dummy \
 	--disable-static
 unset LD_AS_NEEDED
 make -j16
 sed -i -e "s,@libexecdir@,/usr/lib/obex,g" ${S}/packaging/obexd-server.desktop
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir examples/
 
 mkdir -p ${D}//etc/xdg/autostart/
 install -m 0644 ${S}/packaging/obexd-server.desktop ${D}//etc/xdg/autostart/
 install -m 0755 ${S}/packaging/obexd-setup.sh ${D}//usr/lib/obex/obexd-setup.sh
 
 chmod 755 test/*
 
 
}

PACKAGES = ""
PACKAGES += "obexd-client"
PACKAGES += "obexd"
PACKAGES += "obexd-server"
PACKAGES += "obexd-test"

obexd-client_files = ""
obexd-client_files += "obexd.manifest"
obexd-client_files += "/usr/lib/obex"
obexd-client_files += "/usr/lib/obex/obex-client"
obexd-client_files += "/usr/share/dbus-1/services/obex-client.service"

obexd_files = ""
obexd_files += "obexd.manifest"

obexd-server_files = ""
obexd-server_files += "obexd.manifest"
obexd-server_files += "/usr/lib/obex"
obexd-server_files += "/usr/lib/obex/obexd"
obexd-server_files += "/usr/lib/obex/obexd-setup.sh"
obexd-server_files += "/usr/share/dbus-1/services/obexd.service"
obexd-server_files += "/etc/xdg/autostart/obexd-server.desktop"

obexd-test_files = ""
obexd-test_files += "obexd.manifest"
obexd-test_files += "test/*"

FILES_${PN}-client = "${obexd-client_files}"
FILES_${PN} = "${obexd_files}"
FILES_${PN}-server = "${obexd-server_files}"
FILES_${PN}-test = "${obexd-test_files}"

PKG_obexd-client= "obexd-client"
PKG_obexd= "obexd"
PKG_obexd-server= "obexd-server"
PKG_obexd-test= "obexd-test"

require obexd-extraconf.inc
