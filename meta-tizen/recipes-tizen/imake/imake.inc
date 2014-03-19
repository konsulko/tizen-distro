DESCRIPTION = "C preprocessor interface to the make utility"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "Development/Tools/Building"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by imake-docs  
PROVIDES += "imake-docs "
RPROVIDES_imake-docs  += "imake-docs "

#PROVIDES by imake 
PROVIDES += "imake"
RPROVIDES_imake += "imake"

RDEPENDS = ""
#RDEPENDS of imake (${PN})
RDEPENDS_${PN} += "xorg-cf-files"


DEPENDS = ""
#DEPENDS of imake 
DEPENDS += "pkgconfig(xproto)"
DEPENDS += "pkgconfig-native"
DEPENDS += "pkgconfig(xorg-macros)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/imake.manifest .
 
 
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
         --infodir=/usr/share/info --with-config-dir=/usr/share/X11/config
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
PACKAGES += "imake-docs"
PACKAGES += "imake"

imake-docs_files = ""
imake-docs_files += "/usr/share/info"
imake-docs_files += "/usr/share/man"

imake_files = ""
imake_files += "imake.manifest"
imake_files += "COPYING README"
imake_files += "/usr/bin/ccmakedep"
imake_files += "/usr/bin/cleanlinks"
imake_files += "/usr/bin/imake"
imake_files += "/usr/bin/makeg"
imake_files += "/usr/bin/mergelib"
imake_files += "/usr/bin/mkdirhier"
imake_files += "/usr/bin/mkhtmlindex"
imake_files += "/usr/bin/revpath"
imake_files += "/usr/bin/xmkmf"

FILES_${PN}-docs = "${imake-docs_files}"
FILES_${PN} = "${imake_files}"

PKG_imake-docs= "imake-docs"
PKG_imake= "imake"

require imake-extraconf.inc
