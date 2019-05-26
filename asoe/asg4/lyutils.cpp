// $Id: lyutils.cpp,v 1.6 2019-04-18 13:35:11-07 - - $
//Alexander Soe
//asoe
//Ashley Lavizadeh
//alavizad

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auxlib.h"
#include "lyutils.h"

bool lexer::interactive = true;
location lexer::lloc = {0, 1, 0};
size_t lexer::last_yyleng = 0;
vector<string> lexer::filenames;
FILE* outFile;

astree* parser::root = nullptr;

const string* lexer::filename (int filenr) {
   return &lexer::filenames.at(filenr);
}

void lexer::newfilename (const string& filename) {
   lexer::lloc.filenr = lexer::filenames.size();
   lexer::filenames.push_back (filename);
}

void lexer::advance() {
   if (not interactive) {
      if (lexer::lloc.offset == 0) {
         printf (";%2zd.%3zd: ",
                 lexer::lloc.filenr, lexer::lloc.linenr);
      }
      printf ("%s", yytext);
   }
   lexer::lloc.offset += last_yyleng;
   last_yyleng = yyleng;
}

void lexer::newline() {
   ++lexer::lloc.linenr;
   lexer::lloc.offset = 0;
}

void lexer::badchar (unsigned char bad) {
   char buffer[16];
   snprintf (buffer, sizeof buffer,
             isgraph (bad) ? "%c" : "\\%03o", bad);
   errllocprintf (lexer::lloc, "invalid source character (%s)\n",
                  buffer);
}


void lexer::include() {
   // in this function yytext = an entire directive line
   size_t linenr;
   static char filename[0x1000];
   assert (sizeof filename > strlen (yytext));
   int scan_rc = sscanf (yytext, "# %zu \"%[^\"]\"", &linenr, filename);
   
   fprintf(outFile, "%s\n", yytext);

   if (scan_rc != 2) {
      errprintf ("%s: invalid directive, ignored\n", yytext);
   }else {
      if (yy_flex_debug) {
         fprintf (stderr, "--included # %zd \"%s\"\n",
                  linenr, filename);
      }
      lexer::lloc.linenr = linenr - 1;
      lexer::newfilename (filename);
   }
}

int lexer::token (int symbol) {
   yylval = new astree (symbol, lexer::lloc, yytext);
   // do your printing right here fam
   fprintf (outFile, "\t%zd  %zd.%zd  %d  %s  (%s)\n",
      yylval->lloc.filenr, yylval->lloc.linenr, yylval->lloc.offset,
      yylval->symbol, parser::get_tname (yylval->symbol),
      yylval->lexinfo->c_str());
   return symbol;
}

int lexer::badtoken (int symbol) {
   errllocprintf (lexer::lloc, "invalid token (%s)\n", yytext);
   return lexer::token (symbol);
}

void yyerror (const char* message) {
   assert (not lexer::filenames.empty());
   errllocprintf (lexer::lloc, "%s\n", message);
}
