SUMMARY = "Fribidi library for bidirectional text"
SECTION = "libs"
LICENSE = "LGPLv2.1"
LIC_FILES_CHKSUM = "file://COPYING;md5=7fbc338309ac38fefcd64b04bb903e34"
BBCLASSEXTEND = "native"

PROVIDES = "libfribidi"

inherit autotools lib_package pkgconfig

CFLAGS_append = "  -DPAGE_SIZE=4096 "

SRC_URI = "http://fribidi.org/download/fribidi-${PV}.tar.gz"

