DESCRIPTION = "Free Implementation of BiDi Algorithm"
HOMEPAGE = "http://fribidi.org/"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by fribidi 
PROVIDES += "fribidi"
RPROVIDES_fribidi += "fribidi"
# the PROVIDES rules is ignore "locale(ar;he)  "
PROVIDES += "locale(ar;he)"
RPROVIDES_fribidi += "locale(ar;he)"

#PROVIDES by fribidi-devel 
PROVIDES += "fribidi-devel"
RPROVIDES_fribidi-devel += "fribidi-devel"
RPROVIDES_fribidi-devel += "fribidi-dev"

RDEPENDS = ""
#RDEPENDS of fribidi-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "fribidi"
RDEPENDS_${PN}-devel += "pkgconfig"


DEPENDS = ""
#DEPENDS of fribidi 
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/fribidi.manifest .
 
 
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
         --infodir=/usr/share/info --disable-static
 oe_runmake -j16
 
 exit 0
 oe_runmake check
 
 
 
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
PACKAGES += "fribidi"
PACKAGES += "fribidi-devel"

fribidi_files = ""
fribidi_files += "fribidi.manifest"
fribidi_files += "/usr/bin/fribidi"
fribidi_files += "/usr/lib/libfribidi.so.*"

fribidi-devel_files = ""
fribidi-devel_files += "fribidi.manifest"
fribidi-devel_files += "/usr/include/fribidi"
fribidi-devel_files += "/usr/include/fribidi/*"
fribidi-devel_files += "/usr/lib/libfribidi.so"
fribidi-devel_files += "/usr/lib/pkgconfig/fribidi.pc"
fribidi-devel_files += "/usr/share/man/man3/fribidi_*"

FILES_${PN} = "${fribidi_files}"
FILES_${PN}-devel = "${fribidi-devel_files}"

PKG_fribidi= "fribidi"
PKG_fribidi-devel= "fribidi-devel"

require fribidi-extraconf.inc
