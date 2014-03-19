DESCRIPTION = "Evented I/O for V8 JavaScript"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Service"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by nodejs-docs  
PROVIDES += "nodejs-docs "
RPROVIDES_nodejs-docs  += "nodejs-docs "

#PROVIDES by nodejs 
PROVIDES += "nodejs"
RPROVIDES_nodejs += "nodejs"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of nodejs 
DEPENDS += "zlib-devel"
DEPENDS += "gcc-cross"
inherit pythonnative
DEPENDS += "openssl-devel"
DEPENDS += "fdupes-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
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
 
 
 ./configure --prefix=/usr --without-dtrace
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
 
 # cleanup leftover cruft
 rm -fR ${D}/usr/lib/dtrace
 find ${D}/usr/lib/node_modules -name '\.*' -delete
 
 
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r ${D}/usr/lib/node_modules | 
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
PACKAGES += "nodejs-docs"
PACKAGES += "nodejs"

nodejs-docs_files = ""
nodejs-docs_files += "/usr/share/info"
nodejs-docs_files += "/usr/share/man"

nodejs_files = ""
nodejs_files += "/usr/bin/node"
nodejs_files += "/usr/bin/npm"
nodejs_files += "/usr/lib/node_modules"
nodejs_files += "/usr/lib/node_modules/npm"
nodejs_files += "/usr/lib/node_modules/npm/*"

FILES_${PN}-docs = "${nodejs-docs_files}"
FILES_${PN} = "${nodejs_files}"

PKG_nodejs-docs= "nodejs-docs"
PKG_nodejs= "nodejs"

require nodejs-extraconf.inc
