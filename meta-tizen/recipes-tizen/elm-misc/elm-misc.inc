DESCRIPTION = "Elementary config files"
HOMEPAGE = "http://nohomepage.org"
SECTION = "TO_BE/FILLED_IN"
LICENSE = "LGPLv2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by elm-misc 
PROVIDES += "elm-misc"
RPROVIDES_elm-misc += "elm-misc"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/elm-misc.manifest .
 
 
 
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
 
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 /bin/mkdir -p ${D}/etc/profile.d
 /bin/cp etc/profile.d/* ${D}/etc/profile.d/
 mkdir -p ${D}/usr/share/license
 cp ${WORKDIR}/git/COPYING ${D}/usr/share/license/elm-misc
 
 
}

PACKAGES = ""
PACKAGES += "elm-misc"

elm-misc_files = ""
elm-misc_files += "elm-misc.manifest"
elm-misc_files += "/etc/profile.d/*"
elm-misc_files += "/usr/share/license/elm-misc"

FILES_${PN} = "${elm-misc_files}"

PKG_elm-misc= "elm-misc"

require elm-misc-extraconf.inc
