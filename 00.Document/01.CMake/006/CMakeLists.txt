ke_minimum_required (VERSION 2.6)

project(prog7)

find_package(Qt4 REQUIRED)

QT4_WRAP_CPP(prog7_h_moc ${prog7.h})
QT4_WRAP_UI(prog7_ui_h prog1.ui)
QT4_ADD_RESOURCES(prog7_rcc prog7.qrc)

include(${QT_USE_FILE})

add_executable(prog7 prog7.cc)
# add_executable(prog7 prog7.cc ${prog7_h_moc} ${prog7_ui_h} ${prog7_rcc})

include_directories(${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(prog7 ${QT_LIBRARIES})

