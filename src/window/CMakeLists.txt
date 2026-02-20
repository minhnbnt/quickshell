qt_add_library(quickshell-window SHARED
	proxywindow.cpp
	windowinterface.cpp
	panelinterface.cpp
	floatingwindow.cpp
	popupwindow.cpp
)

target_link_libraries(quickshell-window PUBLIC quickshell-core)
target_link_libraries(quickshell-window PUBLIC quickshell-ui)

qt_add_qml_module(quickshell-window
	URI Quickshell._Window
	VERSION 0.1
	DEPENDENCIES QtQuick
	PLUGIN_TYPE DYNAMIC
)

target_link_libraries(quickshell-windowplugin PRIVATE quickshell)

qs_add_module_deps_light(quickshell-window Quickshell)

install_qml_module(quickshell-window)

add_library(quickshell-window-init OBJECT init.cpp)

target_link_libraries(quickshell-window PRIVATE
	Qt::Core Qt::Gui Qt::Quick Qt6::QuickPrivate
)

qs_add_link_dependencies(quickshell-window quickshell-debug)

target_link_libraries(quickshell-window-init PRIVATE Qt::Qml)

qs_pch(quickshell-window SET large)

target_link_libraries(quickshell PRIVATE quickshell-window quickshell-window-init)

if (BUILD_TESTING)
	add_subdirectory(test)
endif()
