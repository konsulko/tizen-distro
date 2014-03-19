DESCRIPTION = "Secure Shell Client and Server (Remote Login Program)"
HOMEPAGE = "http://www.openssh.com/"
SECTION = "System/Network"
LICENSE = "BSD-3-Clause and MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by openssh 
PROVIDES += "openssh"
RPROVIDES_openssh += "openssh"

RDEPENDS = ""
#RDEPENDS of openssh (${PN})
RDEPENDS_${PN} += "coreutils"
RDEPENDS_${PN} += "pam-modules-extra"
RDEPENDS_${PN} += "/usr/bin/netstat"
RDEPENDS_${PN} += "pwdutils"


DEPENDS = ""
#DEPENDS of openssh 
DEPENDS += "systemd"
DEPENDS += "autoconf-native"
DEPENDS += "pam-devel"
DEPENDS += "openssl-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 cp ${S}/packaging/openssh.manifest .
 
 
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
 PIEFLAGS="-fpie"
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables $PIEFLAGS -fstack-protector"
 export CXXFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables $PIEFLAGS -fstack-protector"
 export LDFLAGS="-pie"
 
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
         --infodir=/usr/share/info \
     --with-ssl-engine \
     --sysconfdir=/etc/ssh \
     --libexecdir=/usr/libexec/ssh \
     --with-pam \
     --with-privsep-path=/var/lib/empty \
     --with-sandbox=rlimit \
     --disable-strip \
     --with-xauth=/usr/bin/xauth \
     --target=x86_64-tizen-linux
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make DESTDIR=${D}/ install
 install -d -m 755 ${D}/etc/pam.d
 install -d -m 755 ${D}/var/lib/sshd
 install -m 644 ${S}/packaging/sshd.pamd ${D}/etc/pam.d/sshd
 # install shell script to automate the process of adding your public key to a remote machine
 install -m 755 contrib/ssh-copy-id ${D}/usr/bin
 install -m 644 contrib/ssh-copy-id.1 ${D}/usr/share/man/man1
 sed -e "s,@LIBEXEC@,/usr/libexec,g" < ${S}/packaging/ssh-askpass > ${D}/usr/libexec/ssh/ssh-askpass
 rm -f ${D}/usr/share/Ssh.bin
 sed -i -e s@/usr/libexec@/usr/libexec@g ${D}/etc/ssh/sshd_config
 
 install -D -m 0755 ${S}/packaging/sshd-gen-keys-start ${D}/usr/sbin/sshd-gen-keys-start
 # systemd
 install -D -m 0644 ${S}/packaging/sshd.service ${D}/lib/systemd/system/sshd.service
 install -D -m 0644 ${S}/packaging/sshd.socket ${D}/lib/systemd/system/sshd.socket
 install -D -m 0644 ${S}/packaging/sshd@.service ${D}/lib/systemd/system/sshd@.service
 
 mkdir -p ${D}//lib/systemd/system/sockets.target.wants
 ln -s ../sshd.socket ${D}//lib/systemd/system/sockets.target.wants/sshd.socket
 
 rm -rf ${D}//usr/share/man/cat*
 rm -rf ${D}//usr/share/man/man*
 
 
 
 
}

PACKAGES = ""
PACKAGES += "openssh"

openssh_files = ""
openssh_files += "openssh.manifest"
#Remove rpm attribut "%attr(755,root,root)"
openssh_files += "/var/lib/sshd"
openssh_files += "/usr/bin/scp"
openssh_files += "/usr/bin/sftp"
openssh_files += "/usr/bin/slogin"
openssh_files += "/usr/bin/ssh-*"
openssh_files += "/usr/sbin/*"
openssh_files += "/usr/sbin/sshd-gen-keys-start"
openssh_files += "/lib/systemd/system/sshd.service"
openssh_files += "/lib/systemd/system/sshd@.service"
openssh_files += "/lib/systemd/system/sockets.target.wants/*.socket"
openssh_files += "/lib/systemd/system/sshd.socket"

FILES_${PN} = "${openssh_files}"

PKG_openssh= "openssh"

require openssh-extraconf.inc
