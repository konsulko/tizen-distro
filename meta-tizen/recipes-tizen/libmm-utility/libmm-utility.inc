DESCRIPTION = "Multimedia Framework Utility Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libmm-utility 
PROVIDES += "libmm-utility"
RPROVIDES_libmm-utility += "libmm-utility"

#PROVIDES by libmm-utility-devel 
PROVIDES += "libmm-utility-devel"
RPROVIDES_libmm-utility-devel += "libmm-utility-devel"
RPROVIDES_libmm-utility-devel += "libmm-utility-dev"

#PROVIDES by libmm-utility-tool 
PROVIDES += "libmm-utility-tool"
RPROVIDES_libmm-utility-tool += "libmm-utility-tool"

RDEPENDS = ""
#RDEPENDS of libmm-utility (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"

#RDEPENDS of libmm-utility-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libmm-utility"

#RDEPENDS of libmm-utility-tool (${PN}-tool)
RDEPENDS_${PN}-tool += "libmm-utility"


DEPENDS = ""
#DEPENDS of libmm-utility 
DEPENDS += "libmm-common"
DEPENDS += "libjpeg-turbo"
DEPENDS += "libmm-log"
DEPENDS += "pkgconfig(gmodule-2.0)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(mm-ta)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libmm-utility.manifest .
 
 
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
 
 ./autogen.sh
 
 CFLAGS="$CFLAGS -DEXPORT_API=\"__attribute__((visibility(\\\"default\\\")))\" -D_MM_PROJECT_FLOATER" \
 LDFLAGS+="-Wl,--rpath=/usr/lib -Wl,--hash-style=both -Wl,--as-needed" \
 
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
 make -j16
 
 sed -i -e "s#@IMGP_REQPKG@#$IMGP_REQPKG#g" imgp/mmutil-imgp.pc
 sed -i -e "s#@JPEG_REQPKG@#$JPEG_REQPKG#g" jpeg/mmutil-jpeg.pc
 
 
 
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
 mkdir -p ${D}/usr/share/license
 cp LICENSE ${D}/usr/share/license/libmm-utility
 
 
}

PACKAGES = ""
PACKAGES += "libmm-utility"
PACKAGES += "libmm-utility-devel"
PACKAGES += "libmm-utility-tool"

libmm-utility_files = ""
libmm-utility_files += "libmm-utility.manifest"
libmm-utility_files += "/usr/share/license/libmm-utility"
libmm-utility_files += "libmm-utility.manifest"
libmm-utility_files += "/usr/lib/*.so*"

libmm-utility-devel_files = ""
libmm-utility-devel_files += "libmm-utility.manifest"
libmm-utility-devel_files += "/usr/include/*"
libmm-utility-devel_files += "/usr/lib/pkgconfig/*"

libmm-utility-tool_files = ""
libmm-utility-tool_files += "libmm-utility.manifest"
libmm-utility-tool_files += "/usr/bin/*_testsuite"

FILES_${PN} = "${libmm-utility_files}"
FILES_${PN}-devel = "${libmm-utility-devel_files}"
FILES_${PN}-tool = "${libmm-utility-tool_files}"

PKG_libmm-utility= "libmm-utility"
PKG_libmm-utility-devel= "libmm-utility-devel"
PKG_libmm-utility-tool= "libmm-utility-tool"

require libmm-utility-extraconf.inc
