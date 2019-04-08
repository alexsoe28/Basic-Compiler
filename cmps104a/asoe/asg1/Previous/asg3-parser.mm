.so Tmac.mm-etc
.if t .Newcentury-fonts
.INITR* \n[.F]
.SIZE 12 14
.TITLE CMPS-104A Fall\~2018 Project\~3 \
"LALR(1) Parser using \f[CB]bison\f[P]"
.RCS "$Id: asg3-parser.mm,v 1.184 2018-10-17 14:05:00-07 - - $"
.PWD
.URL
.GETST* META_NOTATION Figure_META_NOTATION
.GETST* OC_GRAMMAR Figure_OC_GRAMMAR
.GETST* OPER_PRECEDENCE Figure_OPER_PRECEDENCE
.GETST* EXAMPLE_CODE Figure_EXAMPLE_CODE
.GETST* EXAMPLE_AST_1 Figure_EXAMPLE_AST_1
.GETST* EXAMPLE_AST_2 Figure_EXAMPLE_AST_2
.GETST* CONFIG_OPTIONS Figure_CONFIG_OPTIONS
.GETST* PARSER_BEGIN Figure_PARSER_BEGIN
.nr Grammar_Pi \n[Pi]*11/4
.nr Margin_Pi \n[Pi]/3
.ds STICK \s+2\v'+1p'|\v'-1p'\s-2
.ds OBRACK \s+2[\s-2
.ds CBRACK \s+2]\s-2
.ds PICDOTS \[bu]\0\[bu]\0\[bu]
.ds ARROW \[->]\0
.nr ARROW_SIZE \w'\*[ARROW]'
.nr STICK_SIZE \w'\*[STICK]'
.nr CONT_ADJUST \n[ARROW_SIZE]-\n[STICK_SIZE]
.de *|
.   RB \*[STICK]
.   *Continuation 0 \\$@
..
.de *[
.   RI \*[OBRACK]
.   *Continuation 0 \\$@
..
.de *]
.   RI \*[CBRACK]
.   *Continuation 0 \\$@
..
.de *]...
.   RI \*[CBRACK]\|.\|.\|.\&
.   *Continuation 0 \\$@
..
.de RULE
.   LI "\\$[1]"
.   RI \*[ARROW]
.   *Continuation 1 \\$@
..
.de CONT
.   LI "\0"
.   RI \h'\\n[CONT_ADJUST]u'
.   *Continuation 0 \\$@
..
.nr SUBST_COUNT 0 1
.de SUBST_LIST
.   V= \\$[1] \\$[2]
.   ds SUBST_LIST_\\n+[SUBST_COUNT] \\$[1]
.   SETR SUBST_HEADER_\\n[SUBST_COUNT]
..
.de SUBST_PRINT_HN
.   GETHN SUBST_HEADER_\\n[SUBST_INDEX] SUBST_HN
.   V= \\*[SUBST_LIST_\\n[SUBST_INDEX]] \~(\[sc]\\*[SUBST_HN])\\$[1]
..
.de SUBST_PRINT
.   nr SUBST_INDEX 0 1
.   br
.   while \\n+[SUBST_INDEX]<\\n[SUBST_COUNT] \{\
.      SUBST_PRINT_HN ,
.      if \\n[SUBST_INDEX]%4==0 .br
.   \}
.   SUBST_PRINT_HN \&.
.   br
..
.H 1 Overview
Augment your string table and scanner by adding an
.V= oc
parser to the project.
The output of this project will be an abstract syntax tree written to
the file
.IV program .ast ,
in addition to the files generated from the previous two projects.
All specifications from the first two projects apply,
and in addition, the
.V= -y
flag must turn on
.V= yydebug .
.SH=BVL
.MANPAGE=LI SYNOPSIS
.V= oc
.=V \|[ -ly ]
.=V \|[ -@
.IR flag \|.\|.\|.]
.=V \|[ -D
.IR string ]
.IR \|program \f[CB].oc\f[P]
.LE
.P
The main function will open a pipe to the C preprocessor as before,
but will never call
.V= yylex() .
Instead it makes a single call to
.V= yyparse() ,
which will call
.V= yylex()
as needed.
When 
.V= yyparse()
returns, the main function will call a function to dump the AST.
The function
.V= yyparse()
calls
.V= yyerror()
to print an error message
whenever it detects a syntax error and has to recover.
The
.V= -y
flag must turn on the
.V= yydebug
switch.
Generate a file called
.IV program .ast
based on the input file name,
and also generate all files specified in earlier projects.
.H 1 "The Metagrammar"
When reading the grammar of
.V= oc ,
it is important to distinguish between the grammar and the
metagrammar. 
the metagrammar is the grammar that describes the grammar.
You must also use your knowledge of C to fill in what
is only implied.
The metalanguage redundantly uses fonts and typography
to represent concepts for the benefit of those reading
this document via simple ASCII text.
It looks prettier in the Postscript version.
Note that the meta-brackets and meta-stick are slightly larger
than normal type.
The notation used is shown in Figure \*[Figure_META_NOTATION].
.br
.DF
\&
.br
.B1
.SP
.VL \n[Grammar_Pi] \n[Margin_Pi] 1
.LI "\*[OBRACK] \f[BI]x\f[R] \*[CBRACK]"
Brackets indicate the the symbols are optional.
.LI "\*[OBRACK] \f[BI]x\f[R] \*[CBRACK]\|.\|.\|.\&"
Brackets and dots mean that the symbols
occur zero or more times.
.LI "\f[BI]x\f[R] \*[STICK] \f[BI]y\f[R]"
A bar indicates alternation between its left and right operands.
.LI "`\f[CB]while\f[R]'"
Symbols themselves
and written in
.V= "Courier bold"
and quoted. 
.LI "symbol"
Nonterminal symbols are written in lower case Roman.
.LI "\fI\s-3TOKEN\s+3\fP"
Token classes
are written in \s-3\f[I]UPPER CASE SMALL ITALIC\f[R]\s+3.
.SP
.B2
.FG "\f[B]Metagrammar for \f[CB]oc\f[P]\f[R]" "" 0 META_NOTATION
.DE
.H 1 "The Grammar of \f[CB]oc\f[P]"
The context-free grammar of
.V= oc 
is shown in Figure \*[Figure_OC_GRAMMAR].
Your task is to translate that descriptive user-grammar into
LALR(1) form acceptable to
.V= bison .
You may, of course,
take advantage of 
.V= bison 's
ability to handle ambiguous grammars via the use of precedence
and associativity declarations.
The dangling
.V= else
problem should also be handled in that way.
.P
You will not be able to feed the grammar above to
.V= bison ,
because it will not be able to handle
.*SI BINOP
and
.*SI UNOP
as you might expect.
You will need to explicitly enumerate all possible rules
with operators in them.
However, using
.V= bison 's
operator precedence declarations,
the number of necessary rules will be reduced.
Operator precedence and associativity is shown in
Figure \*[Figure_OPER_PRECEDENCE].
.P
There is actually more information there than that which will
be useful in 
.V= %left
and
.V= %right
declarations.
In addition,
it is necessary to eliminate the metagrammar's
optional and repetitive brackets,
a feature that
.V= bison
does not have.
.br
.DF
\&
.br
.B1
.SP
.VL \n[Grammar_Pi] \n[Margin_Pi] 1
.RULE program *[ *R structdef *| *R function *| *R globaldecl *]...
.RULE structdef *'V struct *SI TYPEID \
*'V { *[ *R fielddecl *'V ; *]... *'V }
.RULE fielddecl *R basetype *[ *'V [] *] *SI FIELD
.RULE basetype *'V void *| *'V int *| *'V string *| *SI TYPEID
.RULE globaldecl *R identdecl *'V = *R constant *'V ;
.RULE function *R identdecl \
*'V ( *[ *R identdecl *[ *'V , *R identdecl *]... *] *'V ) *R fnbody
.RULE identdecl *R basetype *[ *'V [] *] *SI DECLID
.RULE fnbody *'V { *[ *R localdecl *]... *[ *R statement *]... *'V } *| *'V ;
.RULE localdecl *R identdecl *'V = *R expr *'V ;
.RULE statement *R block \
*| *R while *| *R ifelse *| *R return *| *R expr *'V ; *| *'V ;
.RULE block *'V { *[ *R statement *]... *'V }
.RULE while *'V while *'V ( *R expr *'V ) *R statement
.RULE ifelse *'V if *'V ( *R expr *'V ) *R statement \
*[ *'V else *R statement *]
.RULE return *'V return *[ *R expr *] *'V ;
.RULE expr *R expr *SI BINOP *R expr *| *SI UNOP *R expr \
*| *'V new *R allocation *| *R call
.CONT *| *'V ( *R expr *'V ) *| *R variable *| *R constant
.RULE allocation *SI TYPEID *| *'V string *'V ( *R expr *'V ) \
*| *R basetype *'V [ *R expr *'V ]
.RULE call *SI IDENT *'V ( *[ *R expr *[ *'V , *R expr *]... *] *'V )
.RULE variable *SI IDENT *| *R expr *'V [ *R expr *'V ] \
*| *R expr *'V -> *SI FIELD
.RULE constant *SI INTCON *| *SI CHARCON *| *SI STRINGCON *| *'V null
.LE
.SP
.B2
.FG "\f[B]Grammar of \f[CB]oc\f[P]\f[R]" "" 0 OC_GRAMMAR
.DE
.DF
.TS
expand box tab(|); |l |l |l |l |lw(111p) |.
Precedence|Associativity|Arity|Fixity|\fROperators\FP
_
lowest|right|binary/ternary|matchfix|T{
.fi
.V= \&if\0
.V= \&else\0
T}
|right|binary|infix|T{
.fi
.V= \&=\0
T}
|left|binary|infix|T{
.fi
.V= \&==\0
.V= \&!=\0
.V= \&<\0
.V= \&<=\0
.V= \&>\0
.V= \&>=
T}
|left|binary|infix|T{
.fi
.V= \&+\0
.V= \&-\0
T}
|left|binary|infix|T{
.fi
.V= \&*\0
.V= \&/\0
.V= \&%\0
T}
|right|unary|prefix|T{
.fi
.V= \&+\0
.V= \&-\0
.V= \&not\0
.V= \&new\0
T}
|left|binary/variadic\0|postfix|T{
.fi
.V= \&\fIe\fP[\fIe\fP]\0
.V= \&\fIe\fP->\fIi\fP\0
.V= \&\fIf\fP(\fI...\fP)
T}
highest|\[em]|unary|matchfix|T{
.fi
.V= \&(\fIe\fP)\0
T}
.TE
.SP .75v
.FG "\f[B]Operator precedence in \f[CB]oc\f[R]" "" 0 OPER_PRECEDENCE
.DE
.H 1 "Constructing the Abstract Syntax Tree"
The abstract syntax tree (AST) is constructed in such a way 
that all operators and operator-like tokens are the parents of
their operands, 
which are adopted as their children.
The children may be leaf nodes (identifiers or constants)
or other expressions.
Constants and identifiers are always leaf nodes.
In general,
interior nodes may have an arbitrarily large number of children.
This is the case wherever the grammar shows ``\|.\|.\|.\|''
indicating repetition.
.P
There are also several situations where the scanner can not
distinguish between tokens which have the same lexical structure,
but become different syntactically.
For example,
the operators
.V= +
and
.V= -
may be either unary or binary,
and a sequence of characters like
.V= -123
must be scanned as two separate tokens.
.P
Also,
the difference between an identifier and a type id can only
be determined by the parser, 
not the scanner,
as can the overloaded use of
.V= =
as either a variable declaration initializer or an assignment operator.
.H 2 "The Root Token"
At the root of the entire AST is the root token,
with code 
.SUBST_LIST TOK_ROOT .
This is a token synthesized by the parser,
since there are no characters at the beginning of the program
for the scanner to make with this.
The parser creates this root token as its first action,
when reducing the empty right hand side to a 
.V= program .
.H 2 "Identifiers"
There are multiple different tokens all of which have the appearance of
being identifiers.
The scanner distinguishes and returns special token codes for
reserved words,
but returns all others as
.V= TOK_IDENT .
The parser must then substitute
.V= TOK_IDENT
depending on the context.
This makes the symbol table and type checker easier to implement.
.ALX a ()
.LI
In a field declaration,
substitute
.V= TOK_FIELD .
.LI
In a variable or function declaration,
substitute
.SUBST_LIST TOK_DECLID .
A
.V= TOK_DECLID
and a
.V= TOK_IDENT
are exactly the same,
except that the first appears in a declaration and the second in
a variable or function reference.
.LI
In a structure type declaration,
or a use of a structure type in a variable declaration or
function return type,
substitute
.V= TOK_TYPEID .
.LE
.H 2 "Structure Definitions"
A structure defines a new data type and may only appear as a global
statement.
The
.V= struct
keyword can serve as the root,
with the braces and internal semicolons being discarded.
The
.V= TYPEID
name is the first child,
similar to a call statement,
with each of the field definitions following as the other children
in their declared order.
The scanner will return the
.V= TYPEID
name as a
.V= TOK_IDENT ,
so change it to
.SUBST_LIST TOK_TYPEID .
.H 2 "Operators"
Operators are interior nodes whose children are their operands.
.H 3 "Binary operators"
The binary operators each have two children,
the left being the first,
and the right being the second.
.ALX a ()
.LI
The field selector
.=V ( -> )
behaves syntactically as a binary operator,
but its right operand is a field selector,
not an identifier,
so change the right operand's token code to 
.SUBST_LIST TOK_FIELD .
.LI
The array indexing operator
.=V ( [] )
is syntactically a postfix matchfix operator.
Use the left bracket as the operator and change its token code to
.SUBST_LIST TOK_INDEX .
Discard the right bracket.
The left child is the left operand and the right child is
the expression between the brackets.
.H 3 "Unary operators"
The unary operators have one child each,
but since additon
.=V ( + )
and subtraction
.=V ( \- )
are overloaded,
at the time the parser has these operators adopt the child,
The token codes should be changed to
.SUBST_LIST TOK_POS
and
.SUBST_LIST TOK_NEG ,
respectively.
.H 3 "Variadic operators"
Variadic operators take a variable number of children as arguments.
They can take a variable number of arguments.
The only one in
.V= oc
is the
.V= TOK_CALL 
operator, whose first child is always an identifier,
and whose later children are the arguments found between the
parentheses of the argument list.
Use the left parenthesis as the operator itself and change its token
code to
.SUBST_LIST TOK_CALL 
before adopting the children.
Discard the right parenthesis.
.H 3 "Allocator operator \f[CB]new\f[P]"
The allocator operator
.V= new
is used to allocate a structure object or an array.
Since constructors are not supported,
.V= string
is treated as a special case.
.ALX a ()
.LI
If the word following
.V= new
is an
.V= IDENT ,
change the token code to
.V= TYPEID ,
and have
.V= TOK_NEW 
adopt it as its only child.
.LI
In the case of allocating an array,
change the token code to 
.SUBST_LIST TOK_NEWARRAY
as a binary operator and make the two children the
.V= TYPEID
and the dimension expression.
.LI
If a 
.V= string
is being allocated,
change the token code to
.SUBST_LIST TOK_NEWSTR
as a unary operator with the expression as its child.
.H 3 "Grouping parentheses"
Parentheses which are used to override precedence are discarded
from the abstrct syntax tree, since the tree structure itself
shows the order of evaluation.
The AST for the parenthesized expression is just the expression.
Both parentheses are discarded.
.H 2 "Statement Keywords as Operators"
The statement keywords
.V= while ,
.V= if ,
and
.V= return
have ``operands'' which will be adopted as their children.
These are not really operators in the sense of returning results,
but syntactically they function in the same way.
Blocks and variable declarations are also statements which must have
some kind of operator at the root.
.H 3 "The \f[CB]while\f[P] statement"
The 
.V= while
statement always has two ``operands'' and so should adopt two
children, the first one being the root of the expression,
and the second being the root of the statement following it.
Discard the parentheses around the expression.
.H 3 "The \f[CB]if\f[P]-\f[CB]else\f[P] statement"
The
.V= if
statement might have two or three children,
depending on whether or not the optional
.V= else
is present.
The first child is the expression 
and the second child is the statement following it.
Discard the parentheses around the expression.
.ALX a ()
.LI
If an
.V= else
is present,
the
.V= else
token is discarded and the
.V= if
token adopts the statement following the else as the third child.
The token code
.SUBST_LIST TOK_IF
may have either two or three children\(::
two if the
.V= else
is missing,
and three if it is there.
.LI
If there is no
.V= else ,
then the two children are the expression and the statement.
.LE
.H 3 "The \f[CB]return\f[P] statement"
The
.V= return
keyword may or may not have an operand.
It is marked optional in the grammar,
because the parser has no way to determine whether or not an
operand to
.V= return
is required or prohibited.
The latter decision is made by later semantic routines.
The semicolon is discarded.
If
.V= return
has an expression, it is adopted as its child.
.H 3 "The block statement"
A block is a series of statements enclosed between braces.
The left brace has its token code changed to
.SUBST_LIST TOK_BLOCK ,
and adopts the roots of each of the interior statements.
The right brace is discarded.
.H 3 "The semicolons statement"
A semicolon by itself is just a vacuous block,
and the semicolon itself is the AST.
This also distinguishes a function definition from a prototype.
.H 3 "The expression statement"
When an expression is used as a statement,
the root of the expression becomes the root of the statement.
The semicolon is discarded.
.H 3 "The variable declaration statement"
A variable declaration has as its root the equal symbol which links the
actual declaration with its initial value.
The left child is an identifier declaration and the right
child is the expression.
To avoid confusion with the assignment operator,
the token code of the equal symbol here is changed to
.SUBST_LIST TOK_VARDECL .
.H 2 "Function Definitions"
The most complicated part of parsing global units is the function.
It has a prototype and either a body or just a semicolon.
The prototype consists of an identifier declaration and a parameter
list.
.P
It consists of a
.SUBST_LIST TOK_FUNCTION
with three children\(::
the identifier declaration,
the parameter list,
and the block.
For the parameter list, 
change the open parenthesis token code to 
.SUBST_LIST TOK_PARAM
and have it adopt each of the parameters.
It will always be there but may possibly have no children.
Like
.V= TOK_ROOT ,
the
.V= TOK_FUNCTION
node can be spontaneously generated with the serial number of
the first token in the function.
.P
If instead of a block,
there is only a semicolon,
then the parent node in a function is a
.SUBST_LIST TOK_PROTO ,
and it has only two children.
.H 2 "Miscellaneous"
A few miscellaneous ideas do not strictly belong to a unique one
of the categories above.
.ALX a ()
.LI
.BR "Synthesized tokens\(::"
There are three tokens that are not identified and returned by
the scanner\(::
.V= TOK_ROOT ,
.V= TOK_FUNCTION ,
and
.V= TOK_PROTOTYPE .
Semantic actions that are part of the parser will create these
tokens.
Use the serial number
.V= 0.0.0
for 
.V= TOK_ROOT ,
and the serial number from the first token of a function for
.V= TOK_FUNCTION ,
or prototype for
.V= TOK_PROTOTYPE .
.LI
.BR "Identifier declarations\(::"
Identifier declarations are part of a declaration,
but otherwise can not exist on their own.
They are always associated with an initialized variable declaration,
a structure field,
or a parameter list,
or a function definition.
The type itself can serve as a root,
with the identifier being its child.
In the case of an array,
which is a generic data type,
the array token
.V= TOK_ARRAY
can be the root,
with the base type and identifier being children.
Note that
.V= TOK_ARRAY ,
lexical
.=V ( [] )
is a single token,
different from the left
.=V ( [ )
and and right 
.=V ( ] )
bracket tokens.
.LI
.BR "Substituted token codes\(::"
In order to make the later phases of the compiler simpler and
capable of having individual components chosen by a large
.V= switch
statement,
the parser substitutes a token code initialized by the scanner
to something else.
.LI
.BR "Parser's token codes\(::"
Following are the synthesized and substituted token codes
described above which are introduced by
the parser, with the sections wherein they were defined\(::
.P
.SUBST_PRINT
.LE
.H 1 "The Parser"
Start out with a
.V= parser.y
which will generate a header file and a C source file.
Develop it incrementally,
possibly using routines from the example 
.V= expr-smc ,
bearing in mind that that code does not exactly fit this project.
Use the declarations shown in Figure \*[Figure_CONFIG_OPTIONS]
in section 1 of the grammar to configure your parser.
.br
.DF
\&
.br
.B1
.SP
.ft CB
.nf
.in \n[Margin_Pi]
%debug
%defines
%error-verbose
%token-table
%verbose
%start start
\&
.B2
.FG "Parser configuration options" "" 0 CONFIG_OPTIONS
.DE
.P
.ne 3
Your program will need to perform some syntax error checking and
recovery,
although not much sophistication is required.
Use the code shown in Figure \*[Figure_PARSER_BEGIN]
at the beginning of your grammar section 
to set up the root of the AST and return it back to main.
When there is a syntax error,
an attempt to recover will be done by searching forward for a
closing brace or a semicolon.
.br
.DF
\&
.br
.B1
.SP
.ft CB
.nf
.in \n[Margin_Pi]
start    : program            { yyparse_astree = $1; }
         ;
program  : program structdef  { $$ = $1->adopt ($2); }
         | program function   { $$ = $1->adopt ($2); }
         | program statement  { $$ = $1->adopt ($2); }
         | program error '}'  { $$ = $1; }
         | program error ';'  { $$ = $1; }
         |                    { $$ = parser::root; }
         ;
.SP
.B2
.FG "Beginning parser code" "" 0 PARSER_BEGIN
.DE
.P
All other AST nodes are adopted by the root,
which is a synthetically manufactured token
(not created by the scanner).
The parser needs a way to communicate with the main function,
but has no communication results or parameters,
so the global variable
.V= parser::root
will be used for that purpose.
.P
All actions in the parser should be simple.
Use function calls when that is not the case.
Actions should be of one of the following two forms\(::
.VTCODE* 1 "{ $$ = \fIsimple expression\fP; }
.VTCODE* 1 "{ $$ = \fIfncall (args\|.\|.\|.\|)\fP; }
.P
Neatly line up all of the nonterminals in the first column,
all of the colon
.=V ( : ),
alternation 
.=V ( | ),
and action
.=V ( { )
characters so that the grammar is easy to read.
You should use
.V= valgrind
to detect uninitialized variables and memory leak.
.H 1 "Displaying the AST"
After constructing an AST from a file called
.IV program .oc ,
write a file called
.IV program .ast ,
containing a representation of the AST in text form,
printed using a depth-first pre-order traversal,
showing depth via indententation.
.P
Each line is indented to show its distance from the root,
with a line upward immediately to its right that points at its parent.
After the indentation print the symbolic token code,
lexical information in
double quotation marks,
and the serial number consisting of a file number,
a line number, and an offset.
During project 4,
this will also have type information following it.
.P
All functions and global declarations will appear
under the root,
.V= TOK_ROOT .
If an include file is present,
the contents of that file will also be printed
under
.V= TOK_ROOT
as well,
with only the file numbers leaving a clue as to where the code
originated.
.P
The program shown in Figure \*[Figure_EXAMPLE_CODE]
would be printed as an AST as shown in Figure \*[Figure_EXAMPLE_AST_1]
and Figure \*[Figure_EXAMPLE_AST_2].
To avoid clutter, the prefix
.V= TOK_
has been omitted from the printed tree.
The prefix was used in the C code to avoid possible name clashes.
The following, using pointer arithmetic,
can be used to eliminate the prefix\(::
.DS
.VTCODE* 1 "const char *tname = get_yytname (symbol);"
.VTCODE* 1 "if (strstr (tname, \[Dq]TOK_\[Dq]) == tname) tname += 4;"
.DE
.br
.DF
\&
.br
.B1
\&
.ft CR
     0  #include "oclib.h"
     1  int fac (int n) {
     2     int f = 1;
     3     while (n > 1) {
     4        f = f * n;
     5        n = n - 1;
     6     }
     7     return f;
     8  }
     9  int main() {
    10     int n = 1;
    11     while (n <= 5) {
    12        putint (fac (n));
    13        n = n + 1;
    14     }
    15     return EXIT_SUCCESS;
    16  }
.SP
.B2
.FG "Example program" "" 0 EXAMPLE_CODE
.DE
.DF
.B1
\&
.br
.ft CR
.nf
.in \n[Margin_Pi]
.ds ; |\0\0
ROOT "" 5.0.0
\*;FUNCTION "" 5.1.0
\*;\*;INT "int" 5.1.0
\*;\*;\*;DECLID "fac" 5.1.4
\*;\*;PARAM "(" 5.1.8
\*;\*;\*;INT "int" 5.1.9
\*;\*;\*;\*;DECLID "n" 5.1.13
\*;\*;BLOCK "{" 5.1.15
\*;\*;\*;VARDECL "=" 5.2.9
\*;\*;\*;\*;INT "int" 5.2.3
\*;\*;\*;\*;\*;DECLID "f" 5.2.7
\*;\*;\*;\*;INTCON "1" 5.2.9
\*;\*;\*;WHILE "while" 5.3.3
\*;\*;\*;\*;GT ">" 5.3.10
\*;\*;\*;\*;\*;IDENT "n" 5.3.8
\*;\*;\*;\*;\*;INTCON "1" 5.3.12
.SP
.B2
.FG "Example AST" "" 0 EXAMPLE_AST_1
.DE
.DF
\&
.br
.B1
\&
.br
.ft CR
.nf
.in \n[Margin_Pi]
.ds ; |\0\0
\*;\*;\*;\*;BLOCK "{" 5.3.14
\*;\*;\*;\*;\*;'=' "=" 5.4.8
\*;\*;\*;\*;\*;\*;IDENT "f" 5.4.6
\*;\*;\*;\*;\*;\*;'*' "*" 5.4.12
\*;\*;\*;\*;\*;\*;\*;IDENT "f" 5.4.10
\*;\*;\*;\*;\*;\*;\*;IDENT "n" 5.4.12
\*;\*;\*;\*;\*;'=' "=" 5.5.8
\*;\*;\*;\*;\*;\*;IDENT "n" 5.5.6
\*;\*;\*;\*;\*;\*;'-' "-" 5.5.12
\*;\*;\*;\*;\*;\*;\*;IDENT "n" 5.5.10
\*;\*;\*;\*;\*;\*;\*;INTCON "1" 5.5.12
\*;\*;\*;RETURN "return" 5.7.3
\*;\*;\*;\*;IDENT "f" 5.7.10
\*;FUNCTION "" 5.9.0
\*;\*;INT "int" 5.9.0
\*;\*;\*;DECLID "main" 5.9.4
\*;\*;PARAM "(" 5.9.8
\*;\*;BLOCK "{" 5.9.11
\*;\*;\*;VARDECL "=" 5.10.9
\*;\*;\*;\*;INT "int" 5.10.3
\*;\*;\*;\*;\*;DECLID "f" 5.10.7
\*;\*;\*;\*;INTCON "1" 5.10.9
\*;\*;\*;WHILE "while" 5.10.3
\*;\*;\*;\*;GT "<=" 5.10.10
\*;\*;\*;\*;\*;IDENT "n" 5.10.8
\*;\*;\*;\*;\*;INTCON "5" 5.10.13
\*;\*;\*;\*;BLOCK "{" 5.10.14
\*;\*;\*;\*;\*;CALL "(" 5.12.3
\*;\*;\*;\*;\*;\*;IDENT "putint" 5.12.9
\*;\*;\*;\*;\*;\*;CALL "(" 5.12.13 
\*;\*;\*;\*;\*;\*;\*;IDENT "fac" 5.12.11 
\*;\*;\*;\*;\*;\*;\*;IDENT "n" 5.12.15 
\*;\*;\*;\*;\*;'=' "=" 5.13.5
\*;\*;\*;\*;\*;\*;IDENT "n" 5.13.3
\*;\*;\*;\*;\*;\*;'+' "+" 5.13.9
\*;\*;\*;\*;\*;\*;\*;IDENT "n" 5.13.7
\*;\*;\*;\*;\*;\*;\*;INTCON "1" 5.13.11 
\*;\*;\*;RETURN "return" 5.15.3
\*;\*;\*;\*;INTCON "0" 5.15.10
.SP
.B2
.FG "Example AST (continued)" "" 0 EXAMPLE_AST_2
.DE
.FINISH
