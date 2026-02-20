#pragma once

#include <qcontainerfwd.h>
#include <qobject.h>
#include <qtmetamacros.h>

#include "export.h"

namespace qs::scan::env {

class QS_API PreprocEnv: public QObject {
	Q_OBJECT;

public:
	Q_INVOKABLE static bool
	hasVersion(int major, int minor, const QStringList& features = QStringList());
};

} // namespace qs::scan::env
