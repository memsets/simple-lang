#ifndef IMPORTSTATEMENT_H
#define IMPORTSTATEMENT_H

#include <QString>
#include <QVector>
#include <memory>
#include <typeinfo>
#include <iostream>

#include "../../entities/variablecontainer.h"
#include "../../entities/arrayvalue.h"
#include "../../utils/sourceloader.h"
#include "../../parsing/lexer.h"
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
