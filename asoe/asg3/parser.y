%{
#include <cassert>
#include <stdlib.h>
#include <string.h>
#include "astree.h"
#include "lyutils.h"
#include <iostream>
using namespace std;
extern FILE* outFile;
extern int exit_status;
%}

%debug
%defines
%error-verbose
%token-table
%verbose
%initial-action {
   parser::root = new astree (ROOT, {0, 0, 0}, "<>"); 
} 

%destructor { destroy ($$); } <>
%printer { astree::dump (yyoutput, $$); } <>

%token  ROOT IDENT NUMBER UNOP BINOP TOK_NEWSTRING TOK_INDEX
%token  TOK_IF TOK_ELSE TOK_IFELSE TOK_ALLOC TOK_NULLPTR
%token  TOK_WHILE TOK_RETURN TOK_RETURNVOID
%token  TOK_INT TOK_STRING TOK_STRUCT TOK_VOID
%token  TOK_NEW TOK_NULL TOK_ARRAY TOK_VARDECL 
%token  TOK_EQ TOK_NE TOK_LE TOK_GE TOK_NOT TOK_PTR
%token  TOK_BLOCK TOK_CALL DECLID TOK_FUNCTION TOK_PROTOTYPE
%token  TOK_POS TOK_NEG TOK_NEWARRAY TOK_TYPEID TOK_FIELD
%token  TOK_ORD TOK_CHR TOK_ROOT TOK_PARAMLIST BAD_TOK TOK_EXC
%token  TOK_INTCON TOK_CHARCON TOK_STRINGCON TOK_ARROW

%token  '('  ')'  '['  ']'  '{'  '}'  ';'  ','  '.'
%token  '='  '+'  '-'  '*'  '/'  '%'  '!'

%right  TOK_IF TOK_ELSE
%right  '=' 
%left   TOK_EQ TOK_NEQ '<' TOK_LEQ '>' TOK_GEQ 
%left   '+' '-'
%left   '*' '/' '%'
%right  POS NEG TOK_EXC TOK_NEW
%right  '^'
%left   '[' '.'

%nonassoc '('

%start  start

%%
start     : program                   { $$ = $1 = nullptr; }
          ;

program   : program structdef         { $$ = $1->adopt ($2); }
          | program function          { $$ = $1->adopt ($2); }
          | program statement         { $$ = $1->adopt ($2); }
          | program error '}'         { destroy ($3); $$ = $1; }
          | program error ';'         { destroy ($3); $$ = $1; }
          |                           { $$ = parser::root; }
;


structdef : TOK_STRUCT IDENT '{' '}'  { destroy ($3, $4);
                                        $2->change_sym (TOK_TYPEID);
                                        $$ = $1->adopt ($2); }
          | TOK_STRUCT IDENT '{' structfields '}' 
                                      { destroy ($3, $5);
                                        $2->change_sym (TOK_TYPEID);
                                        $$ = $1->adopt ($2, $4); }
;

structfields    : structfield ';' structfields{ 
            destroy ($2);
            $$ = $1->adopt ($3); }
          | structfield ';'                   {
            destroy ($2); $$ = $1; }
;

structfield     : plaintype IDENT            { 
            $2->change_sym (TOK_FIELD);
            $$ = $1->adopt ($2); }
          | plaintype TOK_ARRAY IDENT        { 
            $2->change_sym (TOK_ARRAY);
            $3->change_sym (TOK_FIELD);
            $$ = $2->adopt ($1, $3); }
;

plaintype  : TOK_VOID                 { $$ = $1; }
          | TOK_INT                   { $$ = $1; }
          | TOK_STRING                { $$ = $1; }
          | IDENT                     { $1->change_sym (TOK_TYPEID); 
                                        $$ = $1; }
;

function  : ident '(' idents ')' block { 
            $4->change_sym (TOK_FUNCTION);
            $2->change_sym (TOK_PARAMLIST);
            $2->adopt ($3);
            $$ = $4->adopt ($1, $2, $5); }
          |  ident '(' idents ')' ';'  { 
            destroy($5);
            $4->change_sym (TOK_FUNCTION);
            $2->change_sym (TOK_PARAMLIST);
            $2->adopt ($3);
            $$ = $4->adopt ($1, $2); }
          | ident '(' ')' ';'         { 
            destroy ($4);
            $3->change_sym (TOK_PROTOTYPE);
            $2->change_sym (TOK_PARAMLIST);
            $$ = $3->adopt ($1, $2); }
          | ident '(' ')' block       { 
            $3->change_sym(TOK_FUNCTION);
            $2->change_sym(TOK_PARAMLIST);
            $$ = $3->adopt ($1, $2, $4); }
;

idents: idents ',' ident  { 
             destroy ($2);
             $$ = $1->adopt ($3); }
          |  ident        { $$ = $1; }
          ;

ident : plaintype TOK_ARRAY IDENT  { $3->change_sym (DECLID);
                                        $$ = $1->adopt ($2, $3); }
          | plaintype IDENT            { $2->change_sym (DECLID);
                                        $$ = $1->adopt ($2); }
          ;


block     : statements '}'            { 
            destroy ($2);
            $1->change_sym (TOK_BLOCK);
            $$ = $1; }
          | '{' '}'                   { 
            destroy ($2);
            $1->change_sym (TOK_BLOCK);
            $$ = $1; }
;

statements     : statements statement      { 
                 $$ = $1->adopt ($2); }
               | '{' statement              { 
                 $$ = $1->adopt ($2); }
;

statement      : block                { $$ = $1; }
          | vardecl                   { $$ = $1; }
          | while                     { $$ = $1; }
          | ifelse                    { $$ = $1; }
          | return                    { $$ = $1; }
          | expr ';'                  { destroy ($2); $$ = $1; }
;

vardecl   : ident '=' expr ';'    { 
            destroy ($4);
            $2->change_sym (TOK_VARDECL);
            $$ = $2->adopt ($1, $3); }
;

while     : TOK_WHILE '(' expr ')' statement{ 
            destroy ($2, $4);
            $$ = $1->adopt($3, $5); }
;

ifelse    : TOK_IF '(' expr ')' statement %prec TOK_IF      { 
            destroy ($2, $4);
            $$ =$1->adopt($3,$5); }
          | TOK_IF '(' expr ')' statement TOK_ELSE statement{ 
            destroy ($2, $4);
            destroy ($5, $6);
            $1->change_sym (TOK_IFELSE);
            $$ = $1->adopt ($3, $5, $7); }
;

return    : TOK_RETURN ';'               { 
            destroy ($2);
            $1->change_sym (TOK_RETURNVOID);
            $$ = $1; }
          | TOK_RETURN expr ';'          { 
            destroy ($3);
            $$ = $1->adopt ($2); }
;

expr        : expr binop expr { $$ = $2->adopt($1, $3); }
            | unop expr       { $$ = $1->adopt($2); }
            | alloc           { $$ = $1; }
            | call            { $$ = $1; }
            | '(' expr ')'    { destroy($1, $3);
              $$ = $2; }
            | variable       { $$ = $1; }
            | constant       { $$ = $1; }
;

binop       : TOK_EQ          { $$ = $1; }
            | TOK_NE          { $$ = $1; }
            | '>'             { $$ = $1; }
            | TOK_LE          { $$ = $1; }
            | '<'             { $$ = $1; }
            | TOK_GE          { $$ = $1; }
            | '+'             { $$ = $1; }
            | '-'             { $$ = $1; }
            | '*'             { $$ = $1; }
            | '/'             { $$ = $1; }
            | '='             { $$ = $1; }
;

unop        : TOK_POS         { $$ = $1; }
            | TOK_NEG         { $$ = $1; }
            | '!'             { $$ = $1; }
            | TOK_NEW         { $$ = $1; }
;

alloc     : TOK_NEW IDENT '(' ')'          { 
            destroy ($3, $4);
            $2->change_sym (TOK_TYPEID);
            $$ = $1->adopt ($2); }
          | TOK_NEW TOK_STRING '(' expr ')'{ 
            destroy ($2, $3, $5);
            $1->change_sym (TOK_NEWSTRING);
            $$ = $1->adopt ($4); }
          | TOK_NEW plaintype '[' expr ']' { 
            destroy ($3, $5);
            $1->change_sym (TOK_NEWARRAY);
            $$ = $1->adopt ($2, $4); }
;

call      : params ')'                { 
            destroy ($2);
            $1->change_sym (TOK_CALL);
            $$ = $1; }
          | IDENT '(' ')'             { 
            destroy ($3);
            $2->change_sym (TOK_CALL);
            $$ = $2->adopt ($1); }
;

params    : IDENT '(' expr            { 
            $$ = $2->adopt ($1, $3); }
          | params ',' expr           { 
            destroy ($2);
            $$ = $1->adopt ($3); }
;

variable  : IDENT                     { $$ = $1; }
          | expr '[' expr ']'         { 
            destroy ($4);
            $2->change_sym (TOK_INDEX);
            $$ = $2->adopt ($1, $3); }
          | expr '.' IDENT            { 
            $3->change_sym(TOK_FIELD);
            $$ = $2->adopt ($1, $3); }
;

constant  : TOK_STRINGCON             { $$ = $1; }
          | TOK_CHARCON               { $$ = $1; }
          | TOK_INTCON                { $$ = $1; }
          | TOK_NULL                  { $$ = $1; }
;

%%

const char* parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}

bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}
