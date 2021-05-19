#pragma once
#include "dzbasicdialog.h"
#include <QtGui/qcombobox.h>
#include <QtCore/qsettings.h>

class QPushButton;
class QLineEdit;
class QCheckBox;
class QComboBox;
class QGroupBox;

class QLabel;
class QTextEdit;

// TODO: Rename the namespace to avoid conflict with other plugins
namespace DazPluginBase {

	class DazPluginBaseDialog : public DzBasicDialog {
		Q_OBJECT
	public:

		/** Constructor **/
		DazPluginBaseDialog(QWidget* parent);

		/** Destructor **/
		virtual ~DazPluginBaseDialog() {}

		QLabel* sampleLabel;
		QTextEdit* sampleTextArea;
		QPushButton* samplePushButton;

		void Accepted();
	private slots:
		void HandleSamplePushButton();

	private:

	};

}
