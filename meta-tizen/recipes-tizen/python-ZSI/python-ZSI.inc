DESCRIPTION = "Zolera SOAP Infrastructure"
HOMEPAGE = "http://pywebsvcs.sf.net"
SECTION = "Development/Languages/Python"
LICENSE = "Python"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-ZSI 
PROVIDES += "python-ZSI"
RPROVIDES_python-ZSI += "python-ZSI"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of python-ZSI 
inherit pythonnative
DEPENDS += "fdupes-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n ZSI-2.1-a1
 cp ${S}/packaging/python-ZSI.manifest .
 find doc -type f -name .cvsignore -exec rm {} \; # Remove CVS files
 #sed -i '1d' ZSI/{auth,client,digest_auth,dispatch,fault,generate/wsdl2dispatch,__init__,parse,resolvers,schema,ServiceContainer,TCapache,TCcompound,TCnumbers,TC,TCtimes,writer,wstools/c14n,wstools/__init__}.py # Remove she-bang line
 #chmod -x doc/guide02-wsdl2py.tex # Remove executable bit from tex file
 
 
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
 
  _target=""; 
  _symlinks=0; 
  _symlinks=1; 
  fdupes -q -n -r doc | 
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

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 python setup.py install --prefix=/usr --root=${D}
 
 
 
}

PACKAGES = ""
PACKAGES += "python-ZSI"

python-ZSI_files = ""
python-ZSI_files += "python-ZSI.manifest"
python-ZSI_files += "/usr/bin/wsdl2py"
python-ZSI_files += "/usr/lib/python2.7/site-packages/*"

FILES_${PN} = "${python-ZSI_files}"

PKG_python-ZSI= "python-ZSI"

require python-ZSI-extraconf.inc
