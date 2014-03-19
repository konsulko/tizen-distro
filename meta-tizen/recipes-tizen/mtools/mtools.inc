DESCRIPTION = "Access Files on an MS-DOS File System"
HOMEPAGE = "http://mtools.linux.lu/"
SECTION = "System/Filesystems"
LICENSE = "GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by mtools-doc 
PROVIDES += "mtools-doc"
RPROVIDES_mtools-doc += "mtools-doc"

#PROVIDES by mtools-docs  
PROVIDES += "mtools-docs "
RPROVIDES_mtools-docs  += "mtools-docs "

#PROVIDES by mtools 
PROVIDES += "mtools"
RPROVIDES_mtools += "mtools"

RDEPENDS = ""
#RDEPENDS of mtools-doc (${PN}-doc)
RDEPENDS_${PN}-doc += "mtools"


DEPENDS = ""
#DEPENDS of mtools 
DEPENDS += "autoconf-native"
DEPENDS += "makeinfo"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/mtools.manifest .
 
 
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
 
 autoconf --force
 export CC=gcc
 export INSTALL_PROGRAM="install"
 
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
     --includedir=/usr/src/linux/include
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 install -d -m 755 ${D}/etc
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 cp -p mtools.conf ${D}/etc
 
 rm -rf ${D}/usr/share/man/man?*/f*
 rm -rf ${D}/usr/bin/f*
 
 
 
}

PACKAGES = ""
PACKAGES += "mtools-docs"
PACKAGES += "mtools"

mtools-docs_files = ""
mtools-docs_files += "/usr/share/info"
mtools-docs_files += "/usr/share/man"

mtools_files = ""
mtools_files += "mtools.manifest"
mtools_files += "/etc/mtools.conf"
mtools_files += "/usr/bin/*"

FILES_${PN}-docs = "${mtools-docs_files}"
FILES_${PN} = "${mtools_files}"

PKG_mtools-docs= "mtools-docs"
PKG_mtools= "mtools"

require mtools-extraconf.inc
