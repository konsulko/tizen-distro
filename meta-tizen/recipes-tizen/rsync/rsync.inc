DESCRIPTION = "A program for synchronizing files over a network"
HOMEPAGE = "http://rsync.samba.org/"
SECTION = "Applications/Internet"
LICENSE = "GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by rsync-support 
PROVIDES += "rsync-support"
RPROVIDES_rsync-support += "rsync-support"

#PROVIDES by rsync 
PROVIDES += "rsync"
RPROVIDES_rsync += "rsync"

#PROVIDES by rsync-docs  
PROVIDES += "rsync-docs "
RPROVIDES_rsync-docs  += "rsync-docs "

RDEPENDS = ""
#RDEPENDS of rsync-support (${PN}-support)
RDEPENDS_${PN}-support += "rsync"


DEPENDS = ""
#DEPENDS of rsync 
DEPENDS += "popt"
DEPENDS += "attr"
DEPENDS += "acl"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/rsync.manifest .
 
 
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
         --infodir=/usr/share/info --disable-static
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
PACKAGES += "rsync"
PACKAGES += "rsync-docs"

rsync_files = ""
rsync_files += "rsync.manifest"
rsync_files += "COPYING"
rsync_files += "/usr/bin/rsync"

rsync-docs_files = ""
rsync-docs_files += "/usr/share/info"
rsync-docs_files += "/usr/share/man"

FILES_${PN} = "${rsync_files}"
FILES_${PN}-docs = "${rsync-docs_files}"

PKG_rsync= "rsync"
PKG_rsync-docs= "rsync-docs"

require rsync-extraconf.inc
