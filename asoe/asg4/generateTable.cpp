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
            const string* key = node->children[0]->children[0]->lexinfo;
            symbol* var_sym = new_sym(node);
            symbol_entry var_entry (key, var_sym);
            assert(node->children.size() == 2);

            if(node->children[0]->symbol != TOK_ARRAY){
                assert(isMatching(node->children[0],
                       node->children[1]));
                node->children[0]->children[0]->attributes 
                = node->children[0]->attributes;
            }
            else{
                 assert(isMatching(node->children[0]->children[0],
                 node->children[1]->children[0]->children[0])); 
            }
            if(in_func != 0){
               local_table.insert(var_entry); 
            }
            else{
               global_table.insert(var_entry);
            }
            return;
        }
        
        case TOK_FUNCTION: {
            for(astree* child: node->children){
                type_check(child);
            }

            in_func = 1;
            block_nr++;

            in_func = 0; 
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
            node->attributes.set(unsigned(attr::ATTR_array));
            return;
        }

        default:
            if(node->children.size() > 0){
                for(astree* child: node->children){
                    type_check(child);
                }   
            }
            return;
        }


   //}
}
/*
void postOrderTraversal(astree* node){
    for(unsigned int i = 0; i < node->children.size(); i++){
        postOrderTraversal(node->children[i]);
    }
    type_check(node);
}
*/
