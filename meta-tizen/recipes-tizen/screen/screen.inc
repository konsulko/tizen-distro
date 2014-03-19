DESCRIPTION = "A program to allow multiple screens on a VT100/ANSI Terminal"
HOMEPAGE = "http://www.gnu.org/software/screen/"
SECTION = "System/Console"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by screen 
PROVIDES += "screen"
RPROVIDES_screen += "screen"

RDEPENDS = ""
#RDEPENDS of screen (${PN})
RDEPENDS_${PN} += "coreutils"


DEPENDS = ""
#DEPENDS of screen 
DEPENDS += "ncurses"
DEPENDS += "makeinfo"
DEPENDS += "utempter-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup
 cp ${S}/packaging/screen.manifest .
 
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
 
 CFLAGS="-DMAXWIN=1000 $RPM_OPT_FLAGS" 
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
         --infodir=/usr/share/info --prefix=/usr --infodir=/usr/share/info \
 				--mandir=/usr/share/man \
 				--with-socket-dir='(eff_uid ? "/var/run/uscreens" : "/var/run/screens")' \
 				--with-sys-screenrc=/etc/screenrc \
 				--with-pty-group=5 \
 				--enable-use-locale \
 				--enable-colors256 \
 				--verbose
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR=$RPM_BUILD_ROOT
 rm -f $RPM_BUILD_ROOT/usr/bin/screen
 mv $RPM_BUILD_ROOT/usr/bin/screen-4.0.4 $RPM_BUILD_ROOT/usr/bin/screen
 chmod 755 $RPM_BUILD_ROOT/usr/bin/screen
 mkdir -p $RPM_BUILD_ROOT/etc
 mkdir -p $RPM_BUILD_ROOT/usr/lib
 mkdir -p $RPM_BUILD_ROOT/usr/lib/tmpfiles.d
 mkdir -p $RPM_BUILD_ROOT/var/run/screens
 chmod 755 $RPM_BUILD_ROOT/var/run/screens
 mkdir -p $RPM_BUILD_ROOT/var/run/uscreens
 chmod 1777 $RPM_BUILD_ROOT/var/run/uscreens
 install -m 644 screenrc $RPM_BUILD_ROOT/etc/screenrc
 install -m 644 ${S}/packaging/screen.conf $RPM_BUILD_ROOT/usr/lib/tmpfiles.d
 
 
}

PACKAGES = ""
PACKAGES += "screen"

screen_files = ""
screen_files += "screen.manifest"
screen_files += "/etc/screenrc"
screen_files += "/usr/share/screen"
screen_files += "/usr/lib/tmpfiles.d"
screen_files += "/usr/lib/tmpfiles.d/screen.conf"
screen_files += "/usr/share/screen/utf8encodings"
screen_files += "/usr/share/info/screen.info*.gz"
screen_files += "/usr/share/man/man1/screen.1.gz"

FILES_${PN} = "${screen_files}"

PKG_screen= "screen"

require screen-extraconf.inc
