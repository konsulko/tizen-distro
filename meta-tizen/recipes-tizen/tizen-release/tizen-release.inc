DESCRIPTION = "Tizen release files"
HOMEPAGE = "http://www.tizen.com"
SECTION = "System/Base"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by tizen-release 
PROVIDES += "tizen-release"
RPROVIDES_tizen-release += "tizen-release"
# the PROVIDES rules is ignore "system-release = 3.0.0"
PROVIDES += "system-release"
RPROVIDES_tizen-release += "system-release"
# the PROVIDES rules is ignore "tizen-release = 3.0.0"
PROVIDES += "tizen-release"
RPROVIDES_tizen-release += "tizen-release"
# the PROVIDES rules is ignore "product()  "
PROVIDES += "product()"
RPROVIDES_tizen-release += "product()"
# the PROVIDES rules is ignore "product(Tizen) = 3.0.0"
PROVIDES += "product(Tizen)"
RPROVIDES_tizen-release += "product(Tizen)"
# the PROVIDES rules is ignore "lsb = 4.1"
PROVIDES += "lsb"
RPROVIDES_tizen-release += "lsb"

RDEPENDS = ""

DEPENDS = ""

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
 
 
 
 install -d ${D}/etc
 cat > ${D}/etc/tizen-release <<EOF
 Tizen 3.0.0 (x86_64)
 VERSION = 3.0.0
 CODENAME = Next
 EOF
 
 ln -s tizen-release ${D}/etc/system-release
 
 cat > ${D}/etc/os-release <<EOF
 NAME=Tizen
 VERSION="3.0.0 (Tizen Next)"
 ID=tizen
 VERSION_ID=3.0.0
 PRETTY_NAME="Tizen 3.0.0 (Tizen Next)"
 ANSI_COLOR="0;36"
 CPE_NAME="cpe:/o:tizen:tizen:3.0.0"
 EOF
 
 mkdir -p ${D}/etc/products.d
 cat >${D}/etc/products.d/tizen.prod << EOF
 <?xml version="1.0" encoding="UTF-8"?>
 <product schemeversion="0">
   <vendor>Tizen.org</vendor>
   <name>Tizen</name>
   <version>3.0.0</version>
   <release>2</release>
   <arch>x86_64</arch>
   <productline>Tizen</productline>
   <register>
     <target>tizen-3.0.0-x86_64</target>
     <release></release>
     <repositories>
     </repositories>
   </register>
   <updaterepokey>000000000</updaterepokey>
   <summary>Tizen</summary>
   <description>Tizen</description>
   <linguas>
     <language>cs</language>
     <language>da</language>
     <language>de</language>
     <language>en</language>
     <language>en_GB</language>
     <language>en_US</language>
     <language>es</language>
     <language>fi</language>
     <language>fr</language>
     <language>hu</language>
     <language>it</language>
     <language>ja</language>
     <language>nb</language>
     <language>nl</language>
     <language>pl</language>
     <language>pt</language>
     <language>pt_BR</language>
     <language>ru</language>
     <language>sv</language>
     <language>zh</language>
     <language>zh_CN</language>
     <language>zh_TW</language>
   </linguas>
   <urls>
     <url name="releasenotes">http://www.tizen.org</url>
     <url name="register">http://www.tizen.org/</url>
     <url name="repository">https://download.tizen.org/snapshots/tizen/common/latest/repos/tizen/x86_64/packages/</url>
   </urls>
   <buildconfig>
     <producttheme>Tizen</producttheme>
     <betaversion>Milestone 1</betaversion>
   </buildconfig>
   <installconfig>
     <defaultlang>en_US</defaultlang>
     <releasepackage name="tizen-release" flag="EQ" version="3.0.0" release="2" />
     <distribution>Tizen</distribution>
   </installconfig>
   <runtimeconfig />
 </product>
 
 EOF
 
 # this is a base product, create symlink
 ln -s tizen.prod ${D}/etc/products.d/baseproduct
 
 
 
}

PACKAGES = ""
PACKAGES += "tizen-release"

tizen-release_files = ""
#Remove rpm attribut "%attr(0644,root,root)"
tizen-release_files += "/etc/tizen-release"
#Remove rpm attribut "%attr(0644,root,root)"
tizen-release_files += "/etc/os-release"
tizen-release_files += "/etc/system-release"
tizen-release_files += "/etc/products.d"

FILES_${PN} = "${tizen-release_files}"

PKG_tizen-release= "tizen-release"

require tizen-release-extraconf.inc
