#pragma once

#include <variant>

class Token {
public:
    virtual ~Token() = default;
    [[nodiscard]] virtual std::string toString() const = 0;
};

inline std::ostream & operator<<(std::ostream& stream, const Token& token) {
    stream << token.toString();
    return stream;
}

namespace tokens {

    class Dot : public Token {
    public:
        [[nodiscard]] std::string toString() const override {
            return ".";
        }
    };

    class Comma : public Token {
    public:
        [[nodiscard]] std::string toString() const override {
            return ",";
        }
    };
    class Colon : public Token {
    public:
        [[nodiscard]] std::string toString() const override {
            return ":";
        }
    };
    class Semicolon : public Token {
    public:
        [[nodiscard]] std::string toString() const override {
            return ";";
        }
    };

    class Equal : public Token {
    public:
        [[nodiscard]] std::string toString() const override {
            return "=";
        }
    };
    namespace operators {
        class Plus : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "+";
            }
        };
        class Minus : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "-";
            }
        };
        class Star : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "*";
            }
        };
        class Slash : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "/";
            }
        };
        class Question : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "?";
            }
        };
        class Percentage : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "%";
            }
        };
        class Exclamation : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "~";
            }
        };
        class Caret : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "^";
            }
        };
        class Tilda : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "~";
            }
        };

        class Equality : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "==";
            }
        };
        class NotEquality : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "!=";
            }
        };
        class LessThan : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "<";
            }
        };
        class LessThanOrEqual : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "<=";
            }
        };
        class GreaterThan : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return ">";
            }
        };
        class GreaterThanOrEqual : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return ">=";
            }
        };
    }

    namespace brackets {
        class OpenRound : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "(";
            }
        };
        class CloseRound : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return ")";
            }
        };

        class OpenSquare : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "[";
            }
        };
        class CloseSquare : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "]";
            }
        };

        class OpenCurly : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "{";
            }
        };
        class CloseCurly : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "}";
            }
        };
    }

    namespace keywords {
        class If : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "if";
            }
        };

        class Else : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "else";
            }
        };

        class FuncDef : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "fn";
            }
        };

        class For : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "for";
            }
        };

        class Return : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "return";
            }
        };

        class In : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "in";
            }
        };

        class Is : public Token {
        public:
            [[nodiscard]] std::string toString() const override {
                return "is";
            }
        };
    }

    class Boolean : public Token {
    public:
        explicit Boolean(bool value) : m_value(value) {
            // Left blank intentionally
        }

        [[nodiscard]] bool value() const {
            return m_value;
        }

        [[nodiscard]] std::string toString() const override {
            return m_value ? "b`true`" : "b`false`";
        }

    private:
        bool m_value;
    };

    class String : public Token {
    public:
        explicit String(std::string value) : m_value(std::move(value)) {
            // Left blank intentionally
        }

        [[nodiscard]] const std::string& value() const {
            return m_value;
        }

        [[nodiscard]] std::string toString() const override {
            return "s\"" + m_value + "\"";
        }

    private:
        std::string m_value;
    };

    class IdentifierOrNumber : public Token {
    public:
        explicit IdentifierOrNumber(std::string value) : m_value(std::move(value)) {
            // Left blank intentionally
        }

        [[nodiscard]] const std::string& value() const {
            return m_value;
        }

        [[nodiscard]] std::string toString() const override {
            return "`" + m_value + "`";
        }

    private:
        std::string m_value;
    };

}

/*
using Token = std::variant<
    tokens::Dot,
    tokens::Comma,
    tokens::Colon,
    tokens::Semicolon,
    tokens::Equal,
    tokens::brackets::OpenRound,
    tokens::brackets::CloseRound,
    tokens::brackets::OpenSquare,
    tokens::brackets::CloseSquare,
    tokens::brackets::OpenCurly,
    tokens::brackets::CloseCurly,
    tokens::operators::Plus,
    tokens::operators::Minus,
    tokens::operators::Star,
    tokens::operators::Slash,
    tokens::operators::Question,
    tokens::operators::Percentage,
    tokens::operators::Exclamation,
    tokens::operators::Caret,
    tokens::operators::Tilda,
    tokens::operators::Equality,
    tokens::operators::NotEquality,
    tokens::operators::LessThan,
    tokens::operators::LessThanOrEqual,
    tokens::operators::GreaterThan,
    tokens::operators::GreaterThanOrEqual,
    tokens::keywords::If,
    tokens::keywords::Else,
    tokens::keywords::FuncDef,
    tokens::keywords::For,
    tokens::keywords::Return,
    tokens::keywords::In,
    tokens::keywords::Is,
    tokens::Identifier,
    tokens::literals::Boolean,
    tokens::literals::String,
    tokens::literals::Integer,
    tokens::literals::Float
>;*/

/**
*
*/