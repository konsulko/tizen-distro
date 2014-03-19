DESCRIPTION = "ISO code lists and translations"
HOMEPAGE = "http://alioth.debian.org/projects/pkg-isocodes/"
SECTION = "System/Base"
LICENSE = "LGPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by iso-codes-devel 
PROVIDES += "iso-codes-devel"
RPROVIDES_iso-codes-devel += "iso-codes-devel"
RPROVIDES_iso-codes-devel += "iso-codes-dev"

#PROVIDES by iso-codes 
PROVIDES += "iso-codes"
RPROVIDES_iso-codes += "iso-codes"

RDEPENDS = ""
#RDEPENDS of iso-codes-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "iso-codes"


DEPENDS = ""
#DEPENDS of iso-codes 
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
 
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
 
 cp ${S}/packaging/iso-codes.manifest .
 
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=noarch-tizen-linux \
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
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} iso-codes --all-name
 
 
}

PACKAGES = ""
PACKAGES += "iso-codes-devel"
PACKAGES += "iso-codes"

iso-codes-devel_files = ""
iso-codes-devel_files += "iso-codes.manifest"
iso-codes-devel_files += "/usr/share/pkgconfig/iso-codes.pc"

iso-codes_files = ""
iso-codes_files += "iso-codes.manifest"
iso-codes_files += "/usr/share/xml/iso-codes"
iso-codes_files += "/usr/share/xml/iso-codes/*.xml"

FILES_${PN}-devel = "${iso-codes-devel_files}"
FILES_${PN} = "${iso-codes_files}"

PKG_iso-codes-devel= "iso-codes-devel"
PKG_iso-codes= "iso-codes"

require iso-codes-extraconf.inc
