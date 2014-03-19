DESCRIPTION = "Tree interface to XML documents"
HOMEPAGE = "http://search.cpan.org/dist/XML::Twig"
SECTION = "Development/Libraries/Perl"
LICENSE = "GPL-1.0+ or Artistic-1.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by perl-XML-Twig 
PROVIDES += "perl-XML-Twig"
RPROVIDES_perl-XML-Twig += "perl-XML-Twig"

RDEPENDS = ""
#RDEPENDS of perl-XML-Twig (${PN})
RDEPENDS_${PN} += "libxml-parser-perl"


DEPENDS = ""
#DEPENDS of perl-XML-Twig 
DEPENDS += "libxml-parser-perl"
inherit perlnative

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n XML-Twig-3.39
 cp ${S}/packaging/perl-XML-Twig.manifest .
 
 
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
 
 perl Makefile.PL
 make
 
 exit 0
 make test
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make DESTDIR=$RPM_BUILD_ROOT install_vendor
 
   if test -n "$RPM_BUILD_ROOT" -a -d $RPM_BUILD_ROOT/usr/lib/perl/5.14.3//auto; then 
     find $RPM_BUILD_ROOT/usr/lib/perl/5.14.3//auto -name .packlist -print0 | xargs -0 -r rm 
     if [ x86_64 == noarch ]; then 
       find $RPM_BUILD_ROOT/usr/lib/perl/5.14.3//auto -depth -type d -print0 | xargs -0 -r rmdir 
     fi 
   fi 
   rm -f $RPM_BUILD_ROOT/usr/lib/perl/5.14.3//perllocal.pod 
   
 
 
}

PACKAGES = ""
PACKAGES += "perl-XML-Twig"

perl-XML-Twig_files = ""
perl-XML-Twig_files += "perl-XML-Twig.manifest"
perl-XML-Twig_files += "/usr/lib/perl/5.14.3/XML"
perl-XML-Twig_files += "/usr/lib/perl/5.14.3/XML/Twig.pm"
perl-XML-Twig_files += "/usr/lib/perl/5.14.3/XML/Twig"
perl-XML-Twig_files += "/usr/bin/xml_grep"
perl-XML-Twig_files += "/usr/bin/xml_merge"
perl-XML-Twig_files += "/usr/bin/xml_pp"
perl-XML-Twig_files += "/usr/bin/xml_spellcheck"
perl-XML-Twig_files += "/usr/bin/xml_split"
perl-XML-Twig_files += "/usr/share/man/man1/xml_*.1.gz"
perl-XML-Twig_files += "/usr/share/man/man3/XML::Twig.3pm.gz"

FILES_${PN} = "${perl-XML-Twig_files}"

PKG_perl-XML-Twig= "perl-XML-Twig"

require perl-XML-Twig-extraconf.inc
