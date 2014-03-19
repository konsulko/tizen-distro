DESCRIPTION = "Text-Based Document Generation"
HOMEPAGE = "http://www.methods.co.nz/asciidoc/"
SECTION = "Development/Tools/Doc Generators"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by asciidoc-examples 
PROVIDES += "asciidoc-examples"
RPROVIDES_asciidoc-examples += "asciidoc-examples"

#PROVIDES by asciidoc 
PROVIDES += "asciidoc"
RPROVIDES_asciidoc += "asciidoc"

RDEPENDS = ""
#RDEPENDS of asciidoc (${PN})
RDEPENDS_${PN} += "python"
RDEPENDS_${PN} += "python-xml"
RDEPENDS_${PN} += "docbook-xsl-stylesheets"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/asciidoc.manifest .
 
 
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
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p $RPM_BUILD_ROOT/etc/asciidoc/filters
 mkdir -p $RPM_BUILD_ROOT/usr/share/asciidoc
 mkdir -p $RPM_BUILD_ROOT/usr/share/man/man1
 install -m 0644 *.conf $RPM_BUILD_ROOT/etc/asciidoc
 install -m 0644 filters/*/*.conf $RPM_BUILD_ROOT/etc/asciidoc/filters/
 install -m 0755 filters/*/*.py $RPM_BUILD_ROOT/etc/asciidoc/filters/
 install -m 0755 -D asciidoc.py $RPM_BUILD_ROOT/usr/bin/asciidoc
 install -m 0755 -D a2x.py $RPM_BUILD_ROOT/usr/bin/a2x
 install -m 0644 doc/*.1  $RPM_BUILD_ROOT/usr/share/man/man1/
 for i in images stylesheets javascripts docbook-xsl dblatex; do
   cp -av $i $RPM_BUILD_ROOT/usr/share/asciidoc/
   ln -s ../..//usr/share/asciidoc/$i $RPM_BUILD_ROOT/etc/asciidoc
 done
 # install vim files
 mkdir -p $RPM_BUILD_ROOT/usr/share/vim/site/{syntax,ftdetect}
 install -m 0644 vim/syntax/* $RPM_BUILD_ROOT/usr/share/vim/site/syntax
 install -m 0644 vim/ftdetect/* $RPM_BUILD_ROOT/usr/share/vim/site/ftdetect
 
 
}

PACKAGES = ""
PACKAGES += "asciidoc"

asciidoc_files = ""
asciidoc_files += "asciidoc.manifest"
asciidoc_files += "/etc/asciidoc"
asciidoc_files += "/usr/share/asciidoc"
asciidoc_files += "/usr/bin/*"
asciidoc_files += "/usr/share/vim"
asciidoc_files += "/usr/share/man/man1/*"

FILES_${PN} = "${asciidoc_files}"

PKG_asciidoc= "asciidoc"

require asciidoc-extraconf.inc
