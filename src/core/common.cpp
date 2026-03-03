#include "common.hpp"

#include <qdatetime.h>

namespace qs {

const QDateTime& Common::launchTime() {
	static const QDateTime time = QDateTime::currentDateTime();
	return time;
}

} // namespace qs
