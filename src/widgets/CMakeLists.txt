qt_add_library(quickshell-widgets STATIC
	cliprect.cpp
	wrapper.cpp
	marginwrapper.cpp
)

qt_add_qml_module(quickshell-widgets
	URI Quickshell.Widgets
	VERSION 0.1
	DEPENDENCIES QtQml
	PLUGIN_TYPE DYNAMIC
	
	QML_FILES
		IconImage.qml
		ClippingRectangle.qml
		WrapperItem.qml
		WrapperMouseArea.qml
		WrapperRectangle.qml
		ClippingWrapperRectangle.qml
		ClippingWrapperRectangleInternal.qml
)

qt6_add_shaders(quickshell-widgets "widgets-cliprect"
	NOHLSL NOMSL BATCHABLE PRECOMPILE OPTIMIZED QUIET
	PREFIX "/Quickshell/Widgets"
	FILES shaders/cliprect.frag
	OUTPUTS shaders/cliprect.frag.qsb
)

qt6_add_shaders(quickshell-widgets "widgets-cliprect-ub"
	NOHLSL NOMSL BATCHABLE PRECOMPILE OPTIMIZED QUIET
	PREFIX "/Quickshell/Widgets"
	FILES shaders/cliprect.frag
	OUTPUTS shaders/cliprect-ub.frag.qsb
	DEFINES CONTENT_UNDER_BORDER
)

target_link_libraries(quickshell-widgetsplugin PRIVATE quickshell)

install_qml_module(quickshell-widgets)

qs_pch(quickshell-widgets)

target_link_libraries(quickshell-widgets PRIVATE Qt::Quick)
target_link_libraries(quickshell PRIVATE quickshell-widgets)
