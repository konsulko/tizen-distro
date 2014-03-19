DESCRIPTION = "The GNU data compression program"
HOMEPAGE = "http://www.gnu.org/software/gzip/"
SECTION = "Base/Compression"
LICENSE = "GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gzip 
PROVIDES += "gzip"
RPROVIDES_gzip += "gzip"

#PROVIDES by gzip-docs  
PROVIDES += "gzip-docs "
RPROVIDES_gzip-docs  += "gzip-docs "

RDEPENDS = ""
#RDEPENDS of gzip (${PN})
RDEPENDS_${PN} += "/usr/bin/mktemp"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/gzip.manifest .
 
 
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
         --infodir=/usr/share/info \
     --bindir=/usr/bin
 
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
 
 
 
}

PACKAGES = ""
PACKAGES += "gzip"
PACKAGES += "gzip-docs"

gzip_files = ""
gzip_files += "gzip.manifest"
gzip_files += "/usr/bin/gzip"
gzip_files += "/usr/bin/gunzip"
gzip_files += "/usr/bin/zcmp"
gzip_files += "/usr/bin/zegrep"
gzip_files += "/usr/bin/zforce"
gzip_files += "/usr/bin/znew"
gzip_files += "/usr/bin/gzexe"
gzip_files += "/usr/bin/zdiff"
gzip_files += "/usr/bin/zfgrep"
gzip_files += "/usr/bin/zgrep"
gzip_files += "/usr/bin/zmore"
gzip_files += "/usr/bin/zcat"
gzip_files += "/usr/bin/uncompress"
gzip_files += "/usr/bin/zless"

gzip-docs_files = ""
gzip-docs_files += "/usr/share/info"
gzip-docs_files += "/usr/share/man"

FILES_${PN} = "${gzip_files}"
FILES_${PN}-docs = "${gzip-docs_files}"

PKG_gzip= "gzip"
PKG_gzip-docs= "gzip-docs"

require gzip-extraconf.inc
