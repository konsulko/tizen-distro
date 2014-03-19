DESCRIPTION = "A Python interface to libcurl"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Platform Development/Python"
LICENSE = "LGPL-2.1+ or MIT/X11"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-pycurl 
PROVIDES += "python-pycurl"
RPROVIDES_python-pycurl += "python-pycurl"
# the PROVIDES rules is ignore "pycurl = 7.19.0-0"
PROVIDES += "pycurl"
RPROVIDES_python-pycurl += "pycurl"

RDEPENDS = ""
#RDEPENDS of python-pycurl (${PN})
RDEPENDS_${PN} += "libcurl"


DEPENDS = ""
#DEPENDS of python-pycurl 
inherit pythonnative
DEPENDS += "curl"
DEPENDS += "c-ares"
DEPENDS += "openssl"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n pycurl-7.19.0
 chmod a-x examples/*
 
 
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
 
 cp ${S}/packaging/python-pycurl.manifest .
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -DHAVE_CURL_OPENSSL"
 python setup.py build
 
 exit 0
 export PYTHONPATH=$PWD/build/lib*
 python tests/test_internals.py -q
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 python setup.py install -O1 --skip-build --root=${D} --prefix=/usr
 
 
 
   rm -rf ${D}/usr/share/info 
   rm -rf ${D}/usr/share/doc/packages 
   rm -rf ${D}/usr/share/doc/python-pycurl 
   rm -rf ${D}/usr/share/doc/python-pycurl-7.19.0 
   rm -rf ${D}/usr/share/gtk-doc 
   rm -rf ${D}/usr/share/doc 
   rm -rf ${D}/usr/share/man 
   find ${D} -regex ".*/man/man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/../man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/man./.*.[0-9]pm" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "python-pycurl"

python-pycurl_files = ""
python-pycurl_files += "python-pycurl.manifest"
python-pycurl_files += "python-pycurl.manifest"
python-pycurl_files += "/usr/lib/python2.7/site-packages/curl/*"
python-pycurl_files += "/usr/lib/python2.7/site-packages/pycurl*"

FILES_${PN} = "${python-pycurl_files}"

PKG_python-pycurl= "python-pycurl"

require python-pycurl-extraconf.inc
