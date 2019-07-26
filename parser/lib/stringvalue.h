#ifndef STRINGVALUE_H
#define STRINGVALUE_H

#include <QString>

#include "value.h"


class StringValue : public Value
{
    QString value;
public:
    StringValue(QString value);
    StringValue();

    double asDouble() override;
    QString asString() override;
    bool asBoolean() override;

    ~StringValue() override;
};

#endif // STRINGVALUE_H
