#pragma once
#include <qmenu.h>
#include <qpoint.h>

#include "../../core/export.h"

namespace qs::menu::platform {

class QS_API PlatformMenuQMenu: public QMenu {
public:
	explicit PlatformMenuQMenu() = default;
	~PlatformMenuQMenu() override;
	Q_DISABLE_COPY_MOVE(PlatformMenuQMenu);

	void setVisible(bool visible) override;

	PlatformMenuQMenu* containingMenu = nullptr;
	QPoint targetPosition;
};

} // namespace qs::menu::platform
