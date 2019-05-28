//Ashley Lavizadeh & Alex Soe

#ifndef __SYMTABLE_H__
#define __SYMTABLE_H__
#include <string>
#include <bitset>
#include <iostream>
#include <unordered_map>
#include <utility
#include <vector>

using namespace std;
enum class attr { ATTR_void, ATTR_bool, ATTR_char, ATTR_int, ATTR_null,
	ATTR_string, ATTR_struct, ATTR_array, ATTR_function,
	ATTR_prototype, ATTR_variable, ATTR_field, ATTR_typeid,
	ATTR_param, ATTR_lval, ATTR_const, ATTR_vreg, ATTR_vadder,
	ATTR_bitset_size
};
struct symbol;

//names for symbol fields
using attr_bitset = bitset<attr::ATTR_bitset_size>;
using symbol_table = unordered_map<const string*, symbol*>;
using symbol_entry = pair<const string*,symbol*>;

struct lloc{
	size_t filenr;
	size_t linenr;
	size_t offset;

}
struct symbol {
	attr_bitset attributes;
	symbol_table *fields;
	lloc location;
	size_t blocknr;
	symbol *parameters;
	const string *type_name;
};





#endif


