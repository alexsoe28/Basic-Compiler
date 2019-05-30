#ifndef GENERATE_TABLE
#define GENERATE_TABLE

#include <iostream>
#include "symtable.h"
#include "astree.h"

void postOrderTraversal(astree* node);

void typecheck(FILE *out, astree *node);
#endif
