DESCRIPTION = "Library to work with PKCS#11 modules"
HOMEPAGE = "http://p11-glue.freedesktop.org/p11-kit.html"
SECTION = "Security/Crypto Libraries"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by p11-kit-tools 
PROVIDES += "p11-kit-tools"
RPROVIDES_p11-kit-tools += "p11-kit-tools"

#PROVIDES by libp11-kit 
PROVIDES += "libp11-kit"
RPROVIDES_libp11-kit += "libp11-kit"

#PROVIDES by p11-kit-devel 
PROVIDES += "p11-kit-devel"
RPROVIDES_p11-kit-devel += "p11-kit-devel"
RPROVIDES_p11-kit-devel += "p11-kit-dev"

#PROVIDES by p11-kit 
PROVIDES += "p11-kit"
RPROVIDES_p11-kit += "p11-kit"

RDEPENDS = ""
#RDEPENDS of p11-kit-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libp11-kit"


DEPENDS = ""
#DEPENDS of p11-kit 
DEPENDS += "libtasn1"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/p11-kit.manifest .
 
 
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
         --infodir=/usr/share/info --with-trust-paths=/etc/ssl/
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
 # Create pkcs11 config directory
 test ! -e ${D}/etc/pkcs11/modules
 install -d ${D}/etc/pkcs11/modules
 # Remove sample config away to doc folder. Having the sample there would conflict
 # with future versions of the library on file level. As replacement, we package
 # the file as documentation file.
 rm ${D}/etc/pkcs11/pkcs11.conf.example
 
 
}

PACKAGES = ""
PACKAGES += "p11-kit-tools"
PACKAGES += "libp11-kit"
PACKAGES += "p11-kit-devel"

p11-kit-tools_files = ""
p11-kit-tools_files += "p11-kit.manifest"
p11-kit-tools_files += "/usr/bin/p11-kit"

libp11-kit_files = ""
libp11-kit_files += "p11-kit.manifest"
libp11-kit_files += "p11-kit/pkcs11.conf.example"
libp11-kit_files += "/etc/pkcs11"
libp11-kit_files += "/etc/pkcs11/modules/"
libp11-kit_files += "/usr/lib/libp11-kit.so.*"
libp11-kit_files += "/usr/lib/p11-kit-proxy.so"
libp11-kit_files += "/usr/lib/pkcs11"
libp11-kit_files += "/usr/lib/p11-kit"
libp11-kit_files += "/usr/lib/pkcs11/p11-kit-trust.so"
libp11-kit_files += "/usr/lib/p11-kit/p11-kit-extract-trust"
libp11-kit_files += "/usr/share/p11-kit"
libp11-kit_files += "/usr/share/p11-kit/modules"
libp11-kit_files += "/usr/share/p11-kit/modules/p11-kit-trust.module"

p11-kit-devel_files = ""
p11-kit-devel_files += "p11-kit.manifest"
p11-kit-devel_files += "/usr/include/p11-kit-1/"
p11-kit-devel_files += "/usr/lib/libp11-kit.so"
p11-kit-devel_files += "/usr/lib/pkgconfig/p11-kit-1.pc"
p11-kit-devel_files += "%dir /usr/share/gtk-doc"
p11-kit-devel_files += "%dir /usr/share/gtk-doc/html"
p11-kit-devel_files += "/usr/share/gtk-doc/html/p11-kit/"

FILES_${PN}-tools = "${p11-kit-tools_files}"
FILES_lib${PN} = "${libp11-kit_files}"
FILES_${PN}-devel = "${p11-kit-devel_files}"

PKG_p11-kit-tools= "p11-kit-tools"
PKG_libp11-kit= "libp11-kit"
PKG_p11-kit-devel= "p11-kit-devel"

require p11-kit-extraconf.inc
