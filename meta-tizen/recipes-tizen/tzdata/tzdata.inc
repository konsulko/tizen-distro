DESCRIPTION = "Timezone Descriptions"
HOMEPAGE = "http://www.gnu.org/software/libc/libc.html"
SECTION = "Base/Configuration"
LICENSE = "BSD-3-Clause and SUSE-Public-Domain"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by tzdata 
PROVIDES += "tzdata"
RPROVIDES_tzdata += "tzdata"
# the PROVIDES rules is ignore "timezone  "
PROVIDES += "timezone"
RPROVIDES_tzdata += "timezone"

RDEPENDS = ""
#RDEPENDS of tzdata (${PN})
RDEPENDS_${PN} += "coreutils"
RDEPENDS_${PN} += "filesystem"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -c 
 cp ${S}/packaging/tzdata.manifest .
 # COMMON-PREP-BEGIN
 # COMMON-PREP-END
 
 
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
 
 unset ${!LC_*}
 LANG=POSIX
 LC_ALL=POSIX
 AREA=Etc
 ZONE=UTC
 export AREA LANG LC_ALL ZONE
 make -j16 TZDIR=/usr/share/zoneinfo CFLAGS="$RPM_OPT_FLAGS -DHAVE_GETTEXT=1 -DTZDEFAULT='\"/etc/localtime\"'" AWK=awk
 make -j16 TZDIR=zoneinfo AWK=awk zones
 # Generate posixrules
 ./zic -y ./yearistype -d zoneinfo -p Etc/UTC
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}/usr/share/zoneinfo
 cp -a zoneinfo ${D}/usr/share/zoneinfo/posix
 cp -al ${D}/usr/share/zoneinfo/posix/. ${D}/usr/share/zoneinfo
 cp -a zoneinfo-leaps ${D}/usr/share/zoneinfo/right
 mkdir -p ${D}/etc
 rm -f  ${D}/etc/localtime
 rm -f  ${D}/usr/share/zoneinfo/posixrules
 cp -fp ${D}/usr/share/zoneinfo/Etc/UTC ${D}/etc/localtime
 ln -sf /etc/localtime      ${D}/usr/share/zoneinfo/posixrules
 install -m 644 iso3166.tab ${D}/usr/share/zoneinfo/iso3166.tab
 install -m 644 zone.tab    ${D}/usr/share/zoneinfo/zone.tab
 install -D -m 755 tzselect ${D}/usr/bin/tzselect
 install -D -m 755 zdump    ${D}/usr/sbin/zdump
 install -D -m 755 zic      ${D}/usr/sbin/zic
 
 
}

PACKAGES = ""
PACKAGES += "tzdata"

tzdata_files = ""
tzdata_files += "tzdata.manifest"
tzdata_files += "/usr/share/zoneinfo"
tzdata_files += "/usr/bin/tzselect"
tzdata_files += "/usr/sbin/zdump"
tzdata_files += "/usr/sbin/zic"

FILES_${PN} = "${tzdata_files}"

PKG_tzdata= "tzdata"

require tzdata-extraconf.inc
