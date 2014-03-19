DESCRIPTION = "Perl extension for the DBus message system"
HOMEPAGE = "http://search.cpan.org/dist/Net-DBus/"
SECTION = "Development/Libraries"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by perl-Net-DBus 
PROVIDES += "perl-Net-DBus"
RPROVIDES_perl-Net-DBus += "perl-Net-DBus"

RDEPENDS = ""
#RDEPENDS of perl-Net-DBus (${PN})
RDEPENDS_${PN} += "perl(XML::Twig)"


DEPENDS = ""
#DEPENDS of perl-Net-DBus 
DEPENDS += "perl(Test::Pod)"
DEPENDS += "perl(XML::Twig)"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "pkgconfig(pkg-config)"
inherit perlnative
DEPENDS += "perl(Test::Pod::Coverage)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Net-DBus-1.0.0
 cp ${S}/packaging/perl-Net-DBus.manifest .
 find . -type f -print0 | xargs -0 chmod 644
 
 
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
 
 perl Makefile.PL INSTALLDIRS=vendor OPTIMIZE="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables"
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
 
 make DESTDIR=$RPM_BUILD_ROOT install_vendor
 
   if test -n "$RPM_BUILD_ROOT" -a -d $RPM_BUILD_ROOT/usr/lib/perl/5.14.3//auto; then 
     find $RPM_BUILD_ROOT/usr/lib/perl/5.14.3//auto -name .packlist -print0 | xargs -0 -r rm 
     if [ x86_64 == noarch ]; then 
       find $RPM_BUILD_ROOT/usr/lib/perl/5.14.3//auto -depth -type d -print0 | xargs -0 -r rmdir 
     fi 
   fi 
   rm -f $RPM_BUILD_ROOT/usr/lib/perl/5.14.3//perllocal.pod 
   
 
 FILES=perl-Net-DBus.files
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
 if [ -f "${RPM_BUILD_ROOT}/var/adm/perl-modules/perl-Net-DBus" ]; then
   fgen_file "/var/adm/perl-modules/perl-Net-DBus"
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
PACKAGES += "perl-Net-DBus"

perl-Net-DBus_files = ""
perl-Net-DBus_files += "perl-Net-DBus.manifest"
perl-Net-DBus_files += "AUTHORS CHANGES examples LICENSE Net-DBus.spec README"

FILES_${PN} = "${perl-Net-DBus_files}"

PKG_perl-Net-DBus= "perl-Net-DBus"

require perl-Net-DBus-extraconf.inc
