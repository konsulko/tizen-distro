DESCRIPTION = "Library providing support for "XML Signature" and "XML Encryption" standards"
HOMEPAGE = "http://www.aleksey.com/xmlsec/index.html"
SECTION = "System/Libraries"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by xmlsec1 
PROVIDES += "xmlsec1"
RPROVIDES_xmlsec1 += "xmlsec1"

#PROVIDES by xmlsec1-gcrypt 
PROVIDES += "xmlsec1-gcrypt"
RPROVIDES_xmlsec1-gcrypt += "xmlsec1-gcrypt"

#PROVIDES by xmlsec1-openssl 
PROVIDES += "xmlsec1-openssl"
RPROVIDES_xmlsec1-openssl += "xmlsec1-openssl"

#PROVIDES by xmlsec1-devel 
PROVIDES += "xmlsec1-devel"
RPROVIDES_xmlsec1-devel += "xmlsec1-devel"
RPROVIDES_xmlsec1-devel += "xmlsec1-dev"

RDEPENDS = ""
#RDEPENDS of xmlsec1-gcrypt (${PN}-gcrypt)
RDEPENDS_${PN}-gcrypt += "xmlsec1"

#RDEPENDS of xmlsec1-openssl (${PN}-openssl)
RDEPENDS_${PN}-openssl += "xmlsec1"

#RDEPENDS of xmlsec1-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "xmlsec1"


DEPENDS = ""
#DEPENDS of xmlsec1 
DEPENDS += "openssl"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "pkgconfig(libxslt)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/xmlsec1.manifest .
 
 
 
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
     --enable-dynamic --disable-crypto-dl --disable-apps-crypto-dl --without-gnutls
 
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
 
 
 
   rm -rf ${D}/usr/share/info 
   rm -rf ${D}/usr/share/doc/packages 
   rm -rf ${D}/usr/share/doc/xmlsec1 
   rm -rf ${D}/usr/share/doc/xmlsec1-1.2.19 
   rm -rf ${D}/usr/share/gtk-doc 
   rm -rf ${D}/usr/share/doc 
   rm -rf ${D}/usr/share/man 
   find ${D} -regex ".*/man/man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/../man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/man./.*.[0-9]pm" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "xmlsec1"
PACKAGES += "xmlsec1-gcrypt"
PACKAGES += "xmlsec1-openssl"
PACKAGES += "xmlsec1-devel"

xmlsec1_files = ""
xmlsec1_files += "xmlsec1.manifest"
xmlsec1_files += "Copyright"
xmlsec1_files += "/usr/lib/libxmlsec1.so.*"
xmlsec1_files += "/usr/bin/xmlsec1"

xmlsec1-gcrypt_files = ""
xmlsec1-gcrypt_files += "xmlsec1.manifest"
xmlsec1-gcrypt_files += "/usr/lib/libxmlsec1-gcrypt.so.*"

xmlsec1-openssl_files = ""
xmlsec1-openssl_files += "xmlsec1.manifest"
xmlsec1-openssl_files += "/usr/lib/libxmlsec1-openssl.so.*"

xmlsec1-devel_files = ""
xmlsec1-devel_files += "xmlsec1.manifest"
xmlsec1-devel_files += "Copyright"
xmlsec1-devel_files += "/usr/include/xmlsec1"
xmlsec1-devel_files += "/usr/bin/xmlsec1-config"
xmlsec1-devel_files += "/usr/lib/lib*.so"
xmlsec1-devel_files += "/usr/lib/pkgconfig/*"
xmlsec1-devel_files += "/usr/lib/xmlsec1Conf.sh"
xmlsec1-devel_files += "/usr/share/aclocal/xmlsec1.m4"

FILES_${PN} = "${xmlsec1_files}"
FILES_${PN}-gcrypt = "${xmlsec1-gcrypt_files}"
FILES_${PN}-openssl = "${xmlsec1-openssl_files}"
FILES_${PN}-devel = "${xmlsec1-devel_files}"

PKG_xmlsec1= "xmlsec1"
PKG_xmlsec1-gcrypt= "xmlsec1-gcrypt"
PKG_xmlsec1-openssl= "xmlsec1-openssl"
PKG_xmlsec1-devel= "xmlsec1-devel"

require xmlsec1-extraconf.inc
