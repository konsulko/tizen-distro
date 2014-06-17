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
