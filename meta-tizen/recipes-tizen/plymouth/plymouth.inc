DESCRIPTION = "Graphical Boot Animation and Logger"
HOMEPAGE = "http://freedesktop.org/software/plymouth/releases"
SECTION = "Base/Startup"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libply-splash-core 
PROVIDES += "libply-splash-core"
RPROVIDES_libply-splash-core += "libply-splash-core"

#PROVIDES by plymouth-x11-renderer 
PROVIDES += "plymouth-x11-renderer"
RPROVIDES_plymouth-x11-renderer += "plymouth-x11-renderer"

#PROVIDES by plymouth-theme-fade-in 
PROVIDES += "plymouth-theme-fade-in"
RPROVIDES_plymouth-theme-fade-in += "plymouth-theme-fade-in"

#PROVIDES by libply-splash-graphics 
PROVIDES += "libply-splash-graphics"
RPROVIDES_libply-splash-graphics += "libply-splash-graphics"

#PROVIDES by plymouth-theme-script 
PROVIDES += "plymouth-theme-script"
RPROVIDES_plymouth-theme-script += "plymouth-theme-script"

#PROVIDES by plymouth-docs  
PROVIDES += "plymouth-docs "
RPROVIDES_plymouth-docs  += "plymouth-docs "

#PROVIDES by plymouth-theme-spinfinity 
PROVIDES += "plymouth-theme-spinfinity"
RPROVIDES_plymouth-theme-spinfinity += "plymouth-theme-spinfinity"

#PROVIDES by libply 
PROVIDES += "libply"
RPROVIDES_libply += "libply"

#PROVIDES by plymouth-theme-solar 
PROVIDES += "plymouth-theme-solar"
RPROVIDES_plymouth-theme-solar += "plymouth-theme-solar"

#PROVIDES by plymouth-plugin-label 
PROVIDES += "plymouth-plugin-label"
RPROVIDES_plymouth-plugin-label += "plymouth-plugin-label"

#PROVIDES by plymouth-plugin-fade-throbber 
PROVIDES += "plymouth-plugin-fade-throbber"
RPROVIDES_plymouth-plugin-fade-throbber += "plymouth-plugin-fade-throbber"

#PROVIDES by plymouth 
PROVIDES += "plymouth"
RPROVIDES_plymouth += "plymouth"

#PROVIDES by libply-boot-client 
PROVIDES += "libply-boot-client"
RPROVIDES_libply-boot-client += "libply-boot-client"

#PROVIDES by plymouth-plugin-script 
PROVIDES += "plymouth-plugin-script"
RPROVIDES_plymouth-plugin-script += "plymouth-plugin-script"

#PROVIDES by plymouth-plugin-two-step 
PROVIDES += "plymouth-plugin-two-step"
RPROVIDES_plymouth-plugin-two-step += "plymouth-plugin-two-step"

#PROVIDES by plymouth-theme-spinner 
PROVIDES += "plymouth-theme-spinner"
RPROVIDES_plymouth-theme-spinner += "plymouth-theme-spinner"

#PROVIDES by plymouth-plugin-space-flares 
PROVIDES += "plymouth-plugin-space-flares"
RPROVIDES_plymouth-plugin-space-flares += "plymouth-plugin-space-flares"

#PROVIDES by plymouth-plugin-throbgress 
PROVIDES += "plymouth-plugin-throbgress"
RPROVIDES_plymouth-plugin-throbgress += "plymouth-plugin-throbgress"

#PROVIDES by plymouth-devel 
PROVIDES += "plymouth-devel"
RPROVIDES_plymouth-devel += "plymouth-devel"
RPROVIDES_plymouth-devel += "plymouth-dev"

#PROVIDES by plymouth-scripts 
PROVIDES += "plymouth-scripts"
RPROVIDES_plymouth-scripts += "plymouth-scripts"

RDEPENDS = ""
#RDEPENDS of plymouth-x11-renderer (${PN}-x11-renderer)
RDEPENDS_${PN}-x11-renderer += "plymouth"

#RDEPENDS of plymouth-theme-fade-in (${PN}-theme-fade-in)
RDEPENDS_${PN}-theme-fade-in += "plymouth-scripts"
RDEPENDS_${PN}-theme-fade-in += "plymouth-plugin-label"
RDEPENDS_${PN}-theme-fade-in += "plymouth-plugin-fade-throbber"

#RDEPENDS of plymouth-theme-script (${PN}-theme-script)
RDEPENDS_${PN}-theme-script += "plymouth-plugin-script"
RDEPENDS_${PN}-theme-script += "plymouth-scripts"

#RDEPENDS of plymouth-theme-spinfinity (${PN}-theme-spinfinity)
RDEPENDS_${PN}-theme-spinfinity += "plymouth"
RDEPENDS_${PN}-theme-spinfinity += "plymouth-plugin-throbgress"
RDEPENDS_${PN}-theme-spinfinity += "plymouth-scripts"

#RDEPENDS of libply (libply)
RDEPENDS_libply += "libply-boot-client"

#RDEPENDS of plymouth-theme-solar (${PN}-theme-solar)
RDEPENDS_${PN}-theme-solar += "plymouth-scripts"
RDEPENDS_${PN}-theme-solar += "plymouth-plugin-space-flares"

#RDEPENDS of plymouth-plugin-label (${PN}-plugin-label)
RDEPENDS_${PN}-plugin-label += "libply-splash-core"

#RDEPENDS of plymouth-plugin-fade-throbber (${PN}-plugin-fade-throbber)
RDEPENDS_${PN}-plugin-fade-throbber += "libply-splash-core"
RDEPENDS_${PN}-plugin-fade-throbber += "libply"
RDEPENDS_${PN}-plugin-fade-throbber += "libply-splash-graphics"

#RDEPENDS of plymouth (${PN})
RDEPENDS_${PN} += "systemd"
RDEPENDS_${PN} += "dracut"
RDEPENDS_${PN} += "plymouth-scripts"

#RDEPENDS of plymouth-plugin-script (${PN}-plugin-script)
RDEPENDS_${PN}-plugin-script += "libply-splash-core"
RDEPENDS_${PN}-plugin-script += "libply"
RDEPENDS_${PN}-plugin-script += "libply-splash-graphics"

#RDEPENDS of plymouth-plugin-two-step (${PN}-plugin-two-step)
RDEPENDS_${PN}-plugin-two-step += "libply-splash-core"
RDEPENDS_${PN}-plugin-two-step += "libply"
RDEPENDS_${PN}-plugin-two-step += "plymouth-plugin-label"
RDEPENDS_${PN}-plugin-two-step += "libply-splash-graphics"

#RDEPENDS of plymouth-theme-spinner (${PN}-theme-spinner)
RDEPENDS_${PN}-theme-spinner += "plymouth-scripts"
RDEPENDS_${PN}-theme-spinner += "plymouth-plugin-two-step"

#RDEPENDS of plymouth-plugin-space-flares (${PN}-plugin-space-flares)
RDEPENDS_${PN}-plugin-space-flares += "libply-splash-core"
RDEPENDS_${PN}-plugin-space-flares += "libply"
RDEPENDS_${PN}-plugin-space-flares += "libply-splash-graphics"
RDEPENDS_${PN}-plugin-space-flares += "plymouth-plugin-label"

#RDEPENDS of plymouth-plugin-throbgress (${PN}-plugin-throbgress)
RDEPENDS_${PN}-plugin-throbgress += "libply-splash-core"
RDEPENDS_${PN}-plugin-throbgress += "libply"
RDEPENDS_${PN}-plugin-throbgress += "libply-splash-graphics"
RDEPENDS_${PN}-plugin-throbgress += "plymouth-plugin-label"

#RDEPENDS of plymouth-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "plymouth-x11-renderer"
RDEPENDS_${PN}-devel += "libply-splash-core"
RDEPENDS_${PN}-devel += "libply-splash-graphics"
RDEPENDS_${PN}-devel += "libply"
RDEPENDS_${PN}-devel += "pkgconfig"
RDEPENDS_${PN}-devel += "plymouth"
RDEPENDS_${PN}-devel += "libply-boot-client"

#RDEPENDS of plymouth-scripts (${PN}-scripts)
RDEPENDS_${PN}-scripts += "gzip"
RDEPENDS_${PN}-scripts += "coreutils"
RDEPENDS_${PN}-scripts += "plymouth"
RDEPENDS_${PN}-scripts += "cpio"
RDEPENDS_${PN}-scripts += "findutils"


DEPENDS = ""
#DEPENDS of libply-splash-graphics 
#DEPENDS of plymouth-plugin-label 
#DEPENDS of plymouth 
DEPENDS += "pkgconfig(pango)"
DEPENDS += "pkgconfig(libdrm_intel)"
DEPENDS += "pkgconfig(libkms)"
DEPENDS += "pkgconfig(libdrm)"
DEPENDS += "pkgconfig(cairo)"
DEPENDS += "automake-native"
DEPENDS += "xz"
DEPENDS += "pkgconfig(systemd)"
DEPENDS += "libtool-cross"
DEPENDS += "libpng"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/plymouth.manifest .
 
 # replace builddate with patch0date
 sed -i "s/__DATE__/\"$(stat -c %y ${S}/packaging//plymouth.changes)\"/" src/main.c
 
 # Change the default theme
 sed -i -e 's/fade-in/tizen/g' src/plymouthd.defaults
 
 
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
 
 autoreconf -fiv
 
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
         --infodir=/usr/share/info --disable-static                                      \
 	   --disable-gtk \
            --enable-systemd-integration                          \
            --enable-tracing --disable-tests                      \
            --with-background-start-color-stop=0x1A3D1F           \
            --with-background-end-color-stop=0x4EA65C             \
            --with-background-color=0x3391cd                      \
            --disable-gdm-transition                              \
            --without-system-root-install                         \
            --without-rhgb-compat-link                            \
            --with-boot-tty=/dev/tty7                             \
            --with-shutdown-tty=/dev/tty1                         \
            --without-gdm-autostart-file                          \
            --with-release-file=/etc/os-release
 
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
 rm -f ${D}//usr/bin/rhgb-client
 #rm -f ${D}/usr/libexec/plymouth/plymouth-generate-initrd
 #rm -f ${D}/usr/libexec/plymouth/plymouth-populate-initrd
 
 # Glow isn't quite ready for primetime
 rm -rf ${D}/usr/share/plymouth/glow/
 rm -rf ${D}/usr/share/plymouth/themes/glow/
 rm -f ${D}/usr/lib/plymouth/glow.so
 #mv ${D}/lib/systemd ${D}//usr/lib
 
 mkdir -p ${D}/var/lib/plymouth
 mkdir -p ${D}/var/run/plymouth
 cp $RPM_SOURCE_DIR/boot-duration ${D}/usr/share/plymouth/default-boot-duration
 cp $RPM_SOURCE_DIR/boot-duration ${D}/var/lib/plymouth
 cp ${D}//usr/share/plymouth/plymouthd.defaults ${D}//etc/plymouth/plymouth.conf
 
 
}

PACKAGES = ""
PACKAGES += "libply-splash-core"
PACKAGES += "plymouth-x11-renderer"
PACKAGES += "plymouth-scripts"
PACKAGES += "libply-splash-graphics"
PACKAGES += "plymouth-theme-script"
PACKAGES += "plymouth-theme-fade-in"
PACKAGES += "plymouth-theme-spinfinity"
PACKAGES += "libply"
PACKAGES += "plymouth-theme-solar"
PACKAGES += "plymouth-plugin-label"
PACKAGES += "plymouth-plugin-fade-throbber"
PACKAGES += "plymouth"
PACKAGES += "libply-boot-client"
PACKAGES += "plymouth-plugin-script"
PACKAGES += "plymouth-plugin-two-step"
PACKAGES += "plymouth-theme-spinner"
PACKAGES += "plymouth-docs"
PACKAGES += "plymouth-plugin-throbgress"
PACKAGES += "plymouth-devel"
PACKAGES += "plymouth-plugin-space-flares"

libply-splash-core_files = ""
libply-splash-core_files += "plymouth.manifest"
libply-splash-core_files += "/usr/lib/libply-splash-core.so.2*"

plymouth-x11-renderer_files = ""
plymouth-x11-renderer_files += "plymouth.manifest"

plymouth-scripts_files = ""
plymouth-scripts_files += "plymouth.manifest"
plymouth-scripts_files += "/usr/libexec/plymouth"
plymouth-scripts_files += "/usr/sbin/plymouth-set-default-theme"
plymouth-scripts_files += "/usr/libexec/plymouth/plymouth-update-initrd"

libply-splash-graphics_files = ""
libply-splash-graphics_files += "plymouth.manifest"
libply-splash-graphics_files += "/usr/lib/libply-splash-graphics.so.2*"

plymouth-theme-script_files = ""
plymouth-theme-script_files += "plymouth.manifest"
plymouth-theme-script_files += "/usr/share/plymouth/themes/script/"
plymouth-theme-script_files += "/usr/share/plymouth/themes/script/*.png"
plymouth-theme-script_files += "/usr/share/plymouth/themes/script/script.script"
plymouth-theme-script_files += "/usr/share/plymouth/themes/script/script.plymouth"

plymouth-theme-fade-in_files = ""
plymouth-theme-fade-in_files += "plymouth.manifest"
plymouth-theme-fade-in_files += "/usr/share/plymouth/themes/fade-in"
plymouth-theme-fade-in_files += "/usr/share/plymouth/themes/fade-in/bullet.png"
plymouth-theme-fade-in_files += "/usr/share/plymouth/themes/fade-in/entry.png"
plymouth-theme-fade-in_files += "/usr/share/plymouth/themes/fade-in/lock.png"
plymouth-theme-fade-in_files += "/usr/share/plymouth/themes/fade-in/star.png"
plymouth-theme-fade-in_files += "/usr/share/plymouth/themes/fade-in/fade-in.plymouth"

plymouth-theme-spinfinity_files = ""
plymouth-theme-spinfinity_files += "plymouth.manifest"
plymouth-theme-spinfinity_files += "/usr/share/plymouth/themes/spinfinity"
plymouth-theme-spinfinity_files += "/usr/share/plymouth/themes/spinfinity/box.png"
plymouth-theme-spinfinity_files += "/usr/share/plymouth/themes/spinfinity/bullet.png"
plymouth-theme-spinfinity_files += "/usr/share/plymouth/themes/spinfinity/entry.png"
plymouth-theme-spinfinity_files += "/usr/share/plymouth/themes/spinfinity/lock.png"
plymouth-theme-spinfinity_files += "/usr/share/plymouth/themes/spinfinity/throbber-[0-3][0-9].png"
plymouth-theme-spinfinity_files += "/usr/share/plymouth/themes/spinfinity/spinfinity.plymouth"

libply_files = ""
libply_files += "plymouth.manifest"
libply_files += "/usr/lib/libply.so.2*"

plymouth-theme-solar_files = ""
plymouth-theme-solar_files += "plymouth.manifest"
plymouth-theme-solar_files += "/usr/share/plymouth/themes/solar"
plymouth-theme-solar_files += "/usr/share/plymouth/themes/solar/*.png"
plymouth-theme-solar_files += "/usr/share/plymouth/themes/solar/solar.plymouth"

plymouth-plugin-label_files = ""
plymouth-plugin-label_files += "plymouth.manifest"
plymouth-plugin-label_files += "/usr/lib/plymouth/label.so"

plymouth-plugin-fade-throbber_files = ""
plymouth-plugin-fade-throbber_files += "plymouth.manifest"
plymouth-plugin-fade-throbber_files += "/usr/lib/plymouth/fade-throbber.so"

plymouth_files = ""
plymouth_files += "plymouth.manifest"
plymouth_files += "/usr/libexec/plymouth/*"
plymouth_files += "/usr/share/plymouth"
plymouth_files += "/usr/share/plymouth/themes"
plymouth_files += "/usr/share/plymouth/themes/details"
plymouth_files += "/usr/share/plymouth/themes/text"
plymouth_files += "/var/lib/plymouth"
plymouth_files += "/usr/lib/plymouth"
plymouth_files += "/usr/lib/plymouth/renderers"
plymouth_files += "/etc/plymouth"
plymouth_files += "/etc/plymouth/plymouthd.conf"
plymouth_files += "/etc/plymouth/plymouth.conf"
plymouth_files += "/usr/sbin/plymouthd"
plymouth_files += "/usr/bin/plymouth"
plymouth_files += "/usr/lib/plymouth/details.so"
plymouth_files += "/usr/lib/plymouth/text.so"
plymouth_files += "/usr/lib/plymouth/renderers/drm*"
plymouth_files += "/usr/lib/plymouth/renderers/frame-buffer*"
plymouth_files += "/usr/share/plymouth/default-boot-duration"
plymouth_files += "/usr/share/plymouth/themes/details/details.plymouth"
plymouth_files += "/usr/share/plymouth/themes/text/text.plymouth"
plymouth_files += "/usr/share/plymouth/plymouthd.defaults"
plymouth_files += "/usr/share/plymouth/bizcom.png"
plymouth_files += "/var/spool/plymouth"
plymouth_files += "/lib/systemd/system/*"

libply-boot-client_files = ""
libply-boot-client_files += "plymouth.manifest"
libply-boot-client_files += "/usr/lib/libply-boot-client.so.2*"

plymouth-plugin-script_files = ""
plymouth-plugin-script_files += "plymouth.manifest"
plymouth-plugin-script_files += "/usr/lib/plymouth/script.so"

plymouth-plugin-two-step_files = ""
plymouth-plugin-two-step_files += "plymouth.manifest"
plymouth-plugin-two-step_files += "/usr/lib/plymouth/two-step.so"

plymouth-theme-spinner_files = ""
plymouth-theme-spinner_files += "plymouth.manifest"
plymouth-theme-spinner_files += "/usr/share/plymouth/themes/spinner"
plymouth-theme-spinner_files += "/usr/share/plymouth/themes/spinner/*.*"

plymouth-docs_files = ""
plymouth-docs_files += "/usr/share/info"
plymouth-docs_files += "/usr/share/man"

plymouth-plugin-throbgress_files = ""
plymouth-plugin-throbgress_files += "plymouth.manifest"
plymouth-plugin-throbgress_files += "/usr/lib/plymouth/throbgress.so"

plymouth-devel_files = ""
plymouth-devel_files += "plymouth.manifest"
plymouth-devel_files += "/usr/lib/libply.so"
plymouth-devel_files += "/usr/lib/libply-splash-core.so"
plymouth-devel_files += "/usr/lib/libply-boot-client.so"
plymouth-devel_files += "/usr/lib/libply-splash-graphics.so"
plymouth-devel_files += "/usr/lib/pkgconfig/ply-splash-core.pc"
plymouth-devel_files += "/usr/lib/pkgconfig/ply-splash-graphics.pc"
plymouth-devel_files += "/usr/lib/pkgconfig/ply-boot-client.pc"
plymouth-devel_files += "/usr/include/plymouth-1"

plymouth-plugin-space-flares_files = ""
plymouth-plugin-space-flares_files += "plymouth.manifest"
plymouth-plugin-space-flares_files += "/usr/lib/plymouth/space-flares.so"

FILES_libply-splash-core = "${libply-splash-core_files}"
FILES_${PN}-x11-renderer = "${plymouth-x11-renderer_files}"
FILES_${PN}-scripts = "${plymouth-scripts_files}"
FILES_libply-splash-graphics = "${libply-splash-graphics_files}"
FILES_${PN}-theme-script = "${plymouth-theme-script_files}"
FILES_${PN}-theme-fade-in = "${plymouth-theme-fade-in_files}"
FILES_${PN}-theme-spinfinity = "${plymouth-theme-spinfinity_files}"
FILES_libply = "${libply_files}"
FILES_${PN}-theme-solar = "${plymouth-theme-solar_files}"
FILES_${PN}-plugin-label = "${plymouth-plugin-label_files}"
FILES_${PN}-plugin-fade-throbber = "${plymouth-plugin-fade-throbber_files}"
FILES_${PN} = "${plymouth_files}"
FILES_libply-boot-client = "${libply-boot-client_files}"
FILES_${PN}-plugin-script = "${plymouth-plugin-script_files}"
FILES_${PN}-plugin-two-step = "${plymouth-plugin-two-step_files}"
FILES_${PN}-theme-spinner = "${plymouth-theme-spinner_files}"
FILES_${PN}-docs = "${plymouth-docs_files}"
FILES_${PN}-plugin-throbgress = "${plymouth-plugin-throbgress_files}"
FILES_${PN}-devel = "${plymouth-devel_files}"
FILES_${PN}-plugin-space-flares = "${plymouth-plugin-space-flares_files}"

PKG_libply-splash-core= "libply-splash-core"
PKG_plymouth-x11-renderer= "plymouth-x11-renderer"
PKG_plymouth-scripts= "plymouth-scripts"
PKG_libply-splash-graphics= "libply-splash-graphics"
PKG_plymouth-theme-script= "plymouth-theme-script"
PKG_plymouth-theme-fade-in= "plymouth-theme-fade-in"
PKG_plymouth-theme-spinfinity= "plymouth-theme-spinfinity"
PKG_libply= "libply"
PKG_plymouth-theme-solar= "plymouth-theme-solar"
PKG_plymouth-plugin-label= "plymouth-plugin-label"
PKG_plymouth-plugin-fade-throbber= "plymouth-plugin-fade-throbber"
PKG_plymouth= "plymouth"
PKG_libply-boot-client= "libply-boot-client"
PKG_plymouth-plugin-script= "plymouth-plugin-script"
PKG_plymouth-plugin-two-step= "plymouth-plugin-two-step"
PKG_plymouth-theme-spinner= "plymouth-theme-spinner"
PKG_plymouth-docs= "plymouth-docs"
PKG_plymouth-plugin-throbgress= "plymouth-plugin-throbgress"
PKG_plymouth-devel= "plymouth-devel"
PKG_plymouth-plugin-space-flares= "plymouth-plugin-space-flares"

require plymouth-extraconf.inc
