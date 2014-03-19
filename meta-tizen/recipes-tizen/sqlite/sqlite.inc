DESCRIPTION = "Embeddable SQL Database Engine"
HOMEPAGE = "http://www.sqlite.org/"
SECTION = "System/Database"
LICENSE = "Public-Domain"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libsqlite 
PROVIDES += "libsqlite"
RPROVIDES_libsqlite += "libsqlite"
# the PROVIDES rules is ignore "libsqlit3  "
PROVIDES += "libsqlit3"
RPROVIDES_libsqlite += "libsqlit3"

#PROVIDES by sqlite-docs  
PROVIDES += "sqlite-docs "
RPROVIDES_sqlite-docs  += "sqlite-docs "

#PROVIDES by sqlite 
PROVIDES += "sqlite"
RPROVIDES_sqlite += "sqlite"
# the PROVIDES rules is ignore "sqlite3  "
PROVIDES += "sqlite3"
RPROVIDES_sqlite += "sqlite3"

#PROVIDES by sqlite-devel 
PROVIDES += "sqlite-devel"
RPROVIDES_sqlite-devel += "sqlite-devel"
RPROVIDES_sqlite-devel += "sqlite-dev"
# the PROVIDES rules is ignore "sqlite3-devel = 3.7.14"
PROVIDES += "sqlite3-devel"
RPROVIDES_sqlite-devel += "sqlite3-devel"
RPROVIDES_sqlite-devel += "sqlite3-dev"

RDEPENDS = ""
#RDEPENDS of sqlite (${PN})
RDEPENDS_${PN} += "libsqlite"

#RDEPENDS of sqlite-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libsqlite"
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "sqlite"


DEPENDS = ""
#DEPENDS of sqlite 
DEPENDS += "readline"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n sqlite-autoconf-3071400
 cp ${S}/packaging/sqlite.manifest .
 
 
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
 
 CFLAGS=`echo -O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables |sed -e 's/-ffast-math//g'`
 chmod +x autogen.sh
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   ./autogen.sh --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=x86_64-tizen-linux \
         --program-prefix= \
         --prefix=/usr \
         --exec-prefix=/usr \
         --bindir=/usr/bin \
         --sbindir=/usr/sbin \
         --sysconfdir=/etc \
         --datadir=/usr/share \
         --includedir=/usr/include \
         --libdir=/usr/lib \
         --libexecdir=/usr/libexec \
         --localstatedir=/var \
         --sharedstatedir=/usr/com \
         --mandir=/usr/share/man \
         --infodir=/usr/share/info
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=x86_64-tizen-linux \
         --program-prefix= \
         --prefix=/usr \
         --exec-prefix=/usr \
         --bindir=/usr/bin \
         --sbindir=/usr/sbin \
         --sysconfdir=/etc \
         --datadir=/usr/share \
         --includedir=/usr/include \
         --libdir=/usr/lib \
         --libexecdir=/usr/libexec \
         --localstatedir=/var \
         --sharedstatedir=/usr/com \
         --mandir=/usr/share/man \
         --infodir=/usr/share/info --disable-static --enable-threadsafe
 make
 
 
 
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
 
 
}

PACKAGES = ""
PACKAGES += "libsqlite"
PACKAGES += "sqlite"
PACKAGES += "sqlite-devel"
PACKAGES += "sqlite-docs"

libsqlite_files = ""
libsqlite_files += "sqlite.manifest"
libsqlite_files += "/usr/lib/libsqlite*.so.*"

sqlite_files = ""
sqlite_files += "sqlite.manifest"
sqlite_files += "/usr/bin/sqlite3"

sqlite-devel_files = ""
sqlite-devel_files += "sqlite.manifest"
sqlite-devel_files += "/usr/include/*.h"
sqlite-devel_files += "/usr/lib/libsqlite*.so"
sqlite-devel_files += "/usr/lib/pkgconfig/sqlite3.pc"

sqlite-docs_files = ""
sqlite-docs_files += "/usr/share/info"
sqlite-docs_files += "/usr/share/man"

FILES_lib${PN} = "${libsqlite_files}"
FILES_${PN} = "${sqlite_files}"
FILES_${PN}-devel = "${sqlite-devel_files}"
FILES_${PN}-docs = "${sqlite-docs_files}"

PKG_libsqlite= "libsqlite"
PKG_sqlite= "sqlite"
PKG_sqlite-devel= "sqlite-devel"
PKG_sqlite-docs= "sqlite-docs"

require sqlite-extraconf.inc
