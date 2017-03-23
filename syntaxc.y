%{
#include<stdio.h>
#include<math.h>

#define YYSTYPE char*
%}

%token integer_constant character_constant floating_constant identifier string SIZEOF EOC
%start CODE
%%
CODE: primary_identifier EOC {printf("Code Accepted\n");exit(0);}
;


translation-unit:
external-declaration
translation-unit external-declaration
external-declaration:
function-definition
declaration
function-definition:
declaration-specifiers opt declarator declaration-list opt compound-statement
declaration:
declaration-specifiers init-declarator-list opt ;
declaration-list:
declaration
declaration-list declaration
declaration-specifiers:
storage-class-specifier declaration-specifiers opt
type-specifier declaration-specifiers opt
type-qualifier declaration-specifiers opt
storage-class specifier: one of
auto register static extern typedef
type specifier: one of
void char short int long float double signed
unsigned struct-or-union-specifier enum-specifier typedef-name194
type-qualifier: one of
const volatile
struct-or-union-specifier:
struct-or-union identifier opt { struct-declaration-list }
struct-or-union identifier
struct-or-union: one of
struct union
struct-declaration-list:
struct declaration
struct-declaration-list struct declaration
init-declarator-list:
init-declarator
init-declarator-list , init-declarator


init-declarator:
declarator
declarator = initializer
struct-declaration:
specifier-qualifier-list struct-declarator-list ;
specifier-qualifier-list:
type-specifier specifier-qualifier-list opt
type-qualifier specifier-qualifier-list opt
struct-declarator-list:
struct-declarator
struct-declarator-list , struct-declarator
struct-declarator:
declarator
declarator opt : constant-expression
enum-specifier:
enum identifier opt { enumerator-list }
enum identifier
enumerator-list:
enumerator
enumerator-list , enumerator
enumerator:
identifier
identifier = constant-expression
declarator:
pointer opt direct-declarator
direct-declarator:
identifier
( declarator )
direct-declarator [ constant-expression opt ]195
direct-declarator ( parameter-type-list )
direct-declarator ( identifier-list opt )
pointer:
* type-qualifier-list opt
* type-qualifier-list opt pointer
type-qualifier-list:
type-qualifier
type-qualifier-list type-qualifier
parameter-type-list:
parameter-list
parameter-list , ...
parameter-list:
parameter-declaration
parameter-list , parameter-declaration
parameter-declaration:
declaration-specifiers declarator
declaration-specifiers abstract-declarator opt
identifier-list:
identifier
identifier-list , identifier
initializer:
assignment-expression
{ initializer-list }
{ initializer-list , }
initializer-list:
initializer
initializer-list , initializer
type-name:
specifier-qualifier-list abstract-declarator opt
abstract-declarator:
pointer
pointer opt direct-abstract-declarator
direct-abstract-declarator:
( abstract-declarator )
direct-abstract-declarator opt [constant-expression opt ]
direct-abstract-declarator opt (parameter-type-list opt )



typedef-name:
identifier
statement:
labeled-statement
expression-statement
compound-statement
selection-statement196
iteration-statement
jump-statement
labeled-statement:
identifier : statement
case constant-expression : statement
default : statement
expression-statement:
expression opt ;
compound-statement:
{ declaration-list opt statement-list opt }
statement-list:
statement
statement-list statement
selection-statement:
if (expression) statement
if (expression) statement else statement
switch (expression) statement
iteration-statement:
while (expression) statement
do statement while (expression) ;
for (expression opt ; expression opt ; expression opt ) statement

jump_statement:
GOTO identifier ';'
| CONTINUE ';'
| BREAK ';'
| RETURN ';'
| RETURN expression ';'
;

expression:
assignment_expression
| expression ',' assignment_expression
;

assignment_expression:
conditional_expression
| unary_expression assignment_operator assignment_expression
;

assignment_operator:
'=' | '*' '=' | '/' '=' | '%' '=' | '+' '=' | '_' '='
| '<' '<' '=' | '>' '>' '=' | '&' '=' | '^' '=' | '|' '='
;

conditional_expression:
logical_OR_expression
| logical_OR_expression '?' expression ':' conditional_expression
;

constant_expression:
conditional_expression
;

logical_OR_expression:
logical_AND_expression
| logical_OR_expression '|' '|' logical_AND_expression
;

logical_AND_expression:
inclusive_OR_expression
| logical_AND_expression '&' '&' inclusive_OR_expression
;

inclusive_OR_expression:
exclusive_OR_expression
| inclusive_OR_expression '|' exclusive_OR_expression
;

exclusive_OR_expression:
AND_expression
| exclusive_OR_expression '^' AND_expression
;

AND_expression:
equality_expression
| AND_expression '&' equality_expression
;

equality_expression:
relational_expression
| equality_expression '=' '=' relational_expression
| equality_expression '!' '=' relational_expression
;

relational_expression:
shift_expression
| relational_expression '<' shift_expression
| relational_expression '>' shift_expression
| relational_expression '<' '=' shift_expression
| relational_expression '>' '=' shift_expression
;

shift_expression:
additive_expression
| shift_expression '<' '<' additive_expression
| shift_expression '>' '>' additive_expression
;

additive_expression:
multiplicative_expression
| additive_expression '+' multiplicative_expression
| additive_expression '-' multiplicative_expression
;

multiplicative_expression:
multiplicative_expression '*' cast_expression
| multiplicative_expression '/' cast_expression
| multiplicative_expression '%' cast_expression
;

cast_expression:
unary_expression
| '(' type_name ')' cast_expression
;

unary_expression:
postfix_expression
| '+' '+' unary_expression
| '-' '-' unary_expression
| unary_operator cast_expression
| SIZEOF unary_expression
| SIZEOF '(' type_name ')'
;

unary_operator: '&' | '*' | '+' | '-' | '~' | '!'
;

postfix_expression:
primary_expression
| postfix_expression '[' expression ']'
| postfix_expression '(' argument_expression_list ')'
| postfix_expression '(' ')'
| postfix_expression '.' identifier
| postfix_expression '-' '>' identifier             {;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;}
| postfix_expression '+' '+'
| postfix_expression '-' '-'
;

primary_identifier:
expression
| constant
| string
| '(' expression ')'
;

argument_expression_list:
assignment_expression
| assignment_expression_list ',' assignment_expression
;

constant:
integer_constant
| character_constant
| floating_constant
;

%%
int yyerror(char *s) {
	printf("Syntax Error : %s\n",s);
	exit(0);
}
int main(){
	yyparse();
}

/*

| enumeration_constant

*/


