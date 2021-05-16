# Zeus

An OOP programming language in development that combines an advanced type system inspired by TypeScript, the syntax simplicity of Python, and the ideas and efficiency of Rust and C++. Written in C++ using LLVM.

## Design Playground

```dart
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

Source(statements: [
    Statement(),
    
])

interface Users {
    [''] for key in users if
}

class Users {
    id: number;
    name: str;
    age: number;
}

class Type {
    void mem();
}


type User = Class(members: [
    Property(name: "name", type: Type),
    Method(name: "name",
        args: [MethodArg(name: "", type: Type)],
        returnType: Type
    )
])

trait Printable {

}

type user = Class<members: [
    
]>

fn gql<code: str>: GraphQLType {
   http.request("server/graphql.schema")
}

optional<User>(name)

variable | type 

UsersQuery = gql<"
    query {
        users
    }
">;

apollo.query<UsersQuery>().users

fn printable<T: Type>() {
    return T.withAdded([]);
}

@inject
class User {

}

class Default<T: Type, default: T> {
    
}

petNamesByUsername : Map<key: String, value: Default<Vector<String>, []>>

class Users {
    public get(id: User['id']): User {
        
    }
}

router(
    route(address) { pageByAddress(address) },
    value: 
)

interface UserCreationDetails {
    name: String
    age: i32
}

class User {
    User(@inject() db: Users, ...details: UserCreationDetails) {
        db.users.create({name: details.name, age: details.age});
    }
    
    User.of(UserDetails details) {
        // work
    }
    
    order(product: Product) {
        
    }
    
    details() {
        // work
    }
}

class Product {
    Product() {
    
    }
}

user = User()
user = User.of(users.get('123'))

fn order(user: e.User, product: e.Product) {

}

class Orde

FireService = FireService.injected(usersService: usersService)

fn f(user: User) {
   create(user)
   Order(user, users)
}

class User {

}

trait StringRepresentable {
    str toString()
}

implement StringRepresentable for 

compilation void file() {

}

compilation x = 2;

class User {
    
}

type A = {};

data class Optional<T> {
    [member.signature(): ] for member in T.props()
}

interface MachineGun {
    key for key in Users
    key for key in Master
}

interface MegaUsers = Union<Users, MachineGun>

var: (types['']) = {}

if x is y:
```

```
fn gql<code: str>: GraphQLType {
   result = http.request<"server/graphql.schema">
   return result
}
fn getRoute<router: Router, route: String>: Route {
    items = Vec<i32>
    items.add<123>
    return items

    for r in router.routes<> {
       if r.maches(route) {
            return r
       }
    }
    return NotFoundRoute()
}

trait StringRepresentable {
    toString(): String
}
StringRepresentable = Trait<members: [
    Method<name: "toString",
        args: [],
        returnType: String>
]>

class User {
    name: String
    age: i32
}
User = Trait<members: [
    Property<name: "name", type: String>,
    Property<name: "age", type: i32>
]>

imlp StringRepresentable for User {
    String toString() {
        return "User { " + name + ", " + String.from(age) + "}"
    }
}
StringRepresentable = Type<members: {
    Method<name: "toString",
        args: [],
        returnType: String> : Language<statements: [
            Return<value: 
                BinaryOperator<
                    String("User {"),
                    Identifier("name"),
                    String(", "),
                    Whatever,
                    String("}")
                >
            >
        ]>
}>

fn deepPartial<T: Type> {
    if (T is PrimitiveType) {
        return partial<T>;
    }
    
    if (T is Optional) {
        return deepPartial<T.type<>>;
    }

    return Type<
        properties: [Property<name: name, type: deepPartial<type>> for { name, type } in T.properties<>],
        methods: [Method<name: name, args: args, returnType: deepPartial<type>> for { name, args, type } in T.methods<>]
    >
}

class Complex {
    Complex(i32 real, Optional<i32> imaginary, bool gpu) {
    
    }
}
Complex(0, gpu: True)

x = 123
x += 134
x += 12342
x += 234343
return x

Steps:
Lexer
Parser
Doing what can done at compile time -> X can be done if every Y that it depends on can
-> All logic but things that require runtime or can be changed in runtime

```