//Alexander Soe
//asoe
//Ashley Lavizadeh
//alavizad


%{
// $Id: parser.y,v 1.21 2019-04-15 15:41:31-07 - - $
// Dummy parser for scanner project.

#include <cassert>

#include "lyutils.h"
#include "astree.h"

%}

%debug
%defines
%error-verbose
%token-table
%verbose

%token  ROOT IDENT NUMBER UNOP BINOP TOK_NEWSTRING TOK_INDEX
%token  TOK_IF TOK_ELSE TOK_IFELSE TOK_ALLOC
%token  TOK_WHILE TOK_RET TOK_RETURNVOID
%token  TOK_INT TOK_STRING TOK_STRUCT TOK_VOID
%token  TOK_NEW TOK_NULL TOK_ARRAY TOK_VARDECL
%token  TOK_INT_CONST TOK_CHAR_CONST TOK_STR_CONST
%token  TOK_EQ TOK_NEQ TOK_LEQ TOK_GEQ
%token  TOK_BLOCK TOK_CALL DECLID TOK_FUNCTION TOK_PROTOTYPE
%token  TOK_POS TOK_NEG TOK_NEWARRAY TOK_TYPEID TOK_FIELD
%token  TOK_ORD TOK_CHR TOK_ROOT TOK_PARAMLIST BAD_TOK TOK_EXC

%token '(' ')' '{' '}' '[' ']' ',' '.' ';'
%token '%' '+' '-' '=' '*' '/' '!' '->' 

%right TOK_IF TOK_ELSE
%right '='
%left  TOK_EQ TOK_NEQ '<' '>' TOK_LEQ TOK_GEQ
%left  '+' '-' 
%left  '*' '/' '%'
%right TOK_POS TOK_NEG TOK_NOT
%left  '[' '->'

%nonassoc '('


%start start

%%

start : program { yyparse_astree = $1; }
;
program : program structdef { $$ = $1->adopt ($2); }
   | program function { $$ = $1->adopt ($2); }
   | program statement { $$ = $1->adopt ($2); }
   | program error ’}’ { $$ = $1; }
   | program error ’;’ { $$ = $1; }
   | { $$ = parser::root; }
;


%%


const char *parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}


bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

