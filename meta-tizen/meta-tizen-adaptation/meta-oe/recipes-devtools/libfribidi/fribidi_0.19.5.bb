SUMMARY = "Fribidi library for bidirectional text"
SECTION = "libs"
LICENSE = "LGPLv2.1"
LIC_FILES_CHKSUM = "file://COPYING;md5=a916467b91076e631dd8edb7424769c7"
BBCLASSEXTEND = "native"

PROVIDES = "libfribidi"

inherit autotools lib_package pkgconfig

CFLAGS_append = "  -DPAGE_SIZE=4096 "

SRC_URI = "http://fribidi.org/download/fribidi-${PV}.tar.bz2"
SRC_URI[md5sum] = "925bafb97afee8a2fc2d0470c072a155"
SRC_URI[sha256sum] = "501231e4260f83fccedae1cafe983a7de87082e3f5387e0b283d016f7f4cb428"

