#pragma once

#include <qdatetime.h>
#include <qprocess.h>

#include "export.h"

namespace qs {

struct QS_API Common {
	static const QDateTime LAUNCH_TIME;
	static inline QProcessEnvironment INITIAL_ENVIRONMENT = {}; // NOLINT
};

} // namespace qs
