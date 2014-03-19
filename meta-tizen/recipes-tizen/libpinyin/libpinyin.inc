DESCRIPTION = "Library to deal with pinyin"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libpinyin 
PROVIDES += "libpinyin"
RPROVIDES_libpinyin += "libpinyin"

#PROVIDES by libpinyin-devel 
PROVIDES += "libpinyin-devel"
RPROVIDES_libpinyin-devel += "libpinyin-devel"
RPROVIDES_libpinyin-devel += "libpinyin-dev"

#PROVIDES by libpinyin-tools 
PROVIDES += "libpinyin-tools"
RPROVIDES_libpinyin-tools += "libpinyin-tools"

RDEPENDS = ""
#RDEPENDS of libpinyin-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libpinyin"

#RDEPENDS of libpinyin-tools (${PN}-tools)
RDEPENDS_${PN}-tools += "libpinyin"


DEPENDS = ""
#DEPENDS of libpinyin 
DEPENDS += "glib"
DEPENDS += "db4"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libpinyin.manifest .
 
 
 
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
 
 make install DESTDIR=$RPM_BUILD_ROOT
 find $RPM_BUILD_ROOT -name '*.la' -exec rm -f {} ';'
 
 
 
}

PACKAGES = ""
PACKAGES += "libpinyin"
PACKAGES += "libpinyin-devel"
PACKAGES += "libpinyin-tools"

libpinyin_files = ""
libpinyin_files += "libpinyin.manifest"
libpinyin_files += "AUTHORS COPYING README"
libpinyin_files += "/usr/lib/*.so.*"
libpinyin_files += "/usr/lib/libpinyin"
libpinyin_files += "/usr/lib/libpinyin/data"

libpinyin-devel_files = ""
libpinyin-devel_files += "libpinyin.manifest"
libpinyin-devel_files += "/usr/include/libpinyin-1.0.0"
libpinyin-devel_files += "/usr/include/libpinyin-1.0.0/*"
libpinyin-devel_files += "/usr/lib/*.so"
libpinyin-devel_files += "/usr/lib/pkgconfig/libpinyin.pc"

libpinyin-tools_files = ""
libpinyin-tools_files += "libpinyin.manifest"
libpinyin-tools_files += "/usr/bin/gen_binary_files"
libpinyin-tools_files += "/usr/bin/import_interpolation"
libpinyin-tools_files += "/usr/bin/gen_unigram"
libpinyin-tools_files += "/usr/share/man/man1/*.1.*"

FILES_${PN} = "${libpinyin_files}"
FILES_${PN}-devel = "${libpinyin-devel_files}"
FILES_${PN}-tools = "${libpinyin-tools_files}"

PKG_libpinyin= "libpinyin"
PKG_libpinyin-devel= "libpinyin-devel"
PKG_libpinyin-tools= "libpinyin-tools"

require libpinyin-extraconf.inc
