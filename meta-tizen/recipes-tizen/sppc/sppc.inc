DESCRIPTION = "Push services and client library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Application Framwork/Service"
LICENSE = "Flora"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by push 
PROVIDES += "push"
RPROVIDES_push += "push"

#PROVIDES by push-bin 
PROVIDES += "push-bin"
RPROVIDES_push-bin += "push-bin"

#PROVIDES by push-tool 
PROVIDES += "push-tool"
RPROVIDES_push-tool += "push-tool"

#PROVIDES by libpush-devel 
PROVIDES += "libpush-devel"
RPROVIDES_libpush-devel += "libpush-devel"
RPROVIDES_libpush-devel += "libpush-dev"

#PROVIDES by libpush 
PROVIDES += "libpush"
RPROVIDES_libpush += "libpush"
# the PROVIDES rules is ignore "libpush.so.0  "
PROVIDES += "libpush.so.0"
RPROVIDES_libpush += "libpush.so.0"

RDEPENDS = ""
#RDEPENDS of push-bin (push-bin)
RDEPENDS_push-bin += "badge"

#RDEPENDS of push-tool (push-tool)
RDEPENDS_push-tool += "push-bin"
RDEPENDS_push-tool += "libpush"

#RDEPENDS of libpush-devel (libpush-devel)
RDEPENDS_libpush-devel += "capi-appfw-application-dev"
RDEPENDS_libpush-devel += "libpush"


DEPENDS = ""
#DEPENDS of push 
DEPENDS += "pkgconfig(libtzplatform-config)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libpush.manifest ${S}/packaging/libpush-devel.manifest ${S}/packaging/push-bin.manifest ${S}/packaging/push-tool.manifest .
 
 
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
 
 rm -rf ${D}
 
 
 mkdir -p ${D}/usr/bin
 mkdir -p ${D}/usr/lib/pkgconfig
 mkdir -p ${D}/usr/include
 mkdir -p ${D}/usr/share/push
 mkdir -p ${D}/etc/init.d
 mkdir -p ${D}/etc/rc.d/{rc3.d,rc5.d}
 mkdir -p ${D}/usr/lib/systemd/user/tizen-middleware.target.wants
 
 
 #libpush
 cp -a x86/lib/libpush.so.* ${D}/usr/lib
 #libpush-devel
 cp -a x86/include/push.h ${D}/usr/include
 cp -a x86/lib/pkgconfig/push.pc ${D}/usr/lib/pkgconfig/push.pc
 cp -a x86/lib/libpush.so ${D}/usr/lib
 #push-bin
 cp -a x86/bin/pushd ${D}/usr/bin
 cp -a x86/share/push/PushServerTrust.cer ${D}/usr/share/push/PushServerTrust.cer
 cp -a x86/etc/init.d/pushd ${D}/etc/init.d/pushd
 cp -a x86/etc/rc.d/rc3.d/S90pushd ${D}/etc/rc.d/rc3.d/S90pushd
 cp -a x86/etc/rc.d/rc5.d/S90pushd ${D}/etc/rc.d/rc5.d/S90pushd
 cp -a x86/lib/systemd/user/pushd.service ${D}/usr/lib/systemd/user/pushd.service
 cp -a x86/lib/systemd/user/tizen-middleware.target.wants/pushd.service \
     ${D}/usr/lib/systemd/user/tizen-middleware.target.wants/pushd.service
 #push-tool
 cp -a x86/bin/push_tool ${D}/usr/bin
 
 #if [ -f /usr/lib/rpm-plugins/msm.so ]
 #then
 #	chsmack -a "_" -e "_" ${D}/etc/init.d/pushd
 #	chsmack -a "_" -e "_" ${D}/etc/rc.d/rc3.d/S90pushd
 #	chsmack -a "_" -e "_" ${D}/etc/rc.d/rc5.d/S90pushd
 #fi
 
 install -D -m 0750 ${S}/packaging/init_push_DB.sh ${D}/usr/share/push/init_push_DB.sh
 
 
}

PACKAGES = ""
PACKAGES += "push-bin"
PACKAGES += "push-tool"
PACKAGES += "libpush-devel"
PACKAGES += "libpush"

push-bin_files = ""
push-bin_files += "push-bin.manifest"
push-bin_files += "/usr/bin/pushd"
push-bin_files += "/usr/share/push/*.cer"
push-bin_files += "/etc/init.d/pushd"
push-bin_files += "/etc/rc.d/rc3.d/S90pushd"
push-bin_files += "/etc/rc.d/rc5.d/S90pushd"
push-bin_files += "/usr/lib/systemd/user/pushd.service"
push-bin_files += "/usr/lib/systemd/user/tizen-middleware.target.wants/pushd.service"
push-bin_files += "/usr/share/push/init_push_DB.sh"

push-tool_files = ""
push-tool_files += "push-tool.manifest"
push-tool_files += "/usr/bin/push_tool"

libpush-devel_files = ""
libpush-devel_files += "libpush-devel.manifest"
libpush-devel_files += "/usr/lib/pkgconfig/*.pc"
libpush-devel_files += "/usr/lib/libpush.so"

libpush_files = ""
libpush_files += "libpush.manifest"

FILES_${PN}-bin = "${push-bin_files}"
FILES_${PN}-tool = "${push-tool_files}"
FILES_lib${PN}-devel = "${libpush-devel_files}"
FILES_lib${PN} = "${libpush_files}"

PKG_push-bin= "push-bin"
PKG_push-tool= "push-tool"
PKG_libpush-devel= "libpush-devel"
PKG_libpush= "libpush"

require sppc-extraconf.inc
