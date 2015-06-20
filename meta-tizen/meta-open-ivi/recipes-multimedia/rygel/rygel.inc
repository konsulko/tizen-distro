DESCRIPTION = "GNOME UPnP/DLNA Media Server"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Applications/Multimedia"
LICENSE = "LGPL-2.0+"
PV = "0_22_0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by rygel


#PROVIDES by rygel-dev
PROVIDES += "rygel-dev"


RDEPENDS = ""
#RDEPENDS of rygel (${PN})
RDEPENDS_${PN} += "coreutils"
RDEPENDS_${PN} += "/usr/bin/pkg_initdb"

#RDEPENDS of rygel-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "rygel"


DEPENDS = ""
#DEPENDS of rygel
DEPENDS += "docbook-xsl-stylesheets"
DEPENDS += "util-linux"
DEPENDS += "gupnp-dlna"
DEPENDS += "gnome-common"
DEPENDS += "gstreamer1.0-plugins-base"
DEPENDS += "gstreamer1.0"
inherit pkgconfig
DEPENDS += "gupnp"
DEPENDS += "libsoup-2.4"
DEPENDS_append_class-native = " intltool-native"
DEPENDS_append_class-target = " intltool-native"
DEPENDS += "libgee"
DEPENDS += "gupnp-av"
DEPENDS += "sqlite3"
DEPENDS += "libxslt"
DEPENDS += "glib-2.0"
DEPENDS += "vala"
DEPENDS += "dbus-glib"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n rygel-0_22_0
 
 # >> setup
 # << setup
 
 
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
  
  # >> build pre
  # << build pre
  NOCONFIGURE=y ./autogen.sh
  
  autotools_do_configure
  
  # >> build post
  # << build post
  
  
}
EXTRA_OECONF += " --disable-static --disable-external-plugin --disable-mpris-plugin --disable-mediathek-plugin --disable-tracker-plugin --disable-gst-launch-plugin --disable-example-plugins --disable-tests --enable-valadoc=no"

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 rm -rf ${D}
 mkdir -p ${D}${prefix}/share/packages/
 install -m 0644 org.tizen.rygel.xml ${D}${prefix}/share/packages/
 
 # >> install pre
 # << install pre
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 # >> install post
 # << install post
 #find_lang rygel
 
 # Systemd service file
 install -D -m 644 examples/service/systemd/rygel.service.tizen ${D}${systemd_unitdir}/system/rygel.service
 # 
 mkdir -p ${D}/${systemd_unitdir}/system/network.target.wants 
 ln -s ../rygel.service  ${D}/${systemd_unitdir}/system/network.target.wants/rygel.service  
 rm -rf  $RPM_BUILD_ROOT${prefix}/share/applications/*.desktop
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
    /bin/touch --no-create $D${prefix}/share/icons/hicolor || :
    $D${prefix}/bin/gtk-update-icon-cache \
      --quiet $D${prefix}/share/icons/hicolor 2> /dev/null|| :
    /usr/bin/pkg_initdb
    # systemctl daemon-reload
    # systemctl restart rygel.service

}

pkg_prerm_${PN}() {
    #!/bin/sh -e

    systemctl stop rygel.service

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
    /bin/touch --no-create $D${prefix}/share/icons/hicolor || :
    $D${prefix}/bin/gtk-update-icon-cache \
      --quiet $D${prefix}/share/icons/hicolor 2> /dev/null|| :
    systemctl daemon-reload

}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " rygel "
PACKAGES += " rygel-dev "

rygel_files = ""
rygel_files += "/etc/rygel.conf"
rygel_files += "${systemd_unitdir}/system/rygel.service"
rygel_files += "${systemd_unitdir}/system/network.target.wants/rygel.service"
rygel_files += "${prefix}/bin/rygel"
rygel_files += "${prefix}/share/dbus-1/services/org.gnome.Rygel1.service"
rygel_files += "${prefix}/share/icons/hicolor/128x128/apps/rygel.png"
rygel_files += "${prefix}/share/icons/hicolor/48x48/apps/rygel.png"
rygel_files += "${prefix}/share/icons/hicolor/32x32/apps/rygel.png"
rygel_files += "${prefix}/share/icons/hicolor/scalable/apps/rygel-full.svg"
rygel_files += "${prefix}/share/icons/hicolor/scalable/apps/rygel.svg"
rygel_files += "${prefix}/share/rygel/icons/120x120/rygel.jpg"
rygel_files += "${prefix}/share/rygel/icons/120x120/rygel.png"
rygel_files += "${prefix}/share/rygel/icons/48x48/rygel.jpg"
rygel_files += "${prefix}/share/rygel/icons/48x48/rygel.png"
rygel_files += "${prefix}/share/rygel/presets/GstFaac.prs"
rygel_files += "${prefix}/share/rygel/presets/GstLameMP3Enc.prs"
rygel_files += "${prefix}/share/rygel/presets/GstMP4Mux.prs"
rygel_files += "${prefix}/share/rygel/presets/GstTwoLame.prs"
rygel_files += "${prefix}/share/rygel/presets/GstX264Enc.prs"
rygel_files += "${prefix}/share/rygel/presets/avenc_aac.prs"
rygel_files += "${prefix}/share/rygel/presets/avenc_mp2.prs"
rygel_files += "${prefix}/share/rygel/presets/avenc_mpeg2video.prs"
rygel_files += "${prefix}/share/rygel/presets/avenc_wmav1.prs"
rygel_files += "${prefix}/share/rygel/presets/avenc_wmv1.prs"
rygel_files += "${prefix}/share/rygel/xml/ContentDirectory-NoTrack.xml"
rygel_files += "${prefix}/share/rygel/xml/AVTransport2.xml"
rygel_files += "${prefix}/share/rygel/xml/BasicManagement2.xml"
rygel_files += "${prefix}/share/rygel/xml/ConnectionManager.xml"
rygel_files += "${prefix}/share/rygel/xml/ContentDirectory.xml"
rygel_files += "${prefix}/share/rygel/xml/MediaRenderer2.xml"
rygel_files += "${prefix}/share/rygel/xml/MediaServer3.xml"
rygel_files += "${prefix}/share/rygel/xml/RenderingControl2.xml"
rygel_files += "${prefix}/share/rygel/xml/X_MS_MediaReceiverRegistrar1.xml"
rygel_files += "${prefix}/share/man/man1/rygel.1.gz"
rygel_files += "${prefix}/share/man/man5/rygel.conf.5.gz"
rygel_files += "${prefix}/share/packages/org.tizen.rygel.xml"
rygel_files += "${prefix}/lib/librygel-*.so.*"
rygel_files += "${prefix}/lib/rygel-2.2/plugins/*.so"
rygel_files += "${prefix}/lib/rygel-2.2/plugins/*.plugin"
rygel_files += "${prefix}/lib/rygel-2.2/engines/*.so"
rygel_files += "${prefix}/lib/rygel-2.2/engines/*.plugin"
CONFFILES_${PN} = ""
CONFFILES_${PN} += "/etc/rygel.conf"

rygel-dev_files = ""
rygel-dev_files += "${prefix}/include/rygel-2.2/*"
rygel-dev_files += "${prefix}/lib/*.so"
rygel-dev_files += "${prefix}/lib/pkgconfig/rygel-*-2.2.pc"
rygel-dev_files += "${prefix}/share/vala/vapi/rygel-*-2.2.deps"
rygel-dev_files += "${prefix}/share/vala/vapi/rygel-*-2.2.vapi"

FILES_${PN} = "${rygel_files}"
FILES_${PN}-dev = "${rygel-dev_files}"

PKG_rygel= "rygel"
PKG_rygel-dev= "rygel-dev"

require rygel-extraconf.inc

