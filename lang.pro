QT += core gui

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
        entities/ast/arrayexpression.cpp \
        entities/ast/arraystatement.cpp \
        entities/ast/assignmentstatement.cpp \
        entities/ast/binaryexpression.cpp \
        entities/ast/blockstatement.cpp \
        entities/ast/breakstatement.cpp \
        entities/ast/continuestatement.cpp \
        entities/ast/expression.cpp \
        entities/ast/forstatement.cpp \
        entities/ast/functiondefinestatement.cpp \
        entities/ast/functionexpression.cpp \
        entities/ast/functionstatement.cpp \
        entities/ast/ifstatement.cpp \
        entities/ast/importstatement.cpp \
        entities/ast/returnstatement.cpp \
        entities/ast/statement.cpp \
        entities/ast/unaryexpression.cpp \
        entities/ast/valueexpression.cpp \
        entities/ast/variableexpression.cpp \
        entities/ast/whilestatement.cpp \
        parsing/lexer.cpp \
        entities/arrayvalue.cpp \
        entities/booleanvalue.cpp \
        entities/doublevalue.cpp \
        entities/function.cpp \
        entities/functioncontainer.cpp \
        entities/stringvalue.cpp \
        entities/userfunction.cpp \
        entities/value.cpp \
        entities/variablecontainer.cpp \
        parsing/parser.cpp \
        utils/sourceloader.cpp \
        parsing/token.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    lib.sl \
    program.sl

HEADERS += \
    entities/ast/arrayexpression.h \
    entities/ast/arraystatement.h \
    entities/ast/assignmentstatement.h \
    entities/ast/binaryexpression.h \
    entities/ast/blockstatement.h \
    entities/ast/breakstatement.h \
    entities/ast/continuestatement.h \
    entities/ast/expression.h \
    entities/ast/forstatement.h \
    entities/ast/functiondefinestatement.h \
    entities/ast/functionexpression.h \
    entities/ast/functionstatement.h \
    entities/ast/ifstatement.h \
    entities/ast/importstatement.h \
    entities/ast/returnstatement.h \
    entities/ast/statement.h \
    entities/ast/unaryexpression.h \
    entities/ast/valueexpression.h \
    entities/ast/variableexpression.h \
    entities/ast/whilestatement.h \
    parsing/lexer.h \
    entities/arrayvalue.h \
    entities/booleanvalue.h \
    entities/doublevalue.h \
    entities/function.h \
    entities/functioncontainer.h \
    entities/stringvalue.h \
    entities/userfunction.h \
    entities/value.h \
    entities/variablecontainer.h \
    parsing/parser.h \
    utils/sourceloader.h \
    parsing/token.h
