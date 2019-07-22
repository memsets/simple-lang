#ifndef PARSER_H
#define PARSER_H

#include <QVector>
#include <QString>
#include <QDebug>
#include <memory>

#include "token.h"
#include "ast/expression.h"
#include "ast/binaryexpression.h"
#include "ast/numberexpression.h"
#include "ast/unaryexpression.h"
#include "lib/variablecontainer.h"
#include "ast/variableexpression.h"
#include "ast/statement.h"
#include "ast/assignmentstatement.h"

class Parser
{
    QVector<Token> tokens;
    int pos, size;
public:
    Parser(QVector<Token> tokens);
    Parser();
    std::shared_ptr<Statement> statement();
    std::shared_ptr<Statement> assignmentStatement();
    std::shared_ptr<Expression> expression();
    std::shared_ptr<Expression> additive();
    std::shared_ptr<Expression> multiplicative();
    std::shared_ptr<Expression> unary();
    std::shared_ptr<Expression> primary();
    Token peek(const int relativePosition) const;
    bool match(TokenType type);
    QVector<Token> getTokens() const;
    void setTokens(const QVector<Token> &value);
    int getPos() const;
    void setPos(int value);
    int getSize() const;
    void setSize(int value);
};

#endif // PARSER_H
