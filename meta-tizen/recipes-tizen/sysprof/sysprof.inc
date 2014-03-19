DESCRIPTION = "Sampling CPU profiler"
HOMEPAGE = "http://sysprof.com/"
SECTION = "Development/Tools/Debuggers"
LICENSE = "GPL v2 or later"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by sysprof-cli 
PROVIDES += "sysprof-cli"
RPROVIDES_sysprof-cli += "sysprof-cli"

#PROVIDES by sysprof 
PROVIDES += "sysprof"
RPROVIDES_sysprof += "sysprof"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of sysprof 
DEPENDS += "glib"
DEPENDS += "autoconf-native"
DEPENDS += "binutils"
DEPENDS += "automake-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n sysprof-1.2.0
 cp ${S}/packaging/sysprof.manifest .
 
 
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
 
 NOCONFIGURE=1 ./autogen.sh
 
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
         --infodir=/usr/share/info CFLAGS="$RPM_OPT_FLAGS -fno-strict-aliasing"
 make
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf $RPM_BUILD_ROOT
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 # unnecessary, sysprof now uses the standard kernel interface for profiling
 # (since 1.1; compare with Debian patches)
 rm -r $RPM_BUILD_ROOT/etc/udev/rules.d
 rm $RPM_BUILD_ROOT/usr/share/pixmaps/*.png
 rm $RPM_BUILD_ROOT/usr/share/sysprof/sysprof.glade
 rmdir $RPM_BUILD_ROOT/usr/share/sysprof
 rmdir $RPM_BUILD_ROOT/usr/share/pixmaps
 rmdir $RPM_BUILD_ROOT/usr/share
 
 
}

PACKAGES = ""
PACKAGES += "sysprof-cli"

sysprof-cli_files = ""
sysprof-cli_files += "sysprof.manifest"
sysprof-cli_files += "/usr/bin/sysprof-cli"

FILES_${PN}-cli = "${sysprof-cli_files}"

PKG_sysprof-cli= "sysprof-cli"

require sysprof-extraconf.inc
