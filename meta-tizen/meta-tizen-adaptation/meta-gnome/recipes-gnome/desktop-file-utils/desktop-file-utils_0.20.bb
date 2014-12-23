HOMEPAGE = "http://www.freedesktop.org/wiki/Software/desktop-file-utils"
DESCRIPTION = "desktop-file-utils contains a few command line utilities for working with desktop entries:"
LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://COPYING;md5=b234ee4d69f5fce4486a80fdaf4a4263"

DEPENDS = "glib-2.0"

SRC_URI = "http://www.freedesktop.org/software/desktop-file-utils/releases/desktop-file-utils-${PV}.tar.bz2"

inherit autotools pkgconfig

CACHED_CONFIGUREVARS += "ac_cv_prog_EMACS=no"

BBCLASSEXTEND = "native"
