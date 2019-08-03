#ifndef USERFUNCTION_H
#define USERFUNCTION_H

#include <QString>
#include <QVector>
#include <memory>

#include "function.h"
#include "../ast/statement.h"
#include "doublevalue.h"
#include "../ast/returnstatement.h"

class UserFunction : public Function
{
    QVector<QString> argNames;
    std::shared_ptr<Statement> body;
public:
    UserFunction(QVector<QString> argNames, std::shared_ptr<Statement> body);
    std::shared_ptr<Value> exec(QVector<std::shared_ptr<Value>> values) override;
    QVector<QString> getArgNames() const;
    void setArgNames(const QVector<QString> &value);
};

#endif // USERFUNCTION_H
