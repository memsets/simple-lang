#ifndef STATEMENT_H
#define STATEMENT_H

class Statement
{
public:
    Statement();
    virtual ~Statement();
    virtual void exec() = 0;
};

#endif // STATEMENT_H
