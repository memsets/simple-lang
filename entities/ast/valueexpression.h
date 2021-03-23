#ifndef NUMBEREXPRESSION_H
#define NUMBEREXPRESSION_H

#include <QChar>
#include <memory>

#include "expression.h"
#include "../../entities/value.h"

class ValueExpression : public Expression
{
    std::shared_ptr<Value> value;
public:
    ValueExpression(std::shared_ptr<Value> value);
    ValueExpression();
    std::shared_ptr<Value> eval() override;
    std::shared_ptr<Value> getValue() const;
    void setValue(const std::shared_ptr<Value> &value);
};

#endif // NUMBEREXPRESSION_H
