DESCRIPTION = "IPv4 and IPv6 Networking Utilities"
HOMEPAGE = "http://www.skbuff.net/iputils"
SECTION = "Productivity/Networking/Other"
LICENSE = "BSD-3-Clause  GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by iputils 
PROVIDES += "iputils"
RPROVIDES_iputils += "iputils"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of iputils 
DEPENDS += "sysfsutils-devel"
DEPENDS += "libopenssl-devel"
DEPENDS += "libcap-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/iputils.manifest .
 mkdir linux
 touch linux/autoconf.h
 
 
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
 
 make -j16 KERNEL_INCLUDE=$PWD \
 	CCOPT='-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fno-strict-aliasing -fpie -D_GNU_SOURCE' \
 	LDLIBS='-pie -lcap -lresolv' \
 	CAPABILITIES=1
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p $RPM_BUILD_ROOT//usr/sbin
 mkdir -p $RPM_BUILD_ROOT//usr/bin
 install arping		$RPM_BUILD_ROOT//usr/sbin
 install clockdiff	$RPM_BUILD_ROOT//usr/sbin
 install rdisc		$RPM_BUILD_ROOT//usr/sbin/in.rdisc
 install tracepath	$RPM_BUILD_ROOT//usr/sbin
 install tracepath6	$RPM_BUILD_ROOT//usr/sbin
 install ping		$RPM_BUILD_ROOT//usr/bin
 install ping6		$RPM_BUILD_ROOT//usr/bin
 install ipg			$RPM_BUILD_ROOT//usr/bin
 
 
}

PACKAGES = ""
PACKAGES += "iputils"

iputils_files = ""
iputils_files += "iputils.manifest"
iputils_files += "/usr/sbin/arping"
iputils_files += "/usr/sbin/clockdiff"
iputils_files += "/usr/bin/ipg"
iputils_files += "/usr/sbin/tracepath"
iputils_files += "/usr/sbin/tracepath6"
iputils_files += "/usr/sbin/in.rdisc"

FILES_${PN} = "${iputils_files}"

PKG_iputils= "iputils"

require iputils-extraconf.inc
