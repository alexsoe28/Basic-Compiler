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
%token  TOK_WHILE TOK_RETURN TOK_RETURNVOID TOK_FIELDLIST
%token  TOK_INT TOK_STRING TOK_STRUCT TOK_VOID
%token  TOK_NULL TOK_ARRAY TOK_VARDECL TOK_PARAMLIST
%token  TOK_EQ TOK_NE TOK_LE TOK_GE TOK_NOT TOK_PTR
%token  TOK_BLOCK TOK_CALL DECLID TOK_FUNCTION TOK_PROTOTYPE
%token  TOK_POS TOK_NEG TOK_NEWARRAY TOK_TYPEID TOK_FIELD
%token  TOK_ORD TOK_CHR TOK_ROOT TOK_PARAM BAD_TOK TOK_EXC
%token  TOK_INTCON TOK_CHARCON TOK_STRINGCON TOK_ARROW

%token  '('  ')'  '['  ']'  '{'  '}'  ';'  ','  '.'
%token  '='  '+'  '-'  '*'  '/'  '%'  '!'

%right  TOK_IF TOK_ELSE
%right  '=' 
%left   TOK_EQ TOK_NE '<' TOK_LE '>' TOK_GE 
%left   '+' '-'
%left   '*' '/' '%'
%right  TOK_POS TOK_NEG TOK_NOT
%left   '[' TOK_ARROW

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


structdef : TOK_STRUCT IDENT '{' structfields '}' { 
            destroy ($3, $5);
            $2->change_sym (TOK_TYPEID);
            $$ = $1->adopt ($2, $4); }
          | TOK_STRUCT IDENT '{' '}'              { 
            destroy ($3, $4);
            $2->change_sym (TOK_TYPEID);
            $$ = $1->adopt ($2); }
;

structfields: type ';'               {
            $$ = new astree(TOK_FIELDLIST, $1->lloc, "");
            destroy ($2); 
            $$ = $$->adopt($1); }
          | type ';' structfields    { 
            destroy ($2);
            $$ = $3->adopt ($1); }
;

type       : plaintype IDENT            {
            $2->change_sym (TOK_FIELD);
            $$ = $1->adopt ($2);}
          | TOK_ARRAY '<' plaintype '>' {
            destroy ($2, $4); 
            $3->change_sym (TOK_FIELD);
            $$ = $1->adopt ($3); }
;

plaintype  : TOK_VOID                       { $$ = $1; }
          | TOK_INT                         { $$ = $1; }
          | TOK_STRING                      { $$ = $1; }
          | TOK_PTR '<' TOK_STRUCT IDENT '>'{
            destroy($2, $3, $5);
            $$ = $1->adopt ($4); }
;

function  : ident '(' ')' block       {
            destroy ($3);  
            $$ = new astree(TOK_FUNCTION, $1->lloc, "");
            $2->change_sym(TOK_PARAM);
            $$ = $$->adopt ($1, $2, $4); }
          | ident '(' idents ')' block {
            destroy ($4); 
            $$ = new astree(TOK_FUNCTION, $1->lloc, "");
            $2->change_sym (TOK_PARAM);
            $2->adopt ($3);
            $$ = $$->adopt ($1, $2, $5); }
          | ident '(' ')' ';'         { 
            destroy ($3, $4);
            $$ = new astree(TOK_PROTOTYPE, $1->lloc, "");
            $2->change_sym (TOK_PARAM);
            $$ = $$->adopt ($1, $2); }
          | ident '(' idents ')' ';'  { 
            destroy($4, $5);
            $$ = new astree(TOK_FUNCTION, $1->lloc, "");
            $2->change_sym (TOK_PARAM);
            $2->adopt ($3);
            $$ = $$->adopt ($1, $2); }
;

idents:     ident        { 
            $$ = new astree(TOK_PARAMLIST, $1->lloc, "");
            $$ = $$->adopt ($1); }
          | idents ',' ident  { 
            
            destroy ($2);
            $$ = $1->adopt ($3); }
;

ident :   TOK_ARRAY '<' plaintype '>' IDENT {
            destroy($2, $4); 
            $5->change_sym (DECLID);
            $$ = $1->adopt ($3, $5); }
          | plaintype IDENT        { 
            $2->change_sym (DECLID);
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

statements: '{' statement             { 
            $$ = $1->adopt ($2); }
          | statements statement      { 
            $$ = $1->adopt ($2); }
;

statement : vardecl                   { $$ = $1; }
          | block                     { $$ = $1; }
          | while                     { $$ = $1; }
          | ifelse                    { $$ = $1; }
          | return                    { $$ = $1; }
          | expr ';'                  { destroy ($2); $$ = $1; }
          | ';'                       { $$ = $1; }
;

vardecl   : ident '=' expr ';'       { 
            destroy ($4);
            $2->change_sym (TOK_VARDECL);
            $$ = $2->adopt ($1, $3); }
          | ident ';'                 {
            $$ = new astree(TOK_VARDECL, $1->lloc, "");
            destroy ($2);
            $$ = $$->adopt($1);}
;

while     : TOK_WHILE '(' expr ')' statement            { 
            destroy ($2, $4);
            $$ = $1->adopt($3, $5); }
;

ifelse    : TOK_IF '(' expr ')' statement  %prec TOK_IF           { 
            destroy ($2, $4);
            $$ =$1->adopt($3,$5); }
          | TOK_IF '(' expr ')' statement TOK_ELSE statement    { 
            destroy ($2, $4, $6);
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

expr        : expr '=' expr          { $$ = $2->adopt($1, $3); }
            | expr TOK_EQ expr       { $$ = $2->adopt($1, $3); }
            | expr TOK_NE expr       { $$ = $2->adopt($1, $3); }
            | expr '<' expr          { $$ = $2->adopt($1, $3); }
            | expr TOK_LE  expr      { $$ = $2->adopt($1, $3); }
            | expr '>' expr          { $$ = $2->adopt($1, $3); }
            | expr TOK_GE  expr      { $$ = $2->adopt($1, $3); }
            | expr '+' expr          { $$ = $2->adopt($1, $3); }
            | expr '-' expr          { $$ = $2->adopt($1, $3); } 
            | expr '*' expr          { $$ = $2->adopt($1, $3); }
            | expr '/' expr          { $$ = $2->adopt($1, $3); }
            | expr '%' expr          { $$ = $2->adopt($1, $3); } 
            | '+' expr %prec '+'     { $$ = $1->adopt($2); }
            | '-' expr %prec '-'     { $$ = $1->adopt($2); }
            | TOK_NOT expr           { $$ = $1->adopt($2); }
            | alloc                  { $$ = $1; }
            | call                   { $$ = $1; }
            | '(' expr ')'           { destroy($1, $3);
              $$ = $2; }
            | variable        { $$ = $1; }
            | constant        { $$ = $1; }
;

alloc     : TOK_ALLOC '<' TOK_STRUCT IDENT '>' '(' ')'          { 
            destroy ($2, $3, $5);
            destroy ($6, $7);
            $4->change_sym (TOK_TYPEID);
            $$ = $1->adopt ($4); }
          | TOK_ALLOC '<' TOK_STRING '>' '(' expr ')'{ 
            destroy ($2, $4, $5);
            destroy ($7);
            $$ = $1->adopt ($3, $6); }
          | TOK_ALLOC '<' TOK_ARRAY '<' plaintype '>' '>' '(' expr ')'{ 
            printf("\n WE IN HERE");
            destroy ($2, $4);
            destroy ($6, $7);
            destroy ($8, $10);
            $3->adopt ($5);
            $$ = $1->adopt ($3, $9); }
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
          | expr TOK_ARROW IDENT            { 
            $3->change_sym(TOK_FIELD);
            $$ = $2->adopt ($1, $3); }
;

constant  : TOK_STRINGCON             { $$ = $1; }
          | TOK_CHARCON               { $$ = $1; }
          | TOK_INTCON                { $$ = $1; }
          | TOK_NULLPTR               { $$ = $1; }
;

%%

const char* parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}

bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}
