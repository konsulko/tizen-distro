DESCRIPTION = "Python Interpreter"
HOMEPAGE = "http://www.python.org/"
SECTION = "Development/Languages"
LICENSE = "Python-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python 
PROVIDES += "python"
RPROVIDES_python += "python"
# the PROVIDES rules is ignore "python = 2.7"
PROVIDES += "python"
RPROVIDES_python += "python"
# the PROVIDES rules is ignore "/bin/python  "
PROVIDES += "/bin/python"
RPROVIDES_python += "/bin/python"

#PROVIDES by python-xml 
PROVIDES += "python-xml"
RPROVIDES_python-xml += "python-xml"
# the PROVIDES rules is ignore "pyxml = 0.8.5"
PROVIDES += "pyxml"
RPROVIDES_python-xml += "pyxml"

#PROVIDES by libpython 
PROVIDES += "libpython"
RPROVIDES_libpython += "libpython"

#PROVIDES by python-curses 
PROVIDES += "python-curses"
RPROVIDES_python-curses += "python-curses"
# the PROVIDES rules is ignore "pyth_cur  "
PROVIDES += "pyth_cur"
RPROVIDES_python-curses += "pyth_cur"

#PROVIDES by python-devel 
PROVIDES += "python-devel"
RPROVIDES_python-devel += "python-devel"
RPROVIDES_python-devel += "python-dev"

RDEPENDS = ""
#RDEPENDS of python-xml (${PN}-xml)
RDEPENDS_${PN}-xml += "python"

#RDEPENDS of python-curses (${PN}-curses)
RDEPENDS_${PN}-curses += "python"

#RDEPENDS of python-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "python"
RDEPENDS_${PN}-devel += "glibc-dev"


DEPENDS = ""
#DEPENDS of python 
DEPENDS += "zlib-devel"
DEPENDS += "bzip2"
DEPENDS += "fdupes-native"
DEPENDS += "readline-devel"
DEPENDS += "ncurses"
DEPENDS += "openssl"
DEPENDS += "automake-native"
DEPENDS += "gmp"
DEPENDS += "db4"
DEPENDS += "sqlite-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Python-2.7.3
 
 # drop Autoconf version requirement
 sed -i 's/^version_required/dnl version_required/' configure.in
 
 # remove newslist.py because of bad license
 rm Demo/scripts/newslist.*
 
 
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
 
 cp ${S}/packaging/python.manifest .
 export OPT=$(echo $RPM_OPT_FLAGS | sed -s "s/--param=ssp-buffer-size=32//g")
 
 autoreconf -f -i . # Modules/_ctypes/libffi
 # prevent make from trying to rebuild asdl stuff, which requires existing
 # python installation
 touch Parser/asdl* Python/Python-ast.c Include/Python-ast.h
 
 
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
     --docdir=/usr/share/doc/packages/python \
     --enable-ipv6 \
     --with-fpectl \
     --enable-shared \
     --enable-unicode=ucs4
 
 LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH \
     make -j16 profile-opt
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 # replace rest of /usr/local/bin/python or /usr/bin/python2.x with /usr/bin/python
 find . -wholename "./Parser" -prune -o -name '*.py' -type f -print0 | xargs -0 grep -lE '^#! *(/usr/.*bin/(env +)?)?python' | xargs sed -r -i -e '1s@^#![[:space:]]*(/usr/(local/)?bin/(env +)?)?python([0-9]+\.[0-9]+)?@#!/usr/bin/python@'
 # the grep inbetween makes it much faster
 ########################################
 # install it
 ########################################
 export OPT=$(echo $RPM_OPT_FLAGS | sed -s "s/--param=ssp-buffer-size=32//g")
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f -- 
 # install site-specific tweaks
 #ln -s python2.7 ${D}/usr/bin/python2
 install -m 644 ${S}/packaging/python.csh ${D}/usr/lib/python2.7/distutils
 install -m 644 ${S}/packaging/_local.pth ${D}/usr/lib/python2.7/site-packages
 install -d -m 755 ${D}/etc/rpm
 install -m 644 ${S}/packaging/macros.python ${D}/etc/rpm
 # make sure /usr/lib/python/site-packages exists even on lib64 machines
 mkdir -p ${D}/usr/lib/python2.7/site-packages
 
 ########################################
 # some cleanups
 ########################################
 # remove hard links and replace them with symlinks
 for dir in bin include lib ; do
     rm -f ${D}//usr/$dir/python
     ln -s python2.7 ${D}//usr/$dir/python
 done
 # kill imageop.so, it's insecure
 rm -f ${D}//usr/lib/python2.7/lib-dynload/imageop.so
 # replace duplicate .pyo/.pyc with hardlinks
 
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r ${D}//usr/lib/python2.7 | 
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
 ########################################
 # documentation
 ########################################
 export PDOCS=${D}/usr/share/doc/packages/python
 install -d -m 755 $PDOCS
 install -c -m 644 README                            $PDOCS/
 ln -s python2.7.1.gz ${D}/usr/share/man/man1/python.1.gz
 
 ########################################
 # devel
 ########################################
 # install Makefile.pre.in and Makefile.pre
 cp Makefile Makefile.pre.in Makefile.pre ${D}/usr/lib/python2.7/config/
 
 ########################################
 # startup script
 ########################################
 install -d -m 755 ${D}/etc/profile.d
 install -m 644 ${S}/packaging/pythonstart ${D}/etc
 install -m 644 ${S}/packaging/python.sh ${S}/packaging/python.csh ${D}/etc/profile.d
 
 rm -rf ${D}/usr/bin/idle
 rm -rf ${D}/usr/lib/python2.7/idlelib
 rm -rf ${D}/usr/lib/python2.7/lib-tk
 
 
}

PACKAGES = ""
PACKAGES += "python-xml"
PACKAGES += "python"
PACKAGES += "libpython"
PACKAGES += "python-devel"
PACKAGES += "python-curses"

python-xml_files = ""
python-xml_files += "python.manifest"
python-xml_files += "/usr/lib/python2.7/xml"
python-xml_files += "/usr/lib/python2.7/lib-dynload/pyexpat.so"

python_files = ""
python_files += "python.manifest"
python_files += "/usr/share/doc/packages/python"
python_files += "/usr/share/doc/packages/python/README"
python_files += "/etc/pythonstart"
python_files += "/etc/profile.d/python.*"
python_files += "/usr/lib/python2.7"
python_files += "/usr/lib/python2.7/ssl.py*"
python_files += "/usr/lib/python2.7/bsddb"
python_files += "/usr/lib/python2.7/sqlite3"
python_files += "/usr/lib/python2.7/lib-dynload"
python_files += "/usr/lib/python2.7/lib-dynload/_bsddb.so"
python_files += "/usr/lib/python2.7/lib-dynload/_hashlib.so"
python_files += "/usr/lib/python2.7/lib-dynload/_sqlite3.so"
python_files += "/usr/lib/python2.7/lib-dynload/_ssl.so"
python_files += "/usr/lib/python2.7/lib-dynload/readline.so"
python_files += "/etc/rpm/macros.python"
python_files += "/usr/share/man/man1/python.1*"
python_files += "/usr/share/man/man1/python2.7.1*"
python_files += "/usr/include/python2.7"
python_files += "/usr/include/python2.7/pyconfig.h"
python_files += "/usr/lib/python"
python_files += "/usr/lib/python2.7"
python_files += "/usr/lib/python2.7/site-packages"
python_files += "/usr/lib/python2.7"
python_files += "/usr/lib/python2.7/config"
python_files += "/usr/lib/python2.7/config/Setup"
python_files += "/usr/lib/python2.7/config/Makefile"
python_files += "/usr/lib/python2.7/*.*"
python_files += "/usr/lib/python2.7/compiler"
python_files += "/usr/lib/python2.7/ctypes"
python_files += "/usr/lib/python2.7/distutils"
python_files += "/usr/lib/python2.7/email"
python_files += "/usr/lib/python2.7/encodings"
python_files += "/usr/lib/python2.7/hotshot"
python_files += "/usr/lib/python2.7/importlib"
python_files += "/usr/lib/python2.7/json"
python_files += "/usr/lib/python2.7/lib2to3"
python_files += "/usr/lib/python2.7/logging"
python_files += "/usr/lib/python2.7/multiprocessing"
python_files += "/usr/lib/python2.7/plat-*"
python_files += "/usr/lib/python2.7/pydoc_data"
python_files += "/usr/lib/python2.7/unittest"
python_files += "/usr/lib/python2.7/wsgiref"
python_files += "/usr/lib/python2.7/site-packages"
python_files += "/usr/lib/python2.7/site-packages/README"
python_files += "/usr/lib/python2.7/site-packages/_local.pth"
python_files += "/usr/lib/python2.7/lib-dynload"
python_files += "/usr/lib/python2.7/lib-dynload/_bisect.so"
python_files += "/usr/lib/python2.7/lib-dynload/_csv.so"
python_files += "/usr/lib/python2.7/lib-dynload/_collections.so"
python_files += "/usr/lib/python2.7/lib-dynload/_ctypes.so"
python_files += "/usr/lib/python2.7/lib-dynload/_ctypes_test.so"
python_files += "/usr/lib/python2.7/lib-dynload/_elementtree.so"
python_files += "/usr/lib/python2.7/lib-dynload/_functools.so"
python_files += "/usr/lib/python2.7/lib-dynload/_heapq.so"
python_files += "/usr/lib/python2.7/lib-dynload/_hotshot.so"
python_files += "/usr/lib/python2.7/lib-dynload/_io.so"
python_files += "/usr/lib/python2.7/lib-dynload/nis.so"
python_files += "/usr/lib/python2.7/lib-dynload/_json.so"
python_files += "/usr/lib/python2.7/lib-dynload/_locale.so"
python_files += "/usr/lib/python2.7/lib-dynload/_lsprof.so"
python_files += "/usr/lib/python2.7/lib-dynload/audioop.so"
python_files += "/usr/lib/python2.7/lib-dynload/dbm.so"
python_files += "/usr/lib/python2.7/lib-dynload/_multiprocessing.so"
python_files += "/usr/lib/python2.7/lib-dynload/_random.so"
python_files += "/usr/lib/python2.7/lib-dynload/_socket.so"
python_files += "/usr/lib/python2.7/lib-dynload/_struct.so"
python_files += "/usr/lib/python2.7/lib-dynload/_testcapi.so"
python_files += "/usr/lib/python2.7/lib-dynload/array.so"
python_files += "/usr/lib/python2.7/lib-dynload/binascii.so"
python_files += "/usr/lib/python2.7/lib-dynload/bz2.so"
python_files += "/usr/lib/python2.7/lib-dynload/cPickle.so"
python_files += "/usr/lib/python2.7/lib-dynload/cStringIO.so"
python_files += "/usr/lib/python2.7/lib-dynload/cmath.so"
python_files += "/usr/lib/python2.7/lib-dynload/crypt.so"
python_files += "/usr/lib/python2.7/lib-dynload/datetime.so"
python_files += "/usr/lib/python2.7/lib-dynload/fcntl.so"
python_files += "/usr/lib/python2.7/lib-dynload/future_builtins.so"
python_files += "/usr/lib/python2.7/lib-dynload/grp.so"
python_files += "/usr/lib/python2.7/lib-dynload/itertools.so"
python_files += "/usr/lib/python2.7/lib-dynload/linuxaudiodev.so"
python_files += "/usr/lib/python2.7/lib-dynload/math.so"
python_files += "/usr/lib/python2.7/lib-dynload/mmap.so"
python_files += "/usr/lib/python2.7/lib-dynload/operator.so"
python_files += "/usr/lib/python2.7/lib-dynload/ossaudiodev.so"
python_files += "/usr/lib/python2.7/lib-dynload/parser.so"
python_files += "/usr/lib/python2.7/lib-dynload/resource.so"
python_files += "/usr/lib/python2.7/lib-dynload/select.so"
python_files += "/usr/lib/python2.7/lib-dynload/spwd.so"
python_files += "/usr/lib/python2.7/lib-dynload/strop.so"
python_files += "/usr/lib/python2.7/lib-dynload/syslog.so"
python_files += "/usr/lib/python2.7/lib-dynload/termios.so"
python_files += "/usr/lib/python2.7/lib-dynload/time.so"
python_files += "/usr/lib/python2.7/lib-dynload/unicodedata.so"
python_files += "/usr/lib/python2.7/lib-dynload/zlib.so"
python_files += "/usr/lib/python2.7/lib-dynload/_codecs*.so"
python_files += "/usr/lib/python2.7/lib-dynload/_multibytecodec.so"
python_files += "/usr/lib/python2.7/lib-dynload/Python-2.7.3-py2.7.egg-info"
python_files += "/usr/bin/python2"

libpython_files = ""
libpython_files += "python.manifest"
libpython_files += "/usr/lib/libpython*.so.*"

python-devel_files = ""
python-devel_files += "python.manifest"
python-devel_files += "/usr/lib/python2.7/config/*"
python-devel_files += "/usr/lib/libpython*.so"
python-devel_files += "/usr/lib/pkgconfig/python-2.7.pc"
python-devel_files += "/usr/lib/pkgconfig/python.pc"
python-devel_files += "/usr/lib/pkgconfig/python2.pc"
python-devel_files += "/usr/include/python*"
python-devel_files += "/usr/lib/python2.7/test"
python-devel_files += "/usr/bin/python-config"
python-devel_files += "/usr/bin/python2-config"
python-devel_files += "/usr/bin/python2.7-config"

python-curses_files = ""
python-curses_files += "python.manifest"
python-curses_files += "/usr/lib/python2.7/curses"
python-curses_files += "/usr/lib/python2.7/lib-dynload/_curses.so"
python-curses_files += "/usr/lib/python2.7/lib-dynload/_curses_panel.so"

FILES_${PN}-xml = "${python-xml_files}"
FILES_${PN} = "${python_files}"
FILES_lib${PN} = "${libpython_files}"
FILES_${PN}-devel = "${python-devel_files}"
FILES_${PN}-curses = "${python-curses_files}"

PKG_python-xml= "python-xml"
PKG_python= "python"
PKG_libpython= "libpython"
PKG_python-devel= "python-devel"
PKG_python-curses= "python-curses"

require python-extraconf.inc
