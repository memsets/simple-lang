#ifndef ARRAYEXPRESSION_H
#define ARRAYEXPRESSION_H

#include <QString>
#include <QVector>
#include <memory>
#include <typeinfo>

#include "../../entities/variablecontainer.h"
#include "expression.h"
#include "../../entities/arrayvalue.h"

class ArrayExpression : public Expression
{
    QString name;
    QVector<std::shared_ptr<Expression>> indices;
public:
    ArrayExpression(const QString &name, QVector<std::shared_ptr<Expression>> indices);
    std::shared_ptr<Value> eval() override;
    QString getName() const;
    void setName(const QString &value);
    QVector<std::shared_ptr<Expression> > getIndices() const;
    void setIndices(const QVector<std::shared_ptr<Expression> > &value);
};

#endif // ARRAYEXPRESSION_H
