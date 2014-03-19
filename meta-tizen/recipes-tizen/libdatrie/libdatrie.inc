DESCRIPTION = "Double-Array Trie Library"
HOMEPAGE = "http://linux.thai.net/~thep/datrie/datrie.html"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libdatrie 
PROVIDES += "libdatrie"
RPROVIDES_libdatrie += "libdatrie"

#PROVIDES by libdatrie-devel 
PROVIDES += "libdatrie-devel"
RPROVIDES_libdatrie-devel += "libdatrie-devel"
RPROVIDES_libdatrie-devel += "libdatrie-dev"

RDEPENDS = ""
#RDEPENDS of libdatrie-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libdatrie"


DEPENDS = ""
#DEPENDS of libdatrie 
DEPENDS += "doxygen"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libdatrie.manifest .
 
 
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
         --infodir=/usr/share/info \
         --disable-static --with-pic \
         --with-html-docdir=/usr/share/doc/packages/libdatrie/html
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
 # This is not installed where it should
 mv ${D}/usr/share/doc/libdatrie/README.migration ${D}/usr/share/doc/packages/libdatrie/
 
 
}

PACKAGES = ""
PACKAGES += "libdatrie"
PACKAGES += "libdatrie-devel"

libdatrie_files = ""
libdatrie_files += "libdatrie.manifest"
libdatrie_files += "COPYING"
libdatrie_files += "/usr/lib/libdatrie.so.1*"

libdatrie-devel_files = ""
libdatrie-devel_files += "libdatrie.manifest"
libdatrie-devel_files += "/usr/bin/trietool-0.2"
libdatrie-devel_files += "/usr/share/man/man*/trietool-0.2.*"
libdatrie-devel_files += "/usr/include/datrie/"
libdatrie-devel_files += "/usr/lib/libdatrie.so"
libdatrie-devel_files += "/usr/lib/pkgconfig/datrie-0.2.pc"
libdatrie-devel_files += "/usr/share/doc/packages/libdatrie/"

FILES_${PN} = "${libdatrie_files}"
FILES_${PN}-devel = "${libdatrie-devel_files}"

PKG_libdatrie= "libdatrie"
PKG_libdatrie-devel= "libdatrie-devel"

require libdatrie-extraconf.inc
