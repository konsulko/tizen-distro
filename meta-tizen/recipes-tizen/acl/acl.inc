DESCRIPTION = "Commands for Manipulating POSIX Access Control Lists"
HOMEPAGE = "http://download.savannah.gnu.org/releases-noredirect/acl/"
SECTION = "Security/Access Control"
LICENSE = "GPL-2.0+ and LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libacl 
PROVIDES += "libacl"
RPROVIDES_libacl += "libacl"

#PROVIDES by acl-docs  
PROVIDES += "acl-docs "
RPROVIDES_acl-docs  += "acl-docs "

#PROVIDES by libacl-devel 
PROVIDES += "libacl-devel"
RPROVIDES_libacl-devel += "libacl-devel"
RPROVIDES_libacl-devel += "libacl-dev"

#PROVIDES by acl 
PROVIDES += "acl"
RPROVIDES_acl += "acl"

RDEPENDS = ""
#RDEPENDS of libacl-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "libattr-dev"
RDEPENDS_lib${PN}-devel += "libacl"
RDEPENDS_lib${PN}-devel += "glibc-dev"


DEPENDS = ""
#DEPENDS of acl 
DEPENDS += "libattr-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n acl-2.2.51
 cp ${S}/packaging/acl.manifest .
 
 
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
 
 export OPTIMIZER="$RPM_OPT_FLAGS -fPIC"
 export DEBUG=-DNDEBUG
 CFLAGS="$RPM_OPT_FLAGS"
 
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
 	--prefix=/ \
 	--exec-prefix=/ \
 	--libdir=/usr/lib \
 	--libexecdir=/usr/lib \
 	--enable-gettext=no \
 	--disable-static \
 	--with-pic
 oe_runmake -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 DIST_ROOT="$RPM_BUILD_ROOT"
 DIST_INSTALL=`pwd`/install.manifest
 DIST_INSTALL_DEV=`pwd`/install-dev.manifest
 DIST_INSTALL_LIB=`pwd`/install-lib.manifest
 export DIST_ROOT DIST_INSTALL DIST_INSTALL_DEV DIST_INSTALL_LIB
 /usr/bin/make install DIST_MANIFEST="$DIST_INSTALL"
 /usr/bin/make install-dev DIST_MANIFEST="$DIST_INSTALL_DEV"
 /usr/bin/make install-lib DIST_MANIFEST="$DIST_INSTALL_LIB"
 
 rm ${D}/usr/share/doc/packages/acl/COPYING*
 
 rm -f ${D}//usr/lib/*.{a,la}
 
 
}

PACKAGES = ""
PACKAGES += "libacl"
PACKAGES += "acl-docs"
PACKAGES += "libacl-devel"
PACKAGES += "acl"

libacl_files = ""
libacl_files += "acl.manifest"
libacl_files += "/usr/lib/libacl.so.1*"

acl-docs_files = ""
acl-docs_files += "/usr/share/info"
acl-docs_files += "/usr/share/man"

libacl-devel_files = ""
libacl-devel_files += "acl.manifest"
#Remove rpm attribut "%attr(755,root,root)"
libacl-devel_files += "/usr/include/acl"

acl_files = ""
acl_files += "acl.manifest"
#Remove rpm attribut "%attr(755,root,root)"
acl_files += "/usr/share/doc/packages/acl"
#Remove rpm attribut "%attr(644,root,root)"
acl_files += "/usr/share/doc/packages/acl/CHANGES.gz"
#Remove rpm attribut "%attr(644,root,root)"
acl_files += "/usr/share/doc/packages/acl/PORTING"
#Remove rpm attribut "%attr(644,root,root)"
acl_files += "/usr/share/doc/packages/acl/README"

FILES_lib${PN} = "${libacl_files}"
FILES_${PN}-docs = "${acl-docs_files}"
FILES_lib${PN}-devel = "${libacl-devel_files}"
FILES_${PN} = "${acl_files}"

PKG_libacl= "libacl"
PKG_acl-docs= "acl-docs"
PKG_libacl-devel= "libacl-devel"
PKG_acl= "acl"

require acl-extraconf.inc
