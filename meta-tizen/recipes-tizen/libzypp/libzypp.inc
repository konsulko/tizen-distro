DESCRIPTION = "Package, Patch, Pattern, and Product Management"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Package Management"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libzypp-locale  
PROVIDES += "libzypp-locale "
RPROVIDES_libzypp-locale  += "libzypp-locale "
# the PROVIDES rules is ignore "libzypp-lang-all = 12.11.0"
PROVIDES += "libzypp-lang-all"
RPROVIDES_libzypp-locale  += "libzypp-lang-all"

#PROVIDES by libzypp 
PROVIDES += "libzypp"
RPROVIDES_libzypp += "libzypp"
# the PROVIDES rules is ignore "libzypp(plugin) = 0"
PROVIDES += "libzypp(plugin)"
RPROVIDES_libzypp += "libzypp(plugin)"
# the PROVIDES rules is ignore "libzypp(plugin:commit) = 0"
PROVIDES += "libzypp(plugin:commit)"
RPROVIDES_libzypp += "libzypp(plugin:commit)"
# the PROVIDES rules is ignore "libzypp(plugin:services) = 0"
PROVIDES += "libzypp(plugin:services)"
RPROVIDES_libzypp += "libzypp(plugin:services)"
# the PROVIDES rules is ignore "libzypp(plugin:system) = 0"
PROVIDES += "libzypp(plugin:system)"
RPROVIDES_libzypp += "libzypp(plugin:system)"
# the PROVIDES rules is ignore "libzypp(plugin:urlresolver) = 0"
PROVIDES += "libzypp(plugin:urlresolver)"
RPROVIDES_libzypp += "libzypp(plugin:urlresolver)"

#PROVIDES by libzypp-devel 
PROVIDES += "libzypp-devel"
RPROVIDES_libzypp-devel += "libzypp-devel"
RPROVIDES_libzypp-devel += "libzypp-dev"

RDEPENDS = ""
#RDEPENDS of libzypp-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "libzypp"

#RDEPENDS of libzypp (${PN})
RDEPENDS_${PN} += "libcurl"
RDEPENDS_${PN} += "rpm"
RDEPENDS_${PN} += "libsolv-tools"
RDEPENDS_${PN} += "lsof"

#RDEPENDS of libzypp-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "zlib-dev"
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "bzip2"
RDEPENDS_${PN}-devel += "boost-dev"
RDEPENDS_${PN}-devel += "popt-dev"
RDEPENDS_${PN}-devel += "libstdc++-dev"
RDEPENDS_${PN}-devel += "libxml2-dev"
RDEPENDS_${PN}-devel += "libcurl-dev"
RDEPENDS_${PN}-devel += "openssl-dev"
RDEPENDS_${PN}-devel += "libudev-dev"
RDEPENDS_${PN}-devel += "libzypp"
RDEPENDS_${PN}-devel += "rpm-dev"
RDEPENDS_${PN}-devel += "cmake"
RDEPENDS_${PN}-devel += "libsolv-dev"


DEPENDS = ""
#DEPENDS of libzypp 
DEPENDS += "glib"
DEPENDS += "rpm-devel"
DEPENDS += "gcc-cross"
DEPENDS += "doxygen"
DEPENDS += "cmake"
DEPENDS += "libsolv"
DEPENDS += "libxml2"
DEPENDS += "expat"
DEPENDS += "pkgconfig-native"
DEPENDS += "openssl-devel"
DEPENDS += "libudev-devel"
DEPENDS += "pkgconfig(libproxy-1.0)"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "popt-devel"
DEPENDS += "curl"
DEPENDS += "boost"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libzypp.manifest .
 
 
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
 
 mkdir build
 cd build
 export CFLAGS="$RPM_OPT_FLAGS"
 export CXXFLAGS="$RPM_OPT_FLAGS"
 unset TRANSLATION_SET
 unset EXTRA_CMAKE_OPTIONS
 cmake -DCMAKE_INSTALL_PREFIX=/usr \
       -DDOC_INSTALL_DIR=/usr/share/doc/packages \
       -DLIB=lib \
       -DCMAKE_BUILD_TYPE=Release \
       -DCMAKE_SKIP_RPATH=1 \
       -DUSE_TRANSLATION_SET=${TRANSLATION_SET:-zypp} \
       ${EXTRA_CMAKE_OPTIONS} \
       ..
 make -j16 VERBOSE=1
 make -C doc/autodoc -j16
 make -C po -j16 translations
 
 
 #make check
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf "$RPM_BUILD_ROOT"
 cd build
 make install DESTDIR=$RPM_BUILD_ROOT
 make -C doc/autodoc install DESTDIR=$RPM_BUILD_ROOT
 mkdir -p $RPM_BUILD_ROOT/etc/zypp/repos.d
 mkdir -p $RPM_BUILD_ROOT/etc/zypp/services.d
 mkdir -p $RPM_BUILD_ROOT/etc/zypp/vendors.d
 mkdir -p $RPM_BUILD_ROOT/etc/zypp/multiversion.d
 mkdir -p $RPM_BUILD_ROOT/usr/lib/zypp
 mkdir -p $RPM_BUILD_ROOT/usr/lib/zypp/plugins
 mkdir -p $RPM_BUILD_ROOT/usr/lib/zypp/plugins/commit
 mkdir -p $RPM_BUILD_ROOT/usr/lib/zypp/plugins/services
 mkdir -p $RPM_BUILD_ROOT/usr/lib/zypp/plugins/system
 mkdir -p $RPM_BUILD_ROOT/usr/lib/zypp/plugins/urlresolver
 mkdir -p $RPM_BUILD_ROOT/var/lib/zypp
 mkdir -p $RPM_BUILD_ROOT/var/log/zypp
 mkdir -p $RPM_BUILD_ROOT/var/cache/zypp
 
 make -C po install DESTDIR=$RPM_BUILD_ROOT
 # Create filelist with translations
 cd ..
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} zypp
 
 
}

PACKAGES = ""
PACKAGES += "libzypp"
PACKAGES += "libzypp-devel"
PACKAGES += "libzypp-locale"

libzypp_files = ""
libzypp_files += "libzypp.manifest"
libzypp_files += "/etc/zypp"
libzypp_files += "/etc/zypp/repos.d"
libzypp_files += "/etc/zypp/services.d"
libzypp_files += "/etc/zypp/vendors.d"
libzypp_files += "/etc/zypp/multiversion.d"
libzypp_files += "/etc/zypp/zypp.conf"
libzypp_files += "/etc/zypp/systemCheck"
libzypp_files += "/etc/logrotate.d/zypp-history.lr"
libzypp_files += "/var/lib/zypp"
libzypp_files += "/var/log/zypp"
libzypp_files += "/var/cache/zypp"
libzypp_files += "/usr/lib/zypp"
libzypp_files += "/usr/share/zypp"
libzypp_files += "/usr/bin/*"
libzypp_files += "/usr/lib/libzypp*so.*"
libzypp_files += "/usr/share/man/man5/locks.5.*"

libzypp-devel_files = ""
libzypp-devel_files += "libzypp.manifest"
libzypp-devel_files += "/usr/lib/libzypp.so"
libzypp-devel_files += "/usr/share/doc/packages/libzypp"
libzypp-devel_files += "/usr/include/zypp"
libzypp-devel_files += "/usr/share/cmake/Modules/*"
libzypp-devel_files += "/usr/lib/pkgconfig/libzypp.pc"

libzypp-locale_files = ""

FILES_${PN} = "${libzypp_files}"
FILES_${PN}-devel = "${libzypp-devel_files}"
FILES_${PN}-locale = "${libzypp-locale_files}"

PKG_libzypp= "libzypp"
PKG_libzypp-devel= "libzypp-devel"
PKG_libzypp-locale= "libzypp-locale"

require libzypp-extraconf.inc
