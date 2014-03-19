DESCRIPTION = "A library for changing configuration files"
HOMEPAGE = "http://augeas.net/"
SECTION = "System/Libraries"
LICENSE = "GPL-3.0+ or LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by augeas 
PROVIDES += "augeas"
RPROVIDES_augeas += "augeas"

#PROVIDES by augeas-lense-tests 
PROVIDES += "augeas-lense-tests"
RPROVIDES_augeas-lense-tests += "augeas-lense-tests"

#PROVIDES by augeas-devel 
PROVIDES += "augeas-devel"
RPROVIDES_augeas-devel += "augeas-devel"
RPROVIDES_augeas-devel += "augeas-dev"

#PROVIDES by augeas-docs  
PROVIDES += "augeas-docs "
RPROVIDES_augeas-docs  += "augeas-docs "

#PROVIDES by augeas-lenses 
PROVIDES += "augeas-lenses"
RPROVIDES_augeas-lenses += "augeas-lenses"

#PROVIDES by libaugeas 
PROVIDES += "libaugeas"
RPROVIDES_libaugeas += "libaugeas"

RDEPENDS = ""
#RDEPENDS of augeas-lense-tests (${PN}-lense-tests)
RDEPENDS_${PN}-lense-tests += "augeas-lenses"

#RDEPENDS of augeas-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libaugeas"

#RDEPENDS of augeas-lenses (${PN}-lenses)
RDEPENDS_${PN}-lenses += "libaugeas"


DEPENDS = ""
#DEPENDS of augeas 
DEPENDS += "libxml2-devel"
DEPENDS += "glib2-devel"
DEPENDS += "readline-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/augeas.manifest .
 
 
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
 
 export CFLAGS="-Wno-error $RPM_OPT_FLAGS"
 
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
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 # move vim files to the right location
 mv $RPM_BUILD_ROOT//usr/share/vim/vimfiles $RPM_BUILD_ROOT//usr/share/vim/site
 
 
}

PACKAGES = ""
PACKAGES += "augeas"
PACKAGES += "augeas-lense-tests"
PACKAGES += "augeas-devel"
PACKAGES += "augeas-lenses"
PACKAGES += "libaugeas"
PACKAGES += "augeas-docs"

augeas_files = ""
augeas_files += "augeas.manifest"
augeas_files += "/usr/bin/augtool"
augeas_files += "/usr/bin/augparse"
augeas_files += "/usr/bin/fadot"

augeas-lense-tests_files = ""
augeas-lense-tests_files += "augeas.manifest"
augeas-lense-tests_files += "/usr/share/augeas/lenses/dist/tests"
augeas-lense-tests_files += "/usr/share/augeas/lenses/dist/tests/*.aug"

augeas-devel_files = ""
augeas-devel_files += "augeas.manifest"
augeas-devel_files += "/usr/include/*"
augeas-devel_files += "/usr/lib/*.so"
augeas-devel_files += "/usr/lib/pkgconfig/augeas.pc"
augeas-devel_files += "/usr/share/vim"
augeas-devel_files += "/usr/share/vim/site"
augeas-devel_files += "/usr/share/vim/site/ftdetect"
augeas-devel_files += "/usr/share/vim/site/ftdetect/augeas.vim"
augeas-devel_files += "/usr/share/vim/site/syntax"
augeas-devel_files += "/usr/share/vim/site/syntax/augeas.vim"

augeas-lenses_files = ""
augeas-lenses_files += "augeas.manifest"
augeas-lenses_files += "/usr/share/augeas"
augeas-lenses_files += "/usr/share/augeas/lenses"
augeas-lenses_files += "/usr/share/augeas/lenses/dist"
augeas-lenses_files += "/usr/share/augeas/lenses/dist/*.aug"

libaugeas_files = ""
libaugeas_files += "augeas.manifest"
libaugeas_files += "/usr/lib/*.so.*"

augeas-docs_files = ""
augeas-docs_files += "/usr/share/info"
augeas-docs_files += "/usr/share/man"

FILES_${PN} = "${augeas_files}"
FILES_${PN}-lense-tests = "${augeas-lense-tests_files}"
FILES_${PN}-devel = "${augeas-devel_files}"
FILES_${PN}-lenses = "${augeas-lenses_files}"
FILES_lib${PN} = "${libaugeas_files}"
FILES_${PN}-docs = "${augeas-docs_files}"

PKG_augeas= "augeas"
PKG_augeas-lense-tests= "augeas-lense-tests"
PKG_augeas-devel= "augeas-devel"
PKG_augeas-lenses= "augeas-lenses"
PKG_libaugeas= "libaugeas"
PKG_augeas-docs= "augeas-docs"

require augeas-extraconf.inc
