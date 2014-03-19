DESCRIPTION = "A library for handling streaming archive formats"
HOMEPAGE = "http://code.google.com/p/libarchive/"
SECTION = "System/Libraries"
LICENSE = "BSD-2-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libarchive-tools 
PROVIDES += "libarchive-tools"
RPROVIDES_libarchive-tools += "libarchive-tools"

#PROVIDES by libarchive-devel 
PROVIDES += "libarchive-devel"
RPROVIDES_libarchive-devel += "libarchive-devel"
RPROVIDES_libarchive-devel += "libarchive-dev"

#PROVIDES by libarchive 
PROVIDES += "libarchive"
RPROVIDES_libarchive += "libarchive"

RDEPENDS = ""
#RDEPENDS of libarchive-tools (${PN}-tools)
RDEPENDS_${PN}-tools += "libarchive"

#RDEPENDS of libarchive-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libarchive"


DEPENDS = ""
#DEPENDS of libarchive 
DEPENDS += "zlib-devel"
DEPENDS += "bzip2"
DEPENDS += "attr"
DEPENDS += "pkgconfig(openssl)"
DEPENDS += "e2fsprogs"
DEPENDS += "acl"
DEPENDS += "bison-native"
DEPENDS += "pkgconfig(liblzma)"
DEPENDS += "libtool-cross"
DEPENDS += "autoconf-native"
DEPENDS += "automake-native"
DEPENDS += "pkgconfig(libxml-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libarchive.manifest .
 
 
 
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
 
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -D_REENTRANT -pipe}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -D_REENTRANT -pipe}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -D_REENTRANT -pipe -I%_fmoddir}" ; export FFLAGS ; 
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
         --infodir=/usr/share/info --disable-static --enable-bsdcpio
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
 
 find ${D} -name cpio.5 -exec rm -f {} ';'
 find ${D} -name mtree.5 -exec rm -f {} ';'
 find ${D} -name tar.5 -exec rm -f {} ';'
 
 
}

PACKAGES = ""
PACKAGES += "libarchive-tools"
PACKAGES += "libarchive-devel"
PACKAGES += "libarchive"

libarchive-tools_files = ""
libarchive-tools_files += "/usr/bin/bsdcpio"
libarchive-tools_files += "/usr/bin/bsdtar"

libarchive-devel_files = ""
libarchive-devel_files += "libarchive.manifest"
libarchive-devel_files += "/usr/include/*"
libarchive-devel_files += "/usr/share/man/*/*"
libarchive-devel_files += "/usr/lib/*.so"
libarchive-devel_files += "/usr/lib/pkgconfig/*"

libarchive_files = ""
libarchive_files += "libarchive.manifest"
libarchive_files += "/usr/lib/*.so.*"

FILES_${PN}-tools = "${libarchive-tools_files}"
FILES_${PN}-devel = "${libarchive-devel_files}"
FILES_${PN} = "${libarchive_files}"

PKG_libarchive-tools= "libarchive-tools"
PKG_libarchive-devel= "libarchive-devel"
PKG_libarchive= "libarchive"

require libarchive-extraconf.inc
