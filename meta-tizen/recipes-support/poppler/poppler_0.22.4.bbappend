DEPENDS = "fontconfig jpeg zlib  cairo tiff lcms"


EXTRA_OECONF = "\
    --enable-xpdf-headers \
    --disable-gtk-test \
    --disable-poppler-qt4 \
    --enable-zlib \
    --disable-gtk-doc \
    --disable-gtk-doc-html \
    --disable-gtk-doc-pdf \
    --disable-gtk-test \
"