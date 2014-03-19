DESCRIPTION = "The GNU disk partition manipulation program"
HOMEPAGE = "http://www.gnu.org/software/parted"
SECTION = "Applications/System"
LICENSE = "GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by parted-docs  
PROVIDES += "parted-docs "
RPROVIDES_parted-docs  += "parted-docs "

#PROVIDES by parted 
PROVIDES += "parted"
RPROVIDES_parted += "parted"

#PROVIDES by parted-locale  
PROVIDES += "parted-locale "
RPROVIDES_parted-locale  += "parted-locale "
# the PROVIDES rules is ignore "parted-lang-all = 3.1"
PROVIDES += "parted-lang-all"
RPROVIDES_parted-locale  += "parted-lang-all"

#PROVIDES by parted-devel 
PROVIDES += "parted-devel"
RPROVIDES_parted-devel += "parted-devel"
RPROVIDES_parted-devel += "parted-dev"

RDEPENDS = ""
#RDEPENDS of parted-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "parted"

#RDEPENDS of parted-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "parted"
RDEPENDS_${PN}-devel += "pkgconfig"


DEPENDS = ""
#DEPENDS of parted 
DEPENDS += "readline-devel"
DEPENDS += "ncurses"
DEPENDS += "texinfo-native"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "libtool-cross"
DEPENDS += "e2fsprogs"
DEPENDS += "libuuid-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/parted.manifest .
 
 
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
         --sbindir=/sbin \
         --sysconfdir=/etc \
         --datadir=/usr/share \
         --includedir=/usr/include \
         --libdir=/usr/lib \
         --libexecdir=/usr/libexec \
         --localstatedir=/var \
         --sharedstatedir=/usr/com \
         --mandir=/usr/share/man \
         --infodir=/usr/share/info --disable-static --disable-device-mapper --with-readline --with-libdir=/usr/lib --exec-prefix=/usr
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
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} parted
 
 
}

PACKAGES = ""
PACKAGES += "parted-devel"
PACKAGES += "parted-locale"
PACKAGES += "parted"
PACKAGES += "parted-docs"

parted-devel_files = ""
parted-devel_files += "parted.manifest"
parted-devel_files += "/usr/include/parted"
parted-devel_files += "/usr/lib/libparted.so"
parted-devel_files += "/usr/lib/libparted-fs-resize.so"
parted-devel_files += "/usr/lib/pkgconfig/libparted.pc"

parted-locale_files = ""

parted_files = ""
parted_files += "parted.manifest"
parted_files += "/sbin/parted"
parted_files += "/sbin/partprobe"
parted_files += "/usr/lib/libparted*.so.*"

parted-docs_files = ""
parted-docs_files += "/usr/share/info"
parted-docs_files += "/usr/share/man"

FILES_${PN}-devel = "${parted-devel_files}"
FILES_${PN}-locale = "${parted-locale_files}"
FILES_${PN} = "${parted_files}"
FILES_${PN}-docs = "${parted-docs_files}"

PKG_parted-devel= "parted-devel"
PKG_parted-locale= "parted-locale"
PKG_parted= "parted"
PKG_parted-docs= "parted-docs"

require parted-extraconf.inc
