#pragma once

#include <qfilesystemwatcher.h>
#include <qobject.h>
#include <qqmlengine.h>
#include <qtclasshelpermacros.h>
#include <qtmetamacros.h>
#include <qurl.h>

#include "export.h"
#include "generation.hpp"

class QS_API RootWrapper: public QObject {
	Q_OBJECT;

public:
	explicit RootWrapper(QString rootPath, QString shellId);
	~RootWrapper() override;
	Q_DISABLE_COPY_MOVE(RootWrapper);

	void reloadGraph(bool hard);

private slots:
	void generationDestroyed();
	void updateTooling();

private:
	QString rootPath;
	QString shellId;
	EngineGeneration* generation = nullptr;
	QString originalWorkingDirectory;
	QFileSystemWatcher configDirWatcher;
};
