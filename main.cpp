#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QFile>

#include "parser/lib/variablecontainer.h"
#include "parser/lexer.h"
#include "parser/parser.h"
#include "parser/lib/doublevalue.h"
#include "parser/lib/functioncontainer.h"
#include "parser/lib/function.h"
#include "parser/sourceloader.h"

#define DEBUG

void init_functions()
{
    FunctionContainer::set("sin", std::make_shared<_native_sin>(_native_sin()));
    FunctionContainer::set("cos", std::make_shared<_native_cos>(_native_cos()));
    FunctionContainer::set("print", std::make_shared<_native_print>(_native_print()));
    FunctionContainer::set("array", std::make_shared<_native_array>(_native_array()));
}

void init_constants()
{
    VariableContainer::set("PI", std::make_shared<DoubleValue>(3.14));
    VariableContainer::set("E", std::make_shared<DoubleValue>(2.7));
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    init_constants();
    init_functions();

    SourceLoader loader("program.sl");
    SourceLoader::setRoot("/home/sanicko/cpp-proj/lang/");
    QString source = loader.loadFromFile();

    Lexer lex(source);

    QVector<Token> tokens = lex.tokenize();
    for (auto &token : tokens) {
        qInfo() << token.getText();
    }
    qInfo() << "===========";

    Parser parser(tokens);


    for (auto &st : parser.statement()) {
        st->exec();
    }
//    qInfo() << parser.expression()->eval();
//    qInfo() << VariableContainer::get("hello");
    a.exit(0);
//    return a.exec();
}
