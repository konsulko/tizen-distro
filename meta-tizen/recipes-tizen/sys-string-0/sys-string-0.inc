DESCRIPTION = "System string package for multilinugual support"
HOMEPAGE = "http://nohomepage.org"
SECTION = "TO_BE/FILLED_IN"
LICENSE = "Apache License, Version 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by sys-string 
PROVIDES += "sys-string"
RPROVIDES_sys-string += "sys-string"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of sys-string 
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/sys-string.manifest .
 
 
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
 
 /usr/bin/msgfmt -o ar.mo ar.po
 /usr/bin/msgfmt -o az.mo az.po
 /usr/bin/msgfmt -o bg.mo bg.po
 /usr/bin/msgfmt -o ca.mo ca.po
 /usr/bin/msgfmt -o cs.mo cs.po
 /usr/bin/msgfmt -o da.mo da.po
 /usr/bin/msgfmt -o de_DE.mo de_DE.po
 /usr/bin/msgfmt -o el_GR.mo el_GR.po
 /usr/bin/msgfmt -o en.mo en.po
 /usr/bin/msgfmt -o en_PH.mo en_PH.po
 /usr/bin/msgfmt -o en_US.mo en_US.po
 /usr/bin/msgfmt -o es_ES.mo es_ES.po
 /usr/bin/msgfmt -o es_MX.mo es_MX.po
 /usr/bin/msgfmt -o et.mo et.po
 /usr/bin/msgfmt -o eu.mo eu.po
 /usr/bin/msgfmt -o fi.mo fi.po
 /usr/bin/msgfmt -o fr_CA.mo fr_CA.po
 /usr/bin/msgfmt -o fr_FR.mo fr_FR.po
 /usr/bin/msgfmt -o ga.mo ga.po
 /usr/bin/msgfmt -o gl.mo gl.po
 /usr/bin/msgfmt -o hi.mo hi.po
 /usr/bin/msgfmt -o hr.mo hr.po
 /usr/bin/msgfmt -o hu.mo hu.po
 /usr/bin/msgfmt -o hy.mo hy.po
 /usr/bin/msgfmt -o is.mo is.po
 /usr/bin/msgfmt -o it_IT.mo it_IT.po
 /usr/bin/msgfmt -o ja_JP.mo ja_JP.po
 /usr/bin/msgfmt -o ka.mo ka.po
 /usr/bin/msgfmt -o kk.mo kk.po
 /usr/bin/msgfmt -o ko_KR.mo ko_KR.po
 /usr/bin/msgfmt -o lt.mo lt.po
 /usr/bin/msgfmt -o lv.mo lv.po
 /usr/bin/msgfmt -o mk.mo mk.po
 /usr/bin/msgfmt -o nb.mo nb.po
 /usr/bin/msgfmt -o nl_NL.mo nl_NL.po
 /usr/bin/msgfmt -o pl.mo pl.po
 /usr/bin/msgfmt -o pt_BR.mo pt_BR.po
 /usr/bin/msgfmt -o pt_PT.mo pt_PT.po
 /usr/bin/msgfmt -o ro.mo ro.po
 /usr/bin/msgfmt -o ru_RU.mo ru_RU.po
 /usr/bin/msgfmt -o sk.mo sk.po
 /usr/bin/msgfmt -o sl.mo sl.po
 /usr/bin/msgfmt -o sr.mo sr.po
 /usr/bin/msgfmt -o sv.mo sv.po
 /usr/bin/msgfmt -o tr_TR.mo tr_TR.po
 /usr/bin/msgfmt -o uk.mo uk.po
 /usr/bin/msgfmt -o uz.mo uz.po
 /usr/bin/msgfmt -o zh_CN.mo zh_CN.po
 /usr/bin/msgfmt -o zh_HK.mo zh_HK.po
 /usr/bin/msgfmt -o zh_SG.mo zh_SG.po
 /usr/bin/msgfmt -o zh_TW.mo zh_TW.po
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
 mkdir -p ${D}/usr/share/locale/ar/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/az/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/bg/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/ca/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/cs/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/da/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/de_DE/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/el_GR/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/en/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/en_PH/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/en_US/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/es_ES/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/es_MX/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/et/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/eu/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/fi/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/fr_CA/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/fr_FR/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/ga/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/gl/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/hi/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/hr/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/hu/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/hy/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/is/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/it_IT/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/ja_JP/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/ka/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/kk/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/ko_KR/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/lt/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/lv/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/mk/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/nb/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/nl_NL/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/pl/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/pt_BR/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/pt_PT/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/ro/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/ru_RU/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/sk/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/sl/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/sr/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/sv/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/tr_TR/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/uk/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/uz/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/zh_CN/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/zh_HK/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/zh_SG/LC_MESSAGES/
 mkdir -p ${D}/usr/share/locale/zh_TW/LC_MESSAGES/
 
 cp ar.mo ${D}/usr/share/locale/ar/LC_MESSAGES/sys_string.mo
 cp az.mo ${D}/usr/share/locale/az/LC_MESSAGES/sys_string.mo
 cp bg.mo ${D}/usr/share/locale/bg/LC_MESSAGES/sys_string.mo
 cp ca.mo ${D}/usr/share/locale/ca/LC_MESSAGES/sys_string.mo
 cp cs.mo ${D}/usr/share/locale/cs/LC_MESSAGES/sys_string.mo
 cp da.mo ${D}/usr/share/locale/da/LC_MESSAGES/sys_string.mo
 cp de_DE.mo ${D}/usr/share/locale/de_DE/LC_MESSAGES/sys_string.mo
 cp el_GR.mo ${D}/usr/share/locale/el_GR/LC_MESSAGES/sys_string.mo
 cp en.mo ${D}/usr/share/locale/en/LC_MESSAGES/sys_string.mo
 cp en_PH.mo ${D}/usr/share/locale/en_PH/LC_MESSAGES/sys_string.mo
 cp en_US.mo ${D}/usr/share/locale/en_US/LC_MESSAGES/sys_string.mo
 cp es_ES.mo ${D}/usr/share/locale/es_ES/LC_MESSAGES/sys_string.mo
 cp es_MX.mo ${D}/usr/share/locale/es_MX/LC_MESSAGES/sys_string.mo
 cp et.mo ${D}/usr/share/locale/et/LC_MESSAGES/sys_string.mo
 cp eu.mo ${D}/usr/share/locale/eu/LC_MESSAGES/sys_string.mo
 cp fi.mo ${D}/usr/share/locale/fi/LC_MESSAGES/sys_string.mo
 cp fr_CA.mo ${D}/usr/share/locale/fr_CA/LC_MESSAGES/sys_string.mo
 cp fr_FR.mo ${D}/usr/share/locale/fr_FR/LC_MESSAGES/sys_string.mo
 cp ga.mo ${D}/usr/share/locale/ga/LC_MESSAGES/sys_string.mo
 cp gl.mo ${D}/usr/share/locale/gl/LC_MESSAGES/sys_string.mo
 cp hi.mo ${D}/usr/share/locale/hi/LC_MESSAGES/sys_string.mo
 cp hr.mo ${D}/usr/share/locale/hr/LC_MESSAGES/sys_string.mo
 cp hu.mo ${D}/usr/share/locale/hu/LC_MESSAGES/sys_string.mo
 cp hy.mo ${D}/usr/share/locale/hy/LC_MESSAGES/sys_string.mo
 cp is.mo ${D}/usr/share/locale/is/LC_MESSAGES/sys_string.mo
 cp it_IT.mo ${D}/usr/share/locale/it_IT/LC_MESSAGES/sys_string.mo
 cp ja_JP.mo ${D}/usr/share/locale/ja_JP/LC_MESSAGES/sys_string.mo
 cp ka.mo ${D}/usr/share/locale/ka/LC_MESSAGES/sys_string.mo
 cp kk.mo ${D}/usr/share/locale/kk/LC_MESSAGES/sys_string.mo
 cp ko_KR.mo ${D}/usr/share/locale/ko_KR/LC_MESSAGES/sys_string.mo
 cp lt.mo ${D}/usr/share/locale/lt/LC_MESSAGES/sys_string.mo
 cp lv.mo ${D}/usr/share/locale/lv/LC_MESSAGES/sys_string.mo
 cp mk.mo ${D}/usr/share/locale/mk/LC_MESSAGES/sys_string.mo
 cp nb.mo ${D}/usr/share/locale/nb/LC_MESSAGES/sys_string.mo
 cp nl_NL.mo ${D}/usr/share/locale/nl_NL/LC_MESSAGES/sys_string.mo
 cp pl.mo ${D}/usr/share/locale/pl/LC_MESSAGES/sys_string.mo
 cp pt_BR.mo ${D}/usr/share/locale/pt_BR/LC_MESSAGES/sys_string.mo
 cp pt_PT.mo ${D}/usr/share/locale/pt_PT/LC_MESSAGES/sys_string.mo
 cp ro.mo ${D}/usr/share/locale/ro/LC_MESSAGES/sys_string.mo
 cp ru_RU.mo ${D}/usr/share/locale/ru_RU/LC_MESSAGES/sys_string.mo
 cp sk.mo ${D}/usr/share/locale/sk/LC_MESSAGES/sys_string.mo
 cp sl.mo ${D}/usr/share/locale/sl/LC_MESSAGES/sys_string.mo
 cp sr.mo ${D}/usr/share/locale/sr/LC_MESSAGES/sys_string.mo
 cp sv.mo ${D}/usr/share/locale/sv/LC_MESSAGES/sys_string.mo
 cp tr_TR.mo ${D}/usr/share/locale/tr_TR/LC_MESSAGES/sys_string.mo
 cp uk.mo ${D}/usr/share/locale/uk/LC_MESSAGES/sys_string.mo
 cp uz.mo ${D}/usr/share/locale/uz/LC_MESSAGES/sys_string.mo
 cp zh_CN.mo ${D}/usr/share/locale/zh_CN/LC_MESSAGES/sys_string.mo
 cp zh_HK.mo ${D}/usr/share/locale/zh_HK/LC_MESSAGES/sys_string.mo
 cp zh_SG.mo ${D}/usr/share/locale/zh_SG/LC_MESSAGES/sys_string.mo
 cp zh_TW.mo ${D}/usr/share/locale/zh_TW/LC_MESSAGES/sys_string.mo
 
 
}

PACKAGES = ""
PACKAGES += "sys-string"

sys-string_files = ""
sys-string_files += "sys-string.manifest"
sys-string_files += "/usr/share/locale/*/LC_MESSAGES/*"

FILES_${PN} = "${sys-string_files}"

PKG_sys-string= "sys-string"

require sys-string-0-extraconf.inc
