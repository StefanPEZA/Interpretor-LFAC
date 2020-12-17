/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOLON = 258,
    CONTAINER = 259,
    IDENTIFIER = 260,
    OPEN_BRACE = 261,
    CLOSE_BRACE = 262,
    OPEN_P = 263,
    CLOSE_P = 264,
    INT = 265,
    FLOAT = 266,
    CHAR = 267,
    STRING = 268,
    BOOL = 269,
    VOID = 270,
    EQUAL = 271,
    INT_CONST = 272,
    FLOAT_CONST = 273,
    CHAR_CONST = 274,
    STR_CONST = 275,
    TRUE = 276,
    FALSE = 277,
    EVAL = 278,
    CONST = 279,
    COMMA = 280,
    FUN = 281,
    VAR = 282,
    PLUS = 283,
    MINUS = 284,
    TIMES = 285,
    DIV = 286
  };
#endif
/* Tokens.  */
#define SEMICOLON 258
#define CONTAINER 259
#define IDENTIFIER 260
#define OPEN_BRACE 261
#define CLOSE_BRACE 262
#define OPEN_P 263
#define CLOSE_P 264
#define INT 265
#define FLOAT 266
#define CHAR 267
#define STRING 268
#define BOOL 269
#define VOID 270
#define EQUAL 271
#define INT_CONST 272
#define FLOAT_CONST 273
#define CHAR_CONST 274
#define STR_CONST 275
#define TRUE 276
#define FALSE 277
#define EVAL 278
#define CONST 279
#define COMMA 280
#define FUN 281
#define VAR 282
#define PLUS 283
#define MINUS 284
#define TIMES 285
#define DIV 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "interpretor.y"

    int intVal;
    float floatVal;
    char charVal;
    char* dataType;
    char* stringVal;
    short boolVal : 1;

#line 128 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
