%{
// $Id: zu_parser.y,v 1.26 2016/05/20 12:44:37 ist178929 Exp $
//-- don't change *any* of these: if you do, you'll break the compiler.
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
//-- don't change *any* of these --- END!
%}

%union {
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
};

%token <i> tLINTEGER  
%token <d> tLREAL 
%token <s> tIDENTIFIER tLSTRING
%token tFOR tIF tPRINT tREAD tBEGIN tEND tBREAK tCONTINUE tRETURN tSTRING tINTEGER tAPPLY

%nonassoc tIFX
%nonassoc tELSE
%nonassoc tUNARY
%nonassoc '~' '#' '$'
%nonassoc '[' ']' '(' ')'


%right '=' '{' '?'
%left '&' '|' '%'
%left tEQ tNE
%left tGE tLE '>' '<'
%left '+' '-'
%left '*' '/'
 

//%type <node> stmt program
%type <s> litstring
%type <node> var cond iter decl instr block
%type <fdecl> funcdecl
%type <sequence> decls vars instrs exprs file fordecls
%type <expression> literal expr funcall
%type <type> type
%type <identifier> id
%type <lvalue> lval

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%


file : decls             { compiler->ast($1); }
     |                   { compiler->ast(new cdk::sequence_node(LINE, new cdk::nil_node(LINE))); }
     ;
     
decls : decl             { $$ = new cdk::sequence_node(LINE, $1); }
      | decls decl       { $$ = new cdk::sequence_node(LINE, $2, $1); }
      ;

decl : var ';'           { $$ = $1; }
     | funcdecl          { $$ = $1; }
     ;
    
     
var : type id '!' '=' expr    { $$ = new zu::variableDefinition_node(LINE, true, false, $1, $2, $5); }
    | type id '=' expr        { $$ = new zu::variableDefinition_node(LINE, false, false, $1, $2, $4); }
    | type id '?' '=' expr    { $$ = new zu::variableDefinition_node(LINE, false, true, $1, $2, $5); }
    | type id '!'             { $$ = new zu::variableDeclaration_node(LINE, true, false, $1, $2); }
    | type id                 { $$ = new zu::variableDeclaration_node(LINE, false, false, $1, $2); }
    | type id '?'             { $$ = new zu::variableDeclaration_node(LINE, false, true, $1, $2); }
    ;
       
funcdecl : type id '(' vars ')' {$$ = new zu::functionDeclaration_node(LINE, $1,false,false, $2, $4);}
         | type id '!' '(' vars ')' {$$ = new zu::functionDeclaration_node(LINE, $1,true, false, $2, $5);}
         | type id '?' '(' vars ')' {$$ = new zu::functionDeclaration_node(LINE, $1,false,true, $2, $5);}
         | type id '(' vars ')' '=' literal block {$$ = new zu::functionDefinition_node(LINE, $1,false,false, $2, $4, $7, $8);}
         | type id '!' '(' vars ')' '=' literal block {$$ = new zu::functionDefinition_node(LINE, $1,true,false, $2, $5, $8, $9);}
         | type id '?' '(' vars ')' '=' literal block {$$ = new zu::functionDefinition_node(LINE, $1,false,true, $2, $5, $8, $9);}
         | type id '(' vars ')' block {$$ = new zu::functionDefinition_node(LINE, $1,false,false, $2, $4, nullptr, $6);}
         | type id '!' '(' vars ')' block {$$ = new zu::functionDefinition_node(LINE, $1,true,false, $2, $5, nullptr, $7);}
         | type id '?' '(' vars ')' block {$$ = new zu::functionDefinition_node(LINE, $1,false,true, $2, $5, nullptr, $7);}
         ;

funcall : id '(' exprs ')' { $$ = new zu::funcall_node(LINE, $1, $3); }
        ;
        
	 
type : '<' tINTEGER '>' { $$ = new basic_type(4, basic_type::TYPE_INT); }
     | '<' '%' '>' { $$ = new basic_type(8, basic_type::TYPE_DOUBLE); }
     | '<' '$' '>' { $$ = new basic_type(4, basic_type::TYPE_STRING); }
     | tINTEGER    { $$ = new basic_type(4, basic_type::TYPE_INT); }
     | '%'         { $$ = new basic_type(8, basic_type::TYPE_DOUBLE); }
     | '!'         { $$ = new basic_type(0, basic_type::TYPE_VOID); }
     | tSTRING     { $$ = new basic_type(4, basic_type::TYPE_STRING); }
     ;
     
vars : var { $$ = new cdk::sequence_node(LINE, $1); }
     | vars ',' var { $$ = new cdk::sequence_node(LINE, $3, $1); }
     | {$$ = nullptr;}
     ;
     
literal : tLINTEGER { $$ = new cdk::integer_node(LINE, $1); }
        | tLREAL { $$ = new cdk::double_node(LINE, $1); }
        | litstring { $$ = new cdk::string_node(LINE, $1);}
        ;

litstring : tLSTRING { $$ = $1; }
          | litstring tLSTRING { $$ = new std::string(*$1 + *$2); }
          ;
     
block : '{' decls instrs '}' { $$ = new zu::block_node(LINE, $2, $3); }
      | '{' instrs '}' { $$ = new zu::block_node(LINE, nullptr, $2); }
      | '{' '}' { $$ = new zu::block_node(LINE, nullptr, nullptr); }
      ;
      
instrs : instr             { $$ = new cdk::sequence_node(LINE, $1); }
      | instrs instr       { $$ = new cdk::sequence_node(LINE, $2, $1); }
      ;
      
instr : expr ';' {$$ = new zu::evaluation_node(LINE ,$1); }
      | expr '!' { $$ = new zu::print_node(LINE, $1, false); }
      | expr tPRINT { $$ = new zu::print_node(LINE, $1, true); }
      | tBREAK { $$ = new zu::break_node(LINE); }
      | tCONTINUE { $$ = new zu::continue_node(LINE); }
      | tRETURN { $$ = new zu::return_node(LINE); }
      | cond { $$ = $1; }
      | iter { $$ = $1; }
      | block { $$ = $1; }
      ;

cond : '[' expr ']' '#' instr %prec tIFX { $$ = new zu::if_node(LINE, $2, $5); }
     | '[' expr ']' '?' instr %prec tIFX { $$ = new zu::if_node(LINE, $2, $5); }
     | '[' expr ']' '#' instr tELSE instr { $$ = new zu::if_else_node(LINE, $2, $5, $7); }
     | '[' expr ']' '?' instr tELSE instr { $$ = new zu::if_else_node(LINE, $2, $5, $7); }
     ;
     
fordecls : fordecls ',' var        { $$ = new cdk::sequence_node(LINE, $3, $1); }
         | fordecls ',' expr       { $$ = new cdk::sequence_node(LINE, $3, $1); }
         | var                     { $$ = new cdk::sequence_node(LINE, $1); }
         | expr                    { $$ = new cdk::sequence_node(LINE, $1); }
         |                         { $$ = nullptr;}
         ;

         
iter :  '[' fordecls ';' expr ';' expr ']' instr { $$ = new zu::for_node(LINE, $2, $4, $6, $8); }
     |  '[' fordecls ';' expr ';' ']' instr { $$ = new zu::for_node(LINE, $2, $4, nullptr, $7); }
     ;
     
exprs : expr             { $$ = new cdk::sequence_node(LINE, $1); }
      | exprs ',' expr   { $$ = new cdk::sequence_node(LINE, $3, $1); }
      |                  { $$ = nullptr;}
      ;
     
expr : lval                    { $$ = $1; }
     | literal                 { $$ = $1; }
     | '-' expr %prec tUNARY   { $$ = new cdk::neg_node(LINE, $2); }
     | '+' expr %prec tUNARY   { $$ = new zu::identity_node(LINE, $2); }
     | '~' expr %prec tUNARY   { $$ = new zu::not_node(LINE, $2); }
     | expr '+' expr	       { $$ = new cdk::add_node(LINE, $1, $3); }
     | expr '|' expr	       { $$ = new zu::or_node(LINE, $1, $3); }
     | expr '&' expr           { $$ = new zu::and_node(LINE, $1, $3); }
     | expr '-' expr	       { $$ = new cdk::sub_node(LINE, $1, $3); }
     | expr '*' expr	       { $$ = new cdk::mul_node(LINE, $1, $3); }
     | expr '/' expr	       { $$ = new cdk::div_node(LINE, $1, $3); }
     | expr '%' expr           { $$ = new cdk::mod_node(LINE, $1, $3); }
     | expr '<' expr	       { $$ = new cdk::lt_node(LINE, $1, $3); }
     | expr '>' expr	       { $$ = new cdk::gt_node(LINE, $1, $3); }
     | expr tGE expr	       { $$ = new cdk::ge_node(LINE, $1, $3); }
     | expr tLE expr           { $$ = new cdk::le_node(LINE, $1, $3); }
     | expr tNE expr	       { $$ = new cdk::ne_node(LINE, $1, $3); }
     | expr tEQ expr	       { $$ = new cdk::eq_node(LINE, $1, $3); }
     | '(' expr ')'            { $$ = $2; }
     | lval '=' expr           { $$ = new zu::assignment_node(LINE, $1, $3); }
     | '[' expr ']'            { $$ = new zu::memalloc_node(LINE, $2); }
     | expr '?'                { $$ = new zu::address_node(LINE, $1); }
     | funcall                 { $$ = $1; }
     ;

lval : id                { $$ = $1; }
     | lval '[' expr ']' { $$ = new zu::indexation_node(LINE, $1, $3); }
     | '(' expr ')' '[' expr ']' { $$ = new zu::indexation_node(LINE, $2, $5); }
     ;
  
id : tIDENTIFIER {$$ = new zu::zuidentifier_node(LINE, $1);}
   ;

%%