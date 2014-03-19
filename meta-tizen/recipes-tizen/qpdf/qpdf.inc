DESCRIPTION = "Command-line tools and library for transforming PDF files"
HOMEPAGE = "http://qpdf.sourceforge.net/"
SECTION = "System/Libraries"
LICENSE = "Artistic-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by qpdf-devel 
PROVIDES += "qpdf-devel"
RPROVIDES_qpdf-devel += "qpdf-devel"
RPROVIDES_qpdf-devel += "qpdf-dev"

#PROVIDES by qpdf 
PROVIDES += "qpdf"
RPROVIDES_qpdf += "qpdf"

#PROVIDES by qpdf-docs  
PROVIDES += "qpdf-docs "
RPROVIDES_qpdf-docs  += "qpdf-docs "

RDEPENDS = ""
#RDEPENDS of qpdf-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "pkgconfig(libpcre)"
RDEPENDS_${PN}-devel += "zlib-dev"
RDEPENDS_${PN}-devel += "qpdf"


DEPENDS = ""
#DEPENDS of qpdf 
DEPENDS += "pcre"
DEPENDS += "zlib-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/qpdf.manifest .
 
 
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
 
 
 ./autogen.sh
 
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
         --infodir=/usr/share/info --without-docdir
 
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
 rm -rf ${D}//usr/share/doc/qpdf
 rm  ${D}//usr/bin/*
 
 
}

PACKAGES = ""
PACKAGES += "qpdf-devel"
PACKAGES += "qpdf"
PACKAGES += "qpdf-docs"

qpdf-devel_files = ""
qpdf-devel_files += "qpdf.manifest"
qpdf-devel_files += "/usr/include/*"
qpdf-devel_files += "/usr/lib/libqpdf*.so"
qpdf-devel_files += "/usr/lib/pkgconfig/*.pc"

qpdf_files = ""
qpdf_files += "qpdf.manifest"
qpdf_files += "/usr/lib/libqpdf*.so.*"

qpdf-docs_files = ""
qpdf-docs_files += "/usr/share/info"
qpdf-docs_files += "/usr/share/man"

FILES_${PN}-devel = "${qpdf-devel_files}"
FILES_${PN} = "${qpdf_files}"
FILES_${PN}-docs = "${qpdf-docs_files}"

PKG_qpdf-devel= "qpdf-devel"
PKG_qpdf= "qpdf"
PKG_qpdf-docs= "qpdf-docs"

require qpdf-extraconf.inc
