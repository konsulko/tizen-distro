DESCRIPTION = "A library management system"
HOMEPAGE = "http://pkgconfig.freedesktop.org/"
SECTION = "Base/Tools"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by pkg-config-docs  
PROVIDES += "pkg-config-docs "
RPROVIDES_pkg-config-docs  += "pkg-config-docs "

#PROVIDES by pkg-config 
PROVIDES += "pkg-config"
RPROVIDES_pkg-config += "pkg-config"
# the PROVIDES rules is ignore "pkgconfig = 0.28"
PROVIDES += "pkgconfig"
RPROVIDES_pkg-config += "pkgconfig"
# the PROVIDES rules is ignore "pkgconfig(pkg-config) = 0.28"
PROVIDES += "pkgconfig(pkg-config)"
RPROVIDES_pkg-config += "pkgconfig(pkg-config)"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/pkg-config.manifest .
 
 
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
         --infodir=/usr/share/info\
     --with-internal-glib \
        --with-pc_path=/usr/local/lib/pkgconfig:/usr/local/share/pkgconfig:/usr/lib/pkgconfig:/usr/share/pkgconfig:/opt/kde3/lib/pkgconfig
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
 rm ${D}/usr/share/doc/pkg-config/pkg-config-guide.html
 
 
}

PACKAGES = ""
PACKAGES += "pkg-config-docs"
PACKAGES += "pkg-config"

pkg-config-docs_files = ""
pkg-config-docs_files += "/usr/share/info"
pkg-config-docs_files += "/usr/share/man"

pkg-config_files = ""
pkg-config_files += "pkg-config.manifest"
pkg-config_files += "/usr/bin/pkg-config"
pkg-config_files += "/usr/bin/*-pkg-config"
pkg-config_files += "/usr/share/aclocal"
pkg-config_files += "/usr/share/aclocal/pkg.m4"

FILES_${PN}-docs = "${pkg-config-docs_files}"
FILES_${PN} = "${pkg-config_files}"

PKG_pkg-config-docs= "pkg-config-docs"
PKG_pkg-config= "pkg-config"

require pkg-config-extraconf.inc
