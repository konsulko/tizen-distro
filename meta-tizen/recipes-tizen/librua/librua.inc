DESCRIPTION = "Recently used application"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Application Framework/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by librua 
PROVIDES += "librua"
RPROVIDES_librua += "librua"

#PROVIDES by librua-devel 
PROVIDES += "librua-devel"
RPROVIDES_librua-devel += "librua-devel"
RPROVIDES_librua-devel += "librua-dev"

RDEPENDS = ""
#RDEPENDS of librua-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "librua"


DEPENDS = ""
#DEPENDS of librua 
DEPENDS += "sqlite3"
DEPENDS += "pkgconfig(libtzplatform-config)"
DEPENDS += "pkgconfig(sqlite3)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(db-util)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/librua.manifest .
 
 
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
 mkdir -p ${D}%{TZ_SYS_DB}
 sqlite3 ${D}%{TZ_SYS_DB}/.rua.db < data/rua_db.sql
 
 
}

PACKAGES = ""
PACKAGES += "librua"
PACKAGES += "librua-devel"

librua_files = ""
librua_files += "librua.manifest"
#Remove rpm attribut "%attr(0660,root,%{TZ_SYS_USER_GROUP})"
librua_files += "%{TZ_SYS_DB}/.rua.db*"
librua_files += "/usr/lib/librua.so.*"

librua-devel_files = ""
librua-devel_files += "librua.manifest"
librua-devel_files += "/usr/include/rua"
librua-devel_files += "/usr/include/rua/*.h"
librua-devel_files += "/usr/lib/librua.so"
librua-devel_files += "/usr/lib/pkgconfig/rua.pc"

FILES_${PN} = "${librua_files}"
FILES_${PN}-devel = "${librua-devel_files}"

PKG_librua= "librua"
PKG_librua-devel= "librua-devel"

require librua-extraconf.inc
