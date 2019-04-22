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
#include <errno.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "string_set.h"
#include "auxlib.h"
#include "astree.h"
#include "lyutils.h"

string CPP = "/usr/bin/cpp -nostdinc";
constexpr size_t LINESIZE = 1024;
extern int yydebug;
extern int yy_flex_debug;
extern FILE* outFile;
string targetFile;

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
      sscanf (buffer, "# %d \"%[^\"]\"",
            &linenr, inputname);
      const char* tokFile = (
         targetFile.substr(0,targetFile.size()-3) + ".tok").c_str();
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
   const char* execname = basename (argv[0]);
   yy_flex_debug = 0;
   yydebug = 0;
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

   //Rename file with .str
   string strFile = targetFile.substr(0,targetFile.size()-3)+".str"; 
   FILE* out = fopen(strFile.c_str(), "w");

   char* filename = argv[optind];
   string command = CPP + " " + filename;
   yyin = popen (command.c_str(), "r");
   if (yyin == nullptr){
      exit_status = EXIT_FAILURE;
      fprintf (stderr, "%s: %s: %s\n",
               execname, command.c_str(), strerror (errno));
   }
   else{
      cpplines (yyin, filename);
      int pclose_rc = pclose (yyin);
      if (pclose_rc != 0) exit_status = EXIT_FAILURE;
   }
   //Dump into new file with .str suffix and close file
   string_set::dump(out);
   fclose(out);
   return exit_status;
}

