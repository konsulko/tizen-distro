DESCRIPTION = "Executes Actions at ACPI Events"
HOMEPAGE = "http://tedfelix.com/linux/acpid-netlink.html"
SECTION = "System/Daemons"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by acpid 
PROVIDES += "acpid"
RPROVIDES_acpid += "acpid"

#PROVIDES by acpid-docs  
PROVIDES += "acpid-docs "
RPROVIDES_acpid-docs  += "acpid-docs "

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of acpid 
DEPENDS += "systemd"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/acpid.manifest .
 
 cp ${S}/packaging/thinkpad_acpi.modprobe ${S}/packaging/events.power_button ${S}/packaging/thinkpad_handler ${S}/packaging/power_button ${S}/packaging/events.thinkpad .
 
 
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
 
 export LDFLAGS="-Wl,-z,relro,-z,now"
 
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
         --infodir=/usr/share/info 
 make OPT="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR=${D} SBINDIR=/usr/sbin
 install -Dm 644 thinkpad_acpi.modprobe ${D}/etc/modprobe.d/50-thinkpad_acpi.conf
 install -Dm 744 thinkpad_handler ${D}/usr/lib/acpid/thinkpad_handler
 install -Dm 744 power_button ${D}/usr/lib/acpid/power_button
 install -Dm 644 events.power_button ${D}/etc/acpi/events/power_button
 install -Dm 644 events.thinkpad ${D}/etc/acpi/events/thinkpad
 mkdir -p ${D}//lib/systemd/system
 install -m 644 ${S}/packaging/acpid.service ${D}//lib/systemd/system
 
 # keep the logfile
 install -dm 755 ${D}/var/log
 touch ${D}/var/log/acpid
 
 
 
 
}

PACKAGES = ""
PACKAGES += "acpid"
PACKAGES += "acpid-docs"

acpid_files = ""
acpid_files += "acpid.manifest"
acpid_files += "/etc/modprobe.d"
acpid_files += "/etc/acpi"
acpid_files += "/etc/acpi/events"
acpid_files += "/etc/acpi/events/thinkpad"
acpid_files += "/etc/acpi/events/power_button"
acpid_files += "/usr/lib/acpid"
acpid_files += "/etc/modprobe.d/50-thinkpad_acpi.conf"
acpid_files += "/lib/systemd/system/acpid.service"
acpid_files += "/usr/sbin/kacpimon"
acpid_files += "/usr/sbin/acpid"
acpid_files += "/usr/bin/acpi_listen"

acpid-docs_files = ""
acpid-docs_files += "/usr/share/info"
acpid-docs_files += "/usr/share/man"

FILES_${PN} = "${acpid_files}"
FILES_${PN}-docs = "${acpid-docs_files}"

PKG_acpid= "acpid"
PKG_acpid-docs= "acpid-docs"

require acpid-extraconf.inc
