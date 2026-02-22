qt_add_library(quickshell-core SHARED
	plugin.cpp
	shell.cpp
	variants.cpp
	reload.cpp
	rootwrapper.cpp
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
	retainable.cpp
	processcore.cpp
	types.cpp
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

target_compile_definitions(quickshell-core PRIVATE QS_CORE_LIBRARY)

qt_add_qml_module(quickshell-core
	URI Quickshell
	VERSION 0.1
	DEPENDENCIES QtQuick
	IMPORTS Quickshell._Window
)
target_link_libraries(quickshell-coreplugin PRIVATE quickshell-core)

install_qml_module(quickshell-core)

target_link_libraries(quickshell-core PRIVATE Qt::Quick Qt::QuickPrivate Qt::Widgets quickshell-build)

qs_pch(quickshell-core SET large)

#target_link_libraries(quickshell PRIVATE quickshell-core)

if (BUILD_TESTING)
	add_subdirectory(test)
endif()
