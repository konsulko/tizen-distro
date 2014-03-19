DESCRIPTION = "XSL Transformation Library"
HOMEPAGE = "http://xmlsoft.org/XSLT/"
SECTION = "System/Libraries"
LICENSE = "MIT and GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libxslt 
PROVIDES += "libxslt"
RPROVIDES_libxslt += "libxslt"

#PROVIDES by libxslt-devel 
PROVIDES += "libxslt-devel"
RPROVIDES_libxslt-devel += "libxslt-devel"
RPROVIDES_libxslt-devel += "libxslt-dev"

#PROVIDES by libxslt-tools 
PROVIDES += "libxslt-tools"
RPROVIDES_libxslt-tools += "libxslt-tools"
# the PROVIDES rules is ignore "xsltproc = 1.1.26-0"
PROVIDES += "xsltproc"
RPROVIDES_libxslt-tools += "xsltproc"

RDEPENDS = ""
#RDEPENDS of libxslt-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "libxslt-tools"
RDEPENDS_${PN}-devel += "libgpg-error-dev"
RDEPENDS_${PN}-devel += "libgcrypt-dev"
RDEPENDS_${PN}-devel += "libxslt"


DEPENDS = ""
#DEPENDS of libxslt 
DEPENDS += "libxml2"
DEPENDS += "libtool-cross"
DEPENDS += "libgcrypt"
DEPENDS += "libgpg-error"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libxslt.manifest .
 
 
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
 
 autoreconf --force --install
 
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
         --infodir=/usr/share/info --disable-static --with-pic --without-python
 make -j16
 
 exit 0
 make check
 
 
 
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
 
 # Unwanted doc stuff
 rm -fr ${D}/usr/share/doc
 
 # the manual page is required
 install -ma=r '-t${D}/usr/share/man/man1' '${S}/packaging/xslt-config.1.gz'
 
 
 
}

PACKAGES = ""
PACKAGES += "libxslt-tools"
PACKAGES += "libxslt-devel"
PACKAGES += "libxslt"

libxslt-tools_files = ""
libxslt-tools_files += "libxslt.manifest"
libxslt-tools_files += "/usr/bin/xsltproc"
libxslt-tools_files += "/usr/share/man/man1/xsltproc.*"

libxslt-devel_files = ""
libxslt-devel_files += "libxslt.manifest"
libxslt-devel_files += "/usr/lib/lib*.so"
libxslt-devel_files += "/usr/lib/*.sh"
libxslt-devel_files += "/usr/lib/pkgconfig/*.pc"
libxslt-devel_files += "/usr/include/*"
libxslt-devel_files += "/usr/share/aclocal/*"
libxslt-devel_files += "/usr/bin/xslt-config"
libxslt-devel_files += "/usr/share/man/man1/xslt-config.*"
libxslt-devel_files += "/usr/share/man/man3/*"

libxslt_files = ""
libxslt_files += "libxslt.manifest"
libxslt_files += "/usr/lib/lib*.so.*"

FILES_${PN}-tools = "${libxslt-tools_files}"
FILES_${PN}-devel = "${libxslt-devel_files}"
FILES_${PN} = "${libxslt_files}"

PKG_libxslt-tools= "libxslt-tools"
PKG_libxslt-devel= "libxslt-devel"
PKG_libxslt= "libxslt"

require libxslt-extraconf.inc
