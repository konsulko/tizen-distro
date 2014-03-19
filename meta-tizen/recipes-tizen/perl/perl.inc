DESCRIPTION = "The Perl interpreter"
HOMEPAGE = "http://www.perl.org/"
SECTION = "Platform Development/Perl"
LICENSE = "Artistic-1.0 or GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by perl-doc 
PROVIDES += "perl-doc"
RPROVIDES_perl-doc += "perl-doc"
# the PROVIDES rules is ignore "perl:/usr/share/man/man3/CORE.3pm.gz  "
PROVIDES += "perl:/usr/share/man/man3/CORE.3pm.gz"
RPROVIDES_perl-doc += "perl:/usr/share/man/man3/CORE.3pm.gz"

#PROVIDES by perl 
PROVIDES += "perl"
RPROVIDES_perl += "perl"
# the PROVIDES rules is ignore "/bin/perl  "
PROVIDES += "/bin/perl"
RPROVIDES_perl += "/bin/perl"
# the PROVIDES rules is ignore "perl-500  "
PROVIDES += "perl-500"
RPROVIDES_perl += "perl-500"
# the PROVIDES rules is ignore "perl-macros  "
PROVIDES += "perl-macros"
RPROVIDES_perl += "perl-macros"
# the PROVIDES rules is ignore "perl(:MODULE_COMPAT_5.16.3)  "
PROVIDES += "perl(:MODULE_COMPAT_5.16.3)"
RPROVIDES_perl += "perl(:MODULE_COMPAT_5.16.3)"
# the PROVIDES rules is ignore "perl-base  "
PROVIDES += "perl-base"
RPROVIDES_perl += "perl-base"
# the PROVIDES rules is ignore "perl-Filter-Simple  "
PROVIDES += "perl-Filter-Simple"
RPROVIDES_perl += "perl-Filter-Simple"
# the PROVIDES rules is ignore "perl-I18N-LangTags  "
PROVIDES += "perl-I18N-LangTags"
RPROVIDES_perl += "perl-I18N-LangTags"
# the PROVIDES rules is ignore "perl-MIME-Base64  "
PROVIDES += "perl-MIME-Base64"
RPROVIDES_perl += "perl-MIME-Base64"
# the PROVIDES rules is ignore "perl-Storable  "
PROVIDES += "perl-Storable"
RPROVIDES_perl += "perl-Storable"
# the PROVIDES rules is ignore "perl-Test-Simple = 0.98-0"
PROVIDES += "perl-Test-Simple"
RPROVIDES_perl += "perl-Test-Simple"
# the PROVIDES rules is ignore "perl-Text-Balanced  "
PROVIDES += "perl-Text-Balanced"
RPROVIDES_perl += "perl-Text-Balanced"
# the PROVIDES rules is ignore "perl-Time-HiRes  "
PROVIDES += "perl-Time-HiRes"
RPROVIDES_perl += "perl-Time-HiRes"
# the PROVIDES rules is ignore "perl-libnet  "
PROVIDES += "perl-libnet"
RPROVIDES_perl += "perl-libnet"
# the PROVIDES rules is ignore "perl-Compress-Raw-Zlib  "
PROVIDES += "perl-Compress-Raw-Zlib"
RPROVIDES_perl += "perl-Compress-Raw-Zlib"
# the PROVIDES rules is ignore "perl-Compress-Zlib  "
PROVIDES += "perl-Compress-Zlib"
RPROVIDES_perl += "perl-Compress-Zlib"
# the PROVIDES rules is ignore "perl-IO-Compress-Base  "
PROVIDES += "perl-IO-Compress-Base"
RPROVIDES_perl += "perl-IO-Compress-Base"
# the PROVIDES rules is ignore "perl-IO-Compress-Zlib  "
PROVIDES += "perl-IO-Compress-Zlib"
RPROVIDES_perl += "perl-IO-Compress-Zlib"
# the PROVIDES rules is ignore "perl-IO-Zlib  "
PROVIDES += "perl-IO-Zlib"
RPROVIDES_perl += "perl-IO-Zlib"
# the PROVIDES rules is ignore "perl-Archive-Tar  "
PROVIDES += "perl-Archive-Tar"
RPROVIDES_perl += "perl-Archive-Tar"
# the PROVIDES rules is ignore "perl-Module-Build  "
PROVIDES += "perl-Module-Build"
RPROVIDES_perl += "perl-Module-Build"
# the PROVIDES rules is ignore "perl(Module::Build) = 0.3900"
PROVIDES += "perl(Module::Build)"
RPROVIDES_perl += "perl(Module::Build)"
# the PROVIDES rules is ignore "perl-Locale-Maketext-Simple  "
PROVIDES += "perl-Locale-Maketext-Simple"
RPROVIDES_perl += "perl-Locale-Maketext-Simple"
# the PROVIDES rules is ignore "perl-Module-Pluggable  "
PROVIDES += "perl-Module-Pluggable"
RPROVIDES_perl += "perl-Module-Pluggable"
# the PROVIDES rules is ignore "perl-Pod-Escapes  "
PROVIDES += "perl-Pod-Escapes"
RPROVIDES_perl += "perl-Pod-Escapes"
# the PROVIDES rules is ignore "perl-Pod-Simple  "
PROVIDES += "perl-Pod-Simple"
RPROVIDES_perl += "perl-Pod-Simple"
# the PROVIDES rules is ignore "perl-ExtUtils-ParseXS  "
PROVIDES += "perl-ExtUtils-ParseXS"
RPROVIDES_perl += "perl-ExtUtils-ParseXS"
# the PROVIDES rules is ignore "perl-version  "
PROVIDES += "perl-version"
RPROVIDES_perl += "perl-version"

RDEPENDS = ""
#RDEPENDS of perl-doc (${PN}-doc)
RDEPENDS_${PN}-doc += "perl"


DEPENDS = ""
#DEPENDS of perl 
DEPENDS += "ncurses"
DEPENDS += "zlib-devel"
DEPENDS += "gdbm"
DEPENDS += "db4"
DEPENDS += "bzip2"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n perl-5.16.3
 cp ${S}/packaging/perl.manifest .
 cp -p ${S}/packaging/README.macros .
 
 
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
 
 RPM_OPT_FLAGS=$(echo $RPM_OPT_FLAGS | sed -e "s/--param=ssp-buffer-size=32//g" )
 export RPM_OPT_FLAGS
 cp -a lib savelib
 export LD_AS_NEEDED=0
 export BZIP2_LIB=/usr/lib
 export BZIP2_INCLUDE=/usr/include
 export BUILD_BZIP2=0
 options="-Doptimize='$RPM_OPT_FLAGS -Wall -pipe'"
 # always use glibc's setenv
 options="$options -Accflags='-DPERL_USE_SAFE_PUTENV'"
 options="$options -Dotherlibdirs=/usr/lib/perl5/site_perl"
 chmod 755 ./configure.gnu
 ./configure.gnu --prefix=/usr -Dvendorprefix=/usr -Dinstallusrbinperl -Dusethreads -Di_db -Di_dbm -Di_ndbm -Di_gdbm -Dd_dbm_open -Duseshrplib=\'true\' $options
 make -j16
 cp -p libperl.so savelibperl.so
 cp -p lib/Config.pm saveConfig.pm
 cp -p lib/Config_heavy.pl saveConfig_heavy.pl
 make clean > /dev/null
 make clobber
 rm -rf lib
 mv savelib lib
 ./configure.gnu --prefix=/usr -Dvendorprefix=/usr -Dinstallusrbinperl -Dusethreads -Di_db -Di_dbm -Di_ndbm -Di_gdbm -Dd_dbm_open $options
 make -j16
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR=$RPM_BUILD_ROOT
 cp -a $RPM_BUILD_ROOT/usr/lib/perl5/site_perl $RPM_BUILD_ROOT/usr/lib/perl5/vendor_perl
 cpa=`echo $RPM_BUILD_ROOT/usr/lib/perl5/*/*/CORE | sed -e 's@/CORE$@@'`
 cp=`echo "$cpa" | sed -e 's@/[^/]*$@@'`
 vpa=`echo $cpa | sed -e 's@/perl5/@/perl5/vendor_perl/@'`
 vp=`echo "$vpa" | sed -e 's@/[^/]*$@@'`
 install -d $vp/auto
 install -d $vpa/auto
 install -m 555 savelibperl.so $cpa/CORE/libperl.so
 install -m 444 saveConfig.pm $cpa/Config.pm
 install -m 444 saveConfig_heavy.pl $cpa/Config_heavy.pl
 # install macros.perl file
 install -D -m 644 ${S}/packaging/macros.perl $RPM_BUILD_ROOT/etc/rpm/macros.perl
 pushd /usr/include
 ( rpm -ql glibc-devel | fgrep '.h' 
   find /usr/include/asm/ -name \*.h
   find /usr/include/asm-generic -name \*.h
   find /usr/include/linux -name \*.h
 ) | while read f; do
   $RPM_BUILD_ROOT/usr/bin/perl -I$cp -I$cpa $RPM_BUILD_ROOT/usr/bin/h2ph -d $vpa ${f/\/usr\/include\//} || : 
 done
 popd
 d="`gcc -print-file-name=include`"
 test -f "$d/stdarg.h" && (cd $d ; $RPM_BUILD_ROOT/usr/bin/perl -I$cp -I$cpa $RPM_BUILD_ROOT/usr/bin/h2ph -d $vpa stdarg.h stddef.h float.h)
 # remove broken pm - we don't have the module
 rm $RPM_BUILD_ROOT/usr/lib/perl5/*/Pod/Perldoc/ToTk.pm
 # we don't need this in here
 rm $RPM_BUILD_ROOT/usr/lib/perl5/*/*/CORE/libperl.a
 #touch $RPM_BUILD_ROOT/usr/share/man/man3/perllocal.3pm
 #touch $cpa/perllocal.pod
 # test CVE-2007-5116
 $RPM_BUILD_ROOT/usr/bin/perl -e '$r=chr(128)."\\x{100}";/$r/'
 # test perl-regexp-refoverflow.diff
 $RPM_BUILD_ROOT/usr/bin/perl -e '/\6666666666/'
 cat << EOF > perl-base-filelist
 /usr/lib/perl5/5.16.3/B/Deparse.pm
 /usr/lib/perl5/5.16.3/Carp.pm
 /usr/lib/perl5/5.16.3/Carp/
 /usr/lib/perl5/5.16.3/Class/
 /usr/lib/perl5/5.16.3/Config/
 /usr/lib/perl5/5.16.3/Digest.pm
 /usr/lib/perl5/5.16.3/Digest/
 /usr/lib/perl5/5.16.3/Exporter.pm
 /usr/lib/perl5/5.16.3/Exporter/
 /usr/lib/perl5/5.16.3/File/
 /usr/lib/perl5/5.16.3/Getopt/
 /usr/lib/perl5/5.16.3/IPC/
 /usr/lib/perl5/5.16.3/Text/
 /usr/lib/perl5/5.16.3/Tie/Hash.pm
 /usr/lib/perl5/5.16.3/XSLoader.pm
 /usr/lib/perl5/5.16.3/warnings.pm
 /usr/lib/perl5/5.16.3/warnings/
 /usr/lib/perl5/5.16.3/AutoLoader.pm
 /usr/lib/perl5/5.16.3/FileHandle.pm
 /usr/lib/perl5/5.16.3/SelectSaver.pm
 /usr/lib/perl5/5.16.3/Symbol.pm
 /usr/lib/perl5/5.16.3/base.pm
 /usr/lib/perl5/5.16.3/bytes.pm
 /usr/lib/perl5/5.16.3/bytes_heavy.pl
 /usr/lib/perl5/5.16.3/constant.pm
 /usr/lib/perl5/5.16.3/fields.pm
 /usr/lib/perl5/5.16.3/feature.pm
 /usr/lib/perl5/5.16.3/integer.pm
 /usr/lib/perl5/5.16.3/locale.pm
 /usr/lib/perl5/5.16.3/overload.pm
 /usr/lib/perl5/5.16.3/overloading.pm
 /usr/lib/perl5/5.16.3/strict.pm
 /usr/lib/perl5/5.16.3/unicore/Heavy.pl
 /usr/lib/perl5/5.16.3/utf8.pm
 /usr/lib/perl5/5.16.3/utf8_heavy.pl
 /usr/lib/perl5/5.16.3/vars.pm
 /usr/lib/perl5/5.16.3/version.pm
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/Data/
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/Digest/
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/File/
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/List/
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/Scalar/
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/IO.pm
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/IO/Dir.pm
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/IO/File.pm
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/IO/Handle.pm
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/IO/Pipe.pm
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/IO/Poll.pm
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/IO/Seekable.pm
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/IO/Select.pm
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/IO/Socket.pm
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/IO/Socket/
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/B.pm
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/Config.pm
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/Config_heavy.pl
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/Cwd.pm
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/DynaLoader.pm
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/Errno.pm
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/Fcntl.pm
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/POSIX.pm
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/Socket.pm
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/attributes.pm
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/auto/Data/
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/auto/Digest/
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/auto/Fcntl/
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/auto/File/
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/auto/IO/
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/auto/List/
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/auto/Cwd/
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/auto/Socket/
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/auto/POSIX/POSIX.bs
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/auto/POSIX/POSIX.so
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/lib.pm
 /usr/lib/perl5/5.16.3/*-linux-thread-multi*/re.pm
 EOF
 
 
 
 
}

PACKAGES = ""
PACKAGES += "perl-doc"
PACKAGES += "perl"

perl-doc_files = ""
perl-doc_files += "perl.manifest"
perl-doc_files += "README.macros"
perl-doc_files += "/usr/lib/perl5/*/pod"
perl-doc_files += "/usr/share/man/man?/*"

perl_files = ""
perl_files += "perl.manifest"
perl_files += "/usr/lib/perl5"
perl_files += "/usr/lib/perl5/5.16.3"
perl_files += "/usr/lib/perl5/5.16.3/B"
perl_files += "/usr/lib/perl5/5.16.3/*-linux-thread-multi*"
perl_files += "/usr/lib/perl5/5.16.3/*-linux-thread-multi*/auto"
perl_files += "/usr/lib/perl5/5.16.3/*-linux-thread-multi*/auto/POSIX"
perl_files += "/etc/rpm/macros.perl"
perl_files += "/usr/lib/perl5/*"
perl_files += "/usr/bin/*"

FILES_${PN}-doc = "${perl-doc_files}"
FILES_${PN} = "${perl_files}"

PKG_perl-doc= "perl-doc"
PKG_perl= "perl"

require perl-extraconf.inc
