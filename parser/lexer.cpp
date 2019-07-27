#include "lexer.h"

const QChar Lexer::END = '\0';
const QString Lexer::OPERATOR_CHARS = "+-*/()%={}<>!";

Lexer::Lexer(QString source) : source(source)
{
    this->pos = 0;

    this->operators["+"] = TokenType::PLUS;
    this->operators["-"] = TokenType::MINUS;
    this->operators["*"] = TokenType::STAR;
    this->operators["/"] = TokenType::SLASH;
    this->operators["("] = TokenType::LPAREN;
    this->operators[")"] = TokenType::RPAREN;
    this->operators["%"] = TokenType::PER;
    this->operators["="] = TokenType::EQ;
    this->operators["{"] = TokenType::LBRACE;
    this->operators["}"] = TokenType::RBRACE;
    this->operators["<"] = TokenType::LT;
    this->operators[">"] = TokenType::GT;
    this->operators["=="] = TokenType::EQEQ;
    this->operators["!="] = TokenType::NOTEQ;
    this->operators["<="] = TokenType::LTEQ;
    this->operators[">="] = TokenType::GTEQ;

    this->keywords["print"] = TokenType::PRINT;
    this->keywords["true"] = TokenType::TRUE;
    this->keywords["false"] = TokenType::FALSE;
    this->keywords["and"] = TokenType::AND;
    this->keywords["or"] = TokenType::OR;
}

QVector<Token> Lexer::tokenize()
{
    while (pos < source.size()) {

        QChar current = peek(0);
        if (current.isDigit()) {
            tokenizeNumber();
        } else if (current == '\"') {
            tokenizeText();
        } else if (current == '/' && peek(1) == '/') {
            tokenizeComment();
        } else if (current == '/' && peek(1) == '*') {
            tokenizeMultilineComment();
        } else if (operators.contains(current)) {
            tokenizeOperator();
        } else if (current.isLetter()) {
            tokenizeWord();
        } else {
            next();
        }
    }
    return tokens;
}

void Lexer::tokenizeNumber()
{
    QChar current = peek(0);

    bool pointReceived = false;
    QString buffer;
    while (current.isDigit() || current == '.') {
        if (pointReceived == true && current == '.') {
            qFatal("float number parsing error (not expected point)");
        }
        if (current == '.') {
            pointReceived = true;
        }
        buffer.append(current);
        current = next();
    }
    Token token(TokenType::NUM, buffer);

    tokens.append(token);
}

void Lexer::tokenizeOperator()
{
    QChar current = peek(0);

    QString buffer;
    while (OPERATOR_CHARS.indexOf(current) != -1) {
        buffer.append(current);
        current = next();
    }

    if (operators.values().contains(operators[buffer])) {
        Token token(operators[buffer], buffer);
        tokens.append(token);
    } else {
        qFatal("Unknown operator");
    }
}

void Lexer::tokenizeWord()
{
    QChar current = peek(0);

    QString buffer;

    while (current.isLetter()) {
        buffer.append(current);

        current = next();
    }

    if (keywords.contains(buffer)) {
        Token token(keywords[buffer], "");
        tokens.append(token);
        return;
    } else {
        Token token(TokenType::WORD, buffer);
        tokens.append(token);
    }
}

void Lexer::tokenizeComment()
{
    next(2);
    QChar current = peek(0);

    while (current != '\n') {
        current = next();
    }

}

void Lexer::tokenizeMultilineComment()
{
    next(2);
    QChar current = peek(0);

    while (current != '*' && peek(1) == '/') {
        current = next();
    }
    next(2);
}

void Lexer::tokenizeText()
{
    next();
    QChar current = peek(0);
    QString buffer;
    while (current != '\"') {
        buffer.append(current);
        current = next();
    }
    Token token(TokenType::TEXT, buffer);
    tokens.append(token);
    next();
}

QChar Lexer::peek(const int relativePosition) const
{
    const int position = pos + relativePosition;
    if (position >= source.size()) {
        return END;
    }
    return source[position];
}

QChar Lexer::next(int numOfPositions)
{
    pos += numOfPositions;
    return peek(0);
}
