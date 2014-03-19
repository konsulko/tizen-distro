DESCRIPTION = "Cheetah is a template engine and code generation tool"
HOMEPAGE = "http://www.cheetahtemplate.org/"
SECTION = "Development/Languages/Python"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-Cheetah 
PROVIDES += "python-Cheetah"
RPROVIDES_python-Cheetah += "python-Cheetah"
# the PROVIDES rules is ignore "python-cheetah = 2.4.4"
PROVIDES += "python-cheetah"
RPROVIDES_python-Cheetah += "python-cheetah"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of python-Cheetah 
inherit pythonnative
DEPENDS += "fdupes-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Cheetah-2.4.4
 cp ${S}/packaging/python-Cheetah.manifest .
 # Remove she-bang lines for non-executable scripts:
 sed -i "1d" cheetah/{Tests/{Unicode,Filters,Parser,Template,Regressions,Cheps,Analyzer,Test,Misc,CheetahWrapper,SyntaxAndOutput,NameMapper,Performance},ImportHooks,Utils/Misc,Servlet,NameMapper,Parser,DirectiveAnalyzer}.py
 
 
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
PACKAGES += "python-Cheetah"

python-Cheetah_files = ""
python-Cheetah_files += "python-Cheetah.manifest"
python-Cheetah_files += "LICENSE"
python-Cheetah_files += "/usr/bin/cheetah*"
python-Cheetah_files += "/usr/lib/python2.7/site-packages/*"

FILES_${PN} = "${python-Cheetah_files}"

PKG_python-Cheetah= "python-Cheetah"

require python-Cheetah-extraconf.inc
