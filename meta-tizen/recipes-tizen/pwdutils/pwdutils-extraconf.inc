
do_configure() {
    autoreconf -v --install --force
    ./configure --disable-ldap --libdir=${prefix}/lib --disable-nls --disable-pam_rpasswd --host=${HOST_SYS}
}

do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;

 make -j16
}

pwdutils_files += "${sysconfdir}/init.d"
pwdutils_files += "${prefix}/bin/passwd"
pwdutils_files += "${prefix}/bin/chsh"
pwdutils_files += "${prefix}/bin/chage"
pwdutils_files += "${prefix}/bin/expiry"
pwdutils_files += "${prefix}/bin/newgrp"
pwdutils_files += "${prefix}/bin/chfn"
pwdutils_files += "${prefix}/bin/gpasswd"
pwdutils_files += "${prefix}/sbin/userdel-post.local"
pwdutils_files += "${prefix}/sbin/useradd.local"
pwdutils_files += "${prefix}/sbin/groupadd.local"
pwdutils_files += "${prefix}/sbin/userdel-pre.local"
