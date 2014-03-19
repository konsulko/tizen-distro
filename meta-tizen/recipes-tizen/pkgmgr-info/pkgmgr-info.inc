DESCRIPTION = "Packager Manager infomation api for package"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Application Framework/Package Management"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by pkgmgr-info-parser 
PROVIDES += "pkgmgr-info-parser"
RPROVIDES_pkgmgr-info-parser += "pkgmgr-info-parser"

#PROVIDES by pkgmgr-info-parser-devel 
PROVIDES += "pkgmgr-info-parser-devel"
RPROVIDES_pkgmgr-info-parser-devel += "pkgmgr-info-parser-devel"
RPROVIDES_pkgmgr-info-parser-devel += "pkgmgr-info-parser-dev"

#PROVIDES by pkgmgr-info 
PROVIDES += "pkgmgr-info"
RPROVIDES_pkgmgr-info += "pkgmgr-info"

#PROVIDES by pkgmgr-info-devel 
PROVIDES += "pkgmgr-info-devel"
RPROVIDES_pkgmgr-info-devel += "pkgmgr-info-devel"
RPROVIDES_pkgmgr-info-devel += "pkgmgr-info-dev"

RDEPENDS = ""
#RDEPENDS of pkgmgr-info-parser (${PN}-parser)
RDEPENDS_${PN}-parser += "pkgmgr-info"

#RDEPENDS of pkgmgr-info-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "pkgmgr-info"

#RDEPENDS of pkgmgr-info-parser-devel (${PN}-parser-devel)
RDEPENDS_${PN}-parser-devel += "pkgmgr-info"


DEPENDS = ""
#DEPENDS of pkgmgr-info 
DEPENDS += "cmake"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "dbus-glib"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(sqlite3)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "libslp-db-util"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/pkgmgr-info.manifest .
 
 
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
 
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export FFLAGS ; 
   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=/usr \
         -DCMAKE_INSTALL_LIBDIR:PATH=/usr/lib \
         -DINCLUDE_INSTALL_DIR:PATH=/usr/include \
         -DLIB_INSTALL_DIR:PATH=/usr/lib \
         -DSYSCONF_INSTALL_DIR:PATH=/etc \
         -DSHARE_INSTALL_PREFIX:PATH=/usr/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON \
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake .
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 mkdir -p ${D}/opt/usr/apps/tmp
 touch ${D}/opt/usr/apps/tmp/pkgmgr_tmp.txt
 
 # create the directory for hosting Read-Write application manifest files
 mkdir -p ${D}/opt/share/packages/
 
 
}

PACKAGES = ""
PACKAGES += "pkgmgr-info-parser"
PACKAGES += "pkgmgr-info-parser-devel"
PACKAGES += "pkgmgr-info-devel"
PACKAGES += "pkgmgr-info"

pkgmgr-info-parser_files = ""
pkgmgr-info-parser_files += "pkgmgr-info.manifest"
pkgmgr-info-parser_files += "/usr/lib/libpkgmgr_parser.so.*"
pkgmgr-info-parser_files += "/etc/package-manager/preload/preload_list.txt"
pkgmgr-info-parser_files += "/etc/package-manager/preload/manifest.xsd"
pkgmgr-info-parser_files += "/etc/package-manager/preload/xml.xsd"
pkgmgr-info-parser_files += "/etc/package-manager/parser_path.conf"
pkgmgr-info-parser_files += "/etc/package-manager/parserlib/metadata/mdparser_list.txt"
pkgmgr-info-parser_files += "/etc/package-manager/parserlib/category/category_parser_list.txt"
pkgmgr-info-parser_files += "/etc/package-manager/parserlib/tag_parser_list.txt"

pkgmgr-info-parser-devel_files = ""
pkgmgr-info-parser-devel_files += "pkgmgr-info.manifest"
pkgmgr-info-parser-devel_files += "/usr/include/pkgmgr/pkgmgr_parser.h"
pkgmgr-info-parser-devel_files += "/usr/include/pkgmgr/pkgmgr_parser_db.h"
pkgmgr-info-parser-devel_files += "/usr/lib/pkgconfig/pkgmgr-parser.pc"
pkgmgr-info-parser-devel_files += "/usr/lib/libpkgmgr_parser.so"

pkgmgr-info-devel_files = ""
pkgmgr-info-devel_files += "pkgmgr-info.manifest"
pkgmgr-info-devel_files += "/usr/include/pkgmgr-info.h"
pkgmgr-info-devel_files += "/usr/lib/pkgconfig/pkgmgr-info.pc"
pkgmgr-info-devel_files += "/usr/lib/libpkgmgr-info.so"

pkgmgr-info_files = ""
pkgmgr-info_files += "pkgmgr-info.manifest"
pkgmgr-info_files += "/usr/lib/libpkgmgr-info.so.*"
#Remove rpm attribut "%attr(771,app,app)"
pkgmgr-info_files += "/opt/usr/apps/tmp"
pkgmgr-info_files += "/opt/usr/apps/tmp/pkgmgr_tmp.txt"
pkgmgr-info_files += "/opt/share/packages"

FILES_${PN}-parser = "${pkgmgr-info-parser_files}"
FILES_${PN}-parser-devel = "${pkgmgr-info-parser-devel_files}"
FILES_${PN}-devel = "${pkgmgr-info-devel_files}"
FILES_${PN} = "${pkgmgr-info_files}"

PKG_pkgmgr-info-parser= "pkgmgr-info-parser"
PKG_pkgmgr-info-parser-devel= "pkgmgr-info-parser-devel"
PKG_pkgmgr-info-devel= "pkgmgr-info-devel"
PKG_pkgmgr-info= "pkgmgr-info"

require pkgmgr-info-extraconf.inc
