QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        parser/ast/assignmentstatement.cpp \
        parser/ast/binaryexpression.cpp \
        parser/ast/expression.cpp \
        parser/ast/numberexpression.cpp \
        parser/ast/statement.cpp \
        parser/ast/unaryexpression.cpp \
        parser/ast/variableexpression.cpp \
        parser/lexer.cpp \
        parser/lib/variablecontainer.cpp \
        parser/parser.cpp \
        parser/token.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    program.sl

HEADERS += \
    parser/ast/assignmentstatement.h \
    parser/ast/binaryexpression.h \
    parser/ast/expression.h \
    parser/ast/numberexpression.h \
    parser/ast/statement.h \
    parser/ast/unaryexpression.h \
    parser/ast/variableexpression.h \
    parser/lexer.h \
    parser/lib/variablecontainer.h \
    parser/parser.h \
    parser/token.h
