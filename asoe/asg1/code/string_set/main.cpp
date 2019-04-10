// $Id: main.cpp,v 1.2 2016-08-18 15:13:48-07 - - $
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

string CPP = "/usr/bin/cpp -nostdinc";
constexpr size_t LINESIZE = 1024;
int yydebug = 0;
int yy_flex_debug = 0;

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
      printf ("%s:line %d: [%s]\n", filename, linenr, buffer);
      // http://gcc.gnu.org/onlinedocs/cpp/Preprocessor-Output.html
      int sscanf_rc = sscanf (buffer, "# %d \"%[^\"]\"",
                              &linenr, inputname);
      if (sscanf_rc == 2) {
         printf ("DIRECTIVE: line %d file \"%s\"\n", linenr, inputname);
         continue;
      }
      char* savepos = nullptr;
      char* bufptr = buffer;
      for (int tokenct = 1;; ++tokenct) {
         char* token = strtok_r (bufptr, " \t\n", &savepos);
         bufptr = nullptr;
         if (token == nullptr) break;
         printf ("token %d.%d: [%s]\n",
                 linenr, tokenct, token);
      }
      ++linenr;
   }
}

int main (int argc, char** argv) {
   const char* execname = basename (argv[0]);
   int exit_status = EXIT_SUCCESS;

   int flagOption;
   while((flagOption = getopt(argc, argv, "@:D:ly")) != -1){
      switch(flagOption){
         case '@': set_debugflags(optarg); break; //Help
         case 'D': CPP = CPP + "-D" + optarg; break; //Help
         case 'l': yy_flex_debug = 1; break; 
         case 'y': yydebug = 1; break;
         default: perror("Usage: oc [-ly] [-@ flag ...] [-D string] program.oc\n"); break;
      }
   }
   if(optind > argc){
      perror("Usage: oc [-ly] [-@ flag ...] [-D string] program.oc\n");
      exit(exit_status);
   }

   string fileSuffix = basename(argv[optind]);
   if(fileSuffix.find(".oc") == string::npos){
      perror("Usage: oc [-ly] [-@ flag ...] [-D string] program.oc\n");
      exit(exit_status);
   }

   char* filename = argv[optind];
   string command = CPP + " " + filename;
   printf ("command=\"%s\"\n", command.c_str());
   
   FILE* pipe = popen (command.c_str(), "r");
   if (pipe == nullptr){
      exit_status = EXIT_FAILURE;
      fprintf (stderr, "%s: %s: %s\n",
               execname, command.c_str(), strerror (errno));
   }
   else{
      cpplines (pipe, filename);
      int pclose_rc = pclose (pipe);
      eprint_status (command.c_str(), pclose_rc);
      if (pclose_rc != 0) exit_status = EXIT_FAILURE;
   }
   
   return exit_status;
}

