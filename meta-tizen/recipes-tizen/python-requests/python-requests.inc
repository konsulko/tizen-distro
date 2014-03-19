DESCRIPTION = "Awesome Python HTTP Library That's Actually Usable"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Base"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-requests 
PROVIDES += "python-requests"
RPROVIDES_python-requests += "python-requests"

RDEPENDS = ""
#RDEPENDS of python-requests (${PN})
RDEPENDS_${PN} += "python"


DEPENDS = ""
#DEPENDS of python-requests 
inherit pythonnative
DEPENDS += "fdupes-native"
DEPENDS += "python-distribute"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n requests-2.2.1
 cp  ${S}/packaging/python-requests.manifest .
 # for rpmlint warning: remove shebang from python library
 sed -i '/^#!/d' ./requests/certs.py
 sed -i '/^#!/d' ./requests/packages/chardet/chardetect.py
 
 
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
 
 python setup.py build
 
 exit 0
 python setup.py test
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 python setup.py install --skip-build --prefix=/usr --root=${D}
 
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r $RPM_BUILD_ROOT | 
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
PACKAGES += "python-requests"

python-requests_files = ""
python-requests_files += "python-requests.manifest"
python-requests_files += "/usr/lib/python2.7/site-packages/*"

FILES_${PN} = "${python-requests_files}"

PKG_python-requests= "python-requests"

require python-requests-extraconf.inc
