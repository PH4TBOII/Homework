CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
SOURCES += main.cpp \
    Component.cpp \
    Input.cpp \
    Output.cpp \
    NotGate.cpp \
    ChainableComponent.cpp \
    TwoInputGate.cpp


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
    Component.h \
    Input.h \
    Output.h \
    NotGate.h \
    ChainableComponent.h \
    TwoInputGate.h


