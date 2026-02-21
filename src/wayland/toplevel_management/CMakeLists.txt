qt_add_library(quickshell-wayland-toplevel-management SHARED
	manager.cpp
	handle.cpp
	qml.cpp
)

qt_add_qml_module(quickshell-wayland-toplevel-management
	URI Quickshell.Wayland._ToplevelManagement
	VERSION 0.1
	DEPENDENCIES QtQml
)

target_link_libraries(quickshell-wayland-toplevel-managementplugin PRIVATE quickshell)

qs_add_module_deps_light(quickshell-wayland-toplevel-management
	Quickshell Quickshell.Wayland
)

install_qml_module(quickshell-wayland-toplevel-management)

wl_proto(wlp-foreign-toplevel wlr-foreign-toplevel-management-unstable-v1 "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(quickshell-wayland-toplevel-management PRIVATE
	Qt::Quick Qt::WaylandClient Qt::WaylandClientPrivate wayland-client
	wlp-foreign-toplevel
)

qs_pch(quickshell-wayland-toplevel-management SET large)

target_link_libraries(quickshell PRIVATE quickshell-wayland-toplevel-management)
