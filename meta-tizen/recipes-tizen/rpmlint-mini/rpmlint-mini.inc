DESCRIPTION = "Rpm correctness checker"
HOMEPAGE = "http://rpmlint.zarb.org/"
SECTION = "System/Packages"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by rpmlint-mini 
PROVIDES += "rpmlint-mini"
RPROVIDES_rpmlint-mini += "rpmlint-mini"

RDEPENDS = ""
#RDEPENDS of rpmlint-mini (${PN})
RDEPENDS_${PN} += "cpio"


DEPENDS = ""
#DEPENDS of rpmlint-mini 
DEPENDS += "glib"
DEPENDS += "python-rpm"
DEPENDS += "dash"
inherit pythonnative
DEPENDS += "rpmlint"
DEPENDS += "libtool-cross"
DEPENDS += "python-magic"

do_patch() {
 #extracte source 99 
 pushd ${S}/../
 unp ${S}/packaging/desktop-file-utils-0.20.tar.xz 
 popd 
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q  -b 99
 cp ${S}/packaging/rpmlint-mini.manifest .
 cd ../desktop-file-utils-0.20
 
 
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
 
 cd ../desktop-file-utils-0.20
 
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
         --infodir=/usr/share/info
 pushd src
 make desktop-file-validate V=1 DESKTOP_FILE_UTILS_LIBS="/usr/lib/libglib-2.0.a -lpthread -lrt"
 popd
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 cd ../desktop-file-utils-0.20
 pwd
 # test if the rpmlint works at all
 set +e
 /usr/bin/rpmlint rpmlint
 test $? -gt 0 -a $? -lt 60 && exit 1
 set -e
 # okay, lets put it together
 mkdir -p $RPM_BUILD_ROOT/opt/testing/share/rpmlint
 install -m 755 -D src/desktop-file-validate $RPM_BUILD_ROOT/opt/testing/bin/desktop-file-validate
 cp -a /usr/share/rpmlint/*.py $RPM_BUILD_ROOT/opt/testing/share/rpmlint
 # install config files
 install -d -m 755 $RPM_BUILD_ROOT/opt/testing/share/rpmlint/mini
 for i in /etc/rpmlint/{licenses,rpmgroups,pie}.config; do
   cp $i $RPM_BUILD_ROOT/opt/testing/share/rpmlint/mini
 done
 install -m 644 -D /usr/share/rpmlint/config $RPM_BUILD_ROOT/opt/testing/share/rpmlint/config
 install -m 644 "${S}/packaging/rpmlint-mini.config" $RPM_BUILD_ROOT/opt/testing/share/rpmlint
 # extra data
 install -m 755 -d $RPM_BUILD_ROOT/opt/testing/share/rpmlint/data
 #install -m 644 /etc/polkit-default-privs.standard $RPM_BUILD_ROOT/opt/testing/share/rpmlint/data
 install -m 644 -D /usr/include/python2.7/pyconfig.h $RPM_BUILD_ROOT/opt/testing/include/python2.7/pyconfig.h
 #
 cd /usr/lib/python2.7
 for f in $(<${S}/packaging/rpmlint-deps.txt); do
   echo $f
   find -path "*/$f" -exec install -D {} $RPM_BUILD_ROOT/opt/testing/lib/python2.7/{} \;
 done
 install -m 644 /usr/lib/python2.7/site-packages/magic.py $RPM_BUILD_ROOT/opt/testing/lib/python2.7/site-packages/magic.py
 install -D /usr/bin/python $RPM_BUILD_ROOT/opt/testing/bin/python
 cp -a /usr/lib/libmagic.so.* $RPM_BUILD_ROOT/opt/testing/lib
 cp -a /usr/lib/libpython2.7.so.* $RPM_BUILD_ROOT/opt/testing/lib
 cp -a /usr/bin/rpmlint $RPM_BUILD_ROOT/opt/testing/share/rpmlint/rpmlint.py
 pushd $RPM_BUILD_ROOT/opt/testing/share/rpmlint
 PYTHONOPTIMIZE=1 python /usr/lib/python2.7/py_compile.py *.py
 rm *.py
 popd
 pushd $RPM_BUILD_ROOT/opt/testing/lib/python2.7/site-packages/
 PYTHONOPTIMIZE=1 python /usr/lib/python2.7/py_compile.py *.py
 rm *.py
 popd
 rm -rf $RPM_BUILD_ROOT/{usr,etc}
 rm -f $RPM_BUILD_ROOT/opt/testing/bin/rpmlint
 install -m 755 -D ${S}/packaging/rpmlint.wrapper $RPM_BUILD_ROOT/opt/testing/bin/rpmlint
 # hackatlon
 cat << EOF > ${WORKDIR}/git/rpmlint-mini-requires
 cat - > file.list
 /usr/share/spec2yocto/macro/find-requires rpmlint-mini < file.list > requires.list
 /usr/share/spec2yocto/macro/find-provides rpmlint-mini < file.list > provides.list
 while read i; do
     grep -F -v "\$i" requires.list > requires.list.new
     mv requires.list.new requires.list
 done < provides.list
 cat requires.list
 rm -f requires.list provides.list file.list
 EOF
 chmod +x ${WORKDIR}/git/rpmlint-mini-requires
 # final run check to detect python dep changes
 LD_LIBRARY_PATH=$RPM_BUILD_ROOT/opt/testing/lib
 PYTHONPATH=$RPM_BUILD_ROOT/opt/testing/share/rpmlint
 export PYTHONPATH LD_LIBRARY_PATH
 $RPM_BUILD_ROOT/opt/testing/bin/python -tt -u -O $RPM_BUILD_ROOT/opt/testing/share/rpmlint/rpmlint.pyo --help || exit 1
 echo ".. ok"
 
 
 
}

PACKAGES = ""
PACKAGES += "rpmlint-mini"

rpmlint-mini_files = ""
rpmlint-mini_files += "rpmlint-mini.manifest"
rpmlint-mini_files += "/opt/testing"

FILES_${PN} = "${rpmlint-mini_files}"

PKG_rpmlint-mini= "rpmlint-mini"

require rpmlint-mini-extraconf.inc
