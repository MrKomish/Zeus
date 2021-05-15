# Zeus

An OOP programming language in development that combines an advanced type system inspired by TypeScript, the syntax simplicity of Python, and the ideas and efficiency of Rust and C++. Written in C++ using LLVM.

## Design Playground

```
Primitive Types
str
u8
i8
u16
i16
u32
i32
u64
i64
float

money = 123
money: u16

void f(uint8 number) {
    return number + 123
}

Types
Object
String
Vector
BigNumber

Initial idea - Python, TypeScript and Rust combination

language = ({statement}\n)*
statement = {variable_assignment_statement}|{variable_operation_statement}|{function_definition_statement}|{if_else_statement}|{for_loop_statement}|{while_loop_statement}
expression_statement = {expression}
variable_assignment_statement = {definition_identifier}\( *: *{identifier}\)? *= *{expression}
variable_operation_statement = {definition_identifier} *{assignment_operator} *{expression}
function_definition_statement = fn +{definition_identifier} *\{{language}\}
expression = {number_expression}|{string_expression}|{identifier}|{operator_usage_expression}|{call_expression}|\({expression}\)
operator_usage_expression = {expression}{binary_operator}{expression} | {unary_operator}{expression}
unary_operator = !|~
binary_operator = +|-|/|*|^|%|\?|==|!=|<|>|<=|>=|:
assignment_operator = +=|-=|/=|*=|%=|\?=
call_expression = {identifier}({expression},( *{expression})*)

string_expression = "{character}*"|'{character}*'
character = ...

float_number_expression = {float_number}
float_number = {digit}+.{digit}+

number_expression = {number}
number = {decimal_number}|{hex_number}|{binary_number}
decimal_number = -?{digit}+
hex_number = 0x-?{digit}+
binary_number = 0b-?{digit}+
decimal_digit = 0|1|2|3|4|5|6|7|8|9
hex_digit = 0|1|2|3|4|5|6|7|8|9|a|A|b|B|c|C|d|D|e|E|f|F
binary_digit = 0|1

stream = Stream.from([1, 2, 3])
stream |= map()
stream |= filter(fn () {return 2})

stream = users.map(fn (user) => user.name).first()
stream = user.name for user in users if user != "dan"
animal = "cat" if isCat else "dog"
[u for u in users if u != 3]

file ? 2
if (file ?

list[12:23]

type User {
    firstName: str,
    lastName: str
}

trait Mappable {
    map(f): Whatever
}

class User {
    User() {

    }

    fn f() {

    }
}

impl Mappable for Vector {
    map(f):
}

fn main(): int {
    return 0;
}

# or #

class User {
    User() {

    }
}

fn main(): int32 {
    user1 = User()

    for x in range() {

    }

    user1.create()

    return 1;
}

for x in

Features:

Knowledge of type limitations for example after `x: Optional<int32> = null; if (x != null) { y = x + 32 }`

class Optional<int32> {
    operator()
}

213321
0123x = 123

"string_literal"
0.100123
1243
0x123AB
0b101
true
false
water100

Atom -> StringLiteral
BooleanLiteral
IdentifierLiteral

<variable_name>: <type> = <value>

a = socket() // creates a socket
```