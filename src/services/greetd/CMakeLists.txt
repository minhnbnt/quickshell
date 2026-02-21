qt_add_library(quickshell-service-greetd SHARED
	qml.cpp
	connection.cpp
)

qt_add_qml_module(quickshell-service-greetd
	URI Quickshell.Services.Greetd
	VERSION 0.1
	DEPENDENCIES QtQml
)

target_link_libraries(quickshell-service-greetdplugin PRIVATE quickshell)

install_qml_module(quickshell-service-greetd)

# can't be Qt::Qml because generation.hpp pulls in gui types
target_link_libraries(quickshell-service-greetd PRIVATE Qt::Quick)

qs_pch(quickshell-service-greetd)

target_link_libraries(quickshell PRIVATE quickshell-service-greetd)
