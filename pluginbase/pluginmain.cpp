#include "dzplugin.h"
#include "dzapp.h"

#include "version.h"
#include "DazPluginBase.h"

DZ_PLUGIN_DEFINITION("DazPluginBase");

DZ_PLUGIN_AUTHOR("plugin author");

DZ_PLUGIN_VERSION(PLUGIN_MAJOR, PLUGIN_MINOR, PLUGIN_REV, PLUGIN_BUILD);

DZ_PLUGIN_DESCRIPTION(QString(
	"DazPluginBase Documentation"
).arg(dzApp->getDocumentationPath()));

DZ_PLUGIN_CLASS_GUID(DazPluginBase, 0b0dac37-1ac4-4888-9cf6-8c2dde6e65fa);
