DESCRIPTION = "Complex Graphical Design/Layout Engine"
HOMEPAGE = "http://www.enlightenment.org/"
SECTION = "Graphics/EFL"
LICENSE = "BSD 2-clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by edje 
PROVIDES += "edje"
RPROVIDES_edje += "edje"

#PROVIDES by edje-devel 
PROVIDES += "edje-devel"
RPROVIDES_edje-devel += "edje-devel"
RPROVIDES_edje-devel += "edje-dev"

#PROVIDES by edje-tools 
PROVIDES += "edje-tools"
RPROVIDES_edje-tools += "edje-tools"
# the PROVIDES rules is ignore "edje-bin  "
PROVIDES += "edje-bin"
RPROVIDES_edje-tools += "edje-bin"

RDEPENDS = ""
#RDEPENDS of edje-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "edje-tools"

#RDEPENDS of edje-tools (${PN}-tools)
RDEPENDS_${PN}-tools += "edje"


DEPENDS = ""
#DEPENDS of edje 
DEPENDS += "doxygen"
DEPENDS += "pkgconfig(evas)"
DEPENDS += "python-devel"
DEPENDS += "pkgconfig(ecore-evas)"
DEPENDS += "pkgconfig(eet)"
DEPENDS += "pkgconfig(lua)"
DEPENDS += "pkgconfig(ecore-imf-evas)"
DEPENDS += "pkgconfig(ecore-imf)"
DEPENDS += "pkgconfig(ecore-file)"
DEPENDS += "ecore"
DEPENDS += "pkgconfig(eina)"
DEPENDS += "pkgconfig(embryo)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/edje.manifest .
 
 
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
PACKAGES += "edje"
PACKAGES += "edje-devel"
PACKAGES += "edje-tools"

edje_files = ""
edje_files += "edje.manifest"
edje_files += "/usr/lib/*.so.*"
edje_files += "/usr/lib/edje/*"
edje_files += "/usr/share/edje/include/edje.inc"
edje_files += "/usr/share/mime/packages/edje.xml"
edje_files += "/usr/bin/inkscape2edc"

edje-devel_files = ""
edje-devel_files += "edje.manifest"
edje-devel_files += "/usr/include/edje-1/*.h"
edje-devel_files += "/usr/lib/*.so"
edje-devel_files += "/usr/lib/pkgconfig/*.pc"
edje-devel_files += "/usr/share/edje/examples/*"

edje-tools_files = ""
edje-tools_files += "edje.manifest"
edje-tools_files += "/usr/bin/edje*"

FILES_${PN} = "${edje_files}"
FILES_${PN}-devel = "${edje-devel_files}"
FILES_${PN}-tools = "${edje-tools_files}"

PKG_edje= "edje"
PKG_edje-devel= "edje-devel"
PKG_edje-tools= "edje-tools"

require edje-extraconf.inc
