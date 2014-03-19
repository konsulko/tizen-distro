DESCRIPTION = "XML Character Entities"
HOMEPAGE = "http://www.oasis-open.org/committees/docbook/xmlcharent/"
SECTION = "Productivity/Publishing/XML"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by xmlcharent 
PROVIDES += "xmlcharent"
RPROVIDES_xmlcharent += "xmlcharent"

RDEPENDS = ""
#RDEPENDS of xmlcharent (${PN})
RDEPENDS_${PN} += "sgml-skel"
RDEPENDS_${PN} += "grep"
RDEPENDS_${PN} += "/usr/bin/sgml-register-catalog"
RDEPENDS_${PN} += "libxml2"
RDEPENDS_${PN} += "gawk"
RDEPENDS_${PN} += "/usr/bin/xmlcatalog"
RDEPENDS_${PN} += "sed"
RDEPENDS_${PN} += "/usr/bin/edit-xml-catalog"


DEPENDS = ""
#DEPENDS of xmlcharent 
DEPENDS += "sgml-skel"
DEPENDS += "unzip"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/xmlcharent.manifest .
 sed 's|@VERSION@|0.3|
 s|@DIR@|/usr/share/xml/entities/xmlcharent/0.3|' ${S}/packaging/catalog.xml >catalog.xml
 sed 's|@VERSION@|0.3|
 s|@DIR@|/usr/share/xml/entities/xmlcharent/0.3|' ${S}/packaging/CATALOG.xmlcharent >CATALOG.xmlcharent
 ##setup -q -n xmlcharent
 
 
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
 
 # # lynx -width=300 -dump  entities-2002-03-19.html \
 # #   | grep '\(Public\|System\) identifier' \
 # #   | awk -F 'entifier: ' '
 # # / System i/ {printf "\"%s\"\n", gensub(/.*\//,"%{sgml_dir_iso}/", g, $2)}
 # # / Public i/ {printf "PUBLIC \"-//%s\" ", $2}' > CATALOG.xmlcharent
 # {
 #   for f in iso-*.ent; do
 #     {
 #       grep ' *ISO 8879:1986' $f | sed 's:^ \+::' \
 #         | awk '{printf "PUBLIC \"-//%s\"", $0}';
 #       echo " \"%{sgml_dir_iso}/$f\"";
 #     }
 #   done
 # } > CATALOG.xmlcharent
 # sed 's:/usr/share/xml/entities/xmlcharent/0.3/::' CATALOG.xmlcharent > sgml.catalog
 # Prep XML catalog fragment
 xmlcatbin=/usr/bin/xmlcatalog
 # build root catalog fragment
 rm -f for-catalog-xmlcharent-0.3.xml.tmp
 $xmlcatbin --noout --create for-catalog-xmlcharent-0.3.xml.tmp
 CATALOG=/usr/share/xml/entities/xmlcharent/0.3/catalog.xml
 $xmlcatbin --noout --add "delegatePublic" "ISO 8879:1986//ENTITIES" \
     "file://$CATALOG" for-catalog-xmlcharent-0.3.xml.tmp
 # Create tag
 sed '/<catalog/a\
   <group id="xmlcharent-0.3">
 /<\/catalog/i\
   </group>' \
   for-catalog-xmlcharent-0.3.xml.tmp > for-catalog-xmlcharent-0.3.xml
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 install -d -m755 ${D}{/usr/share/xml/entities/xmlcharent/0.3,/usr/share/sgml,/var/lib/sgml}
 install -m644 catalog.xml *.ent ${D}/usr/share/xml/entities/xmlcharent/0.3
 install -m644 CATALOG.xmlcharent ${D}/var/lib/sgml
 pushd ${D}/usr/share/sgml
 ln -sf ../../../var/lib/sgml/CATALOG.* .
 popd
 pushd ${D}/usr/share/xml/entities/xmlcharent/0.3
 for f in *.ent; do
   ln -sf "$f" "${f/-}"
 done
 popd
 # parse-sgml-catalog.sh CATALOG.xmlcharent > CATALOG.norm
 # sgml2xmlcat.sh -i CATALOG.norm \
 #   -l -s '${D}/usr/share/sgml' -p xmlcharent
 #
 mkdir -p ${D}/etc/xml
 install -m644 for-catalog-xmlcharent-0.3.xml ${D}/etc/xml
 #
 
 
}

PACKAGES = ""
PACKAGES += "xmlcharent"

xmlcharent_files = ""
xmlcharent_files += "xmlcharent.manifest"
xmlcharent_files += "/usr/share/xml/entities/xmlcharent/0.3"
xmlcharent_files += "/etc/xml/for-catalog-xmlcharent-0.3.xml"
xmlcharent_files += "/var/lib/sgml/CATALOG.*"
xmlcharent_files += "/usr/share/sgml/CATALOG.*"
xmlcharent_files += "/usr/share/xml/entities"
xmlcharent_files += "/usr/share/xml/entities/xmlcharent"

FILES_${PN} = "${xmlcharent_files}"

PKG_xmlcharent= "xmlcharent"

require xmlcharent-extraconf.inc
