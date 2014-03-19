DESCRIPTION = "Test runner with a command-line interface"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Testing"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by testkit-lite 
PROVIDES += "testkit-lite"
RPROVIDES_testkit-lite += "testkit-lite"

RDEPENDS = ""
#RDEPENDS of testkit-lite (${PN})
RDEPENDS_${PN} += "python"
RDEPENDS_${PN} += "testkit-stub"
RDEPENDS_${PN} += "python-lxml"
RDEPENDS_${PN} += "python-requests"


DEPENDS = ""
#DEPENDS of testkit-lite 
inherit pythonnative
DEPENDS += "fdupes-native"
DEPENDS += "python-requests"
DEPENDS += "python-distribute"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/testkit-lite.manifest .
 
 # for rpmlint warning: remove shebang from python library
 sed -i '/^#!/d' ./commodule/config.py
 sed -i '/^#!/d' ./commodule/connector.py
 sed -i '/^#!/d' ./commodule/log.py
 sed -i '/^#!/d' ./commodule/killall.py
 sed -i '/^#!/d' ./commodule/autoexec.py
 sed -i '/^#!/d' ./commodule/httprequest.py
 sed -i '/^#!/d' ./commodule/str2.py
 sed -i '/^#!/d' ./commodule/impl/androidmobile.py
 sed -i '/^#!/d' ./commodule/impl/tizenivi.py
 sed -i '/^#!/d' ./commodule/impl/tizenpc.py
 sed -i '/^#!/d' ./commodule/impl/localhost.py
 sed -i '/^#!/d' ./commodule/impl/tizenmobile.py
 sed -i '/^#!/d' ./testkitlite/common/process_killall.py
 sed -i '/^#!/d' ./testkitlite/engines/default/runner.py
 sed -i '/^#!/d' ./testkitlite/engines/default/worker.py
 
 
 
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
 rm -rf $RPM_BUILD_ROOT/opt/testkit/lite/testkit-lite_user_guide_for_tct.pdf
 
 
 
}

PACKAGES = ""
PACKAGES += "testkit-lite"

testkit-lite_files = ""
testkit-lite_files += "testkit-lite.manifest"
testkit-lite_files += "/opt/testkit/lite/testkit-lite_user_guide.pdf"
testkit-lite_files += "/opt/testkit/lite/testkit-lite_tutorial.pdf"
testkit-lite_files += "/opt/testkit/lite/test_definition_schema.pdf"
testkit-lite_files += "/usr/bin/testkit-lite"
testkit-lite_files += "/usr/bin/testkit-lite-dbus"
testkit-lite_files += "/etc/dbus-1/system.d/com.intel.testkit.conf"
testkit-lite_files += "/usr/lib/python2.7/site-packages/testkitlite/*"
testkit-lite_files += "/usr/lib/python2.7/site-packages/commodule/*"
testkit-lite_files += "/usr/lib/python2.7/site-packages/testkit_lite-3.0.7-py2.7.egg-info/*"
testkit-lite_files += "/opt/testkit/lite/VERSION"
testkit-lite_files += "/opt/testkit/lite/commodule/CONFIG"

FILES_${PN} = "${testkit-lite_files}"

PKG_testkit-lite= "testkit-lite"

require testkit-lite-extraconf.inc
