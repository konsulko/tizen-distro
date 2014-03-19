DESCRIPTION = "A Japanese character input system library.(with dictionary)"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System Environment/Libraries"
LICENSE = "GPL"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by anthy 
PROVIDES += "anthy"
RPROVIDES_anthy += "anthy"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/anthy.manifest .
 #tar zxf ${S}/packaging//cannadic-0.93.tar.gz
 #ln -s ../cannadic-0.93/gcanna.t mkanthydic
 #ln -s ../cannadic-0.93/gcannaf.t mkanthydic
 
 
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
         --infodir=/usr/share/info
 
 make
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${RPM_BUILD_ROOT}
 
   oe_runmake \
         DESTDIR=${D} \
         BINDIR=/usr/bin \
         prefix=/usr \
         exec_prefix=/usr \
         bindir=/usr/bin \
         sbindir=/usr/sbin \
         sysconfdir=/etc \
         datadir=/usr/share \
         includedir=/usr/include \
         libdir=/usr/lib \
         libexecdir=/usr/libexec \
         localstatedir=}/var \
         sharedstatedir=/usr/com \
         mandir=/usr/share/man \
         infodir=/usr/share/info \
   install
 
 
}

PACKAGES = ""
PACKAGES += "anthy"

anthy_files = ""
anthy_files += "anthy.manifest"
anthy_files += "/usr/bin/*"
anthy_files += "/etc/*"
anthy_files += "/usr/share/anthy"
anthy_files += "/usr/lib/pkgconfig/*"
anthy_files += "/usr/lib/libanthy*"
anthy_files += "/usr/include/*"

FILES_${PN} = "${anthy_files}"

PKG_anthy= "anthy"

require anthy-extraconf.inc
