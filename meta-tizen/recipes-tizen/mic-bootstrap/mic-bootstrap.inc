DESCRIPTION = "mic bootstrap"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Tools"
LICENSE = "GPLv2"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by mic-bootstrap 
PROVIDES += "mic-bootstrap"
RPROVIDES_mic-bootstrap += "mic-bootstrap"
# the PROVIDES rules is ignore "mic-bootstrap  "
PROVIDES += "mic-bootstrap"
RPROVIDES_mic-bootstrap += "mic-bootstrap"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of mic-bootstrap 
DEPENDS += "kmod"
DEPENDS += "syslinux"
DEPENDS += "grep"
DEPENDS += "rpm-security-plugin"
DEPENDS += "python-rpm"
DEPENDS += "libzypp-bindings"
DEPENDS += "mic"
DEPENDS += "psmisc"
DEPENDS += "syslinux-extlinux"
DEPENDS += "lsof"
DEPENDS += "python-xml"
DEPENDS += "util-linux"
DEPENDS += "rpm"

do_patch() {
 
 
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
 
 set +x
 
 mkdir -p ${D}
 mkdir -p ${D}/bootstrap
 rpm -qla > filestoinclude1
 
 # ignore files - construct sed script
 sedtmp="sedtmp.$$"
 echo "s#^/usr/share/doc/packages.*##" >> $sedtmp
 echo "s#^/usr/share/man.*##" >> $sedtmp
 echo "s#^/usr/share/info.*##" >> $sedtmp
 # ignore pyc and pyo
 echo "s#^.*\.pyc\$##" >> $sedtmp
 echo "s#^.*\.pyo\$##" >> $sedtmp
 
 # ignore default filesystem files
 for i in `rpm -ql filesystem`; do
   echo "s#^${i}\$##" >> $sedtmp
 done
 
 #finish up
 echo "/^\$/d" >> $sedtmp
 
 #execute
 sed -f $sedtmp -i filestoinclude1
 
 # tar copy to bootstrap dir under buildroot
 # prefix /bootstrap will fix conflicts
 tar -T filestoinclude1 -cpf - | ( cd ${D}/bootstrap && tar -xpf - )
 # tar copy /usr/bin and /usr/sbin to /bin and /sbin to fix symblic lost in tar
 (cd /usr/bin && tar -cpf - *) | (cd ${D}/bootstrap/bin && tar -xpf -)
 (cd /usr/sbin && tar -cpf - *) | (cd ${D}/bootstrap/sbin && tar -xpf -)
 rm filestoinclude1
 
 # Todo: refractor
 # no directories, in filelist
 find ${D} >  filestoinclude2
 cat filestoinclude2 | sed -e "s#${D}##g" | uniq | sort > filestoinclude1
 for i in `cat filestoinclude1`; do
 # no directories
   if test -h ${D}/$i || ! test -d ${D}/$i; then
     #
     echo "$i" >> filestoinclude
   fi
 done
 rm filestoinclude1
 rm filestoinclude2
 
 set -x
 
 
}

PACKAGES = ""
PACKAGES += "mic-bootstrap"

mic-bootstrap_files = ""

FILES_${PN} = "${mic-bootstrap_files}"

PKG_mic-bootstrap= "mic-bootstrap"

require mic-bootstrap-extraconf.inc
