DESCRIPTION = "A high-level cross-protocol url-grabber"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-urlgrabber 
PROVIDES += "python-urlgrabber"
RPROVIDES_python-urlgrabber += "python-urlgrabber"
# the PROVIDES rules is ignore "urlgrabber = 3.9.1-0"
PROVIDES += "urlgrabber"
RPROVIDES_python-urlgrabber += "urlgrabber"

RDEPENDS = ""
#RDEPENDS of python-urlgrabber (${PN})
RDEPENDS_${PN} += "python-pycurl"
RDEPENDS_${PN} += "python-M2Crypto"


DEPENDS = ""
#DEPENDS of python-urlgrabber 
inherit pythonnative
DEPENDS += "python-pycurl"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n urlgrabber-3.9.1
 
 
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
 
 cp ${S}/packaging/python-urlgrabber.manifest .
 python setup.py build
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 python setup.py install --root=${D} -O1 --prefix=/usr
 
 
 
   rm -rf ${D}/usr/share/info 
   rm -rf ${D}/usr/share/doc/packages 
   rm -rf ${D}/usr/share/doc/python-urlgrabber 
   rm -rf ${D}/usr/share/doc/python-urlgrabber-3.9.1 
   rm -rf ${D}/usr/share/gtk-doc 
   rm -rf ${D}/usr/share/doc 
   rm -rf ${D}/usr/share/man 
   find ${D} -regex ".*/man/man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/../man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/man./.*.[0-9]pm" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "python-urlgrabber"

python-urlgrabber_files = ""
python-urlgrabber_files += "python-urlgrabber.manifest"
python-urlgrabber_files += "/usr/bin/urlgrabber"
python-urlgrabber_files += "/usr/lib/python2.7/site-packages/urlgrabber*"

FILES_${PN} = "${python-urlgrabber_files}"

PKG_python-urlgrabber= "python-urlgrabber"

require python-urlgrabber-extraconf.inc
