DESCRIPTION = "A crash dump reporting tool"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Base"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by corewatcher 
PROVIDES += "corewatcher"
RPROVIDES_corewatcher += "corewatcher"

RDEPENDS = ""
#RDEPENDS of corewatcher (${PN})
RDEPENDS_${PN} += "gdb"


DEPENDS = ""
#DEPENDS of corewatcher 
DEPENDS += "pkgconfig(libcurl)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(libsystemd-journal)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n corewatcher-0.9.11
 
 
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
 
 cp ${S}/packaging/corewatcher.manifest .
 
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
 
 make
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 
 mkdir -p ${D}//lib/systemd/system/multi-user.target.wants 
 ln -s ../corewatcher.service  ${D}//lib/systemd/system/multi-user.target.wants/corewatcher.service  
 
 
}

PACKAGES = ""
PACKAGES += "corewatcher"

corewatcher_files = ""
corewatcher_files += "corewatcher.manifest"
corewatcher_files += "corewatcher.manifest"
corewatcher_files += "/etc/corewatcher/corewatcher.conf"
corewatcher_files += "/etc/security/limits.d/95-core.conf"
corewatcher_files += "/etc/corewatcher/gdb.command"
corewatcher_files += "/usr/sbin/corewatcher"
corewatcher_files += "/lib/systemd/system/corewatcher.service"
corewatcher_files += "/lib/systemd/system/multi-user.target.wants/corewatcher.service"

FILES_${PN} = "${corewatcher_files}"

PKG_corewatcher= "corewatcher"

require corewatcher-extraconf.inc
