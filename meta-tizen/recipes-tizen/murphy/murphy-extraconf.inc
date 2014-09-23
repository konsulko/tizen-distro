EXTRA_OECONF = " \
                --with-dynamic-plugins=domain-control,system-controller,ivi-resource-manager,resource-asm \
                --enable-gpl \
                --enable-pulse \
                --enable-glib \
                --disable-qt \
                --enable-libdbus \
                --enable-telephony \
                --enable-websockets \
                --enable-smack \
                --disable-system-controller \
                --enable-system-monitor \
                "

systemd_unitdir = "/usr/lib/systemd"
                
do_configure_append() {
    ./bootstrap
    autotools_do_configure
}

do_compile() {
    cd ${S}
    LANG=C
    export LANG
    unset DISPLAY
    LD_AS_NEEDED=1; export LD_AS_NEEDED ;

    oe_runmake clean
    oe_runmake
}

do_install_append() {
    # Remove unused directories and files
    rm -rf ${D}${systemd_unitdir}/user
}

FILES_${PN}-dev += "${prefix}/lib/libmurphy-plugin-system-monitor.so"
FILES_${PN}-dev += "${prefix}/include/murphy/resolver/resolver.h"
FILES_${PN}-dev += "${prefix}/include/murphy/core.h"
FILES_${PN}-dev += "${prefix}/include/murphy/config.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common.h"
FILES_${PN}-dev += "${prefix}/include/murphy/domain-control/client.h"
FILES_${PN}-dev += "${prefix}/include/murphy/dbus/dbus-error.h"
FILES_${PN}-dev += "${prefix}/include/murphy/dbus/libdbus.h"
FILES_${PN}-dev += "${prefix}/include/murphy/dbus/dbus-libdbus.h"
FILES_${PN}-dev += "${prefix}/include/murphy/core/domain.h"
FILES_${PN}-dev += "${prefix}/include/murphy/core/method.h"
FILES_${PN}-dev += "${prefix}/include/murphy/core/context.h"
FILES_${PN}-dev += "${prefix}/include/murphy/core/auth.h"
FILES_${PN}-dev += "${prefix}/include/murphy/core/console-command.h"
FILES_${PN}-dev += "${prefix}/include/murphy/core/plugin.h"
FILES_${PN}-dev += "${prefix}/include/murphy/core/console.h"
FILES_${PN}-dev += "${prefix}/include/murphy/core/domain-types.h"
FILES_${PN}-dev += "${prefix}/include/murphy/core/event.h"
FILES_${PN}-dev += "${prefix}/include/murphy/core/scripting.h"
FILES_${PN}-dev += "${prefix}/include/murphy/core/lua-utils/funcbridge.h"
FILES_${PN}-dev += "${prefix}/include/murphy/core/lua-utils/error.h"
FILES_${PN}-dev += "${prefix}/include/murphy/core/lua-utils/lua-utils.h"
FILES_${PN}-dev += "${prefix}/include/murphy/core/lua-utils/include.h"
FILES_${PN}-dev += "${prefix}/include/murphy/core/lua-utils/strarray.h"
FILES_${PN}-dev += "${prefix}/include/murphy/core/lua-utils/object.h"
FILES_${PN}-dev += "${prefix}/include/murphy/core/lua-decision/mdb.h"
FILES_${PN}-dev += "${prefix}/include/murphy/core/lua-decision/element.h"
FILES_${PN}-dev += "${prefix}/include/murphy/core/lua-bindings/murphy.h"
FILES_${PN}-dev += "${prefix}/include/murphy/core/lua-bindings/lua-json.h"
FILES_${PN}-dev += "${prefix}/include/murphy/plugins/resource-native/libmurphy-resource/resource-private.h"
FILES_${PN}-dev += "${prefix}/include/murphy/plugins/resource-native/libmurphy-resource/resource-api.h"
FILES_${PN}-dev += "${prefix}/include/murphy/resource/protocol.h"
FILES_${PN}-dev += "${prefix}/include/murphy/resource/client-api.h"
FILES_${PN}-dev += "${prefix}/include/murphy/resource/config-api.h"
FILES_${PN}-dev += "${prefix}/include/murphy/resource/manager-api.h"
FILES_${PN}-dev += "${prefix}/include/murphy/resource/data-types.h"
FILES_${PN}-dev += "${prefix}/include/murphy/resource/common-api.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/websocklib.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/dbus-error.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/debug-info.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/mainloop.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/libdbus.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/debug.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/dbus-libdbus.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/list.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/fragbuf.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/websocket.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/refcnt.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/native-types.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/env.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/utils.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/macros.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/hashtbl.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/transport.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/mm.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/file-utils.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/json.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/msg.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/tlv.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/log.h"
FILES_${PN}-dev += "${prefix}/include/murphy/common/process.h"

FILES_${PN} += "${prefix}/lib/libmurphy-plugin-system-monitor.so.0"
FILES_${PN} += "${prefix}/lib/libmurphy-plugin-system-monitor.so.0.0.0"
FILES_${PN} += "${prefix}/share/murphy.manifest"
FILES_${PN} += "${prefix}/share/doc/murphy/ChangeLog"
FILES_${PN} += "${prefix}/share/doc/murphy/NEWS"
FILES_${PN} += "${prefix}/share/doc/murphy/CODING-STYLE"
FILES_${PN} += "${prefix}/share/doc/murphy/README"
FILES_${PN} += "${prefix}/share/doc/murphy/AUTHORS"
FILES_${PN} += "${prefix}/share/doc/murphy/INSTALL"
FILES_${PN} += "${prefix}/share/doc/murphy/COPYING"

FILES_${PN}-dbg += "${prefix}/lib/murphy/plugins/.debug/plugin-ivi-resource-manager.so"
FILES_${PN}-dbg += "${prefix}/lib/murphy/plugins/.debug/plugin-domain-control.so"
FILES_${PN}-dbg += "${prefix}/murphy/plugins/.debug/plugin-resource-native.so"
FILES_${PN}-dbg += "${prefix}/lib/murphy/plugins/.debug/plugin-resource-native.so"

FILES_${PN}-glib-dev += "${prefix}/include/murphy/glib/glib-glue.h"

FILES_${PN}-glib += "${prefix}/share/murphy-glib.manifest"

FILES_${PN}-pulse-dev += "${prefix}/include/murphy/pulse/pulse-glue.h"

FILES_${PN}-pulse += "${prefix}/share/murphy-pulse.manifest"

FILES_${PN}-ecore-dev += "${prefix}/include/murphy/ecore/ecore-glue.h"

FILES_${PN}-ecore += "${prefix}/share/murphy-ecore.manifest"

FILES_${PN}-ivi-resource-manager += "${prefix}/share/murphy-ivi-resource-manager.manifest"

FILES_${PN}-tests += "${prefix}/share/murphy-tests.manifest"
