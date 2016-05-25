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
extern YYSTYPE yylval;
