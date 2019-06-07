#include "generateTable.h"
#include <assert.h>
#include "yyparse.h"
#include "symtable.h"
#include "astree.h"
symbol_table local_table;                                      
symbol_table global_table;                                     
symbol_table struct_table; 
bool in_func = 0;                                    
int block_nr = 0;
int next_block = 1;
symbol* new_sym (astree* node) {
    symbol* new_symbol = new symbol();
    new_symbol->attributes = node->attributes;
    new_symbol->fields = nullptr;
    new_symbol->lloc = node->lloc;
    new_symbol->parameters = new vector<symbol*>();
    return new_symbol;
}

bool isMatching(astree* node1, astree* node2){
    
    if((node1->attributes[unsigned(attr::ATTR_nullptr_t)] && 
       node2->attributes[unsigned(attr::ATTR_string)]) ||
       (node1->attributes[unsigned(attr::ATTR_string)] && 
       node2->attributes[unsigned(attr::ATTR_nullptr_t)]) ||

       (node1->attributes[unsigned(attr::ATTR_ptr)] &&              
       node2->attributes[unsigned(attr::ATTR_nullptr_t)]) ||
       (node1->attributes[unsigned(attr::ATTR_nullptr_t)] && 
       node2->attributes[unsigned(attr::ATTR_ptr)]) ||

       (node1->attributes[unsigned(attr::ATTR_array)] &&   
       node2->attributes[unsigned(attr::ATTR_nullptr_t)]) ||
       (node1->attributes[unsigned(attr::ATTR_nullptr_t)] &&
       node2->attributes[unsigned(attr::ATTR_array)]) ||

       (node1->attributes[unsigned(attr::ATTR_struct)] &&
       node2->attributes[unsigned(attr::ATTR_nullptr_t)]) ||
       (node1->attributes[unsigned(attr::ATTR_nullptr_t)] &&
       node2->attributes[unsigned(attr::ATTR_struct)])){return true;}

     if((node1->attributes[unsigned(attr::ATTR_int)] !=
        node2->attributes[unsigned(attr::ATTR_int)]) ||
        
        (node1->attributes[unsigned(attr::ATTR_string)] !=
        node2->attributes[unsigned(attr::ATTR_string)]) ||
        
        (node1->attributes[unsigned(attr::ATTR_array)] !=
        node2->attributes[unsigned(attr::ATTR_array)]) ||

        (node1->attributes[unsigned(attr::ATTR_struct)] !=
        node2->attributes[unsigned(attr::ATTR_struct)]) ||
        
        (node1->attributes[unsigned(attr::ATTR_void)] !=
        node2->attributes[unsigned(attr::ATTR_void)])){return false;}
     return true;
}

void type_check (astree* node ){
printf("recursive call: %s\n", node->lexinfo->c_str()); 
   //for(unsigned int i = 0; i < node->children.size(); i++){
    switch(node->symbol){
        case TOK_VOID: {
            node->attributes.set(unsigned(attr::ATTR_void)); 
            return;
        }
        case TOK_INT: {
            node->attributes.set(unsigned(attr::ATTR_int));
            return;
        }
        case TOK_NULLPTR: {
            node->attributes.set(unsigned(attr::ATTR_nullptr_t));
            node->attributes.set(unsigned(attr::ATTR_const));
            return;
        }
        case TOK_STRING: {
            node->attributes.set(unsigned(attr::ATTR_string));
            return;                                                   
        }
        case TOK_INTCON:
        
        case TOK_CHARCON: {
            node->attributes.set(unsigned(attr::ATTR_int));
            node->attributes.set(unsigned(attr::ATTR_const));
            return;
        }
        case TOK_STRINGCON: {
            node->attributes.set(unsigned(attr::ATTR_string));
            node->attributes.set(unsigned(attr::ATTR_const));
            return;
        }

        case TOK_NOT:
        case '-':{
            for(astree* child: node->children){
                type_check(child);
            }
 
            if(node->children.size() == 2){
                assert(node->children[0]->
                       attributes[unsigned(attr::ATTR_int)]);
                assert(node->children[1]->
                       attributes[unsigned(attr::ATTR_int)]);
                node->attributes.set(unsigned(attr::ATTR_int));
                node->attributes.set(unsigned(attr::ATTR_vreg));
                return;
            }
            else if(node->children.size() == 1){
                assert(node->children[0]->
                       attributes[unsigned(attr::ATTR_int)]);
                node->attributes.set(unsigned(attr::ATTR_int));
                node->attributes.set(unsigned(attr::ATTR_vreg));
               return;
            }
            
            //type_check(node->children[i]);
            return;
        }
        case '+':
        case '*':
        case '%':
        case '/':
        case '>':
        case TOK_LE:
        case TOK_GE:
        case '<': {
            for(astree* child: node->children){
                type_check(child);
            }
            assert(node->children.size() == 2);
            assert(node->children[0]->
                   attributes[unsigned(attr::ATTR_int)]);
            assert(node->children[1]->
                   attributes[unsigned(attr::ATTR_int)]);
            node->attributes.set(unsigned(attr::ATTR_int));
            node->attributes.set(unsigned(attr::ATTR_vreg));
            
            //recursive call
            //type_check(node->children[i]);
            return;
        }
        case TOK_NE:
        case TOK_EQ: {
            
            assert(node->children.size() == 2);
            assert(isMatching(node->children[0], node->children[1]));
            node->attributes.set(unsigned(attr::ATTR_int));
            node->attributes.set(unsigned(attr::ATTR_vreg));
            
            //recursive call
            //type_check(node->children[i]);
            return;
        }
        case TOK_VARDECL: {
            for(astree* child: node->children){
                type_check(child);
            }
            //Check if the variable is an array or  ptr
            int declid = 0;
            if(node->children[0]->symbol == TOK_ARRAY ||
                node->children[0]->symbol == TOK_PTR) declid++;
 
            //Create a new symbol entry to put into table
            const string* key = 
                node->children[0]->children[declid]->lexinfo;
            symbol* var_sym = new_sym(node);
            var_sym->attributes = node->children[0]->attributes;
            symbol_entry var_entry (key, var_sym);
           
            //Change the DECLID to have the same type as the type
            node->children[0]->children[0]->attributes 
                = node->children[0]->attributes;
            if(node->children.size() == 2) {
                assert(isMatching
                (node->children[0], node->children[1]));
            }
            if(in_func != 0){
               node->children[0]->children[declid]->attributes.set
               (unsigned(attr::ATTR_local));
               local_table.insert(var_entry); 
            }
            else{
               global_table.insert(var_entry);
            }
            return;
        }
        
        case IDENT: {
            
            auto entry = local_table.find(node->lexinfo);
            if(entry == local_table.end()) {
                entry = global_table.find(node->lexinfo);
                assert(entry != global_table.end());
            }
            symbol* symbolPointer = entry->second;
            assert(symbolPointer != nullptr);
            node->attributes = symbolPointer->attributes;
            return;
        }
        case TOK_FUNCTION: {
            in_func = 1;
            node->attributes.set(unsigned(attr::ATTR_function));

            const string* key = 
                   node->children[0]->children[0]->lexinfo;
            symbol* func_sym = new_sym(node);
            symbol_entry func_entry (key, func_sym);
         
            astree* type = node->children[0];
            astree* paramList = node->children[1]->children[0];
 
           //Switch case to set attribute of function and and node
            switch(type->symbol){
                case TOK_INT:{
                     type->attributes.set(unsigned(attr::ATTR_int));
                     node->attributes.set(unsigned(attr::ATTR_int)); 
                     break; 
                }
                case TOK_VOID:{
                     type->attributes.set(unsigned(attr::ATTR_void));
                     node->attributes.set(unsigned(attr::ATTR_void));
                     break; 
                }
                case TOK_PTR:{
                     type->attributes.set(unsigned(attr::ATTR_ptr));
                     node->attributes.set(unsigned(attr::ATTR_ptr));    
                     break; 
                }
                case TOK_STRING:{
                     type->attributes.set(unsigned(attr::ATTR_string));
                     node->attributes.set(unsigned(attr::ATTR_int));
                     break;    
                }
           }

           
           for(unsigned int i = 0; i < paramList->children.size(); i++){
                type_check(paramList->children[i]);
           }
           
           for(unsigned i = 0; i < paramList->children.size(); i++){
                 const string* paramkey = 
                       paramList->children[i]->children[0]->lexinfo;

                 paramList->children[i]->children[0]->attributes = 
                       paramList->children[i]->attributes;

                 symbol* param_sym = new_sym(paramList->children[i]
                                   ->children[0]);
                 symbol_entry param_entry(paramkey, param_sym);
                 local_table.insert(param_entry);
                 func_sym->parameters->push_back(param_sym);

           }

           for(astree* child: node->children){
                type_check(child);
           } 
         
           in_func = 0;

            //block_nr++;
            return;
        }
        

        case TOK_PROTOTYPE: { 
            block_nr++;
            return;
        }
        case TOK_ARRAY:{
            for(astree* child: node->children){
                type_check(child);
            }
            node->attributes = node->children[0]->attributes;
            node->attributes.set(unsigned(attr::ATTR_array));
            return;
        }

        case TOK_BLOCK:{
            for(astree* child: node->children){
                type_check(child);
            }   
            return;
        }
        case TOK_STRUCT: {
            node->attributes.set(unsigned(attr::ATTR_struct));

            const string* key = 
                   node->children[0]->lexinfo;
            symbol* struct_sym = new_sym(node);
            struct_sym->fields = new symbol_table();
            symbol_entry struct_entry (key, struct_sym);
            struct_table.insert(struct_entry);
            
            astree* fieldList = node->children[1]; 
            for(unsigned i = 0; i < fieldList->children.size(); i++){
                const string* fieldkey = 
                      fieldList->children[i]->children[0]->lexinfo;
                type_check(fieldList->children[i]);
                fieldList->children[i]->children[0]->attributes
                        = fieldList->children[i]->attributes;
                
                symbol* field_sym = new_sym(fieldList->children[i]
                                   ->children[0]);
                symbol_entry field_entry(fieldkey, field_sym);
                struct_sym->fields->insert(field_entry);
            }
            return;
        }
        case TOK_ARROW: {
           return; 
        }
        default:{
            if(node->children.size() > 0){
                for(astree* child: node->children){
                    type_check(child);
                }   
            }
            return;
        }
  
     }
}
void printTable(FILE* outfile) {
   fprintf(outfile, "Global Table \n%s\n", 
           table_to_string(&global_table, 0).c_str());
   fprintf(outfile, "Local Table \n%s\n",
           table_to_string(&local_table, 0).c_str());
   fprintf(outfile, "Struct Table \n%s\n",
           table_to_string(&struct_table, 0).c_str()); 
}

