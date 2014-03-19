DESCRIPTION = "GNU Unicode string library"
HOMEPAGE = "http://www.gnu.org/software/libunistring/"
SECTION = "Development/Libraries/C and C++"
LICENSE = "LGPL-3.0+ and GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libunistring-devel 
PROVIDES += "libunistring-devel"
RPROVIDES_libunistring-devel += "libunistring-devel"
RPROVIDES_libunistring-devel += "libunistring-dev"

#PROVIDES by libunistring 
PROVIDES += "libunistring"
RPROVIDES_libunistring += "libunistring"

RDEPENDS = ""
#RDEPENDS of libunistring-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "info"
RDEPENDS_${PN}-devel += "libunistring"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libunistring.manifest .
 
 
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
         --infodir=/usr/share/info --disable-static --disable-rpath --docdir=/usr/share/doc/packages/libunistring
 make -j16
 
 exit 0
 make check -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 echo " " > debugsources.list
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f -- DESTDIR=${D} INSTALL="install -p"
 rm -f ${D}//usr/share/info/dir
 rm -f ${D}//usr/lib/libunistring.la
 
 
 
   rm -rf ${D}/usr/share/info 
   rm -rf ${D}/usr/share/doc/packages 
   rm -rf ${D}/usr/share/doc/libunistring 
   rm -rf ${D}/usr/share/doc/libunistring-0.9.3 
   rm -rf ${D}/usr/share/gtk-doc 
   rm -rf ${D}/usr/share/doc 
   rm -rf ${D}/usr/share/man 
   find ${D} -regex ".*/man/man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/../man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/man./.*.[0-9]pm" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "libunistring-devel"
PACKAGES += "libunistring"

libunistring-devel_files = ""
libunistring-devel_files += "libunistring.manifest"
libunistring-devel_files += "/usr/lib/libunistring.so"
libunistring-devel_files += "/usr/include/unistring"
libunistring-devel_files += "/usr/include/*.h"

libunistring_files = ""
libunistring_files += "libunistring.manifest"
libunistring_files += "/usr/lib/libunistring.so.0*"

FILES_${PN}-devel = "${libunistring-devel_files}"
FILES_${PN} = "${libunistring_files}"

PKG_libunistring-devel= "libunistring-devel"
PKG_libunistring= "libunistring"

require libunistring-extraconf.inc
