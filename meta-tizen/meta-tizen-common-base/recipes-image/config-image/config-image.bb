SUMMARY = "Config image"
DESCRIPTION = "This Config image"
SECTION = "config"
PR = "r1"
LICENSE = "MIT"
LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

RDEPENDS_${PN} += "weston"
RDEPENDS_${PN} += "media-server"
RDEPENDS_${PN} += "wrt-widgets"
RDEPENDS_${PN} += "avsystem"
RDEPENDS_${PN} += "download-provider"

do_install() {
  mkdir -p ${D}${sysconfdir}
  echo "Tizen on Yocto" > ${D}${sysconfdir}/tizen
  
  touch ${D}${sysconfdir}/environment
  chmod 0644 ${D}${sysconfdir}/environment
  
  mkdir -p ${D}${sysconfdir}/profile.d
cat >${D}${sysconfdir}/profile.d/bash_prompt_custom.sh <<'EOF'
    # set a fancy prompt (overwrite the one in /etc/profile)
    default="\[\e[0m\]"
    usercol='\[\e[1;34m\]' # blue
    hostcol='\[\e[1;32m\]' # green
    pathcol='\[\e[1;33m\]' # yellow
    gitcol='\[\e[1;31m\]' # light red
    termcmd=''
    _p="$";

    if [ "`id -u`" -eq 0 ]; then
        usercol='\[\e[1;31m\]'
        _p="#"
    fi

    PS1="${usercol}\u${default}@${hostcol}\h${default}:${pathcol}\w${default}${gitcol}${default}${_p} ${termcmd}"

    alias ll="ls -lZ"
    alias lr="ls -ltrZ"
    alias la="ls -alZ"

EOF
  
}

pkg_postinst_${PN} () {
  chsmack -t $D${sysconfdir}
  chsmack -a 'System::Shared' $D${sysconfdir}
  
  mkdir -p $D${localstatedir}/volatile/log
  mkdir -p $D${localstatedir}/volatile/tmp
  
  chsmack -t $D${localstatedir}/volatile/log
  chsmack -a 'System::Log'  $D${localstatedir}/volatile/log

  touch $D${localstatedir}/volatile/log/lastlog
  touch $D${localstatedir}/volatile/log/faillog
  touch $D${localstatedir}/volatile/log/wtmp
  touch $D${localstatedir}/volatile/log/btmp
  
  mkdir -p $D${sysconfdir}/profile.d
  
  if [ "x$D" != "x" ]; then  
    cp -fra $D${localstatedir}/log $D${localstatedir}/volatile
    #cp -fra $D/sbin $D/usr
    #cp -fra $D/bin  $D/usr
  
    #rm -fr $D/lib
    #rm -fr $D/sbin
    #rm -fr $D/bin
    rm -fr $D${localstatedir}/log
    
    #ln -s usr/lib  $D/lib
    #ln -s usr/sbin $D/sbin
    #ln -s usr/bin  $D/bin
    ln -s volatile/log  $D${localstatedir}/log
    
 fi
}

FILES_${PN} = "${sysconfdir}/tizen \
               ${sysconfdir}/environment \
               ${sysconfdir}/profile.d/bash_prompt_custom.sh \
               "
