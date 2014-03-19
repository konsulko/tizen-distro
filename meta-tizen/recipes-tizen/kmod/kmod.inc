DESCRIPTION = "Utilities to load modules into the kernel"
HOMEPAGE = "http://www.politreco.com/2011/12/announce-kmod-2/"
SECTION = "Base/Libraries"
LICENSE = "LGPL-2.1+ and GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libkmod-devel 
PROVIDES += "libkmod-devel"
RPROVIDES_libkmod-devel += "libkmod-devel"
RPROVIDES_libkmod-devel += "libkmod-dev"

#PROVIDES by kmod 
PROVIDES += "kmod"
RPROVIDES_kmod += "kmod"

#PROVIDES by kmod-compat 
PROVIDES += "kmod-compat"
RPROVIDES_kmod-compat += "kmod-compat"
# the PROVIDES rules is ignore "module-init-tools  "
PROVIDES += "module-init-tools"
RPROVIDES_kmod-compat += "module-init-tools"

#PROVIDES by kmod-docs  
PROVIDES += "kmod-docs "
RPROVIDES_kmod-docs  += "kmod-docs "

#PROVIDES by libkmod 
PROVIDES += "libkmod"
RPROVIDES_libkmod += "libkmod"

RDEPENDS = ""
#RDEPENDS of libkmod-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "libkmod"

#RDEPENDS of kmod-compat (${PN}-compat)
RDEPENDS_${PN}-compat += "kmod"
RDEPENDS_${PN}-compat += "filesystem"


DEPENDS = ""
#DEPENDS of kmod 
DEPENDS += "zlib-devel"
DEPENDS += "pkgconfig-native"
DEPENDS += "automake-native"
DEPENDS += "xz"
DEPENDS += "libtool-cross"
DEPENDS += "pkgconfig(liblzma)"
DEPENDS += "autoconf-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/kmod.manifest .
 
 
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
 
 autoreconf -fi
 # The extra --includedir gives us the possibility to detect dependent
 # packages which fail to properly use pkgconfig.
 
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
    --with-xz \
    --disable-manpages \
    --with-zlib \
    --includedir=/usr/include/kmod-15 \
    --with-rootlibdir=/usr/lib \
    --bindir=/usr/bin
 make -j16
 
 exit 0
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
 
 # kmod-compat
 mkdir -p ${D}//usr/sbin
 ln -s /usr/bin/kmod ${D}//usr/bin/lsmod
 for i in depmod insmod lsmod modinfo modprobe rmmod; do
 	ln -s /usr/bin/kmod ${D}//usr/sbin/$i
 done;
 
 
 
}

PACKAGES = ""
PACKAGES += "libkmod-devel"
PACKAGES += "kmod"
PACKAGES += "kmod-docs"
PACKAGES += "kmod-compat"
PACKAGES += "libkmod"

libkmod-devel_files = ""
libkmod-devel_files += "kmod.manifest"
libkmod-devel_files += "/usr/include/*"
libkmod-devel_files += "/usr/lib/pkgconfig/libkmod.pc"
libkmod-devel_files += "/usr/lib/libkmod.so"

kmod_files = ""
kmod_files += "kmod.manifest"
kmod_files += "LGPL-2.1+ COPYING"
kmod_files += "/usr/bin/kmod"
kmod_files += "/usr/share/bash-completion/completions"
kmod_files += "/usr/share/bash-completion/completions/kmod"

kmod-docs_files = ""
kmod-docs_files += "/usr/share/info"
kmod-docs_files += "/usr/share/man"

kmod-compat_files = ""
kmod-compat_files += "kmod.manifest"
kmod-compat_files += "/usr/bin/lsmod"
kmod-compat_files += "/usr/sbin/depmod"
kmod-compat_files += "/usr/sbin/insmod"
kmod-compat_files += "/usr/sbin/lsmod"
kmod-compat_files += "/usr/sbin/modinfo"
kmod-compat_files += "/usr/sbin/modprobe"
kmod-compat_files += "/usr/sbin/rmmod"

libkmod_files = ""
libkmod_files += "kmod.manifest"
libkmod_files += "/usr/lib/libkmod.so.2*"

FILES_lib${PN}-devel = "${libkmod-devel_files}"
FILES_${PN} = "${kmod_files}"
FILES_${PN}-docs = "${kmod-docs_files}"
FILES_${PN}-compat = "${kmod-compat_files}"
FILES_lib${PN} = "${libkmod_files}"

PKG_libkmod-devel= "libkmod-devel"
PKG_kmod= "kmod"
PKG_kmod-docs= "kmod-docs"
PKG_kmod-compat= "kmod-compat"
PKG_libkmod= "libkmod"

require kmod-extraconf.inc
