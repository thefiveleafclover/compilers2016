%option c++ yyclass="zu_scanner" outfile="zu_scanner.cpp"
%option debug warn stack noyywrap yylineno 8bit
%{ 
/* $Id: zu_scanner.l,v 1.16 2016/05/18 19:38:01 ist178929 Exp $ */
// make relevant includes before including the parser's tab file
#include <string>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include "zu_scanner.h"
#include "zu_parser.tab.h"

// don't change this
#define yyerror LexerError
%}
ALPHA                  [a-zA-Z]
ALNUM                  [0-9]|{ALPHA}
DIG_HEX                [0-9a-fA-F]

ID                     ({ALPHA}|_)({ALNUM}|_)*
WHITESPACE             [ \t\r\n]
INT_DEC                0|([1-9][0-9]*)
INT_HEX                0x{DIG_HEX}+
REAL_1                 [0-9]+\.[0-9]*([eE][0-9]+)?
REAL_2                 [0-9]*\.[0-9]+([eE][0-9]+)?
REAL                   {REAL_1}|{REAL_2}

%x X_STRING X_NULL_STRING X_SPECIAL_CHAR X_COMMENT
%%
    { set_debug(1); }

">="                   return tGE; 
"<="                   return tLE; 
"=="                   return tEQ; 
"!="                   return tNE;

"for"                  return tFOR;
"apply"                  return tAPPLY;
"if"                   return tIF; 
":"                    return tELSE; 

"@"                    return tREAD;
"!!"                   return tPRINT; 
"!!!"                  return tRETURN;
"><"                   return tBREAK;
"<>"                   return tCONTINUE;
"#"                    return tINTEGER;
"$"                    return tSTRING;

{ID}                   yylval.s = new std::string(yytext); return tIDENTIFIER;

{INT_HEX}              { yylval.i = strtol(yytext, nullptr,16); return tLINTEGER; }
{INT_DEC}              { yylval.i = strtol(yytext, nullptr,10); return tLINTEGER; }
[0-9]+                 yyerror("Invalid number");

{REAL}                 { yylval.d = strtod(yytext, nullptr); return tLREAL; }


\"                     yy_push_state(X_STRING); yylval.s = new std::string("");
<X_STRING>\"           yy_pop_state(); return tLSTRING;
<X_STRING>\\\"         *yylval.s += yytext + 1;
<X_STRING>\\           yy_push_state(X_SPECIAL_CHAR);
<X_STRING>.            *yylval.s += yytext;
<X_STRING>\n           yyerror("newline in string");

"/*"                   yy_push_state(X_COMMENT);
<X_COMMENT>"/*"        yy_push_state(X_COMMENT);
<X_COMMENT>"*/"        yy_pop_state();
<X_COMMENT>.|\n        ;

"//".*$                ;

<X_SPECIAL_CHAR>{DIG_HEX}{DIG_HEX}          yy_pop_state(); *yylval.s += std::string(1, strtol(yytext, nullptr, 16));
<X_SPECIAL_CHAR>0      yy_pop_state(); yy_push_state(X_NULL_STRING);
<X_SPECIAL_CHAR>n      yy_pop_state(); *yylval.s += std::string(1,10);
<X_SPECIAL_CHAR>r      yy_pop_state(); *yylval.s += std::string(1,13);
<X_SPECIAL_CHAR>t      yy_pop_state(); *yylval.s += std::string(1,9);
<X_SPECIAL_CHAR>.|\n   yyerror("Invalid special character");

<X_NULL_STRING>\"      yy_pop_state(); yy_pop_state();
<X_NULL_STRING>.       ;

[-()<>=+*/%&|,;:{}?@!#$~]      return *yytext;
\]                              return *yytext;
\[                              return *yytext;

{WHITESPACE}+           ; /* ignore whitespace */

.                      yyerror("Unknown character");

%%
// Very, very dirty hack: flex is a mess generating C++ scanners.
int zu_scanner::yywrap() { return 1; } 
