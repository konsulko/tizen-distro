DESCRIPTION = "A set of documentation tools: man, apropos and whatis"
HOMEPAGE = "http://man-db.nongnu.org/"
SECTION = "System/Base"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by man-db 
PROVIDES += "man-db"
RPROVIDES_man-db += "man-db"
# the PROVIDES rules is ignore "man  "
PROVIDES += "man"
RPROVIDES_man-db += "man"

#PROVIDES by man-db-docs  
PROVIDES += "man-db-docs "
RPROVIDES_man-db-docs  += "man-db-docs "

#PROVIDES by man-db-locale  
PROVIDES += "man-db-locale "
RPROVIDES_man-db-locale  += "man-db-locale "
# the PROVIDES rules is ignore "man-db-lang-all = 2.6.3"
PROVIDES += "man-db-lang-all"
RPROVIDES_man-db-locale  += "man-db-lang-all"

RDEPENDS = ""
#RDEPENDS of man-db (${PN})
RDEPENDS_${PN} += "lzma"
RDEPENDS_${PN} += "bzip2"
RDEPENDS_${PN} += "less"
RDEPENDS_${PN} += "coreutils"
RDEPENDS_${PN} += "gzip"
RDEPENDS_${PN} += "groff"

#RDEPENDS of man-db-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "man-db"


DEPENDS = ""
#DEPENDS of man-db 
DEPENDS += "libpipeline"
DEPENDS += "groff"
DEPENDS += "db4"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/man-db.manifest .
 
 
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
         --infodir=/usr/share/info --libdir=/usr/lib \
 	--libexecdir=/usr/lib \
 	--sysconfdir=/etc \
 	--with-db=db4 \
 	--disable-setuid \
 	--enable-mandirs=GNU \
 	--enable-mb-groff \
 	--with-sections="1 n l 8 3 0 2 5 4 9 6 7"
 
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
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} man-db --with-man --all-name
 
 rm -rf ${D}/usr/share/doc/man-db
 
 # groff provides this file
 rm ${D}/usr/bin/zsoelim
 
 
 
 
}

PACKAGES = ""
PACKAGES += "man-db"
PACKAGES += "man-db-locale"
PACKAGES += "man-db-docs"

man-db_files = ""
man-db_files += "man-db.manifest"
man-db_files += "/etc/man_db.conf"
man-db_files += "/usr/bin/apropos"
man-db_files += "/usr/bin/catman"
man-db_files += "/usr/bin/lexgrog"
man-db_files += "/usr/bin/man"
man-db_files += "/usr/bin/mandb"
man-db_files += "/usr/bin/manpath"
man-db_files += "/usr/bin/whatis"
man-db_files += "/usr/sbin/accessdb"
man-db_files += "/usr/lib/man-db/libman-2.6.3.so"
man-db_files += "/usr/lib/man-db/libman.so"
man-db_files += "/usr/lib/man-db/libmandb-2.6.3.so"
man-db_files += "/usr/lib/man-db/libmandb.so"
man-db_files += "/usr/lib/man-db/globbing"
man-db_files += "/usr/lib/man-db/manconv"

man-db-locale_files = ""

man-db-docs_files = ""
man-db-docs_files += "/usr/share/info"
man-db-docs_files += "/usr/share/man"

FILES_${PN} = "${man-db_files}"
FILES_${PN}-locale = "${man-db-locale_files}"
FILES_${PN}-docs = "${man-db-docs_files}"

PKG_man-db= "man-db"
PKG_man-db-locale= "man-db-locale"
PKG_man-db-docs= "man-db-docs"

require man-db-extraconf.inc
