DESCRIPTION = "A tool that is used for power diagnostics"
HOMEPAGE = "http://www.01.org"
SECTION = "System/Utilities"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by powertop 
PROVIDES += "powertop"
RPROVIDES_powertop += "powertop"

#PROVIDES by powertop-locale  
PROVIDES += "powertop-locale "
RPROVIDES_powertop-locale  += "powertop-locale "
# the PROVIDES rules is ignore "powertop-lang-all = 2.5"
PROVIDES += "powertop-lang-all"
RPROVIDES_powertop-locale  += "powertop-lang-all"

#PROVIDES by powertop-docs  
PROVIDES += "powertop-docs "
RPROVIDES_powertop-docs  += "powertop-docs "

RDEPENDS = ""
#RDEPENDS of powertop-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "powertop"


DEPENDS = ""
#DEPENDS of powertop 
DEPENDS += "ncurses"
DEPENDS += "zlib-devel"
DEPENDS += "pkgconfig(libnl-1)"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "pciutils"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/powertop.manifest .
 
 
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
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} powertop
 
 
 
}

PACKAGES = ""
PACKAGES += "powertop"
PACKAGES += "powertop-locale"
PACKAGES += "powertop-docs"

powertop_files = ""
powertop_files += "powertop.manifest"
powertop_files += "/usr/sbin/powertop"

powertop-locale_files = ""

powertop-docs_files = ""
powertop-docs_files += "/usr/share/info"
powertop-docs_files += "/usr/share/man"

FILES_${PN} = "${powertop_files}"
FILES_${PN}-locale = "${powertop-locale_files}"
FILES_${PN}-docs = "${powertop-docs_files}"

PKG_powertop= "powertop"
PKG_powertop-locale= "powertop-locale"
PKG_powertop-docs= "powertop-docs"

require powertop-extraconf.inc
