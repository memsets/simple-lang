#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QFile>

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

    QFile file("/home/sanicko/cpp-proj/lang/program.sl");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qFatal("Could not open the file");

    QTextStream in(&file);
    QString source = in.readAll();

    Lexer lex(source);

    QVector<Token> tokens = lex.tokenize();
    Parser parser(tokens);

    parser.statement()->exec();
//    qInfo() << parser.expression()->eval();
    qInfo() << VariableContainer::get("hello");

    a.exit(0);
}
