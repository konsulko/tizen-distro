DESCRIPTION = "A Perl module for time and date manipulation"
HOMEPAGE = "http://search.cpan.org/dist/TimeDate/"
SECTION = "Development/Libraries"
LICENSE = "GPL+ or Artistic"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by perl-TimeDate 
PROVIDES += "perl-TimeDate"
RPROVIDES_perl-TimeDate += "perl-TimeDate"

RDEPENDS = ""
#RDEPENDS of perl-TimeDate (${PN})
RDEPENDS_${PN} += "perl"


DEPENDS = ""
#DEPENDS of perl-TimeDate 
DEPENDS += "perl(ExtUtils::MakeMaker)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n TimeDate-1.20
 cp ${S}/packaging/perl-TimeDate.manifest .
 
 
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
 
 perl Makefile.PL INSTALLDIRS=vendor
 make -j16
 
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
 
 make pure_install PERL_INSTALL_ROOT=${D}
 find ${D} -type f -name .packlist -exec rm -f {} ';'
 find ${D} -depth -type d -exec rmdir {} 2>/dev/null ';'
 /bin/chmod -Rf a+rX,u+w,g-w,o-w ${D}/*
 
 
 
}

PACKAGES = ""
PACKAGES += "perl-TimeDate"

perl-TimeDate_files = ""
perl-TimeDate_files += "perl-TimeDate.manifest"
perl-TimeDate_files += "/usr/lib/perl/5.14.3/Date/*"
perl-TimeDate_files += "/usr/lib/perl/5.14.3/Time/*"
perl-TimeDate_files += "/usr/share/man/man3/*.3*"

FILES_${PN} = "${perl-TimeDate_files}"

PKG_perl-TimeDate= "perl-TimeDate"

require perl-TimeDate-extraconf.inc
