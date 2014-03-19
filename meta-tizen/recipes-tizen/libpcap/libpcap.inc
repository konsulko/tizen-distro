DESCRIPTION = "A Library for Network Sniffers"
HOMEPAGE = "http://www.tcpdump.org/"
SECTION = "System/Libraries"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libpcap-docs  
PROVIDES += "libpcap-docs "
RPROVIDES_libpcap-docs  += "libpcap-docs "

#PROVIDES by libpcap-devel 
PROVIDES += "libpcap-devel"
RPROVIDES_libpcap-devel += "libpcap-devel"
RPROVIDES_libpcap-devel += "libpcap-dev"

#PROVIDES by libpcap 
PROVIDES += "libpcap"
RPROVIDES_libpcap += "libpcap"

RDEPENDS = ""
#RDEPENDS of libpcap-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libpcap"


DEPENDS = ""
#DEPENDS of libpcap 
DEPENDS += "libusb-devel"
DEPENDS += "flex"
DEPENDS += "bison-native"
DEPENDS += "automake-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libpcap.manifest .
 
 
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
 
 pic="pic"
 autoreconf -fiv
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -f$pic" CXXFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -f$pic"
 
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
   --enable-ipv6
 make -j16 all shared
 
 
 
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
   
 
 
 
}

PACKAGES = ""
PACKAGES += "libpcap-docs"
PACKAGES += "libpcap-devel"
PACKAGES += "libpcap"

libpcap-docs_files = ""
libpcap-docs_files += "/usr/share/info"
libpcap-docs_files += "/usr/share/man"

libpcap-devel_files = ""
libpcap-devel_files += "libpcap.manifest"
libpcap-devel_files += "/usr/include/*"
libpcap-devel_files += "/usr/bin/pcap-config"
libpcap-devel_files += "/usr/lib/*.so"
libpcap-devel_files += "/usr/lib/*.*a"

libpcap_files = ""
libpcap_files += "libpcap.manifest"
libpcap_files += "LICENSE"
libpcap_files += "/usr/lib/*.so.*"

FILES_${PN}-docs = "${libpcap-docs_files}"
FILES_${PN}-devel = "${libpcap-devel_files}"
FILES_${PN} = "${libpcap_files}"

PKG_libpcap-docs= "libpcap-docs"
PKG_libpcap-devel= "libpcap-devel"
PKG_libpcap= "libpcap"

require libpcap-extraconf.inc
