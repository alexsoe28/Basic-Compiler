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
    new_symbol->parameters = nullptr;
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

void type_check (astree* node){
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
            
            const string* key = 
                   node->children[0]->children[0]->lexinfo;
            symbol* var_sym = new_sym(node);
            symbol_entry var_entry (key, var_sym);
         
            astree* type = node->children[0];
            astree* params = node->children[1];
 
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

           
           for(unsigned i = 0; i < params->children.size(); i++){
                type_check(params->children[i]);
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
            printf("In block \n");
            fflush(stdin);
            for(astree* child: node->children){
                type_check(child);
            }   
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
   fprintf(outfile, "%s\n", to_string(&global_table, 0).c_str());
   fprintf(outfile, "%s\n", to_string(&local_table, 0).c_str());
   fprintf(outfile, "%s\n", to_string(&struct_table, 0).c_str());  
}


/*
void postOrderTraversal(astree* node){
    for(unsigned int i = 0; i < node->children.size(); i++){
        postOrderTraversal(node->children[i]);
    }
    type_check(node);
}
*/

/*
void set_variables(astree* node, symbol* sym){
     sym->attributes.set(unsigned(attr::ATTR_variable));
        sym->attributes.set(unsigned(attr::ATTR_variable));
        switch(node->symbol){
          case TOK_INT:{
             sym->attributes.set(unsigned(attr::ATTR_variable));
             sym->attributes.set(unsigned(attr::ATTR_int));
          }
          case TOK_PTR:{
             node->attributes.set(unsigned(attr::ATTR_ptr));
             node->attributes.set(unsigned(attr::ATTR_ptr));    
             break; 
          }
      case TOK_STRING:{
             node->attributes.set(unsigned(attr::ATTR_string));
             node->attributes.set(unsigned(attr::ATTR_int));
             break;    
         }
        }


}
*/
