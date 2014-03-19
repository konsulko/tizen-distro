DESCRIPTION = "A YAML 1.1 parser and emitter written in C"
HOMEPAGE = "http://pyyaml.org/wiki/LibYAML"
SECTION = "Development/Libraries/C and C++"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libyaml-devel 
PROVIDES += "libyaml-devel"
RPROVIDES_libyaml-devel += "libyaml-devel"
RPROVIDES_libyaml-devel += "libyaml-dev"

#PROVIDES by yaml 
PROVIDES += "yaml"
RPROVIDES_yaml += "yaml"

#PROVIDES by libyaml 
PROVIDES += "libyaml"
RPROVIDES_libyaml += "libyaml"

RDEPENDS = ""
#RDEPENDS of libyaml-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "libyaml"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -n yaml-0.1.4
 cp ${S}/packaging/yaml.manifest .
 
 
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
         --infodir=/usr/share/info --with-pic --disable-static
 make 
 
 exit 0
 make check
 
 
 
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
PACKAGES += "libyaml-devel"
PACKAGES += "libyaml"

libyaml-devel_files = ""
libyaml-devel_files += "yaml.manifest"
libyaml-devel_files += "/usr/include/yaml.h"
libyaml-devel_files += "/usr/lib/libyaml.so"
libyaml-devel_files += "/usr/lib/pkgconfig/yaml-0.1.pc"

libyaml_files = ""
libyaml_files += "yaml.manifest"
libyaml_files += "/usr/lib/libyaml-0.so.*"

FILES_lib${PN}-devel = "${libyaml-devel_files}"
FILES_lib${PN} = "${libyaml_files}"

PKG_libyaml-devel= "libyaml-devel"
PKG_libyaml= "libyaml"

require yaml-extraconf.inc
