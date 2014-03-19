DESCRIPTION = "Hangul input library used by scim-hangul and ibus-hangul"
HOMEPAGE = "http://code.google.com/p/libhangul"
SECTION = "System/I18n/Korean"
LICENSE = "LGPLv2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libhangul-devel 
PROVIDES += "libhangul-devel"
RPROVIDES_libhangul-devel += "libhangul-devel"
RPROVIDES_libhangul-devel += "libhangul-dev"

#PROVIDES by libhangul 
PROVIDES += "libhangul"
RPROVIDES_libhangul += "libhangul"

RDEPENDS = ""
#RDEPENDS of libhangul-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libhangul"


DEPENDS = ""
#DEPENDS of libhangul 
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libhangul.manifest .
 
 
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
   ./autogen.sh --build=${TARGET_SYS} --host=${HOST_SYS} \
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
         --infodir=/usr/share/info
 
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
         --infodir=/usr/share/info --disable-static --with-pic
 oe_runmake -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make DESTDIR=${RPM_BUILD_ROOT} install
 /bin/rm -f ${D}/usr/lib/*.la
 
 
}

PACKAGES = ""
PACKAGES += "libhangul-devel"
PACKAGES += "libhangul"

libhangul-devel_files = ""
libhangul-devel_files += "libhangul.manifest"
libhangul-devel_files += "/usr/include/hangul-1.0/"
libhangul-devel_files += "/usr/include/hangul-1.0/*"
libhangul-devel_files += "/usr/lib/lib*.so"
libhangul-devel_files += "/usr/lib/pkgconfig/libhangul.pc"

libhangul_files = ""
libhangul_files += "libhangul.manifest"
libhangul_files += "AUTHORS COPYING NEWS README ChangeLog"
libhangul_files += "/usr/lib/lib*.so.*"
libhangul_files += "/usr/share/libhangul/"
libhangul_files += "/usr/share/libhangul/hanja/"
libhangul_files += "/usr/share/libhangul/hanja/hanja.txt"
libhangul_files += "/usr/bin/hangul"
libhangul_files += "/usr/share/locale/ko/LC_MESSAGES/libhangul.mo"

FILES_${PN}-devel = "${libhangul-devel_files}"
FILES_${PN} = "${libhangul_files}"

PKG_libhangul-devel= "libhangul-devel"
PKG_libhangul= "libhangul"

require libhangul-extraconf.inc
