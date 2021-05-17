#pragma once

#include "tokens.h"

using std::optional;

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