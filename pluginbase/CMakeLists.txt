set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(DZ_PLUGIN_TGT_NAME dazpluginbase)
set(DZ_PLUGIN_PROJECT_NAME "DazPluginBase")

option(MYOPTIONS "Customizable Options (MYOPTIONS)" OFF)
if(MYOPTIONS)
	add_compile_definitions(MYOPTIONS)
endif()

# if building a plugin and you want the compiled result placed in the Daz Studio ./plugins directory
if(DAZ_STUDIO_EXE_DIR)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DAZ_STUDIO_EXE_DIR}/plugins)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${DAZ_STUDIO_EXE_DIR}/plugins)
endif()

if(WIN32)
	set(OS_SOURCES 
		DazPluginBase.rc
		DazPluginBase.def
	)
elseif(APPLE)	
	set(OS_SOURCES "")
endif()

add_library( ${DZ_PLUGIN_TGT_NAME} SHARED	
	DazPluginBase.cpp
	DazPluginBase.h
	DazPluginBaseDialog.cpp
	DazPluginBaseDialog.h
	pluginmain.cpp
	version.h
	Resources/resources.qrc
	${OS_SOURCES}
)

target_link_libraries(${DZ_PLUGIN_TGT_NAME}
	PRIVATE 
	dzcore
	${DZSDK_QT_CORE_TARGET}
	${DZSDK_QT_GUI_TARGET}
	${DZSDK_QT_SCRIPT_TARGET}
	${DZSDK_QT_NETWORK_TARGET}
)

set_target_properties (${DZ_PLUGIN_TGT_NAME}
	PROPERTIES
	FOLDER ""
	PROJECT_LABEL ${DZ_PLUGIN_PROJECT_NAME}
)