#pragma once

#include <qicon.h>
#include <qqmlengine.h>
#include <qurl.h>

#include "export.h"

QS_API QIcon getEngineImageAsIcon(QQmlEngine* engine, const QUrl& url);
QS_API QIcon getCurrentEngineImageAsIcon(const QUrl& url);
