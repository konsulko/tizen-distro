DESCRIPTION = "Parallel implementation of bzip2"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Applications/Other"
LICENSE = "BSD"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by pbzip2 
PROVIDES += "pbzip2"
RPROVIDES_pbzip2 += "pbzip2"

#PROVIDES by pbzip2-docs  
PROVIDES += "pbzip2-docs "
RPROVIDES_pbzip2-docs  += "pbzip2-docs "

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of pbzip2 
DEPENDS += "bzip2"
DEPENDS += "gcc-cross"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/pbzip2.manifest .
 
 
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
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 install -Dm755 pbzip2 ${D}/usr/bin/pbzip2
 install -Dm644 pbzip2.1 ${D}/usr/share/man/man1/pbzip2.1
 ln -s pbzip2 ${D}/usr/bin/pbunzip2
 ln -s pbzip2 ${D}/usr/bin/pbzcat
 
 
 
}

PACKAGES = ""
PACKAGES += "pbzip2"
PACKAGES += "pbzip2-docs"

pbzip2_files = ""
pbzip2_files += "pbzip2.manifest"
pbzip2_files += "/usr/bin/pbzip2"
pbzip2_files += "/usr/bin/pbunzip2"
pbzip2_files += "/usr/bin/pbzcat"

pbzip2-docs_files = ""
pbzip2-docs_files += "/usr/share/info"
pbzip2-docs_files += "/usr/share/man"

FILES_${PN} = "${pbzip2_files}"
FILES_${PN}-docs = "${pbzip2-docs_files}"

PKG_pbzip2= "pbzip2"
PKG_pbzip2-docs= "pbzip2-docs"

require pbzip2-extraconf.inc
