# daz-plugin-base
generic daz plugin base to use as template

This project is based on source code and project files from Daz Studio plugins and SDK.

I use this as a template for making new plugins.  To set up this project, you will need to use CMake 3.4+, Daz SDK and Qt 4.8.1 (64bit DazStudio will require 64bit Qt4 binaries).  Instead of building 64bit Qt4 binaries, I suggest you search the web and download a pre-built Qt4 64bit.

In order to prevent conflicts with other plugins that use this template, do the following:

1. Rename the namespace to avoid conflict with other plugins. Do this in the following files:
- pluginbase\DazPluginBase.cpp
- pluginbase\DazPluginBase.h
- pluginbase\DazPluginBaseDialog.cpp
- pluginbase\DazPluginBaseDialog.h
- pluginbase\pluginmain.cpp

2. Generate new GUID and replace the one in "pluginbase\pluginmain.cpp".  If you don't know how to generate one, just search the web for "Generate GUID".
