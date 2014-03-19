DESCRIPTION = "Easy API to read/write XML (Perl module)"
HOMEPAGE = "http://cpan.org/modules/by-module/XML/"
SECTION = "Development/Libraries/Perl"
LICENSE = "Artistic-1.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by perl-XML-Simple 
PROVIDES += "perl-XML-Simple"
RPROVIDES_perl-XML-Simple += "perl-XML-Simple"

RDEPENDS = ""
#RDEPENDS of perl-XML-Simple (${PN})
RDEPENDS_${PN} += "libxml-parser-perl"


DEPENDS = ""
#DEPENDS of perl-XML-Simple 
DEPENDS += "libxml-parser-perl"
inherit perlnative

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n XML-Simple-2.18
 cp ${S}/packaging/perl-XML-Simple.manifest .
 
 
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
PACKAGES += "perl-XML-Simple"

perl-XML-Simple_files = ""
perl-XML-Simple_files += "perl-XML-Simple.manifest"
perl-XML-Simple_files += "/usr/share/man/man?/*"
perl-XML-Simple_files += "/usr/lib/perl/5.14.3/XML"
perl-XML-Simple_files += "/usr/lib/perl/5.14.3/auto/XML"

FILES_${PN} = "${perl-XML-Simple_files}"

PKG_perl-XML-Simple= "perl-XML-Simple"

require perl-XML-Simple-extraconf.inc
