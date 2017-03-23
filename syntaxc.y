%{
#include<stdio.h>
#include<math.h>

#define YYSTYPE char*
%}

%token integer_constant character_constant floating_constant identifier string SIZEOF EOC AUTO REGISTER STATIC EXTERN TYPEDEF VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED STRUCT_OR_UNION_SPECIFIER ENUM_SPECIFIER TYPEDEF_NAME CONST VOLATILE STRUCT UNION ENUM CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN 

%start CODE
%%
CODE: translation_unit EOC {printf("Code Accepted\n");exit(0);}
;


translation_unit:
external_declaration
translation_unit external_declaration

external_declaration:
function_definition
declaration

function_definition:
declarator declaration_list
| declaration_specifiers declarator declaration_list
|  declarator 
| declaration_specifiers declarator 
|  declarator declaration_list
| declaration_specifiers declarator declaration_list
| compound_statement
;

declaration:
declaration_specifiers init_declarator_list ';'
declaration_specifiers   ';'
;

declaration_list:
| declaration
| declaration_list declaration
;

declaration_specifiers:
storage_class_specifier
| storage_class_specifier declaration_specifiers
| type_specifier
| type_specifier declaration_specifiers
| type_qualifier
;

storage_class_specifier:
| AUTO | REGISTER | STATIC | EXTERN | TYPEDEF
;

type_specifier:
| VOID | CHAR | SHORT | INT | LONG | FLOAT | DOUBLE | SIGNED
| UNSIGNED | STRUCT_OR_UNION_SPECIFIER | ENUM_SPECIFIER | TYPEDEF_NAME
;

type_qualifier:
CONST VOLATILE
| struct_or_union_specifier:
| struct_or_union '{' struct_declaration_list '}'
| struct_or_union identifier '{' struct_declaration_list '}'
| struct_or_union identifier
;

struct_or_union: 
| STRUCT | UNION
| struct_declaration_list:
| STRUCT declaration
| struct_declaration_list STRUCT declaration
;

init_declarator_list:
| init_declarator
| init_declarator_list ',' init_declarator
;

init_declarator:
declarator
| declarator '=' initializer
;

struct_declaration:
specifier_qualifier_list struct_declarator_list ';'
;

specifier_qualifier_list:
type_specifier
| type_specifier specifier_qualifier_list
| type_qualifier
| type_qualifier specifier_qualifier_list
;

struct_declarator_list:
struct_declarator
| struct_declarator_list ',' struct_declarator
;

struct_declarator:
declarator
| declarator ':' constant_expression
;

enum_specifier:
| '{' enumerator_list '}'
| ENUM identifier '{' enumerator_list '}'
| ENUM identifier
;

enumerator_list:
enumerator
| enumerator_list ',' enumerator
;

enumerator:
identifier
identifier '=' constant_expression
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
|  '[' ']'
|  '['constant_expression ']'
| direct_abstract_declarator '[' ']'
| direct_abstract_declarator '['constant_expression ']'
|  '(' ')'
|  '('parameter_type_list ')'
| direct_abstract_declarator '(' ')'
| direct_abstract_declarator '('parameter_type_list ')'
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
| DEFAULT ':' statement
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
statement_list:
statement
| statement_list statement
;

selection_statement:
| IF '('expression')' statement
| IF '('expression')' statement ELSE statement
| SWITCH '('expression')' statement
;

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

primary_expression:
| constant
| string
| '(' expression ')'
;

argument_expression_list:
assignment_expression
| argument_expression_list ',' assignment_expression
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


