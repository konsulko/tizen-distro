DESCRIPTION = "An Accessibility ToolKit"
HOMEPAGE = "http://www.gtk.org/"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by typelib-Atk 
PROVIDES += "typelib-Atk"
RPROVIDES_typelib-Atk += "typelib-Atk"

#PROVIDES by atk-docs  
PROVIDES += "atk-docs "
RPROVIDES_atk-docs  += "atk-docs "

#PROVIDES by atk 
PROVIDES += "atk"
RPROVIDES_atk += "atk"

#PROVIDES by atk-devel 
PROVIDES += "atk-devel"
RPROVIDES_atk-devel += "atk-devel"
RPROVIDES_atk-devel += "atk-dev"

#PROVIDES by libatk 
PROVIDES += "libatk"
RPROVIDES_libatk += "libatk"
# the PROVIDES rules is ignore "atk = 2.8.0"
PROVIDES += "atk"
RPROVIDES_libatk += "atk"

RDEPENDS = ""
#RDEPENDS of atk (${PN})
RDEPENDS_${PN} += "libatk"

#RDEPENDS of atk-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libatk"


DEPENDS = ""
#DEPENDS of atk 
DEPENDS += "glib2-devel"
DEPENDS += "fdupes-native"
DEPENDS += "gcc-c++"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/atk.manifest .
 
 
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
         --infodir=/usr/share/info \
   --disable-static
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
 
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r ${D} | 
   while read _file; do 
     if test -z "$_target" ; then 
       _target="$_file"; 
     else 
       if test -z "$_file" ; then 
 	_target=""; 
 	continue ; 
       fi ; 
       if test "$_symlinks" = 1; then 
         ln -sf "${_target#${D}}" "$_file"; 
       else 
         ln -f "$_target" "$_file"; 
       fi ;
     fi ; 
  done 
 
 
}

PACKAGES = ""
PACKAGES += "atk-devel"
PACKAGES += "atk-docs"
PACKAGES += "libatk"

atk-devel_files = ""
atk-devel_files += "atk.manifest"
atk-devel_files += "/usr/include/atk-1.0"
atk-devel_files += "/usr/lib/lib*.so"
atk-devel_files += "/usr/lib/pkgconfig/*.pc"

atk-docs_files = ""
atk-docs_files += "/usr/share/info"
atk-docs_files += "/usr/share/man"

libatk_files = ""
libatk_files += "atk.manifest"
libatk_files += "/usr/lib/lib*.so.*"

FILES_${PN}-devel = "${atk-devel_files}"
FILES_${PN}-docs = "${atk-docs_files}"
FILES_lib${PN} = "${libatk_files}"

PKG_atk-devel= "atk-devel"
PKG_atk-docs= "atk-docs"
PKG_libatk= "libatk"

require atk-extraconf.inc
