DESCRIPTION = "D-Bus Message Bus System"
HOMEPAGE = "http://dbus.freedesktop.org/"
SECTION = "Base/IPC"
LICENSE = "GPL-2.0+ or AFL-2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by dbus-docs  
PROVIDES += "dbus-docs "
RPROVIDES_dbus-docs  += "dbus-docs "

#PROVIDES by dbus 
PROVIDES += "dbus"
RPROVIDES_dbus += "dbus"

#PROVIDES by dbus-devel-doc 
PROVIDES += "dbus-devel-doc"
RPROVIDES_dbus-devel-doc += "dbus-devel-doc"
RPROVIDES_dbus-devel-doc += "dbus-dev"

RDEPENDS = ""
#RDEPENDS of dbus (${PN})
RDEPENDS_${PN} += "/usr/sbin/useradd"
RDEPENDS_${PN} += "/usr/sbin/groupadd"

#RDEPENDS of dbus-devel-doc (${PN}-devel-doc)
RDEPENDS_${PN}-devel-doc += "dbus"


DEPENDS = ""
#DEPENDS of dbus 
DEPENDS += "doxygen"
DEPENDS += "libxslt-tools"
DEPENDS += "pkgconfig(libsmack)"
DEPENDS += "libzio"
DEPENDS += "expat-devel"
DEPENDS += "pkgconfig-native"
DEPENDS += "pkgconfig(libsystemd-login)"
DEPENDS += "libcap-ng-devel"
DEPENDS += "libtool-cross"
DEPENDS += "pkgconfig(libsystemd-daemon)"
DEPENDS += "xmlto"

do_patch() {
 # COMMON2-BEGIN
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -n dbus-1.6.12 -q
 
 
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
 
 autoreconf -fi
 # We use -fpie/-pie for the whole build; this is the recommended way to harden
 # the build upstream, see discussion in fdo#46570
 export CFLAGS="${RPM_OPT_FLAGS} -fno-strict-aliasing -fPIC -fpie"
 export LDFLAGS="-pie"
 export CXXFLAGS="${RPM_OPT_FLAGS} -fno-strict-aliasing"
 export CFLAGS="$CFLAGS -fstack-protector"
 export CXXFLAGS="$CXXFLAGS -fstack-protector"
 export V=1
 
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
         --infodir=/usr/share/info \
     --disable-static 							\
     --with-pic 								\
     --with-dbus-user=dbus 						\
     --libexecdir=/usr/lib/dbus					\
     --libdir=/usr/lib							\
     --with-init-scripts=suse						\
     --enable-inotify							\
     --enable-doxygen-docs						\
     --enable-systemd							\
     --with-console-auth-dir=/var/run/dbus/at_console/			\
     --with-systemdsystemunitdir=/lib/systemd/system				\
     --enable-smack
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 # COMMON2-END
 make DESTDIR=${D} install
 mkdir -p ${D}/usr/sbin
 install -d ${D}//var/run/dbus
 mkdir -p ${D}//usr/lib/pkgconfig
 mkdir -p ${D}/lib/dbus-1/system-services
 mkdir -p ${D}//usr/share/dbus-1/system-services
 mkdir -p ${D}//usr/share/dbus-1/interfaces
 #
 chmod a-x AUTHORS COPYING HACKING NEWS README doc/*.txt doc/file-boilerplate.c doc/TODO
 #
 install -d ${D}/etc/ConsoleKit/run-session.d
 install -m 755 ${S}/packaging/dbus_at_console.ck ${D}/etc/ConsoleKit/run-session.d
 mkdir -p ${D}/var/lib/dbus
 touch ${D}//var/lib/dbus/machine-id
 
 mkdir -p ${D}/lib/systemd/user
 install -m0644 ${S}/packaging/dbus-user.service ${D}/lib/systemd/user/dbus.service
 install -m0644 ${S}/packaging/dbus-user.socket ${D}/lib/systemd/user/dbus.socket
 # File packaged by libdbus and dbus-devel
 rm -rf ${D}//usr/include/*
 rm -rf ${D}//usr/lib/*.la
 rm -rf ${D}//usr/lib/libdbus-1.so
 rm -rf ${D}//usr/lib/libdbus-1.so.*
 rm -rf ${D}//usr/lib/dbus-1.0/include
 rm -rf ${D}//usr/lib/pkgconfig/dbus-1.pc
 rm -rf ${D}//usr/share/man/man1/dbus-launch.1*
 rm -rf ${D}//usr/bin/dbus-launch
 
 
 
}

PACKAGES = ""
PACKAGES += "dbus"
PACKAGES += "dbus-devel-doc"
PACKAGES += "dbus-docs"

dbus_files = ""
dbus_files += "/var/lib/dbus"
dbus_files += "/lib/dbus-1"
dbus_files += "/lib/dbus-1/system-services"
dbus_files += "/etc/dbus-1/session.conf"
dbus_files += "/etc/dbus-1/system.conf"
dbus_files += "/etc/ConsoleKit"
dbus_files += "/usr/bin/dbus-cleanup-sockets"
dbus_files += "/usr/bin/dbus-daemon"
dbus_files += "/usr/bin/dbus-monitor"
dbus_files += "/usr/bin/dbus-send"
dbus_files += "/usr/bin/dbus-uuidgen"
dbus_files += "/lib/systemd/system"
dbus_files += "/lib/systemd/system/dbus.service"
dbus_files += "/lib/systemd/system/dbus.socket"
dbus_files += "/lib/systemd/user/dbus.service"
dbus_files += "/lib/systemd/user/dbus.socket"
dbus_files += "/lib/systemd/system/dbus.target.wants"
dbus_files += "/lib/systemd/system/dbus.target.wants/dbus.socket"
dbus_files += "/lib/systemd/system/multi-user.target.wants"
dbus_files += "/lib/systemd/system/multi-user.target.wants/dbus.service"
dbus_files += "/lib/systemd/system/sockets.target.wants"
dbus_files += "/lib/systemd/system/sockets.target.wants/dbus.socket"
dbus_files += "/etc/dbus-1"
dbus_files += "/etc/dbus-1/session.d"
dbus_files += "/etc/dbus-1/system.d"
dbus_files += "/usr/share/dbus-1"
dbus_files += "/usr/share/dbus-1/interfaces"
dbus_files += "/usr/share/dbus-1/services"
dbus_files += "/usr/share/dbus-1/system-services"

dbus-devel-doc_files = ""
dbus-devel-doc_files += "/usr/share/doc/dbus"
dbus-devel-doc_files += "/usr/share/doc/dbus/api/"
dbus-devel-doc_files += "/usr/share/doc/dbus/dbus-faq.html"
dbus-devel-doc_files += "/usr/share/doc/dbus/dbus-specification.html"
dbus-devel-doc_files += "/usr/share/doc/dbus/dbus-test-plan.html"
dbus-devel-doc_files += "/usr/share/doc/dbus/dbus-tutorial.html"
dbus-devel-doc_files += "/usr/share/doc/dbus/dbus.devhelp"
dbus-devel-doc_files += "/usr/share/doc/dbus/diagram.*"
dbus-devel-doc_files += "/usr/share/doc/dbus/system-activation.txt"
dbus-devel-doc_files += "doc/*.txt doc/file-boilerplate.c doc/TODO"

dbus-docs_files = ""
dbus-docs_files += "/usr/share/info"
dbus-docs_files += "/usr/share/man"

FILES_${PN} = "${dbus_files}"
FILES_${PN}-devel-doc = "${dbus-devel-doc_files}"
FILES_${PN}-docs = "${dbus-docs_files}"

PKG_dbus= "dbus"
PKG_dbus-devel-doc= "dbus-devel-doc"
PKG_dbus-docs= "dbus-docs"

require dbus-extraconf.inc
