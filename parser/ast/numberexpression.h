#ifndef NUMBEREXPRESSION_H
#define NUMBEREXPRESSION_H

#include "expression.h"
#include <QChar>
#include <memory>

class NumberExpression : public Expression
{
    double number;
public:
    NumberExpression(double number);
    NumberExpression();
    double eval() override;
    double getNumber() const;
    void setNumber(double value);
};

#endif // NUMBEREXPRESSION_H
