DESCRIPTION = "Pico Editor Clone with Enhancements"
HOMEPAGE = "http://www.nano-editor.org/"
SECTION = "Productivity/Editors/Other"
LICENSE = "GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by nano-docs  
PROVIDES += "nano-docs "
RPROVIDES_nano-docs  += "nano-docs "

#PROVIDES by nano 
PROVIDES += "nano"
RPROVIDES_nano += "nano"

#PROVIDES by nano-locale  
PROVIDES += "nano-locale "
RPROVIDES_nano-locale  += "nano-locale "
# the PROVIDES rules is ignore "nano-lang-all = 2.3.1"
PROVIDES += "nano-lang-all"
RPROVIDES_nano-locale  += "nano-lang-all"

RDEPENDS = ""
#RDEPENDS of nano-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "nano"


DEPENDS = ""
#DEPENDS of nano 
DEPENDS += "file"
DEPENDS += "ncurses-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/nano.manifest .
 
 # Remove build time references so build-compare can do its work
 FAKE_BUILDTIME=$(LC_ALL=C date -u -r ${S}/packaging//nano.changes '+%H:%M')
 FAKE_BUILDDATE=$(LC_ALL=C date -u -r ${S}/packaging//nano.changes '+%b %e %Y')
 sed -i "s/__TIME__/\"$FAKE_BUILDTIME\"/" src/nano.c
 sed -i "s/__DATE__/\"$FAKE_BUILDDATE\"/" src/nano.c
 
 
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
         --infodir=/usr/share/info --disable-rpath --enable-utf8
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
 
 # Remove doc files from /usr/share/nano (they should be in defaultdocdir)
 rm -rf ${D}/usr/share/nano/man-html/
 rm -rf ${D}/usr/share/man/fr
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} nano --all-name
 
 
 
}

PACKAGES = ""
PACKAGES += "nano-locale"
PACKAGES += "nano-docs"
PACKAGES += "nano"

nano-locale_files = ""

nano-docs_files = ""
nano-docs_files += "/usr/share/info"
nano-docs_files += "/usr/share/man"

nano_files = ""
nano_files += "nano.manifest"
nano_files += "/usr/bin/nano"
nano_files += "/usr/bin/rnano"
nano_files += "/usr/share/nano/"

FILES_${PN}-locale = "${nano-locale_files}"
FILES_${PN}-docs = "${nano-docs_files}"
FILES_${PN} = "${nano_files}"

PKG_nano-locale= "nano-locale"
PKG_nano-docs= "nano-docs"
PKG_nano= "nano"

require nano-extraconf.inc
