DESCRIPTION = "Commands for Manipulating Extended Attributes"
HOMEPAGE = "http://download.savannah.gnu.org/releases-noredirect/attr/"
SECTION = "Base/File Systems"
LICENSE = "GPL-2.0+  LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libattr-devel-static 
PROVIDES += "libattr-devel-static"
RPROVIDES_libattr-devel-static += "libattr-devel-static"
RPROVIDES_libattr-devel-static += "libattr-dev"
# the PROVIDES rules is ignore "libattr-devel:/lib/libattr.a  "
PROVIDES += "libattr-devel:/lib/libattr.a"
RPROVIDES_libattr-devel-static += "libattr-devel:/lib/libattr.a"
RPROVIDES_libattr-devel-static += "libattr-dev"

#PROVIDES by libattr-devel 
PROVIDES += "libattr-devel"
RPROVIDES_libattr-devel += "libattr-devel"
RPROVIDES_libattr-devel += "libattr-dev"
# the PROVIDES rules is ignore "attr-devel  "
PROVIDES += "attr-devel"
RPROVIDES_libattr-devel += "attr-devel"
RPROVIDES_libattr-devel += "attr-dev"

#PROVIDES by attr-docs  
PROVIDES += "attr-docs "
RPROVIDES_attr-docs  += "attr-docs "

#PROVIDES by attr 
PROVIDES += "attr"
RPROVIDES_attr += "attr"

#PROVIDES by libattr 
PROVIDES += "libattr"
RPROVIDES_libattr += "libattr"

RDEPENDS = ""
#RDEPENDS of libattr-devel-static (lib${PN}-devel-static)
RDEPENDS_lib${PN}-devel-static += "libattr-dev"

#RDEPENDS of libattr-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "glibc-dev"
RDEPENDS_lib${PN}-devel += "libattr"


DEPENDS = ""
#DEPENDS of attr 
DEPENDS += "autoconf-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/attr.manifest .
 
 
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
 autoconf
 CFLAGS="$RPM_OPT_FLAGS" \
 
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
         --libdir=/lib \
         --libexecdir=/usr/lib \
         --localstatedir=/var \
         --sharedstatedir=/usr/com \
         --mandir=/usr/share/man \
         --infodir=/usr/share/info \
 	--prefix=/ \
 	--enable-gettext=no \
 	--exec-prefix=/ \
 	--sbindir=/usr/sbin \
 	--libdir=/lib \
 	--libexecdir=/lib \
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
 rm -f $RPM_BUILD_ROOT/usr/share/man/man2/*xattr.2*
 rm -f $RPM_BUILD_ROOT//lib/libattr.la
 install -d -m 755 $RPM_BUILD_ROOT//etc
 install -m 644 ${S}/packaging//xattr.conf $RPM_BUILD_ROOT//etc
 chmod 755 $RPM_BUILD_ROOT//lib/libattr.so.1*
 
 
}

PACKAGES = ""
PACKAGES += "libattr-devel-static"
PACKAGES += "libattr-devel"
PACKAGES += "attr"
PACKAGES += "attr-docs"
PACKAGES += "libattr"

libattr-devel-static_files = ""
libattr-devel-static_files += "attr.manifest"
libattr-devel-static_files += "/lib/libattr.a"

libattr-devel_files = ""
libattr-devel_files += "attr.manifest"
#Remove rpm attribut "%attr(755,root,root)"
libattr-devel_files += "/usr/include/attr"

attr_files = ""
attr_files += "attr.manifest"
#Remove rpm attribut "%attr(755,root,root)"
attr_files += "/usr/share/doc/packages/attr"
#Remove rpm attribut "%attr(644,root,root)"
attr_files += "/usr/share/doc/packages/attr/README"
#Remove rpm attribut "%attr(644,root,root)"
attr_files += "/usr/share/doc/packages/attr/CHANGES.gz"
#Remove rpm attribut "%attr(644,root,root)"
attr_files += "/usr/share/doc/packages/attr/COPYING"
#Remove rpm attribut "%attr(644,root,root)"
attr_files += "/usr/share/doc/packages/attr/PORTING"

attr-docs_files = ""
attr-docs_files += "/usr/share/info"
attr-docs_files += "/usr/share/man"

libattr_files = ""
libattr_files += "attr.manifest"
libattr_files += "/lib/libattr.so.1*"
libattr_files += "/etc/xattr.conf"

FILES_lib${PN}-devel-static = "${libattr-devel-static_files}"
FILES_lib${PN}-devel = "${libattr-devel_files}"
FILES_${PN} = "${attr_files}"
FILES_${PN}-docs = "${attr-docs_files}"
FILES_lib${PN} = "${libattr_files}"

PKG_libattr-devel-static= "libattr-devel-static"
PKG_libattr-devel= "libattr-devel"
PKG_attr= "attr"
PKG_attr-docs= "attr-docs"
PKG_libattr= "libattr"

require attr-extraconf.inc
