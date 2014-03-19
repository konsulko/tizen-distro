DESCRIPTION = "Intelligent Pinyin engine based on libpinyin for IBus"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by ibus-libpinyin 
PROVIDES += "ibus-libpinyin"
RPROVIDES_ibus-libpinyin += "ibus-libpinyin"

RDEPENDS = ""
#RDEPENDS of ibus-libpinyin (${PN})
RDEPENDS_${PN} += "libpinyin"
RDEPENDS_${PN} += "ibus"


DEPENDS = ""
#DEPENDS of ibus-libpinyin 
DEPENDS += "lua-devel"
DEPENDS += "intltool-native"
DEPENDS += "sqlite-devel"
DEPENDS += "pkgconfig-native"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "ibus"
DEPENDS += "libtool-cross"
DEPENDS += "libpinyin-devel"
DEPENDS += "libuuid-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/ibus-libpinyin.manifest .
 
 
 
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
         --infodir=/usr/share/info --disable-static \
            --disable-boost
 
 # make -C po update-gmo
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf $RPM_BUILD_ROOT
 make DESTDIR=${RPM_BUILD_ROOT} install
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} ibus-libpinyin
 
 
}

PACKAGES = ""
PACKAGES += "ibus-libpinyin"

ibus-libpinyin_files = ""
ibus-libpinyin_files += "ibus-libpinyin.manifest"
ibus-libpinyin_files += "AUTHORS COPYING README"
ibus-libpinyin_files += "/usr/share/applications/*.desktop"
ibus-libpinyin_files += "/usr/libexec/ibus-engine-libpinyin"
ibus-libpinyin_files += "/usr/libexec/ibus-setup-libpinyin"
ibus-libpinyin_files += "/usr/share/ibus-libpinyin/phrases.txt"
ibus-libpinyin_files += "/usr/share/ibus-libpinyin/icons"
ibus-libpinyin_files += "/usr/share/ibus-libpinyin/setup"
ibus-libpinyin_files += "/usr/share/ibus-libpinyin/*.lua"
ibus-libpinyin_files += "/usr/share/ibus-libpinyin/db/*.db"
ibus-libpinyin_files += "/usr/share/ibus-libpinyin"
ibus-libpinyin_files += "/usr/share/ibus-libpinyin/db"
ibus-libpinyin_files += "/usr/share/ibus/component/*"

FILES_${PN} = "${ibus-libpinyin_files}"

PKG_ibus-libpinyin= "ibus-libpinyin"

require ibus-libpinyin-extraconf.inc
