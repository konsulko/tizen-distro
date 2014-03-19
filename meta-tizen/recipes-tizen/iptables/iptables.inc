DESCRIPTION = "IP Packet Filter Administration utilities"
HOMEPAGE = "http://netfilter.org/"
SECTION = "Security/Network"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by iptables 
PROVIDES += "iptables"
RPROVIDES_iptables += "iptables"

#PROVIDES by libxtables-devel 
PROVIDES += "libxtables-devel"
RPROVIDES_libxtables-devel += "libxtables-devel"
RPROVIDES_libxtables-devel += "libxtables-dev"

#PROVIDES by libxtables 
PROVIDES += "libxtables"
RPROVIDES_libxtables += "libxtables"

#PROVIDES by iptables-docs  
PROVIDES += "iptables-docs "
RPROVIDES_iptables-docs  += "iptables-docs "

#PROVIDES by libipq 
PROVIDES += "libipq"
RPROVIDES_libipq += "libipq"

#PROVIDES by libiptc 
PROVIDES += "libiptc"
RPROVIDES_libiptc += "libiptc"

#PROVIDES by libiptc-devel 
PROVIDES += "libiptc-devel"
RPROVIDES_libiptc-devel += "libiptc-devel"
RPROVIDES_libiptc-devel += "libiptc-dev"

#PROVIDES by libipq-devel 
PROVIDES += "libipq-devel"
RPROVIDES_libipq-devel += "libipq-devel"
RPROVIDES_libipq-devel += "libipq-dev"

#PROVIDES by xtables-plugins 
PROVIDES += "xtables-plugins"
RPROVIDES_xtables-plugins += "xtables-plugins"

RDEPENDS = ""
#RDEPENDS of libxtables-devel (libxtables-devel)
RDEPENDS_libxtables-devel += "libxtables"

#RDEPENDS of libiptc-devel (libiptc-devel)
RDEPENDS_libiptc-devel += "libiptc"

#RDEPENDS of libipq-devel (libipq-devel)
RDEPENDS_libipq-devel += "libipq"


DEPENDS = ""
#DEPENDS of iptables 
DEPENDS += "pkgconfig(libnfnetlink)"
DEPENDS += "fdupes-native"
DEPENDS += "libtool-cross"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/iptables.manifest .
 
 
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
 
 # bnc#561793 - do not include unclean module in iptables manpage
 rm -f extensions/libipt_unclean.man
 # includedir is overriden on purpose to detect projects that
 # fail to include libxtables_CFLAGS
 
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
         --infodir=/usr/share/info --includedir=/usr/include/iptables-1.4.19.1 --enable-libipq
 make -j16
 
 
 
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
 # iptables-apply is not installed by upstream Makefile
 install -m0755 iptables/iptables-apply ${D}/usr/sbin/
 install -m0644 iptables/iptables-apply.8 ${D}/usr/share/man/man8/
 rm -f "${D}//usr/lib"/*.la;
 
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
PACKAGES += "iptables"
PACKAGES += "libxtables-devel"
PACKAGES += "libxtables"
PACKAGES += "libipq"
PACKAGES += "libiptc"
PACKAGES += "iptables-docs"
PACKAGES += "libiptc-devel"
PACKAGES += "libipq-devel"
PACKAGES += "xtables-plugins"

iptables_files = ""
iptables_files += "iptables.manifest"
iptables_files += "/usr/bin/iptables*"
iptables_files += "/usr/sbin/iptables*"
iptables_files += "/usr/sbin/ip6tables*"
iptables_files += "/usr/sbin/xtables*"
iptables_files += "/usr/sbin/nfnl_osf"
iptables_files += "/usr/lib/xtables"
iptables_files += "/usr/share/xtables"

libxtables-devel_files = ""
libxtables-devel_files += "iptables.manifest"
libxtables-devel_files += "/usr/include/iptables-1.4.19.1"
libxtables-devel_files += "/usr/include/iptables-1.4.19.1/xtables.h"
libxtables-devel_files += "/usr/include/iptables-1.4.19.1/xtables-version.h"
libxtables-devel_files += "/usr/lib/libxtables.so"
libxtables-devel_files += "/usr/lib/pkgconfig/xtables.pc"

libxtables_files = ""
libxtables_files += "iptables.manifest"
libxtables_files += "/usr/lib/libxtables.so.*"

libipq_files = ""
libipq_files += "iptables.manifest"
libipq_files += "/usr/lib/libipq.so.0*"

libiptc_files = ""
libiptc_files += "iptables.manifest"
libiptc_files += "/usr/lib/libiptc.so.0*"
libiptc_files += "/usr/lib/libip4tc.so.0*"
libiptc_files += "/usr/lib/libip6tc.so.0*"

iptables-docs_files = ""
iptables-docs_files += "/usr/share/info"
iptables-docs_files += "/usr/share/man"

libiptc-devel_files = ""
libiptc-devel_files += "iptables.manifest"
libiptc-devel_files += "/usr/include/iptables-1.4.19.1"
libiptc-devel_files += "/usr/include/iptables-1.4.19.1/libiptc*"
libiptc-devel_files += "/usr/lib/libip*tc.so"
libiptc-devel_files += "/usr/lib/pkgconfig/libip*tc.pc"

libipq-devel_files = ""
libipq-devel_files += "iptables.manifest"
libipq-devel_files += "/usr/include/iptables-1.4.19.1"
libipq-devel_files += "/usr/include/iptables-1.4.19.1/libipq*"
libipq-devel_files += "/usr/lib/libipq.so"
libipq-devel_files += "/usr/lib/pkgconfig/libipq.pc"

xtables-plugins_files = ""
xtables-plugins_files += "/etc/xtables/"
xtables-plugins_files += "/etc/xtables/*.conf"
xtables-plugins_files += "/usr/lib/xtables/"
xtables-plugins_files += "/usr/sbin/nfnl_osf"
xtables-plugins_files += "/usr/share/xtables/"

FILES_${PN} = "${iptables_files}"
FILES_libxtables-devel = "${libxtables-devel_files}"
FILES_libxtables = "${libxtables_files}"
FILES_libipq = "${libipq_files}"
FILES_libiptc = "${libiptc_files}"
FILES_${PN}-docs = "${iptables-docs_files}"
FILES_libiptc-devel = "${libiptc-devel_files}"
FILES_libipq-devel = "${libipq-devel_files}"
FILES_xtables-plugins = "${xtables-plugins_files}"

PKG_iptables= "iptables"
PKG_libxtables-devel= "libxtables-devel"
PKG_libxtables= "libxtables"
PKG_libipq= "libipq"
PKG_libiptc= "libiptc"
PKG_iptables-docs= "iptables-docs"
PKG_libiptc-devel= "libiptc-devel"
PKG_libipq-devel= "libipq-devel"
PKG_xtables-plugins= "xtables-plugins"

require iptables-extraconf.inc
