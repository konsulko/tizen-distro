DESCRIPTION = "DocBook DTD Version 4.x"
HOMEPAGE = "http://www.oasis-open.org/docbook/"
SECTION = "Productivity/Publishing/DocBook"
LICENSE = "BSD-3-Clause  MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by docbook_4 
PROVIDES += "docbook_4"
RPROVIDES_docbook_4 += "docbook_4"
# the PROVIDES rules is ignore "docbk_4  "
PROVIDES += "docbk_4"
RPROVIDES_docbook_4 += "docbk_4"
# the PROVIDES rules is ignore "docbook  "
PROVIDES += "docbook"
RPROVIDES_docbook_4 += "docbook"
# the PROVIDES rules is ignore "docbook-dtd  "
PROVIDES += "docbook-dtd"
RPROVIDES_docbook_4 += "docbook-dtd"
# the PROVIDES rules is ignore "docbook-dtds  "
PROVIDES += "docbook-dtds"
RPROVIDES_docbook_4 += "docbook-dtds"

RDEPENDS = ""
#RDEPENDS of docbook_4 (docbook_4)
RDEPENDS_docbook_4 += "sgml-skel"
RDEPENDS_docbook_4 += "grep"
RDEPENDS_docbook_4 += "/usr/bin/sgml-register-catalog"
RDEPENDS_docbook_4 += "libxml2"
RDEPENDS_docbook_4 += "/usr/bin/xmlcatalog"
RDEPENDS_docbook_4 += "sed"
RDEPENDS_docbook_4 += "awk"
RDEPENDS_docbook_4 += "iso_ent"


DEPENDS = ""
#DEPENDS of docbook_4 
DEPENDS += "unzip"
DEPENDS += "sgml-skel"
DEPENDS += "fdupes-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -n docbook_4 -c -T
 cp ${S}/packaging/docbook_4.manifest .
 install -d -m755 dtd/4.{1,2,3,4,5} 4.{1,2,3,4,5}xml
 echo "**** ${S}/packaging/docbk41.zip"
 pushd dtd/4.1
   unzip -q -a ${S}/packaging/docbk41.zip
 popd
 pushd 4.1xml
   unzip -q -a ${S}/packaging/docbkx412.zip
 popd
 pushd dtd/4.2
   unzip -q -a ${S}/packaging/docbook-4.2.zip
 popd
 pushd 4.2xml
   unzip -q -a ${S}/packaging/docbook-xml-4.2.zip
 popd
 pushd dtd/4.3
   unzip -q -a ${S}/packaging/docbook-4.3.zip
 popd
 pushd 4.3xml
   unzip -q -a ${S}/packaging/docbook-xml-4.3.zip
 popd
 pushd dtd/4.4
   unzip -q -a ${S}/packaging/docbook-4.4.zip
 cat ${S}/packaging/docbook.4.4.dcl.diff | patch -s  -p 0 --fuzz=2
 #patch3 -p 0
 popd
 pushd 4.4xml
   unzip -q -a ${S}/packaging/docbook-xml-4.4.zip
 popd
 pushd dtd/4.5
   unzip -q -a ${S}/packaging/docbook-4.5.zip
 popd
 pushd 4.5xml
   unzip -q -a ${S}/packaging/docbook-xml-4.5.zip
 popd
 cat ${S}/packaging/docbook-4-3-cat.diff | patch -s  -p 1 -P 1 -p 0 --fuzz=2
 #patch -p 1 -P 1 -p 0
 cat ${S}/packaging/docbook-4-3-xml-cat.diff | patch -s  -p 1 --fuzz=2
 #patch2 -p 1
 # CATALOG.* files
 cp ${S}/packaging/CATALOG.docbook_4 ${S}/packaging/CATALOG.db41xml ${S}/packaging/CATALOG.db42xml ${S}/packaging/CATALOG.db43xml ${S}/packaging/CATALOG.db44xml ${S}/packaging/CATALOG.db45xml .
 chmod -R a+rX,g-w,o-w .
 find . -type f | xargs chmod a-x
 
 
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
 
 CATALOG=docbook_41.xml
 # # build root catalog fragment
 xmlcatbin=/usr/bin/xmlcatalog
 $xmlcatbin --create --noout $CATALOG
 docbookdir=/usr/share/xml/docbook/schema/dtd/4.1
 $xmlcatbin --noout --add "public" \
     "-//OASIS//ELEMENTS DocBook XML Information Pool V4.1.2//EN" \
     "file://$docbookdir/dbpoolx.mod" $CATALOG
 $xmlcatbin --noout --add "public" \
     "-//OASIS//DTD DocBook XML V4.1.2//EN" \
     "file://$docbookdir/docbookx.dtd" $CATALOG
 $xmlcatbin --noout --add "public" \
     "-//OASIS//ENTITIES DocBook XML Character Entities V4.1.2//EN" \
     "file://$docbookdir/dbcentx.mod" $CATALOG
 $xmlcatbin --noout --add "public" \
     "-//OASIS//ENTITIES DocBook XML Notations V4.1.2//EN" \
     "file://$docbookdir/dbnotnx.mod" $CATALOG
 $xmlcatbin --noout --add "public" \
     "-//OASIS//ENTITIES DocBook XML Additional General Entities V4.1.2//EN" \
     "file://$docbookdir/dbgenent.mod" $CATALOG
 $xmlcatbin --noout --add "public" \
     "-//OASIS//ELEMENTS DocBook XML Document Hierarchy V4.1.2//EN" \
     "file://$docbookdir/dbhierx.mod" $CATALOG
 $xmlcatbin --noout --add "public" \
     "-//OASIS//DTD XML Exchange Table Model 19990315//EN" \
     "file://$docbookdir/soextblx.dtd" $CATALOG
 $xmlcatbin --noout --add "public" \
     "-//OASIS//DTD DocBook XML CALS Table Model V4.1.2//EN" \
     "file://$docbookdir/calstblx.dtd" $CATALOG
 $xmlcatbin --noout --add "rewriteSystem" \
     "http://www.oasis-open.org/docbook/xml/4.1.2" \
     "file://$docbookdir" $CATALOG
 $xmlcatbin --noout --add "rewriteURI" \
     "http://www.oasis-open.org/docbook/xml/4.1.2" \
     "file://$docbookdir" $CATALOG
 # === iso
 isodir=$docbookdir/ent
 $xmlcatbin --noout --add "public" \
     "ISO 8879:1986//ENTITIES Publishing//EN//XML" \
     "file://$isodir/iso-pub.ent" $CATALOG
 $xmlcatbin --noout --add "public" \
     "ISO 8879:1986//ENTITIES Greek Letters//EN//XML" \
     "file://$isodir/iso-grk1.ent" $CATALOG
 $xmlcatbin --noout --add "public" \
     "ISO 8879:1986//ENTITIES Box and Line Drawing//EN//XML" \
     "file://$isodir/iso-box.ent" $CATALOG
 $xmlcatbin --noout --add "public" \
     "ISO 8879:1986//ENTITIES Greek Symbols//EN//XML" \
     "file://$isodir/iso-grk3.ent" $CATALOG
 $xmlcatbin --noout --add "public" \
     "ISO 8879:1986//ENTITIES Added Math Symbols: Negated Relations//EN//XML" \
     "file://$isodir/iso-amsn.ent" $CATALOG
 $xmlcatbin --noout --add "public" \
     "ISO 8879:1986//ENTITIES Numeric and Special Graphic//EN//XML" \
     "file://$isodir/iso-num.ent" $CATALOG
 $xmlcatbin --noout --add "public" \
     "ISO 8879:1986//ENTITIES Alternative Greek Symbols//EN//XML" \
     "file://$isodir/iso-grk4.ent" $CATALOG
 $xmlcatbin --noout --add "public" \
     "ISO 8879:1986//ENTITIES Diacritical Marks//EN//XML" \
     "file://$isodir/iso-dia.ent" $CATALOG
 $xmlcatbin --noout --add "public" \
     "ISO 8879:1986//ENTITIES Monotoniko Greek//EN//XML" \
     "file://$isodir/iso-grk2.ent" $CATALOG
 $xmlcatbin --noout --add "public" \
     "ISO 8879:1986//ENTITIES Added Math Symbols: Arrow Relations//EN//XML" \
     "file://$isodir/iso-amsa.ent" $CATALOG
 $xmlcatbin --noout --add "public" \
     "ISO 8879:1986//ENTITIES Added Math Symbols: Ordinary//EN//XML" \
     "file://$isodir/iso-amso.ent" $CATALOG
 $xmlcatbin --noout --add "public" \
     "ISO 8879:1986//ENTITIES Russian Cyrillic//EN//XML" \
     "file://$isodir/iso-cyr1.ent" $CATALOG
 $xmlcatbin --noout --add "public" \
     "ISO 8879:1986//ENTITIES General Technical//EN//XML" \
     "file://$isodir/iso-tech.ent" $CATALOG
 $xmlcatbin --noout --add "public" \
     "ISO 8879:1986//ENTITIES Added Math Symbols: Delimiters//EN//XML" \
     "file://$isodir/iso-amsc.ent" $CATALOG
 $xmlcatbin --noout --add "public" \
     "ISO 8879:1986//ENTITIES Added Latin 1//EN//XML" \
     "file://$isodir/iso-lat1.ent" $CATALOG
 $xmlcatbin --noout --add "public" \
     "ISO 8879:1986//ENTITIES Added Math Symbols: Binary Operators//EN//XML" \
     "file://$isodir/iso-amsb.ent" $CATALOG
 $xmlcatbin --noout --add "public" \
     "ISO 8879:1986//ENTITIES Added Latin 2//EN//XML" \
     "file://$isodir/iso-lat2.ent" $CATALOG
 $xmlcatbin --noout --add "public" \
     "ISO 8879:1986//ENTITIES Added Math Symbols: Relations//EN//XML" \
     "file://$isodir/iso-amsr.ent" $CATALOG
 $xmlcatbin --noout --add "public" \
     "ISO 8879:1986//ENTITIES Non-Russian Cyrillic//EN//XML" \
     "file://$isodir/iso-cyr2.ent" $CATALOG
 # ====
 CATALOG=etc/xml/$CATALOG
 rm -f for-catalog-docbook_4-4.5.xml.tmp
 $xmlcatbin --noout --create for-catalog-docbook_4-4.5.xml.tmp
 for v in 4.2 4.3 4.4 4.5; do
   cat42=/usr/share/xml/docbook/schema/dtd/$v/catalog.xml
   for s in \
     "-//OASIS//DTD DocBook XML V${v}//EN" \
     "-//OASIS//DTD DocBook CALS Table Model V${v}//EN" \
     "-//OASIS//DTD XML Exchange Table Model 19990315//EN" \
     "-//OASIS//ELEMENTS DocBook Information Pool V${v}//EN" \
     "-//OASIS//ELEMENTS DocBook Document Hierarchy V${v}//EN" \
     "-//OASIS//ENTITIES DocBook Additional General Entities V${v}//EN" \
     "-//OASIS//ENTITIES DocBook Notations V${v}//EN" \
     "-//OASIS//ENTITIES DocBook Character Entities V${v}//EN"
    do
    $xmlcatbin --noout --add "delegatePublic" "$s" \
      "file://$cat42" for-catalog-docbook_4-4.5.xml.tmp
   done
   case $v in
     4.[345])
       $xmlcatbin --noout --add "delegatePublic" \
          "-//OASIS//ELEMENTS DocBook XML HTML Tables V${v}//EN" \
          "file://$cat42" for-catalog-docbook_4-4.5.xml.tmp
       ;;
     *)
       true
   esac
   $xmlcatbin --noout --add "delegateSystem" \
     "http://www.oasis-open.org/docbook/xml/${v}" \
     "file://$cat42" for-catalog-docbook_4-4.5.xml.tmp
   $xmlcatbin --noout --add "delegateURI" \
     "http://www.oasis-open.org/docbook/xml/${v}" \
     "file://$cat42" for-catalog-docbook_4-4.5.xml.tmp
   $xmlcatbin --noout --add "rewriteSystem" \
     "http://www.oasis-open.org/docbook/xml/${v}" \
     "file:///usr/share/xml/docbook/schema/dtd/${v}" for-catalog-docbook_4-4.5.xml.tmp
   $xmlcatbin --noout --add "delegatePublic" \
     "ISO 8879:1986" \
     "file:///$CATALOG" for-catalog-docbook_4-4.5.xml.tmp
 done
 # 41xml
 for s in \
   "-//OASIS//DTD DocBook XML V4.1" \
   "-//OASIS//ELEMENTS DocBook Information Pool V4.1" \
   "-//OASIS//ELEMENTS DocBook Document Hierarchy V4.1" \
   "-//OASIS//ENTITIES DocBook Additional General Entities V4.1" \
   "-//OASIS//ENTITIES DocBook Notations V4.1" \
   "-//OASIS//ENTITIES DocBook Character Entities V4.1"
  do
  $xmlcatbin --noout --add "delegatePublic" "$s" \
    "file:///$CATALOG" for-catalog-docbook_4-4.5.xml.tmp
 done
 $xmlcatbin --noout --add "delegateSystem" \
   "http://www.oasis-open.org/docbook/xml/4.1" \
   "file:///$CATALOG" for-catalog-docbook_4-4.5.xml.tmp
 $xmlcatbin --noout --add "delegateURI" \
   "http://www.oasis-open.org/docbook/xml/4.1" \
   "file:///$CATALOG" for-catalog-docbook_4-4.5.xml.tmp
 # Create tag
 sed '/<catalog/a\
   <group id="docbook_4-4.5">
 /<\/catalog/i\
   </group>' \
   for-catalog-docbook_4-4.5.xml.tmp > for-catalog-docbook_4-4.5.xml
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 install -d -m755 $RPM_BUILD_ROOT/var/lib/sgml
 install -d -m755 $RPM_BUILD_ROOT/var/lib/xml
 install -m644 CATALOG.* $RPM_BUILD_ROOT/var/lib/sgml
 # for CATALOG.* links
 for v in 4.1 4.2 4.3 4.4 4.5; do
   vl=${v/\.}
   install -d -m755 $RPM_BUILD_ROOT/usr/share/sgml/docbook/dtd/$v
   install -m644 dtd/${v}/* $RPM_BUILD_ROOT/usr/share/sgml/docbook/dtd/${v}
   install -d -m755 $RPM_BUILD_ROOT/usr/share/xml/docbook/schema/dtd/$v
   cp -a ${v}xml/* $RPM_BUILD_ROOT/usr/share/xml/docbook/schema/dtd/$v
   ln -s /usr/share/xml/docbook/schema/dtd/$v $RPM_BUILD_ROOT/usr/share/sgml/docbook/dtd/${v}xml
   ln -sf /var/lib/sgml/CATALOG.db${vl}xml \
     $RPM_BUILD_ROOT/usr/share/sgml/CATALOG.db${vl}xml
 done
 ln -sf /usr/share/sgml/docbook/dtd/4.1 $RPM_BUILD_ROOT/usr/share/sgml/docbook_4.1
 ln -sf /var/lib/sgml/CATALOG.docbook_4 \
   $RPM_BUILD_ROOT/usr/share/sgml/CATALOG.docbook_4
 ln -sf /var/lib/sgml/CATALOG.docbook_4 \
   $RPM_BUILD_ROOT/usr/share/sgml/CATALOG.docbk41
 cat_dir=${D}/etc/xml
 install -d -m755 $cat_dir
 install -m644 for-catalog-docbook_4-4.5.xml docbook_41.xml $cat_dir
 # rng
 install -d -m755 $RPM_BUILD_ROOT/usr/share/xml/docbook/schema/rng/{4.3,4.4} \
                $RPM_BUILD_ROOT/usr/share/xml/docbook/schema/xsd/{4.3,4.4}
 unzip -q -a -d $RPM_BUILD_ROOT/usr/share/xml/docbook/schema/rng/4.2 ${S}/packaging/docbook-rng-4.2.zip
 unzip -q -a -d $RPM_BUILD_ROOT/usr/share/xml/docbook/schema/rng/4.3 ${S}/packaging/docbook-rng-4.3.zip
 unzip -q -a -d $RPM_BUILD_ROOT/usr/share/xml/docbook/schema/rng/4.4 ${S}/packaging/docbook-rng-4.4.zip
 unzip -q -a -d $RPM_BUILD_ROOT/usr/share/xml/docbook/schema/rng/4.5 ${S}/packaging/docbook-rng-4.5.zip
 # w3c schema
 unzip -q -a -d $RPM_BUILD_ROOT/usr/share/xml/docbook/schema/xsd/4.2 ${S}/packaging/docbook-rng-4.2.zip
 unzip -q -a -d $RPM_BUILD_ROOT/usr/share/xml/docbook/schema/xsd/4.3 ${S}/packaging/docbook-xsd-4.3.zip
 unzip -q -a -d $RPM_BUILD_ROOT/usr/share/xml/docbook/schema/xsd/4.4 ${S}/packaging/docbook-xsd-4.4.zip
 unzip -q -a -d $RPM_BUILD_ROOT/usr/share/xml/docbook/schema/xsd/4.5 ${S}/packaging/docbook-xsd-4.5.zip
 # cleanup
 
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r $RPM_BUILD_ROOT | 
   while read _file; do 
     if test -z "$_target" ; then 
       _target="$_file"; 
     else 
       if test -z "$_file" ; then 
 	_target=""; 
 	continue ; 
       fi ; 
       if test "$_symlinks" = 1; then 
         ln -sf "${_target#${D}}" "$_file"; 
       else 
         ln -f "$_target" "$_file"; 
       fi ;
     fi ; 
  done 
 
 
}

PACKAGES = ""
PACKAGES += "docbook_4"

docbook_4_files = ""
docbook_4_files += "docbook_4.manifest"
docbook_4_files += "/var/lib/sgml/CATALOG.*"
docbook_4_files += "/usr/share/sgml/CATALOG.*"
docbook_4_files += "/usr/share/sgml/docbook/dtd/4.1"
docbook_4_files += "/usr/share/sgml/docbook/dtd/4.2"
docbook_4_files += "/usr/share/sgml/docbook/dtd/4.3"
docbook_4_files += "/usr/share/sgml/docbook/dtd/4.4"
docbook_4_files += "/usr/share/sgml/docbook/dtd/4.5"
docbook_4_files += "/usr/share/sgml/docbook/dtd/4.1xml"
docbook_4_files += "/usr/share/sgml/docbook/dtd/4.2xml"
docbook_4_files += "/usr/share/sgml/docbook/dtd/4.3xml"
docbook_4_files += "/usr/share/sgml/docbook/dtd/4.4xml"
docbook_4_files += "/usr/share/sgml/docbook/dtd/4.5xml"
docbook_4_files += "/usr/share/xml/docbook/schema/dtd/4.1"
docbook_4_files += "/usr/share/xml/docbook/schema/dtd/4.2"
docbook_4_files += "/usr/share/xml/docbook/schema/dtd/4.3"
docbook_4_files += "/usr/share/xml/docbook/schema/dtd/4.4"
docbook_4_files += "/usr/share/xml/docbook/schema/dtd/4.5"
docbook_4_files += "/usr/share/xml/docbook/schema/rng/4.2"
docbook_4_files += "/usr/share/xml/docbook/schema/rng/4.3"
docbook_4_files += "/usr/share/xml/docbook/schema/rng/4.4"
docbook_4_files += "/usr/share/xml/docbook/schema/rng/4.5"
docbook_4_files += "/usr/share/xml/docbook/schema/xsd/4.2"
docbook_4_files += "/usr/share/xml/docbook/schema/xsd/4.3"
docbook_4_files += "/usr/share/xml/docbook/schema/xsd/4.4"
docbook_4_files += "/usr/share/xml/docbook/schema/xsd/4.5"
docbook_4_files += "/etc/xml/docbook_41.xml"
docbook_4_files += "/etc/xml/for-catalog-docbook_4-4.5.xml"
docbook_4_files += "/usr/share/sgml/docbook/dtd"
docbook_4_files += "/usr/share/sgml/docbook_4.1"
docbook_4_files += "/usr/share/xml/docbook/schema"
docbook_4_files += "/usr/share/xml/docbook/schema/dtd"
docbook_4_files += "/usr/share/xml/docbook/schema/rng"
docbook_4_files += "/usr/share/xml/docbook/schema/xsd"

FILES_${PN} = "${docbook_4_files}"

PKG_docbook_4= "docbook_4"

require docbook-4-extraconf.inc
