EXTRA_OECONF = " \
    --cross-prefix=${TARGET_PREFIX} \
    --prefix=${prefix} \
    --ld="${CCLD}" \
    --arch=${TARGET_ARCH} \
    --target-os="linux" \
    --enable-cross-compile \
    --extra-cflags="${TARGET_CFLAGS} ${HOST_CC_ARCH}${TOOLCHAIN_OPTIONS}" \
    --extra-ldflags="${TARGET_LDFLAGS}" \
    --sysroot="${STAGING_DIR_TARGET}" \
    --enable-hardcoded-tables \
    ${EXTRA_FFCONF} \
    --libdir=${libdir} \
    --shlibdir=${libdir} \
"

do_compile() {
    cd ${S}
    LANG=C
    export LANG
    unset DISPLAY
    LD_AS_NEEDED=1; export LD_AS_NEEDED ;


    export CONFIGURE_OPTIONS="\
    --disable-static            --disable-nonfree            --disable-gpl \
    --disable-version3          --disable-devices            --disable-doc \
    --disable-zlib              --disable-network            --disable-avdevice \
    --disable-bsfs              --disable-yasm               --disable-avresample \
    --disable-muxers \
    --disable-filters \
    --enable-filter=buffer      --enable-filter=buffersink  --enable-filter=crop \
    --enable-filter=hflip       --enable-filter=lut         --enable-filter=lutyuv \
    --enable-filter=lutrgb      --enable-filter=overlay     --enable-filter=scale \
    --enable-filter=transpose   --enable-filter=unsharp     --enable-filter=vflip \
    --disable-protocols \
    --enable-protocol=file \
    --disable-parsers \
    --enable-parser=aac         --enable-parser=h264        --enable-parser=mpegaudio \
    --enable-parser=h263        --enable-parser=mpeg4video  --enable-parser=mpegvideo \
    --disable-demuxers \
    --enable-demuxer=aac        --enable-demuxer=h264       --enable-demuxer=mpegts \
    --enable-demuxer=amr        --enable-demuxer=m4v        --enable-demuxer=mpegtsraw \
    --enable-demuxer=asf        --enable-demuxer=mmf        --enable-demuxer=mpegvideo \
    --enable-demuxer=avi        --enable-demuxer=mov        --enable-demuxer=ogg \
    --enable-demuxer=flac       --enable-demuxer=mp3        --enable-demuxer=wav \
    --enable-demuxer=h263       --enable-demuxer=mpegps     --enable-demuxer=matroska \
    --enable-demuxer=dv         --enable-demuxer=flv \
    --disable-decoders \
    --enable-decoder=alac       --enable-decoder=h264       --enable-decoder=wmv1 \
    --enable-decoder=flac       --enable-decoder=mpeg4      --enable-decoder=wmv2 \
    --enable-decoder=h263       --enable-decoder=mpegvideo  --enable-decoder=wmv3 \
    --enable-decoder=vc1        --enable-decoder=flv        --enable-decoder=amrnb \
    --enable-decoder=tiff       --enable-decoder=mp3        --enable-decoder=h263i \
    --enable-decoder=aac        --enable-decoder=theora     --enable-decoder=pcm_mulaw \
    --enable-decoder=pcm_alaw   --enable-decoder=bmp \
    --disable-encoders \
    --enable-encoder=h263       --enable-encoder=h263p      --enable-encoder=mpeg4 \
    --enable-encoder=bmp        --enable-encoder=aac \
    --enable-swscale            --enable-fft                --enable-rdft \
    --enable-mdct               --enable-neon               --enable-shared \
    --enable-pthreads \
    "

    CFLAGS="$CFLAGS -fPIC -DEXPORT_API=\"__attribute__((visibility(\\\"default\\\")))\" "; export CFLAGS

    ./configure --prefix=${prefix} --shlibdir=${prefix}/lib --libdir=${prefix}/lib  $CONFIGURE_OPTIONS ${EXTRA_OECONF}

    oe_runmake -j16
}

do_install() {
    export RPM_BUILD_ROOT=${D}
    cd ${S}
    LANG=C
    export LANG
    unset DISPLAY
    rm -rf ${D}
    mkdir -p ${D}

    oe_runmake \
        DESTDIR=${D} \
        INSTALL_ROOT=${D} \
    install

    rm -f ${D}${infodir}/dir 
    find ${D} -regex ".*\.la$" | xargs rm -f -- 
    find ${D} -regex ".*\.a$" | xargs rm -f --
}


libavtools_files += "${prefix}/share/libvpx-720p.avpreset"
libavtools_files += "${prefix}/share/libx264-lossless_medium.avpreset"
libavtools_files += "${prefix}/share/libx264-slow.avpreset"
libavtools_files += "${prefix}/share/libx264-veryslow_firstpass.avpreset"
libavtools_files += "${prefix}/share/libx264-ultrafast_firstpass.avpreset"
libavtools_files += "${prefix}/share/libx264-lossless_slow.avpreset"
libavtools_files += "${prefix}/share/libx264-superfast_firstpass.avpreset"
libavtools_files += "${prefix}/share/libx264-lossless_ultrafast.avpreset"
libavtools_files += "${prefix}/share/libx264-fast_firstpass.avpreset"
libavtools_files += "${prefix}/share/libx264-lossless_fast.avpreset"
libavtools_files += "${prefix}/share/libx264-slower.avpreset"
libavtools_files += "${prefix}/share/libx264-fast.avpreset"
libavtools_files += "${prefix}/share/libvpx-720p50_60.avpreset"
libavtools_files += "${prefix}/share/libx264-medium.avpreset"
libavtools_files += "${prefix}/share/libx264-faster_firstpass.avpreset"
libavtools_files += "${prefix}/share/libx264-slow_firstpass.avpreset"
libavtools_files += "${prefix}/share/libvpx-1080p.avpreset"
libavtools_files += "${prefix}/share/libx264-faster.avpreset"
libavtools_files += "${prefix}/share/libx264-veryfast_firstpass.avpreset"
libavtools_files += "${prefix}/share/libvpx-1080p50_60.avpreset"
libavtools_files += "${prefix}/share/libx264-lossless_slower.avpreset"
libavtools_files += "${prefix}/share/libx264-veryslow.avpreset"
libavtools_files += "${prefix}/share/libx264-main.avpreset"
libavtools_files += "${prefix}/share/libx264-ultrafast.avpreset"
libavtools_files += "${prefix}/share/libx264-medium_firstpass.avpreset"
libavtools_files += "${prefix}/share/libx264-placebo.avpreset"
libavtools_files += "${prefix}/share/libx264-ipod320.avpreset"
libavtools_files += "${prefix}/share/libx264-baseline.avpreset"
libavtools_files += "${prefix}/share/libx264-ipod640.avpreset"
libavtools_files += "${prefix}/share/libx264-lossless_max.avpreset"
libavtools_files += "${prefix}/share/libx264-slower_firstpass.avpreset"
libavtools_files += "${prefix}/share/libvpx-360p.avpreset"
libavtools_files += "${prefix}/share/libx264-superfast.avpreset"
libavtools_files += "${prefix}/share/libx264-placebo_firstpass.avpreset"
libavtools_files += "${prefix}/share/libx264-veryfast.avpreset"
