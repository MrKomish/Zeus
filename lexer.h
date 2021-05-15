#pragma once

#include <string>
#include <vector>
#include <memory>
#include <regex>

#include "tokens.h"
#include "utils.h"
#include "keywords.h"

using std::make_unique;
using std::string;

enum class LexingMode {
    Normal,
    IdentifierOrNumber,
    SingleLineComment,
    MultiLineComment
};

struct SourcePosition {
    uint32_t line;
    uint32_t column;
};

class SourceToken {
public:
    SourceToken(std::unique_ptr<Token> token, SourcePosition position, uint32_t length)
            : m_token(std::move(token)), m_position(position), m_length(length) {

    }

    [[nodiscard]] const std::unique_ptr<Token>& value() const {
        return m_token;
    }

    [[nodiscard]] uint32_t length() const {
        return m_length;
    }

    [[nodiscard]] const SourcePosition &position() const {
        return m_position;
    }

private:
    std::unique_ptr<Token> m_token;

    SourcePosition m_position;
    uint32_t m_length;
};

class Lexer {
public:
    explicit Lexer(const string& input)
        : m_input(input), m_position(0), m_mode(LexingMode::Normal), m_sourcePosition{1, 1} {
        run();
    }

    NO_COPY(Lexer);

    [[nodiscard]] std::vector<SourceToken>&& getTokens() && {
        return std::move(m_sourceTokens);
    }

private:
    void run() {
        while (m_position < m_input.size()) {
            char c = m_input[m_position];
            char c2 = m_input[m_position + 1];

            auto& keywords = Keywords::getInstance();

            if (m_mode == LexingMode::Normal) {
                if (c == '\n') {
                    nextLine();
                } else if (isspace(c)) {
                    ignoreInLine(1);
                } else if (c == '.') {
                    addToken(make_unique<tokens::Dot>(), 1);
                } else if (c == ',') {
                    addToken(make_unique<tokens::Comma>(), 1);
                } else if (c == ':') {
                    addToken(make_unique<tokens::Colon>(), 1);
                } else if (c == ';') {
                    addToken(make_unique<tokens::Semicolon>(), 1);
                } else if (c == '=') {
                    if (c2 == '=') {
                        addToken(make_unique<tokens::operators::Equality>(), 2);
                    } else {
                        addToken(make_unique<tokens::Equal>(), 1);
                    }
                } else if (c == '(') {
                    addToken(make_unique<tokens::brackets::OpenRound>(), 1);
                } else if (c == ')') {
                    addToken(make_unique<tokens::brackets::CloseRound>(), 1);
                } else if (c == '[') {
                    addToken(make_unique<tokens::brackets::OpenSquare>(), 1);
                } else if (c == ']') {
                    addToken(make_unique<tokens::brackets::CloseSquare>(), 1);
                } else if (c == '{') {
                    addToken(make_unique<tokens::brackets::OpenCurly>(), 1);
                } else if (c == '}') {
                    addToken(make_unique<tokens::brackets::CloseCurly>(), 1);
                } else if (c == '+') {
                    addToken(make_unique<tokens::operators::Plus>(), 1);
                } else if (c == '-') {
                    addToken(make_unique<tokens::operators::Minus>(), 1);
                } else if (c == '*') {
                    addToken(make_unique<tokens::operators::Star>(), 1);
                } else if (c == '/') {
                    if (c2 == '/') {
                        m_mode = LexingMode::SingleLineComment;
                    } else if (c2 == '*') {
                        m_mode = LexingMode::MultiLineComment;
                    } else {
                        addToken(make_unique<tokens::operators::Slash>(), 1);
                    }
                } else if (c == '?') {
                    addToken(make_unique<tokens::operators::Question>(), 1);
                } else if (c == '%') {
                    addToken(make_unique<tokens::operators::Percentage>(), 1);
                } else if (c == '!') {
                    if (c2 == '=') {
                        addToken(make_unique<tokens::operators::NotEquality>(), 2);
                    } else {
                        addToken(make_unique<tokens::operators::Exclamation>(), 1);
                    }
                } else if (c == '^') {
                    addToken(make_unique<tokens::operators::Caret>(), 1);
                } else if (c == '~') {
                    addToken(make_unique<tokens::operators::Tilda>(), 1);
                } else if (c == '<') {
                    if (c2 == '=') {
                        addToken(make_unique<tokens::operators::LessThanOrEqual>(), 2);
                    } else {
                        addToken(make_unique<tokens::operators::LessThan>(), 1);
                    }
                } else if (c == '>') {
                    if (c2 == '=') {
                        addToken(make_unique<tokens::operators::GreaterThanOrEqual>(), 2);
                    } else {
                        addToken(make_unique<tokens::operators::GreaterThan>(), 1);
                    }
                } else if (c == '"' || c == '\'') {
                    std::regex regex(R"(".*?[^\]"|'.*?[^\]')");
                    auto matches_begin = std::sregex_iterator(m_input.begin(), m_input.end(), regex);
                    std::smatch match = *matches_begin;
                    string value = match.str().substr(1, match.size() - 1);
                    addToken(make_unique<tokens::String>(value), match.size());
                } else if (checkIfKeyword(keywords.IF)) {
                    addToken(make_unique<tokens::keywords::If>(), keywords.IF.size());
                } else if (checkIfKeyword(keywords.ELSE)) {
                    addToken(make_unique<tokens::keywords::Else>(), keywords.ELSE.size());
                } else if (checkIfKeyword(keywords.FUNC_DEF)) {
                    addToken(make_unique<tokens::keywords::FuncDef>(), keywords.FUNC_DEF.size());
                } else if (checkIfKeyword(keywords.FOR)) {
                    addToken(make_unique<tokens::keywords::For>(), keywords.FOR.size());
                } else if (checkIfKeyword(keywords.RETURN)) {
                    addToken(make_unique<tokens::keywords::Return>(), keywords.RETURN.size());
                } else if (checkIfKeyword(keywords.IN)) {
                    addToken(make_unique<tokens::keywords::In>(), keywords.IN.size());
                } else if (checkIfKeyword(keywords.IS)) {
                    addToken(make_unique<tokens::keywords::Is>(), keywords.IS.size());
                } else if (checkIfKeyword(keywords.TRUE)) {
                    addToken(make_unique<tokens::Boolean>(true), keywords.TRUE.size());
                } else if (checkIfKeyword(keywords.FALSE)) {
                    addToken(make_unique<tokens::Boolean>(false), keywords.FALSE.size());
                } else {
                    m_mode = LexingMode::IdentifierOrNumber;
                }
            } else if (m_mode == LexingMode::SingleLineComment) {
                string::size_type endPosition = m_input.find('\n', m_position);
                if (endPosition == string::npos) endPosition = m_input.size();

                ignoreInLine(endPosition - m_position);
                m_mode = LexingMode::Normal;
            } else if (m_mode == LexingMode::MultiLineComment) {
                if (c == '\n') {
                    nextLine();
                } else if (c == '*' && c2 == '/') {
                    ignoreInLine(2);
                    m_mode = LexingMode::Normal;
                } else {
                    ignoreInLine(1);
                }
            } else if (m_mode == LexingMode::IdentifierOrNumber) {
                auto endPosition = m_input.find_first_not_of(IDENTIFIER_OR_NUMBER_CHARACTERS, m_position);
                if (endPosition == string::npos) endPosition = m_input.size();

                auto length = endPosition - m_position;

                addToken(make_unique<tokens::IdentifierOrNumber>(m_input.substr(m_position, length)), length);
                m_mode = LexingMode::Normal;
            }
        }
    }

    bool checkIfKeyword(const string &keyword) {
        return m_input.compare(m_position, keyword.size(), keyword) == 0 &&
               !isIdentifierOrNumberCharacter(m_input[m_position + keyword.size()]);
    }

    bool isIdentifierOrNumberCharacter(char c) {
        return IDENTIFIER_OR_NUMBER_CHARACTERS.find(c) != string::npos;
    }

    void nextLine() {
        m_sourcePosition.line += 1;
        m_sourcePosition.column = 1;
        m_position += 1;
    }

    void ignoreInLine(uint32_t length) {
        m_sourcePosition.column += length;
        m_position += length;
    }

    void addToken(std::unique_ptr<Token> token, uint32_t length) {
        m_sourceTokens.emplace_back(
            SourceToken(
                    std::move(token),
                    m_sourcePosition,
                    length
            )
        );

        m_sourcePosition.column += length;
        m_position += length;
    }

    const string IDENTIFIER_OR_NUMBER_CHARACTERS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_$";

    const string &m_input;

    LexingMode m_mode;
    size_t m_position;
    SourcePosition m_sourcePosition;

    std::vector<SourceToken> m_sourceTokens;
};
