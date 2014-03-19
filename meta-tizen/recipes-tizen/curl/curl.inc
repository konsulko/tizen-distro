DESCRIPTION = "A utility for getting files from remote servers (FTP, HTTP, and others)"
HOMEPAGE = "http://curl.haxx.se/"
SECTION = "Base/Utilities"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libcurl 
PROVIDES += "libcurl"
RPROVIDES_libcurl += "libcurl"

#PROVIDES by curl 
PROVIDES += "curl"
RPROVIDES_curl += "curl"
# the PROVIDES rules is ignore "webclient  "
PROVIDES += "webclient"
RPROVIDES_curl += "webclient"

#PROVIDES by libcurl-devel 
PROVIDES += "libcurl-devel"
RPROVIDES_libcurl-devel += "libcurl-devel"
RPROVIDES_libcurl-devel += "libcurl-dev"
# the PROVIDES rules is ignore "curl-devel = 7.32.0"
PROVIDES += "curl-devel"
RPROVIDES_libcurl-devel += "curl-devel"
RPROVIDES_libcurl-devel += "curl-dev"

RDEPENDS = ""
#RDEPENDS of libcurl-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "libcurl"
RDEPENDS_lib${PN}-devel += "libidn-dev"


DEPENDS = ""
#DEPENDS of curl 
DEPENDS += "pkgconfig(libidn)"
DEPENDS += "pkgconfig(nss)"
DEPENDS += "c-ares"
DEPENDS += "zlib-devel"
DEPENDS += "pkgconfig(openssl)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/curl.manifest .
 
 
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
 
 export CPPFLAGS="$(pkg-config --cflags nss) -DHAVE_PK11_CREATEGENERICOBJECT"
 
 
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
         --infodir=/usr/share/info --without-nss \
         --without-gnutls \
         --with-openssl \
         --disable-ipv6 \
         --with-ca-path=/etc/ssl/certs \
         --with-libidn \
         --with-lber-lib=lber \
         --enable-manual \
         --enable-versioned-symbols \
         --enable-ares \
         --enable-debug \
         --enable-curldebug \
         --disable-static
 
 sed -i -e 's,-L/usr/lib ,,g;s,-L/usr/lib64 ,,g;s,-L/usr/lib$,,g;s,-L/usr/lib64$,,g' \
 Makefile libcurl.pc
 
 # Remove bogus rpath
 sed -i \
 -e 's|^hardcode_libdir_flag_spec=.*|hardcode_libdir_flag_spec=""|g' \
 -e 's|^runpath_var=LD_RUN_PATH|runpath_var=DIE_RPATH_DIE|g' libtool
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make DESTDIR=${D} INSTALL="install -p" install
 
 rm -f ${D}/usr/lib/libcurl.la
 install -d ${D}//usr/share/aclocal
 install -m 644 docs/libcurl/libcurl.m4 ${D}//usr/share/aclocal
 
 # don't need curl's copy of the certs; use openssl's
 find ${D} -name ca-bundle.crt -exec rm -f '{}' \;
 rm -rf ${D}/usr/share/man
 
 
}

PACKAGES = ""
PACKAGES += "libcurl"
PACKAGES += "curl"
PACKAGES += "libcurl-devel"

libcurl_files = ""
libcurl_files += "curl.manifest"
libcurl_files += "/usr/lib/libcurl.so.*"

curl_files = ""
curl_files += "curl.manifest"
curl_files += "/usr/bin/curl"

libcurl-devel_files = ""
libcurl-devel_files += "curl.manifest"
libcurl-devel_files += "/usr/bin/curl-config*"
libcurl-devel_files += "/usr/include/curl"
libcurl-devel_files += "/usr/lib/*.so"
libcurl-devel_files += "/usr/lib/pkgconfig/*.pc"
libcurl-devel_files += "/usr/share/aclocal/libcurl.m4"

FILES_lib${PN} = "${libcurl_files}"
FILES_${PN} = "${curl_files}"
FILES_lib${PN}-devel = "${libcurl-devel_files}"

PKG_libcurl= "libcurl"
PKG_curl= "curl"
PKG_libcurl-devel= "libcurl-devel"

require curl-extraconf.inc
