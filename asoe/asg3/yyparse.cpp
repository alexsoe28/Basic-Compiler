/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <cassert>
#include <stdlib.h>
#include <string.h>
#include "astree.h"
#include "lyutils.h"
#include <iostream>
using namespace std;
extern FILE* outFile;
extern int exit_status;

#line 78 "yyparse.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yyparse.h".  */
#ifndef YY_YY_YYPARSE_H_INCLUDED
# define YY_YY_YYPARSE_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ROOT = 258,
    IDENT = 259,
    NUMBER = 260,
    UNOP = 261,
    BINOP = 262,
    TOK_NEWSTRING = 263,
    TOK_INDEX = 264,
    TOK_IF = 265,
    TOK_ELSE = 266,
    TOK_IFELSE = 267,
    TOK_ALLOC = 268,
    TOK_NULLPTR = 269,
    TOK_WHILE = 270,
    TOK_RETURN = 271,
    TOK_RETURNVOID = 272,
    TOK_INT = 273,
    TOK_STRING = 274,
    TOK_STRUCT = 275,
    TOK_VOID = 276,
    TOK_NULL = 277,
    TOK_ARRAY = 278,
    TOK_VARDECL = 279,
    TOK_EQ = 280,
    TOK_NE = 281,
    TOK_LE = 282,
    TOK_GE = 283,
    TOK_NOT = 284,
    TOK_PTR = 285,
    TOK_BLOCK = 286,
    TOK_CALL = 287,
    DECLID = 288,
    TOK_FUNCTION = 289,
    TOK_PROTOTYPE = 290,
    TOK_POS = 291,
    TOK_NEG = 292,
    TOK_NEWARRAY = 293,
    TOK_TYPEID = 294,
    TOK_FIELD = 295,
    TOK_ORD = 296,
    TOK_CHR = 297,
    TOK_ROOT = 298,
    TOK_PARAMLIST = 299,
    BAD_TOK = 300,
    TOK_EXC = 301,
    TOK_INTCON = 302,
    TOK_CHARCON = 303,
    TOK_STRINGCON = 304,
    TOK_ARROW = 305,
    TOK_NEQ = 306,
    TOK_LEQ = 307,
    TOK_GEQ = 308,
    POS = 309,
    NEG = 310,
    TOK_NEW = 311
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YYPARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 186 "yyparse.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   530

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,     2,     2,     2,    65,     2,     2,
      51,    52,    63,    61,    58,    62,    59,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    57,
      68,    60,    70,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,    75,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    67,    69,    71,    72,
      73,    74
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    53,    53,    56,    57,    58,    59,    60,    61,    65,
      69,    75,    78,    82,    85,    91,    92,    93,    94,    99,
     104,   110,   115,   121,   124,   127,   130,   135,   139,   145,
     147,   151,   152,   153,   154,   155,   156,   159,   165,   170,
     173,   180,   184,   189,   190,   191,   192,   193,   195,   196,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   212,   213,   214,   217,   222,   226,   234,   238,   244,
     246,   251,   252,   256,   261,   262,   263,   264
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ROOT", "IDENT", "NUMBER", "UNOP",
  "BINOP", "TOK_NEWSTRING", "TOK_INDEX", "TOK_IF", "TOK_ELSE",
  "TOK_IFELSE", "TOK_ALLOC", "TOK_NULLPTR", "TOK_WHILE", "TOK_RETURN",
  "TOK_RETURNVOID", "TOK_INT", "TOK_STRING", "TOK_STRUCT", "TOK_VOID",
  "TOK_NULL", "TOK_ARRAY", "TOK_VARDECL", "TOK_EQ", "TOK_NE", "TOK_LE",
  "TOK_GE", "TOK_NOT", "TOK_PTR", "TOK_BLOCK", "TOK_CALL", "DECLID",
  "TOK_FUNCTION", "TOK_PROTOTYPE", "TOK_POS", "TOK_NEG", "TOK_NEWARRAY",
  "TOK_TYPEID", "TOK_FIELD", "TOK_ORD", "TOK_CHR", "TOK_ROOT",
  "TOK_PARAMLIST", "BAD_TOK", "TOK_EXC", "TOK_INTCON", "TOK_CHARCON",
  "TOK_STRINGCON", "TOK_ARROW", "'('", "')'", "'['", "']'", "'{'", "'}'",
  "';'", "','", "'.'", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'",
  "TOK_NEQ", "'<'", "TOK_LEQ", "'>'", "TOK_GEQ", "POS", "NEG", "TOK_NEW",
  "'^'", "$accept", "start", "program", "structdef", "structfields",
  "structfield", "plaintype", "function", "idents", "ident", "block",
  "statements", "statement", "vardecl", "while", "ifelse", "return",
  "expr", "binop", "unop", "alloc", "call", "params", "variable",
  "constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,    40,    41,    91,    93,   123,   125,    59,    44,    46,
      61,    43,    45,    42,    47,    37,    33,   306,    60,   307,
      62,   308,   309,   310,   311,    94
};
# endif

#define YYPACT_NINF -84

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-84)))

#define YYTABLE_NINF -3

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -84,     5,    24,   -84,    45,   -28,   -19,   -35,    12,     0,
     -84,   -84,    52,   -84,   -84,    -3,   -84,   -84,   -84,    56,
      78,   -84,   -84,   -84,   -84,     7,   -84,   -44,   -84,   132,
     -84,   -84,   -84,   -84,   -84,   209,    56,   -84,   -84,   -50,
     -84,   -84,   -84,   -84,   124,    56,    64,    56,   -84,   255,
       9,    57,   268,   -84,    21,   -84,   -84,    85,   186,    56,
     -84,   -84,   -84,   -84,   -84,   -84,    88,    56,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,    56,   460,   -84,    56,
     -84,   460,   314,    25,    94,    42,   327,   -84,    -4,   107,
     -84,   -84,   -37,    16,   -84,   343,   -84,   389,   460,   460,
      58,    61,    46,   102,    58,   -84,    63,    67,     8,    60,
     -84,   -84,    -2,   102,   -84,   -84,   202,   148,    56,    84,
      68,   202,   -84,   102,   -84,   137,   -84,   -84,   -84,   -84,
      58,   402,    91,    79,   -84,   -84,   202,   -84,   -84,   104,
      56,   448,   -84
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     1,     0,    71,     0,     0,     0,     0,
      16,    17,     0,    15,    77,     0,    76,    75,    74,     0,
       0,    61,    62,    63,     3,     0,     4,     0,    31,     0,
       5,    32,    33,    34,    35,     0,     0,    45,    46,     0,
      48,    49,     6,     7,     0,     0,     0,     0,    41,     0,
       0,     0,     0,    28,     0,    30,    26,     0,     0,     0,
      27,    29,    50,    51,    53,    55,     0,     0,    36,    60,
      56,    57,    58,    59,    54,    52,     0,    44,    67,     0,
      68,    69,     0,     0,     0,     0,     0,    42,     0,     0,
      47,    25,     0,     0,    24,     0,    73,     0,    43,    70,
       0,     0,     0,     0,     0,     9,     0,     0,     0,     0,
      21,    22,     0,     0,    37,    72,     0,    39,     0,     0,
       0,    38,    10,    12,    13,     0,    18,    20,    19,    23,
       0,     0,     0,     0,    11,    14,    40,    65,    64,     0,
       0,     0,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -84,   -84,   -84,   -84,    33,   -84,   -82,   -84,   -84,     1,
     -83,   -24,    -1,   -84,   -84,   -84,   -84,    -9,   -84,   -84,
     -84,   -84,   -84,   -84,   -84
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    24,   106,   107,    25,    26,    93,    54,
      28,    29,    61,    31,    32,    33,    34,    35,    76,    36,
      37,    38,    39,    40,    41
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    30,    78,    27,     5,     3,   108,    58,    79,   111,
      52,    56,   124,     7,    10,    11,    59,    13,    20,    55,
     110,   120,    14,    44,    -2,     4,    15,    77,     5,   128,
      57,   125,    45,    46,     6,    81,    82,     7,    86,     8,
       9,   108,    10,    11,    12,    13,    14,    16,    17,    18,
      95,    19,   105,    20,    15,   127,    50,    48,    97,    94,
       5,    21,    22,    47,    88,    51,    23,    98,   112,     7,
      99,    16,    17,    18,   113,    19,   117,    89,    14,    20,
     121,    59,     5,    83,    84,    21,    22,    85,     6,    91,
      23,     7,    96,     8,     9,   101,    10,    11,   102,    13,
      14,    42,    43,    16,    17,    18,   136,    19,    15,   131,
     103,   109,   118,   116,   129,    55,   119,    21,    22,   122,
      10,    11,    23,    13,   123,    16,    17,    18,     5,    19,
     126,   141,    15,    20,    53,   132,     5,     7,   133,    21,
      22,   135,     6,   138,    23,     7,    14,     8,     9,   139,
      10,    11,     5,    13,    14,   140,   134,     0,     6,   130,
       0,     7,    15,     8,     9,     0,    10,    11,     0,    13,
      14,    16,    17,    18,     0,    19,    80,     0,    15,    16,
      17,    18,     0,    19,     0,    21,    22,    20,    60,     0,
      23,     0,     0,    21,    22,    16,    17,    18,    23,    19,
       0,     0,     0,    20,    10,    11,     5,    13,     0,    21,
      22,     0,     6,     0,    23,     7,    15,     8,     9,     0,
      10,    11,     0,    13,    14,     0,     0,     0,     0,     0,
       0,     0,    15,     0,    62,    63,    64,    65,    92,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      17,    18,     0,    19,     0,     0,     0,    20,     0,     0,
       0,     0,    67,    21,    22,     0,    68,     0,    23,    69,
      70,    71,    72,    73,     0,     0,     0,    74,     0,    75,
      62,    63,    64,    65,     0,    66,     0,     0,     0,     0,
       0,     0,     0,    62,    63,    64,    65,     0,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    67,     0,
       0,     0,    87,     0,     0,    69,    70,    71,    72,    73,
      90,    67,     0,    74,     0,    75,     0,     0,    69,    70,
      71,    72,    73,     0,     0,     0,    74,     0,    75,    62,
      63,    64,    65,     0,    66,     0,     0,     0,     0,     0,
       0,     0,    62,    63,    64,    65,     0,    66,     0,     0,
       0,     0,     0,     0,     0,     0,   100,    67,    62,    63,
      64,    65,     0,    66,    69,    70,    71,    72,    73,   104,
      67,     0,    74,     0,    75,     0,     0,    69,    70,    71,
      72,    73,     0,     0,     0,    74,    67,    75,     0,     0,
     114,     0,     0,    69,    70,    71,    72,    73,     0,     0,
       0,    74,     0,    75,    62,    63,    64,    65,     0,    66,
       0,     0,     0,     0,     0,     0,     0,    62,    63,    64,
      65,     0,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,   115,     0,     0,     0,     0,     0,    69,
      70,    71,    72,    73,   137,    67,     0,    74,     0,    75,
       0,     0,    69,    70,    71,    72,    73,     0,     0,     0,
      74,     0,    75,    62,    63,    64,    65,     0,    66,     0,
       0,     0,     0,     0,     0,    62,    63,    64,    65,     0,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,    67,     0,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,    67,     0,     0,    74,     0,    75,     0,
      69,    70,    71,    72,    73,     0,     0,     0,    74,     0,
      75
};

static const yytype_int16 yycheck[] =
{
       9,     2,    52,     2,     4,     0,    88,    51,    58,    92,
      19,     4,     4,    13,    18,    19,    60,    21,    55,    20,
      57,   103,    22,    51,     0,     1,    30,    36,     4,   112,
      23,    23,    51,    68,    10,    44,    45,    13,    47,    15,
      16,   123,    18,    19,    20,    21,    22,    47,    48,    49,
      59,    51,    56,    55,    30,    57,     4,    57,    67,    58,
       4,    61,    62,    51,    55,    68,    66,    76,    52,    13,
      79,    47,    48,    49,    58,    51,   100,    20,    22,    55,
     104,    60,     4,    19,    20,    61,    62,    23,    10,     4,
      66,    13,     4,    15,    16,    70,    18,    19,     4,    21,
      22,    56,    57,    47,    48,    49,   130,    51,    30,   118,
      68,     4,    51,    55,   113,   116,    70,    61,    62,    56,
      18,    19,    66,    21,    57,    47,    48,    49,     4,    51,
      70,   140,    30,    55,    56,    51,     4,    13,    70,    61,
      62,     4,    10,    52,    66,    13,    22,    15,    16,    70,
      18,    19,     4,    21,    22,    51,   123,    -1,    10,    11,
      -1,    13,    30,    15,    16,    -1,    18,    19,    -1,    21,
      22,    47,    48,    49,    -1,    51,    52,    -1,    30,    47,
      48,    49,    -1,    51,    -1,    61,    62,    55,    56,    -1,
      66,    -1,    -1,    61,    62,    47,    48,    49,    66,    51,
      -1,    -1,    -1,    55,    18,    19,     4,    21,    -1,    61,
      62,    -1,    10,    -1,    66,    13,    30,    15,    16,    -1,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    25,    26,    27,    28,    52,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    -1,    51,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    53,    61,    62,    -1,    57,    -1,    66,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    68,    -1,    70,
      25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    57,    -1,    -1,    60,    61,    62,    63,    64,
      52,    53,    -1,    68,    -1,    70,    -1,    -1,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    68,    -1,    70,    25,
      26,    27,    28,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    25,    26,
      27,    28,    -1,    30,    60,    61,    62,    63,    64,    52,
      53,    -1,    68,    -1,    70,    -1,    -1,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    68,    53,    70,    -1,    -1,
      57,    -1,    -1,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    68,    -1,    70,    25,    26,    27,    28,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    52,    53,    -1,    68,    -1,    70,
      -1,    -1,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      68,    -1,    70,    25,    26,    27,    28,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,    64,    53,    -1,    -1,    68,    -1,    70,    -1,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    68,    -1,
      70
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    77,    78,     0,     1,     4,    10,    13,    15,    16,
      18,    19,    20,    21,    22,    30,    47,    48,    49,    51,
      55,    61,    62,    66,    79,    82,    83,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    95,    96,    97,    98,
      99,   100,    56,    57,    51,    51,    68,    51,    57,    93,
       4,    68,    93,    56,    85,    88,     4,    23,    51,    60,
      56,    88,    25,    26,    27,    28,    30,    53,    57,    60,
      61,    62,    63,    64,    68,    70,    94,    93,    52,    58,
      52,    93,    93,    19,    20,    23,    93,    57,    55,    20,
      52,     4,    52,    84,    85,    93,     4,    93,    93,    93,
      52,    70,     4,    68,    52,    56,    80,    81,    82,     4,
      57,    86,    52,    58,    57,    54,    55,    87,    51,    70,
      82,    87,    56,    57,     4,    23,    70,    57,    86,    85,
      11,    93,    51,    70,    80,     4,    87,    52,    52,    70,
      51,    93,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    77,    78,    78,    78,    78,    78,    78,    79,
      79,    80,    80,    81,    81,    82,    82,    82,    82,    83,
      83,    83,    83,    84,    84,    85,    85,    86,    86,    87,
      87,    88,    88,    88,    88,    88,    88,    89,    90,    91,
      91,    92,    92,    93,    93,    93,    93,    93,    93,    93,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    95,    95,    95,    96,    96,    96,    97,    97,    98,
      98,    99,    99,    99,   100,   100,   100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     3,     3,     0,     4,
       5,     3,     2,     2,     3,     1,     1,     1,     5,     5,
       5,     4,     4,     3,     1,     3,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     2,     4,     5,     5,
       7,     2,     3,     3,     2,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     7,     7,    10,     2,     3,     3,
       3,     1,     4,     3,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
          case 3: /* ROOT  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 864 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 4: /* IDENT  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 870 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 5: /* NUMBER  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 876 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 6: /* UNOP  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 882 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 7: /* BINOP  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 888 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 8: /* TOK_NEWSTRING  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 894 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 9: /* TOK_INDEX  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 900 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 10: /* TOK_IF  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 906 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 11: /* TOK_ELSE  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 912 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 12: /* TOK_IFELSE  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 918 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 13: /* TOK_ALLOC  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 924 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 14: /* TOK_NULLPTR  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 930 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 15: /* TOK_WHILE  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 936 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 16: /* TOK_RETURN  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 942 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 17: /* TOK_RETURNVOID  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 948 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 18: /* TOK_INT  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 954 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 19: /* TOK_STRING  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 960 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 20: /* TOK_STRUCT  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 966 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 21: /* TOK_VOID  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 972 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 22: /* TOK_NULL  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 978 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 23: /* TOK_ARRAY  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 984 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 24: /* TOK_VARDECL  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 990 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 25: /* TOK_EQ  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 996 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 26: /* TOK_NE  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1002 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 27: /* TOK_LE  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1008 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 28: /* TOK_GE  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1014 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 29: /* TOK_NOT  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1020 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 30: /* TOK_PTR  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1026 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 31: /* TOK_BLOCK  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1032 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 32: /* TOK_CALL  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1038 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 33: /* DECLID  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1044 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 34: /* TOK_FUNCTION  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1050 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 35: /* TOK_PROTOTYPE  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1056 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 36: /* TOK_POS  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1062 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 37: /* TOK_NEG  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1068 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 38: /* TOK_NEWARRAY  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1074 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 39: /* TOK_TYPEID  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1080 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 40: /* TOK_FIELD  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1086 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 41: /* TOK_ORD  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1092 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 42: /* TOK_CHR  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1098 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 43: /* TOK_ROOT  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1104 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 44: /* TOK_PARAMLIST  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1110 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 45: /* BAD_TOK  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1116 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 46: /* TOK_EXC  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1122 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 47: /* TOK_INTCON  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1128 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 48: /* TOK_CHARCON  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1134 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 49: /* TOK_STRINGCON  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1140 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 50: /* TOK_ARROW  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1146 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 51: /* '('  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1152 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 52: /* ')'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1158 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 53: /* '['  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1164 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 54: /* ']'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1170 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 55: /* '{'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1176 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 56: /* '}'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1182 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 57: /* ';'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1188 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 58: /* ','  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1194 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 59: /* '.'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1200 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 60: /* '='  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1206 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 61: /* '+'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1212 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 62: /* '-'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1218 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 63: /* '*'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1224 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 64: /* '/'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1230 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 65: /* '%'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1236 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 66: /* '!'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1242 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 67: /* TOK_NEQ  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1248 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 68: /* '<'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1254 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 69: /* TOK_LEQ  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1260 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 70: /* '>'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1266 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 71: /* TOK_GEQ  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1272 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 72: /* POS  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1278 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 73: /* NEG  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1284 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 74: /* TOK_NEW  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1290 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 75: /* '^'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1296 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 77: /* start  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1302 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 78: /* program  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1308 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 79: /* structdef  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1314 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 80: /* structfields  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1320 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 81: /* structfield  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1326 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 82: /* plaintype  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1332 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 83: /* function  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1338 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 84: /* idents  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1344 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 85: /* ident  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1350 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 86: /* block  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1356 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 87: /* statements  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1362 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 88: /* statement  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1368 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 89: /* vardecl  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1374 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 90: /* while  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1380 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 91: /* ifelse  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1386 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 92: /* return  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1392 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 93: /* expr  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1398 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 94: /* binop  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1404 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 95: /* unop  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1410 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 96: /* alloc  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1416 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 97: /* call  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1422 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 98: /* params  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1428 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 99: /* variable  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1434 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 100: /* constant  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1440 "yyparse.cpp" /* yacc.c:684  */
        break;


      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 3: /* ROOT  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1786 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 4: /* IDENT  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1792 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 5: /* NUMBER  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1798 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 6: /* UNOP  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1804 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 7: /* BINOP  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1810 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 8: /* TOK_NEWSTRING  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1816 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 9: /* TOK_INDEX  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1822 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 10: /* TOK_IF  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1828 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 11: /* TOK_ELSE  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1834 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 12: /* TOK_IFELSE  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1840 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 13: /* TOK_ALLOC  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1846 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 14: /* TOK_NULLPTR  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1852 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 15: /* TOK_WHILE  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1858 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 16: /* TOK_RETURN  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1864 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 17: /* TOK_RETURNVOID  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1870 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 18: /* TOK_INT  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1876 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 19: /* TOK_STRING  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1882 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 20: /* TOK_STRUCT  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1888 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 21: /* TOK_VOID  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1894 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 22: /* TOK_NULL  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1900 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 23: /* TOK_ARRAY  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1906 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 24: /* TOK_VARDECL  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1912 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 25: /* TOK_EQ  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1918 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 26: /* TOK_NE  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1924 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 27: /* TOK_LE  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1930 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 28: /* TOK_GE  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1936 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 29: /* TOK_NOT  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1942 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 30: /* TOK_PTR  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1948 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 31: /* TOK_BLOCK  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1954 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 32: /* TOK_CALL  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1960 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 33: /* DECLID  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1966 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 34: /* TOK_FUNCTION  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1972 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 35: /* TOK_PROTOTYPE  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1978 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 36: /* TOK_POS  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1984 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 37: /* TOK_NEG  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1990 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 38: /* TOK_NEWARRAY  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1996 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 39: /* TOK_TYPEID  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2002 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 40: /* TOK_FIELD  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2008 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 41: /* TOK_ORD  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2014 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 42: /* TOK_CHR  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2020 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 43: /* TOK_ROOT  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2026 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 44: /* TOK_PARAMLIST  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2032 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 45: /* BAD_TOK  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2038 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 46: /* TOK_EXC  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2044 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 47: /* TOK_INTCON  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2050 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 48: /* TOK_CHARCON  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2056 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 49: /* TOK_STRINGCON  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2062 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 50: /* TOK_ARROW  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2068 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 51: /* '('  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2074 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 52: /* ')'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2080 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 53: /* '['  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2086 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 54: /* ']'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2092 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 55: /* '{'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2098 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 56: /* '}'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2104 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 57: /* ';'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2110 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 58: /* ','  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2116 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 59: /* '.'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2122 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 60: /* '='  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2128 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 61: /* '+'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2134 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 62: /* '-'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2140 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 63: /* '*'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2146 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 64: /* '/'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2152 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 65: /* '%'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2158 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 66: /* '!'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2164 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 67: /* TOK_NEQ  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2170 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 68: /* '<'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2176 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 69: /* TOK_LEQ  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2182 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 70: /* '>'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2188 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 71: /* TOK_GEQ  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2194 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 72: /* POS  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2200 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 73: /* NEG  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2206 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 74: /* TOK_NEW  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2212 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 75: /* '^'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2218 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 77: /* start  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2224 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 78: /* program  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2230 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 79: /* structdef  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2236 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 80: /* structfields  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2242 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 81: /* structfield  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2248 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 82: /* plaintype  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2254 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 83: /* function  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2260 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 84: /* idents  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2266 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 85: /* ident  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2272 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 86: /* block  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2278 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 87: /* statements  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2284 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 88: /* statement  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2290 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 89: /* vardecl  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2296 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 90: /* while  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2302 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 91: /* ifelse  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2308 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 92: /* return  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2314 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 93: /* expr  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2320 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 94: /* binop  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2326 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 95: /* unop  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2332 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 96: /* alloc  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2338 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 97: /* call  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2344 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 98: /* params  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2350 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 99: /* variable  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2356 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 100: /* constant  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2362 "yyparse.cpp" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

/* User initialization code.  */
#line 18 "parser.y" /* yacc.c:1429  */
{
   parser::root = new astree (ROOT, {0, 0, 0}, "<>"); 
}

#line 2452 "yyparse.cpp" /* yacc.c:1429  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 53 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]) = nullptr; }
#line 2634 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 56 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt ((yyvsp[0])); }
#line 2640 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 57 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt ((yyvsp[0])); }
#line 2646 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 58 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt ((yyvsp[0])); }
#line 2652 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 59 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]); }
#line 2658 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 60 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]); }
#line 2664 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 61 "parser.y" /* yacc.c:1646  */
    { (yyval) = parser::root; }
#line 2670 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 65 "parser.y" /* yacc.c:1646  */
    { 
            destroy ((yyvsp[-1]), (yyvsp[0]));
            (yyvsp[-2])->change_sym (TOK_TYPEID);
            (yyval) = (yyvsp[-3])->adopt ((yyvsp[-2])); }
#line 2679 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 69 "parser.y" /* yacc.c:1646  */
    { 
            destroy ((yyvsp[-2]), (yyvsp[0]));
            (yyvsp[-3])->change_sym (TOK_TYPEID);
            (yyval) = (yyvsp[-4])->adopt ((yyvsp[-3]), (yyvsp[-1])); }
#line 2688 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 75 "parser.y" /* yacc.c:1646  */
    { 
            destroy ((yyvsp[-1]));
            (yyval) = (yyvsp[-2])->adopt ((yyvsp[0])); }
#line 2696 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 78 "parser.y" /* yacc.c:1646  */
    {
            destroy ((yyvsp[0])); (yyval) = (yyvsp[-1]); }
#line 2703 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 82 "parser.y" /* yacc.c:1646  */
    { 
            (yyvsp[0])->change_sym (TOK_FIELD);
            (yyval) = (yyvsp[-1])->adopt ((yyvsp[0])); }
#line 2711 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 85 "parser.y" /* yacc.c:1646  */
    { 
            (yyvsp[-1])->change_sym (TOK_ARRAY);
            (yyvsp[0])->change_sym (TOK_FIELD);
            (yyval) = (yyvsp[-1])->adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2720 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 91 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2726 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 92 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2732 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 93 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2738 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 94 "parser.y" /* yacc.c:1646  */
    {
            destroy((yyvsp[-3]), (yyvsp[-2]), (yyvsp[0]));
            (yyval) = (yyvsp[-4])->adopt ((yyvsp[-1])); }
#line 2746 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 99 "parser.y" /* yacc.c:1646  */
    { 
            (yyvsp[-1])->change_sym (TOK_FUNCTION);
            (yyvsp[-3])->change_sym (TOK_PARAMLIST);
            (yyvsp[-3])->adopt ((yyvsp[-2]));
            (yyval) = (yyvsp[-1])->adopt ((yyvsp[-4]), (yyvsp[-3]), (yyvsp[0])); }
#line 2756 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 104 "parser.y" /* yacc.c:1646  */
    { 
            destroy((yyvsp[0]));
            (yyvsp[-1])->change_sym (TOK_FUNCTION);
            (yyvsp[-3])->change_sym (TOK_PARAMLIST);
            (yyvsp[-3])->adopt ((yyvsp[-2]));
            (yyval) = (yyvsp[-1])->adopt ((yyvsp[-4]), (yyvsp[-3])); }
#line 2767 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 110 "parser.y" /* yacc.c:1646  */
    { 
            destroy ((yyvsp[0]));
            (yyvsp[-1])->change_sym (TOK_PROTOTYPE);
            (yyvsp[-2])->change_sym (TOK_PARAMLIST);
            (yyval) = (yyvsp[-1])->adopt ((yyvsp[-3]), (yyvsp[-2])); }
#line 2777 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 115 "parser.y" /* yacc.c:1646  */
    { 
            (yyvsp[-1])->change_sym(TOK_FUNCTION);
            (yyvsp[-2])->change_sym(TOK_PARAMLIST);
            (yyval) = (yyvsp[-1])->adopt ((yyvsp[-3]), (yyvsp[-2]), (yyvsp[0])); }
#line 2786 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 121 "parser.y" /* yacc.c:1646  */
    { 
             destroy ((yyvsp[-1]));
             (yyval) = (yyvsp[-2])->adopt ((yyvsp[0])); }
#line 2794 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 124 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2800 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 127 "parser.y" /* yacc.c:1646  */
    { 
            (yyvsp[0])->change_sym (DECLID);
            (yyval) = (yyvsp[-2])->adopt ((yyvsp[-1]), (yyvsp[0])); }
#line 2808 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 130 "parser.y" /* yacc.c:1646  */
    { 
            (yyvsp[0])->change_sym (DECLID);
            (yyval) = (yyvsp[-1])->adopt ((yyvsp[0])); }
#line 2816 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 135 "parser.y" /* yacc.c:1646  */
    { 
            destroy ((yyvsp[0]));
            (yyvsp[-1])->change_sym (TOK_BLOCK);
            (yyval) = (yyvsp[-1]); }
#line 2825 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 139 "parser.y" /* yacc.c:1646  */
    { 
            destroy ((yyvsp[0]));
            (yyvsp[-1])->change_sym (TOK_BLOCK);
            (yyval) = (yyvsp[-1]); }
#line 2834 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 145 "parser.y" /* yacc.c:1646  */
    { 
                 (yyval) = (yyvsp[-1])->adopt ((yyvsp[0])); }
#line 2841 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 147 "parser.y" /* yacc.c:1646  */
    { 
                 (yyval) = (yyvsp[-1])->adopt ((yyvsp[0])); }
#line 2848 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2854 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2860 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2866 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 154 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2872 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2878 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 156 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-1]); }
#line 2884 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 159 "parser.y" /* yacc.c:1646  */
    { 
            destroy ((yyvsp[0]));
            (yyvsp[-2])->change_sym (TOK_VARDECL);
            (yyval) = (yyvsp[-2])->adopt ((yyvsp[-3]), (yyvsp[-1])); }
#line 2893 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 165 "parser.y" /* yacc.c:1646  */
    { 
            destroy ((yyvsp[-3]), (yyvsp[-1]));
            (yyval) = (yyvsp[-4])->adopt((yyvsp[-2]), (yyvsp[0])); }
#line 2901 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 170 "parser.y" /* yacc.c:1646  */
    { 
            destroy ((yyvsp[-3]), (yyvsp[-1]));
            (yyval) =(yyvsp[-4])->adopt((yyvsp[-2]),(yyvsp[0])); }
#line 2909 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 173 "parser.y" /* yacc.c:1646  */
    { 
            destroy ((yyvsp[-5]), (yyvsp[-3]));
            destroy ((yyvsp[-2]), (yyvsp[-1]));
            (yyvsp[-6])->change_sym (TOK_IFELSE);
            (yyval) = (yyvsp[-6])->adopt ((yyvsp[-4]), (yyvsp[-2]), (yyvsp[0])); }
#line 2919 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 180 "parser.y" /* yacc.c:1646  */
    { 
            destroy ((yyvsp[0]));
            (yyvsp[-1])->change_sym (TOK_RETURNVOID);
            (yyval) = (yyvsp[-1]); }
#line 2928 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 184 "parser.y" /* yacc.c:1646  */
    { 
            destroy ((yyvsp[0]));
            (yyval) = (yyvsp[-2])->adopt ((yyvsp[-1])); }
#line 2936 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 189 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]), (yyvsp[0])); }
#line 2942 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 190 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 2948 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2954 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2960 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 193 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[-2]), (yyvsp[0]));
              (yyval) = (yyvsp[-1]); }
#line 2967 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 195 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2973 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 196 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2979 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 199 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2985 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 200 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2991 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 201 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2997 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 202 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3003 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 203 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3009 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 204 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3015 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 205 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3021 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3027 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 207 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3033 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 208 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3039 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3045 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3051 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3057 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 214 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3063 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 217 "parser.y" /* yacc.c:1646  */
    { 
            destroy ((yyvsp[-5]), (yyvsp[-4]), (yyvsp[-2]));
            destroy ((yyvsp[-1]), (yyvsp[0]));
            (yyvsp[-3])->change_sym (TOK_TYPEID);
            (yyval) = (yyvsp[-6])->adopt ((yyvsp[-3])); }
#line 3073 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 222 "parser.y" /* yacc.c:1646  */
    { 
            destroy ((yyvsp[-5]), (yyvsp[-3]), (yyvsp[-2]));
            destroy ((yyvsp[0]));
            (yyval) = (yyvsp[-6])->adopt ((yyvsp[-4]), (yyvsp[-1])); }
#line 3082 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 226 "parser.y" /* yacc.c:1646  */
    { 
            destroy ((yyvsp[-8]), (yyvsp[-6]));
            destroy ((yyvsp[-4]), (yyvsp[-3]));
            destroy ((yyvsp[-2]), (yyvsp[0]));
            (yyvsp[-7])->adopt ((yyvsp[-5]));
            (yyval) = (yyvsp[-9])->adopt ((yyvsp[-7]), (yyvsp[-1])); }
#line 3093 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 234 "parser.y" /* yacc.c:1646  */
    { 
            destroy ((yyvsp[0]));
            (yyvsp[-1])->change_sym (TOK_CALL);
            (yyval) = (yyvsp[-1]); }
#line 3102 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 238 "parser.y" /* yacc.c:1646  */
    { 
            destroy ((yyvsp[0]));
            (yyvsp[-1])->change_sym (TOK_CALL);
            (yyval) = (yyvsp[-1])->adopt ((yyvsp[-2])); }
#line 3111 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 244 "parser.y" /* yacc.c:1646  */
    { 
            (yyval) = (yyvsp[-1])->adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 3118 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 246 "parser.y" /* yacc.c:1646  */
    { 
            destroy ((yyvsp[-1]));
            (yyval) = (yyvsp[-2])->adopt ((yyvsp[0])); }
#line 3126 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 251 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3132 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 252 "parser.y" /* yacc.c:1646  */
    { 
            destroy ((yyvsp[0]));
            (yyvsp[-2])->change_sym (TOK_INDEX);
            (yyval) = (yyvsp[-2])->adopt ((yyvsp[-3]), (yyvsp[-1])); }
#line 3141 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 256 "parser.y" /* yacc.c:1646  */
    { 
            (yyvsp[0])->change_sym(TOK_FIELD);
            (yyval) = (yyvsp[-1])->adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 3149 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 261 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3155 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 262 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3161 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 263 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3167 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 264 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3173 "yyparse.cpp" /* yacc.c:1646  */
    break;


#line 3177 "yyparse.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 267 "parser.y" /* yacc.c:1906  */


const char* parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}

bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}
