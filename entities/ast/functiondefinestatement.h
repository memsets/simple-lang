#ifndef FUNCTIONDEFINESTATEMENT_H
#define FUNCTIONDEFINESTATEMENT_H

#include <QString>
#include <QVector>

#include "statement.h"
#include "expression.h"
#include "../../entities/functioncontainer.h"
#include "../../entities/userfunction.h"

class FunctionDefineStatement : public Statement
{
    QString name;
    QVector<QString> argNames;
    std::shared_ptr<Statement> body;
public:
    FunctionDefineStatement(const QString &name, const QVector<QString> &argNames,
                            std::shared_ptr<Statement> body);
    FunctionDefineStatement();
    void exec() override;
    QString getName() const;
    void setName(const QString &value);
    QVector<QString> getArgNames() const;
    void setArgNames(const QVector<QString> &value);
    std::shared_ptr<Statement> getBody() const;
    void setBody(const std::shared_ptr<Statement> &value);
};

#endif // FUNCTIONDEFINESTATEMENT_H
