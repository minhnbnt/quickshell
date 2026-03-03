qt_add_library(quickshell SHARED
	plugin.cpp
	shell.cpp
	variants.cpp
	rootwrapper.cpp
	reload.cpp
	qmlglobal.cpp
	qmlscreen.cpp
	region.cpp
	persistentprops.cpp
	singleton.cpp
	generation.cpp
	scan.cpp
	scanenv.cpp
	qsintercept.cpp
	incubator.cpp
	lazyloader.cpp
	easingcurve.cpp
	iconimageprovider.cpp
	imageprovider.cpp
	transformwatcher.cpp
	boundcomponent.cpp
	model.cpp
	elapsedtimer.cpp
	desktopentry.cpp
	desktopentrymonitor.cpp
	platformmenu.cpp
	qsmenu.cpp
	retainable.cpp
	popupanchor.cpp
	types.cpp
	qsmenuanchor.cpp
	clock.cpp
	logging.cpp
	paths.cpp
	instanceinfo.cpp
	common.cpp
	iconprovider.cpp
	scriptmodel.cpp
	colorquantizer.cpp
	toolsupport.cpp
)

qt_add_qml_module(quickshell
	URI Quickshell
	VERSION 0.1
	DEPENDENCIES QtQuick
	OPTIONAL_IMPORTS Quickshell._Window
	DEFAULT_IMPORTS Quickshell._Window
	NO_GENERATE_PLUGIN_SOURCE
)

target_sources(quickshellplugin PRIVATE qmlplugin.cpp)

install_qml_module(quickshell)

target_link_libraries(quickshell PRIVATE Qt::Quick Qt::QuickPrivate Qt::Widgets quickshell-build)

qs_pch(quickshell SET large)

#target_link_libraries(quickshell PRIVATE quickshell-coreplugin)

if (BUILD_TESTING)
	add_subdirectory(test)
endif()
