#pragma once

#include "tokens.h"

using std::optional;

class ExpressionNode {

};

class ExpressionNode {

};

// stmt = { if_stmt } |
// if_stmt = { if_stmt_part } { else_if_stmt_part }* { else_stmt_part }?
// if_stmt_part = if { expr } `{` { lang } `}`
// else_if_stmt_part = else if { expr } `{` { language } `}`
// else_stmt_part = else { lang }
// fn_def_stmt = fn { identifier } ({ fn_def_stmt_var } [, { fn_def_stmt_var }]*) `{` {language} `}`
// fn_def_stmt_var = { expression }: { expression }
// language = { stmt }*

if variable is Variable {
    run()
} else if create() {

} else {
    run()
}

namespace ast {
    class Node {
    public:
        virtual Node() = default;
    };

    class Statement : public Node {
    public:
        Statement() {

        }
    };

    class AssignmentStatement : public Statement {
    public:
        AssignmentStatement() {

        }
    };

    class AssignmentStatement : public Statement {
    public:
        AssignmentStatement() {

        }
    };

    class Source: public Node {
    public:
        Source(vector<Statement> statements) : m_statements(std::move(statements)) {
            // Left blank intentionally
        }

        void addStatement(vector<Statement>&& statement) {
            m_statements.emplace_back(statement);
        }

        [[nodiscard]] const vector<Statement>& statements() const {
            return m_statements;
        };

    public:
        vector<Statement> m_statements;
    };
}

class Parser final {
public:
    explicit Parser(std::vector<SourceToken>& tokens) {
        parse();
    }

private:
    void parse() {
        if (match()) {

        }
    }
};