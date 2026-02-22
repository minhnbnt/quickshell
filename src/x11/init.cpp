#include <qguiapplication.h>
#include <qlist.h>
#include <qqml.h>
#include <qstring.h>

#include "../core/plugin.hpp"
#include "panel_window.hpp"
#include "util.hpp"

namespace {

class X11Plugin: public QsEnginePlugin {
public:
	QList<QString> dependencies() override { return {"window"}; }

	bool applies() override { return QGuiApplication::platformName() == "xcb"; }

	void init() override { XAtom::initAtoms(); }

	void registerTypes() override {
		qmlRegisterType<XPanelInterface>("Quickshell._Window", 1, 0, "PanelWindow");
	}
};

QS_REGISTER_PLUGIN(X11Plugin);

} // namespace
