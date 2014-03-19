DESCRIPTION = "GNU implementation of tar ((t)ape (ar)chiver)"
HOMEPAGE = "http://www.gnu.org/software/tar/"
SECTION = "System/Utilities"
LICENSE = "GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by tar-docs  
PROVIDES += "tar-docs "
RPROVIDES_tar-docs  += "tar-docs "

#PROVIDES by tar 
PROVIDES += "tar"
RPROVIDES_tar += "tar"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of tar 
DEPENDS += "help2man-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/tar.manifest .
 
 
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
 
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -W -Wall -Wpointer-arith -Wstrict-prototypes -Wformat-security -Wno-unused-parameter"
 export RSH="/usr/bin/rsh"
 export DEFAULT_ARCHIVE_FORMAT="POSIX"
 
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
 	gl_cv_func_linkat_follow="yes" \
 	--disable-silent-rules \
 	--disable-nls
 make -j16;
 
 exit 0
 # Checks disabled in qemu because of races happening when we emulate
 # multi-threaded programs
 make check
 
 
 
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
 install -d -m 755 ${D}//usr/share/man/man1
 help2man ./src/tar --name "The GNU version of the tar archiving utility" -p tar \
         | gzip -c > ${D}//usr/share/man/man1/tar.1.gz
 rm -rf ${D}/usr/libexec/rmt
 rm -f ${D}/usr/share/info/dir
 
 
 
 
}

PACKAGES = ""
PACKAGES += "tar-docs"
PACKAGES += "tar"

tar-docs_files = ""
tar-docs_files += "/usr/share/info"
tar-docs_files += "/usr/share/man"

tar_files = ""
tar_files += "tar.manifest"
tar_files += "/usr/bin/tar"

FILES_${PN}-docs = "${tar-docs_files}"
FILES_${PN} = "${tar_files}"

PKG_tar-docs= "tar-docs"
PKG_tar= "tar"

require tar-extraconf.inc
