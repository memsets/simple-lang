#ifndef VALUE_H
#define VALUE_H

#include <QString>

class Value
{
public:
    virtual double asDouble() = 0;
    virtual QString asString() = 0;
    virtual bool asBoolean() = 0;
    Value();
    virtual ~Value();
};

#endif // VALUE_H
