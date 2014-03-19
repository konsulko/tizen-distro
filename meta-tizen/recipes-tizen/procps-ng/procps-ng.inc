DESCRIPTION = "System and process monitoring utilities"
HOMEPAGE = "https://sourceforge.net/projects/procps-ng/"
SECTION = "Base/Utilities"
LICENSE = "GPL-2.0 and LGPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by procps-ng 
PROVIDES += "procps-ng"
RPROVIDES_procps-ng += "procps-ng"
# the PROVIDES rules is ignore "procps = 3.3.9"
PROVIDES += "procps"
RPROVIDES_procps-ng += "procps"
# the PROVIDES rules is ignore "/sbin/sysctl  "
PROVIDES += "/sbin/sysctl"
RPROVIDES_procps-ng += "/sbin/sysctl"
# the PROVIDES rules is ignore "/bin/ps  "
PROVIDES += "/bin/ps"
RPROVIDES_procps-ng += "/bin/ps"

#PROVIDES by procps-ng-docs  
PROVIDES += "procps-ng-docs "
RPROVIDES_procps-ng-docs  += "procps-ng-docs "

#PROVIDES by procps-ng-devel 
PROVIDES += "procps-ng-devel"
RPROVIDES_procps-ng-devel += "procps-ng-devel"
RPROVIDES_procps-ng-devel += "procps-ng-dev"
# the PROVIDES rules is ignore "procps-devel = 3.3.9"
PROVIDES += "procps-devel"
RPROVIDES_procps-ng-devel += "procps-devel"
RPROVIDES_procps-ng-devel += "procps-dev"

RDEPENDS = ""
#RDEPENDS of procps-ng (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"

#RDEPENDS of procps-ng-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "procps-ng(x86-64)"


DEPENDS = ""
#DEPENDS of procps-ng 
DEPENDS += "ncurses"
DEPENDS += "autoconf-native"
DEPENDS += "libtool-cross"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "automake-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/procps-ng.manifest .
 
 
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
         --infodir=/usr/share/info
 ./configure --prefix=/ \
             --bindir=/usr/bin \
             --sbindir=/usr/sbin \
             --libdir=/usr/lib \
             --mandir=/usr/share/man \
             --includedir=/usr/include \
             --sysconfdir=/etc \
             --docdir=/unwanted \
             --disable-static \
             --disable-w-from \
             --disable-kill \
             --disable-rpath
 
 
 make CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables"
 
 
 
 
 
 
 
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
 
 mkdir -p ${D}/etc/sysctl.d
 rm -rf ${D}/unwanted
 
 
}

PACKAGES = ""
PACKAGES += "procps-ng"
PACKAGES += "procps-ng-docs"
PACKAGES += "procps-ng-devel"

procps-ng_files = ""
procps-ng_files += "procps-ng.manifest"
procps-ng_files += "/usr/lib/libprocps.so.*"
procps-ng_files += "/usr/bin/*"
procps-ng_files += "/usr/sbin/*"
procps-ng_files += "/etc/sysctl.d"

procps-ng-docs_files = ""
procps-ng-docs_files += "/usr/share/info"
procps-ng-docs_files += "/usr/share/man"

procps-ng-devel_files = ""
procps-ng-devel_files += "procps-ng.manifest"
procps-ng-devel_files += "/usr/lib/libprocps.so"
procps-ng-devel_files += "/usr/include/proc"
procps-ng-devel_files += "/usr/lib/pkgconfig/libprocps.pc"

FILES_${PN} = "${procps-ng_files}"
FILES_${PN}-docs = "${procps-ng-docs_files}"
FILES_${PN}-devel = "${procps-ng-devel_files}"

PKG_procps-ng= "procps-ng"
PKG_procps-ng-docs= "procps-ng-docs"
PKG_procps-ng-devel= "procps-ng-devel"

require procps-ng-extraconf.inc
