%{
#include <stdio.h>
#include "y.tab.h"

void trackLines();
void comment();
extern void yyerror();
int lineno = 1;
char lastlines[10000][1000];

%}



D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*


%%
"/*"			{ comment(); }

"auto"			{ trackLines(); return(AUTO); }
"break"			{ trackLines(); return(BREAK); }
"case"			{ trackLines(); return(CASE); }
"char"			{ trackLines(); return(CHAR); }
"const"			{ trackLines(); return(CONST); }
"continue"		{ trackLines(); return(CONTINUE); }
"default"		{ trackLines(); return(DEFAULT); }
"do"			{ trackLines(); return(DO); }
"double"		{ trackLines(); return(DOUBLE); }
"else"			{ trackLines(); return(ELSE); }
"enum"			{ trackLines(); return(ENUM); }
"extern"		{ trackLines(); return(EXTERN); }
"float"			{ trackLines(); return(FLOAT); }
"for"			{ trackLines(); return(FOR); }
"goto"			{ trackLines(); return(GOTO); }
"if"			{ trackLines(); return(IF); }
"int"			{ trackLines(); return(INT); }
"long"			{ trackLines(); return(LONG); }
"register"		{ trackLines(); return(REGISTER); }
"return"		{ trackLines(); return(RETURN); }
"short"			{ trackLines(); return(SHORT); }
"signed"		{ trackLines(); return(SIGNED); }
"sizeof"		{ trackLines(); return(SIZEOF); }
"static"		{ trackLines(); return(STATIC); }
"struct"		{ trackLines(); return(STRUCT); }
"switch"		{ trackLines(); return(SWITCH); }
"typedef"		{ trackLines(); return(TYPEDEF); }
"union"			{ trackLines(); return(UNION); }
"unsigned"		{ trackLines(); return(UNSIGNED); }
"void"			{ trackLines(); return(VOID); }
"volatile"		{ trackLines(); return(VOLATILE); }
"while"			{ trackLines(); return(WHILE); }

{L}({L}|{D})*		{ trackLines(); return IDENTIFIER; }

0[xX]{H}+{IS}?		{ trackLines(); return(CONSTANT); }
0{D}+{IS}?		{ trackLines(); return(CONSTANT); }
{D}+{IS}?		{ trackLines(); return(CONSTANT); }
L?'(\\.|[^\\'])+'	{ trackLines(); return(CONSTANT); }

{D}+{E}{FS}?		{ trackLines(); return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ trackLines(); return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ trackLines(); return(CONSTANT); }

L?\"(\\.|[^\\"])*\"	{ trackLines(); return(STRING_LITERAL); }

"..."			{ trackLines(); return(ELLIPSIS); }
">>="			{ trackLines(); return(RIGHT_ASSIGN); }
"<<="			{ trackLines(); return(LEFT_ASSIGN); }
"+="			{ trackLines(); return(ADD_ASSIGN); }
"-="			{ trackLines(); return(SUB_ASSIGN); }
"*="			{ trackLines(); return(MUL_ASSIGN); }
"/="			{ trackLines(); return(DIV_ASSIGN); }
"%="			{ trackLines(); return(MOD_ASSIGN); }
"&="			{ trackLines(); return(AND_ASSIGN); }
"^="			{ trackLines(); return(XOR_ASSIGN); }
"|="			{ trackLines(); return(OR_ASSIGN); }
">>"			{ trackLines(); return(RIGHT_OP); }
"<<"			{ trackLines(); return(LEFT_OP); }
"++"			{ trackLines(); return(INC_OP); }
"--"			{ trackLines(); return(DEC_OP); }
"->"			{ trackLines(); return(PTR_OP); }
"&&"			{ trackLines(); return(AND_OP); }
"||"			{ trackLines(); return(OR_OP); }
"<="			{ trackLines(); return(LE_OP); }
">="			{ trackLines(); return(GE_OP); }
"=="			{ trackLines(); return(EQ_OP); }
"!="			{ trackLines(); return(NE_OP); }
";"			{ trackLines(); return(';'); }
("{"|"<%")		{ trackLines(); return('{'); }
("}"|"%>")		{ trackLines(); return('}'); }
","			{ trackLines(); return(','); }
":"			{ trackLines(); return(':'); }
"="			{ trackLines(); return('='); }
"("			{ trackLines(); return('('); }
")"			{ trackLines(); return(')'); }
("["|"<:")		{ trackLines(); return('['); }
("]"|":>")		{ trackLines(); return(']'); }
"."			{ trackLines(); return('.'); }
"&"			{ trackLines(); return('&'); }
"!"			{ trackLines(); return('!'); }
"~"			{ trackLines(); return('~'); }
"-"			{ trackLines(); return('-'); }
"+"			{ trackLines(); return('+'); }
"*"			{ trackLines(); return('*'); }
"/"			{ trackLines(); return('/'); }
"%"			{ trackLines(); return('%'); }
"<"			{ trackLines(); return('<'); }
">"			{ trackLines(); return('>'); }
"^"			{ trackLines(); return('^'); }
"|"			{ trackLines(); return('|'); }
"?"			{ trackLines(); return('?'); }

[ \t\v\f]		{ trackLines(); }
[\n]			{ trackLines(); lineno++;lastlines[lineno][0]='\0'; /* lineno keeps track of index of current Line. Increase lineno on seeing newline.*/}
.		{ 
			strcat(lastlines[lineno],yytext);
			yyerror("Invalid Token");
			exit(0);
		}

%%

int yywrap()
{
	return(1);
}


void comment()
{
	/* ignore comments, increase lineno, also append newline as string to the lastlines array */ 
	char c, c1;

	loop:
	while ((c = input()) != '*' && c != 0)
		{
			char s2[]="\n";
			if(c=='\n') {
				strcat(lastlines[lineno],s2);
				lineno++;
				lastlines[lineno][0]='\0';
			}

		}

	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}

}


int offset = 0;
/* offset to keep track of which position the parse error occurs. */

void trackLines()
{
	/* Append the token to the end of current line in lastlines */

	strcat(lastlines[lineno],yytext);
	int i;
	
	for (i = 0; yytext[i] ; i++) {
		if(yytext[i]=='\n')
			offset= 0;
		else if(yytext[i]=='\t')
			offset+= 8 - (offset % 8);
		else
			offset++;
	}
}
