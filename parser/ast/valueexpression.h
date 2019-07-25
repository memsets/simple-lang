#ifndef NUMBEREXPRESSION_H
#define NUMBEREXPRESSION_H

#include <QChar>
#include <memory>

#include "expression.h"
#include "../lib/value.h"

class ValueExpression : public Expression
{
    std::shared_ptr<Value> value;
public:
    ValueExpression(std::shared_ptr<Value> value);
    ValueExpression();
    std::shared_ptr<Value> eval() override;
};

#endif // NUMBEREXPRESSION_H