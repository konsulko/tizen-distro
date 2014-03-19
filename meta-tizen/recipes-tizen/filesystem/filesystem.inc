DESCRIPTION = "The basic directory layout for a Linux system"
HOMEPAGE = "https://fedorahosted.org/filesystem"
SECTION = "Base/Configuration"
LICENSE = "Public Domain"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by filesystem 
PROVIDES += "filesystem"
RPROVIDES_filesystem += "filesystem"

RDEPENDS = ""
#RDEPENDS of filesystem (${PN})
RDEPENDS_${PN} += "setup"


DEPENDS = ""

do_patch() {
 rm -f $RPM_BUILD_DIR/filelist
 
 
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
 
 function create_dir () {
     local MODE=$1
     case "$MODE" in
      \#*) return ;;
     esac
     local OWNR=$2
     local GRUP=$3
     local NAME=$4
     local XTRA=$5
     local BDIR=`dirname $NAME`
     test -d "$RPM_BUILD_ROOT/$NAME" && { echo "dir $NAME does already exist" ; echo "input out of sequence ?" ; exit 1 ; }
     test -n "$BDIR" -a ! -d $RPM_BUILD_ROOT$BDIR && create_dir 0755 root root $BDIR
     mkdir -m $MODE $RPM_BUILD_ROOT/$NAME
     echo "$XTRA%dir %attr($MODE,$OWNR,$GRUP) $NAME" >> $RPM_BUILD_DIR/filelist
 }
 
 cd ${D}
 
 mkdir -p boot dev \
         etc/{X11/{applnk,fontpath.d},xdg/autostart,ld.so.conf.d,opt,pm/{config.d,power.d,sleep.d},xinetd.d,skel,sysconfig,pki} \
         home media mnt opt/home/{app,developer} proc root run/lock srv sys tmp \
         usr/{bin,etc,games,include,lib/{pkgconfig,games,sse2,tls,X11,pm-utils/{module.d,power.d,sleep.d}},lib/{games,locale,modules,sse2},libexec,local/{bin,etc,games,lib,lib,sbin,src,share/{applications,man/man{1,2,3,4,5,6,7,8,9,n,1x,2x,3x,4x,5x,6x,7x,8x,9x},info},libexec,include,},sbin,share/{help/C,aclocal,applications,augeas/lenses,backgrounds,desktop-directories,dict,doc,empty,games,ghostscript/conf.d,gnome,icons,idl,info,man/man{1,2,3,4,5,6,7,8,9,n,1x,2x,3x,4x,5x,6x,7x,8x,9x,0p,1p,3p},mime-info,misc,omf,pixmaps,sounds,themes,xsessions,X11},src,src/kernels,src/debug} \
         var/{adm,empty,gopher,lib/{empty,games,misc,rpm-state},local,lock/subsys,log,nis,preserve,run,spool/{mail,lpd,uucp},tmp,db,cache,opt,games,yp} \
         opt/{dbspace,usr/dbspace} \
         opt/usr/{media,share} \
         usr/apps
 
 ln -snf ../var/tmp usr/tmp
 ln -snf spool/mail var/mail
 ln -snf usr/bin bin
 ln -snf usr/sbin sbin
 ln -snf usr/lib lib
 ln -snf usr/lib lib
 
 # Create the locale directories:
 while read LANG ; do
   echo "%lang(${LANG}) %ghost %config(missingok) /usr/share/locale/${LANG}" >>$RPM_BUILD_DIR/filelist
   create_dir 0755 root root /usr/share/locale/$LANG/LC_MESSAGES
   create_dir 0755 root root /usr/share/help/$LANG
 done < ${S}/packaging/languages
 # Create the locale directories for man:
 while read LANG ; do
   create_dir 0755 root root /usr/share/man/$LANG
   for sec in 1 2 3 4 5 6 7 8 9 n; do
     create_dir 0755 root root /usr/share/man/$LANG/man$sec 
 ##"%lang(${LANG}) %ghost %config(missingok)"
   done
 done < ${S}/packaging/languages.man
 
 
 
}

PACKAGES = ""
PACKAGES += "filesystem"

filesystem_files = ""
#Remove rpm attribut "%attr(555,root,root)"
filesystem_files += ""
filesystem_files += "/bin"
filesystem_files += "/dev"
filesystem_files += "/etc"
filesystem_files += "/etc/X11"
filesystem_files += "/etc/xdg"
filesystem_files += "/etc/opt"
filesystem_files += "/etc/pm"
filesystem_files += "/etc/xinetd.d"
filesystem_files += "/etc/skel"
filesystem_files += "/etc/sysconfig"
filesystem_files += "/etc/pki"
filesystem_files += "/home"
filesystem_files += "/lib"
filesystem_files += "/lib"
filesystem_files += "/media"
filesystem_files += "/mnt"
filesystem_files += "/opt"
#Remove rpm attribut "%attr(755,root,root)"
filesystem_files += "/opt/dbspace"
#Remove rpm attribut "%attr(755,root,root)"
filesystem_files += "/opt/usr"
#Remove rpm attribut "%attr(755,root,app)"
filesystem_files += "/opt/usr/dbspace"
#Remove rpm attribut "%attr(755,app,app)"
filesystem_files += "/opt/usr/media"
#Remove rpm attribut "%attr(755,app,app)"
filesystem_files += "/opt/usr/share"
filesystem_files += "/run"
filesystem_files += "/sbin"
filesystem_files += "/srv"
filesystem_files += "/sys"
filesystem_files += "/usr"
filesystem_files += "/usr/etc"
filesystem_files += "/usr/games"
filesystem_files += "/usr/include"
filesystem_files += "/usr/libexec"
filesystem_files += "/usr/local"
filesystem_files += "/usr/share"
filesystem_files += "/usr/share/aclocal"
filesystem_files += "/usr/share/applications"
filesystem_files += "/usr/share/help/C"
filesystem_files += "/usr/share/augeas"
filesystem_files += "/usr/share/backgrounds"
filesystem_files += "/usr/share/desktop-directories"
filesystem_files += "/usr/share/dict"
filesystem_files += "/usr/share/doc"
filesystem_files += "/usr/share/games"
filesystem_files += "/usr/share/ghostscript"
filesystem_files += "/usr/share/gnome"
filesystem_files += "/usr/share/icons"
filesystem_files += "/usr/share/idl"
filesystem_files += "/usr/share/info"
filesystem_files += "/usr/share/locale"
filesystem_files += "/usr/share/man"
filesystem_files += "/usr/share/mime-info"
filesystem_files += "/usr/share/misc"
filesystem_files += "/usr/share/omf"
filesystem_files += "/usr/share/pixmaps"
filesystem_files += "/usr/share/sounds"
filesystem_files += "/usr/share/themes"
filesystem_files += "/usr/share/xsessions"
filesystem_files += "/usr/share/X11"
filesystem_files += "/usr/src"
filesystem_files += "/usr/tmp"
filesystem_files += "/var"
filesystem_files += "/var/adm"
filesystem_files += "/var/cache"
filesystem_files += "/var/db"
filesystem_files += "/var/empty"
filesystem_files += "/var/games"
filesystem_files += "/var/gopher"
filesystem_files += "/var/lib"
filesystem_files += "/var/local"
filesystem_files += "/var/log"
filesystem_files += "/var/mail"
filesystem_files += "/var/nis"
filesystem_files += "/var/opt"
filesystem_files += "/var/preserve"
filesystem_files += "/var/spool"
filesystem_files += "/var/yp"

FILES_${PN} = "${filesystem_files}"

PKG_filesystem= "filesystem"

require filesystem-extraconf.inc
