#include "parser.h"

Parser::Parser(QVector<Token> tokens) : tokens(tokens)
{
    this->pos = 0;
    this->size = tokens.size();
}

Parser::Parser()
{
}

QVector<std::shared_ptr<Statement>> Parser::statement()
{
    QVector<std::shared_ptr<Statement>> statements;

    while (!match(TokenType::END)) {
        statements.append(blockStatement());
    }
    return statements;
}

std::shared_ptr<Statement> Parser::blockStatement()
{
    auto statements = QVector<std::shared_ptr<Statement>>();
    if (match(TokenType::LBRACE)) {
        while (!match(TokenType::RBRACE)) {
            statements.append(blockStatement());
        }
        return std::make_shared<BlockStatement>(BlockStatement(statements));
    }
    return printStatement();

}

std::shared_ptr<Statement> Parser::printStatement()
{
    if (match(TokenType::PRINT)) {
        return std::make_shared<PrintStatement>(PrintStatement(expression()));
    }
    return assignmentStatement();
}

std::shared_ptr<Statement> Parser::assignmentStatement()
{
    // TODO: Needs refactoring this condition
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
            expr = std::make_shared<BinaryExpression>(
                        BinaryExpression(TokenType::PLUS, expr, multiplicative()));
            continue;
        } else if (match(TokenType::MINUS)) {
            expr = std::make_shared<BinaryExpression>(
                        BinaryExpression(TokenType::MINUS, expr, multiplicative()));
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
            expr = std::make_shared<BinaryExpression>(
                        BinaryExpression(TokenType::STAR, expr, unary()));
            continue;
        } else if (match(TokenType::SLASH)) {
            expr = std::make_shared<BinaryExpression>(
                        BinaryExpression(TokenType::SLASH, expr, unary()));
            continue;
        } else if (match(TokenType::PER)) {
            expr = std::make_shared<BinaryExpression>(
                        BinaryExpression(TokenType::PER, expr, unary()));
            continue;
        }
        break;
    }
    return expr;
}

std::shared_ptr<Expression> Parser::unary()
{
    if (match(TokenType::MINUS)) {
        return std::make_shared<UnaryExpression>(
                    UnaryExpression(TokenType::MINUS, primary()));
    } else if (match(TokenType::PLUS)) {
        return std::make_shared<UnaryExpression>(
                    UnaryExpression(TokenType::PLUS, primary()));
    }
    return primary();
}

std::shared_ptr<Expression> Parser::primary()
{
    Token current = peek(0);
    if (match(TokenType::NUM)) {
        return std::make_shared<ValueExpression>(
                    ValueExpression(std::make_shared<DoubleValue>(current.getText().toDouble())));
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

QVector<Token> Parser::getTokens() const
{
    return tokens;
}

void Parser::setTokens(const QVector<Token> &value)
{
    tokens = value;
}

int Parser::getPos() const
{
    return pos;
}

void Parser::setPos(int value)
{
    pos = value;
}

int Parser::getSize() const
{
    return size;
}

void Parser::setSize(int value)
{
    size = value;
}
