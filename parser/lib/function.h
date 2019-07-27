#ifndef FUNCTION_H
#define FUNCTION_H

#include <QVector>
#include <memory>

#include "value.h"

class Function
{
public:
    Function();
    virtual std::shared_ptr<Value> exec(QVector<std::shared_ptr<Value>> values) = 0;
    virtual ~Function();
};

#endif // FUNCTION_H
