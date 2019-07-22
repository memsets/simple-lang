#include <QCoreApplication>
#include <QDebug>
#include <QString>

#include "parser/lib/variablecontainer.h"
#include "parser/lexer.h"
#include "parser/parser.h"

void init_constants()
{
    VariableContainer::set("PI", 3.14);
    VariableContainer::set("E", 2.7);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    init_constants();

    QString source = "2 + 2";
    QString source1 = "hello = 9";

    Lexer lex(source1);

    QVector<Token> tokens = lex.tokenize();
    Parser parser(tokens);

    parser.statement()->exec();
//    qInfo() << parser.expression()->eval();
    qInfo() << VariableContainer::get("hello");
    a.exit(0);
}
