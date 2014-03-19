DESCRIPTION = "Tizen theme files"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by efl-theme-tizen-devel 
PROVIDES += "efl-theme-tizen-devel"
RPROVIDES_efl-theme-tizen-devel += "efl-theme-tizen-devel"
RPROVIDES_efl-theme-tizen-devel += "efl-theme-tizen-dev"

#PROVIDES by efl-theme-tizen-hd 
PROVIDES += "efl-theme-tizen-hd"
RPROVIDES_efl-theme-tizen-hd += "efl-theme-tizen-hd"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of efl-theme-tizen-hd 
DEPENDS += "edje"
DEPENDS += "embryo"
DEPENDS += "embryo-bin"
inherit perlnative

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 
 
 
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
 
 export CFLAGS+=" --fPIC"
 export LDFLAGS+=" -Wl,--hash-style=both -Wl,--as-needed -Wl,--rpath=/usr/lib"
 
 make -j16
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 mkdir -p ${D}/usr/share/license
 cp ${WORKDIR}/git/LICENSE ${D}/usr/share/license/efl-theme-tizen-hd
 cp ${D}/usr/share/elementary/themes/tizen-HD-dark.edj ${D}/usr/share/elementary/themes/tizen-hd.edj
 
 
}

PACKAGES = ""
PACKAGES += "efl-theme-tizen-devel"
PACKAGES += "efl-theme-tizen-hd"

efl-theme-tizen-devel_files = ""
efl-theme-tizen-devel_files += "/opt/var/efl-theme-tizen-edc/*"

efl-theme-tizen-hd_files = ""
efl-theme-tizen-hd_files += "/usr/share/elementary/themes/tizen-HD-dark.edj"
efl-theme-tizen-hd_files += "/usr/share/elementary/themes/tizen-HD-light.edj"
efl-theme-tizen-hd_files += "/usr/share/elementary/themes/tizen-hd.edj"
efl-theme-tizen-hd_files += "efl-theme-tizen-hd.manifest"
efl-theme-tizen-hd_files += "/usr/share/license/efl-theme-tizen-hd"

FILES_efl-theme-tizen-devel = "${efl-theme-tizen-devel_files}"
FILES_${PN} = "${efl-theme-tizen-hd_files}"

PKG_efl-theme-tizen-devel= "efl-theme-tizen-devel"
PKG_efl-theme-tizen-hd= "efl-theme-tizen-hd"

require efl-theme-tizen-extraconf.inc
