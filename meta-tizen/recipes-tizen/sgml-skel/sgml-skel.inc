DESCRIPTION = "Helper Scripts for the SGML System"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Productivity/Publishing/SGML"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by sgml-skel 
PROVIDES += "sgml-skel"
RPROVIDES_sgml-skel += "sgml-skel"

RDEPENDS = ""
#RDEPENDS of sgml-skel (${PN})
RDEPENDS_${PN} += "libxml2-tools"
RDEPENDS_${PN} += "/usr/bin/mv"
RDEPENDS_${PN} += "/usr/bin/awk"
RDEPENDS_${PN} += "/usr/bin/chmod"


DEPENDS = ""
#DEPENDS of sgml-skel 
DEPENDS += "libxml2"
DEPENDS += "automake-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/sgml-skel.manifest .
 cp ${S}/packaging/install-catalog.in .
 cp ${S}/packaging/edit-xml-catalog.sh .
 
 
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
 
 # CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables"
 autoreconf -i -f
 ./configure --prefix=/usr --infodir=/usr/share/info \
   --datadir=/usr/share --mandir=/usr/share/man \
   --build $RPM_ARCH-tizen-linux
 
 
 
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
 install -m755 install-catalog.in ${D}/usr/bin/install-catalog
 install -m755 edit-xml-catalog.sh \
   ${D}/usr/bin/edit-xml-catalog
 ln -sf sgml2xmlcat.sh ${D}/usr/bin/sgmlcat2x.sh
 ln -sf install-catalog ${D}/usr/bin/install-catalog.sh
 install -d -m755 ${D}/usr/share/sgml
 install -d -m755 ${D}/etc/{sgml,xml}
 install -d -m755 ${D}/var/lib/sgml
 touch ${D}/etc/sgml/catalog
 xmlcatalog --noout --create ${D}/etc/xml/tizen-catalog.xml
 xmlcatalog --noout --create ${D}/etc/xml/catalog
 xmlcatalog --noout --add  "nextCatalog" "tizen-catalog.xml" "tizen-catalog.xml" \
   ${D}/etc/xml/catalog
 
 
}

PACKAGES = ""
PACKAGES += "sgml-skel"

sgml-skel_files = ""
sgml-skel_files += "sgml-skel.manifest"
sgml-skel_files += "AUTHORS COPYING NEWS README*"
sgml-skel_files += "%verify(not md5 size mtime) /etc/xml/catalog"
sgml-skel_files += "/etc/sgml"
sgml-skel_files += "/etc/xml"
sgml-skel_files += "/usr/bin/*"
sgml-skel_files += "/var/lib/sgml"

FILES_${PN} = "${sgml-skel_files}"

PKG_sgml-skel= "sgml-skel"

require sgml-skel-extraconf.inc
