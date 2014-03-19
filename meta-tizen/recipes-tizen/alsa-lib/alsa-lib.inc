DESCRIPTION = "The Advanced Linux Sound Architecture (ALSA) library"
HOMEPAGE = "http://www.alsa-project.org/"
SECTION = "System/Audio"
LICENSE = "LGPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by alsa-lib 
PROVIDES += "alsa-lib"
RPROVIDES_alsa-lib += "alsa-lib"

#PROVIDES by libasound 
PROVIDES += "libasound"
RPROVIDES_libasound += "libasound"

#PROVIDES by libasound-devel 
PROVIDES += "libasound-devel"
RPROVIDES_libasound-devel += "libasound-devel"
RPROVIDES_libasound-devel += "libasound-dev"

RDEPENDS = ""
#RDEPENDS of libasound-devel (libasound-devel)
RDEPENDS_libasound-devel += "libasound"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/alsa-lib.manifest .
 
 
 
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
     --with-alsa-devdir=/dev/snd \
     --disable-alisp \
     --disable-seq \
     --disable-python \
     --with-gnu-ld \
     --with-pcm-plugins=rate,linear,plug,dmix,dsnoop,asym,mmap,ioplug,empty,hooks,route,multi,softvol,file,iec958,null,shm
 
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
 
 rm -f ${D}//usr/bin/aserver
 
 
}

PACKAGES = ""
PACKAGES += "libasound-devel"
PACKAGES += "libasound"

libasound-devel_files = ""
libasound-devel_files += "alsa-lib.manifest"
libasound-devel_files += "/usr/include/*"
libasound-devel_files += "/usr/lib/lib*.so"
libasound-devel_files += "/usr/lib/pkgconfig/*"
libasound-devel_files += "/usr/share/aclocal"

libasound_files = ""
libasound_files += "alsa-lib.manifest"
libasound_files += "/usr/lib/lib*.so.*"
libasound_files += "/usr/lib/alsa-lib/smixer/*.so"
libasound_files += "/usr/share/alsa/*"

FILES_libasound-devel = "${libasound-devel_files}"
FILES_libasound = "${libasound_files}"

PKG_libasound-devel= "libasound-devel"
PKG_libasound= "libasound"

require alsa-lib-extraconf.inc
