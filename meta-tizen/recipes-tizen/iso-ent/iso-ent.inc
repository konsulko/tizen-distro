DESCRIPTION = "Character Entity Sets for ISO 8879:1986"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Productivity/Publishing/SGML"
LICENSE = "SUSE-Permissive"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by iso_ent 
PROVIDES += "iso_ent"
RPROVIDES_iso_ent += "iso_ent"
# the PROVIDES rules is ignore "iso-ent  "
PROVIDES += "iso-ent"
RPROVIDES_iso_ent += "iso-ent"
# the PROVIDES rules is ignore "iso-entities  "
PROVIDES += "iso-entities"
RPROVIDES_iso_ent += "iso-entities"

RDEPENDS = ""
#RDEPENDS of iso_ent (iso_ent)
RDEPENDS_iso_ent += "/usr/bin/sgml-register-catalog"


DEPENDS = ""
#DEPENDS of iso_ent 
DEPENDS += "sgml-skel"
DEPENDS += "unzip"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/iso_ent.manifest .
 
 
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
 
 root=$RPM_BUILD_ROOT
 # sgml_dir=${root}/usr/share/sgml
 # sgml_dir_config=${root}/var/lib/sgml
 sgml_dir_iso=$RPM_BUILD_ROOT/usr/share/sgml/iso-ent
 sgml_dir_ISO=$RPM_BUILD_ROOT/usr/share/sgml/ISO_8879:1986/entities
 install -d -m755 $RPM_BUILD_ROOT/var/lib/sgml
 install -d -m755 $RPM_BUILD_ROOT/usr/share/sgml/iso-ent
 install -d -m755 $RPM_BUILD_ROOT/usr/share/sgml/{ISO_8879:1986,ISO_9573-15:1993}/entities
 install -m644 ISO* $RPM_BUILD_ROOT/usr/share/sgml/iso-ent
 install -m644 CATALOG $RPM_BUILD_ROOT/var/lib/sgml/CATALOG.iso_ent
 pushd $RPM_BUILD_ROOT/usr/share/sgml
 ln -sf ../../../var/lib/sgml/CATALOG.iso_ent CATALOG.iso_ent
 rm -f ISO_8879-1986 
 ln -s ISO_8879:1986 ISO_8879-1986
 popd
 pushd ${sgml_dir_ISO}
 rm -f * 2>/dev/null
 ln -s ../../iso-ent/ISOamsa Added_Math_Symbols:_Arrow_Relations
 ln -s ../../iso-ent/ISOamsb Added_Math_Symbols:_Binary_Operators
 ln -s ../../iso-ent/ISOamsc Added_Math_Symbols:_Delimiters
 ln -s ../../iso-ent/ISOamsn Added_Math_Symbols:_Negated_Relations
 ln -s ../../iso-ent/ISOamso Added_Math_Symbols:_Ordinary
 ln -s ../../iso-ent/ISOamsr Added_Math_Symbols:_Relations
 ln -s ../../iso-ent/ISObox Box_and_Line_Drawing
 ln -s ../../iso-ent/ISOcyr1 Russian_Cyrillic
 ln -s ../../iso-ent/ISOcyr2 Non-Russian_Cyrillic
 ln -s ../../iso-ent/ISOdia Diacritical_Marks
 ln -s ../../iso-ent/ISOgrk1 Greek_Letters
 ln -s ../../iso-ent/ISOgrk2 Monotoniko_Greek
 ln -s ../../iso-ent/ISOgrk3 Greek_Symbols
 ln -s ../../iso-ent/ISOgrk4 Alternative_Greek_Symbols
 ln -s ../../iso-ent/ISOlat1 Added_Latin_1
 ln -s ../../iso-ent/ISOlat2 Added_Latin_2
 ln -s ../../iso-ent/ISOnum Numeric_and_Special_Graphic
 ln -s ../../iso-ent/ISOpub Publishing
 ln -s ../../iso-ent/ISOtech General_Technical
 popd
 pushd $RPM_BUILD_ROOT/usr/share/sgml
 rm -f ISO_9573-15-1993
 ln -s ISO_9573-15:1993 ISO_9573-15-1993
 popd
 pushd $RPM_BUILD_ROOT/usr/share/sgml/ISO_9573-15:1993/entities
 rm -f * 2>/dev/null
 ln -s ../../iso-ent/ISOgrk5 Extra_Classical_Greek_Letters
 popd
 
 
}

PACKAGES = ""
PACKAGES += "iso_ent"

iso_ent_files = ""
iso_ent_files += "iso_ent.manifest"
iso_ent_files += "/var/lib/sgml/CATALOG.iso_ent"
iso_ent_files += "/usr/share/sgml/CATALOG.iso_ent"
iso_ent_files += "/usr/share/sgml/iso-ent"
iso_ent_files += "/usr/share/sgml/ISO_8879-1986"
iso_ent_files += "/usr/share/sgml/ISO_8879:1986"
iso_ent_files += "/usr/share/sgml/ISO_9573-15:1993"
iso_ent_files += "/usr/share/sgml/ISO_9573-15-1993"

FILES_${PN} = "${iso_ent_files}"

PKG_iso_ent= "iso_ent"

require iso-ent-extraconf.inc
