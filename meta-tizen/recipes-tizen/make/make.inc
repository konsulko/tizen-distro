DESCRIPTION = "GNU make"
HOMEPAGE = "http://www.gnu.org/software/make/make.html"
SECTION = "Development/Tools/Building"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by make 
PROVIDES += "make"
RPROVIDES_make += "make"
# the PROVIDES rules is ignore "gmake  "
PROVIDES += "gmake"
RPROVIDES_make += "gmake"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/make.manifest .
 
 
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
 
 CFLAGS=$RPM_OPT_FLAGS \
 ./configure --prefix=/usr --mandir=/usr/share/man --infodir=/usr/share/info --disable-nls
 make -j16
 
 exit 0
 make check
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make DESTDIR=$RPM_BUILD_ROOT install
 ln -s make $RPM_BUILD_ROOT/usr/bin/gmake
 
 
}

PACKAGES = ""
PACKAGES += "make"

make_files = ""
make_files += "make.manifest"
make_files += "/usr/bin/make"
make_files += "/usr/bin/gmake"
make_files += "/usr/share/info/make.info-*.gz"
make_files += "/usr/share/info/make.info.gz"
make_files += "/usr/share/man/man1/make.1.gz"

FILES_${PN} = "${make_files}"

PKG_make= "make"

require make-extraconf.inc
