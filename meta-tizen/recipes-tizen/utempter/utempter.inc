DESCRIPTION = "A privileged helper for utmp and wtmp updates"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Productivity/Security"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by utempter 
PROVIDES += "utempter"
RPROVIDES_utempter += "utempter"

#PROVIDES by utempter-devel 
PROVIDES += "utempter-devel"
RPROVIDES_utempter-devel += "utempter-devel"
RPROVIDES_utempter-devel += "utempter-dev"

RDEPENDS = ""
#RDEPENDS of utempter-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "utempter"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/utempter.manifest .
 
 
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
 
 make -j16 RPM_OPT_FLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" CC="gcc"
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 export DESTDIR=${D}
 make PREFIX=$DESTDIR LIBDIR=/usr/lib install
 chmod 755 $DESTDIR/usr/lib/libutempter.so*
 /sbin/ldconfig -n $DESTDIR/usr/lib
 
 
}

PACKAGES = ""
PACKAGES += "utempter"
PACKAGES += "utempter-devel"

utempter_files = ""
utempter_files += "utempter.manifest"
utempter_files += "COPYING"

utempter-devel_files = ""
utempter-devel_files += "utempter.manifest"

FILES_${PN} = "${utempter_files}"
FILES_${PN}-devel = "${utempter-devel_files}"

PKG_utempter= "utempter"
PKG_utempter-devel= "utempter-devel"

require utempter-extraconf.inc
