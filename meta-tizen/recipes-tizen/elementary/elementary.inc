DESCRIPTION = "EFL toolkit for small touchscreens"
HOMEPAGE = "http://trac.enlightenment.org/e/wiki/Elementary"
SECTION = "Graphics/EFL"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by elementary 
PROVIDES += "elementary"
RPROVIDES_elementary += "elementary"

#PROVIDES by elementary-tools 
PROVIDES += "elementary-tools"
RPROVIDES_elementary-tools += "elementary-tools"

#PROVIDES by elementary-devel 
PROVIDES += "elementary-devel"
RPROVIDES_elementary-devel += "elementary-devel"
RPROVIDES_elementary-devel += "elementary-dev"

#PROVIDES by elementary-examples 
PROVIDES += "elementary-examples"
RPROVIDES_elementary-examples += "elementary-examples"

#PROVIDES by elementary-locale  
PROVIDES += "elementary-locale "
RPROVIDES_elementary-locale  += "elementary-locale "
# the PROVIDES rules is ignore "elementary-lang-all = 1.7.8"
PROVIDES += "elementary-lang-all"
RPROVIDES_elementary-locale  += "elementary-lang-all"

RDEPENDS = ""
#RDEPENDS of elementary-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "elementary"

#RDEPENDS of elementary-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "elementary"


DEPENDS = ""
#DEPENDS of elementary 
DEPENDS += "pkgconfig(ecore-wayland)"
DEPENDS += "pkgconfig(emotion)"
DEPENDS += "doxygen"
DEPENDS += "pkgconfig(evas)"
DEPENDS += "pkgconfig(edje)"
DEPENDS += "eet"
DEPENDS += "pkgconfig(ecore-fb)"
DEPENDS += "python-devel"
DEPENDS += "pkgconfig(ecore-evas)"
DEPENDS += "pkgconfig(eet)"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "pkgconfig(ethumb_client)"
DEPENDS += "pkgconfig(ecore-imf)"
DEPENDS += "pkgconfig(ecore-file)"
DEPENDS += "pkgconfig(efreet)"
DEPENDS += "pkgconfig(edbus)"
DEPENDS += "ecore"
DEPENDS += "pkgconfig(eina)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/elementary.manifest .
 
 
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
          --enable-ecore-wayland \
          --disable-ecore-x \
          --enable-build-examples
 
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
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} elementary
 
 
}

PACKAGES = ""
PACKAGES += "elementary-locale"
PACKAGES += "elementary"
PACKAGES += "elementary-tools"
PACKAGES += "elementary-devel"
PACKAGES += "elementary-examples"

elementary-locale_files = ""

elementary_files = ""
elementary_files += "elementary.manifest"
elementary_files += "/usr/bin/elementary_quicklaunch"
elementary_files += "/usr/bin/elementary_run"
elementary_files += "/usr/lib/edje/*"
elementary_files += "/usr/lib/elementary/modules/*"
elementary_files += "/usr/lib/*.so.*"
elementary_files += "/usr/share/elementary/*"
elementary_files += "/usr/share/icons/elementary.png"

elementary-tools_files = ""
elementary-tools_files += "/usr/share/applications/*"
elementary-tools_files += "/usr/bin/elementary_config"
elementary-tools_files += "/usr/bin/elementary_test*"

elementary-devel_files = ""
elementary-devel_files += "elementary.manifest"
elementary-devel_files += "/usr/include/elementary-1/*.h"
elementary-devel_files += "/usr/lib/*.so"
elementary-devel_files += "/usr/lib/pkgconfig/*.pc"

elementary-examples_files = ""
elementary-examples_files += "/usr/lib/elementary/examples/*"

FILES_${PN}-locale = "${elementary-locale_files}"
FILES_${PN} = "${elementary_files}"
FILES_${PN}-tools = "${elementary-tools_files}"
FILES_${PN}-devel = "${elementary-devel_files}"
FILES_${PN}-examples = "${elementary-examples_files}"

PKG_elementary-locale= "elementary-locale"
PKG_elementary= "elementary"
PKG_elementary-tools= "elementary-tools"
PKG_elementary-devel= "elementary-devel"
PKG_elementary-examples= "elementary-examples"

require elementary-extraconf.inc
