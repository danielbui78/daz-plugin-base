#pragma once
#include <dzaction.h>
#include <dznode.h>
#include <DzFileIOSettings.h>

#include "QtCore/qfile.h"
#include "QtCore/qtextstream.h"

class DazPluginBase : public DzAction {
	 Q_OBJECT
public:

	 DazPluginBase(const QString& text = QString::null, const QString& desc = QString::null);
	 virtual ~DazPluginBase();

protected:
	void executeAction();

//	 virtual QString getActionGroup() const { return tr("PluginBase"); }
	 virtual QString getDefaultMenuPath() const { return tr("&Plugin Menu"); }

};
