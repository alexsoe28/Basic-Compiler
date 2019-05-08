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

%initial-action {
   parser::root = new astree (ROOT, {0, 0, 0}, "<<ROOT>>");
}

%token TOK_VOID TOK_INT TOK_STRING TOK_BOOL TOK_CHAR
%token TOK_IF TOK_ELSE TOK_WHILE TOK_RETURN TOK_STRUCT
%token TOK_FALSE TOK_TRUE TOK_NULL TOK_NEW
%token TOK_NULLPTR TOK_ARRAY TOK_ARROW TOK_ALLOC TOK_PTR
%token TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE TOK_NOT
%token TOK_IDENT TOK_INTCON TOK_CHARCON TOK_STRINGCON
%token TOK_ROOT TOK_BLOCK TOK_CALL TOK_INITDECL NUMBER
%token TOK_CHAR_CONST TOK_STR_CONST TOK_INT_CONST

%token TOK_IFELSE TOK_POS TOK_NEG TOK_NEWARRAY 
%token TOK_TYPEID TOK_FIELD 

%token TOK_RETURNVOID TOK_PARAM TOK_PROTOTYPE TOK_DECLID
%token TOK_NEWSTRING TOK_VARDECL TOK_INDEX TOK_FUNCTION

%token '(' ')' '{' '}' '[' ']' ',' '.' ';'
%token '%' '+' '-' '=' '*' '/' '!'  

%right TOK_IFELSE TOK_IF TOK_ELSE
%right '='
%left  TOK_EQ TOK_NEQ '<' '>' TOK_LEQ TOK_GEQ
%left  '+' '-' 
%left  '*' '/' '%'
%right TOK_POS TOK_NEG TOK_NOT TOK_NEW
%left  '[' TOK_ARROW

%nonassoc '('


%start start

%%

start : program { yyparse_astree = $1; }
;
program : program structdef { $$ = $1->adopt ($2); }
   | program function { $$ = $1->adopt ($2); }
   | program statement { $$ = $1->adopt ($2); }
   | program error '}' { $$ = $1; }
   | program error ';' { $$ = $1; }
   | { $$ = parser::root; }
;

structdef : TOK_STRUCT TOK_IDENT '{' '}' ';' {
      destroy($3, $4, $5);
      $2->change_sym (TOK_TYPEID);
      $$ = $1->adopt ($2);
   }
   | TOK_STRUCT TOK_IDENT '{' structfields'}' ';'{
       destroy($3, $5, $6);
       $2->change_sym (TOK_TYPEID);
       $$ = $1->adopt ($2);
   }
;

structfields : type ';' structfields {
      destroy($2);
      $$ = $1->adopt ($3);
    }
    | type ';'{
         destroy($2);
         $$ = $1;      
    }
;

type : plaintype TOK_IDENT {
      $2->change_sym (TOK_FIELD);
      $$ = $1->adopt ($2)
    }
    | plaintype TOK_ARRAY TOK_IDENT {
      $2->change_sym (TOK_ARRAY);
      $3->change_sym (TOK_FIELD);
      $$ = $2->adopt ($1, $3);
    }
;
plaintype : TOK_VOID { $$ = $1; }
   | TOK_INT { $$ = $1; }
   | TOK_STRING { $$ = $1; }
   | TOK_IDENT { $1->change_sym (TOK_TYPEID);
     $$ = $1
   }
   | TOK_PTR '<' TOK_STRUCT TOK_IDENT '>' { 
     destroy($2, $5);
     $4->change_sym (TOK_TYPEID);
     $$ = $1->adopt ($3,$4);
   }
;

function : 

constant : TOK_INT_CONST { $$ = $1; }
   | TOK_CHAR_CONST { $$ = $1; }
   | TOK_NULL { $$ = $1; }
   | TOK_STR_CONST { $$ = $1; }
;

%%


const char *parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}


bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

