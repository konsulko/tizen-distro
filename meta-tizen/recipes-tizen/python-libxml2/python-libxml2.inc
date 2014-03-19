DESCRIPTION = "Python Bindings for libxml2"
HOMEPAGE = "http://xmlsoft.org"
SECTION = "Platform Development/Python"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-libxml2 
PROVIDES += "python-libxml2"
RPROVIDES_python-libxml2 += "python-libxml2"
# the PROVIDES rules is ignore "libxml2-python = 2.8.0"
PROVIDES += "libxml2-python"
RPROVIDES_python-libxml2 += "libxml2-python"

RDEPENDS = ""
#RDEPENDS of python-libxml2 (${PN})
RDEPENDS_${PN} += "libxml2"


DEPENDS = ""
#DEPENDS of python-libxml2 
inherit pythonnative
DEPENDS += "libxml2"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n libxml2-2.8.0
 
 
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
 
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fno-strict-aliasing"
 
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
     --with-fexceptions \
     --with-history \
     --enable-ipv6 \
     --with-sax1 \
     --with-regexps \
     --with-threads \
     --with-reader \
     --with-http
 
 # use libxml2 as built by libxml2 source package
 mkdir .libs
 cp -v /usr/lib/libxml2.la .
 make -C python -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make -C python install \
     DESTDIR=${D} \
     pythondir=/usr/lib/python2.7/site-packages \
     PYTHON_SITE_PACKAGES=/usr/lib/python2.7/site-packages
 chmod a-x python/tests/*.py
 # Unwanted doc stuff
 rm -fr ${D}/usr/share/doc
 rm -f python/tests/Makefile*
 # #223696
 rm -f ${D}/usr/lib/python2.7/site-packages/*.{la,a}
 
 
}

PACKAGES = ""
PACKAGES += "python-libxml2"

python-libxml2_files = ""
python-libxml2_files += "python/libxml2class.txt"
python-libxml2_files += "python/tests"
python-libxml2_files += "/usr/lib/python2.7/site-packages/*"

FILES_${PN} = "${python-libxml2_files}"

PKG_python-libxml2= "python-libxml2"

require python-libxml2-extraconf.inc
