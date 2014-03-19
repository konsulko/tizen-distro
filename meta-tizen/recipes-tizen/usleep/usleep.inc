DESCRIPTION = "Sleeps for microseconds"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Base"
LICENSE = "GPLv2"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by usleep 
PROVIDES += "usleep"
RPROVIDES_usleep += "usleep"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of usleep 
DEPENDS += "popt"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n usleep-1
 
 # >> setup
 # << setup
 
 
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
 
 # >> build pre
 # << build pre
 
 cp ${S}/packaging/usleep.manifest .
 make -j16
 
 # >> build post
 # << build post
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 # >> install pre
 # << install pre
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 # >> install post
 
 
 # << install post
 
 
 
 
 
 
 
}

PACKAGES = ""
PACKAGES += "usleep"

usleep_files = ""
usleep_files += "usleep.manifest"
usleep_files += "usleep.manifest"
usleep_files += "/usr/share/man/man*/*"
usleep_files += "/bin/usleep"

FILES_${PN} = "${usleep_files}"

PKG_usleep= "usleep"

require usleep-extraconf.inc
