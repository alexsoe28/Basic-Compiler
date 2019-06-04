#include <string>
#include <bitset>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
#include "lyutils.h"
#include "symtable.h"
#include "yyparse.h"
#include "astree.h"

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

string to_string(symbol_table* table, int depth) {
    if(table == nullptr) return "";
    string ret = "";
    ret += "size = " + to_string(table->size())+ "\n";
    for(auto x : *table) {
       const string* ident = x.first;
       symbol* entry = x.second;
       for(int i = 0; i < depth; i++) {
           ret += "   ";
       }
       ret += *ident + bitset_to_string(entry->attributes);
       ret += "\n";
       ret += to_string(entry->fields, depth+1);
    }        
    return ret;
}
