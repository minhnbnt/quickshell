#include "plugin.hpp"

#include <iostream>

#include <QtCore/qtsymbolmacros.h>
#include <QtQml/qqmlextensionplugin.h>

QT_DECLARE_EXTERN_SYMBOL_VOID(qml_register_types_Quickshell)

class QuickshellPlugin: public QQmlEngineExtensionPlugin {
	Q_OBJECT
	Q_PLUGIN_METADATA(IID QQmlEngineExtensionInterface_iid)

public:
	QuickshellPlugin(QObject* parent = nullptr): QQmlEngineExtensionPlugin(parent) {
		QT_KEEP_SYMBOL(qml_register_types_Quickshell)

		static bool initialized = false;
		if (!initialized) {
			initialized = true;
			std::cout << "[QuickshellPlugin] Running QsEnginePlugin::initPlugins()" << std::endl;
			QsEnginePlugin::initPlugins();
		}
	}
};

#include "qmlplugin.moc"