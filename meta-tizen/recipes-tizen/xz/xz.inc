DESCRIPTION = "A Program for Compressing Files"
HOMEPAGE = "http://tukaani.org/lzma/"
SECTION = "Base/Tools"
LICENSE = "LGPL-2.1+ and GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by xz 
PROVIDES += "xz"
RPROVIDES_xz += "xz"
# the PROVIDES rules is ignore "lzma = 5.0.3"
PROVIDES += "lzma"
RPROVIDES_xz += "lzma"

#PROVIDES by xz-locale  
PROVIDES += "xz-locale "
RPROVIDES_xz-locale  += "xz-locale "
# the PROVIDES rules is ignore "xz-lang-all = 5.0.3"
PROVIDES += "xz-lang-all"
RPROVIDES_xz-locale  += "xz-lang-all"

#PROVIDES by liblzma 
PROVIDES += "liblzma"
RPROVIDES_liblzma += "liblzma"

#PROVIDES by xz-devel 
PROVIDES += "xz-devel"
RPROVIDES_xz-devel += "xz-devel"
RPROVIDES_xz-devel += "xz-dev"
# the PROVIDES rules is ignore "lzma-devel = 5.0.3"
PROVIDES += "lzma-devel"
RPROVIDES_xz-devel += "lzma-devel"
RPROVIDES_xz-devel += "lzma-dev"
# the PROVIDES rules is ignore "lzma-alpha-devel = 5.0.3"
PROVIDES += "lzma-alpha-devel"
RPROVIDES_xz-devel += "lzma-alpha-devel"
RPROVIDES_xz-devel += "lzma-alpha-dev"

#PROVIDES by xz-docs  
PROVIDES += "xz-docs "
RPROVIDES_xz-docs  += "xz-docs "

RDEPENDS = ""
#RDEPENDS of xz-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "xz"

#RDEPENDS of xz-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "liblzma"


DEPENDS = ""
#DEPENDS of xz 

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/xz.manifest .
 
 
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
         --infodir=/usr/share/info --disable-static --with-pic --docdir=/usr/share/doc/packages/xz
 make -j16
 
 exit 0
 time make check
 
 
 
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
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} xz
 
 
}

PACKAGES = ""
PACKAGES += "xz-locale"
PACKAGES += "xz"
PACKAGES += "liblzma"
PACKAGES += "xz-devel"
PACKAGES += "xz-docs"

xz-locale_files = ""

xz_files = ""
xz_files += "xz.manifest"
xz_files += "/usr/share/doc/packages/xz"
xz_files += "/usr/bin/*"

liblzma_files = ""
liblzma_files += "xz.manifest"
liblzma_files += "/usr/lib/lib*.so.5*"

xz-devel_files = ""
xz-devel_files += "xz.manifest"
xz-devel_files += "/usr/include/*.h"
xz-devel_files += "/usr/include/lzma"
xz-devel_files += "/usr/lib/lib*.so"
xz-devel_files += "/usr/lib/pkgconfig/*.pc"

xz-docs_files = ""
xz-docs_files += "/usr/share/info"
xz-docs_files += "/usr/share/man"

FILES_${PN}-locale = "${xz-locale_files}"
FILES_${PN} = "${xz_files}"
FILES_liblzma = "${liblzma_files}"
FILES_${PN}-devel = "${xz-devel_files}"
FILES_${PN}-docs = "${xz-docs_files}"

PKG_xz-locale= "xz-locale"
PKG_xz= "xz"
PKG_liblzma= "liblzma"
PKG_xz-devel= "xz-devel"
PKG_xz-docs= "xz-docs"

require xz-extraconf.inc
