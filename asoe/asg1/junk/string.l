%{
// $Id: string.l,v 1.1 2017-10-26 15:07:21-07 - - $

#include <stdio.h>

%}

%option 8bit
%option debug
%option nobackup
%option nodefault
%option noinput
%option nounput
%option noyywrap
%option verbose
%option warn

STRING   (\"([^\\"\n]|\\[\\'"0nt])*\")
NQSTRING (\"([^\\"\n]|\\[\\'"0nt])*)
ALNUM    ([[:alnum:]]+)

%%

{STRING}  { printf ("string=\"%s\"\n", yytext); }
{NQSTRING}  { printf ("nqstring=\"%s\"\n", yytext); }
"+"       { printf ("+\n"); }
{ALNUM}   { printf ("alnum=\"%s\"\n", yytext); }
[ \t\n]   { }

%%

int main() {
   while (yylex());
   return 0;
}
