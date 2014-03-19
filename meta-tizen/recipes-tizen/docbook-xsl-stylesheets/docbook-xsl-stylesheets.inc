DESCRIPTION = "XSL Stylesheets for DocBook 4"
HOMEPAGE = "http://sourceforge.net/projects/docbook/"
SECTION = "Productivity/Publishing/DocBook"
LICENSE = "MPL-1.1 and MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by docbook-xsl-stylesheets 
PROVIDES += "docbook-xsl-stylesheets"
RPROVIDES_docbook-xsl-stylesheets += "docbook-xsl-stylesheets"

RDEPENDS = ""
#RDEPENDS of docbook-xsl-stylesheets (${PN})
RDEPENDS_${PN} += "xmlcharent"
RDEPENDS_${PN} += "docbook_4"
RDEPENDS_${PN} += "sgml-skel"
RDEPENDS_${PN} += "/usr/bin/sgml-register-catalog"
RDEPENDS_${PN} += "/usr/bin/xmlcatalog"


DEPENDS = ""
#DEPENDS of docbook-xsl-stylesheets 
DEPENDS += "unzip"
DEPENDS += "sgml-skel"
DEPENDS += "fdupes-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n docbook-xsl-1.77.1 
 cp ${S}/packaging/docbook-xsl-stylesheets.manifest .
 
 # mv epub/bin/dbtoepub epub/bin/dbtoepub.tmp
 sed -i 's=@@EPUBDIR@@=/usr/share/xml/docbook/stylesheet/nwalsh/current//epub/bin='  epub/bin/dbtoepub
 
 # We don't need these scripts:
 rm -rf install.sh tools/bin/docbook-xsl-update
 
 find -type f  -exec chmod -x {} \;
 chmod -R a+rX,g-w,o-w .
 chmod -x images/*.{svg,png,gif,tif} images/callouts/*.{svg,png,gif} extensions/docbook.py
 # Start cleanup (to avoid warnings for rpmlint
 [ -f ./extensions/saxon65/dist/saxon65.jar ] && rm -rf ./extensions/saxon65/dist/saxon65.jar
 [ -f ./extensions/xalan27/dist/xalan27.jar ] && rm -rf ./extensions/xalan27/dist/xalan27.jar
 find . -name '.gitignore' | xargs rm -fr
 #x=$(find {lib,html,fo,lib,website,slides/fo,slides/html,roundtrip,manpages}/.[a-zA-Z0-9]* -maxdepth 1 -type f )
 #if [ "$x" != '' ]; then
 ## rm $x;
 #  for i in $x; do
 #     if [ -f $i ]; then
 #        rm $i
 #     fi
 #  done
 #fi
 
 
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
 
 xmlcatbin=/usr/bin/xmlcatalog
 CATALOG=docbook-xsl-stylesheets.xml
 # file:///usr/share/sgml/docbook/ = %{sgml_mod_dir} map it to
 # %{xml_mod_style_prod_dir}/%{version}
 $xmlcatbin --noout --create $CATALOG
 /usr/bin/xmlcatalog --noout --add "rewriteSystem" \
  "http://docbook.sourceforge.net/release/xsl/1.77.1" \
  "file:///usr/share/xml/docbook/stylesheet/nwalsh/1.77.1" $CATALOG
 /usr/bin/xmlcatalog --noout --add "rewriteURI" \
  "http://docbook.sourceforge.net/release/xsl/1.77.1" \
  "file:///usr/share/xml/docbook/stylesheet/nwalsh/1.77.1" $CATALOG
 /usr/bin/xmlcatalog --noout --add "rewriteSystem" \
  "http://docbook.sourceforge.net/release/xsl/current" \
  "file:///usr/share/xml/docbook/stylesheet/nwalsh/1.77.1" $CATALOG
 /usr/bin/xmlcatalog --noout --add "rewriteURI" \
  "http://docbook.sourceforge.net/release/xsl/current" \
  "file:///usr/share/xml/docbook/stylesheet/nwalsh/1.77.1" $CATALOG
 CATALOG=etc/xml/$CATALOG
 rm -f for-catalog-docbook-xsl-stylesheets-1.77.1.xml.tmp
 $xmlcatbin --noout --create for-catalog-docbook-xsl-stylesheets-1.77.1.xml.tmp
 $xmlcatbin --noout --add "delegateSystem" \
   "http://docbook.sourceforge.net/release/xsl/" \
   "file:///$CATALOG" for-catalog-docbook-xsl-stylesheets-1.77.1.xml.tmp
 # $xmlcatbin --noout --add "delegatePublic" \
 #   "-//OASIS//xxx" \
 #   "file:///$CATALOG" %{FOR_ROOT_CAT}.tmp
 # Create tag
 sed '/<catalog/a\
   <group id="docbook-xsl-stylesheets-1.77.1">
 /<\/catalog/i\
   </group>' \
   for-catalog-docbook-xsl-stylesheets-1.77.1.xml.tmp > for-catalog-docbook-xsl-stylesheets-1.77.1.xml
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 # FIXME: Danger!?
 # export NO_BRP_CHECK_BYTECODE_VERSION=true
 
 # Install scripts
 install -d -m755 ${D}/usr/bin
 install -m755 fo/pdf2index       ${D}/usr/bin
 install -m755 epub/bin/dbtoepub  ${D}/usr/bin
 rm fo/pdf2index
 
 doc_dir=${D}/usr/share/doc/packages/docbook-xsl-stylesheets
 install -d -m755 ${D}/usr/share/xml/docbook/stylesheet/nwalsh/1.77.1
 cp -a [[:lower:]]* ${D}/usr/share/xml/docbook/stylesheet/nwalsh/1.77.1
 cp -a VERSION.xsl ${D}/usr/share/xml/docbook/stylesheet/nwalsh/1.77.1
 find ${D}/usr/share/xml/docbook/stylesheet/nwalsh -type f -name '*.orig' -exec rm -f {} \;
 rm -f ${D}/usr/share/xml/docbook/stylesheet/nwalsh/1.77.1/for-catalog*
 : >docbook-xsl-stylesheets_list
 {
   pushd ${D}/usr/share/xml/docbook/stylesheet/nwalsh >/dev/null
 # do not create the current link for snapshots
 #  if ! echo %{SOURCE0} | grep -q snapshot; then
     ln -sf 1.77.1 current
     echo /usr/share/xml/docbook/stylesheet/nwalsh/current
 #  fi
   popd >/dev/null
 } >docbook-xsl-stylesheets_list
 install -d -m755 $doc_dir
 # documentation
 for f in README BUGS TODO WhatsNew RELEASE-NOTES.html; do
   # On snapshots, WhatsNew is missing
   [ -f $f ] && install -m644 $f $doc_dir/$f
 done
 # cp -p README.SuSE $doc_dir/README.SuSE
 #
 {
   LANG=C \
     find ${D}/usr/share/xml/docbook/stylesheet/nwalsh/1.77.1 \
     -type d \
     -not -path '${D}/usr/share/xml/docbook/stylesheet/nwalsh/1.77.1/latex*' \
     | sed 's|${D}|%dir |'
   LANG=C \
     find ${D}/usr/share/xml/docbook/stylesheet/nwalsh/1.77.1 \
     -type f \
     -not -path '${D}/usr/share/xml/docbook/stylesheet/nwalsh/1.77.1/latex*' \
     | sed 's|${D}||'
 } >> ${WORKDIR}/git/docbook-xsl-stylesheets_list
 # pushd %{buildroot}%{xml_mod_style_prod_dir}
 #   rm -f docbook-xsl
 #   ln -sf docbook-xsl-stylesheets-%{version} docbook-xsl
 #   rm -f xsl-stylesheets
 #   ln -sf docbook-xsl-stylesheets-%{version} xsl-stylesheets
 #   rm -f %{name}
 #   ln -sf docbook-xsl-stylesheets-%{version} %{name}
 # popd
 cat_dir=${D}/etc/xml
 install -d -m755 $cat_dir
 install -m644 for-catalog-docbook-xsl-stylesheets-1.77.1.xml docbook-xsl-stylesheets.xml $cat_dir
 # cleanup
 rm -f ${D}/usr/share/xml/docbook/stylesheet/nwalsh/1.77.1/docbook-xsl-stylesheets.xml
 cp $cat_dir/for-catalog-docbook-xsl-stylesheets-1.77.1.xml \
   ${D}/usr/share/xml/docbook/stylesheet/nwalsh/1.77.1/docbook-xsl-stylesheets.xml
 chmod +x \
 ${D}/usr/share/xml/docbook/stylesheet/nwalsh/1.77.1/extensions/docbook.py \
 ${D}/usr/share/xml/docbook/stylesheet/nwalsh/1.77.1/extensions/xslt.py
 # %{buildroot}%{xml_mod_style_prod_dir}/%{version}/epub/bin/lib/docbook.rb
 # %{buildroot}%{xml_mod_style_prod_dir}/%{version}/epub/bin/spec/spec_helper.rb
 
 
  _target=""; 
  _symlinks=0; 
  _symlinks=1; 
  fdupes -q -n -r ${D} | 
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
PACKAGES += "docbook-xsl-stylesheets"

docbook-xsl-stylesheets_files = ""
docbook-xsl-stylesheets_files += "docbook-xsl-stylesheets.manifest"
docbook-xsl-stylesheets_files += "/etc/xml/docbook-xsl-stylesheets.xml"
docbook-xsl-stylesheets_files += "/etc/xml/for-catalog-docbook-xsl-stylesheets-1.77.1.xml"
docbook-xsl-stylesheets_files += "/usr/share/doc/packages/docbook-xsl-stylesheets"
docbook-xsl-stylesheets_files += "/usr/share/xml/docbook/stylesheet"
docbook-xsl-stylesheets_files += "/usr/share/xml/docbook/stylesheet/nwalsh"
docbook-xsl-stylesheets_files += "/usr/bin/*"

FILES_${PN} = "${docbook-xsl-stylesheets_files}"

PKG_docbook-xsl-stylesheets= "docbook-xsl-stylesheets"

require docbook-xsl-stylesheets-extraconf.inc
