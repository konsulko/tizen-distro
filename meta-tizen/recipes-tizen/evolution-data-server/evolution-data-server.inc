DESCRIPTION = "Evolution Data Server"
HOMEPAGE = "http://www.gnome.org"
SECTION = "Development/Libraries"
LICENSE = "LGPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by typelib-EBook
PROVIDES += "typelib-EBook"


#PROVIDES by evolution-data-server


#PROVIDES by typelib-EDataServer
PROVIDES += "typelib-EDataServer"


#PROVIDES by libedataserver
PROVIDES += "libedataserver"


#PROVIDES by libecal
PROVIDES += "libecal"


#PROVIDES by libcamel
PROVIDES += "libcamel"


#PROVIDES by libedata-cal
PROVIDES += "libedata-cal"


#PROVIDES by libebook-contacts
PROVIDES += "libebook-contacts"


#PROVIDES by typelib-EBookContacts
PROVIDES += "typelib-EBookContacts"


#PROVIDES by libedata-book
PROVIDES += "libedata-book"


#PROVIDES by evolution-data-server-doc
PROVIDES += "evolution-data-server-doc"


#PROVIDES by libebook
PROVIDES += "libebook"


#PROVIDES by libebackend
PROVIDES += "libebackend"


#PROVIDES by evolution-data-server-dev
PROVIDES += "evolution-data-server-dev"


RDEPENDS = ""
#RDEPENDS of evolution-data-server (${PN})
RDEPENDS_${PN} += "glib-2.0"

#RDEPENDS of evolution-data-server-doc (${PN}-doc)
RDEPENDS_${PN}-doc += "evolution-data-server"

#RDEPENDS of evolution-data-server-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "typelib-EBook"
RDEPENDS_${PN}-dev += "evolution-data-server"
RDEPENDS_${PN}-dev += "typelib-EDataServer"
RDEPENDS_${PN}-dev += "libedataserver"
RDEPENDS_${PN}-dev += "libecal"
RDEPENDS_${PN}-dev += "libcamel"
RDEPENDS_${PN}-dev += "libedata-cal"
RDEPENDS_${PN}-dev += "eglibc"
RDEPENDS_${PN}-dev += "libedata-book"
RDEPENDS_${PN}-dev += "libebook"
RDEPENDS_${PN}-dev += "libebackend"


DEPENDS = ""
#DEPENDS of evolution-data-server
DEPENDS_append_class-native = " intltool-native"
DEPENDS_append_class-target = " intltool-native"
DEPENDS += "gnome-common"
DEPENDS += "gperf"
DEPENDS += "nss"
DEPENDS += "eglibc-locale"
DEPENDS += "db"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "gtk-doc-stub"
DEPENDS += "libical"
DEPENDS += "libsoup-2.4"
inherit pythonnative
DEPENDS += "gcr"
DEPENDS += "libsecret"
DEPENDS += "icu"
DEPENDS += "sqlite3"
DEPENDS_append_class-native = " fdupes-native"
DEPENDS_append_class-target = " fdupes-native"
DEPENDS += "vala"
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
  
  
  # "maintainer mode" depends on GTK and is not needed
  # for packaging, so disable it.
  
  
   
  autotools_do_configure
  
  make -j16 V=1
  
  
  
}
EXTRA_OECONF += " --libexecdir=${prefix}/libexec/evolution-data-server --disable-maintainer-mode --enable-ipv6= --enable-smime= --enable-nntp= --disable-static --disable-uoa --enable-goa=no --enable-weather=no --enable-gtk=no --enable-google=no --enable-vala-bindings --enable-introspection --disable-examples # end of configure line"

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
 mkdir -p ${D}/${prefix}/share/help
 #find_lang evolution-data-server-3.12
 mv evolution-data-server-3.12.lang evolution-data-server.lang
 #fdupes ${D}
 
 #lang_package
 
 
}

pkg_postinst_libebook() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_libecal() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    %glib2_gsettings_schema_post

}

pkg_postinst_libebackend() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_libedata-cal() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_libebook-contacts() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_libedataserver() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_libedata-book() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_libcamel() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_libedata-cal() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_libcamel() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_libedata-book() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    %glib2_gsettings_schema_postun

}

pkg_postrm_libebackend() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_libedataserver() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_libecal() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_libebook() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_libebook-contacts() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " typelib-EBook "
PACKAGES += " evolution-data-server "
PACKAGES += " typelib-EDataServer "
PACKAGES += " libecal "
PACKAGES += " libcamel "
PACKAGES += " libedataserver "
PACKAGES += " libedata-cal "
PACKAGES += " libebook-contacts "
PACKAGES += " typelib-EBookContacts "
PACKAGES += " libebook "
PACKAGES += " libedata-book "
PACKAGES += " libebackend "
PACKAGES += " evolution-data-server-dev "

typelib-EBook_files = ""
typelib-EBook_files += "${prefix}/lib/girepository-1.0/EBook-1.2.typelib"

evolution-data-server_files = ""
evolution-data-server_files += "${prefix}/share/GConf/gsettings/evolution-data-server.convert"
evolution-data-server_files += "${prefix}/share/glib-2.0/schemas/org.gnome.Evolution.DefaultSources.gschema.xml"
evolution-data-server_files += "${prefix}/share/glib-2.0/schemas/org.gnome.evolution.eds-shell.gschema.xml"
evolution-data-server_files += "${prefix}/share/glib-2.0/schemas/org.gnome.evolution.shell.network-config.gschema.xml"
evolution-data-server_files += "${prefix}/share/glib-2.0/schemas/org.gnome.evolution-data-server.addressbook.gschema.xml"
evolution-data-server_files += "${prefix}/share/glib-2.0/schemas/org.gnome.evolution-data-server.calendar.gschema.xml"
evolution-data-server_files += "${prefix}/share/pixmaps/evolution-data-server/"
evolution-data-server_files += "${prefix}/share/dbus-1/services/org.gnome.evolution.dataserver.*.service"
evolution-data-server_files += "${prefix}/lib/evolution-data-server/"
evolution-data-server_files += "${prefix}/libexec/evolution-data-server/"

typelib-EDataServer_files = ""
typelib-EDataServer_files += "${prefix}/lib/girepository-1.0/EDataServer-1.2.typelib"

libecal_files = ""
libecal_files += "${prefix}/lib/libecal-1.2.so.16*"

libcamel_files = ""
libcamel_files += "${prefix}/lib/libcamel-1.2.so.49*"

libedataserver_files = ""
libedataserver_files += "${prefix}/lib/libedataserver-1.2.so.18*"

libedata-cal_files = ""
libedata-cal_files += "${prefix}/lib/libedata-cal-1.2.so.23*"

libebook-contacts_files = ""
libebook-contacts_files += "${prefix}/lib/libebook-contacts-1.2.so.0*"

typelib-EBookContacts_files = ""
typelib-EBookContacts_files += "${prefix}/lib/girepository-1.0/EBookContacts-1.2.typelib"

libebook_files = ""
libebook_files += "${prefix}/lib/libebook-1.2.so.14*"

libedata-book_files = ""
libedata-book_files += "${prefix}/lib/libedata-book-1.2.so.20*"

libebackend_files = ""
libebackend_files += "${prefix}/lib/libebackend-1.2.so.7*"

evolution-data-server-dev_files = ""
evolution-data-server-dev_files += "${prefix}/include/evolution-data-server/"
evolution-data-server-dev_files += "${prefix}/lib/*.so"
evolution-data-server-dev_files += "${prefix}/lib/pkgconfig/*.pc"
evolution-data-server-dev_files += "${prefix}/share/gir-1.0/*.gir"
evolution-data-server-dev_files += "${prefix}/share/vala"
evolution-data-server-dev_files += "${prefix}/share/vala/vapi"
evolution-data-server-dev_files += "${prefix}/share/vala/vapi/*.deps"
evolution-data-server-dev_files += "${prefix}/share/vala/vapi/*.vapi"
DIRFILES_${PN}-dev = ""
DIRFILES_${PN}-dev += "${prefix}/share/vala"
DIRFILES_${PN}-dev += "${prefix}/share/vala/vapi"

FILES_typelib-EBook = "${typelib-EBook_files}"
FILES_${PN} = "${evolution-data-server_files}"
FILES_typelib-EDataServer = "${typelib-EDataServer_files}"
FILES_libecal = "${libecal_files}"
FILES_libcamel = "${libcamel_files}"
FILES_libedataserver = "${libedataserver_files}"
FILES_libedata-cal = "${libedata-cal_files}"
FILES_libebook-contacts = "${libebook-contacts_files}"
FILES_typelib-EBookContacts = "${typelib-EBookContacts_files}"
FILES_libebook = "${libebook_files}"
FILES_libedata-book = "${libedata-book_files}"
FILES_libebackend = "${libebackend_files}"
FILES_${PN}-dev = "${evolution-data-server-dev_files}"

PKG_typelib-EBook= "typelib-EBook"
PKG_evolution-data-server= "evolution-data-server"
PKG_typelib-EDataServer= "typelib-EDataServer"
PKG_libecal= "libecal"
PKG_libcamel= "libcamel"
PKG_libedataserver= "libedataserver"
PKG_libedata-cal= "libedata-cal"
PKG_libebook-contacts= "libebook-contacts"
PKG_typelib-EBookContacts= "typelib-EBookContacts"
PKG_libebook= "libebook"
PKG_libedata-book= "libedata-book"
PKG_libebackend= "libebackend"
PKG_evolution-data-server-dev= "evolution-data-server-dev"

require evolution-data-server-extraconf.inc

