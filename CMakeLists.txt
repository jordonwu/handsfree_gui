cmake_minimum_required(VERSION 2.8.3)
project(handsfree_gui)
find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Gui)
find_package(Qt5PrintSupport)
find_package(Qt5SerialPort)
find_package(Boost COMPONENTS REQUIRED system thread)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(EXECUTABLE_OUTPUT_PATH  "${PROJECT_SOURCE_DIR}/bin")


set(handsfree_gui_SRCS
    main_widget/main.cpp
    main_widget/main_widget.cpp
    util/widget/availablecommand_list.cpp
    util/widget/switch_button.cpp
    util/widget/round_pushbutton.cpp
    util/widget/button_listwidgetitem.cpp
    util/sliding/slide_pushbutton.cpp
    util/sliding/sliding_moudle.cpp
    util/sliding/sliding_stackedwidget.cpp

    visualization_widget/plot_widget.cpp
    visualization_widget/visualization_widget.cpp

    about_widget/about_widget.cpp
	
    information_widget/radar_pos.cpp
    information_widget/information_widget.cpp

    serial_widget/serial_combobox.cpp
    serial_widget/serial_widget.cpp
#    serial_widget/transport_serial.cpp

    control_widget/control_widget.cpp
    control_widget/joystick.cpp
    param_widget/param_widget.cpp

    robot/robot_hardware.cpp
    robot/robot_commands.cpp
    robot/read_thread.cpp
#    robot/information/param_moterspeed.cpp
#    robot/information/param_robotspeed.cpp
#    robot/information/param_systeminfo.cpp
#    robot/information/param_globalspeed.cpp
#    robot/information/param_robotcoordinate.cpp
#    robot/information/param_globalcoordinate.cpp

#    robot/command/motorparameters_command.cpp
#    robot/command/globalspeed_command.cpp
#    robot/command/headstate_command.cpp
#    robot/command/armstate_command.cpp
#    robot/command/motorspeed_command.cpp
#    robot/command/robotspeed_command.cpp
)

set(handsfree_gui_moc_HDRS

)

set(handsfree_gui_HDRS
    main_widget/main_widget.h
    util/sliding/slide_pushbutton.h
    util/sliding/sliding_moudle.h
    util/sliding/sliding_stackedwidget.h
    util/widget/availablecommand_list.h
    util/widget/switch_button.h
    util/widget/round_pushbutton.h
    util/widget/button_listwidgetitem.h
    util/factory/linefactory.h
    util/factory/treeitem_factory.h
    util/csv/csv.h

    visualization_widget/plot_widget.h
    visualization_widget/visualization_widget.h

    about_widget/about_widget.h
	
    information_widget/radar_pos.h
    information_widget/information_widget.h

#    serial_widget/transport_serial.h
    serial_widget/serial_combobox.h
    serial_widget/serial_widget.h

    control_widget/joystick.h
    control_widget/control_widget.h

    param_widget/param_widget.h

    robot/robot_hardware.h
    robot/expect_list.h
    robot/measure_list.h
    robot/command.h
    robot/robot_commands.h
    robot/command_factory.h
    robot/read_thread.h

    robot/measure/measure_moterspeed.h
    robot/measure/measure_robotspeed.h
    robot/measure/measure_systeminfo.h
    robot/measure/measure_globalspeed.h
    robot/measure/measure_robotcoordinate.h
    robot/measure/measure_globalcoordinate.h

    robot/expect/expect_motorparameter.h
    robot/expect/expect_motorspeed.h
    robot/expect/expect_robotspeed.h
    robot/expect/expect_globalspeed.h
    robot/expect/expect_headstate.h
    robot/expect/expect_armstate.h
)

set(handsfree_gui_UIS
    main_widget/ui/main_widget.ui
    util/ui/slide_pushbutton.ui
    util/ui/availablecommand_list.ui
    util/ui/button_listwidgetitem.ui
    about_widget/ui/about_widget.ui
    serial_widget/ui/serial_widget.ui
    control_widget/ui/control_widget.ui
    param_widget/ui/param_widget.ui
    visualization_widget/ui/visualization_widget.ui
    information_widget/ui/information_widget.ui
)

set(handsfree_gui_RCC
    res/res.qrc 
    res/qss.qrc
)
link_directories(.)
INCLUDE_DIRECTORIES(
	sdk/
        sdk/handsfree_sdk/
        ${QT_INCLUDE_DIR}
	${BOOST_INCLUDE_DIR}
)


QT5_ADD_RESOURCES(handsfree_RESOURCES_CPP ${handsfree_gui_RCC})
QT5_WRAP_CPP(handsfree_MOCS ${handsfree_gui_moc_HDRS})
QT5_WRAP_UI(handsfree_UIS_H ${handsfree_gui_UIS})

ADD_EXECUTABLE(handsfree_gui ${handsfree_gui_SRCS} ${handsfree_UIS_H} ${handsfree_MOCS}
                                                ${handsfree_RESOURCES_CPP} ${handsfree_gui_HDRS})
target_link_libraries(handsfree_gui handsfree_qt_sdk qcustomplot Qt5::SerialPort Qt5::Core Qt5::Gui Qt5::Widgets Qt5::PrintSupport
                                                        ${Boost_LIBRARIES})


