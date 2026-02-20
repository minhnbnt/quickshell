#pragma once

#include <qcolor.h>
#include <qmetaobject.h>
#include <qnamespace.h>
#include <qqmlintegration.h>
#include <qtmetamacros.h>

#include "../core/export.h"

class QS_API ClippingRectangleBorder {
	Q_GADGET;
	Q_PROPERTY(QColor color MEMBER color);
	Q_PROPERTY(bool pixelAligned MEMBER pixelAligned);
	Q_PROPERTY(int width MEMBER width);
	QML_VALUE_TYPE(clippingRectangleBorder);

public:
	QColor color = Qt::black;
	bool pixelAligned = true;
	int width = 0;
};
