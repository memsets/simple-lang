#include <QCoreApplication>
#include <QDebug>
#include <QString>

#include "parser/lexer.h"
#include "parser/parser.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString source = "2 + 2";
    QString source1 = "(2 + 2) * -2";

    Lexer lex(source1);

    QVector<Token> tokens = lex.tokenize();
    Parser parser(tokens);
    qInfo() << parser.expression()->eval();
    a.exit(0);
}
