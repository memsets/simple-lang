#include "parser.h"

Parser::Parser(QVector<Token> tokens) : tokens(tokens)
{
    this->pos = 0;
    this->size = tokens.size();
}

std::shared_ptr<Statement> Parser::statement()
{
    return assignmentStatement();
}

std::shared_ptr<Statement> Parser::assignmentStatement()
{
    if (peek(0).getType() == TokenType::WORD && peek(1).getType() == TokenType::EQ) {
        QString name = peek(0).getText();
        match(TokenType::WORD);
        match(TokenType::EQ);
        return std::make_shared<AssignmentStatement>(AssignmentStatement(name, expression()));
    }
    qFatal("Unknown statement");
}

std::shared_ptr<Expression> Parser::expression()
{
    return additive();
}

std::shared_ptr<Expression> Parser::additive()
{
    auto expr = multiplicative();

    while (true) {
        if (match(TokenType::PLUS)) {
            expr = std::make_shared<BinaryExpression>(BinaryExpression(TokenType::PLUS, expr,
                                                                       multiplicative()));
            continue;
        } else if (match(TokenType::MINUS)) {
            expr = std::make_shared<BinaryExpression>(BinaryExpression(TokenType::MINUS, expr,
                                                                       multiplicative()));
            continue;
        }
        break;
    }
    return expr;
}

std::shared_ptr<Expression> Parser::multiplicative()
{
    auto expr = unary();

    while (true) {
        if (match(TokenType::STAR)) {
            expr = std::make_shared<BinaryExpression>(BinaryExpression(TokenType::STAR, expr, unary()));
            continue;
        } else if (match(TokenType::SLASH)) {
            expr = std::make_shared<BinaryExpression>(BinaryExpression(TokenType::SLASH, expr, unary()));
            continue;
        } else if (match(TokenType::PER)) {
            expr = std::make_shared<BinaryExpression>(BinaryExpression(TokenType::PER, expr, unary()));
            continue;
        }
        break;
    }
    return expr;
}

std::shared_ptr<Expression> Parser::unary()
{
    if (match(TokenType::MINUS)) {
        return std::make_shared<UnaryExpression>(UnaryExpression(TokenType::MINUS, primary()));
    } else if (match(TokenType::PLUS)) {
        return std::make_shared<UnaryExpression>(UnaryExpression(TokenType::PLUS, primary()));
    }
    return primary();
}

std::shared_ptr<Expression> Parser::primary()
{
    Token current = peek(0);
    if (match(TokenType::NUM)) {
        return std::make_shared<NumberExpression>(NumberExpression(current.getText().toDouble()));
    } else if (match(TokenType::LPAREN)) {
        std::shared_ptr<Expression> expr = expression();
        match(TokenType::RPAREN);
        return expr;
    } else if (match(TokenType::WORD)) {
        return std::make_shared<VariableExpression>(VariableExpression(current.getText()));
    } else {
        qFatal("Unknown token");
    }
}

Token Parser::peek(const int relativePosition) const
{
    const int position = relativePosition + pos;
    if (position >= size) {
        return Token(TokenType::END, "");
    }
    return tokens[position];
}

bool Parser::match(TokenType type)
{
    const Token current = peek(0);
    if (current.getType() == type) {
        pos++;
        return true;
    }
    return false;
}
