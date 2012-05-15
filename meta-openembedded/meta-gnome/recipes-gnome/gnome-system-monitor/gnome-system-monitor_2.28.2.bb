DESCRIPTION = "Gnome system monitor"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=751419260aa954499f7abaabaa882bbe"
SECTION = "x11/gnome"
PR = "r1"

DEPENDS = "libgtop gtkmm glibmm gnome-doc-utils gnome-icon-theme libwnck gtk+ dbus-glib librsvg"

inherit gnome
SRC_URI[archive.md5sum] = "3f0bca9b0ebc7a365466851cd580d167"
SRC_URI[archive.sha256sum] = "b628edfd39e3a6b374ce133f367d3568475eb4e981a367f4f9d62a9784e5ae59"
SRC_URI += "file://0001-Fix-glib-includes.patch"

do_configure_prepend() {
        sed -i -e s:help::g ${S}/Makefile.am
}

FILES_${PN} += "${datadir}/icons \
                ${datadir}/dbus-1 \
                ${datadir}/gnome/autostart \
		"

FILES_${PN}-doc += "${datadir}/omf \
                    ${datadir}/gnome/help "

