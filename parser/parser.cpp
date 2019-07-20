#include "parser.h"

Parser::Parser(QVector<Token> tokens) : tokens(tokens)
{
    this->pos = 0;
    this->size = tokens.size();
}

Expression *Parser::expression()
{
    return additive();
}

Expression *Parser::additive()
{
    Expression *expr = multiplicative();

    while (true) {
        if (match(TokenType::PLUS)) {
            expr = new BinaryExpression(TokenType::PLUS, expr, multiplicative());
            continue;
        } else if (match(TokenType::MINUS)) {
            expr = new BinaryExpression(TokenType::MINUS, expr, multiplicative());
            continue;
        }
        break;
    }
    return expr;
}

Expression *Parser::multiplicative()
{
    Expression *expr = unary();

    while (true) {
        if (match(TokenType::STAR)) {
            expr = new BinaryExpression(TokenType::STAR, expr, unary());
            continue;
        } else if (match(TokenType::SLASH)) {
            expr = new BinaryExpression(TokenType::SLASH, expr, unary());
            continue;
        } else if (match(TokenType::PER)) {
            expr = new BinaryExpression(TokenType::PER, expr, unary());
            continue;
        }
        break;
    }
    return expr;
}

Expression *Parser::unary()
{
    if (match(TokenType::MINUS)) {
        return new UnaryExpression(TokenType::MINUS, primary());
    } else if (match(TokenType::PLUS)) {
        return new UnaryExpression(TokenType::PLUS, primary());
    }
    return primary();
}

Expression *Parser::primary()
{
    Token current = peek(0);
    if (match(TokenType::NUM)) {
        return new NumberExpression(current.getText().toDouble());
    } else if (match(TokenType::LPAREN)) {
        Expression *expr = expression();
        match(TokenType::RPAREN);
        return expr;
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
