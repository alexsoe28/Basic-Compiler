%{
// $Id: jamscanner.l,v 1.5 2014-10-24 16:34:59-07 - - $

#include <stdio.h>

#define YY_USER_ACTION { printf ("token=\"%s\" - ", yytext); }

%}

%option 8bit
%option debug
%option nobackup
%option nodefault
%option noinput
%option nounput
%option noyywrap
%option warn

%%

[a-z]+             printf ("identifier\n");
[0-9]+             printf ("number\n");
'[^'\n']*'         printf ("string\n");
[!@#$%^&*()_+=-]+  printf ("symbols\n");
[ \t\n]+           printf ("white space\n");
.                  printf ("error char %c\n", *yytext);

%%

int main() {
   yy_flex_debug = 0;
   while (yylex());
   return 0;
}
