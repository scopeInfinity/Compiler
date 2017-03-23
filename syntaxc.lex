%{
#include "y.tab.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
extern char* yylval;
char* ana(char *s){
	int len = strlen(s);
	char *x = (char*) malloc((sizeof(char))*(len+1));
	strcpy(x,s);
	return x;
}
%}


ident [A-Za-z_][A-Za-z_0-9]*
sp ([ \t\n])
integer_constant character_constant floating_constant identifier string SIZEOF
%%
(\"[^"]*\")		{return string;}
(\'[^']\')		{return character_constant;}

((\+|-)?[0-9]*\.[0-9]+)		{return floating_constant;}
((\+|-)?[0-9]+)		{return integer_constant;}


(sizeof)		{return SIZEOF;}



"auto" {return AUTO;}

"register" {return REGISTER;}

"static" {return STATIC;}

"extern" {return EXTERN;}

"typedef" {return TYPEDEF;}

"void" {return VOID;}

"char" {return CHAR;}

"short" {return SHORT;}

"int" {return INT;}

"long" {return LONG;}

"float" {return FLOAT;}

"double" {return DOUBLE;}

"signed" {return SIGNED;}

"unsigned" {return UNSIGNED;}

"const" {return CONST;}

"volatile" {return VOLATILE;}

"struct" {return STRUCT;}

"union" {return UNION;}

"enum" {return ENUM;}

"case" {return CASE;}

"default" {return DEFAULT;}

"if" {return IF;}

"else" {return ELSE;}

"switch" {return SWITCH;}

"while" {return WHILE;}

"do" {return DO;}

"for" {return FOR;}

"goto" {return GOTO;}

"continue" {return CONTINUE;}

"break" {return BREAK;}

"return" {return RETURN;} 



(EOC)			{return EOC;}
{ident}			{return identifier;}
{sp} {}

(.)			{printf("%c\n",yytext[0]); return yytext[0];}
%%
int yywrap(){
return 1;
}
/*
"&&" {return O_AND;}
"||" {return O_OR;}
"!=" {return O_NEQ;}
"==" {return O_EQ;}
">=" {return O_GE;}
"<=" {return O_LE;}
*/
