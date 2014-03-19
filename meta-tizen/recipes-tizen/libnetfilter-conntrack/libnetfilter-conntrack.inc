DESCRIPTION = "Userspace library for the in-kernel connection tracking state table"
HOMEPAGE = "http://netfilter.org/projects/libnetfilter_conntrack/"
SECTION = "Productivity/Networking/Security"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libnetfilter_conntrack 
PROVIDES += "libnetfilter_conntrack"
RPROVIDES_libnetfilter_conntrack += "libnetfilter_conntrack"

#PROVIDES by libnetfilter_conntrack-devel 
PROVIDES += "libnetfilter_conntrack-devel"
RPROVIDES_libnetfilter_conntrack-devel += "libnetfilter_conntrack-devel"
RPROVIDES_libnetfilter_conntrack-devel += "libnetfilter_conntrack-dev"

RDEPENDS = ""
#RDEPENDS of libnetfilter_conntrack-devel (libnetfilter_conntrack-devel)
RDEPENDS_libnetfilter_conntrack-devel += "libnetfilter_conntrack"


DEPENDS = ""
#DEPENDS of libnetfilter_conntrack 
DEPENDS += "pkgconfig(libnfnetlink)"
DEPENDS += "libmnl"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libnetfilter_conntrack.manifest .
 
 
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
 
 if [ "%git_snapshot" -ne 0 ] || [ ! -e configure ]; then
 	autoreconf -fi;
 fi;
 
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
         --infodir=/usr/share/info --disable-static --includedir="/usr/include/libnetfilter_conntrack-1.0.2"
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
 
 
}

PACKAGES = ""
PACKAGES += "libnetfilter_conntrack"
PACKAGES += "libnetfilter_conntrack-devel"

libnetfilter_conntrack_files = ""
libnetfilter_conntrack_files += "libnetfilter_conntrack.manifest"
libnetfilter_conntrack_files += "/usr/lib/libnetfilter_conntrack.so.3*"

libnetfilter_conntrack-devel_files = ""
libnetfilter_conntrack-devel_files += "libnetfilter_conntrack.manifest"
libnetfilter_conntrack-devel_files += "/usr/include/libnetfilter_conntrack-1.0.2"
libnetfilter_conntrack-devel_files += "/usr/lib/libnetfilter_conntrack.so"
libnetfilter_conntrack-devel_files += "/usr/lib/pkgconfig/libnetfilter_conntrack.pc"

FILES_${PN} = "${libnetfilter_conntrack_files}"
FILES_${PN}-devel = "${libnetfilter_conntrack-devel_files}"

PKG_libnetfilter_conntrack= "libnetfilter_conntrack"
PKG_libnetfilter_conntrack-devel= "libnetfilter_conntrack-devel"

require libnetfilter-conntrack-extraconf.inc
