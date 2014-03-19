DESCRIPTION = "A Tool to Determine File Types"
HOMEPAGE = "http://www.darwinsys.com/file/"
SECTION = "System/Base"
LICENSE = "BSD-2-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by file-devel 
PROVIDES += "file-devel"
RPROVIDES_file-devel += "file-devel"
RPROVIDES_file-devel += "file-dev"
# the PROVIDES rules is ignore "file:/usr/include/magic.h  "
PROVIDES += "file:/usr/include/magic.h"
RPROVIDES_file-devel += "file:/usr/include/magic.h"

#PROVIDES by libmagic-data 
PROVIDES += "libmagic-data"
RPROVIDES_libmagic-data += "libmagic-data"

#PROVIDES by libmagic 
PROVIDES += "libmagic"
RPROVIDES_libmagic += "libmagic"
# the PROVIDES rules is ignore "libfile  "
PROVIDES += "libfile"
RPROVIDES_libmagic += "libfile"

#PROVIDES by file 
PROVIDES += "file"
RPROVIDES_file += "file"

RDEPENDS = ""
#RDEPENDS of file-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "libmagic"

#RDEPENDS of libmagic (libmagic)
RDEPENDS_libmagic += "libmagic-data"


DEPENDS = ""
#DEPENDS of file 
DEPENDS += "zlib-devel"
DEPENDS += "libtool-cross"
DEPENDS += "findutils"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n file-5.11
 ### PREP BEGIN ###
 cp ${S}/packaging/file.manifest .
 ### PREP END ###
 
 
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
 
 ### BUILD BEGIN ###
 export LANG=POSIX
 export LC_ALL=POSIX
 rm -f Magdir/*,v Magdir/*~
 rm -f ltcf-c.sh ltconfig ltmain.sh
 autoreconf -fiv
 CFLAGS="$RPM_OPT_FLAGS -DHOWMANY=69632"
 
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
         --infodir=/usr/share/info --disable-silent-rules --datadir=/usr/share/misc --disable-static --with-pic --enable-fsect-man5
 oe_runmake -j16 pkgdatadir='$(datadir)'
 ### BUILD END ###
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 export LANG=POSIX
 export LC_ALL=POSIX
 mkdir  ${D}/etc
 make DESTDIR=${D} install pkgdatadir='$(datadir)'
 rm -vf ${D}/etc/magic
 echo '# Localstuff: file(1) magic(5) for locally observed files' > ${D}/etc/magic
 echo '#     global magic file is /usr/share/misc/magic(.mgc)'	>> ${D}/etc/magic
 
 # Check out that the binary does not bail out:
 LD_LIBRARY_PATH=${D}/usr/lib
 export LD_LIBRARY_PATH
 find ${D}/usr/bin/file /usr/bin/ /lib/ /usr/lib/ | \
 	xargs ${D}/usr/bin/file -m ${D}/usr/share/misc/magic
 unset LD_LIBRARY_PATH
 /bin/rm -f ${D}/usr/lib/*.la
 
 
}

PACKAGES = ""
PACKAGES += "file-devel"
PACKAGES += "libmagic-data"
PACKAGES += "file"
PACKAGES += "libmagic"

file-devel_files = ""
file-devel_files += "file.manifest"
file-devel_files += "/usr/lib/lib*.so"
file-devel_files += "/usr/include/magic.h"
file-devel_files += "/usr/share/man/man3/libmagic.3.gz"

libmagic-data_files = ""
libmagic-data_files += "file.manifest"
libmagic-data_files += "/etc/magic"
libmagic-data_files += "/usr/share/misc/magic.mgc"
libmagic-data_files += "/usr/share/man/man5/magic.5.gz"

file_files = ""
file_files += "file.manifest"
file_files += "/usr/share/man/man1/file.1.gz"

libmagic_files = ""
libmagic_files += "file.manifest"
libmagic_files += "/usr/lib/lib*.so.*"

FILES_${PN}-devel = "${file-devel_files}"
FILES_libmagic-data = "${libmagic-data_files}"
FILES_${PN} = "${file_files}"
FILES_libmagic = "${libmagic_files}"

PKG_file-devel= "file-devel"
PKG_libmagic-data= "libmagic-data"
PKG_file= "file"
PKG_libmagic= "libmagic"

require file-extraconf.inc
