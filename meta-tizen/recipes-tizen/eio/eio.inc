DESCRIPTION = "Enlightenment Input/Output Library"
HOMEPAGE = "http://www.enlightenment.org/"
SECTION = "Graphics/EFL"
LICENSE = "BSD 3-clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by eio-devel 
PROVIDES += "eio-devel"
RPROVIDES_eio-devel += "eio-devel"
RPROVIDES_eio-devel += "eio-dev"

#PROVIDES by eio 
PROVIDES += "eio"
RPROVIDES_eio += "eio"

RDEPENDS = ""
#RDEPENDS of eio-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "eio"


DEPENDS = ""
#DEPENDS of eio 
DEPENDS += "ecore"
DEPENDS += "doxygen"
DEPENDS += "pkgconfig(eina)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/eio.manifest .
 
 
 
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
PACKAGES += "eio-devel"
PACKAGES += "eio"

eio-devel_files = ""
eio-devel_files += "eio.manifest"
eio-devel_files += "/usr/include/eio-1/*"
eio-devel_files += "/usr/lib/*.so"
eio-devel_files += "/usr/lib/pkgconfig/*"

eio_files = ""
eio_files += "eio.manifest"
eio_files += "/usr/lib/*.so.*"

FILES_${PN}-devel = "${eio-devel_files}"
FILES_${PN} = "${eio_files}"

PKG_eio-devel= "eio-devel"
PKG_eio= "eio"

require eio-extraconf.inc
