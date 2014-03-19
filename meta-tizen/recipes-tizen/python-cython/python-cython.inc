DESCRIPTION = "The Cython compiler for writing C extensions for the Python language"
HOMEPAGE = "http://www.cython.org"
SECTION = "Development/Languages/Python"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-cython 
PROVIDES += "python-cython"
RPROVIDES_python-cython += "python-cython"
# the PROVIDES rules is ignore "python-cython = 0.20"
PROVIDES += "python-cython"
RPROVIDES_python-cython += "python-cython"

RDEPENDS = ""
#RDEPENDS of python-cython (${PN})
RDEPENDS_${PN} += "python-xml"
RDEPENDS_${PN} += "python-libxml2"
RDEPENDS_${PN} += "python-lxml"
RDEPENDS_${PN} += "update-alternatives"


DEPENDS = ""
#DEPENDS of python-cython 
inherit pythonnative
DEPENDS += "fdupes-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Cython-0.20
 sed -i "s|^#!.*||" Cython/Debugger/{libpython,Cygdb}.py cython.py # Fix non-executable scripts
 sed -i "s|\r||" Demos/callback/{README.txt,cheesefinder.h} Demos/embed/Makefile.{unix,msc.static} Doc/primes.c # Fix EOL encoding
 mv bin/cython bin/cython-2.7
 mv bin/cygdb bin/cygdb-2.7
 sed -i "s|bin/cython|bin/cython-2.7|" setup.py
 sed -i "s|bin/cygdb|bin/cygdb-2.7|" setup.py
 
 
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
 
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" python setup.py build
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 python setup.py install --prefix=/usr --root=${D}
 ln -s  /usr/bin/cython-2.7 ${D}/usr/bin/cython
 ln -s  /usr/bin/cygdb-2.7 ${D}/usr/bin/cygdb
 
  _target=""; 
  _symlinks=0; 
  _symlinks=1; 
  fdupes -q -n -r ${D}/usr/lib/python2.7/site-packages | 
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
PACKAGES += "python-cython"

python-cython_files = ""
python-cython_files += "README.txt ToDo.txt USAGE.txt Doc Demos"
python-cython_files += "/usr/bin/cygdb-2.7"
python-cython_files += "/usr/bin/cython-2.7"
python-cython_files += "/usr/lib/python2.7/site-packages/Cython/"
python-cython_files += "/usr/lib/python2.7/site-packages/Cython-0.20-py2.7.egg-info"
python-cython_files += "/usr/lib/python2.7/site-packages/cython.py*"
python-cython_files += "/usr/lib/python2.7/site-packages/pyximport/"

FILES_${PN} = "${python-cython_files}"

PKG_python-cython= "python-cython"

require python-cython-extraconf.inc
