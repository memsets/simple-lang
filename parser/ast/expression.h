#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <memory>

#include "../lib/value.h"


class Expression
{
public:
    Expression();
    virtual std::shared_ptr<Value> eval() = 0;
    virtual ~Expression();
};

#endif // EXPRESSION_H
