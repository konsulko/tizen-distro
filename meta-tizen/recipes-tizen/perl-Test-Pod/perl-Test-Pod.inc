DESCRIPTION = "check for POD errors in files"
HOMEPAGE = "http://search.cpan.org/dist/Test-Pod/"
SECTION = "Development/Libraries/Perl"
LICENSE = "Artistic-2.0 or GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by perl-Test-Pod 
PROVIDES += "perl-Test-Pod"
RPROVIDES_perl-Test-Pod += "perl-Test-Pod"

RDEPENDS = ""
#RDEPENDS of perl-Test-Pod (${PN})
RDEPENDS_${PN} += "perl(Test::Builder::Tester)"
RDEPENDS_${PN} += "perl(Pod::Simple)"
RDEPENDS_${PN} += "perl(Test::More)"
RDEPENDS_${PN} += "perl(File::Spec)"


DEPENDS = ""
#DEPENDS of perl-Test-Pod 
DEPENDS += "perl(File::Spec)"
DEPENDS += "perl(Pod::Simple)"
DEPENDS += "perl(Test::More)"
inherit perlnative

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Test-Pod-1.45
 cp ${S}/packaging/perl-Test-Pod.manifest .
 
 
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
 
 perl Build.PL installdirs=vendor
 ./Build build flags=-j16
 
 exit 0
 ./Build test
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 ./Build install destdir=${D} create_packlist=0
 
 FILES=perl-Test-Pod.files
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
 if [ -f "${RPM_BUILD_ROOT}/var/adm/perl-modules/perl-Test-Pod" ]; then
   fgen_file "/var/adm/perl-modules/perl-Test-Pod"
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
PACKAGES += "perl-Test-Pod"

perl-Test-Pod_files = ""
perl-Test-Pod_files += "perl-Test-Pod.manifest"

FILES_${PN} = "${perl-Test-Pod_files}"

PKG_perl-Test-Pod= "perl-Test-Pod"

require perl-Test-Pod-extraconf.inc
