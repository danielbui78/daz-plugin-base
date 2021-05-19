#include <QtGui/QLayout>
#include <QtGui/QLabel>
#include <QtGui/QGroupBox>
#include <QtGui/QPushButton>
#include <QtGui/QMessageBox>
#include <QtGui/QToolTip>
#include <QtGui/QWhatsThis>
#include <QtGui/qlineedit.h>
#include <QtGui/qboxlayout.h>
#include <QtGui/qfiledialog.h>
#include <QtCore/qsettings.h>
#include <QtGui/qformlayout.h>
#include <QtGui/qcombobox.h>
#include <QtGui/qdesktopservices.h>
#include <QtGui/qcheckbox.h>
#include <QtGui/qlistwidget.h>
#include <QtGui/qgroupbox.h>

#include <QtGui/qtextedit.h>

#include "dzapp.h"
#include "dzscene.h"
#include "dzstyle.h"
#include "dzmainwindow.h"
#include "dzactionmgr.h"
#include "dzaction.h"
#include "dzskeleton.h"

#include "DazPluginBaseDialog.h"

/*****************************
Local definitions
*****************************/
#define DAZ_TO_UNITY_PLUGIN_NAME "DazPluginBase"

// TODO: Rename the namespace to avoid conflict with other plugins
namespace DazPluginBase {

	DazPluginBaseDialog::DazPluginBaseDialog(QWidget* parent) :
		DzBasicDialog(parent, DAZ_TO_UNITY_PLUGIN_NAME)
	{

		// Declarations
		int margin = style()->pixelMetric(DZ_PM_GeneralMargin);
		int wgtHeight = style()->pixelMetric(DZ_PM_ButtonHeight);
		int btnMinWidth = style()->pixelMetric(DZ_PM_ButtonMinWidth);

		// Set the dialog title
		setWindowTitle(tr("DazPluginBase"));

		QFormLayout* mainLayout = new QFormLayout(this);

		// Label
		sampleLabel = new QLabel(this);
		sampleLabel->setText("Label Text goes here.");

		// Sample Subdivision
		QHBoxLayout* subdivisionLayout = new QHBoxLayout(this);
		sampleTextArea = new QTextEdit(this);
		sampleTextArea->setHtml("<b>Sample Text Area Text</b> goes here.</br>");
		sampleTextArea->setMinimumHeight(400);
		subdivisionLayout->addWidget(sampleTextArea);

		// Sample Button
		samplePushButton = new QPushButton("Sample Button", this);
		connect(samplePushButton, SIGNAL(released()), this, SLOT(HandleSamplePushButton()));

		mainLayout->addRow("DazPluginBase", sampleLabel);
		mainLayout->addRow("", subdivisionLayout);
		mainLayout->addRow("", samplePushButton);

		addLayout(mainLayout);

		// Make the dialog fit its contents, with a minimum width, and lock it down
		resize(QSize(500, 0).expandedTo(minimumSizeHint()));
		setFixedWidth(width());
		setFixedHeight(height());

		// Set Defaults
		DzNode* Selection = dzScene->getPrimarySelection();
		if (Selection)
		{
			sampleTextArea->moveCursor(QTextCursor::End);
			sampleTextArea->insertHtml("<br>Current Selection: " + Selection->getName() + "</br>");
		}

	}

	void DazPluginBaseDialog::HandleSamplePushButton()
	{
		sampleTextArea->moveCursor(QTextCursor::End);
		sampleTextArea->insertHtml("<hr></br>More sample text inserted.</br>");
	}

}


#include "moc_DazPluginBaseDialog.cpp"
