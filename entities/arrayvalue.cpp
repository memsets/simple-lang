#include "arrayvalue.h"

ArrayValue::ArrayValue(QVector<std::shared_ptr<Value>> values) : Value(),
    values(values)
{
}

bool ArrayValue::asBoolean()
{
    throw std::runtime_error("Cannot cast array to boolean.");
}

QString ArrayValue::asString()
{
    QString buffer;
    buffer.append("[");
    for (auto &value : values) {
        buffer.append(value->asString());
        buffer.append(", ");
    }
    buffer.append("]");
    return buffer;
}

double ArrayValue::asDouble()
{
    throw std::runtime_error("Cannot cast array to double.");
}

//needs move asDouble pairs to expression
std::shared_ptr<Value> &ArrayValue::index(std::shared_ptr<Value> index)
{
    int i = static_cast<int>(index->asDouble());
    return values[i];
}

void ArrayValue::set(std::shared_ptr<Value> index, std::shared_ptr<Value> value)
{
    values[static_cast<int>(index->asDouble())] = value;
}
