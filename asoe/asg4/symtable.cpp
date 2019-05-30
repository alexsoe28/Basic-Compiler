#include <string>
#include <bitset>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
#include "lyutils.h"
#include "symtable.h"
#include "astree.h"
symbol_table local_table;
symbol_table global_table;
symbol_table struct_table;
int next_block = 1;
vector<int> block_stack;
vector<symbol_table*> symStack;

const string to_string (attr attribute) {
   static const unordered_map<attr,string> hash {
      {attr::ATTR_void       , "void"       },
      {attr::ATTR_int        , "int"        },
      {attr::ATTR_nullptr_t  , "null"       },
      {attr::ATTR_string     , "string"     },
      {attr::ATTR_struct     , "struct"     },
      {attr::ATTR_array      , "array"      },
      {attr::ATTR_function   , "function"   },
      {attr::ATTR_variable   , "variable"   },
      {attr::ATTR_field      , "field"      },
      {attr::ATTR_typeid     , "typeid"     },
      {attr::ATTR_param      , "param"      },
      {attr::ATTR_lval       , "lval"       },
      {attr::ATTR_const      , "const"      },
      {attr::ATTR_vreg       , "vreg"       },
      {attr::ATTR_vaddr      , "vaddr"      },
      {attr::ATTR_bitset_size,"bitset_size"},
   };
   auto str = hash.find (attribute);
   if (str == hash.end()) {
      throw invalid_argument (string (__PRETTY_FUNCTION__) + ": "
                              + to_string (unsigned (attribute)));
   }
   return str->second;
}

const string bitset_to_string(attr_bitset attributes){
      
   string result = "";
   for(unsigned i = 0; i < unsigned(
      attr::ATTR_bitset_size); i++){
      if(attributes[i]){
          result = result + " " + to_string(static_cast<attr>(i));
      }
   }
   return result;
}

/*symbol* new_sym(astree *node){
    symbol* sym = new symbol();
    sym->filenr = node->lloc.filenr;
    sym->linenr = node->lloc.linenr;
    sym->offset = node->lloc.offset;
    sym->blocknr = static_cast<size_t>(next_block);
    set_attributes(node, sym);
    sym->attributes[ATTR_lval] = 1;
    sym->attributes[ATTR_variable] = 1;   
    return sym;
}*/


