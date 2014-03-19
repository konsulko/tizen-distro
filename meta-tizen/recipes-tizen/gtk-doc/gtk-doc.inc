DESCRIPTION = "GTK+ DocBook Documentation Generator"
HOMEPAGE = "http://www.gtk.org/gtk-doc/"
SECTION = "Productivity/Publishing/SGML"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gtk-doc 
PROVIDES += "gtk-doc"
RPROVIDES_gtk-doc += "gtk-doc"

RDEPENDS = ""
#RDEPENDS of gtk-doc (${PN})
RDEPENDS_${PN} += "docbook-xsl-stylesheets"
RDEPENDS_${PN} += "docbook_4"
RDEPENDS_${PN} += "libxslt"
RDEPENDS_${PN} += "libxslt-tools"
RDEPENDS_${PN} += "libxml2-tools"


DEPENDS = ""
#DEPENDS of gtk-doc 
DEPENDS += "sgml-skel"
DEPENDS += "xsltproc"
inherit pythonnative
DEPENDS += "pkgconfig-native"
DEPENDS += "docbook-xsl-stylesheets"
DEPENDS += "libxslt"
DEPENDS += "libxml2-tools"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
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
         --infodir=/usr/share/info --disable-scrollkeeper
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
 mkdir -p ${D}/usr/share/gtk-doc/html
 mv -v doc/README doc/doc.README
 
 
}

PACKAGES = ""
PACKAGES += "gtk-doc"

gtk-doc_files = ""
gtk-doc_files += "AUTHORS COPYING COPYING-DOCS ChangeLog NEWS README TODO doc/*"
gtk-doc_files += "/usr/bin/gtkdoc-*"
gtk-doc_files += "/usr/bin/gtkdocize"
gtk-doc_files += "/usr/share/aclocal"
gtk-doc_files += "/usr/share/aclocal/gtk-doc.m4"
gtk-doc_files += "/usr/share/gtk-doc/"
gtk-doc_files += "/usr/share/pkgconfig/gtk-doc.pc"
gtk-doc_files += "/usr/share/sgml/gtk-doc/"

FILES_${PN} = "${gtk-doc_files}"

PKG_gtk-doc= "gtk-doc"

require gtk-doc-extraconf.inc
