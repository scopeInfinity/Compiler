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
 ':' constant_expression
| declarator ':' constant_expression
;

enum-specifier:
| '{' enumerator-list '}'
| enum identifier '{' enumerator_list '}'
| enum identifier
;

enumerator_list:
enumerator
| enumerator_list ',' enumerator
;

enumerator:
identifier
identifier '=' constant-expression
;

declarator:
 direct_declarator
| pointer direct_declarator
;

direct_declarator:
identifier
| '(' declarator ')'
| direct_declarator '[' ']'
| direct_declarator '[' constant_expression ']'
| direct_declarator '(' parameter_type_list ')'
| direct_declarator '(' ')'
| direct_declarator '(' identifier_list ')'
;

pointer:
'*' 
| '*' pointer
| '*' type_qualifier_list
| '*' type_qualifier_list pointer
;

type_qualifier_list:
type_qualifier
| type_qualifier_list type_qualifier
;

parameter_type_list:
parameter_list
| parameter_list ',' '.' '.' '.'
;
parameter_list:
| parameter_declaration
| parameter_list ',' parameter_declaration
;

parameter_declaration:
declaration_specifiers declarator
| declaration_specifiers
| declaration_specifiers abstract_declarator
;

identifier_list:
| identifier
| identifier_list ',' identifier
;

initializer:
assignment_expression
'{' initializer_list '}'
'{' initializer_list ',' '}'
;

initializer_list:
initializer
|initializer_list ',' initializer
;

type_name:
specifier_qualifier_list
| specifier_qualifier_list abstract_declarator
;

abstract_declarator:
pointer
|  direct_abstract_declarator
| pointer  direct_abstract_declarator
;

direct_abstract_declarator:
'(' abstract_declarator ')'
|  [ ]
|  [constant_expression ]
| direct_abstract_declarator [ ]
| direct_abstract_declarator [constant_expression ]
|  ( )
|  (parameter_type_list )
| direct_abstract_declarator ( )
| direct_abstract_declarator (parameter_type_list )
;


typedef_name:
identifier
;

statement:
labeled_statement
| expression_statement
| compound_statement
| selection_statement
| iteration_statement
| jump_statement
;

labeled_statement:
identifier ':' statement
| CASE constant_expression ':' statement
| DEFAULT ':'' statement
;

expression_statement:
expression ';'
| expression ';'


compound_statement:
'{'   '}'
|'{'  statement_list '}'
|'{' declaration_list  '}'
|'{' declaration_list statement_list '}'

;
statement-list:
statement
statement-list statement
selection-statement:
if (expression) statement
if (expression) statement else statement
switch (expression) statement

iteration_statement:
WHILE '(' expression ')' statement
| DO statement WHILE '(' expression ')' ';'
| FOR '('  ';'  ';'  ')'
| FOR '('  ';'  ';' expression ')'
| FOR '('  ';' expression ';'  ')'
| FOR '('  ';' expression ';' expression ')'
| FOR '(' expression ';'  ';'  ')'
| FOR '(' expression ';'  ';' expression ')'
| FOR '(' expression ';' expression ';'  ')'
| FOR '(' expression ';' expression ';' expression ')'
| statement
;

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


