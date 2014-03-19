DESCRIPTION = "Evolution Data Server"
HOMEPAGE = "http://www.gnome.org"
SECTION = "Development/Libraries"
LICENSE = "LGPL-2.0+"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "typelib-EBook"
PACKAGES += "evolution-data-server"
PACKAGES += "typelib-EDataServer"
PACKAGES += "libedata-cal"
PACKAGES += "libecal"
PACKAGES += "libcamel"
PACKAGES += "libedataserver"
PACKAGES += "evolution-data-server-locale"
PACKAGES += "libebook-contacts"
PACKAGES += "evolution-data-server-devel"
PACKAGES += "libebook"
PACKAGES += "libedata-book"
PACKAGES += "libebackend"
PACKAGES += "typelib-EBookContacts"

typelib-EBook_files = ""
typelib-EBook_files += "/usr/lib/girepository-1.0/EBook-1.2.typelib"

evolution-data-server_files = ""
evolution-data-server_files += "/usr/share/GConf/gsettings/evolution-data-server.convert"
evolution-data-server_files += "/usr/share/GConf/gsettings/libedataserver.convert"
evolution-data-server_files += "/usr/share/glib-2.0/schemas/org.gnome.Evolution.DefaultSources.gschema.xml"
evolution-data-server_files += "/usr/share/glib-2.0/schemas/org.gnome.evolution.eds-shell.gschema.xml"
evolution-data-server_files += "/usr/share/glib-2.0/schemas/org.gnome.evolution.shell.network-config.gschema.xml"
evolution-data-server_files += "/usr/share/glib-2.0/schemas/org.gnome.evolution-data-server.addressbook.gschema.xml"
evolution-data-server_files += "/usr/share/glib-2.0/schemas/org.gnome.evolution-data-server.calendar.gschema.xml"
evolution-data-server_files += "/usr/share/pixmaps/evolution-data-server/"
evolution-data-server_files += "/usr/share/dbus-1/services/org.gnome.evolution.dataserver.*.service"
evolution-data-server_files += "/usr/lib/evolution-data-server/"
evolution-data-server_files += "/usr/libexec/evolution-data-server/"

typelib-EDataServer_files = ""
typelib-EDataServer_files += "/usr/lib/girepository-1.0/EDataServer-1.2.typelib"

libedata-cal_files = ""
libedata-cal_files += "/usr/lib/libedata-cal-1.2.so.20*"

libecal_files = ""
libecal_files += "/usr/lib/libecal-1.2.so.15*"

libcamel_files = ""
libcamel_files += "/usr/lib/libcamel-1.2.so.43*"

libedataserver_files = ""
libedataserver_files += "/usr/lib/libedataserver-1.2.so.17*"

evolution-data-server-locale_files = ""

libebook-contacts_files = ""
libebook-contacts_files += "/usr/lib/libebook-contacts-1.2.so.0*"

evolution-data-server-devel_files = ""
evolution-data-server-devel_files += "/usr/include/evolution-data-server/"
evolution-data-server-devel_files += "/usr/lib/*.so"
evolution-data-server-devel_files += "/usr/lib/pkgconfig/*.pc"
evolution-data-server-devel_files += "/usr/share/gir-1.0/*.gir"
evolution-data-server-devel_files += "/usr/share/vala"
evolution-data-server-devel_files += "/usr/share/vala/vapi"
evolution-data-server-devel_files += "/usr/share/vala/vapi/*.deps"
evolution-data-server-devel_files += "/usr/share/vala/vapi/*.vapi"

libebook_files = ""
libebook_files += "/usr/lib/libebook-1.2.so.14*"

libedata-book_files = ""
libedata-book_files += "/usr/lib/libedata-book-1.2.so.17*"

libebackend_files = ""
libebackend_files += "/usr/lib/libebackend-1.2.so.6*"

typelib-EBookContacts_files = ""
typelib-EBookContacts_files += "/usr/lib/girepository-1.0/EBookContacts-1.2.typelib"

FILES_typelib-EBook = "${typelib-EBook_files}"
FILES_${PN} = "${evolution-data-server_files}"
FILES_typelib-EDataServer = "${typelib-EDataServer_files}"
FILES_libedata-cal = "${libedata-cal_files}"
FILES_libecal = "${libecal_files}"
FILES_libcamel = "${libcamel_files}"
FILES_libedataserver = "${libedataserver_files}"
FILES_${PN}-locale = "${evolution-data-server-locale_files}"
FILES_libebook-contacts = "${libebook-contacts_files}"
FILES_${PN}-devel = "${evolution-data-server-devel_files}"
FILES_libebook = "${libebook_files}"
FILES_libedata-book = "${libedata-book_files}"
FILES_libebackend = "${libebackend_files}"
FILES_typelib-EBookContacts = "${typelib-EBookContacts_files}"

PKG_typelib-EBook= "typelib-EBook"
PKG_evolution-data-server= "evolution-data-server"
PKG_typelib-EDataServer= "typelib-EDataServer"
PKG_libedata-cal= "libedata-cal"
PKG_libecal= "libecal"
PKG_libcamel= "libcamel"
PKG_libedataserver= "libedataserver"
PKG_evolution-data-server-locale= "evolution-data-server-locale"
PKG_libebook-contacts= "libebook-contacts"
PKG_evolution-data-server-devel= "evolution-data-server-devel"
PKG_libebook= "libebook"
PKG_libedata-book= "libedata-book"
PKG_libebackend= "libebackend"
PKG_typelib-EBookContacts= "typelib-EBookContacts"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require evolution-data-server-rdepends.inc
require evolution-data-server-depends.inc
require evolution-data-server-extraconf.inc
