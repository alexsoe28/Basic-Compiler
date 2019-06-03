#include "generateTable.h"
#include <assert.h>
#include "yyparse.h"
#include "symtable.h"
#include "astree.h"
symbol_table local_table;                                      
symbol_table global_table;                                     
symbol_table struct_table;                                     
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
    switch(node->symbol){
        case TOK_VOID: {
            node->attributes.set(unsigned(attr::ATTR_void)); 
            break;
        }
        case TOK_INT: {
            node->attributes.set(unsigned(attr::ATTR_int));
            break;
        }
        case TOK_NULLPTR: {
            node->attributes.set(unsigned(attr::ATTR_nullptr_t));
            node->attributes.set(unsigned(attr::ATTR_const));
            break;
        }
        case TOK_STRING: {
            node->attributes.set(unsigned(attr::ATTR_string));
            break;                                                    
        }
        case TOK_INTCON:
        
        case TOK_CHARCON: {
            node->attributes.set(unsigned(attr::ATTR_int));
            node->attributes.set(unsigned(attr::ATTR_const));
            break;
        }
        case TOK_STRINGCON: {
            node->attributes.set(unsigned(attr::ATTR_string));
            node->attributes.set(unsigned(attr::ATTR_const));
            break;
        }

        case TOK_NOT:
        case '-': {
            if(node->children.size() == 2){
                assert(node->children[0]->
                       attributes[unsigned(attr::ATTR_int)]);
                assert(node->children[1]->
                       attributes[unsigned(attr::ATTR_int)]);
                node->attributes.set(unsigned(attr::ATTR_int));
                node->attributes.set(unsigned(attr::ATTR_vreg));
                break;
            }
            else if(node->children.size() == 1){
                assert(node->children[0]->
                       attributes[unsigned(attr::ATTR_int)]);
                node->attributes.set(unsigned(attr::ATTR_int));
                node->attributes.set(unsigned(attr::ATTR_vreg));
                break;
            }
            break;
        }
        case '+':
        case '*':
        case '%':
        case '/':
        case '>':
        case TOK_LE:
        case TOK_GE:
        case '<': {
            assert(node->children.size() == 2);
            assert(node->children[0]->
                   attributes[unsigned(attr::ATTR_int)]);
            assert(node->children[1]->
                   attributes[unsigned(attr::ATTR_int)]);
            node->attributes.set(unsigned(attr::ATTR_int));
            node->attributes.set(unsigned(attr::ATTR_vreg));
            break;
        }
        case TOK_NE:
        case TOK_EQ: {
            assert(node->children.size() == 2);
            assert(isMatching(node->children[0], node->children[1]));
            node->attributes.set(unsigned(attr::ATTR_int));
            node->attributes.set(unsigned(attr::ATTR_vreg));
            break;
        }
        case TOK_VARDECL: {
            const string* key = node->children[0]->children[0]->lexinfo;
            symbol* var_sym = new_sym(node);
            symbol_entry var_entry (key, var_sym);
            assert(node->children.size() == 2);
            assert(isMatching(node->children[0], node->children[1]));
            node->children[0]->children[0]->attributes 
            = node->children[0]->attributes;
            if(block_nr != 0){
               local_table.insert(var_entry); 
            }
            else{
               global_table.insert(var_entry);
            }
            break;
        }
        case TOK_FUNCTION: {
            block_nr++;
            break;
        }
        case TOK_PROTOTYPE: { 
            block_nr++;
            break;
        }
        default:
            break;
    }
}

void postOrderTraversal(astree* node){
    for(unsigned int i = 0; i < node->children.size(); i++){
        postOrderTraversal(node->children[i]);
    }
    type_check(node);
}

