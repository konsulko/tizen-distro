DESCRIPTION = "Common SGML catalog and DTD files"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Applications/Text"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by sgml-common 
PROVIDES += "sgml-common"
RPROVIDES_sgml-common += "sgml-common"

#PROVIDES by xml-common 
PROVIDES += "xml-common"
RPROVIDES_xml-common += "xml-common"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of sgml-common 
DEPENDS += "libxml2"
DEPENDS += "config(docbook_4)"
DEPENDS += "automake-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cat ${S}/packaging/sgml-common-umask.patch | patch -s  -p1 --fuzz=2
 #patch0 -p1
 cat ${S}/packaging/sgml-common-xmldir.patch | patch -s  -p1 --fuzz=2
 #patch1 -p1
 
 # replace bogus links with files
 for file in COPYING INSTALL install-sh missing mkinstalldirs; do 
    rm $file
    cp -p /usr/share/automake-1.12/$file .
 done
 
 
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
         --target=noarch-tizen-linux \
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
         --infodir=/usr/share/info
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR="${D}" htmldir='/usr/share/doc' INSTALL='install -p'
 mkdir ${D}/etc/xml
 mkdir -p ${D}/usr/share/sgml/docbook
 # Create an empty XML catalog.
 XMLCATALOG=${D}/etc/xml/catalog
 /usr/bin/xmlcatalog --noout --create $XMLCATALOG
 # Now put the common DocBook entries in it
 /usr/bin/xmlcatalog --noout --add "delegatePublic" \
     "-//OASIS//ENTITIES DocBook XML" \
     "file:///usr/share/sgml/docbook/xmlcatalog" $XMLCATALOG
 /usr/bin/xmlcatalog --noout --add "delegatePublic" \
     "-//OASIS//DTD DocBook XML" \
     "file:///usr/share/sgml/docbook/xmlcatalog" $XMLCATALOG
 /usr/bin/xmlcatalog --noout --add "delegatePublic" \
     "ISO 8879:1986" \
     "file:///usr/share/sgml/docbook/xmlcatalog" $XMLCATALOG
 /usr/bin/xmlcatalog --noout --add "delegateSystem" \
     "http://www.oasis-open.org/docbook/" \
     "file:///usr/share/sgml/docbook/xmlcatalog" $XMLCATALOG
 /usr/bin/xmlcatalog --noout --add "delegateURI" \
     "http://www.oasis-open.org/docbook/" \
     "file:///usr/share/sgml/docbook/xmlcatalog" $XMLCATALOG
 # Also create the common DocBook catalog
 /usr/bin/xmlcatalog --noout --create \
     ${D}/usr/share/sgml/docbook/xmlcatalog
 
 rm -f ${D}/usr/share/sgml/xml.dcl
 
 install -p -m0644 ${S}/packaging/xml.dcl ${S}/packaging/xml.soc ${S}/packaging/html.dcl ${S}/packaging/html.soc \
     ${D}/usr/share/sgml
 
 rm -rf ${D}/usr/share/xml/*
 rm -f ${D}/usr/share/doc/*.html
 
 
 
}

PACKAGES = ""
PACKAGES += "sgml-common"
PACKAGES += "xml-common"

sgml-common_files = ""
sgml-common_files += "/etc/sgml"
sgml-common_files += "/etc/sgml/sgml.conf"
sgml-common_files += "/usr/share/sgml"
sgml-common_files += "/usr/share/sgml/sgml-iso-entities-8879.1986"
sgml-common_files += "/usr/share/sgml/sgml-iso-entities-8879.1986/*"
sgml-common_files += "/usr/share/sgml/xml.dcl"
sgml-common_files += "/usr/share/sgml/xml.soc"
sgml-common_files += "/usr/share/sgml/html.dcl"
sgml-common_files += "/usr/share/sgml/html.soc"
sgml-common_files += "/usr/bin/sgmlwhich"
sgml-common_files += "/usr/bin/install-catalog"
sgml-common_files += "/usr/share/man/man8/install-catalog.8*"

xml-common_files = ""
xml-common_files += "/etc/xml"
xml-common_files += "%verify(not md5 size mtime) /etc/xml/catalog"
xml-common_files += "/usr/share/sgml"
xml-common_files += "/usr/share/sgml/docbook"
xml-common_files += "/usr/share/xml"

FILES_${PN} = "${sgml-common_files}"
FILES_xml-common = "${xml-common_files}"

PKG_sgml-common= "sgml-common"
PKG_xml-common= "xml-common"

require sgml-common-extraconf.inc
