DESCRIPTION = "System wide profiler"
HOMEPAGE = "http://oprofile.sf.net"
SECTION = "Base/Tools"
LICENSE = "GPL-2.0+ and LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by oprofile-jit 
PROVIDES += "oprofile-jit"
RPROVIDES_oprofile-jit += "oprofile-jit"

#PROVIDES by oprofile-docs  
PROVIDES += "oprofile-docs "
RPROVIDES_oprofile-docs  += "oprofile-docs "

#PROVIDES by oprofile 
PROVIDES += "oprofile"
RPROVIDES_oprofile += "oprofile"

#PROVIDES by oprofile-devel 
PROVIDES += "oprofile-devel"
RPROVIDES_oprofile-devel += "oprofile-devel"
RPROVIDES_oprofile-devel += "oprofile-dev"

RDEPENDS = ""
#RDEPENDS of oprofile-jit (${PN}-jit)
RDEPENDS_${PN}-jit += "oprofile"

#RDEPENDS of oprofile (${PN})
RDEPENDS_${PN} += "pwdutils"
RDEPENDS_${PN} += "which"

#RDEPENDS of oprofile-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "oprofile"


DEPENDS = ""
#DEPENDS of oprofile 
DEPENDS += "pkgconfig(popt)"
DEPENDS += "binutils"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/oprofile.manifest .
 
 
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
         --infodir=/usr/share/info --enable-gui=no
 make -j16
 
 
 
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
 
 mkdir -p ${D}/etc/ld.so.conf.d
 echo "/usr/lib/oprofile" > ${D}/etc/ld.so.conf.d/oprofile-x86_64.conf
 
 rm -rf ${D}/usr/share/doc
 
 
}

PACKAGES = ""
PACKAGES += "oprofile-jit"
PACKAGES += "oprofile"
PACKAGES += "oprofile-devel"
PACKAGES += "oprofile-docs"

oprofile-jit_files = ""
oprofile-jit_files += "oprofile.manifest"
oprofile-jit_files += "/etc/ld.so.conf.d/*"
oprofile-jit_files += "/usr/lib/oprofile"

oprofile_files = ""
oprofile_files += "oprofile.manifest"
oprofile_files += "/usr/bin/ophelp"
oprofile_files += "/usr/bin/opimport"
oprofile_files += "/usr/bin/opannotate"
oprofile_files += "/usr/bin/opcontrol"
oprofile_files += "/usr/bin/opgprof"
oprofile_files += "/usr/bin/opreport"
oprofile_files += "/usr/bin/oprofiled"
oprofile_files += "/usr/bin/oparchive"
oprofile_files += "/usr/bin/opjitconv"
oprofile_files += "/usr/bin/op-check-perfevents"
oprofile_files += "/usr/bin/operf"
oprofile_files += "/usr/share/oprofile"

oprofile-devel_files = ""
oprofile-devel_files += "oprofile.manifest"
oprofile-devel_files += "/usr/include/opagent.h"

oprofile-docs_files = ""
oprofile-docs_files += "/usr/share/info"
oprofile-docs_files += "/usr/share/man"

FILES_${PN}-jit = "${oprofile-jit_files}"
FILES_${PN} = "${oprofile_files}"
FILES_${PN}-devel = "${oprofile-devel_files}"
FILES_${PN}-docs = "${oprofile-docs_files}"

PKG_oprofile-jit= "oprofile-jit"
PKG_oprofile= "oprofile"
PKG_oprofile-devel= "oprofile-devel"
PKG_oprofile-docs= "oprofile-docs"

require oprofile-extraconf.inc
