DESCRIPTION = "Certification service"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "SAMSUNG"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by cert-svc-devel 
PROVIDES += "cert-svc-devel"
RPROVIDES_cert-svc-devel += "cert-svc-devel"
RPROVIDES_cert-svc-devel += "cert-svc-dev"

#PROVIDES by cert-svc 
PROVIDES += "cert-svc"
RPROVIDES_cert-svc += "cert-svc"
# the PROVIDES rules is ignore "libcert-svc-vcore.so.1  "
PROVIDES += "libcert-svc-vcore.so.1"
RPROVIDES_cert-svc += "libcert-svc-vcore.so.1"

RDEPENDS = ""
#RDEPENDS of cert-svc-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "cert-svc"

#RDEPENDS of cert-svc (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"


DEPENDS = ""
#DEPENDS of cert-svc 
DEPENDS += "pkgconfig(libpcre)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(evas)"
DEPENDS += "pkgconfig(openssl)"
DEPENDS += "pkgconfig(xmlsec1)"
DEPENDS += "pkgconfig(secure-storage)"
DEPENDS += "pkgconfig(libpcrecpp)"
DEPENDS += "pkgconfig(libsoup-2.4)"
DEPENDS += "pkgconfig(dpl-efl)"
DEPENDS += "pkgconfig(dlog)"
DEPENDS += "pkgconfig(libxslt)"
DEPENDS += "pkgconfig(libxml-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/cert-svc.manifest .
 
 
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
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export FFLAGS ; 
   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=/usr \
         -DCMAKE_INSTALL_LIBDIR:PATH=/usr/lib \
         -DINCLUDE_INSTALL_DIR:PATH=/usr/include \
         -DLIB_INSTALL_DIR:PATH=/usr/lib \
         -DSYSCONF_INSTALL_DIR:PATH=/etc \
         -DSHARE_INSTALL_PREFIX:PATH=/usr/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON \
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DPREFIX=/usr \
          -DEXEC_PREFIX=/usr \
          -DBINDIR=/usr/bin \
          -DINCLUDEDIR=/usr/include \
          -DCMAKE_BUILD_TYPE="Release"
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 mkdir -p ${D}/usr/share/license
 cp LICENSE.APLv2 ${D}/usr/share/license/cert-svc
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 ln -sf /opt/etc/ssl/certs ${D}/opt/share/cert-svc/certs/ssl
 touch ${D}/opt/share/cert-svc/pkcs12/storage
 chmod 766 ${D}/opt/share/cert-svc/pkcs12/storage
 
 
}

PACKAGES = ""
PACKAGES += "cert-svc-devel"
PACKAGES += "cert-svc"

cert-svc-devel_files = ""
cert-svc-devel_files += "cert-svc.manifest"
cert-svc-devel_files += "/usr/include/*"
cert-svc-devel_files += "/usr/lib/pkgconfig/*"
cert-svc-devel_files += "/usr/lib/*.so"

cert-svc_files = ""
cert-svc_files += "cert-svc.manifest"
cert-svc_files += "/usr/lib/*.so.*"
cert-svc_files += "/usr/bin/dpkg-pki-sig"
cert-svc_files += "/opt/share/cert-svc/targetinfo"
cert-svc_files += "/usr/share/cert-svc/cert_svc_vcore_db.sql"
cert-svc_files += "/usr/share/license/cert-svc"
#Remove rpm attribut "%attr(0755,root,use_cert)"
cert-svc_files += "/usr/share/cert-svc"
#Remove rpm attribut "%attr(0755,root,use_cert)"
cert-svc_files += "/usr/share/cert-svc/ca-certs"
#Remove rpm attribut "%attr(0755,root,use_cert)"
cert-svc_files += "/usr/share/cert-svc/ca-certs/code-signing"
#Remove rpm attribut "%attr(0755,root,use_cert)"
cert-svc_files += "/usr/share/cert-svc/ca-certs/code-signing/native"
#Remove rpm attribut "%attr(0755,root,use_cert)"
cert-svc_files += "/usr/share/cert-svc/ca-certs/code-signing/wac"
#Remove rpm attribut "%attr(0775,root,use_cert)"
cert-svc_files += "/opt/share/cert-svc"
#Remove rpm attribut "%attr(0775,root,use_cert)"
cert-svc_files += "/opt/share/cert-svc/certs"
#Remove rpm attribut "%attr(0775,root,use_cert)"
cert-svc_files += "/opt/share/cert-svc/certs/code-signing"
#Remove rpm attribut "%attr(0775,root,use_cert)"
cert-svc_files += "/opt/share/cert-svc/certs/code-signing/wac"
#Remove rpm attribut "%attr(0775,root,use_cert)"
cert-svc_files += "/opt/share/cert-svc/certs/code-signing/tizen"
#Remove rpm attribut "%attr(0775,root,use_cert)"
cert-svc_files += "/opt/share/cert-svc/certs/sim"
#Remove rpm attribut "%attr(0775,root,use_cert)"
cert-svc_files += "/opt/share/cert-svc/certs/sim/operator"
#Remove rpm attribut "%attr(0775,root,use_cert)"
cert-svc_files += "/opt/share/cert-svc/certs/sim/thirdparty"
#Remove rpm attribut "%attr(0777,root,use_cert)"
cert-svc_files += "/opt/share/cert-svc/certs/user"
#Remove rpm attribut "%attr(0777,root,use_cert)"
cert-svc_files += "/opt/share/cert-svc/certs/trusteduser"
#Remove rpm attribut "%attr(0775,root,use_cert)"
cert-svc_files += "/opt/share/cert-svc/certs/mdm"
#Remove rpm attribut "%attr(0775,root,use_cert)"
cert-svc_files += "/opt/share/cert-svc/certs/mdm/security"
#Remove rpm attribut "%attr(0775,root,use_cert)"
cert-svc_files += "/opt/share/cert-svc/certs/mdm/security/cert"
#Remove rpm attribut "%attr(0777,root,use_cert)"
cert-svc_files += "/opt/share/cert-svc/pkcs12"
cert-svc_files += "/opt/share/cert-svc/certs/ssl"
cert-svc_files += "/opt/share/cert-svc/pkcs12/storage"

FILES_${PN}-devel = "${cert-svc-devel_files}"
FILES_${PN} = "${cert-svc_files}"

PKG_cert-svc-devel= "cert-svc-devel"
PKG_cert-svc= "cert-svc"

require cert-svc-extraconf.inc
