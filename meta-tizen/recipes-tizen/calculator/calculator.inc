DESCRIPTION = "SLP Calculator application"
HOMEPAGE = "http://nohomepage.org"
SECTION = "tizen/Application"
LICENSE = "TIZEN"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by org.tizen.calculator 
PROVIDES += "org.tizen.calculator"
RPROVIDES_org.tizen.calculator += "org.tizen.calculator"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of org.tizen.calculator 
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "cmake"
DEPENDS += "pkgconfig(edje)"
DEPENDS += "pkgconfig(ecore)"
DEPENDS += "app-core"
DEPENDS += "embryo-bin"
DEPENDS += "pkgconfig(capi-appfw-application)"
DEPENDS += "pkgconfig(elementary)"
DEPENDS += "pkgconfig(feedback)"
DEPENDS += "edje-bin"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(dlog)"
DEPENDS += "pkgconfig(embryo)"
DEPENDS += "pkgconfig(vconf)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/org.tizen.calculator.manifest .
 
 
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
 
 
 LDFLAGS+="-Wl,--rpath=/usr/apps/org.tizen.calculator/lib -Wl,--as-needed -Wl,--hash-style=both"; export LDFLAGS
 
 cmake . -DCMAKE_INSTALL_PREFIX=/usr/apps/org.tizen.calculator
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "org.tizen.calculator"

org.tizen.calculator_files = ""
org.tizen.calculator_files += "org.tizen.calculator.manifest"
org.tizen.calculator_files += "/usr/apps/org.tizen.calculator/bin/calculator"
org.tizen.calculator_files += "/usr/apps/org.tizen.calculator/res/edje/calculator.edj"
org.tizen.calculator_files += "/usr/apps/org.tizen.calculator/res/edje/calculator_theme.edj"
org.tizen.calculator_files += "/usr/share/icons/default/small/org.tizen.calculator.png"
org.tizen.calculator_files += "/usr/apps/org.tizen.calculator/res/icons/org.tizen.calculator.png"
org.tizen.calculator_files += "/usr/apps/org.tizen.calculator/res/locale/*"
org.tizen.calculator_files += "/usr/share/packages/org.tizen.calculator.xml"
org.tizen.calculator_files += "/usr/share/process-info/calculator.ini"

FILES_${PN} = "${org.tizen.calculator_files}"

PKG_org.tizen.calculator= "org.tizen.calculator"

require calculator-extraconf.inc
