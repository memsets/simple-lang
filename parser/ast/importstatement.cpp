#include "importstatement.h"
#include "../parser.h"

ImportStatement::ImportStatement(const QString &importName) : Statement (),
    importName(importName)
{
}

void ImportStatement::exec()
{
    SourceLoader loader;
    QString source = loader.loadFromFile(importName + ".sl");

    Lexer lexer(source);
    Parser parser(lexer.tokenize());

    for (auto &st : parser.statement()) {
        st->exec();
    }
}

QString ImportStatement::getImportName() const
{
    return importName;
}

void ImportStatement::setImportName(const QString &value)
{
    importName = value;
}
