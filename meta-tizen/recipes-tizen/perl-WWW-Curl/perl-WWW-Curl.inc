DESCRIPTION = ""
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Base"
LICENSE = ""

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by  
PROVIDES += ""
RPROVIDES_ += ""

RDEPENDS = ""
#RDEPENDS of  ()
RDEPENDS_ += "libcurl"


DEPENDS = ""
#DEPENDS of  
DEPENDS += "perl-Test-Pod-Coverage"
DEPENDS += "pkgconfig(libcurl)"
DEPENDS += "c-ares"
DEPENDS += "openssl"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup
 cp ${S}/packaging/perl-WWW-Curl.manifest .
 chmod -R u+w ${WORKDIR}/perl-WWW-Curl-4.05
 
 
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
 
 grep -rsl '^#!.*perl' . |
 grep -v '.bak$' |xargs --no-run-if-empty \
 /bin/perl -MExtUtils::MakeMaker -e 'MY->fixin(@ARGV)'
 CFLAGS="$RPM_OPT_FLAGS"
 /bin/perl Makefile.PL `/bin/perl -MExtUtils::MakeMaker -e ' print qq|PREFIX=${D}/usr| if \$ExtUtils::MakeMaker::VERSION =~ /5\.9[1-6]|6\.0[0-5]/ '`
 oe_runmake 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 [ "${D}" != "/" ] && rm -rf ${D}
 
 
   oe_runmake \
         DESTDIR=${D} \
         BINDIR=/usr/bin \
         prefix=/usr \
         exec_prefix=/usr \
         bindir=/usr/bin \
         sbindir=/usr/sbin \
         sysconfdir=/etc \
         datadir=/usr/share \
         includedir=/usr/include \
         libdir=/usr/lib \
         libexecdir=/usr/libexec \
         localstatedir=}/var \
         sharedstatedir=/usr/com \
         mandir=/usr/share/man \
         infodir=/usr/share/info \
   install `/bin/perl -MExtUtils::MakeMaker -e ' print \$ExtUtils::MakeMaker::VERSION <= 6.05 ? qq|PREFIX=${D}/usr| : qq|DESTDIR=${D}| '`
 
 cmd=/usr/share/spec-helper/compress_files
 [ -x $cmd ] || cmd=/usr/lib/rpm/brp-compress
 [ -x $cmd ] && $cmd
 
 # SuSE Linux
 if [ -e /etc/SuSE-release -o -e /etc/UnitedLinux-release ]
 then
     /bin/mkdir -p ${D}/var/adm/perl-modules
     /bin/cat `find ${D} -name "perllocal.pod"`  \
         | /bin/sed -e s+${D}++g                 \
         > ${D}/var/adm/perl-modules/perl-WWW-Curl
 fi
 
 # remove special files
 find ${D} -name "perllocal.pod" \
     -o -name ".packlist"                \
     -o -name "*.bs"                     \
     |xargs -i rm -f {}
 
 # no empty directories
 find ${D}/usr             \
     -type d -depth                      \
     -exec rmdir {} \; 2>/dev/null
 
 /bin/perl -MFile::Find -le '
     find({ wanted => \&wanted, no_chdir => 1}, "${D}");
     print "%doc  README.Win32 template inc Changes README LICENSE";
     for my $x (sort @dirs, @files) {
         push @ret, $x unless indirs($x);
         }
     print join "\n", sort @ret;
 
     sub wanted {
         return if /auto$/;
 
         local $_ = $File::Find::name;
         my $f = $_; s|^\Q${D}\E||;
         return unless length;
         return $files[@files] = $_ if -f $f;
 
         $d = $_;
         /\Q$d\E/ && return for reverse sort @INC;
         $d =~ /\Q$_\E/ && return
             for qw|/etc /usr/man /usr/bin /usr/share|;
 
         $dirs[@dirs] = $_;
         }
 
     sub indirs {
         my $x = shift;
         $x =~ /^\Q$_\E\// && $x ne $_ && return 1 for @dirs;
         }
     ' > WWW-Curl-4.05-filelist
 
 [ -z WWW-Curl-4.05-filelist ] && {
     echo "ERROR: empty %files listing"
     exit -1
     }
 
 
}

PACKAGES = ""
PACKAGES += ""

_files = ""

FILES_${PN} = "${_files}"

PKG_= ""

require perl-WWW-Curl-extraconf.inc
