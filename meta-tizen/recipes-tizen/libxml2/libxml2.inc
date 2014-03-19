DESCRIPTION = "A Library to Manipulate XML Files"
HOMEPAGE = "http://xmlsoft.org"
SECTION = "System/Libraries"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libxml2 
PROVIDES += "libxml2"
RPROVIDES_libxml2 += "libxml2"

#PROVIDES by libxml2-devel 
PROVIDES += "libxml2-devel"
RPROVIDES_libxml2-devel += "libxml2-devel"
RPROVIDES_libxml2-devel += "libxml2-dev"

#PROVIDES by libxml2-tools 
PROVIDES += "libxml2-tools"
RPROVIDES_libxml2-tools += "libxml2-tools"

RDEPENDS = ""
#RDEPENDS of libxml2-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "zlib-dev"
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "xz-dev"
RDEPENDS_${PN}-devel += "readline-dev"
RDEPENDS_${PN}-devel += "libxml2"
RDEPENDS_${PN}-devel += "libxml2-tools"


DEPENDS = ""
#DEPENDS of libxml2 
DEPENDS += "zlib-devel"
DEPENDS += "xz-devel"
DEPENDS += "pkgconfig-native"
DEPENDS += "readline-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libxml2.manifest .
 
 
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
         --infodir=/usr/share/info --disable-static \
     --docdir=/usr/share/doc/packages/libxml2 \
     --with-html-dir=/usr/share/doc/packages/libxml2/html \
     --with-fexceptions \
     --with-history \
     --without-python \
     --enable-ipv6 \
     --with-sax1 \
     --with-regexps \
     --with-threads \
     --with-reader \
     --with-http
 
 make -j16 BASE_DIR="/usr/share/doc/packages" DOC_MODULE="libxml2"
 
 exit 0
 # qemu-arm can't keep up atm, disabling check for arm
 make check
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR="${D}" BASE_DIR="/usr/share/doc/packages" DOC_MODULE="libxml2"
 ln -s libxml2/libxml ${D}/usr/include/libxml
 
 
   rm -rf ${D}/usr/share/info 
   rm -rf ${D}/usr/share/doc/packages 
   rm -rf ${D}/usr/share/doc/libxml2 
   rm -rf ${D}/usr/share/doc/libxml2-2.8.0 
   rm -rf ${D}/usr/share/gtk-doc 
   rm -rf ${D}/usr/share/doc 
   rm -rf ${D}/usr/share/man 
   find ${D} -regex ".*/man/man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/../man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/man./.*.[0-9]pm" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "libxml2"
PACKAGES += "libxml2-devel"
PACKAGES += "libxml2-tools"

libxml2_files = ""
libxml2_files += "libxml2.manifest"
libxml2_files += "/usr/lib/lib*.so.*"

libxml2-devel_files = ""
libxml2-devel_files += "libxml2.manifest"
libxml2-devel_files += "/usr/bin/xml2-config"
libxml2-devel_files += "/usr/share/aclocal"
libxml2-devel_files += "/usr/share/aclocal/libxml.m4"
libxml2-devel_files += "/usr/include/libxml"
libxml2-devel_files += "/usr/include/libxml2"
libxml2-devel_files += "/usr/lib/lib*.so"
libxml2-devel_files += "/usr/lib/libxml2.la"
libxml2-devel_files += "/usr/lib/*.sh"
libxml2-devel_files += "/usr/lib/pkgconfig/*.pc"

libxml2-tools_files = ""
libxml2-tools_files += "libxml2.manifest"
libxml2-tools_files += "/usr/bin/xmllint"
libxml2-tools_files += "/usr/bin/xmlcatalog"

FILES_${PN} = "${libxml2_files}"
FILES_${PN}-devel = "${libxml2-devel_files}"
FILES_${PN}-tools = "${libxml2-tools_files}"

PKG_libxml2= "libxml2"
PKG_libxml2-devel= "libxml2-devel"
PKG_libxml2-tools= "libxml2-tools"

require libxml2-extraconf.inc
