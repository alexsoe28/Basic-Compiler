/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    TOK_FIELDLIST = 273,
    TOK_INT = 274,
    TOK_STRING = 275,
    TOK_STRUCT = 276,
    TOK_VOID = 277,
    TOK_NULL = 278,
    TOK_ARRAY = 279,
    TOK_VARDECL = 280,
    TOK_PARAMLIST = 281,
    TOK_EQ = 282,
    TOK_NE = 283,
    TOK_LE = 284,
    TOK_GE = 285,
    TOK_NOT = 286,
    TOK_PTR = 287,
    TOK_BLOCK = 288,
    TOK_CALL = 289,
    DECLID = 290,
    TOK_FUNCTION = 291,
    TOK_PROTOTYPE = 292,
    TOK_POS = 293,
    TOK_NEG = 294,
    TOK_NEWARRAY = 295,
    TOK_TYPEID = 296,
    TOK_FIELD = 297,
    TOK_ORD = 298,
    TOK_CHR = 299,
    TOK_ROOT = 300,
    TOK_PARAM = 301,
    BAD_TOK = 302,
    TOK_EXC = 303,
    TOK_INTCON = 304,
    TOK_CHARCON = 305,
    TOK_STRINGCON = 306,
    TOK_ARROW = 307
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
