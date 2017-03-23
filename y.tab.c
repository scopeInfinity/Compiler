/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "syntaxc.y"
#include<stdio.h>
#include<math.h>

#define YYSTYPE char*
#line 26 "y.tab.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define integer_constant 257
#define character_constant 258
#define floating_constant 259
#define identifier 260
#define string 261
#define SIZEOF 262
#define EOC 263
#define type_name 264
#define primary_expression 265
#define assignment_expression_list 266
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    2,    2,    3,    3,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    4,    4,    8,    7,
    7,    9,    9,   10,   10,   11,   11,   12,   12,   13,
   13,   13,   14,   14,   14,   14,   14,   15,   15,   15,
   16,   16,   16,   17,   17,   17,   18,   18,    5,    5,
    5,    5,    5,    5,   20,   20,   20,   20,   20,   20,
   19,   19,   19,   19,   19,   19,   19,   19,    1,    1,
    1,    1,   21,   21,   22,   22,   22,
};
static const YYINT yylen[] = {                            2,
    2,    1,    3,    1,    3,    1,    2,    2,    2,    2,
    2,    3,    3,    2,    2,    2,    1,    5,    1,    1,
    4,    1,    4,    1,    3,    1,    3,    1,    3,    1,
    4,    4,    1,    3,    3,    4,    4,    1,    4,    4,
    1,    3,    3,    3,    3,    3,    1,    4,    1,    3,
    3,    2,    2,    4,    1,    1,    1,    1,    1,    1,
    1,    4,    4,    3,    3,    4,    3,    3,    1,    1,
    1,    2,    1,    3,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
   75,   76,   77,   71,    0,   56,    0,   55,   60,    0,
    0,   59,   61,    0,    0,    0,    2,    4,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   70,    0,   53,    0,    0,   72,    1,    0,    6,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   47,   52,    0,   50,   51,    3,
    7,    8,    9,   10,   11,    0,    0,   14,   15,   16,
    5,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   44,   45,   46,
   67,    0,   68,   64,    0,   73,    0,    0,   65,    0,
   54,   12,   13,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   66,    0,   63,   62,    0,   18,   74,   48,
};
static const YYINT yydgoto[] = {                         14,
   15,   16,   17,   18,   19,   51,   20,    0,   21,   22,
   23,   24,   25,   26,   27,   28,   29,   76,   30,   31,
  117,   32,
};
static const YYINT yysindex[] = {                       -22,
    0,    0,    0,    0,  -16,    0,  -28,    0,    0,  -39,
  -13,    0,    0,    0, -225,   22,    0,    0,  495,  -49,
   39,  -26,    8,   68,  -14,   24,   41,   62,   32,   54,
   -8,    0, -148,    0,   -2,   -2,    0,    0,   -2,    0,
   56,   58,   61,   66,   67,   69,   72,   70,   78,   80,
   -2,   18,   -2,  109,    0,    0,    0,   87,   95,   96,
  104,  106,  107,    0,    0,   -8,   -8,   -8,  128,   -3,
  -33,   -2,  -84,  -87,    0,    0,  138,    0,    0,    0,
    0,    0,    0,    0,    0,  119,  121,    0,    0,    0,
    0,    0,    5,    0,    8,   68,  -14,    0,    0,    0,
   41,    0,   41,    0,    0,   32,   32,    0,    0,    0,
    0,  -79,    0,    0,  140,    0,  147,  -37,    0,  152,
    0,    0,    0,   39,    0,  -26,   24,   24,   41,   41,
   62,   62,    0,   -2,    0,    0,   -8,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    6,    0,    0,   12,
    0,    0,    0,    0,    0,  -69,    0,    0,    0,   82,
  168,  105,  162,  435,  120,  302,  306,  218,   27,   20,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  364,  446,  428,    0,    0,    0,
  340,    0,  349,    0,    0,   92,  129,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  461,    0,  226,  353,  391,  407,  417,
  255,  264,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,   23,  -38,   71,  477,    0,    0,    0,  103,  108,
  142,  148,  150,   -7,   99,    4,   47,  -64,    0,    0,
    0,    0,
};
#define YYTABLESIZE 724
static const YYINT yytable[] = {                          9,
   80,  108,  109,  110,    8,   36,   39,  114,    6,    7,
    9,   10,   91,   53,   35,    8,    9,   11,   59,    6,
    7,    8,   10,   33,    9,    6,    7,   37,   10,    8,
    9,   74,  116,    6,    7,    8,   10,   38,   57,    6,
    7,  113,   10,   57,   58,   57,   58,   57,   39,   58,
   57,   58,   49,   58,   58,  136,   49,   49,  112,   41,
   49,   49,  125,   49,   41,   39,   49,   41,   68,   41,
   41,   41,  140,   66,   52,   93,   54,   49,   67,   49,
   49,   49,   49,   60,   41,   61,   41,   41,   41,   41,
  127,  128,   12,   71,  118,  139,   69,   55,   70,   73,
   62,   56,   63,   12,   64,   57,   65,  131,  132,   12,
  106,  107,   49,   49,   49,   77,   81,   12,   82,   41,
   41,   83,   17,   12,   42,   17,   84,   85,   86,   42,
   88,   57,   42,   87,   42,   42,   42,   58,   89,   17,
   90,   92,   22,   49,   72,   22,   94,   98,   22,   42,
   41,   42,   42,   42,   42,   99,  100,   28,  101,  103,
   28,   43,   22,   28,  102,  104,   43,   22,  105,   43,
  111,   43,   43,   43,   17,  119,  120,   28,  121,  122,
  133,  123,   28,  134,   42,   42,   43,  135,   43,   43,
   43,   43,  137,   69,  124,  138,   95,   22,  129,   24,
  130,  126,   24,   96,    0,   24,   97,    0,   20,    0,
    0,   20,   28,   28,    0,   42,    0,    0,    0,   24,
    0,   43,   43,    0,   24,   20,    0,    0,    5,    0,
   20,   13,  115,    0,    1,    2,    3,    0,    4,    5,
    0,    0,   13,   28,    0,    5,    0,    0,   13,    0,
   38,    0,   43,    5,   24,   38,   13,    0,   38,    5,
   20,   38,   13,   23,    0,    0,   23,   57,    0,   23,
   57,    0,    0,   58,    0,   38,   58,   38,   38,   38,
   38,    0,   49,   23,    0,   24,    0,   39,   23,   41,
    0,   20,   39,    0,    0,   39,   40,    0,   39,    0,
    0,   40,    0,    0,   40,    0,    0,   40,    0,    0,
   38,   38,   39,    0,   39,   39,   39,   39,   23,    0,
    0,   40,    0,   40,   40,   40,   40,    0,    0,    0,
    0,    0,    0,    0,   30,    0,    0,    0,   33,   30,
    0,   38,   30,   33,   17,   30,   33,   39,   39,   33,
    0,    0,    0,    0,   42,    0,   40,   40,    0,   30,
    0,    0,   30,   33,   30,    0,   33,   22,   33,    0,
    0,    0,   34,    0,    0,    0,    0,   34,   39,    0,
   34,   35,   28,   34,    0,   31,   35,   40,    0,   35,
   31,   43,   35,   31,   30,   30,   31,   34,   33,   33,
   34,   25,   34,    0,   25,    0,   35,   25,    0,   35,
   31,   35,    0,   31,    0,   31,    0,    0,    0,    0,
    0,   25,    0,   32,   24,   30,   25,    0,   32,   33,
   20,   32,   34,   34,   32,    0,    0,    0,    0,   36,
    0,   35,   35,    0,   36,   31,   31,   36,   32,   37,
   36,   32,    0,   32,   37,    0,   25,   37,    0,    0,
   37,    0,    0,   34,   36,   29,    0,   36,   29,   36,
    0,   29,   35,    0,   37,   26,   31,   37,   26,   37,
   38,   34,    0,   32,   32,   29,   27,   25,   23,   27,
   29,    0,   26,    0,    0,    0,    0,   26,    0,   36,
   36,   21,    0,   27,   21,    0,    0,   75,   27,   37,
   37,   78,   79,    0,   32,    0,    0,   39,   21,    0,
   29,   29,    0,   21,    0,    0,   40,   26,   26,    0,
   36,   43,   48,    0,    0,    0,   41,   44,   27,   27,
   37,   42,   75,   75,   75,    0,    0,    0,    0,    0,
    0,   29,    0,   21,   46,   40,   47,    0,   26,    0,
    0,    0,    0,    0,   30,    0,    0,    0,   33,   27,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   21,    0,    0,    0,   49,   45,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   34,    0,    0,    0,    0,    0,    0,    0,
    0,   35,    0,   75,    0,   31,    0,    0,   50,    0,
    0,    0,    0,    0,    0,    0,   25,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   32,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   36,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   37,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   29,    0,    0,    0,    0,    0,    0,   26,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   27,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   21,
};
static const YYINT yycheck[] = {                         33,
   39,   66,   67,   68,   38,   45,   44,   41,   42,   43,
   33,   45,   51,   63,   43,   38,   33,   40,   33,   42,
   43,   38,   45,   40,   33,   42,   43,   41,   45,   38,
   33,   40,   71,   42,   43,   38,   45,  263,   33,   42,
   43,   45,   45,   38,   33,   40,   61,   42,   44,   38,
   45,   40,   33,   42,   43,   93,   37,   38,   62,   33,
   41,   42,   58,   44,   38,   44,   47,   41,   37,   43,
   44,   45,  137,   42,  124,   53,   38,   58,   47,   60,
   61,   62,   63,   60,   58,   62,   60,   61,   62,   63,
   98,   99,  126,   40,   72,  134,   43,  124,   45,   46,
   60,   94,   62,  126,   43,   38,   45,  104,  105,  126,
   64,   65,   93,   94,   95,  264,   61,  126,   61,   93,
   94,   61,   41,  126,   33,   44,   61,   61,   60,   38,
   61,  126,   41,   62,   43,   44,   45,  126,   61,   58,
   61,  124,   38,  124,   91,   41,   38,   61,   44,   58,
  124,   60,   61,   62,   63,   61,   61,   38,   60,   61,
   41,   33,   58,   44,   61,   60,   38,   63,   62,   41,
   43,   43,   44,   45,   93,  260,  264,   58,   41,   61,
  260,   61,   63,   44,   93,   94,   58,   41,   60,   61,
   62,   63,   41,  263,   92,  125,   55,   93,  100,   38,
  102,   94,   41,   56,   -1,   44,   57,   -1,   41,   -1,
   -1,   44,   93,   94,   -1,  124,   -1,   -1,   -1,   58,
   -1,   93,   94,   -1,   63,   58,   -1,   -1,  262,   -1,
   63,  265,  266,   -1,  257,  258,  259,   -1,  261,  262,
   -1,   -1,  265,  124,   -1,  262,   -1,   -1,  265,   -1,
   33,   -1,  124,  262,   93,   38,  265,   -1,   41,  262,
   93,   44,  265,   38,   -1,   -1,   41,  262,   -1,   44,
  265,   -1,   -1,  262,   -1,   58,  265,   60,   61,   62,
   63,   -1,  263,   58,   -1,  124,   -1,   33,   63,  263,
   -1,  124,   38,   -1,   -1,   41,   33,   -1,   44,   -1,
   -1,   38,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,
   93,   94,   58,   -1,   60,   61,   62,   63,   93,   -1,
   -1,   58,   -1,   60,   61,   62,   63,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   33,   -1,   -1,   -1,   33,   38,
   -1,  124,   41,   38,  263,   44,   41,   93,   94,   44,
   -1,   -1,   -1,   -1,  263,   -1,   93,   94,   -1,   58,
   -1,   -1,   61,   58,   63,   -1,   61,  263,   63,   -1,
   -1,   -1,   33,   -1,   -1,   -1,   -1,   38,  124,   -1,
   41,   33,  263,   44,   -1,   33,   38,  124,   -1,   41,
   38,  263,   44,   41,   93,   94,   44,   58,   93,   94,
   61,   38,   63,   -1,   41,   -1,   58,   44,   -1,   61,
   58,   63,   -1,   61,   -1,   63,   -1,   -1,   -1,   -1,
   -1,   58,   -1,   33,  263,  124,   63,   -1,   38,  124,
  263,   41,   93,   94,   44,   -1,   -1,   -1,   -1,   33,
   -1,   93,   94,   -1,   38,   93,   94,   41,   58,   33,
   44,   61,   -1,   63,   38,   -1,   93,   41,   -1,   -1,
   44,   -1,   -1,  124,   58,   38,   -1,   61,   41,   63,
   -1,   44,  124,   -1,   58,   41,  124,   61,   44,   63,
  263,    5,   -1,   93,   94,   58,   41,  124,  263,   44,
   63,   -1,   58,   -1,   -1,   -1,   -1,   63,   -1,   93,
   94,   41,   -1,   58,   44,   -1,   -1,   31,   63,   93,
   94,   35,   36,   -1,  124,   -1,   -1,  263,   58,   -1,
   93,   94,   -1,   63,   -1,   -1,  263,   93,   94,   -1,
  124,   37,   38,   -1,   -1,   -1,   42,   43,   93,   94,
  124,   47,   66,   67,   68,   -1,   -1,   -1,   -1,   -1,
   -1,  124,   -1,   93,   60,   61,   62,   -1,  124,   -1,
   -1,   -1,   -1,   -1,  263,   -1,   -1,   -1,  263,  124,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,   94,   95,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  263,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  263,   -1,  137,   -1,  263,   -1,   -1,  124,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  263,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  263,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  263,   -1,   -1,   -1,   -1,   -1,   -1,  263,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  263,
};
#define YYFINAL 14
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 266
#define YYUNDFTOKEN 291
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'","'.'","'/'",0,0,0,
0,0,0,0,0,0,0,"':'",0,"'<'","'='","'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"'['",0,"']'","'^'","'_'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,"'|'",0,"'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"integer_constant",
"character_constant","floating_constant","identifier","string","SIZEOF","EOC",
"type_name","primary_expression","assignment_expression_list",0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : CODE",
"CODE : primary_identifier EOC",
"expression : assignment_expression",
"expression : expression ',' assignment_expression",
"assignment_expression : conditional_expression",
"assignment_expression : unary_expression assignment_operator assignment_expression",
"assignment_operator : '='",
"assignment_operator : '*' '='",
"assignment_operator : '/' '='",
"assignment_operator : '%' '='",
"assignment_operator : '+' '='",
"assignment_operator : '_' '='",
"assignment_operator : '<' '<' '='",
"assignment_operator : '>' '>' '='",
"assignment_operator : '&' '='",
"assignment_operator : '^' '='",
"assignment_operator : '|' '='",
"conditional_expression : logical_OR_expression",
"conditional_expression : logical_OR_expression '?' expression ':' conditional_expression",
"constant_expression : conditional_expression",
"logical_OR_expression : logical_AND_expression",
"logical_OR_expression : logical_OR_expression '|' '|' logical_AND_expression",
"logical_AND_expression : inclusive_OR_expression",
"logical_AND_expression : logical_AND_expression '&' '&' inclusive_OR_expression",
"inclusive_OR_expression : exclusive_OR_expression",
"inclusive_OR_expression : inclusive_OR_expression '|' exclusive_OR_expression",
"exclusive_OR_expression : AND_expression",
"exclusive_OR_expression : exclusive_OR_expression '^' AND_expression",
"AND_expression : equality_expression",
"AND_expression : AND_expression '&' equality_expression",
"equality_expression : relational_expression",
"equality_expression : equality_expression '=' '=' relational_expression",
"equality_expression : equality_expression '!' '=' relational_expression",
"relational_expression : shift_expression",
"relational_expression : relational_expression '<' shift_expression",
"relational_expression : relational_expression '>' shift_expression",
"relational_expression : relational_expression '<' '=' shift_expression",
"relational_expression : relational_expression '>' '=' shift_expression",
"shift_expression : additive_expression",
"shift_expression : shift_expression '<' '<' additive_expression",
"shift_expression : shift_expression '>' '>' additive_expression",
"additive_expression : multiplicative_expression",
"additive_expression : additive_expression '+' multiplicative_expression",
"additive_expression : additive_expression '-' multiplicative_expression",
"multiplicative_expression : multiplicative_expression '*' cast_expression",
"multiplicative_expression : multiplicative_expression '/' cast_expression",
"multiplicative_expression : multiplicative_expression '%' cast_expression",
"cast_expression : unary_expression",
"cast_expression : '(' type_name ')' cast_expression",
"unary_expression : postfix_expression",
"unary_expression : '+' '+' unary_expression",
"unary_expression : '-' '-' unary_expression",
"unary_expression : unary_operator cast_expression",
"unary_expression : SIZEOF unary_expression",
"unary_expression : SIZEOF '(' type_name ')'",
"unary_operator : '&'",
"unary_operator : '*'",
"unary_operator : '+'",
"unary_operator : '-'",
"unary_operator : '~'",
"unary_operator : '!'",
"postfix_expression : primary_expression",
"postfix_expression : postfix_expression '[' expression ']'",
"postfix_expression : postfix_expression '(' argument_expression_list ')'",
"postfix_expression : postfix_expression '(' ')'",
"postfix_expression : postfix_expression '.' identifier",
"postfix_expression : postfix_expression '-' '>' identifier",
"postfix_expression : postfix_expression '+' '+'",
"postfix_expression : postfix_expression '-' '-'",
"primary_identifier : expression",
"primary_identifier : constant",
"primary_identifier : string",
"primary_identifier : '(' ')'",
"argument_expression_list : assignment_expression",
"argument_expression_list : assignment_expression_list ',' assignment_expression",
"constant : integer_constant",
"constant : character_constant",
"constant : floating_constant",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 142 "syntaxc.y"
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


#line 460 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 11 "syntaxc.y"
	{printf("Code Accepted\n");exit(0);}
break;
case 66:
#line 118 "syntaxc.y"
	{;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;}
break;
#line 670 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
