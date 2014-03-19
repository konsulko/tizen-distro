DESCRIPTION = "Perl module for parsing HTML"
HOMEPAGE = "http://search.cpan.org/dist/HTML-Parser/"
SECTION = "Development/Libraries"
LICENSE = "GPL-2.0+ or Artistic"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by perl-HTML-Parser 
PROVIDES += "perl-HTML-Parser"
RPROVIDES_perl-HTML-Parser += "perl-HTML-Parser"

#PROVIDES by perl-HTML-Parser-docs  
PROVIDES += "perl-HTML-Parser-docs "
RPROVIDES_perl-HTML-Parser-docs  += "perl-HTML-Parser-docs "

RDEPENDS = ""
#RDEPENDS of perl-HTML-Parser (${PN})
RDEPENDS_${PN} += "perl(HTML::Tagset)"


DEPENDS = ""
#DEPENDS of perl-HTML-Parser 
DEPENDS += "perl(HTML::Tagset)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n HTML-Parser-3.69
 cp ${S}/packaging/perl-HTML-Parser.manifest .
 
 
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
   
 
 FILES=perl-HTML-Parser.files
 # fgen_dir func
 # IN: dir
 fgen_dir(){
 /bin/cat >> $FILES << EOF
 %dir ${1}
 EOF
 }
 # fgen_file func
 # IN: file
 fgen_file(){
 /bin/cat >> $FILES << EOF
 ${1}
 EOF
 }
 # check for files in /usr/lib/perl/5.14.3/
 RES=`find ${RPM_BUILD_ROOT}/usr/lib/perl/5.14.3/ -maxdepth 1 -type f`
 if [ -n "$RES" ]; then
   for file in $RES; do
     fgen_file "/usr/lib/perl/5.14.3//$(basename ${file})"
   done
 fi
 
 # get all dirs into array
 base_dir="${RPM_BUILD_ROOT}/usr/lib/perl/5.14.3//"
 for dir in `find ${base_dir} -type d | sort`; do
   if [ "$dir" = "${base_dir}" ]; then
     continue
   else
     el=`echo $dir | gawk -F"${base_dir}" '{print $2}'`
     all_dir=(${all_dir[@]} $el)
   fi
 done
 
 # build filelist
 for i in ${all_dir[@]}; do
   # do not add "dir {perl_vendorlib/arch}/auto", included in perl package
   if [ "${i}" = "auto" ]; then
     continue
   fi
   if [ "/usr/lib/perl/5.14.3//${i}" = "/usr/lib/perl/5.14.3//auto" ]; then
     continue
   else
     if [ -d ${base_dir}/${i} ]; then
       RES=`find "${base_dir}/${i}" -maxdepth 1 -type f`
       if [ -n "$RES" ]; then
         fgen_dir "/usr/lib/perl/5.14.3//${i}"
         for file in $RES; do
           fgen_file "/usr/lib/perl/5.14.3//${i}/$(basename ${file})"
         done
       else
         fgen_dir "/usr/lib/perl/5.14.3//${i}"
       fi
     fi
   fi
 done
 # add man pages
 # if exist :)
 if [ -d "${RPM_BUILD_ROOT}/usr/share/man" ]; then
 fgen_file "/usr/share/man/man?/*"
 fi
 
 # add packlist file
 # generated fom perllocal.pod
 if [ -f "${RPM_BUILD_ROOT}/var/adm/perl-modules/perl-HTML-Parser" ]; then
   fgen_file "/var/adm/perl-modules/perl-HTML-Parser"
 fi
 
 # check for files in /usr/bin
 if [ -d ${RPM_BUILD_ROOT}/usr/bin ]; then
   RES=`find "${RPM_BUILD_ROOT}/usr/bin" -maxdepth 1 -type f`
   if [ -n "$RES" ]; then
     for file in $RES; do
       fgen_file "/usr/bin/$(basename ${file})"
     done
   fi
 fi
 
 
 
}

PACKAGES = ""
PACKAGES += "perl-HTML-Parser"
PACKAGES += "perl-HTML-Parser-docs"

perl-HTML-Parser_files = ""

perl-HTML-Parser-docs_files = ""
perl-HTML-Parser-docs_files += "/usr/share/info"
perl-HTML-Parser-docs_files += "/usr/share/man"

FILES_${PN} = "${perl-HTML-Parser_files}"
FILES_${PN}-docs = "${perl-HTML-Parser-docs_files}"

PKG_perl-HTML-Parser= "perl-HTML-Parser"
PKG_perl-HTML-Parser-docs= "perl-HTML-Parser-docs"

require perl-HTML-Parser-extraconf.inc
