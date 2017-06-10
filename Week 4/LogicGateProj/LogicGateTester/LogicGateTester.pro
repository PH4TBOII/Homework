CONFIG   += console
CONFIG   -= app_bundle

INCLUDEPATH += ..
INCLUDEPATH += ../LogicGates/

TEMPLATE = app
SOURCES += catch.hpp \
    ../LogicGates/ChainableComponent.cpp \
    ../LogicGates/Component.cpp \
    ../LogicGates/Input.cpp \
    ../LogicGates/NotGate.cpp \
    ../LogicGates/Output.cpp \
    ../LogicGates/TwoInputGate.cpp \
    LogicGateTester.cpp
SOURCES += mainTester.cpp
SOURCES +=


QMAKE_CXXFLAGS += -std=c++11
QMAKE_LFLAGS += -std=c++11

QMAKE_CXXFLAGS += -Wmissing-include-dirs
QMAKE_CXXFLAGS += -Wfloat-equal
QMAKE_CXXFLAGS += -Wredundant-decls
QMAKE_CXXFLAGS += -Winit-self
QMAKE_CXXFLAGS += -Wshadow
QMAKE_CXXFLAGS += -Wconversion

# QMAKE_CXXFLAGS += -Werror
# QMAKE_CXXFLAGS += -Wno-error=unused-variable

QMAKE_CXXFLAGS += -pedantic
QMAKE_CXXFLAGS += -pedantic-errors

HEADERS += \
    ../LogicGates/ChainableComponent.h \
    ../LogicGates/Component.h \
    ../LogicGates/Input.h \
    ../LogicGates/NotGate.h \
    ../LogicGates/Output.h \
    ../LogicGates/TwoInputGate.h
