DESCRIPTION = "Local network service discovery"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System Environment/Base"
LICENSE = "LGPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by avahi-devel 
PROVIDES += "avahi-devel"
RPROVIDES_avahi-devel += "avahi-devel"
RPROVIDES_avahi-devel += "avahi-dev"

#PROVIDES by avahi 
PROVIDES += "avahi"
RPROVIDES_avahi += "avahi"

#PROVIDES by avahi-data 
PROVIDES += "avahi-data"
RPROVIDES_avahi-data += "avahi-data"

#PROVIDES by avahi-libs 
PROVIDES += "avahi-libs"
RPROVIDES_avahi-libs += "avahi-libs"

RDEPENDS = ""
#RDEPENDS of avahi-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "pkgconfig"
RDEPENDS_${PN}-devel += "avahi-libs"

#RDEPENDS of avahi-data (${PN}-data)
RDEPENDS_${PN}-data += "avahi"

#RDEPENDS of avahi (${PN})
RDEPENDS_${PN} += "dbus"
RDEPENDS_${PN} += "expat"
RDEPENDS_${PN} += "eglibc"
RDEPENDS_${PN} += "avahi-libs"

#RDEPENDS of avahi-libs (${PN}-libs)
RDEPENDS_${PN}-libs += "poppler-tools"


DEPENDS = ""
#DEPENDS of avahi 
DEPENDS += "intltool-native"
DEPENDS += "expat-devel"
DEPENDS += "dbus-devel"
DEPENDS += "automake-native"
DEPENDS += "libtool-cross"
DEPENDS += "libcap-devel"
DEPENDS += "libdaemon-devel"
DEPENDS += "libxml-parser-perl"
DEPENDS += "dbus-glib-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/avahi.manifest ${S}/packaging/avahi-libs.manifest ${S}/packaging/avahi-devel.manifest ${S}/packaging/avahi-data.manifest .
 
 ##patch1 -p1
 
 
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
         --infodir=/usr/share/info --with-distro=fedora --with-avahi-user=app --with-avahi-group=app --with-avahi-priv-access-group=app \
 		--disable-compat-libdns_sd \
 		--disable-mono \
 		--disable-monodoc \
 		--disable-qt3 \
 		--disable-qt4 \
 		--disable-gtk \
 		--disable-gtk3\
 		--disable-python \
 		--disable-pygtk \
 		--disable-python-dbus \
 		--disable-doxygen-doc\
 		--disable-doxygen-dot\
 		--disable-doxygen-xml\
 		--disable-doxygen-html\
 		--disable-doxygen-manpages\
 		--disable-doxygen-xmltoman\
 		--disable-glib \
 		--disable-gobject \
 		--disable-gdbm \
         --sysconfdir=/usr/etc  \
 		--localstatedir=/opt/var \
 		--without-systemdsystemunitdir
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
 rm -rf $RPM_BUILD_ROOT
 make install DESTDIR=$RPM_BUILD_ROOT
 
 mkdir -p ${D}/usr/share/license
 cp ${WORKDIR}/git/LICENSE ${D}/usr/share/license/avahi
 cp ${WORKDIR}/git/LICENSE ${D}/usr/share/license/avahi-libs
 cp ${WORKDIR}/git/LICENSE ${D}/usr/share/license/avahi-data
 
 rm -f $RPM_BUILD_ROOT/usr/lib/*.la
 rm -f $RPM_BUILD_ROOT/usr/lib/*.a
 
 # remove example
 rm -f $RPM_BUILD_ROOT/usr/etc/avahi/services/sftp-ssh.service
 
 # create /var/run/avahi-daemon to ensure correct selinux policy for it:
 mkdir -p $RPM_BUILD_ROOT/opt/var/run/avahi-daemon
 
 
 #mkdir -p $RPM_BUILD_ROOT/var/lib/avahi-autoipd
 
 # remove the documentation directory - let % doc handle it:
 #rm -rf $RPM_BUILD_ROOT/usr/share/avahi-0.6.30
 
 # Make /etc/avahi/etc/localtime owned by avahi:
 mkdir -p $RPM_BUILD_ROOT/usr/etc/avahi/etc
 touch $RPM_BUILD_ROOT/usr/etc/avahi/etc/localtime
 
 # fix bug 197414 - add missing symlinks for avahi-compat-howl and avahi-compat-dns-sd
 #%if 0
 #ln -s avahi-compat-howl.pc  $RPM_BUILD_ROOT//usr/lib/pkgconfig/howl.pc
 #%endif
 #%if 0
 #ln -s avahi-compat-libdns_sd.pc $RPM_BUILD_ROOT//usr/lib/pkgconfig/libdns_sd.pc
 #ln -s avahi-compat-libdns_sd/dns_sd.h $RPM_BUILD_ROOT//usr/include/
 #%endif
 #
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} avahi
 
 
}

PACKAGES = ""
PACKAGES += "avahi-devel"
PACKAGES += "avahi-data"
PACKAGES += "avahi"
PACKAGES += "avahi-libs"

avahi-devel_files = ""
avahi-devel_files += "avahi-devel.manifest"
avahi-devel_files += "/usr/include/avahi-client"
avahi-devel_files += "/usr/include/avahi-common"
avahi-devel_files += "/usr/include/avahi-core"
avahi-devel_files += "/usr/lib/pkgconfig/avahi-core.pc"
avahi-devel_files += "/usr/lib/pkgconfig/avahi-client.pc"

avahi-data_files = ""
avahi-data_files += "avahi-data.manifest"
avahi-data_files += "/usr/share/license/avahi-data"
avahi-data_files += "/usr/etc/avahi"
avahi-data_files += "/usr/etc/avahi/etc"
avahi-data_files += "/usr/etc/avahi/avahi-daemon.conf"

avahi_files = ""
avahi_files += "avahi.manifest"
avahi_files += "/usr/share/license/avahi"

avahi-libs_files = ""
avahi-libs_files += "avahi-libs.manifest"
avahi-libs_files += "/usr/share/license/avahi-libs"
avahi-libs_files += "/usr/lib/avahi"

FILES_${PN}-devel = "${avahi-devel_files}"
FILES_${PN}-data = "${avahi-data_files}"
FILES_${PN} = "${avahi_files}"
FILES_${PN}-libs = "${avahi-libs_files}"

PKG_avahi-devel= "avahi-devel"
PKG_avahi-data= "avahi-data"
PKG_avahi= "avahi"
PKG_avahi-libs= "avahi-libs"

require avahi-extraconf.inc
