#include <string>
#include <bitset>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
#include "lyutils.h"
#include "symbol_table.h"
symbol_table struct_table;
symbol_table global_table;
int next_block = 1;
vector<int> block_stack;
vector<symbol_table*> symStack;


symbol* new_symbol(astree* node){
    symStack.push_back(new symbol_table)
}

string set_attributes (astree* node, symbol* sym){
    sym->filenr = node->lloc.filenr;
    sym->linenr = node->lloc.linenr;
    sym->offset = node->lloc.offset;
    sym->filenr = node->lloc.filenr;
    sym->blocknr = block_stack.back();
    switch(node->symbol){
        case TOK_VOID: {
            sym->attributes[ATTR_void] = 1;
        }
        case TOK_INT: {
            sym->attributes[ATTR_int] = 1;
        }
        case TOK_NULL: {
            sym->attributes[ATTR_null] = 1;
        }
        case
        case TOK_STRING: {
            sym->attributes[ATTR_string] = 1;
        }
    }
}



void typecheck(FILE *out, astree *node){

}
