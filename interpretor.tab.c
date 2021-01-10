/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "interpretor.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdarg.h>
    #include "interpretor.h"
    extern int nr_lines;
    extern int nr_word;
    extern FILE* yyin;
    extern char* yytext;

    /* prototipurile functiilor */
    nodeType *nodOper(int oper, int nops, ...);
        /* nod operator in arbore */
    nodeType *nodId(char* i, int newId);
        /* nod frunza identificator */
    nodeType *nodCon(int type, void* value);
        /* nod frunza constanta */
    nodeType *nodArr(int type, int size);
    void freeNode(nodeType *p);
        /* eliberare memorie */
    int interpret(nodeType *p);
    void evalError(const char*, int nre);
        /* functia de interpretare */
    int arrayInt[1000];
    short arrayBool[1000];
    char arrayChar[1000];
    char* arrayStr[1000];
    float arrayFloat[1000];
    char strExpr[1000] = "";
    int nreval = 1;
    int indx=0;
    int lastIndex = 0;
    int yylex();
    int yyerror(const char *s);
    int sym[30];

    int localScope = 0;


#line 111 "interpretor.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_INTERPRETOR_TAB_H_INCLUDED
# define YY_YY_INTERPRETOR_TAB_H_INCLUDED
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
    CONTAINER = 258,
    EVAL = 259,
    CONST = 260,
    FUN = 261,
    VAR = 262,
    CALL = 263,
    IF = 264,
    ELSE = 265,
    WHILE = 266,
    FOR = 267,
    INT = 268,
    FLOAT = 269,
    CHAR = 270,
    STRING = 271,
    BOOL = 272,
    VOID = 273,
    ARR = 274,
    MAIN = 275,
    IDENTIFIER = 276,
    INT_CONST = 277,
    FLOAT_CONST = 278,
    CHAR_CONST = 279,
    STR_CONST = 280,
    TRUE = 281,
    FALSE = 282,
    AND = 283,
    OR = 284,
    EQUALITY = 285,
    INEQUALITY = 286,
    LT = 287,
    GT = 288,
    LTE = 289,
    GTE = 290,
    NEG = 291,
    ACCES = 292,
    THEN = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "interpretor.y"

    short boolVal;
    int intVal;
    float floatVal;
    char charVal;
    char* strVal;
    char* varId;
    int Types;
    nodeType *nodPtr;

#line 213 "interpretor.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INTERPRETOR_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

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
# define YYCOPY_NEEDED 1
#endif


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   453

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

#define YYUNDEFTOK  2
#define YYMAXUTOK   293


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,     2,     2,    41,     2,     2,
      44,    45,    39,    37,    51,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
       2,    36,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      35,    42,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    84,    85,    88,    89,    90,    91,    92,
      93,    96,   100,   103,   104,   107,   108,   111,   112,   115,
     116,   119,   120,   123,   126,   127,   128,   129,   130,   133,
     134,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   150,   151,   154,   155,   158,   161,   164,   167,
     169,   172,   173,   174,   175,   176,   178,   181,   182,   184,
     185,   187,   188,   190,   191,   193,   194,   195,   196,   198,
     201,   204,   207,   210,   215,   222,   225,   226,   227,   230,
     233,   234,   237,   238,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONTAINER", "EVAL", "CONST", "FUN",
  "VAR", "CALL", "IF", "ELSE", "WHILE", "FOR", "INT", "FLOAT", "CHAR",
  "STRING", "BOOL", "VOID", "ARR", "MAIN", "IDENTIFIER", "INT_CONST",
  "FLOAT_CONST", "CHAR_CONST", "STR_CONST", "TRUE", "FALSE", "AND", "OR",
  "EQUALITY", "INEQUALITY", "LT", "GT", "LTE", "GTE", "'='", "'+'", "'-'",
  "'*'", "'/'", "'%'", "NEG", "'!'", "'('", "')'", "ACCES", "THEN", "';'",
  "'{'", "'}'", "','", "'['", "']'", "$accept", "start", "stmts", "stmt",
  "main_function", "container_declaration", "container_body",
  "container_elements", "function_declaration", "return_type",
  "fun_params", "parameter", "types", "fun_body", "code_block",
  "code_block_list", "if_statement", "while_statement", "for_statement",
  "var_assignment", "array_declaration", "array_list", "array_assignment",
  "array_list_int", "array_list_float", "array_list_char",
  "array_list_string", "array_list_bool", "array_val",
  "get_container_elem", "container_assignment", "container_function",
  "var_declaration", "const_declaration", "call_function", "eval_function",
  "call_params", "call_param", "expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    61,    43,    45,    42,
      47,    37,   291,    33,    40,    41,   292,   293,    59,   123,
     125,    44,    91,    93
};
# endif

#define YYPACT_NINF (-191)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     116,   -40,   153,   132,   153,     6,   153,    28,   116,  -191,
    -191,  -191,  -191,   -17,    11,    25,   118,  -191,  -191,  -191,
    -191,  -191,    26,  -191,    55,  -191,    65,    74,    69,  -191,
    -191,  -191,  -191,  -191,    10,  -191,  -191,    81,   100,    95,
     104,   119,    99,   157,  -191,  -191,   252,    83,   252,   125,
     159,   134,   -33,  -191,  -191,  -191,  -191,  -191,  -191,   252,
     252,   252,  -191,  -191,   377,   135,    13,  -191,   164,   377,
     383,   133,  -191,   172,   184,  -191,  -191,   290,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   383,   161,   153,  -191,    -1,   187,   191,   193,     9,
       3,  -191,  -191,  -191,  -191,   197,   198,   199,   212,     8,
     201,   203,   204,   206,   208,   221,  -191,   205,  -191,   390,
     402,   412,   412,   176,   176,   176,   176,    76,    76,  -191,
    -191,  -191,    30,   383,  -191,   219,   220,  -191,   252,   252,
     238,   252,  -191,  -191,  -191,  -191,  -191,   252,   252,   245,
    -191,  -191,  -191,  -191,  -191,   231,  -191,  -191,    70,   252,
     217,   308,   326,   246,   233,   377,   377,   377,  -191,    42,
    -191,   377,   174,  -191,   344,  -191,    50,   235,   236,   252,
    -191,   245,  -191,  -191,  -191,  -191,  -191,  -191,   237,   240,
     241,   242,   243,   254,  -191,  -191,   383,   383,   269,  -191,
    -191,   264,   288,   289,   287,   106,  -191,   168,   183,   238,
    -191,  -191,  -191,  -191,  -191,  -191,   304,  -191,  -191,   270,
     267,   277,   383,   383,   200,   215,  -191,  -191
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     2,     4,
      10,     9,     8,     0,     0,     0,     0,    24,    25,    26,
      27,    28,     0,    20,     0,    19,     0,     0,     0,     1,
       3,     6,     5,     7,     0,    13,    16,     0,     0,     0,
      73,     0,     0,     0,    14,    15,     0,     0,     0,     0,
       0,     0,    84,    87,    88,   107,   108,    96,    97,     0,
       0,     0,    86,    85,    75,     0,     0,    21,     0,    74,
       0,     0,    12,     0,     0,    95,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,    29,    39,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,    70,     0,    89,   104,
     105,   102,   103,    98,    99,   100,   101,    90,    91,    92,
      93,    94,     0,     0,    22,     0,     0,    78,     0,     0,
       0,     0,    11,    30,    36,    32,    33,     0,     0,     0,
      37,    38,    31,    34,    35,     0,    69,    18,     0,     0,
       0,     0,     0,     0,     0,    48,    56,    71,    82,     0,
      80,    83,     0,    17,     0,    77,     0,     0,     0,     0,
      72,     0,    58,    60,    62,    64,    67,    68,     0,    51,
      52,    53,    54,    55,    79,    76,     0,     0,     0,    81,
      49,     0,     0,     0,     0,     0,    42,     0,     0,     0,
      57,    59,    61,    63,    65,    66,    44,    43,    46,     0,
       0,     0,     0,     0,     0,     0,    45,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -191,  -191,  -191,   324,  -191,  -191,  -191,   299,   -11,  -191,
    -191,   251,   226,   -90,   -64,  -190,  -191,  -191,  -191,  -138,
      46,  -191,  -191,  -191,  -191,  -191,  -191,  -191,   -70,   -66,
    -191,  -191,    40,    57,  -131,  -191,   190,   170,    24
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    11,    34,    35,    12,    24,
      66,    67,    68,   100,   206,   207,   102,   103,   104,   105,
     106,   188,   107,   189,   190,   191,   192,   193,    62,    63,
     110,   111,   112,   113,   114,   137,   169,   170,   171
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     108,   132,   164,   135,   109,    36,   101,   208,     2,    16,
       4,    95,    96,    73,    97,    98,     3,     4,   168,    74,
     136,   108,     6,    36,    99,   109,    27,   101,    29,   168,
     108,    31,   224,   225,   109,     2,   143,     4,    95,    96,
      14,    97,    98,   158,   148,   141,    13,    38,    14,     6,
     168,    99,   149,   142,    13,    73,    37,    15,    92,    32,
      43,    74,   108,   108,    93,    15,   109,   109,   143,   101,
      64,   219,    69,    33,    37,     2,    39,     4,    95,    96,
     157,    97,    98,    75,    76,    77,    40,   180,   108,     6,
      42,    99,   109,   181,   143,   195,    17,    18,    19,    20,
      21,   181,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    88,    89,    90,    41,     1,
     173,     2,     3,     4,     3,     4,   108,   108,    65,    45,
     109,   109,   214,   215,     5,     6,    46,   108,   108,    47,
      48,   109,   109,   217,   217,    17,    18,    19,    20,    21,
      23,    50,   108,   108,   108,   108,   109,   109,   109,   109,
     217,   217,   161,   162,    49,   165,    17,    18,    19,    20,
      21,   166,   167,     2,    70,     4,    95,    96,    51,    97,
      98,    71,    72,   174,    91,    94,   115,     6,     2,    99,
       4,    95,    96,   116,    97,    98,   182,   183,   184,   185,
     186,   187,     6,   198,    99,     2,   117,     4,    95,    96,
     133,    97,    98,    86,    87,    88,    89,    90,   216,     6,
       2,    99,     4,    95,    96,    95,    97,    98,    22,    25,
      26,   138,    28,   218,     6,   139,    99,   140,    52,    53,
      54,    55,    56,    57,    58,   144,   145,   146,   147,   150,
     226,   151,   152,    95,   153,    59,   154,   155,   156,   163,
      60,    61,   175,   159,   160,   227,    52,    53,    54,    55,
      56,    57,    58,    52,    53,    54,    55,    56,    57,    58,
     172,   179,   141,    59,   196,   197,   210,   200,    60,    61,
      59,   201,   202,   203,   204,    60,    61,    78,    79,    80,
      81,    82,    83,    84,    85,   205,    86,    87,    88,    89,
      90,   211,   213,   212,   220,   221,   222,   209,    78,    79,
      80,    81,    82,    83,    84,    85,   223,    86,    87,    88,
      89,    90,    30,    44,     0,   118,    78,    79,    80,    81,
      82,    83,    84,    85,   134,    86,    87,    88,    89,    90,
     176,   199,     0,   177,    78,    79,    80,    81,    82,    83,
      84,    85,     0,    86,    87,    88,    89,    90,     0,     0,
       0,   178,    78,    79,    80,    81,    82,    83,    84,    85,
       0,    86,    87,    88,    89,    90,     0,     0,     2,   194,
       4,    95,    96,     0,    97,    98,     0,     0,     0,     0,
       0,     0,     6,     0,    99,    78,    79,    80,    81,    82,
      83,    84,    85,     0,    86,    87,    88,    89,    90,    79,
      80,    81,    82,    83,    84,    85,     0,    86,    87,    88,
      89,    90,    80,    81,    82,    83,    84,    85,     0,    86,
      87,    88,    89,    90,    82,    83,    84,    85,     0,    86,
      87,    88,    89,    90
};

static const yytype_int16 yycheck[] =
{
      70,    91,   140,     4,    70,    16,    70,   197,     5,    49,
       7,     8,     9,    46,    11,    12,     6,     7,   149,    52,
      21,    91,    19,    34,    21,    91,    20,    91,     0,   160,
     100,    48,   222,   223,   100,     5,   100,     7,     8,     9,
       0,    11,    12,   133,    36,    36,     0,    21,     8,    19,
     181,    21,    44,    50,     8,    46,    16,     0,    45,    48,
      50,    52,   132,   133,    51,     8,   132,   133,   132,   133,
      46,   209,    48,    48,    34,     5,    21,     7,     8,     9,
      50,    11,    12,    59,    60,    61,    21,    45,   158,    19,
      21,    21,   158,    51,   158,    45,    13,    14,    15,    16,
      17,    51,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    39,    40,    41,    44,     3,
      50,     5,     6,     7,     6,     7,   196,   197,    45,    48,
     196,   197,    26,    27,    18,    19,    36,   207,   208,    44,
      36,   207,   208,   207,   208,    13,    14,    15,    16,    17,
      18,    52,   222,   223,   224,   225,   222,   223,   224,   225,
     224,   225,   138,   139,    45,   141,    13,    14,    15,    16,
      17,   147,   148,     5,    49,     7,     8,     9,    21,    11,
      12,    22,    48,   159,    49,    21,    53,    19,     5,    21,
       7,     8,     9,    21,    11,    12,    22,    23,    24,    25,
      26,    27,    19,   179,    21,     5,    22,     7,     8,     9,
      49,    11,    12,    37,    38,    39,    40,    41,    50,    19,
       5,    21,     7,     8,     9,     8,    11,    12,     2,     3,
       4,    44,     6,    50,    19,    44,    21,    44,    21,    22,
      23,    24,    25,    26,    27,    48,    48,    48,    36,    48,
      50,    48,    48,     8,    48,    38,    48,    36,    53,    21,
      43,    44,    45,    44,    44,    50,    21,    22,    23,    24,
      25,    26,    27,    21,    22,    23,    24,    25,    26,    27,
      49,    48,    36,    38,    49,    49,    22,    50,    43,    44,
      38,    51,    51,    51,    51,    43,    44,    28,    29,    30,
      31,    32,    33,    34,    35,    51,    37,    38,    39,    40,
      41,    23,    25,    24,    10,    45,    49,    48,    28,    29,
      30,    31,    32,    33,    34,    35,    49,    37,    38,    39,
      40,    41,     8,    34,    -1,    45,    28,    29,    30,    31,
      32,    33,    34,    35,    93,    37,    38,    39,    40,    41,
     160,   181,    -1,    45,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    45,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    37,    38,    39,    40,    41,    -1,    -1,     5,    45,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    -1,    21,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    37,    38,    39,    40,    41,    29,
      30,    31,    32,    33,    34,    35,    -1,    37,    38,    39,
      40,    41,    30,    31,    32,    33,    34,    35,    -1,    37,
      38,    39,    40,    41,    32,    33,    34,    35,    -1,    37,
      38,    39,    40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,     7,    18,    19,    55,    56,    57,
      58,    59,    62,    74,    86,    87,    49,    13,    14,    15,
      16,    17,    66,    18,    63,    66,    66,    20,    66,     0,
      57,    48,    48,    48,    60,    61,    62,    86,    21,    21,
      21,    44,    21,    50,    61,    48,    36,    44,    36,    45,
      52,    21,    21,    22,    23,    24,    25,    26,    27,    38,
      43,    44,    82,    83,    92,    45,    64,    65,    66,    92,
      49,    22,    48,    46,    52,    92,    92,    92,    28,    29,
      30,    31,    32,    33,    34,    35,    37,    38,    39,    40,
      41,    49,    45,    51,    21,     8,     9,    11,    12,    21,
      67,    68,    70,    71,    72,    73,    74,    76,    82,    83,
      84,    85,    86,    87,    88,    53,    21,    22,    45,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    67,    49,    65,     4,    21,    89,    44,    44,
      44,    36,    50,    68,    48,    48,    48,    36,    36,    44,
      48,    48,    48,    48,    48,    36,    53,    50,    67,    44,
      44,    92,    92,    21,    73,    92,    92,    92,    88,    90,
      91,    92,    49,    50,    92,    45,    90,    45,    45,    48,
      45,    51,    22,    23,    24,    25,    26,    27,    75,    77,
      78,    79,    80,    81,    45,    45,    49,    49,    92,    91,
      50,    51,    51,    51,    51,    51,    68,    69,    69,    48,
      22,    23,    24,    25,    26,    27,    50,    68,    50,    73,
      10,    45,    49,    49,    69,    69,    50,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    57,    57,    57,
      57,    58,    59,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    66,    66,    66,    66,    66,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    69,    69,    70,    70,    71,    72,    73,    74,
      74,    75,    75,    75,    75,    75,    76,    77,    77,    78,
      78,    79,    79,    80,    80,    81,    81,    81,    81,    82,
      83,    84,    85,    86,    86,    87,    88,    88,    88,    89,
      90,    90,    91,    91,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     2,     1,     1,
       1,     7,     6,     1,     2,     2,     1,     9,     8,     1,
       1,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     2,     7,    11,     7,    11,     3,    10,
       6,     1,     1,     1,     1,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     1,     4,
       3,     3,     4,     3,     5,     5,     5,     4,     2,     4,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     2,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        YY_LAC_DISCARD ("YYBACKUP");                              \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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

/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return 1 if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yy_state_t **yybottom,
                      yy_state_t *yybottom_no_free,
                      yy_state_t **yytop, yy_state_t *yytop_empty)
{
  YYPTRDIFF_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYPTRDIFF_T yyalloc = 2 * yysize_new;
      yy_state_t *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        YY_CAST (yy_state_t *,
                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
                                         yyalloc * YYSIZEOF (*yybottom_new))));
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                         \
do {                                                             \
  if (!yy_lac_established)                                       \
    {                                                            \
      YYDPRINTF ((stderr,                                        \
                  "LAC: initial context established for %s\n",   \
                  yytname[yytoken]));                            \
      yy_lac_established = 1;                                    \
      {                                                          \
        int yy_lac_status =                                      \
          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
        if (yy_lac_status == 2)                                  \
          goto yyexhaustedlab;                                   \
        if (yy_lac_status == 1)                                  \
          goto yyerrlab;                                         \
      }                                                          \
    }                                                            \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      if (yydebug)                                                       \
        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
                   Event "\n");                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return 2 if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, int yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
  if (yytoken == YYUNDEFTOK)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[+*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      {
        YYPTRDIFF_T yylen = yyr2[yyrule];
        YYDPRINTF ((stderr, " R%d", yyrule - 1));
        if (yyesp != yyes_prev)
          {
            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yylen -= yysize;
                yyesp = yyes_prev;
              }
          }
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      {
        yy_state_fast_t yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                     ? yytable[yyi]
                     : yydefgoto[yylhs]);
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            YY_IGNORE_USELESS_CAST_BEGIN
            *yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return 2;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store or if
   yy_lac returned 2.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyesa, yy_state_t **yyes,
                YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          int yyx;

          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
              {
                {
                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
                                              yyssp, yyx);
                  if (yy_lac_status == 2)
                    return 2;
                  if (yy_lac_status == 1)
                    continue;
                }
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
# if YYDEBUG
      else if (yydebug)
        YYFPRINTF (stderr, "No expected tokens.\n");
# endif
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
  YYUSE (yytype);
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

    yy_state_t yyesa[20];
    yy_state_t *yyes;
    YYPTRDIFF_T yyes_capacity;

  int yy_lac_established = 0;
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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  yyes = yyesa;
  yyes_capacity = 20;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");
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
| yyreduce -- do a reduction.  |
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
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 2:
#line 83 "interpretor.y"
              {interpret((yyvsp[0].nodPtr)); }
#line 1828 "interpretor.tab.c"
    break;

  case 3:
#line 84 "interpretor.y"
                   {(yyval.nodPtr) = nodOper(';', 2, (yyvsp[-1].nodPtr), (yyvsp[0].nodPtr));}
#line 1834 "interpretor.tab.c"
    break;

  case 4:
#line 85 "interpretor.y"
           {(yyval.nodPtr)=(yyvsp[0].nodPtr);}
#line 1840 "interpretor.tab.c"
    break;

  case 5:
#line 88 "interpretor.y"
                           {}
#line 1846 "interpretor.tab.c"
    break;

  case 6:
#line 89 "interpretor.y"
                            {}
#line 1852 "interpretor.tab.c"
    break;

  case 7:
#line 90 "interpretor.y"
                            {}
#line 1858 "interpretor.tab.c"
    break;

  case 8:
#line 91 "interpretor.y"
                           {}
#line 1864 "interpretor.tab.c"
    break;

  case 9:
#line 92 "interpretor.y"
                            {}
#line 1870 "interpretor.tab.c"
    break;

  case 10:
#line 93 "interpretor.y"
                    {}
#line 1876 "interpretor.tab.c"
    break;

  case 11:
#line 96 "interpretor.y"
                                                   {
    (yyval.nodPtr)=nodOper(MAIN,1,(yyvsp[-1].nodPtr));}
#line 1883 "interpretor.tab.c"
    break;

  case 12:
#line 100 "interpretor.y"
                                                                        {}
#line 1889 "interpretor.tab.c"
    break;

  case 13:
#line 103 "interpretor.y"
                                    {}
#line 1895 "interpretor.tab.c"
    break;

  case 14:
#line 104 "interpretor.y"
                                        {}
#line 1901 "interpretor.tab.c"
    break;

  case 15:
#line 107 "interpretor.y"
                                         {}
#line 1907 "interpretor.tab.c"
    break;

  case 16:
#line 108 "interpretor.y"
                           {}
#line 1913 "interpretor.tab.c"
    break;

  case 17:
#line 111 "interpretor.y"
                                                                                      {}
#line 1919 "interpretor.tab.c"
    break;

  case 18:
#line 112 "interpretor.y"
                                                          {}
#line 1925 "interpretor.tab.c"
    break;

  case 19:
#line 115 "interpretor.y"
                    {}
#line 1931 "interpretor.tab.c"
    break;

  case 20:
#line 116 "interpretor.y"
           {}
#line 1937 "interpretor.tab.c"
    break;

  case 22:
#line 120 "interpretor.y"
                               {}
#line 1943 "interpretor.tab.c"
    break;

  case 23:
#line 123 "interpretor.y"
                             {}
#line 1949 "interpretor.tab.c"
    break;

  case 24:
#line 126 "interpretor.y"
            {(yyval.Types)=INT;}
#line 1955 "interpretor.tab.c"
    break;

  case 25:
#line 127 "interpretor.y"
            {(yyval.Types)=FLOAT;}
#line 1961 "interpretor.tab.c"
    break;

  case 26:
#line 128 "interpretor.y"
           {(yyval.Types)=CHAR;}
#line 1967 "interpretor.tab.c"
    break;

  case 27:
#line 129 "interpretor.y"
             {(yyval.Types)=STRING;}
#line 1973 "interpretor.tab.c"
    break;

  case 28:
#line 130 "interpretor.y"
           {(yyval.Types)=BOOL;}
#line 1979 "interpretor.tab.c"
    break;

  case 29:
#line 133 "interpretor.y"
                      {(yyval.nodPtr) = (yyvsp[0].nodPtr);}
#line 1985 "interpretor.tab.c"
    break;

  case 30:
#line 134 "interpretor.y"
                          {(yyval.nodPtr) = nodOper(';', 2, (yyvsp[-1].nodPtr), (yyvsp[0].nodPtr));}
#line 1991 "interpretor.tab.c"
    break;

  case 31:
#line 137 "interpretor.y"
                                 {}
#line 1997 "interpretor.tab.c"
    break;

  case 32:
#line 138 "interpretor.y"
                            {}
#line 2003 "interpretor.tab.c"
    break;

  case 33:
#line 139 "interpretor.y"
                           {}
#line 2009 "interpretor.tab.c"
    break;

  case 34:
#line 140 "interpretor.y"
                            {}
#line 2015 "interpretor.tab.c"
    break;

  case 35:
#line 141 "interpretor.y"
                        {}
#line 2021 "interpretor.tab.c"
    break;

  case 36:
#line 142 "interpretor.y"
                         {}
#line 2027 "interpretor.tab.c"
    break;

  case 37:
#line 143 "interpretor.y"
                               {}
#line 2033 "interpretor.tab.c"
    break;

  case 38:
#line 144 "interpretor.y"
                             {}
#line 2039 "interpretor.tab.c"
    break;

  case 39:
#line 145 "interpretor.y"
                   {}
#line 2045 "interpretor.tab.c"
    break;

  case 40:
#line 146 "interpretor.y"
                      {}
#line 2051 "interpretor.tab.c"
    break;

  case 41:
#line 147 "interpretor.y"
                    {}
#line 2057 "interpretor.tab.c"
    break;

  case 42:
#line 150 "interpretor.y"
                             {(yyval.nodPtr) = (yyvsp[0].nodPtr);}
#line 2063 "interpretor.tab.c"
    break;

  case 43:
#line 151 "interpretor.y"
                                 {(yyval.nodPtr) = nodOper(';', 2, (yyvsp[-1].nodPtr), (yyvsp[0].nodPtr));}
#line 2069 "interpretor.tab.c"
    break;

  case 44:
#line 154 "interpretor.y"
                                                                          {(yyval.nodPtr) = nodOper(IF, 2, (yyvsp[-4].nodPtr), (yyvsp[-1].nodPtr));}
#line 2075 "interpretor.tab.c"
    break;

  case 45:
#line 155 "interpretor.y"
                                                                                   {(yyval.nodPtr) = nodOper(IF, 3, (yyvsp[-8].nodPtr), (yyvsp[-5].nodPtr), (yyvsp[-1].nodPtr));}
#line 2081 "interpretor.tab.c"
    break;

  case 46:
#line 158 "interpretor.y"
                                                                    {(yyval.nodPtr) = nodOper(WHILE, 2, (yyvsp[-4].nodPtr), (yyvsp[-1].nodPtr));}
#line 2087 "interpretor.tab.c"
    break;

  case 47:
#line 161 "interpretor.y"
                                                                                                        { (yyval.nodPtr) = nodOper(FOR,4,(yyvsp[-8].nodPtr),(yyvsp[-6].nodPtr),(yyvsp[-4].nodPtr),(yyvsp[-1].nodPtr));}
#line 2093 "interpretor.tab.c"
    break;

  case 48:
#line 164 "interpretor.y"
                                           {(yyval.nodPtr) = nodOper('=', 2, nodId((yyvsp[-2].varId), 0), (yyvsp[0].nodPtr));}
#line 2099 "interpretor.tab.c"
    break;

  case 49:
#line 167 "interpretor.y"
                                                                                  {
        (yyval.nodPtr)=nodOper(ARR, 4,nodCon(typeName,&(yyvsp[-8].Types)),nodId((yyvsp[-7].varId), 1),nodCon(constInt,&(yyvsp[-5].intVal)),nodArr((yyvsp[-8].Types), indx)); indx=0;}
#line 2106 "interpretor.tab.c"
    break;

  case 50:
#line 169 "interpretor.y"
                                             {(yyval.nodPtr)=nodOper(ARR, 3,nodCon(typeName,&(yyvsp[-4].Types)),nodId((yyvsp[-3].varId), 1),nodCon(constInt,&(yyvsp[-1].intVal)));}
#line 2112 "interpretor.tab.c"
    break;

  case 51:
#line 172 "interpretor.y"
                            {}
#line 2118 "interpretor.tab.c"
    break;

  case 52:
#line 173 "interpretor.y"
                       {}
#line 2124 "interpretor.tab.c"
    break;

  case 53:
#line 174 "interpretor.y"
                      {}
#line 2130 "interpretor.tab.c"
    break;

  case 54:
#line 175 "interpretor.y"
                        {}
#line 2136 "interpretor.tab.c"
    break;

  case 55:
#line 176 "interpretor.y"
                      {}
#line 2142 "interpretor.tab.c"
    break;

  case 56:
#line 178 "interpretor.y"
                                           {}
#line 2148 "interpretor.tab.c"
    break;

  case 57:
#line 181 "interpretor.y"
                                              { arrayInt[indx]=(yyvsp[0].intVal); indx++;}
#line 2154 "interpretor.tab.c"
    break;

  case 58:
#line 182 "interpretor.y"
                {arrayInt[indx]=(yyvsp[0].intVal); indx++;}
#line 2160 "interpretor.tab.c"
    break;

  case 59:
#line 184 "interpretor.y"
                                                    {arrayFloat[indx]=(yyvsp[0].floatVal); indx++;}
#line 2166 "interpretor.tab.c"
    break;

  case 60:
#line 185 "interpretor.y"
                  {arrayFloat[indx]=(yyvsp[0].floatVal); indx++;}
#line 2172 "interpretor.tab.c"
    break;

  case 61:
#line 187 "interpretor.y"
                                                 {arrayChar[indx]=(yyvsp[0].charVal); indx++;}
#line 2178 "interpretor.tab.c"
    break;

  case 62:
#line 188 "interpretor.y"
                 {arrayChar[indx]=(yyvsp[0].charVal); indx++;}
#line 2184 "interpretor.tab.c"
    break;

  case 63:
#line 190 "interpretor.y"
                                                    {arrayStr[indx]=(yyvsp[0].strVal); indx++;}
#line 2190 "interpretor.tab.c"
    break;

  case 64:
#line 191 "interpretor.y"
                {arrayStr[indx]=(yyvsp[0].strVal); indx++;}
#line 2196 "interpretor.tab.c"
    break;

  case 65:
#line 193 "interpretor.y"
                                           {arrayBool[indx]=1; indx++;}
#line 2202 "interpretor.tab.c"
    break;

  case 66:
#line 194 "interpretor.y"
                                {arrayBool[indx]=0; indx++;}
#line 2208 "interpretor.tab.c"
    break;

  case 67:
#line 195 "interpretor.y"
           {arrayBool[indx]=1; indx++;}
#line 2214 "interpretor.tab.c"
    break;

  case 68:
#line 196 "interpretor.y"
            {arrayBool[indx]=0; indx++;}
#line 2220 "interpretor.tab.c"
    break;

  case 69:
#line 198 "interpretor.y"
                                         {}
#line 2226 "interpretor.tab.c"
    break;

  case 70:
#line 201 "interpretor.y"
                                                 {}
#line 2232 "interpretor.tab.c"
    break;

  case 71:
#line 204 "interpretor.y"
                                                         {}
#line 2238 "interpretor.tab.c"
    break;

  case 72:
#line 207 "interpretor.y"
                                                            {}
#line 2244 "interpretor.tab.c"
    break;

  case 73:
#line 210 "interpretor.y"
                                       {
        if (addSymbol((yyvsp[0].varId), VAR, (yyvsp[-1].Types), localScope) == -1){
            yyerror("Variabila deja declarata - ");
        }
        (yyval.nodPtr) = nodOper(VAR,2,nodCon(typeName,&(yyvsp[-1].Types)),nodId((yyvsp[0].varId), 1));}
#line 2254 "interpretor.tab.c"
    break;

  case 74:
#line 215 "interpretor.y"
                                          {
        if (addSymbol((yyvsp[-2].varId), VAR, (yyvsp[-3].Types), localScope) == -1){
            yyerror("Variabila deja declarata - ");
        }
        (yyval.nodPtr) = nodOper(VAR,3,nodCon(typeName,&(yyvsp[-3].Types)),nodId((yyvsp[-2].varId), 1),(yyvsp[0].nodPtr));}
#line 2264 "interpretor.tab.c"
    break;

  case 75:
#line 222 "interpretor.y"
                                                          {}
#line 2270 "interpretor.tab.c"
    break;

  case 76:
#line 225 "interpretor.y"
                                                    {}
#line 2276 "interpretor.tab.c"
    break;

  case 77:
#line 226 "interpretor.y"
                              {}
#line 2282 "interpretor.tab.c"
    break;

  case 78:
#line 227 "interpretor.y"
                         {(yyval.nodPtr) = (yyvsp[0].nodPtr); }
#line 2288 "interpretor.tab.c"
    break;

  case 79:
#line 230 "interpretor.y"
                                        { (yyval.nodPtr) = nodOper(EVAL, 1, (yyvsp[-1].nodPtr)); }
#line 2294 "interpretor.tab.c"
    break;

  case 80:
#line 233 "interpretor.y"
                         {}
#line 2300 "interpretor.tab.c"
    break;

  case 81:
#line 234 "interpretor.y"
                                 {}
#line 2306 "interpretor.tab.c"
    break;

  case 82:
#line 237 "interpretor.y"
                           {}
#line 2312 "interpretor.tab.c"
    break;

  case 83:
#line 238 "interpretor.y"
                 {}
#line 2318 "interpretor.tab.c"
    break;

  case 84:
#line 241 "interpretor.y"
                      {(yyval.nodPtr) = nodId((yyvsp[0].varId), 0);}
#line 2324 "interpretor.tab.c"
    break;

  case 85:
#line 242 "interpretor.y"
                         {}
#line 2330 "interpretor.tab.c"
    break;

  case 86:
#line 243 "interpretor.y"
                {}
#line 2336 "interpretor.tab.c"
    break;

  case 87:
#line 244 "interpretor.y"
                {(yyval.nodPtr) = nodCon(constInt, &(yyvsp[0].intVal));}
#line 2342 "interpretor.tab.c"
    break;

  case 88:
#line 245 "interpretor.y"
                  {(yyval.nodPtr) = nodCon(constFloat, &(yyvsp[0].floatVal));}
#line 2348 "interpretor.tab.c"
    break;

  case 89:
#line 246 "interpretor.y"
                         {(yyval.nodPtr) = (yyvsp[-1].nodPtr);}
#line 2354 "interpretor.tab.c"
    break;

  case 90:
#line 247 "interpretor.y"
                                {(yyval.nodPtr) = nodOper('+', 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr));}
#line 2360 "interpretor.tab.c"
    break;

  case 91:
#line 248 "interpretor.y"
                                {(yyval.nodPtr) = nodOper('-', 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr));}
#line 2366 "interpretor.tab.c"
    break;

  case 92:
#line 249 "interpretor.y"
                                {(yyval.nodPtr) = nodOper('*', 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr));}
#line 2372 "interpretor.tab.c"
    break;

  case 93:
#line 250 "interpretor.y"
                                {(yyval.nodPtr) = nodOper('/', 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr));}
#line 2378 "interpretor.tab.c"
    break;

  case 94:
#line 251 "interpretor.y"
                                {(yyval.nodPtr) = nodOper('%', 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr));}
#line 2384 "interpretor.tab.c"
    break;

  case 95:
#line 252 "interpretor.y"
                               {(yyval.nodPtr) = nodOper(NEG, 1, (yyvsp[0].nodPtr));}
#line 2390 "interpretor.tab.c"
    break;

  case 96:
#line 253 "interpretor.y"
           {short b = 1; (yyval.nodPtr) = nodCon(constBool, &b);}
#line 2396 "interpretor.tab.c"
    break;

  case 97:
#line 254 "interpretor.y"
            {short b = 0; (yyval.nodPtr) = nodCon(constBool, &b);}
#line 2402 "interpretor.tab.c"
    break;

  case 98:
#line 255 "interpretor.y"
                               {(yyval.nodPtr) = nodOper(LT, 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr));}
#line 2408 "interpretor.tab.c"
    break;

  case 99:
#line 256 "interpretor.y"
                               {(yyval.nodPtr) = nodOper(GT, 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr));}
#line 2414 "interpretor.tab.c"
    break;

  case 100:
#line 257 "interpretor.y"
                                {(yyval.nodPtr) = nodOper(LTE, 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr));}
#line 2420 "interpretor.tab.c"
    break;

  case 101:
#line 258 "interpretor.y"
                                {(yyval.nodPtr) = nodOper(GTE, 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr));}
#line 2426 "interpretor.tab.c"
    break;

  case 102:
#line 259 "interpretor.y"
                                     {(yyval.nodPtr) = nodOper(EQUALITY, 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr));}
#line 2432 "interpretor.tab.c"
    break;

  case 103:
#line 260 "interpretor.y"
                                      {(yyval.nodPtr) = nodOper(INEQUALITY, 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr));}
#line 2438 "interpretor.tab.c"
    break;

  case 104:
#line 261 "interpretor.y"
                                {(yyval.nodPtr) = nodOper(AND, 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr));}
#line 2444 "interpretor.tab.c"
    break;

  case 105:
#line 262 "interpretor.y"
                               {(yyval.nodPtr) = nodOper(OR, 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr));}
#line 2450 "interpretor.tab.c"
    break;

  case 106:
#line 263 "interpretor.y"
                     {(yyval.nodPtr) = nodOper('!', 1, (yyvsp[0].nodPtr));}
#line 2456 "interpretor.tab.c"
    break;

  case 107:
#line 264 "interpretor.y"
                 {(yyval.nodPtr) = nodCon(constChar, &(yyvsp[0].charVal));}
#line 2462 "interpretor.tab.c"
    break;

  case 108:
#line 265 "interpretor.y"
                {(yyval.nodPtr) = nodCon(constStr, &(yyvsp[0].strVal));}
#line 2468 "interpretor.tab.c"
    break;


#line 2472 "interpretor.tab.c"

        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
                                        yyesa, &yyes, &yyes_capacity, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

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


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 268 "interpretor.y"

int check = 1;

#define SIZEOF_NODETYPE ((char *)&p->con - (char *)p)
nodeType *nodCon(int type, void* value)
{
    nodeType *p;
    size_t nodeSize;
    /* alocare memorie pentru noul nod */
    nodeSize = SIZEOF_NODETYPE + sizeof(conNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");
    /* copiere valoare constanta */
    if (type == constInt){
        p->type = constInt;
        p->con.intVal = *((int*)value);
    }
    else if (type == constBool){
        p->type = constBool;
        p->con.boolVal = *((short*)value);
    }
    else if (type == constChar){
        p->type = constChar;
        p->con.charVal = *((char*)value);
    }
    else if (type == constFloat){
        p->type = constFloat;
        p->con.floatVal = *((float*)value);
    }
    else if (type == constStr){
        p->type = constStr;
        p->con.strVal = *((char**)value);
    }
    else if(type==typeName){
        p->type = typeName;
        p->con.typeVal = *((int*)value);
    }
    return p;
}
nodeType *nodId(char* i, int newId)
{
    nodeType *p;
    size_t nodeSize;
    /* alocare memorie pentru noul nod */
    nodeSize = SIZEOF_NODETYPE + sizeof(idNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");
    /* copiere valoare indice */
    p->type = typeId;
    p->id.i = getIndex(i, localScope);
    return p;
}

nodeType *nodOper(int oper, int nops, ...)
{
    va_list ap;
    nodeType *p;
    size_t nodeSize;
    int i;
    /* allocare memorie pentru noul nod */
    nodeSize = SIZEOF_NODETYPE + sizeof(oprNodeType) +
               (nops - 1) * sizeof(nodeType *);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");
    /* copiere informatii functie de nops */
    p->type = typeOper;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType *);
    va_end(ap);
    return p;
}

nodeType *nodArr(int type, int size)
{
    nodeType *p;
    size_t nodeSize;
    /* alocare memorie pentru noul nod */
    nodeSize = SIZEOF_NODETYPE + sizeof(arrayNodeType) + size*sizeof(int);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");
    /* copiere valoare constanta */
    if (type == INT){
        p->type = arraylist;
        p->arr.arrInt=(int*)malloc(size*sizeof(int));
        for(int i=0; i<size;i++){
            p->arr.arrInt[i] = arrayInt[i];
        }
    }
    else if (type == BOOL){
        p->type = arraylist;
        p->arr.arrBool=malloc(size*sizeof(short));
        for(int i=0; i<size;i++){
            p->arr.arrBool[i] = arrayBool[i];
        }
    }
    else if (type == CHAR){
        p->type = arraylist;
        p->arr.arrChar=malloc(size*sizeof(char));
        for(int i=0; i<size;i++){
            p->arr.arrChar[i] = arrayChar[i];
        }
    }
    else if (type == STRING){
        p->type = arraylist;
        p->arr.arrStr=malloc(size*sizeof(char*));
        for(int i=0; i<size;i++){
            p->arr.arrStr[i] = arrayStr[i];
        }
    }
    else if (type == FLOAT){
        p->type = arraylist;
        p->arr.arrFloat=malloc(size*sizeof(float));
        for(int i=0; i<size;i++){
            p->arr.arrFloat[i] = arrayFloat[i];
        }
    }
    return p;
}
void freeNode(nodeType *p)
{
    int i;
    if (!p)
        return;
    if (p->type == typeOper)
    {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    }
    free(p);
}


int interpret(nodeType *p)
{
    int result;
    if (!p)
        return 0;
    switch (p->type)
    {
    case constInt:
        return p->con.intVal;
    case constFloat:
        return p->con.floatVal;
    case constBool:
        return p->con.boolVal;
    case constChar:
        return p->con.charVal;
    case constStr:
        return *p->con.strVal;
    case typeId:
        return sym[p->id.i];
    case typeOper:
        switch (p->opr.oper)
        {
        case MAIN: return interpret(p->opr.op[0]);
        case EVAL:
            inorderExpr(p->opr.op[0]);
            if (strstr(strExpr, "fail"))
            {
                evalError("Parametrul nu este de tip int - la eval #", nreval);
                return 0;
            }
            nreval++;
            result = interpret(p->opr.op[0]);
            printf("Eval[%s] = %d\n", strExpr, result);
            return result;
        case ';': interpret(p->opr.op[0]);
            return interpret(p->opr.op[1]);
        case WHILE:
            while (interpret(p->opr.op[0]))
                interpret(p->opr.op[1]);
            return 0;
        case IF:
            if (interpret(p->opr.op[0]))
                interpret(p->opr.op[1]);
            else if (p->opr.nops > 2)
                interpret(p->opr.op[2]);
            return 0;
        case FOR:
            for(interpret(p->opr.op[0]);interpret(p->opr.op[1]);interpret(p->opr.op[2]))
                interpret(p->opr.op[3]);
            return 0;
        case ARR:
            if(p->opr.nops == 3){
                if(p->opr.op[0]->con.typeVal==INT)
                    return sym[p->opr.op[1]->id.i] = 0;
                else if(p->opr.op[0]->con.typeVal==FLOAT)
                    return sym[p->opr.op[1]->id.i] = 0.0;
                else if(p->opr.op[0]->con.typeVal==CHAR)
                    return sym[p->opr.op[1]->id.i] = '\0';
                else if(p->opr.op[0]->con.typeVal==STRING)
                    return sym[p->opr.op[1]->id.i] = '\0';
                else if(p->opr.op[0]->con.typeVal==BOOL)
                    return sym[p->opr.op[1]->id.i] = 0;
            }
            else{
                if(p->opr.op[0]->con.typeVal==INT)
                    return sym[p->opr.op[1]->id.i] = p->opr.op[3]->arr.arrInt[0];
                else if(p->opr.op[0]->con.typeVal==FLOAT)
                    return sym[p->opr.op[1]->id.i] = p->opr.op[3]->arr.arrFloat[0];
                else if(p->opr.op[0]->con.typeVal==CHAR)
                    return sym[p->opr.op[1]->id.i] = p->opr.op[3]->arr.arrChar[0];
                else if(p->opr.op[0]->con.typeVal==STRING)
                    return sym[p->opr.op[1]->id.i] = *p->opr.op[3]->arr.arrStr[0];
                else if(p->opr.op[0]->con.typeVal==BOOL)
                    return sym[p->opr.op[1]->id.i] = p->opr.op[3]->arr.arrBool[0];
            }
        case VAR:
            if(p->opr.nops == 2){
                if(p->opr.op[0]->con.typeVal==INT)
                    return symbol[p->opr.op[1]->id.i].val.intVal=0;
                else if(p->opr.op[0]->con.typeVal==FLOAT)
                    return symbol[p->opr.op[1]->id.i].val.floatVal =0.0;
                else if(p->opr.op[0]->con.typeVal==CHAR)
                    return symbol[p->opr.op[1]->id.i].val.charVal = '\0';
                else if(p->opr.op[0]->con.typeVal==STRING){
                    symbol[p->opr.op[1]->id.i].val.strVal = (char*)"";
                    return 0;
                }
                else if(p->opr.op[0]->con.typeVal==BOOL)
                    return symbol[p->opr.op[1]->id.i].val.boolVal = 0;
            }
            else{
                if(p->opr.op[0]->con.typeVal==INT)
                    return symbol[p->opr.op[1]->id.i].val.intVal=interpret(p->opr.op[2]);
                else if(p->opr.op[0]->con.typeVal==FLOAT)
                    return symbol[p->opr.op[1]->id.i].val.floatVal=interpret(p->opr.op[2]);
                else if(p->opr.op[0]->con.typeVal==CHAR)
                    return symbol[p->opr.op[1]->id.i].val.charVal=interpret(p->opr.op[2]);
                else if(p->opr.op[0]->con.typeVal==STRING)
                    return (symbol[p->opr.op[1]->id.i].val.strVal[0])=interpret(p->opr.op[2]);
                else if(p->opr.op[0]->con.typeVal==BOOL)
                    return symbol[p->opr.op[1]->id.i].val.boolVal=interpret(p->opr.op[2]);
            }
        case '=':
            return sym[p->opr.op[0]->id.i] = interpret(p->opr.op[1]);
        case NEG:
            return -interpret(p->opr.op[0]);
        case '+':
            return interpret(p->opr.op[0]) + interpret(p->opr.op[1]);
        case '-':
            return interpret(p->opr.op[0]) - interpret(p->opr.op[1]);
        case '*':
            return interpret(p->opr.op[0]) * interpret(p->opr.op[1]);
        case '/':
            return interpret(p->opr.op[0]) / interpret(p->opr.op[1]);
        case '%':
            return interpret(p->opr.op[0]) % interpret(p->opr.op[1]);
        case LT:
            return interpret(p->opr.op[0]) <  interpret(p->opr.op[1]);
        case GT:
            return interpret(p->opr.op[0]) > interpret(p->opr.op[1]);
        case GTE:
            return interpret(p->opr.op[0]) >= interpret(p->opr.op[1]);
        case LTE:
            return interpret(p->opr.op[0]) <= interpret(p->opr.op[1]);
        case INEQUALITY:
            return interpret(p->opr.op[0]) !=  interpret(p->opr.op[1]);
        case EQUALITY:
            return interpret(p->opr.op[0]) == interpret(p->opr.op[1]);
        }
    }
    return 0;
}

void evalError(const char* s, int nre){
    printf("%s%d\n", s, nre);
}

int yyerror(const char *s)
{
    printf("%s la linia %d, cuvantul %d\n", s, nr_lines, nr_word);
    check = 0;
}

int main(int argc, char **argv)
{   
    printf("\n");
    if (argc > 0)
        yyin = fopen(argv[1], "r");
    yyparse();
    if (check == 1)
    {
        printf("\n");
        /*for (int i = 0; i < 30; i++)
        {
            printf("%d " , sym[i]);
        }*/
        printf("%s = %d", symbol[0].name, symbol[0].val.charVal);
        printf("\n");
    }
}
