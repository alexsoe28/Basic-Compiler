/* $Id: lexer.l,v 1.9 2019-04-18 13:33:21-07 - - $ */

%{

#include "lyutils.h"

#define YY_USER_ACTION  { lexer::advance(); }

%}

%option 8bit
%option debug
%option nobackup
%option nodefault
%option noinput
%option nounput
%option noyywrap
%option warn
/*%option verbose*/

LETTER          [A-Za-z_]
DIGIT           [0-9]
MANTISSA        ({DIGIT}+\.?{DIGIT}*|\.{DIGIT}+)
EXPONENT        ([Ee][+-]?{DIGIT}+)
NUMBER          ({MANTISSA}{EXPONENT}?)
NOTNUMBER       ({MANTISSA}[Ee][+-]?)
IDENT           ({LETTER}({LETTER}|{DIGIT})*)

STRING          (\"([^\\"\n]|\\[\\'"0nt])*\")
CHAR            ('([^\\'\n]|\\[\\'"0nt])')
%%

"#".*           { lexer::include(); }
[ \t]+          { }
\n              { lexer::newline(); }

(if)            { return yylval_token (TOK_IF); }
(else)          { return yylval_token (TOK_ELSE); }
(while)         { return yylval_token (TOK_WHILE); }
(return)        { return yylval_token (TOK_RETURN); }
(alloc)         { return yylval_token (TOK_ALLOC); }
(nullptr)       { return yylval_token (TOK_NULLPTR); }
(not)           { return yylval_token (TOK_NOT); }
(int)           { return yylval_token (TOK_INT); }
(string)        { return yylval_token (TOK_STRING); }
(struct)        { return yylval_token (TOK_STRUCT); }
(array)         { return yylval_token (TOK_ARRAY); }
(ptr)           { return yylval_token (TOK_PTR); }
(void)          { return yylval_token (TOK_VOID); }

{STRING}        { return yylval_token (TOK_STR_CONST); }
{CHAR}          { return yylval_token (TOK_CHAR_CONST); }
(\[\])          { return yylval_token (TOK_ARRAY); }
{NUMBER}            { return lexer::token (NUMBER); }
{IDENT}             { return lexer::token (IDENT); }
(<=)            { return yylval_token (TOK_LEQ); }
(>=)            { return yylval_token (TOK_GEQ); }
(==)            { return yylval_token (TOK_EQ); }
(!=)            { return yylval_token (TOK_NEQ); }
(->)            { return yylval_token (TOK_PTR); }
"="                 { return lexer::token ('='); }
"+"                 { return lexer::token ('+'); }
"-"                 { return lexer::token ('-'); }
"*"                 { return lexer::token ('*'); }
"/"                 { return lexer::token ('/'); }
"^"                 { return lexer::token ('^'); }
"("                 { return lexer::token ('('); }
")"                 { return lexer::token (')'); }
"%"                 { return yylval_token ('%'); }
"<"                 { return yylval_token ('<'); }
">"                 { return yylval_token ('>'); }
";"                 { return yylval_token (';'); }
"("                 { return yylval_token ('('); }
")"                 { return yylval_token (')'); }
"{"                 { return yylval_token ('{'); }
"}"                 { return yylval_token ('}'); }
"["                 { return yylval_token ('['); }
"]"                 { return yylval_token (']'); } 


{NOTNUMBER}     { return lexer::badtoken (NUMBER); }
.               { lexer::badchar (*yytext); }

%%

