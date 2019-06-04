// $Id: main.cpp,v 1.2 2016-08-18 15:13:48-07 - - $
//Alexander Soe
//asoe
//Ashley Lavizadeh
//alavizad

#include <unistd.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include <libgen.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "string_set.h"
#include "auxlib.h"
#include "lyutils.h"
#include "astree.h"
#include "generateTable.h"

string CPP = "/usr/bin/cpp -nostdinc";
constexpr size_t LINESIZE = 1024;
string targetFile;
extern int yy_flex_debug;
extern int yydebug;
extern FILE* outFile;

void chomp (char* string, char delim) {
   size_t len = strlen (string);
   if (len == 0) return;
   char* nlpos = string + len - 1;
   if (*nlpos == delim) *nlpos = '\0';
}

void cpplines (FILE* pipe, const char* filename) {
   int linenr = 1;
   char inputname[LINESIZE];
   strcpy (inputname, filename);
   for (;;) {
      char buffer[LINESIZE];
      char* fgets_rc = fgets (buffer, LINESIZE, pipe);
      if (fgets_rc == nullptr) break;
      chomp (buffer, '\n');
      //printf ("%s:line %d: [%s]\n", filename, linenr, buffer);
      // http://gcc.gnu.org/onlinedocs/cpp/Preprocessor-Output.html
      int sscanf_rc = sscanf (buffer, "# %d \"%[^\"]\"",
                              &linenr, inputname);
      if (sscanf_rc == 2) {
      //printf ("DIRECTIVE: line %d file \"%s\"\n", linenr, inputname);
         continue;
      }
      char* savepos = nullptr;
      char* bufptr = buffer;
      for (int tokenct = 1;; ++tokenct) {
         char* token = strtok_r (bufptr, " \t\n", &savepos);
         bufptr = nullptr;
         if (token == nullptr) break;
         //printf ("token %d.%d: [%s]\n",linenr, tokenct, token);
         string_set::intern(token);
      }
      ++linenr;
   }
}

int main (int argc, char** argv) {
   exec::execname = basename (argv[0]);
   int exit_status = EXIT_SUCCESS;

   /*Getopt switch case checks the user input in console 
   for which flags they call during compiler call*/
   int flagOption;
   while((flagOption = getopt(argc, argv, "@:D:ly")) != -1){
      switch(flagOption){
         case '@': set_debugflags(optarg); break; //Help
         case 'D': CPP = CPP + "-D" + optarg; break; //Help
         case 'l': yy_flex_debug = 1; break; 
         case 'y': yydebug = 1; break;
         default:
         perror("Usage: oc [-ly] [-@ flag] [-D string] program.oc\n");
         break;
      }
   }

   if(optind > argc){
      perror("Usage: oc [-ly] [-@ flag] [-D string] program.oc\n");
      exit(exit_status);
   }
   
   //check if the file ends in .oc
   targetFile = basename(argv[optind]);
   if(targetFile.find(".oc") == string::npos){
      perror("Usage: oc [-ly] [-@ flag] [-D string] program.oc\n");
      exit(exit_status);
   }
   //Call cpplines on the .oc files. Use yyin as the read file
   char* filename = argv[optind];
   string command = CPP + " " + filename;
   yyin = popen(command.c_str(), "r");
   if (yyin == nullptr){
      exit_status = EXIT_FAILURE;
      fprintf (stderr, "%s: %s: %s\n",
               exec::execname.c_str(), command.c_str(), 
               strerror (errno));
   }
   else{
      cpplines (yyin, filename);
      int pclose_rc = pclose(yyin);
      eprint_status (command.c_str(), pclose_rc);
      if (pclose_rc != 0) exit_status = EXIT_FAILURE;
   }
   //Rename file with .str
   string strFile = targetFile.substr(0,targetFile.size()-3)+".str"; 
   FILE* out = fopen(strFile.c_str(), "w");
   //Dump into new file with .str suffix and close file
   string_set::dump(out);
   //Open yyin with read and create a new file with tok suffix
   //to write to.
   yyin = popen(command.c_str(), "r");
   string tokFile = targetFile.substr(0,targetFile.size()-3)+".tok"; 
   outFile = fopen(tokFile.c_str(), "w");
   yyparse();
   fclose(outFile); 

   type_check(parser::root);
      

   string astFile = targetFile.substr(0,targetFile.size()-3)+".ast";
   FILE*outfile = fopen(astFile.c_str(), "w");
   astree::print(outfile, parser::root);

   string symFile = targetFile.substr(0,targetFile.size()-3)+".sym";
   FILE*symfile = fopen(symFile.c_str(), "w");

   printTable(symfile);
   fclose(symfile);
   fclose(out);
   fclose(outfile);
   return exit_status;
}

