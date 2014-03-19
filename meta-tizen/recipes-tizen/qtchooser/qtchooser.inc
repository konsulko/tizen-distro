DESCRIPTION = "Qt Chooser"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Libraries"
LICENSE = "LGPL-2.1+ or GPL-3.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by qtchooser 
PROVIDES += "qtchooser"
RPROVIDES_qtchooser += "qtchooser"

RDEPENDS = ""
#RDEPENDS of qtchooser (${PN})
RDEPENDS_${PN} += "qt-default"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n qtchooser-39.tar.bz2
 
 
 
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
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}/etc/xdg/qtchooser
 mkdir -p ${D}/etc/rpm/
 cp ${S}/packaging/macros.qmake ${D}/etc/rpm/macros.qmake
 
 mkdir -p ${D}/etc/xdg/qtchooser
 
 # Add configuration file for qt5
 echo "/usr/lib/qt5/bin" > ${D}/etc/xdg/qtchooser/5.conf
 echo "/usr/lib" >> ${D}/etc/xdg/qtchooser/5.conf
 
 
 
}

PACKAGES = ""
PACKAGES += "qtchooser"

qtchooser_files = ""
qtchooser_files += "LGPL_EXCEPTION.txt LICENSE.GPL LICENSE.LGPL"
qtchooser_files += "/etc/xdg/qtchooser"
qtchooser_files += "/etc/rpm/macros.qmake"
qtchooser_files += "/etc/xdg/qtchooser/5.conf"
qtchooser_files += "/usr/bin/qtchooser"
qtchooser_files += "/usr/bin/assistant"
qtchooser_files += "/usr/bin/designer"
qtchooser_files += "/usr/bin/lconvert"
qtchooser_files += "/usr/bin/linguist"
qtchooser_files += "/usr/bin/lrelease"
qtchooser_files += "/usr/bin/lupdate"
qtchooser_files += "/usr/bin/moc"
qtchooser_files += "/usr/bin/pixeltool"
qtchooser_files += "/usr/bin/qcollectiongenerator"
qtchooser_files += "/usr/bin/qdbus"
qtchooser_files += "/usr/bin/qdbuscpp2xml"
qtchooser_files += "/usr/bin/qdbusviewer"
qtchooser_files += "/usr/bin/qdbusxml2cpp"
qtchooser_files += "/usr/bin/qdoc"
qtchooser_files += "/usr/bin/qdoc3"
qtchooser_files += "/usr/bin/qglinfo"
qtchooser_files += "/usr/bin/qhelpconverter"
qtchooser_files += "/usr/bin/qhelpgenerator"
qtchooser_files += "/usr/bin/qmake"
qtchooser_files += "/usr/bin/qtpaths"
qtchooser_files += "/usr/bin/qml"
qtchooser_files += "/usr/bin/qml1plugindump"
qtchooser_files += "/usr/bin/qmlbundle"
qtchooser_files += "/usr/bin/qmlmin"
qtchooser_files += "/usr/bin/qmlplugindump"
qtchooser_files += "/usr/bin/qmlprofiler"
qtchooser_files += "/usr/bin/qmlscene"
qtchooser_files += "/usr/bin/qmltestrunner"
qtchooser_files += "/usr/bin/qmlviewer"
qtchooser_files += "/usr/bin/qmlimportscanner"
qtchooser_files += "/usr/bin/qtconfig"
qtchooser_files += "/usr/bin/rcc"
qtchooser_files += "/usr/bin/uic"
qtchooser_files += "/usr/bin/uic3"
qtchooser_files += "/usr/bin/xmlpatterns"
qtchooser_files += "/usr/bin/xmlpatternsvalidator"
qtchooser_files += "/usr/share/man/man1/qtchooser.1.gz"

FILES_${PN} = "${qtchooser_files}"

PKG_qtchooser= "qtchooser"

require qtchooser-extraconf.inc
