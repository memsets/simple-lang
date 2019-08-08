#ifndef IMPORTSTATEMENT_H
#define IMPORTSTATEMENT_H

#include <QString>
#include <QVector>
#include <memory>
#include <typeinfo>
#include <iostream>

#include "../lib/variablecontainer.h"
#include "../lib/arrayvalue.h"
#include "../sourceloader.h"
#include "../lexer.h"
#include "expression.h"
#include "statement.h"

class ImportStatement : public Statement
{
    QString importName;
public:
    ImportStatement(const QString &importName);
    void exec() override;
    QString getImportName() const;
    void setImportName(const QString &value);
};

#endif // IMPORTSTATEMENT_H
