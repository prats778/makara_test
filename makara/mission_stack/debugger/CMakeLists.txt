##############################################################################
# CMake
##############################################################################

cmake_minimum_required(VERSION 2.8.3)
project(debugger)
add_definitions(-std=c++11)

##############################################################################
# Catkin
##############################################################################

# qt_build provides the qt cmake glue, roscpp the comms for a default talker
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  genmsg
  qt_build
  roscpp
  roslib
  
)
find_package(OpenCV REQUIRED)

find_package(Qt4 REQUIRED COMPONENTS
  QtCore
  QtGui
)

file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ui/*.ui)
set(QT_MOC 
	include/debugger/mainwindow.h 
        include/debugger/log_tools.h)
SET(QT_SOURCES 
	src/mainwindow.cpp )

QT4_WRAP_UI(QT_FORMS_HPP ${QT_FORMS})
QT4_WRAP_CPP(QT_MOC_HPP ${QT_MOC})

catkin_package(
CATKIN_DEPENDS message_runtime
)

include(
  ${QT_USE_FILE}
)

include_directories(
include
  ${OpenCV_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
  ${QT_INCLUDE_DIRS}
  ${CMAKE_CURRENT_BINARY_DIR}
)

add_library(qt_lib ${QT_SOURCES} ${QT_FORMS_HPP} ${QT_MOC_HPP})
target_link_libraries(qt_lib ${QT_LIBRARIES} ${catkin_LIBRARIES})

add_library(debugger_lib include/debugger/mainwindow.h  src/mainwindow.cpp)
target_link_libraries(debugger_lib qt_lib ${QT_LIBRARIES} ${catkin_LIBRARIES} )

add_executable(debugger src/main.cpp)
target_link_libraries(debugger debugger_lib ${QT_LIBRARIES} ${catkin_LIBRARIES})

#add_library(tub_lib ${QT_SOURCES} ${QT_MOC})#include/tiburon_gui/mainwin.h  src/mainwin.cpp include/tiburon_gui/gate.h  src/gate.cpp)
#target_link_libraries(tub_lib qt_lib ${OpenCV_LIBS})

##############################################################################
# Binaries
##############################################################################
#add_executable(debugger src/main.cpp)
#target_link_libraries(debugger tub_lib ${catkin_LIBRARIES} ${OpenCV_LIBS})
#install(TARGETS debugger RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

#add_executable(debugger ${QT_SOURCES} ${QT_RESOURCES_CPP} ${QT_FORMS_HPP} ${QT_MOC_HPP})
#target_link_libraries(debugger ${QT_LIBRARIES} ${catkin_LIBRARIES})
#install(TARGETS debugger RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

