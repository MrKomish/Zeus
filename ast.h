#pragma once

#include <vector>
#include <map>

#include "tokens.h"

using std::vector;
using std::map;

namespace ast {
    class Node {
    public:
        virtual ~Node() = default;
    };

    class Identifier : public Node {
    public:
        explicit Identifier(string name) : m_name(std::move(name)) {

        }

        [[nodiscard]] const string& name() const {
            return m_name;
        }

    private:
        string m_name;
    };

    class Expression : public Node {

    };

    class Statement : public Node {

    };

    class Code: public Node {
    public:
        Code(vector<unique<Statement>> statements) : m_statements(std::move(statements)) {
            // Left blank intentionally
        }

        [[nodiscard]] const vector<unique<Statement>>& statements() const {
            return m_statements;
        };

    public:
        vector<unique<Statement>> m_statements;
    };

    class AssignmentOperator {
    public:
        enum class Type {
            PLUS,
            MINUS,
            STAR,
            SLASH,
            CARET,
            PERCENTAGE,
            QUESTION
        };

        explicit AssignmentOperator(Type type) : m_type(type) {

        }

    private:
        Type m_type;
    };

    class EvaluateExpressionStatement : public Statement {
    public:
        explicit EvaluateExpressionStatement(unique_ptr<Expression> expression)
                : m_expression(std::move(expression)) {
            // Left blank intentionally
        }

        [[nodiscard]] const unique_ptr<Expression>& expression() const {
            return m_expression;
        }

    private:
        unique_ptr<Expression> m_expression;
    };

    class AssignmentStatement : public Statement {
    public:
        explicit AssignmentStatement(Identifier variable, unique_ptr<Expression> type, unique_ptr<Expression> expression)
                : m_variable(std::move(variable)), m_type(type), m_expression(std::move(expression)) {
            // Left blank intentionally
        }

        [[nodiscard]] const Identifier& variable() const {
            return m_variable;
        }

        [[nodiscard]] const unique_ptr<Expression>& value() const {
            return m_value;
        }

    private:
        Identifier m_variable;
        unique_ptr<Expression> m_type;
        unique_ptr<Expression> m_value;
    };

    class OperationAssignmentStatement : public Statement {
    public:
        explicit OperationAssignmentStatement(Identifier variable, AssignmentOperator op, unique_ptr<Expression> expression)
                : m_variable(std::move(variable)), m_op(std::move(op)), m_expression(std::move(expression)) {
            // Left blank intentionally
        }

        [[nodiscard]] const AssignmentOperator& variable() const {
            return m_variable;
        }

        [[nodiscard]] const Identifier& op() const {
            return m_op;
        }

        [[nodiscard]] const unique_ptr<Expression>& value() const {
            return m_value;
        }

    private:
        Identifier m_variable;
        AssignmentOperator m_op;
        unique_ptr<Expression> m_value;
    };

    class IfElseStatement : public Statement {
    public:
        IfElseStatement(vector<ConditionalCode> ifCodes, Code elseCode)
            : m_ifCodes(std::move(ifCodes)), m_elseCode(std::move(elseCode)) {
            // Left blank intentionally
        }

        [[nodiscard]] const vector<ConditionalCode>& ifCodes() const {
            return m_ifCodes;
        }

        [[nodiscard]] const Code& elseCode() const {
            return m_elseCode;
        }

        struct ConditionalCode {
            Expression condition;
            Code code;
        };
    private:
        vector<ConditionalCode> m_ifCodes;
        Code m_elseCode;
    };

    class ForLoopStatement : public Statement {
    public:
        ForLoopStatement(Identifier itemVariable, Expression iterable, Code code):
                m_itemVariable(std::move(itemVariable)), m_iterable(std::move(iterable)), m_code(std::move(code)) {
            // Left blank intentionally
        }

        [[nodiscard]] const Identifier& itemVariable() const {
            return m_itemVariable;
        }

        [[nodiscard]] const Expression& iterable() const {
            return m_iterable;
        }

        [[nodiscard]] const Code& code() const {
            return m_code;
        }

    private:
        Identifier m_itemVariable;
        Expression m_iterable;
        Code m_code;
    };
    class VariableAssignmentStatement: public Statement {
    public:
        VariableAssignmentStatement(Identifier identifier,
                                    vector<ArgumentDefinition> compileArgs,
                                    vector<ArgumentDefinition> args,
                                    Code code)
                : m_identifier(std::move(identifier)),
                  m_compileArgs(std::move(compileArgs)),
                  m_args(std::move(args)),
                  m_code(std::move(code)) {
            // Left blank intentionally
        }

        [[nodiscard]] const Identifier& identifier() const {
            return m_identifier;
        }

        [[nodiscard]] const vector<ArgumentDefinition>& compileArgs() const {
            return m_compileArgs;
        }

        [[nodiscard]] const vector<ArgumentDefinition>& args() const {
            return m_args;
        }

        [[nodiscard]] const Code& code() const {
            return m_code;
        }

    private:
        Identifier m_identifier;
        vector<ArgumentDefinition> m_compileArgs;
        vector<ArgumentDefinition> m_args;
        Code m_code;
    };

    class WhileStatement : public Statement {
    public:
        WhileStatement(Expression condition, Code code)
            : m_condition(std::move(condition)), m_code(std::move(code)) {
            // Left blank intentionally
        }

        [[nodiscard]] const Expression& condition() const {
            return m_condition;
        }

        [[nodiscard]] const Code& code() const {
            return m_code;
        }
    private:
        Expression m_condition;
        Code m_code;
    };

    class ArgumentDefinition : public Node {
    public:
        ArgumentDefinition(Identifier name, Expression type)
            : name(std::move(name)), type(std::move(type)) {
            // Left blank intentionally
        }

        [[nodiscard]] const Identifier& name() const {
            return m_name;
        }

        [[nodiscard]] const Expression& type() const {
            return m_type;
        }

    private:
        Identifier m_name;
        Expression m_type;
    };

    class FunctionDefinitionStatement: public Statement {
    public:
        FunctionDefinitionStatement(Identifier identifier,
                                    vector<ArgumentDefinition> compileArgs,
                                    vector<ArgumentDefinition> args,
                                    Code code)
                : m_identifier(std::move(identifier)),
                m_compileArgs(std::move(compileArgs)),
                m_args(std::move(args)),
                m_code(std::move(code)) {
            // Left blank intentionally
        }

        [[nodiscard]] const Identifier& identifier() const {
            return m_identifier;
        }

        [[nodiscard]] const vector<ArgumentDefinition>& compileArgs() const {
            return m_compileArgs;
        }

        [[nodiscard]] const vector<ArgumentDefinition>& args() const {
            return m_args;
        }

        [[nodiscard]] const Code& code() const {
            return m_code;
        }

    private:
        Identifier m_identifier;
        vector<ArgumentDefinition> m_compileArgs;
        vector<ArgumentDefinition> m_args;
        Code m_code;
    };

    class ClassDefinitionStatement;

    class ClassMethodDefinitionStatement : public Statement {
    public:
        explicit ClassMethodDefinitionStatement(ClassDefinitionStatement& cls, FunctionDefinitionStatement function)
            : m_class(cls), m_function(std::move(function)) {

        }

        [[nodiscard]] const ClassDefinitionStatement& getClass() const {
            return m_class;
        }

        [[nodiscard]] const FunctionDefinitionStatement& getClass() const {
            return m_function;
        }

    private:
        ClassDefinitionStatement& m_class;
        FunctionDefinitionStatement m_function;
    };

    class ClassPropertyDefinitionStatement : public Statement {
    public:
        explicit ClassMethodDefinitionStatement(ClassDefinitionStatement& cls, FunctionDefinitionStatement function)
                : m_class(cls), m_function(std::move(function)) {

        }

        [[nodiscard]] const ClassDefinitionStatement& getClass() const {
            return m_class;
        }

        [[nodiscard]] const FunctionDefinitionStatement& getClass() const {
            return m_function;
        }

    private:
        ClassDefinitionStatement& m_class;
        FunctionDefinitionStatement m_function;
    };

    class ClassDefinitionStatement : public Statement {
    public:
        explicit ClassDefinitionStatement(vector<ClassMethodDefinitionStatement> methods, vector<>) {

        }

    private:

    };

    class ClassDefinitionStatementBuilder final {
    public:
        ClassDefinitionStatementBuilder() {

        }
    };

    class TraitDefinitionStatement : public Statement {
    public:

    };

}