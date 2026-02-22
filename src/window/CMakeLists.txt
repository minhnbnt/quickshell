qt_add_library(quickshell-window SHARED
	proxywindow.cpp
	windowinterface.cpp
	panelinterface.cpp
	floatingwindow.cpp
	popupwindow.cpp
	menu/popupanchor.cpp
	menu/platformmenu.cpp
	menu/qsmenu.cpp
	menu/qsmenuanchor.cpp
)

target_link_libraries(quickshell-window PRIVATE quickshell-core)
target_include_directories(quickshell-window PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/menu)

set(IMPORTS)
set(DEFAULT_IMPORTS)

# # TODO
# if (X11)
# 	list(APPEND IMPORTS Quickshell._X11Overlay)
# 	list(APPEND DEFAULT_IMPORTS Quickshell.X11)
# endif()

if (WAYLAND)
	list(APPEND IMPORTS Quickshell._WaylandOverlay)
	list(APPEND DEFAULT_IMPORTS Quickshell.Wayland)
endif()

qt_add_qml_module(quickshell-window
	URI Quickshell._Window
	VERSION 0.1
	DEPENDENCIES QtQuick
)

target_link_libraries(quickshell-windowplugin PRIVATE quickshell)

qs_add_module_deps_light(quickshell-window Quickshell)

install_qml_module(quickshell-window)

add_library(quickshell-window-init OBJECT init.cpp)

target_link_libraries(quickshell-window PRIVATE
	Qt::Core Qt::Gui Qt::Quick Qt6::QuickPrivate Qt::Widgets
)

qs_add_link_dependencies(quickshell-window quickshell-debug)

target_link_libraries(quickshell-window-init PRIVATE Qt::Qml)

qs_pch(quickshell-window SET large)

target_link_libraries(quickshell PRIVATE quickshell-window quickshell-window-init)

if (BUILD_TESTING)
	add_subdirectory(test)
endif()
