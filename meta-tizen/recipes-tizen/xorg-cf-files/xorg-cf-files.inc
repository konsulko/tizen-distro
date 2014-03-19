DESCRIPTION = "Data files for the imake utility"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "Development/Tools/Building"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by xorg-cf-files 
PROVIDES += "xorg-cf-files"
RPROVIDES_xorg-cf-files += "xorg-cf-files"

RDEPENDS = ""
#RDEPENDS of xorg-cf-files (${PN})
RDEPENDS_${PN} += "gccmakedep"
RDEPENDS_${PN} += "makedepend"
RDEPENDS_${PN} += "imake"


DEPENDS = ""
#DEPENDS of xorg-cf-files 
DEPENDS += "font-util"
DEPENDS += "pkgconfig(xorg-macros)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/xorg-cf-files.manifest .
 cat > host.def << EOF
 #define ConfigDir /usr/share/X11/config
 #define XAppLoadDir /usr/share/X11/app-defaults
 #define UseSeparateConfDir NO
 #define ManPath /usr/share/man
 #define ModuleDir /usr/lib/xorg/modules
 #ifdef  i386Architecture
 #undef  DefaultGcc2i386Opt
 #define DefaultGcc2i386Opt      -O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fno-strict-aliasing
 #endif
 #ifdef  MipsArchitecture
 #undef  DefaultGcc2MipsOpt
 #define DefaultGcc2MipsOpt      -O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fno-strict-aliasing
 #endif
 #ifdef  PpcArchitecture
 #undef  DefaultGcc2PpcOpt
 #define DefaultGcc2PpcOpt       -O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fno-strict-aliasing
 #endif
 #ifdef  Ppc64Architecture
 #undef  DefaultGcc2Ppc64Opt
 #define DefaultGcc2Ppc64Opt     -O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fno-strict-aliasing
 #endif
 #ifdef  AMD64Architecture
 #undef  DefaultGcc2AMD64Opt
 #define DefaultGcc2AMD64Opt     -O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fno-strict-aliasing
 #endif
 #ifdef  s390xArchitecture
 #undef  OptimizedCDebugFlags
 #define OptimizedCDebugFlags    -O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fno-strict-aliasing
 #endif
 #ifdef  ia64Architecture
 #undef  OptimizedCDebugFlags
 #define OptimizedCDebugFlags    -O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fno-strict-aliasing
 #endif
 #if defined(SparcArchitecture) || defined(Sparc64Architecture)
 #undef  OptimizedCDebugFlags
 #define OptimizedCDebugFlags    -O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fno-strict-aliasing
 # undef HaveLib64
 #if defined(Sparc64Architecture)
 # define HaveLib64    YES
 #else
 # define HaveLib64    NO
 #endif
 #endif
 EOF
 
 
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
         --target=noarch-tizen-linux \
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
         --infodir=/usr/share/info --with-config-dir=/usr/share/X11/config
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
 
 
}

PACKAGES = ""
PACKAGES += "xorg-cf-files"

xorg-cf-files_files = ""
xorg-cf-files_files += "xorg-cf-files.manifest"
xorg-cf-files_files += "ChangeLog COPYING README"
xorg-cf-files_files += "/usr/share/X11"
xorg-cf-files_files += "/usr/share/X11/config/"

FILES_${PN} = "${xorg-cf-files_files}"

PKG_xorg-cf-files= "xorg-cf-files"

require xorg-cf-files-extraconf.inc
