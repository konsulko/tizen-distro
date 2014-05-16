DESCRIPTION = "Identifying or deleting duplicate files"
HOMEPAGE = "http://premium.caribe.net/~adrian2/fdupes.html"
SECTION = "Productivity/Archiving/Compression"
LICENSE = "X11/MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND += ""
PROVIDES = ""

#PROVIDES by fdupes 


RDEPENDS = ""

DEPENDS = ""

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/fdupes.manifest .
 
 
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
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ; 
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
 LD_AS_NEEDED=1; export LD_AS_NEEDED ; 
 
 make
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 install -D -m755 fdupes ${D}/usr/bin/fdupes
 install -D -m644 fdupes.1 ${D}/usr/share/man/man1/fdupes.1
 install -D -m644 ${S}/packaging/macros.fdupes ${D}${sysconfdir}/rpm/macros.fdupes
 
 
}


fdupes_files = ""
fdupes_files += "fdupes.manifest"
fdupes_files += "CHANGES"
fdupes_files += "${prefix}/bin/fdupes"
fdupes_files += "${mandir}/*/*"
fdupes_files += "${sysconfdir}/rpm"

FILES_${PN} = "${fdupes_files}"

PKG_fdupes= "fdupes"

require fdupes-extraconf.inc

