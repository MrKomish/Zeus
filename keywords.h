#pragma once

using std::make_unique;

class Keywords final {
public:
    Keywords() = default;
    ~Keywords() = default;

    static Keywords& getInstance() {
        if (g_instance == nullptr) {
            g_instance = make_unique<Keywords>();
        }
        return *g_instance;
    }

    NO_COPY(Keywords);
    NO_MOVE(Keywords);

    const std::string IF = "if";
    const std::string ELSE = "else";
    const std::string FUNC_DEF = "fn";
    const std::string FOR = "for";
    const std::string IN = "in";
    const std::string IS = "is";
    const std::string RETURN = "return";
    const std::string TRUE = "true";
    const std::string FALSE = "false";
    const std::string SELF = "this";
    const std::string PUBLIC = "public";
    const std::string PRIVATE = "private";

private:
    inline static std::unique_ptr<Keywords> g_instance;
};
