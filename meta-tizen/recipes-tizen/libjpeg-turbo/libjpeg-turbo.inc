DESCRIPTION = "A MMX/SSE2 accelerated library for manipulating JPEG image files"
HOMEPAGE = "http://sourceforge.net/projects/libjpeg-turbo"
SECTION = "Graphics & UI Framework/Libraries"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by libjpeg
PROVIDES += "libjpeg"
# the PROVIDES rules is ignore "libjpeg = 8.0.2"
# the PROVIDES rules is ignore "libjpeg8  "
PROVIDES += "libjpeg8"
RPROVIDES_libjpeg += "libjpeg8"


#PROVIDES by libjpeg-turbo


#PROVIDES by libjpeg-dev
PROVIDES += "libjpeg-dev"
# the PROVIDES rules is ignore "libjpeg-turbo-dev  "
PROVIDES += "libjpeg-turbo-dev"
RPROVIDES_libjpeg-dev += "libjpeg-turbo-dev"
# the PROVIDES rules is ignore "libjpeg-dev = 8.0.2"
# the PROVIDES rules is ignore "libjpeg8-dev  "
PROVIDES += "libjpeg8-dev"
RPROVIDES_libjpeg-dev += "libjpeg8-dev"


#PROVIDES by libjpeg-turbo-docs
PROVIDES += "libjpeg-turbo-docs "


RDEPENDS = ""
#RDEPENDS of libjpeg-dev (libjpeg-dev)
RDEPENDS_libjpeg-dev += "libjpeg"


DEPENDS = ""
#DEPENDS of libjpeg-turbo
DEPENDS_append_class-native = " libtool"
DEPENDS_append_class-target = " libtool-cross"
DEPENDS += "yasm"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libjpeg-turbo.manifest .
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
  LANG=C
  export LANG
  unset DISPLAY
  LD_AS_NEEDED=1; export LD_AS_NEEDED ;
  
  autoreconf -fiv
  
  autotools_do_configure
  make -j16
  
  exit 0
  make test libdir=${prefix}/lib
  
  
  
}
EXTRA_OECONF += " --disable-static --with-jpeg8"

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 
   oe_runmake \
         DESTDIR=${D} \
         BINDIR=${prefix}/bin \
         prefix=${prefix} \
         exec_prefix=${prefix} \
         bindir=${prefix}/bin \
         sbindir=${prefix}/sbin \
         sysconfdir=${sysconfdir} \
         datadir=${prefix}/share \
         includedir=${prefix}/include \
         libdir=${prefix}/lib \
         libexecdir=${prefix}/libexec \
         localstatedir=}${localstatedir} \
         sharedstatedir=${prefix}/com \
         mandir=${mandir} \
         infodir=${infodir} \
   install
 
 # Fix perms
 chmod -x README-turbo.txt release/copyright
 
 # Remove unwanted files
 rm -f ${D}${prefix}/lib/lib{,turbo}jpeg.la
 
 rm ${D}${prefix}/bin/tjbench
 
 # Remove docs, we'll select docs manually
 rm -rf ${D}${prefix}/share/doc/
 
 
}

pkg_postinst_libjpeg() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_libjpeg() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " libjpeg "
PACKAGES += " libjpeg-turbo "
PACKAGES += " libjpeg-turbo-docs "
PACKAGES += " libjpeg-dev "

libjpeg_files = ""
libjpeg_files += "${prefix}/lib/libturbojpeg.so"
libjpeg_files += "${prefix}/lib/libjpeg.so.8.0.2"
libjpeg_files += "${prefix}/lib/libjpeg.so.8"
MANIFESTFILES_libjpeg = "libjpeg-turbo.manifest"

libjpeg-turbo_files = ""
libjpeg-turbo_files += "${prefix}/bin/*"
MANIFESTFILES_${PN} = "libjpeg-turbo.manifest"

libjpeg-turbo-docs_files = ""

libjpeg-dev_files = ""
libjpeg-dev_files += "${prefix}/include/*.h"
libjpeg-dev_files += "${prefix}/lib/libjpeg.so"
libjpeg-dev_files += "coderules.txt jconfig.txt libjpeg.txt structure.txt example.c"
MANIFESTFILES_libjpeg-dev = "libjpeg-turbo.manifest"

FILES_libjpeg = "${libjpeg_files}"
FILES_${PN} = "${libjpeg-turbo_files}"
FILES_${PN}-docs = "${libjpeg-turbo-docs_files}"
FILES_libjpeg-dev = "${libjpeg-dev_files}"

PKG_libjpeg= "libjpeg"
PKG_libjpeg-turbo= "libjpeg-turbo"
PKG_libjpeg-turbo-docs= "libjpeg-turbo-docs"
PKG_libjpeg-dev= "libjpeg-dev"

require libjpeg-turbo-extraconf.inc

