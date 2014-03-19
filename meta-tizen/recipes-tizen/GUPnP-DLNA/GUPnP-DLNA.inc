DESCRIPTION = "Utility library for easing DLNA-related tasks"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Applications/Multimedia"
LICENSE = "LGPLv2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gupnp-dlna-devel 
PROVIDES += "gupnp-dlna-devel"
RPROVIDES_gupnp-dlna-devel += "gupnp-dlna-devel"
RPROVIDES_gupnp-dlna-devel += "gupnp-dlna-dev"

#PROVIDES by gupnp-dlna 
PROVIDES += "gupnp-dlna"
RPROVIDES_gupnp-dlna += "gupnp-dlna"

RDEPENDS = ""
#RDEPENDS of gupnp-dlna-devel (gupnp-dlna-devel)
RDEPENDS_gupnp-dlna-devel += "gupnp-dlna"

#RDEPENDS of gupnp-dlna (gupnp-dlna)
RDEPENDS_gupnp-dlna += "/sbin/ldconfig"


DEPENDS = ""
#DEPENDS of gupnp-dlna 
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "pkgconfig(gstreamer-1.0)"
DEPENDS += "pkgconfig(gstreamer-plugins-base-1.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n gupnp-dlna-0.10.2
 
 
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
         --infodir=/usr/share/info --disable-static 
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
 
 rm -rf  $RPM_BUILD_ROOT/usr/share/gtk-doc
 
 
}

PACKAGES = ""
PACKAGES += "gupnp-dlna-devel"
PACKAGES += "gupnp-dlna"

gupnp-dlna-devel_files = ""
gupnp-dlna-devel_files += "/usr/include/gupnp-dlna-2.0/libgupnp-dlna/gupnp-dlna.h"
gupnp-dlna-devel_files += "/usr/include/gupnp-dlna-2.0/libgupnp-dlna/gupnp-dlna-audio-information.h"
gupnp-dlna-devel_files += "/usr/include/gupnp-dlna-2.0/libgupnp-dlna/gupnp-dlna-container-information.h"
gupnp-dlna-devel_files += "/usr/include/gupnp-dlna-2.0/libgupnp-dlna/gupnp-dlna-gst-utils.h"
gupnp-dlna-devel_files += "/usr/include/gupnp-dlna-2.0/libgupnp-dlna/gupnp-dlna-g-values.h"
gupnp-dlna-devel_files += "/usr/include/gupnp-dlna-2.0/libgupnp-dlna/gupnp-dlna-image-information.h"
gupnp-dlna-devel_files += "/usr/include/gupnp-dlna-2.0/libgupnp-dlna/gupnp-dlna-information.h"
gupnp-dlna-devel_files += "/usr/include/gupnp-dlna-2.0/libgupnp-dlna/gupnp-dlna-profile.h"
gupnp-dlna-devel_files += "/usr/include/gupnp-dlna-2.0/libgupnp-dlna/gupnp-dlna-profile-guesser.h"
gupnp-dlna-devel_files += "/usr/include/gupnp-dlna-2.0/libgupnp-dlna/gupnp-dlna-restriction.h"
gupnp-dlna-devel_files += "/usr/include/gupnp-dlna-2.0/libgupnp-dlna/gupnp-dlna-value-list.h"
gupnp-dlna-devel_files += "/usr/include/gupnp-dlna-2.0/libgupnp-dlna/gupnp-dlna-values.h"
gupnp-dlna-devel_files += "/usr/include/gupnp-dlna-2.0/libgupnp-dlna/gupnp-dlna-video-information.h"
gupnp-dlna-devel_files += "/usr/include/gupnp-dlna-2.0/libgupnp-dlna/metadata/gupnp-dlna-metadata-extractor.h"
gupnp-dlna-devel_files += "/usr/lib/pkgconfig/gupnp-dlna-2.0.pc"
gupnp-dlna-devel_files += "/usr/lib/pkgconfig/gupnp-dlna-metadata-2.0.pc"
gupnp-dlna-devel_files += "/usr/lib/pkgconfig/gupnp-dlna-gst-2.0.pc"
gupnp-dlna-devel_files += "/usr/lib/libgupnp-dlna-2.0.so"
gupnp-dlna-devel_files += "/usr/lib/libgupnp-dlna-gst-2.0.so"
gupnp-dlna-devel_files += "/usr/lib/gupnp-dlna/libgstreamer.so"

gupnp-dlna_files = ""
gupnp-dlna_files += "/usr/bin/gupnp-dlna-info-2.0"
gupnp-dlna_files += "/usr/bin/gupnp-dlna-ls-profiles-2.0"
gupnp-dlna_files += "/usr/lib/libgupnp-dlna-2.0.so.*"
gupnp-dlna_files += "/usr/lib/libgupnp-dlna-gst-2.0.so.*"
gupnp-dlna_files += "/usr/lib/gupnp-dlna/libgstreamer.so"
gupnp-dlna_files += "/usr/share/gupnp-dlna-2.0/dlna-profiles/aac.xml"
gupnp-dlna_files += "/usr/share/gupnp-dlna-2.0/dlna-profiles/ac3.xml"
gupnp-dlna_files += "/usr/share/gupnp-dlna-2.0/dlna-profiles/amr.xml"
gupnp-dlna_files += "/usr/share/gupnp-dlna-2.0/dlna-profiles/avc.xml"
gupnp-dlna_files += "/usr/share/gupnp-dlna-2.0/dlna-profiles/common.xml"
gupnp-dlna_files += "/usr/share/gupnp-dlna-2.0/dlna-profiles/dlna-profiles.rng"
gupnp-dlna_files += "/usr/share/gupnp-dlna-2.0/dlna-profiles/jpeg.xml"
gupnp-dlna_files += "/usr/share/gupnp-dlna-2.0/dlna-profiles/lpcm.xml"
gupnp-dlna_files += "/usr/share/gupnp-dlna-2.0/dlna-profiles/mp3.xml"
gupnp-dlna_files += "/usr/share/gupnp-dlna-2.0/dlna-profiles/mpeg-ts.xml"
gupnp-dlna_files += "/usr/share/gupnp-dlna-2.0/dlna-profiles/mpeg1.xml"
gupnp-dlna_files += "/usr/share/gupnp-dlna-2.0/dlna-profiles/mpeg4.xml"
gupnp-dlna_files += "/usr/share/gupnp-dlna-2.0/dlna-profiles/png.xml"
gupnp-dlna_files += "/usr/share/gupnp-dlna-2.0/dlna-profiles/wma.xml"
gupnp-dlna_files += "/usr/share/gupnp-dlna-2.0/dlna-profiles/mpeg-common.xml"
gupnp-dlna_files += "/usr/share/gupnp-dlna-2.0/dlna-profiles/mpeg-ps.xml"

FILES_${PN}-devel = "${gupnp-dlna-devel_files}"
FILES_${PN} = "${gupnp-dlna_files}"

PKG_gupnp-dlna-devel= "gupnp-dlna-devel"
PKG_gupnp-dlna= "gupnp-dlna"

require GUPnP-DLNA-extraconf.inc
