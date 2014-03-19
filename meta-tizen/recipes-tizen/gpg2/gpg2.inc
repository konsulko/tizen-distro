DESCRIPTION = "GnuPG 2"
HOMEPAGE = "http://www.gnupg.org/aegypten2/"
SECTION = "Security/Certificate Management"
LICENSE = "GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gpg2 
PROVIDES += "gpg2"
RPROVIDES_gpg2 += "gpg2"
# the PROVIDES rules is ignore "gnupg = 2.0.19"
PROVIDES += "gnupg"
RPROVIDES_gpg2 += "gnupg"
# the PROVIDES rules is ignore "gpg = 1.4.9"
PROVIDES += "gpg"
RPROVIDES_gpg2 += "gpg"
# the PROVIDES rules is ignore "newpg  "
PROVIDES += "newpg"
RPROVIDES_gpg2 += "newpg"
# the PROVIDES rules is ignore "gpg2_signd_support  "
PROVIDES += "gpg2_signd_support"
RPROVIDES_gpg2 += "gpg2_signd_support"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of gpg2 
DEPENDS += "zlib-devel"
DEPENDS += "libpth-devel"
DEPENDS += "readline-devel"
DEPENDS += "adns"
DEPENDS += "libgpg-error-devel"
DEPENDS += "libksba-devel"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "automake-native"
DEPENDS += "pkgconfig(libusb-1.0)"
DEPENDS += "expect"
DEPENDS += "libgcrypt-devel"
DEPENDS += "curl"
DEPENDS += "fdupes-native"
DEPENDS += "libassuan-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup  -q -n gnupg-2.0.19
 cp ${S}/packaging/gpg2.manifest .
 
 
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
 
 autoreconf -fi
 # build PIEs (position independent executables) for address space randomisation:
 PIE="-fpie"
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables ${PIE}"
 export LDFLAGS=-pie
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=x86_64-tizen-linux \
         --program-prefix= \
         --prefix=/usr \
         --exec-prefix=/usr \
         --bindir=/usr/bin \
         --sbindir=/usr/sbin \
         --sysconfdir=/etc \
         --datadir=/usr/share \
         --includedir=/usr/include \
         --libdir=/usr/lib \
         --libexecdir=/usr/libexec \
         --localstatedir=/var \
         --sharedstatedir=/usr/com \
         --mandir=/usr/share/man \
         --infodir=/usr/share/info \
     --libexecdir=/usr/lib \
     --docdir=/usr/share/doc/packages/gpg2 \
     --with-agent-pgm=/usr/bin/gpg-agent \
     --with-scdaemon-pgm=/usr/bin/scdaemon \
     --enable-gpgsm=yes \
     --enable-gpg \
     --with-gnu-ld
 
 make -j16
 
 exit 0
 make check
 ${D}/usr/bin/gpgsplit -v -p pubsplit-                    --uncompress <tests/openpgp/pubring.gpg
 ${D}/usr/bin/gpgsplit -v -p secsplit- --secret-to-public --uncompress <tests/openpgp/secring.gpg
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 mkdir -p ${D}/etc/gnupg/
 
 install -m 644 doc/examples/gpgconf.conf ${D}/etc/gnupg
 
 rm -rf ${D}/usr/share/doc/packages/gpg2/examples/gpgconf.conf
 
 ln -sf gpg2 ${D}/usr/bin/gpg
 ln -sf gpgv2 ${D}/usr/bin/gpgv
 ln -sf gpg2.1 ${D}/usr/share/man/man1/gpg.1
 ln -sf gpgv2.1 ${D}/usr/share/man/man1/gpgv.1
 
 rm -rf ${D}//usr/share/locale/en@{bold,}quot
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} gnupg2
 
 
  _target=""; 
  _symlinks=0; 
   
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
PACKAGES += "gpg2"

gpg2_files = ""
gpg2_files += "gpg2.manifest"
gpg2_files += "/usr/share/info/gnupg*"
gpg2_files += "/usr/share/doc/packages/gpg2"
gpg2_files += "/usr/share/man/man*/*"
gpg2_files += "/usr/bin/*"
gpg2_files += "/usr/lib/[^d]*"
gpg2_files += "/usr/sbin/addgnupghome"
gpg2_files += "/usr/sbin/applygnupgdefaults"
gpg2_files += "/usr/share/gnupg"
gpg2_files += "/etc/gnupg"
gpg2_files += "/etc/gnupg/gpgconf.conf"

FILES_${PN} = "${gpg2_files}"

PKG_gpg2= "gpg2"

require gpg2-extraconf.inc
