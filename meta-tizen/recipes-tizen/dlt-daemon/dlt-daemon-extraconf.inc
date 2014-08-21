inherit pkgconfig cmake

EXTRA_OECMAKE += " -DWITH_SYSTEMD=ON \
                    -DWITH_SYSTEMD_JOURNAL=ON \
                    -DWITH_MAN=OFF \
                    -DWITH_DLT_EXAMPLES=OFF "
