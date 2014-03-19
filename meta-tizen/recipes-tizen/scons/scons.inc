DESCRIPTION = "Replacement for Make"
HOMEPAGE = "http://www.scons.org/"
SECTION = "Development/Tools/Building"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by scons 
PROVIDES += "scons"
RPROVIDES_scons += "scons"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of scons 
inherit pythonnative
DEPENDS += "fdupes-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/scons.manifest .
 
 
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
 
 export CFLAGS="$RPM_OPT_FLAGS"
 python setup.py build
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 python setup.py install --prefix=/usr --root=${D} --install-lib=/usr/lib/python2.7/site-packages
 
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r ${D}/usr/bin | 
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
PACKAGES += "scons"

scons_files = ""
scons_files += "scons.manifest"
scons_files += "/usr/bin/*"
scons_files += "/usr/lib/python2.7/site-packages/SCons/"
scons_files += "/usr/lib/python2.7/site-packages/*.egg-info"
scons_files += "/usr/share/man/man1/*.gz"

FILES_${PN} = "${scons_files}"

PKG_scons= "scons"

require scons-extraconf.inc
