DESCRIPTION = "Library for Crypto UI related task"
HOMEPAGE = "http://www.gnome.org"
SECTION = "Security/Crypto Libraries"
LICENSE = "LGPL-2.1+"
PV = "3.8.2"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by typelib-Gcr
PROVIDES += "typelib-Gcr"


#PROVIDES by libgcr
PROVIDES += "libgcr"


#PROVIDES by libgcr-dev
PROVIDES += "libgcr-dev"


#PROVIDES by gcr


#PROVIDES by typelib-Gck
PROVIDES += "typelib-Gck"


#PROVIDES by libgck
PROVIDES += "libgck"
# the PROVIDES rules is ignore "gck = 3.8.2"
PROVIDES += "gck"
RPROVIDES_libgck += "gck"


#PROVIDES by gcr-data
PROVIDES += "gcr-data"


#PROVIDES by libgck-dev
PROVIDES += "libgck-dev"


RDEPENDS = ""
#RDEPENDS of libgcr (lib${PN})
RDEPENDS_lib${PN} += "gcr-data"

#RDEPENDS of libgcr-dev (lib${PN}-dev)
RDEPENDS_lib${PN}-dev += "typelib-Gcr"
RDEPENDS_lib${PN}-dev += "libgcr"

#RDEPENDS of gcr-data (${PN}-data)
RDEPENDS_${PN}-data += "glib-2.0"

#RDEPENDS of libgck-dev (libgck-dev)
RDEPENDS_libgck-dev += "typelib-Gck"
RDEPENDS_libgck-dev += "libgck"


DEPENDS = ""
#DEPENDS of gcr
DEPENDS += "shared-mime-info"
DEPENDS_append_class-native = " intltool-native"
DEPENDS_append_class-target = " intltool-native"
DEPENDS += "p11-kit"
DEPENDS += "gnome-common"
DEPENDS += "dbus"
DEPENDS += "libtasn1"
inherit pkgconfig
DEPENDS += "gpg2"
DEPENDS += "glib-2.0"
DEPENDS += "update-desktop-files"
DEPENDS += "gtk-doc-stub"
DEPENDS += "libgcrypt"
DEPENDS += "gtk-doc"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
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
  
  
  
   
  autotools_do_configure
  
  make
  
  
  
}
EXTRA_OECONF += " --with-gtk=no --disable-gtk-doc-html"

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
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 #find_lang gcr
 
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    %glib2_gsettings_schema_post
    %icon_theme_cache_post

}

pkg_postinst_libgcr() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_libgck() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_libgcr() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_libgck() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    %glib2_gsettings_schema_postun
    %icon_theme_cache_postun

}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " typelib-Gcr "
PACKAGES += " libgcr "
PACKAGES += " libgcr-dev "
PACKAGES += " typelib-Gck "
PACKAGES += " libgck "
PACKAGES += " gcr-data "
PACKAGES += " libgck-dev "

typelib-Gcr_files = ""
typelib-Gcr_files += "${prefix}/lib/girepository-1.0/Gcr-3.typelib"

libgcr_files = ""
libgcr_files += "${prefix}/lib/libgcr-base-3.so.*"

libgcr-dev_files = ""
libgcr-dev_files += "${prefix}/lib/libgcr-base-3.so"
libgcr-dev_files += "${prefix}/lib/pkgconfig/gcr-base-3.pc"
libgcr-dev_files += "${prefix}/include/gcr-3/"

typelib-Gck_files = ""
typelib-Gck_files += "${prefix}/lib/girepository-1.0/Gck-1.typelib"

libgck_files = ""
libgck_files += "${prefix}/lib/libgck-1.so.*"

gcr-data_files = ""
gcr-data_files += "${prefix}/share/GConf"
gcr-data_files += "${prefix}/share/GConf/gsettings"
gcr-data_files += "${prefix}/share/GConf/gsettings/org.gnome.crypto.pgp.convert"
gcr-data_files += "${prefix}/share/GConf/gsettings/org.gnome.crypto.pgp_keyservers.convert"
gcr-data_files += "${prefix}/share/glib-2.0/schemas/org.gnome.crypto.pgp.gschema.xml"
DIRFILES_${PN}-data = ""
DIRFILES_${PN}-data += "${prefix}/share/GConf"
DIRFILES_${PN}-data += "${prefix}/share/GConf/gsettings"

libgck-dev_files = ""
libgck-dev_files += "${prefix}/lib/libgck-1.so"
libgck-dev_files += "${prefix}/lib/pkgconfig/gck-1.pc"
libgck-dev_files += "${prefix}/include/gck-1/"
libgck-dev_files += "${prefix}/share/gir-1.0/Gck-1.gir"
libgck-dev_files += "${prefix}/share/gir-1.0/Gcr-3.gir"

FILES_typelib-Gcr = "${typelib-Gcr_files}"
FILES_lib${PN} = "${libgcr_files}"
FILES_lib${PN}-dev = "${libgcr-dev_files}"
FILES_typelib-Gck = "${typelib-Gck_files}"
FILES_libgck = "${libgck_files}"
FILES_${PN}-data = "${gcr-data_files}"
FILES_libgck-dev = "${libgck-dev_files}"

PKG_typelib-Gcr= "typelib-Gcr"
PKG_libgcr= "libgcr"
PKG_libgcr-dev= "libgcr-dev"
PKG_typelib-Gck= "typelib-Gck"
PKG_libgck= "libgck"
PKG_gcr-data= "gcr-data"
PKG_libgck-dev= "libgck-dev"

require gcr-extraconf.inc

