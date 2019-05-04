%{

#include "lyutils.h"
#include "auxlib.h"
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
INTEGER         ({DIGIT}+)
STRING          (\"([^\\"\n]|\\[\\'"0nt])*\")
CHAR            ('([^\\'\n]|\\[\\'"0nt])')
%%

"#".*               { lexer::include(); }
[ \t]+              { }
\n                  { lexer::newline(); }

"if"                { return lexer::token (TOK_IF); }
"else"              { return lexer::token (TOK_ELSE); }
"while"             { return lexer::token (TOK_WHILE); }
"return"            { return lexer::token (TOK_RETURN); }
"alloc"             { return lexer::token (TOK_ALLOC); }
"nullptr"           { return lexer::token (TOK_NULLPTR); }
"not"               { return lexer::token (TOK_NOT); }
"int"               { return lexer::token (TOK_INT); }
"string"            { return lexer::token (TOK_STRING); }
"struct"            { return lexer::token (TOK_STRUCT); }
"array"             { return lexer::token (TOK_ARRAY); }
"ptr"               { return lexer::token (TOK_PTR); }
"void"              { return lexer::token (TOK_VOID); }

{STRING}            { return lexer::token (TOK_STRINGCON); }
{CHAR}              { return lexer::token (TOK_CHARCON); }
(\[\])              { return lexer::token (TOK_ARRAY); }
{INTEGER}           { return lexer::token (TOK_INT); }
{IDENT}             { return lexer::token (TOK_IDENT); }
"<="                { return lexer::token (TOK_LE); }
">="                { return lexer::token (TOK_GE); }
"=="                { return lexer::token (TOK_EQ); }
"!="                { return lexer::token (TOK_NE); }
"->"                { return lexer::token (TOK_ARROW); }
"="                 { return lexer::token ('='); }
"+"                 { return lexer::token ('+'); }
"-"                 { return lexer::token ('-'); }
"*"                 { return lexer::token ('*'); }
"/"                 { return lexer::token ('/'); }
"^"                 { return lexer::token ('^'); }
"("                 { return lexer::token ('('); }
")"                 { return lexer::token (')'); }
"%"                 { return lexer::token ('%'); }
"<"                 { return lexer::token ('<'); }
">"                 { return lexer::token ('>'); }
";"                 { return lexer::token (';'); }
"{"                 { return lexer::token ('{'); }
"}"                 { return lexer::token ('}'); }
"["                 { return lexer::token ('['); }
"]"                 { return lexer::token (']'); } 


{NOTNUMBER}     { return lexer::badtoken (NUMBER); }
.               { lexer::badchar (*yytext); }

%%

