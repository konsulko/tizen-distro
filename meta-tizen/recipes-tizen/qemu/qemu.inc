DESCRIPTION = "Universal CPU emulator"
HOMEPAGE = "http://www.qemu.org/"
SECTION = "System/Utilities"
LICENSE = "BSD-3-Clause and GPL-2.0 and GPL-2.0+ and LGPL-2.1+ and MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by qemu-tools 
PROVIDES += "qemu-tools"
RPROVIDES_qemu-tools += "qemu-tools"
# the PROVIDES rules is ignore "qemu:/usr/libexec/qemu-bridge-helper  "
PROVIDES += "qemu:/usr/libexec/qemu-bridge-helper"
RPROVIDES_qemu-tools += "qemu:/usr/libexec/qemu-bridge-helper"

#PROVIDES by qemu-linux-user 
PROVIDES += "qemu-linux-user"
RPROVIDES_qemu-linux-user += "qemu-linux-user"
# the PROVIDES rules is ignore "qemu:/usr/bin/qemu-arm  "
PROVIDES += "qemu:/usr/bin/qemu-arm"
RPROVIDES_qemu-linux-user += "qemu:/usr/bin/qemu-arm"

#PROVIDES by qemu 
PROVIDES += "qemu"
RPROVIDES_qemu += "qemu"

#PROVIDES by qemu-guest-agent 
PROVIDES += "qemu-guest-agent"
RPROVIDES_qemu-guest-agent += "qemu-guest-agent"
# the PROVIDES rules is ignore "qemu:/usr/bin/qemu-ga  "
PROVIDES += "qemu:/usr/bin/qemu-ga"
RPROVIDES_qemu-guest-agent += "qemu:/usr/bin/qemu-ga"

RDEPENDS = ""
#RDEPENDS of qemu (${PN})
RDEPENDS_${PN} += "timezone"
RDEPENDS_${PN} += "pwdutils"
RDEPENDS_${PN} += "/usr/sbin/groupadd"


DEPENDS = ""
#DEPENDS of qemu 
DEPENDS += "glib"
DEPENDS += "bison-native"
DEPENDS += "zlib-devel-static"
DEPENDS += "attr"
DEPENDS += "SDL"
DEPENDS += "ncurses"
DEPENDS += "libjpeg-turbo"
DEPENDS += "pwdutils"
DEPENDS += "e2fsprogs"
inherit pythonnative
DEPENDS += "libcap-ng"
DEPENDS += "gnutls"
DEPENDS += "libpng"
DEPENDS += "libcap"
DEPENDS += "curl"
DEPENDS += "fdupes-native"
DEPENDS += "pcre"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n qemu-1.6.0
 
 
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
 
 # build QEMU
 mkdir -p dynamic
 # build qemu-system
 ./configure --prefix=/usr \
 	--sysconfdir=/etc \
 	--libexecdir=/usr/libexec \
 	--enable-curl \
 	--enable-virtfs \
 	--disable-linux-aio \
 	--extra-cflags="$QEMU_OPT_FLAGS" \
 	--enable-system \
 	--disable-linux-user \
 	--enable-sdl
 
 make -j16 V=1
 mv *-softmmu/qemu-system-* dynamic
 mv qemu-io qemu-img qemu-nbd qemu-bridge-helper dynamic
 #mv qemu-img.1 qemu-nbd.8 dynamic
 mv qemu-ga dynamic
 mv fsdev/virtfs-proxy-helper dynamic
 make clean
 # build userland emus
 ./configure --prefix=/usr --sysconfdir=/etc \
 	--libexecdir=/usr/libexec \
 	--enable-linux-user \
 	--disable-system \
 	--static --disable-linux-aio \
 	--extra-cflags="$QEMU_OPT_FLAGS"
 make -j16 V=1
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR=$RPM_BUILD_ROOT
 rm -fr $RPM_BUILD_ROOT//usr/share/doc
 install -m 755 dynamic/qemu-system-* $RPM_BUILD_ROOT//usr/bin
 install -m 755 dynamic/qemu-io $RPM_BUILD_ROOT//usr/bin
 install -m 755 dynamic/qemu-img $RPM_BUILD_ROOT//usr/bin
 install -m 755 dynamic/qemu-nbd $RPM_BUILD_ROOT//usr/bin
 install -m 755 dynamic/qemu-ga $RPM_BUILD_ROOT//usr/bin
 install -m 755 dynamic/virtfs-proxy-helper $RPM_BUILD_ROOT//usr/bin
 install -d -m 755 $RPM_BUILD_ROOT//usr/sbin
 install -m 755 scripts/qemu-binfmt-conf.sh $RPM_BUILD_ROOT//usr/sbin
 install -d -m 755 $RPM_BUILD_ROOT//usr/libexec
 install -m 755 dynamic/qemu-bridge-helper $RPM_BUILD_ROOT//usr/libexec
 install -d -m 755 $RPM_BUILD_ROOT//usr/share/man/man1
 install -D -m 644 ${S}/packaging/bridge.conf $RPM_BUILD_ROOT//etc/qemu/bridge.conf
 mkdir -p $RPM_BUILD_ROOT/emul/ia32-linux
 
  _target=""; 
  _symlinks=0; 
  _symlinks=1; 
  fdupes -q -n -r $RPM_BUILD_ROOT | 
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
PACKAGES += "qemu-tools"
PACKAGES += "qemu-linux-user"
PACKAGES += "qemu"
PACKAGES += "qemu-guest-agent"

qemu-tools_files = ""
qemu-tools_files += "/usr/bin/qemu-io"
qemu-tools_files += "/usr/bin/qemu-img"
qemu-tools_files += "/usr/bin/qemu-nbd"
qemu-tools_files += "/usr/bin/virtfs-proxy-helper"
qemu-tools_files += "/etc/qemu"
qemu-tools_files += "/etc/qemu/bridge.conf"

qemu-linux-user_files = ""
qemu-linux-user_files += "/usr/bin/qemu-alpha"
qemu-linux-user_files += "/usr/bin/qemu-arm"
qemu-linux-user_files += "/usr/bin/qemu-armeb"
qemu-linux-user_files += "/usr/bin/qemu-cris"
qemu-linux-user_files += "/usr/bin/qemu-i386"
qemu-linux-user_files += "/usr/bin/qemu-m68k"
qemu-linux-user_files += "/usr/bin/qemu-microblaze"
qemu-linux-user_files += "/usr/bin/qemu-microblazeel"
qemu-linux-user_files += "/usr/bin/qemu-mips"
qemu-linux-user_files += "/usr/bin/qemu-mips64"
qemu-linux-user_files += "/usr/bin/qemu-mips64el"
qemu-linux-user_files += "/usr/bin/qemu-mipsel"
qemu-linux-user_files += "/usr/bin/qemu-mipsn32"
qemu-linux-user_files += "/usr/bin/qemu-mipsn32el"
qemu-linux-user_files += "/usr/bin/qemu-or32"
qemu-linux-user_files += "/usr/bin/qemu-ppc64abi32"
qemu-linux-user_files += "/usr/bin/qemu-ppc64"
qemu-linux-user_files += "/usr/bin/qemu-ppc"
qemu-linux-user_files += "/usr/bin/qemu-s390x"
qemu-linux-user_files += "/usr/bin/qemu-sh4"
qemu-linux-user_files += "/usr/bin/qemu-sh4eb"
qemu-linux-user_files += "/usr/bin/qemu-sparc32plus"
qemu-linux-user_files += "/usr/bin/qemu-sparc64"
qemu-linux-user_files += "/usr/bin/qemu-sparc"
qemu-linux-user_files += "/usr/bin/qemu-unicore32"
qemu-linux-user_files += "/usr/bin/qemu-x86_64"
qemu-linux-user_files += "/usr/bin/qemu-*-binfmt"
qemu-linux-user_files += "/usr/sbin/qemu-binfmt-conf.sh"

qemu_files = ""
qemu_files += "COPYING COPYING.LIB Changelog README VERSION"
qemu_files += "/usr/bin/qemu-system-*"
qemu_files += "/usr/share/qemu"
qemu_files += "/etc/qemu"
qemu_files += "/etc/qemu/target-x86_64.conf"

qemu-guest-agent_files = ""

FILES_${PN}-tools = "${qemu-tools_files}"
FILES_${PN}-linux-user = "${qemu-linux-user_files}"
FILES_${PN} = "${qemu_files}"
FILES_${PN}-guest-agent = "${qemu-guest-agent_files}"

PKG_qemu-tools= "qemu-tools"
PKG_qemu-linux-user= "qemu-linux-user"
PKG_qemu= "qemu"
PKG_qemu-guest-agent= "qemu-guest-agent"

require qemu-extraconf.inc
