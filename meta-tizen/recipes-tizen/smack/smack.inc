DESCRIPTION = "Selection of tools for developers working with Smack"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Security/Access Control"
LICENSE = "LGPL-2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by smack-devel 
PROVIDES += "smack-devel"
RPROVIDES_smack-devel += "smack-devel"
RPROVIDES_smack-devel += "smack-dev"

#PROVIDES by smack 
PROVIDES += "smack"
RPROVIDES_smack += "smack"

#PROVIDES by libsmack 
PROVIDES += "libsmack"
RPROVIDES_libsmack += "libsmack"

#PROVIDES by smack-docs  
PROVIDES += "smack-docs "
RPROVIDES_smack-docs  += "smack-docs "

RDEPENDS = ""
#RDEPENDS of smack-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libsmack"


DEPENDS = ""
#DEPENDS of smack 
DEPENDS += "autoconf-native"
DEPENDS += "libtool-cross"
DEPENDS += "automake-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/smack.manifest .
 
 
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
 
 autoreconf --install --symlink
 
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
         --infodir=/usr/share/info --with-systemdsystemunitdir=/usr/lib/systemd/system
 
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
 
 install -d ${D}/etc/smack/accesses.d
 install -d ${D}/etc/smack/cipso.d
 install -d ${D}/smack
 
 
 
}

PACKAGES = ""
PACKAGES += "smack-devel"
PACKAGES += "smack"
PACKAGES += "libsmack"
PACKAGES += "smack-docs"

smack-devel_files = ""
smack-devel_files += "smack.manifest"
smack-devel_files += "/usr/include/sys/smack.h"
smack-devel_files += "/usr/lib/libsmack.so"
smack-devel_files += "/usr/lib/pkgconfig/libsmack.pc"

smack_files = ""
smack_files += "smack.manifest"
smack_files += "/etc/smack"
smack_files += "/etc/smack/accesses.d"
smack_files += "/etc/smack/cipso.d"

libsmack_files = ""
libsmack_files += "smack.manifest"
libsmack_files += "/usr/lib/libsmack.so.*"

smack-docs_files = ""
smack-docs_files += "/usr/share/info"
smack-docs_files += "/usr/share/man"

FILES_${PN}-devel = "${smack-devel_files}"
FILES_${PN} = "${smack_files}"
FILES_lib${PN} = "${libsmack_files}"
FILES_${PN}-docs = "${smack-docs_files}"

PKG_smack-devel= "smack-devel"
PKG_smack= "smack"
PKG_libsmack= "libsmack"
PKG_smack-docs= "smack-docs"

require smack-extraconf.inc
