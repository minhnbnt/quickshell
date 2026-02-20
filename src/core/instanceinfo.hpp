#pragma once

#include <qdatetime.h>
#include <qlogging.h>
#include <qstring.h>
#include <sys/types.h>

#include "export.h"

struct QS_API InstanceInfo {
	QString instanceId;
	QString configPath;
	QString shellId;
	QDateTime launchTime;
	pid_t pid = -1;
	QString display;

	static InstanceInfo CURRENT; // NOLINT
};

struct QS_API RelaunchInfo {
	InstanceInfo instance;
	bool noColor = false;
	bool timestamp = false;
	bool sparseLogsOnly = false;
	QtMsgType defaultLogLevel = QtWarningMsg;
	QString logRules;
};

QS_API QDataStream& operator<<(QDataStream& stream, const InstanceInfo& info);
QS_API QDataStream& operator>>(QDataStream& stream, InstanceInfo& info);

QS_API QDataStream& operator<<(QDataStream& stream, const RelaunchInfo& info);
QS_API QDataStream& operator>>(QDataStream& stream, RelaunchInfo& info);

namespace qs::crash {

struct QS_API CrashInfo {
	int logFd = -1;

	static CrashInfo INSTANCE; // NOLINT
};

} // namespace qs::crash
