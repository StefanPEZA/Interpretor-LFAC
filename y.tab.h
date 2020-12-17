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
    OPEN_BRACE = 260,
    CLOSE_BRACE = 261,
    OPEN_P = 262,
    CLOSE_P = 263,
    VOID = 264,
    EQUAL = 265,
    EVAL = 266,
    CONST = 267,
    COMMA = 268,
    FUN = 269,
    VAR = 270,
    UNARY = 271,
    IDENTIFIER = 272,
    INT_CONST = 273,
    FLOAT_CONST = 274,
    CHAR_CONST = 275,
    STR_CONST = 276,
    TRUE = 277,
    FALSE = 278,
    INT = 279,
    FLOAT = 280,
    CHAR = 281,
    STRING = 282,
    BOOL = 283
  };
#endif
/* Tokens.  */
#define SEMICOLON 258
#define CONTAINER 259
#define OPEN_BRACE 260
#define CLOSE_BRACE 261
#define OPEN_P 262
#define CLOSE_P 263
#define VOID 264
#define EQUAL 265
#define EVAL 266
#define CONST 267
#define COMMA 268
#define FUN 269
#define VAR 270
#define UNARY 271
#define IDENTIFIER 272
#define INT_CONST 273
#define FLOAT_CONST 274
#define CHAR_CONST 275
#define STR_CONST 276
#define TRUE 277
#define FALSE 278
#define INT 279
#define FLOAT 280
#define CHAR 281
#define STRING 282
#define BOOL 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 10 "interpretor.y"

    int intVal;
    float floatVal;
    char charVal;
    char* dataType;
    char* stringVal;
    short boolVal : 1;

#line 122 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
