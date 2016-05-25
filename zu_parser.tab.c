/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20150711

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "zu_parser.y"
/* $Id: zu_parser.y,v 1.26 2016/05/20 12:44:37 ist178929 Exp $*/
/*-- don't change *any* of these: if you do, you'll break the compiler.*/
#include <cdk/compiler.h>
#include <cdk/basic_type.h>
#include <ast/lvalue_node.h>
#include <ast/zuidentifier_node.h>
#include "ast/all.h"

#define LINE       compiler->scanner()->lineno()
#define yylex()    compiler->scanner()->scan()
#define yyerror(s) compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
/*-- don't change *any* of these --- END!*/
#line 18 "zu_parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  int                   i;	/* integer value */
  double                d;
  std::string          *s;	/* symbol name or string literal */
  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  zu::functionDeclaration_node *fdecl;
  basic_type           *type;
  zu::zuidentifier_node  *identifier;
  zu::lvalue_node  *lvalue;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 62 "zu_parser.y"
/*-- The rules below will be included in yyparse, the main parsing function.*/
#line 58 "zu_parser.tab.c"

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

#define tLINTEGER 257
#define tLREAL 258
#define tIDENTIFIER 259
#define tLSTRING 260
#define tFOR 261
#define tIF 262
#define tPRINT 263
#define tREAD 264
#define tBEGIN 265
#define tEND 266
#define tBREAK 267
#define tCONTINUE 268
#define tRETURN 269
#define tSTRING 270
#define tINTEGER 271
#define tAPPLY 272
#define tIFX 273
#define tELSE 274
#define tUNARY 275
#define tEQ 276
#define tNE 277
#define tGE 278
#define tLE 279
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    9,    9,    5,    5,    2,    2,    2,    2,
    2,    2,    8,    8,    8,    8,    8,    8,    8,    8,
    8,   16,   17,   17,   17,   17,   17,   17,   17,   10,
   10,   10,   14,   14,   14,    1,    1,    7,    7,    7,
   11,   11,    6,    6,    6,    6,    6,    6,    6,    6,
    6,    3,    3,    3,    3,   13,   13,   13,   13,   13,
    4,    4,   12,   12,   12,   15,   15,   15,   15,   15,
   15,   15,   15,   15,   15,   15,   15,   15,   15,   15,
   15,   15,   15,   15,   15,   15,   15,   15,   19,   19,
   19,   18,
};
static const YYINT yylen[] = {                            2,
    1,    0,    1,    2,    2,    1,    5,    4,    5,    3,
    2,    3,    5,    6,    6,    8,    9,    9,    6,    7,
    7,    4,    3,    3,    3,    1,    1,    1,    1,    1,
    3,    0,    1,    1,    1,    1,    2,    4,    3,    2,
    1,    2,    2,    2,    2,    1,    1,    1,    1,    1,
    1,    5,    5,    7,    7,    3,    3,    1,    1,    0,
    8,    7,    1,    3,    0,    1,    1,    2,    2,    2,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    2,    1,    1,    4,
    6,    1,
};
static const YYINT yydefred[] = {                         0,
   29,   26,   27,    0,   28,    0,    0,    3,    6,    0,
    0,    0,    0,    0,    5,    4,   92,    0,   23,   25,
   24,    0,    0,    0,    0,   30,    0,    0,   33,   34,
   36,    0,    0,    0,    0,    0,    0,   67,    0,   88,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   37,   87,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   19,   31,
    0,    0,   86,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   75,   76,    0,    0,    0,
    0,    0,    0,    0,   46,   47,   48,    0,   40,   49,
   50,   41,   51,    0,    0,    0,    0,   22,    0,   90,
    0,   21,    0,   20,   16,   58,    0,    0,    0,   39,
   42,   45,   43,   44,    0,    0,    0,    0,    0,    0,
    0,   38,   91,   18,   17,    0,   56,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   62,    0,   54,
   55,   61,
};
static const YYINT yydgoto[] = {                          6,
   37,    7,  110,  111,    8,  112,  113,    9,   10,   27,
  115,   98,  127,   38,  116,   40,   28,   41,   42,
};
static const YYINT yysindex[] = {                       -30,
    0,    0,    0,  -32,    0,    0,  -41,    0,    0,  -30,
 -251,  -26,   69,   80,    0,    0,    0,    2,    0,    0,
    0,  -30,   54,   13,   56,    0,   15, -251,    0,    0,
    0,   54,   54,   54,   54,   54, -233,    0,  735,    0,
   88,   -9,  -30,   54,  -30,   54,  -55,  -30,  -18,  735,
  513,  579,  735,  735,    0,    0,   54,   54,   54,   54,
   54,   54,   54,   54,   54,   54,   54,   54,   54,   54,
   54,   54,   47,  735,   95,  735, -246,  773,    0,    0,
   57,   83,    0,   61,  -23,  -23,  -23,   87,   87,  293,
  293,  293,  293,   67,   67,    0,    0,  133,  735,  547,
  735,  -52,  -51,   44,    0,    0,    0,  828,    0,    0,
    0,    0,    0,  794,  800,  325,   54,    0,   54,    0,
 -246,    0, -246,    0,    0,    0,   -4,  616,  857,    0,
    0,    0,    0,    0,  652,  735,   44,   44,   54,  828,
  -35,    0,    0,    0,    0,  690,    0,  735,  954,  954,
  760, -109,  -96,  954,  724,  954,  954,    0,  954,    0,
    0,    0,
};
static const YYINT yyrindex[] = {                       183,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  205,
    0,    0,    0,    0,    0,    0,    0,  148,    0,    0,
    0,  144,    0,  161,  166,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   78,    0,  -28,    0,
   42,  113,  144,    0,  144,    0,    1,    0,  140,  120,
    0,    0,  156,  266,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  154,
    0,    0,    0,  173,    0,  175,    0,    0,    0,    0,
  222,  238,    0,  149,  846,  899,  912,  -12,  454,  336,
  373,  409,  445,  185,  289,    0,    0,    0,  180,    0,
  364,   17,   33,    0,    0,    0,    0,    5,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   51,    0,    0,
    0,    0,    0,    0,    0,  194,    0,    0,    0,    0,
  481,    0,    0,    0,    0,    0,    0,  104,    0,    0,
    0,  861,  948,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,  188,    0,    0,   -8,  713,   66,    0,  165,   55,
  132,    0,    0,  -54, 1119,    0,   48,   79,    0,
};
#define YYTABLESIZE 1270
static const YYINT yytable[] = {                        149,
   13,   16,    5,   13,   14,   77,    3,   17,  121,  123,
   29,   30,    8,   31,   82,    8,   15,   15,   68,   66,
   83,   67,  104,   69,   83,   83,   55,  150,   83,    4,
    8,   83,   14,   13,   25,   19,   65,   13,   64,  140,
   13,   22,   23,   13,   81,   13,   83,   11,   60,   15,
   83,   72,   43,   15,  139,   47,   15,   11,   48,   15,
   13,   15,   23,   60,   24,   14,  137,   78,  138,   14,
   78,   78,   14,   44,   89,   14,   15,   14,   89,   89,
   83,   71,   89,   89,   89,   89,   89,  102,   89,   18,
   48,   13,   14,   34,   59,   45,   35,   73,   36,   75,
   89,   89,   89,   89,   89,   16,   49,   15,   68,   59,
   35,   83,   79,   69,   35,   35,   46,   44,   35,   35,
   35,   35,   35,   14,   35,   11,   13,   70,   68,   66,
   20,   67,   89,   69,   89,  103,   35,   35,   48,   35,
   35,   21,   15,   46,   33,   66,   65,   57,   64,   66,
   66,  117,   70,   66,   66,   66,   66,   66,   14,   66,
   70,   11,   57,   70,  156,   89,   78,  122,  124,  125,
   35,   66,   66,  118,   66,   66,  119,  157,   70,   32,
   11,   84,    2,   11,   32,   84,   84,   32,   69,   84,
   84,   84,   84,   84,   65,   84,   69,   65,   11,   69,
   35,   35,  144,  145,    1,   66,   11,   84,   84,   26,
   84,   84,   70,    9,   69,    7,    9,   71,    7,   12,
   63,   71,   71,   63,   10,   71,    0,   71,   71,   71,
   26,    9,   26,    7,   64,   80,   66,   64,   12,    1,
    2,   84,  114,   71,   71,  129,   71,   71,   69,    0,
   83,    0,   60,   61,   62,   63,    0,   13,   13,   13,
   13,    0,   12,   83,   83,   12,    0,   13,   13,   13,
   13,   13,   84,   15,   15,   15,   15,   71,   10,    0,
   12,   10,    0,   15,   15,   15,   15,   15,    0,   14,
   14,   14,   14,    0,    0,  126,   10,    0,   68,   14,
   14,   14,   14,   14,   89,    0,   68,    0,   71,   68,
   29,   30,   17,   31,    0,    0,    0,   89,   89,   89,
   89,   74,    0,    0,   68,   74,   74,  147,    0,   74,
    0,   74,   74,   74,   68,   66,    0,   67,    0,   69,
   35,    0,    0,    0,    0,    0,    0,   74,   74,    0,
   74,   74,    0,   35,   35,   35,   35,  134,   68,    0,
    0,   59,   57,    0,   62,   63,   68,   66,   80,   67,
    0,   69,   80,   80,    0,   66,   80,    0,    0,   80,
    0,   74,   70,  133,   65,    0,   64,   56,   66,   66,
   66,   66,    0,    0,   80,   80,   85,   80,   80,    0,
    0,    0,    0,    0,   85,   81,    0,   85,    0,   81,
   81,   84,   74,   81,    0,    0,   81,    0,   69,    0,
    0,    0,   85,    0,   84,   84,   84,   84,   80,    0,
    0,   81,   81,    0,   81,   81,    0,    0,    0,    0,
    0,   79,    0,    0,    0,   79,   79,   71,   58,   79,
    0,    0,   79,    0,    0,    0,   85,    0,    0,   80,
   71,   71,   71,   71,    0,   81,    0,   79,   79,    0,
   79,   79,    0,    0,    0,    0,    0,   78,    0,    0,
    0,   78,   78,    0,    0,   78,   82,    0,   78,    0,
   82,   82,    0,    0,   82,    0,   81,   82,    0,    0,
    0,   79,    0,   78,   78,    0,   78,   78,    0,    0,
    0,    0,   82,   86,    0,    0,   82,   86,   86,    0,
    0,    0,   86,   86,    0,   86,    0,   86,   68,    0,
    0,    0,   79,    0,    0,    0,    0,   78,    0,   86,
   86,    0,   86,    0,    0,    0,   82,    0,    0,   59,
   57,   74,    0,    0,   68,   66,    0,   67,    0,   69,
    0,    0,    0,    0,   74,   74,   74,   74,   78,    0,
    0,    0,   65,    0,   64,   56,    0,   82,    0,    0,
    0,    0,    0,   59,   57,    0,    0,  132,   68,   66,
    0,   67,    0,   69,    0,    0,    0,    0,   80,    0,
   60,   61,   62,   63,   86,   83,   65,    0,   64,   56,
    0,   80,   80,   80,   80,   59,   57,    0,    0,   84,
   68,   66,    0,   67,    0,   69,   85,    0,    0,    0,
    0,    0,    0,    0,    0,   81,   58,    0,   65,  120,
   64,   56,    0,    0,    0,    0,    0,    0,   81,   81,
   81,   81,   59,   57,    0,    0,    0,   68,   66,    0,
   67,    0,   69,    0,    0,    0,    0,    0,    0,    0,
   58,   79,    0,    0,    0,   65,    0,   64,   56,    0,
    0,    0,    0,    0,   79,   79,   79,   79,   59,   57,
    0,    0,    0,   68,   66,    0,   67,    0,   69,    0,
    0,    0,   58,    0,    0,    0,    0,   78,  141,    0,
    0,   65,    0,   64,   56,    0,   82,    0,    0,    0,
   78,   78,   78,   78,    0,    0,   59,   57,    0,   82,
   82,   68,   66,    0,   67,    0,   69,    0,    0,   58,
    0,    0,    0,   86,  143,    0,    0,    0,  151,   65,
    0,   64,   56,    0,    0,    0,   86,   86,   86,   86,
   59,   57,    0,    0,    0,   68,   66,    0,   67,    0,
   69,   59,   57,    0,    0,   58,   68,   66,    0,   67,
    0,   69,    0,   65,    0,   64,   56,    0,   60,   61,
   62,   63,    0,    0,   65,    0,   64,   56,    0,   34,
    0,    0,   35,    0,   36,    5,    0,    0,    0,    3,
    0,    0,   34,   58,    0,   35,  159,   36,    0,    0,
    0,    0,   60,   61,   62,   63,    5,  131,    0,    0,
    3,    0,    4,   34,    0,    0,   35,    0,   36,   34,
    0,  131,   35,    0,   36,    0,    0,   58,    0,    0,
   33,    0,  154,    4,   60,   61,   62,   63,   58,    0,
    5,  152,  153,  108,    3,    0,  158,   34,  160,  161,
   35,  162,   36,    0,    0,    0,    0,    0,   73,    0,
    0,    0,   73,   73,  108,   32,   73,    4,    0,   73,
  108,   60,   61,   62,   63,   78,   34,  109,   32,   35,
   52,   36,    0,   52,   73,   52,    0,    0,   73,    0,
    0,    0,    0,    0,    0,    0,   78,    0,   33,   32,
    0,    0,   78,    0,  130,   32,    0,   60,   61,   62,
   63,   72,    0,    0,    0,   72,   72,    0,   73,   72,
    0,    0,   72,    0,   77,    0,    0,  108,   77,   77,
    0,   52,   77,   32,    0,   77,    0,   72,    0,    0,
    0,   72,    0,    0,    0,   60,   61,   62,   63,   73,
   77,    0,    0,    0,   77,    0,    0,    0,    0,   78,
    0,  142,   32,   52,    0,   52,   52,   53,    0,    0,
   53,   72,   53,   34,    0,    0,   35,    0,   36,   60,
   61,   62,   63,    0,   77,    0,    0,    0,    0,    0,
   60,   61,   62,   63,    0,    0,   29,   30,   17,   31,
    0,    0,   72,    0,    0,    0,    0,    0,    0,   29,
   30,   17,   31,    0,    0,   77,    0,    0,   53,  105,
  106,  107,    1,    2,  108,    0,    0,    0,    0,    0,
   29,   30,   17,   31,    0,    0,   29,   30,   17,   31,
  105,  106,  107,    1,    2,    0,  105,  106,  107,    0,
   53,    0,   53,   53,    0,    0,   78,    0,    0,   32,
    0,    0,    0,    0,   29,   30,   17,   31,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    1,    2,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   73,    0,
    0,    0,    0,   29,   30,   17,   31,   52,   52,   52,
   52,    0,    0,  105,  106,  107,    0,   52,   52,   52,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   39,    0,    0,    0,    0,    0,    0,    0,    0,
   50,   51,   52,   53,   54,    0,    0,    0,    0,    0,
    0,   72,   74,    0,   76,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   77,   85,   86,   87,   88,   89,
   90,   91,   92,   93,   94,   95,   96,   97,   99,  100,
  101,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   53,   53,   53,   53,    0,    0,
   29,   30,   17,   31,   53,   53,   53,    0,    0,    0,
  105,  106,  107,    0,    0,    0,  128,    0,    0,    0,
    0,    0,    0,    0,    0,  135,    0,  136,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  146,  148,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  155,
};
static const YYINT yycheck[] = {                         35,
    0,   10,   33,   36,   37,   61,   37,  259,   61,   61,
  257,  258,   41,  260,   33,   44,    0,   59,   42,   43,
   33,   45,   77,   47,   37,   38,  260,   63,   41,   60,
   59,   44,    0,   33,   33,   62,   60,   37,   62,   44,
   40,   40,   61,   43,   63,   45,   59,    0,   44,   33,
   63,   61,   40,   37,   59,   41,   40,   10,   44,   43,
   60,   45,   61,   59,   63,   33,  121,  123,  123,   37,
  123,  123,   40,   61,   33,   43,   60,   45,   37,   38,
   93,   91,   41,   42,   43,   44,   45,   41,   47,   11,
   44,   91,   60,   40,   44,   40,   43,   43,   45,   45,
   59,   60,   61,   62,   63,  114,   28,   91,   42,   59,
   33,  124,   47,   47,   37,   38,   61,   61,   41,   42,
   43,   44,   45,   91,   47,   78,  126,   40,   42,   43,
   62,   45,   91,   47,   93,   41,   59,   60,   44,   62,
   63,   62,  126,   61,   91,   33,   60,   44,   62,   37,
   38,   91,   33,   41,   42,   43,   44,   45,  126,   47,
   41,  114,   59,   44,  274,  124,  123,  102,  103,  104,
   93,   59,   60,   41,   62,   63,   44,  274,   59,  126,
   41,   33,    0,   44,   41,   37,   38,   44,   33,   41,
   42,   43,   44,   45,   41,   47,   41,   44,   59,   44,
  123,  124,  137,  138,    0,   93,   59,   59,   60,   22,
   62,   63,   93,   41,   59,   41,   44,   33,   44,   59,
   41,   37,   38,   44,   59,   41,   -1,   43,   44,   45,
   43,   59,   45,   59,   41,   48,  124,   44,  271,  270,
  271,   93,   78,   59,   60,  114,   62,   63,   93,   -1,
  263,   -1,  276,  277,  278,  279,   -1,  257,  258,  259,
  260,   -1,   41,  276,  277,   44,   -1,  267,  268,  269,
  270,  271,  124,  257,  258,  259,  260,   93,   41,   -1,
   59,   44,   -1,  267,  268,  269,  270,  271,   -1,  257,
  258,  259,  260,   -1,   -1,  108,   59,   -1,   33,  267,
  268,  269,  270,  271,  263,   -1,   41,   -1,  124,   44,
  257,  258,  259,  260,   -1,   -1,   -1,  276,  277,  278,
  279,   33,   -1,   -1,   59,   37,   38,  140,   -1,   41,
   -1,   43,   44,   45,   42,   43,   -1,   45,   -1,   47,
  263,   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,   -1,
   62,   63,   -1,  276,  277,  278,  279,   33,   93,   -1,
   -1,   37,   38,   -1,  278,  279,   42,   43,   33,   45,
   -1,   47,   37,   38,   -1,  263,   41,   -1,   -1,   44,
   -1,   93,  263,   59,   60,   -1,   62,   63,  276,  277,
  278,  279,   -1,   -1,   59,   60,   33,   62,   63,   -1,
   -1,   -1,   -1,   -1,   41,   33,   -1,   44,   -1,   37,
   38,  263,  124,   41,   -1,   -1,   44,   -1,  263,   -1,
   -1,   -1,   59,   -1,  276,  277,  278,  279,   93,   -1,
   -1,   59,   60,   -1,   62,   63,   -1,   -1,   -1,   -1,
   -1,   33,   -1,   -1,   -1,   37,   38,  263,  124,   41,
   -1,   -1,   44,   -1,   -1,   -1,   93,   -1,   -1,  124,
  276,  277,  278,  279,   -1,   93,   -1,   59,   60,   -1,
   62,   63,   -1,   -1,   -1,   -1,   -1,   33,   -1,   -1,
   -1,   37,   38,   -1,   -1,   41,   33,   -1,   44,   -1,
   37,   38,   -1,   -1,   41,   -1,  124,   44,   -1,   -1,
   -1,   93,   -1,   59,   60,   -1,   62,   63,   -1,   -1,
   -1,   -1,   59,   33,   -1,   -1,   63,   37,   38,   -1,
   -1,   -1,   42,   43,   -1,   45,   -1,   47,  263,   -1,
   -1,   -1,  124,   -1,   -1,   -1,   -1,   93,   -1,   59,
   60,   -1,   62,   -1,   -1,   -1,   93,   -1,   -1,   37,
   38,  263,   -1,   -1,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   -1,   -1,  276,  277,  278,  279,  124,   -1,
   -1,   -1,   60,   -1,   62,   63,   -1,  124,   -1,   -1,
   -1,   -1,   -1,   37,   38,   -1,   -1,  263,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,  263,   -1,
  276,  277,  278,  279,  124,   93,   60,   -1,   62,   63,
   -1,  276,  277,  278,  279,   37,   38,   -1,   -1,   41,
   42,   43,   -1,   45,   -1,   47,  263,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  263,  124,   -1,   60,   93,
   62,   63,   -1,   -1,   -1,   -1,   -1,   -1,  276,  277,
  278,  279,   37,   38,   -1,   -1,   -1,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  124,  263,   -1,   -1,   -1,   60,   -1,   62,   63,   -1,
   -1,   -1,   -1,   -1,  276,  277,  278,  279,   37,   38,
   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,  124,   -1,   -1,   -1,   -1,  263,   93,   -1,
   -1,   60,   -1,   62,   63,   -1,  263,   -1,   -1,   -1,
  276,  277,  278,  279,   -1,   -1,   37,   38,   -1,  276,
  277,   42,   43,   -1,   45,   -1,   47,   -1,   -1,  124,
   -1,   -1,   -1,  263,   93,   -1,   -1,   -1,   59,   60,
   -1,   62,   63,   -1,   -1,   -1,  276,  277,  278,  279,
   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,
   47,   37,   38,   -1,   -1,  124,   42,   43,   -1,   45,
   -1,   47,   -1,   60,   -1,   62,   63,   -1,  276,  277,
  278,  279,   -1,   -1,   60,   -1,   62,   63,   -1,   40,
   -1,   -1,   43,   -1,   45,   33,   -1,   -1,   -1,   37,
   -1,   -1,   40,  124,   -1,   43,   93,   45,   -1,   -1,
   -1,   -1,  276,  277,  278,  279,   33,  115,   -1,   -1,
   37,   -1,   60,   40,   -1,   -1,   43,   -1,   45,   40,
   -1,  129,   43,   -1,   45,   -1,   -1,  124,   -1,   -1,
   91,   -1,   93,   60,  276,  277,  278,  279,  124,   -1,
   33,  149,  150,   91,   37,   -1,  154,   40,  156,  157,
   43,  159,   45,   -1,   -1,   -1,   -1,   -1,   33,   -1,
   -1,   -1,   37,   38,   91,  126,   41,   60,   -1,   44,
   91,  276,  277,  278,  279,  123,   40,  125,  126,   43,
   40,   45,   -1,   43,   59,   45,   -1,   -1,   63,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,   91,  126,
   -1,   -1,  123,   -1,  125,  126,   -1,  276,  277,  278,
  279,   33,   -1,   -1,   -1,   37,   38,   -1,   93,   41,
   -1,   -1,   44,   -1,   33,   -1,   -1,   91,   37,   38,
   -1,   91,   41,  126,   -1,   44,   -1,   59,   -1,   -1,
   -1,   63,   -1,   -1,   -1,  276,  277,  278,  279,  124,
   59,   -1,   -1,   -1,   63,   -1,   -1,   -1,   -1,  123,
   -1,  125,  126,  123,   -1,  125,  126,   40,   -1,   -1,
   43,   93,   45,   40,   -1,   -1,   43,   -1,   45,  276,
  277,  278,  279,   -1,   93,   -1,   -1,   -1,   -1,   -1,
  276,  277,  278,  279,   -1,   -1,  257,  258,  259,  260,
   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,  257,
  258,  259,  260,   -1,   -1,  124,   -1,   -1,   91,  267,
  268,  269,  270,  271,   91,   -1,   -1,   -1,   -1,   -1,
  257,  258,  259,  260,   -1,   -1,  257,  258,  259,  260,
  267,  268,  269,  270,  271,   -1,  267,  268,  269,   -1,
  123,   -1,  125,  126,   -1,   -1,  123,   -1,   -1,  126,
   -1,   -1,   -1,   -1,  257,  258,  259,  260,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  270,  271,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,   -1,
   -1,   -1,   -1,  257,  258,  259,  260,  257,  258,  259,
  260,   -1,   -1,  267,  268,  269,   -1,  267,  268,  269,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   23,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   32,   33,   34,   35,   36,   -1,   -1,   -1,   -1,   -1,
   -1,  263,   44,   -1,   46,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  263,   57,   58,   59,   60,   61,
   62,   63,   64,   65,   66,   67,   68,   69,   70,   71,
   72,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,  259,  260,   -1,   -1,
  257,  258,  259,  260,  267,  268,  269,   -1,   -1,   -1,
  267,  268,  269,   -1,   -1,   -1,  108,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  117,   -1,  119,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  139,  140,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  151,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 279
#define YYUNDFTOKEN 301
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'","'$'","'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,
0,0,0,0,0,0,0,0,0,0,"';'","'<'","'='","'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"tLINTEGER",
"tLREAL","tIDENTIFIER","tLSTRING","tFOR","tIF","tPRINT","tREAD","tBEGIN","tEND",
"tBREAK","tCONTINUE","tRETURN","tSTRING","tINTEGER","tAPPLY","tIFX","tELSE",
"tUNARY","tEQ","tNE","tGE","tLE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file : decls",
"file :",
"decls : decl",
"decls : decls decl",
"decl : var ';'",
"decl : funcdecl",
"var : type id '!' '=' expr",
"var : type id '=' expr",
"var : type id '?' '=' expr",
"var : type id '!'",
"var : type id",
"var : type id '?'",
"funcdecl : type id '(' vars ')'",
"funcdecl : type id '!' '(' vars ')'",
"funcdecl : type id '?' '(' vars ')'",
"funcdecl : type id '(' vars ')' '=' literal block",
"funcdecl : type id '!' '(' vars ')' '=' literal block",
"funcdecl : type id '?' '(' vars ')' '=' literal block",
"funcdecl : type id '(' vars ')' block",
"funcdecl : type id '!' '(' vars ')' block",
"funcdecl : type id '?' '(' vars ')' block",
"funcall : id '(' exprs ')'",
"type : '<' tINTEGER '>'",
"type : '<' '%' '>'",
"type : '<' '$' '>'",
"type : tINTEGER",
"type : '%'",
"type : '!'",
"type : tSTRING",
"vars : var",
"vars : vars ',' var",
"vars :",
"literal : tLINTEGER",
"literal : tLREAL",
"literal : litstring",
"litstring : tLSTRING",
"litstring : litstring tLSTRING",
"block : '{' decls instrs '}'",
"block : '{' instrs '}'",
"block : '{' '}'",
"instrs : instr",
"instrs : instrs instr",
"instr : expr ';'",
"instr : expr '!'",
"instr : expr tPRINT",
"instr : tBREAK",
"instr : tCONTINUE",
"instr : tRETURN",
"instr : cond",
"instr : iter",
"instr : block",
"cond : '[' expr ']' '#' instr",
"cond : '[' expr ']' '?' instr",
"cond : '[' expr ']' '#' instr tELSE instr",
"cond : '[' expr ']' '?' instr tELSE instr",
"fordecls : fordecls ',' var",
"fordecls : fordecls ',' expr",
"fordecls : var",
"fordecls : expr",
"fordecls :",
"iter : '[' fordecls ';' expr ';' expr ']' instr",
"iter : '[' fordecls ';' expr ';' ']' instr",
"exprs : expr",
"exprs : exprs ',' expr",
"exprs :",
"expr : lval",
"expr : literal",
"expr : '-' expr",
"expr : '+' expr",
"expr : '~' expr",
"expr : expr '+' expr",
"expr : expr '|' expr",
"expr : expr '&' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr tGE expr",
"expr : expr tLE expr",
"expr : expr tNE expr",
"expr : expr tEQ expr",
"expr : '(' expr ')'",
"expr : lval '=' expr",
"expr : '[' expr ']'",
"expr : expr '?'",
"expr : funcall",
"lval : id",
"lval : lval '[' expr ']'",
"lval : '(' expr ')' '[' expr ']'",
"id : tIDENTIFIER",

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
#line 67 "zu_parser.y"
	{ compiler->ast(yystack.l_mark[0].sequence); }
break;
case 2:
#line 68 "zu_parser.y"
	{ compiler->ast(new cdk::sequence_node(LINE, new cdk::nil_node(LINE))); }
break;
case 3:
#line 71 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 4:
#line 72 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-1].sequence); }
break;
case 5:
#line 75 "zu_parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 6:
#line 76 "zu_parser.y"
	{ yyval.node = yystack.l_mark[0].fdecl; }
break;
case 7:
#line 80 "zu_parser.y"
	{ yyval.node = new zu::variableDefinition_node(LINE, true, false, yystack.l_mark[-4].type, yystack.l_mark[-3].identifier, yystack.l_mark[0].expression); }
break;
case 8:
#line 81 "zu_parser.y"
	{ yyval.node = new zu::variableDefinition_node(LINE, false, false, yystack.l_mark[-3].type, yystack.l_mark[-2].identifier, yystack.l_mark[0].expression); }
break;
case 9:
#line 82 "zu_parser.y"
	{ yyval.node = new zu::variableDefinition_node(LINE, false, true, yystack.l_mark[-4].type, yystack.l_mark[-3].identifier, yystack.l_mark[0].expression); }
break;
case 10:
#line 83 "zu_parser.y"
	{ yyval.node = new zu::variableDeclaration_node(LINE, true, false, yystack.l_mark[-2].type, yystack.l_mark[-1].identifier); }
break;
case 11:
#line 84 "zu_parser.y"
	{ yyval.node = new zu::variableDeclaration_node(LINE, false, false, yystack.l_mark[-1].type, yystack.l_mark[0].identifier); }
break;
case 12:
#line 85 "zu_parser.y"
	{ yyval.node = new zu::variableDeclaration_node(LINE, false, true, yystack.l_mark[-2].type, yystack.l_mark[-1].identifier); }
break;
case 13:
#line 88 "zu_parser.y"
	{yyval.fdecl = new zu::functionDeclaration_node(LINE, yystack.l_mark[-4].type,false,false, yystack.l_mark[-3].identifier, yystack.l_mark[-1].sequence);}
break;
case 14:
#line 89 "zu_parser.y"
	{yyval.fdecl = new zu::functionDeclaration_node(LINE, yystack.l_mark[-5].type,true, false, yystack.l_mark[-4].identifier, yystack.l_mark[-1].sequence);}
break;
case 15:
#line 90 "zu_parser.y"
	{yyval.fdecl = new zu::functionDeclaration_node(LINE, yystack.l_mark[-5].type,false,true, yystack.l_mark[-4].identifier, yystack.l_mark[-1].sequence);}
break;
case 16:
#line 91 "zu_parser.y"
	{yyval.fdecl = new zu::functionDefinition_node(LINE, yystack.l_mark[-7].type,false,false, yystack.l_mark[-6].identifier, yystack.l_mark[-4].sequence, yystack.l_mark[-1].expression, yystack.l_mark[0].node);}
break;
case 17:
#line 92 "zu_parser.y"
	{yyval.fdecl = new zu::functionDefinition_node(LINE, yystack.l_mark[-8].type,true,false, yystack.l_mark[-7].identifier, yystack.l_mark[-4].sequence, yystack.l_mark[-1].expression, yystack.l_mark[0].node);}
break;
case 18:
#line 93 "zu_parser.y"
	{yyval.fdecl = new zu::functionDefinition_node(LINE, yystack.l_mark[-8].type,false,true, yystack.l_mark[-7].identifier, yystack.l_mark[-4].sequence, yystack.l_mark[-1].expression, yystack.l_mark[0].node);}
break;
case 19:
#line 94 "zu_parser.y"
	{yyval.fdecl = new zu::functionDefinition_node(LINE, yystack.l_mark[-5].type,false,false, yystack.l_mark[-4].identifier, yystack.l_mark[-2].sequence, nullptr, yystack.l_mark[0].node);}
break;
case 20:
#line 95 "zu_parser.y"
	{yyval.fdecl = new zu::functionDefinition_node(LINE, yystack.l_mark[-6].type,true,false, yystack.l_mark[-5].identifier, yystack.l_mark[-2].sequence, nullptr, yystack.l_mark[0].node);}
break;
case 21:
#line 96 "zu_parser.y"
	{yyval.fdecl = new zu::functionDefinition_node(LINE, yystack.l_mark[-6].type,false,true, yystack.l_mark[-5].identifier, yystack.l_mark[-2].sequence, nullptr, yystack.l_mark[0].node);}
break;
case 22:
#line 99 "zu_parser.y"
	{ yyval.expression = new zu::funcall_node(LINE, yystack.l_mark[-3].identifier, yystack.l_mark[-1].sequence); }
break;
case 23:
#line 103 "zu_parser.y"
	{ yyval.type = new basic_type(4, basic_type::TYPE_INT); }
break;
case 24:
#line 104 "zu_parser.y"
	{ yyval.type = new basic_type(8, basic_type::TYPE_DOUBLE); }
break;
case 25:
#line 105 "zu_parser.y"
	{ yyval.type = new basic_type(4, basic_type::TYPE_STRING); }
break;
case 26:
#line 106 "zu_parser.y"
	{ yyval.type = new basic_type(4, basic_type::TYPE_INT); }
break;
case 27:
#line 107 "zu_parser.y"
	{ yyval.type = new basic_type(8, basic_type::TYPE_DOUBLE); }
break;
case 28:
#line 108 "zu_parser.y"
	{ yyval.type = new basic_type(0, basic_type::TYPE_VOID); }
break;
case 29:
#line 109 "zu_parser.y"
	{ yyval.type = new basic_type(4, basic_type::TYPE_STRING); }
break;
case 30:
#line 112 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 31:
#line 113 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-2].sequence); }
break;
case 32:
#line 114 "zu_parser.y"
	{yyval.sequence = nullptr;}
break;
case 33:
#line 117 "zu_parser.y"
	{ yyval.expression = new cdk::integer_node(LINE, yystack.l_mark[0].i); }
break;
case 34:
#line 118 "zu_parser.y"
	{ yyval.expression = new cdk::double_node(LINE, yystack.l_mark[0].d); }
break;
case 35:
#line 119 "zu_parser.y"
	{ yyval.expression = new cdk::string_node(LINE, yystack.l_mark[0].s);}
break;
case 36:
#line 122 "zu_parser.y"
	{ yyval.s = yystack.l_mark[0].s; }
break;
case 37:
#line 123 "zu_parser.y"
	{ yyval.s = new std::string(*yystack.l_mark[-1].s + *yystack.l_mark[0].s); }
break;
case 38:
#line 126 "zu_parser.y"
	{ yyval.node = new zu::block_node(LINE, yystack.l_mark[-2].sequence, yystack.l_mark[-1].sequence); }
break;
case 39:
#line 127 "zu_parser.y"
	{ yyval.node = new zu::block_node(LINE, nullptr, yystack.l_mark[-1].sequence); }
break;
case 40:
#line 128 "zu_parser.y"
	{ yyval.node = new zu::block_node(LINE, nullptr, nullptr); }
break;
case 41:
#line 131 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 42:
#line 132 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-1].sequence); }
break;
case 43:
#line 135 "zu_parser.y"
	{yyval.node = new zu::evaluation_node(LINE ,yystack.l_mark[-1].expression); }
break;
case 44:
#line 136 "zu_parser.y"
	{ yyval.node = new zu::print_node(LINE, yystack.l_mark[-1].expression, false); }
break;
case 45:
#line 137 "zu_parser.y"
	{ yyval.node = new zu::print_node(LINE, yystack.l_mark[-1].expression, true); }
break;
case 46:
#line 138 "zu_parser.y"
	{ yyval.node = new zu::break_node(LINE); }
break;
case 47:
#line 139 "zu_parser.y"
	{ yyval.node = new zu::continue_node(LINE); }
break;
case 48:
#line 140 "zu_parser.y"
	{ yyval.node = new zu::return_node(LINE); }
break;
case 49:
#line 141 "zu_parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 50:
#line 142 "zu_parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 51:
#line 143 "zu_parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 52:
#line 146 "zu_parser.y"
	{ yyval.node = new zu::if_node(LINE, yystack.l_mark[-3].expression, yystack.l_mark[0].node); }
break;
case 53:
#line 147 "zu_parser.y"
	{ yyval.node = new zu::if_node(LINE, yystack.l_mark[-3].expression, yystack.l_mark[0].node); }
break;
case 54:
#line 148 "zu_parser.y"
	{ yyval.node = new zu::if_else_node(LINE, yystack.l_mark[-5].expression, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 55:
#line 149 "zu_parser.y"
	{ yyval.node = new zu::if_else_node(LINE, yystack.l_mark[-5].expression, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 56:
#line 152 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-2].sequence); }
break;
case 57:
#line 153 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression, yystack.l_mark[-2].sequence); }
break;
case 58:
#line 154 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 59:
#line 155 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression); }
break;
case 60:
#line 156 "zu_parser.y"
	{ yyval.sequence = nullptr;}
break;
case 61:
#line 160 "zu_parser.y"
	{ yyval.node = new zu::for_node(LINE, yystack.l_mark[-6].sequence, yystack.l_mark[-4].expression, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 62:
#line 161 "zu_parser.y"
	{ yyval.node = new zu::for_node(LINE, yystack.l_mark[-5].sequence, yystack.l_mark[-3].expression, nullptr, yystack.l_mark[0].node); }
break;
case 63:
#line 164 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression); }
break;
case 64:
#line 165 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression, yystack.l_mark[-2].sequence); }
break;
case 65:
#line 166 "zu_parser.y"
	{ yyval.sequence = nullptr;}
break;
case 66:
#line 169 "zu_parser.y"
	{ yyval.expression = yystack.l_mark[0].lvalue; }
break;
case 67:
#line 170 "zu_parser.y"
	{ yyval.expression = yystack.l_mark[0].expression; }
break;
case 68:
#line 171 "zu_parser.y"
	{ yyval.expression = new cdk::neg_node(LINE, yystack.l_mark[0].expression); }
break;
case 69:
#line 172 "zu_parser.y"
	{ yyval.expression = new zu::identity_node(LINE, yystack.l_mark[0].expression); }
break;
case 70:
#line 173 "zu_parser.y"
	{ yyval.expression = new zu::not_node(LINE, yystack.l_mark[0].expression); }
break;
case 71:
#line 174 "zu_parser.y"
	{ yyval.expression = new cdk::add_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 72:
#line 175 "zu_parser.y"
	{ yyval.expression = new zu::or_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 73:
#line 176 "zu_parser.y"
	{ yyval.expression = new zu::and_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 74:
#line 177 "zu_parser.y"
	{ yyval.expression = new cdk::sub_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 75:
#line 178 "zu_parser.y"
	{ yyval.expression = new cdk::mul_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 76:
#line 179 "zu_parser.y"
	{ yyval.expression = new cdk::div_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 77:
#line 180 "zu_parser.y"
	{ yyval.expression = new cdk::mod_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 78:
#line 181 "zu_parser.y"
	{ yyval.expression = new cdk::lt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 79:
#line 182 "zu_parser.y"
	{ yyval.expression = new cdk::gt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 80:
#line 183 "zu_parser.y"
	{ yyval.expression = new cdk::ge_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 81:
#line 184 "zu_parser.y"
	{ yyval.expression = new cdk::le_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 82:
#line 185 "zu_parser.y"
	{ yyval.expression = new cdk::ne_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 83:
#line 186 "zu_parser.y"
	{ yyval.expression = new cdk::eq_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 84:
#line 187 "zu_parser.y"
	{ yyval.expression = yystack.l_mark[-1].expression; }
break;
case 85:
#line 188 "zu_parser.y"
	{ yyval.expression = new zu::assignment_node(LINE, yystack.l_mark[-2].lvalue, yystack.l_mark[0].expression); }
break;
case 86:
#line 189 "zu_parser.y"
	{ yyval.expression = new zu::memalloc_node(LINE, yystack.l_mark[-1].expression); }
break;
case 87:
#line 190 "zu_parser.y"
	{ yyval.expression = new zu::address_node(LINE, yystack.l_mark[-1].expression); }
break;
case 88:
#line 191 "zu_parser.y"
	{ yyval.expression = yystack.l_mark[0].expression; }
break;
case 89:
#line 194 "zu_parser.y"
	{ yyval.lvalue = yystack.l_mark[0].identifier; }
break;
case 90:
#line 195 "zu_parser.y"
	{ yyval.lvalue = new zu::indexation_node(LINE, yystack.l_mark[-3].lvalue, yystack.l_mark[-1].expression); }
break;
case 91:
#line 196 "zu_parser.y"
	{ yyval.lvalue = new zu::indexation_node(LINE, yystack.l_mark[-4].expression, yystack.l_mark[-1].expression); }
break;
case 92:
#line 199 "zu_parser.y"
	{yyval.identifier = new zu::zuidentifier_node(LINE, yystack.l_mark[0].s);}
break;
#line 1187 "zu_parser.tab.c"
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
