SECTION = "Base/Configuration"

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

# Additional Policy files for PAM from pwdutils
PAM_SRC_URI = "file://pam.d/chage \
               file://pam.d/chfn \
               file://pam.d/chsh \
               file://pam.d/passwd \
               file://pam.d/shadow \
               file://pam.d/useradd \
              "

# Additional Policy files for PAM from util-linux
PAM_SRC_URI += "file://pam.d/login \
                file://pam.d/remote \
                file://pam.d/su \
                file://pam.d/su-l \
               "

do_install_append() {
    # Remove rules that are not present in Tizen Common
    rm -f \
        ${D}${sysconfdir}/pam.d/chgpasswd \
        ${D}${sysconfdir}/pam.d/chpasswd \
        ${D}${sysconfdir}/pam.d/groupadd \
        ${D}${sysconfdir}/pam.d/groupdel \
        ${D}${sysconfdir}/pam.d/groupmems \
        ${D}${sysconfdir}/pam.d/groupmod \
        ${D}${sysconfdir}/pam.d/newusers \
        ${D}${sysconfdir}/pam.d/userdel \
        ${D}${sysconfdir}/pam.d/usermod
}

