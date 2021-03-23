#ifndef ARRAYSTATEMENT_H
#define ARRAYSTATEMENT_H

#include <QString>
#include <QVector>
#include <memory>
#include <typeinfo>
#include <iostream>

#include "../../entities/variablecontainer.h"
#include "expression.h"
#include "../../entities/arrayvalue.h"
#include "statement.h"

class ArrayStatement : public Statement
{
    QString name;
    QVector<std::shared_ptr<Expression>> indices;
    std::shared_ptr<Expression> value;
public:
    ArrayStatement(const QString &name, QVector<std::shared_ptr<Expression>> indices,
                   std::shared_ptr<Expression> value);
    ArrayStatement();
    void exec() override;
    std::shared_ptr<Expression> getValue() const;
    void setValue(const std::shared_ptr<Expression> &value);
    QVector<std::shared_ptr<Expression> > getIndices() const;
    void setIndices(const QVector<std::shared_ptr<Expression> > &value);
    QString getName() const;
    void setName(const QString &value);
};

#endif // ARRAYSTATEMENT_H
