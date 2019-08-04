#ifndef ARRAYSTATEMENT_H
#define ARRAYSTATEMENT_H

#include <QString>
#include <QVector>
#include <memory>
#include <typeinfo>
#include <iostream>

#include "../lib/variablecontainer.h"
#include "expression.h"
#include "../lib/arrayvalue.h"
#include "statement.h"

class ArrayStatement : public Statement
{
    QString name;
    QVector<std::shared_ptr<Expression>> indices;
    std::shared_ptr<Expression> value;
public:
    ArrayStatement(QString name, QVector<std::shared_ptr<Expression>> indices, std::shared_ptr<Expression> value);
    void exec() override;
};

#endif // ARRAYSTATEMENT_H
