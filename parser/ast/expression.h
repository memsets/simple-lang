#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression
{
public:
    Expression();
    virtual double eval() = 0;
    virtual ~Expression();
};

#endif // EXPRESSION_H
