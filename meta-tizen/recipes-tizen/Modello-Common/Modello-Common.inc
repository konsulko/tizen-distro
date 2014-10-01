DESCRIPTION = "Pure html5 UI"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Automotive/Modello"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by Modello-Common


RDEPENDS = ""

DEPENDS = ""
#DEPENDS of Modello-Common
DEPENDS_append_class-native = " fdupes-native"
DEPENDS_append_class-target = " fdupes-native"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Modello-Common-0.0.2
 cp ${S}/packaging/Modello-Common.manifest .
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;
 
 #empty
 
 
 
}

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 mkdir -p ${D}${prefix}/share/Modello/Common/
 cp -r css ${D}${prefix}/share/Modello/Common/
 cp -r js ${D}${prefix}/share/Modello/Common/
 
 
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r ${D}${prefix}/share | 
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
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " Modello-Common "

Modello-Common_files = ""
Modello-Common_files += "${prefix}/share/Modello/Common/js"
Modello-Common_files += "${prefix}/share/Modello/Common/css"
MANIFESTFILES_${PN} = "Modello-Common.manifest"

FILES_${PN} = "${Modello-Common_files}"

PKG_Modello-Common= "Modello-Common"

require Modello-Common-extraconf.inc

