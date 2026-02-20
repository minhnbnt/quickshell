#pragma once

#include <qcontainerfwd.h>
#include <qdbusargument.h>
#include <qdebug.h>
#include <qlist.h>
#include <qtypes.h>
#include "../../core/export.h"

struct DBusMenuLayout {
	qint32 id = 0;
	QVariantMap properties;
	QList<DBusMenuLayout> children;
};

using DBusMenuIdList = QList<qint32>;

struct DBusMenuItemProperties {
	qint32 id = 0;
	QVariantMap properties;
};

using DBusMenuItemPropertiesList = QList<DBusMenuItemProperties>;

struct DBusMenuItemPropertyNames {
	qint32 id = 0;
	QStringList properties;
};

using DBusMenuItemPropertyNamesList = QList<DBusMenuItemPropertyNames>;

QS_API const QDBusArgument& operator>>(const QDBusArgument& argument, DBusMenuLayout& layout);
QS_API const QDBusArgument& operator<<(QDBusArgument& argument, const DBusMenuLayout& layout);
QS_API const QDBusArgument& operator>>(const QDBusArgument& argument, DBusMenuItemProperties& item);
QS_API const QDBusArgument& operator<<(QDBusArgument& argument, const DBusMenuItemProperties& item);
QS_API const QDBusArgument& operator>>(const QDBusArgument& argument, DBusMenuItemPropertyNames& names);
QS_API const QDBusArgument& operator<<(QDBusArgument& argument, const DBusMenuItemPropertyNames& names);

QS_API QDebug operator<<(QDebug debug, const DBusMenuLayout& layout);
QS_API QDebug operator<<(QDebug debug, const DBusMenuItemProperties& item);
QS_API QDebug operator<<(QDebug debug, const DBusMenuItemPropertyNames& names);

Q_DECLARE_METATYPE(DBusMenuLayout);
Q_DECLARE_METATYPE(DBusMenuIdList);
Q_DECLARE_METATYPE(DBusMenuItemProperties);
Q_DECLARE_METATYPE(DBusMenuItemPropertiesList);
Q_DECLARE_METATYPE(DBusMenuItemPropertyNames);
Q_DECLARE_METATYPE(DBusMenuItemPropertyNamesList);
