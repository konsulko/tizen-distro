DESCRIPTION = "A library for Perl-compatible regular expressions"
HOMEPAGE = "ftp://ftp.csx.cam.ac.uk/pub/software/programming/pcre/"
SECTION = "System/Libraries"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by pcre 
PROVIDES += "pcre"
RPROVIDES_pcre += "pcre"

#PROVIDES by pcre-devel-static 
PROVIDES += "pcre-devel-static"
RPROVIDES_pcre-devel-static += "pcre-devel-static"
RPROVIDES_pcre-devel-static += "pcre-dev"

#PROVIDES by pcre-devel 
PROVIDES += "pcre-devel"
RPROVIDES_pcre-devel += "pcre-devel"
RPROVIDES_pcre-devel += "pcre-dev"

#PROVIDES by pcre-tools 
PROVIDES += "pcre-tools"
RPROVIDES_pcre-tools += "pcre-tools"

#PROVIDES by pcre-doc 
PROVIDES += "pcre-doc"
RPROVIDES_pcre-doc += "pcre-doc"

#PROVIDES by libpcreposix 
PROVIDES += "libpcreposix"
RPROVIDES_libpcreposix += "libpcreposix"

#PROVIDES by libpcre 
PROVIDES += "libpcre"
RPROVIDES_libpcre += "libpcre"
# the PROVIDES rules is ignore "pcre = 8.31"
PROVIDES += "pcre"
RPROVIDES_libpcre += "pcre"

#PROVIDES by libpcrecpp 
PROVIDES += "libpcrecpp"
RPROVIDES_libpcrecpp += "libpcrecpp"

RDEPENDS = ""
#RDEPENDS of pcre-devel-static (${PN}-devel-static)
RDEPENDS_${PN}-devel-static += "pcre-dev"

#RDEPENDS of pcre-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libpcre"
RDEPENDS_${PN}-devel += "libpcreposix"
RDEPENDS_${PN}-devel += "libpcrecpp"
RDEPENDS_${PN}-devel += "libstdc++-dev"


DEPENDS = ""
#DEPENDS of pcre 
DEPENDS += "gcc-cross"
DEPENDS += "libtool-cross"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/pcre.manifest .
 
 
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
 
 # Available JIT archs see sljit/sljitConfig.h
 autoreconf -fiv
 
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
 	    --enable-jit \
 	    --enable-static \
 	    --with-link-size=2 \
 	    --with-match-limit=10000000 \
 	    --enable-newline-is-lf \
 	    --enable-utf8 \
         --enable-unicode-properties
 make -j16
 
 
 exit 0
 export LANG=POSIX
 make test
 
 
 
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
   
 mkdir -p ${D}//usr/share/doc/packages
 mv ${D}/usr/share/doc/pcre ${D}//usr/share/doc/packages/pcre-doc
 rm -f ${D}/usr/lib/*.la
 
 
 
}

PACKAGES = ""
PACKAGES += "pcre-devel-static"
PACKAGES += "pcre-devel"
PACKAGES += "pcre-tools"
PACKAGES += "pcre-doc"
PACKAGES += "libpcreposix"
PACKAGES += "libpcre"
PACKAGES += "libpcrecpp"

pcre-devel-static_files = ""
pcre-devel-static_files += "pcre.manifest"
pcre-devel-static_files += "/usr/lib/*.a"

pcre-devel_files = ""
pcre-devel_files += "pcre.manifest"
pcre-devel_files += "/usr/bin/pcre-config"
pcre-devel_files += "/usr/include/*"
pcre-devel_files += "/usr/lib/*.so"
pcre-devel_files += "/usr/lib/pkgconfig/libpcre.pc"
pcre-devel_files += "/usr/lib/pkgconfig/libpcrecpp.pc"
pcre-devel_files += "/usr/lib/pkgconfig/libpcreposix.pc"
pcre-devel_files += "/usr/share/man/man1/pcre-config.*"
pcre-devel_files += "/usr/share/man/man3/*.gz"

pcre-tools_files = ""
pcre-tools_files += "pcre.manifest"
pcre-tools_files += "/usr/bin/pcregrep"
pcre-tools_files += "/usr/bin/pcretest"
pcre-tools_files += "/usr/share/man/man1/pcregrep.*"
pcre-tools_files += "/usr/share/man/man1/pcretest.*"

pcre-doc_files = ""
pcre-doc_files += "pcre.manifest"
pcre-doc_files += "doc/html doc/*.txt"

libpcreposix_files = ""
libpcreposix_files += "pcre.manifest"
libpcreposix_files += "/usr/lib/libpcreposix.so.*"

libpcre_files = ""
libpcre_files += "pcre.manifest"
libpcre_files += "/usr/lib/libpcre.so.*"

libpcrecpp_files = ""
libpcrecpp_files += "pcre.manifest"
libpcrecpp_files += "/usr/lib/libpcrecpp.so.*"

FILES_${PN}-devel-static = "${pcre-devel-static_files}"
FILES_${PN}-devel = "${pcre-devel_files}"
FILES_${PN}-tools = "${pcre-tools_files}"
FILES_${PN}-doc = "${pcre-doc_files}"
FILES_lib${PN}posix = "${libpcreposix_files}"
FILES_lib${PN} = "${libpcre_files}"
FILES_lib${PN}cpp = "${libpcrecpp_files}"

PKG_pcre-devel-static= "pcre-devel-static"
PKG_pcre-devel= "pcre-devel"
PKG_pcre-tools= "pcre-tools"
PKG_pcre-doc= "pcre-doc"
PKG_libpcreposix= "libpcreposix"
PKG_libpcre= "libpcre"
PKG_libpcrecpp= "libpcrecpp"

require pcre-extraconf.inc
