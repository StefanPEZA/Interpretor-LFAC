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
#line 1 "interpretor.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    extern int nr_lines;
    extern int nr_word;
    extern FILE* yyin;
    extern char* yytext;

#line 76 "interpretor.tab.c" /* yacc.c:339  */

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
   by #include "interpretor.tab.h".  */
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
    IDENTIFIER = 275,
    INT_CONST = 276,
    FLOAT_CONST = 277,
    CHAR_CONST = 278,
    STR_CONST = 279,
    TRUE = 280,
    FALSE = 281,
    AND = 282,
    OR = 283,
    EQUALITY = 284,
    INEQUALITY = 285,
    LT = 286,
    GT = 287,
    LTE = 288,
    GTE = 289,
    NEG = 290,
    ACCES = 291,
    THEN = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 10 "interpretor.y" /* yacc.c:355  */

    short boolVal : 1;
    int intVal;
    float floatVal;
    char charVal;
    char* stringVal;
    char* varId;

#line 163 "interpretor.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INTERPRETOR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 180 "interpretor.tab.c" /* yacc.c:358  */

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
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   391

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  230

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,     2,     2,    40,     2,     2,
      43,    44,    38,    36,    50,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
       2,    35,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      41,    45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    42,    42,    43,    43,    44,    45,    46,    47,    48,
      51,    54,    55,    58,    59,    62,    65,    66,    69,    70,
      73,    74,    77,    78,    79,    80,    81,    84,    85,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
     101,   102,   105,   108,   111,   114,   115,   117,   118,   119,
     120,   121,   122,   124,   127,   128,   130,   131,   133,   134,
     136,   137,   139,   140,   141,   142,   144,   146,   149,   152,
     155,   156,   159,   162,   163,   166,   169,   170,   173,   174,
     177,   178,   179,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     213,   214,   215,   216,   217,   218
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONTAINER", "EVAL", "CONST", "FUN",
  "VAR", "CALL", "IF", "ELSE", "WHILE", "FOR", "INT", "FLOAT", "CHAR",
  "STRING", "BOOL", "VOID", "ARR", "IDENTIFIER", "INT_CONST",
  "FLOAT_CONST", "CHAR_CONST", "STR_CONST", "TRUE", "FALSE", "AND", "OR",
  "EQUALITY", "INEQUALITY", "LT", "GT", "LTE", "GTE", "'='", "'+'", "'-'",
  "'*'", "'/'", "'%'", "NEG", "'!'", "'('", "')'", "ACCES", "THEN", "';'",
  "'{'", "'}'", "','", "'['", "']'", "$accept", "start", "stmts", "stmt",
  "container_declaration", "container_body", "container_elements",
  "function_declaration", "return_type", "fun_params", "parameter",
  "types", "fun_body", "code_block", "if_statement", "while_statement",
  "for_statement", "var_assignment", "array_declaration", "array_list",
  "array_assignment", "array_list_int", "array_list_float",
  "array_list_char", "array_list_string", "array_list_bool", "array_val",
  "get_container_elem", "container_assignment", "container_function",
  "var_declaration", "const_declaration", "call_function", "eval_function",
  "call_params", "call_param", "expression", "nr_exp", "bool_exp",
  "string_exp", YY_NULLPTR
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
     285,   286,   287,   288,   289,    61,    43,    45,    42,    47,
      37,   290,    33,    40,    41,   291,   292,    59,   123,   125,
      44,    91,    93
};
# endif

#define YYPACT_NINF -152

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-152)))

#define YYTABLE_NINF -98

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     160,   -43,   264,   362,   264,   264,    10,   160,  -152,  -152,
    -152,   -16,   -14,    18,    99,  -152,  -152,  -152,  -152,  -152,
      74,  -152,    80,  -152,    83,    94,  -152,  -152,  -152,  -152,
    -152,    22,  -152,  -152,    69,    85,   111,    91,   108,   158,
    -152,  -152,   209,   264,   209,   147,   115,    47,  -152,  -152,
    -152,  -152,  -152,  -152,   113,   216,   216,   121,   125,  -152,
     316,   142,   144,    19,  -152,   161,  -152,   132,  -152,   168,
     175,    37,   113,  -152,  -152,  -152,   231,   254,   270,   316,
    -152,   286,   -12,   113,  -152,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   216,   216,   105,   156,   264,  -152,
     170,  -152,   155,   321,  -152,  -152,   301,   301,   301,   301,
     301,   101,   101,  -152,  -152,  -152,   180,  -152,    37,  -152,
    -152,  -152,   324,  -152,   167,  -152,    79,   166,   173,   174,
      25,    15,  -152,  -152,  -152,  -152,   171,   193,   196,   212,
      67,   201,   203,   207,   208,   210,   360,   206,   213,  -152,
     209,   216,   246,   209,  -152,  -152,  -152,  -152,  -152,   209,
     209,   202,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,   223,   224,   239,   245,   247,   255,   113,
     202,   229,    51,   261,   265,  -152,  -152,  -152,  -152,   169,
    -152,  -152,  -152,   290,   291,   298,   303,   148,   330,   177,
     280,   294,   216,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,   324,   324,    34,   285,   302,   246,   352,
    -152,   319,   323,   325,   324,   324,   315,   338,  -152,  -152
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     2,     4,     9,
       8,     0,     0,     0,     0,    22,    23,    24,    25,    26,
       0,    17,     0,    16,     0,     0,     1,     3,     6,     5,
       7,     0,    11,    14,     0,     0,     0,    70,     0,     0,
      12,    13,     0,    21,     0,     0,     0,    83,    86,    87,
     113,   114,    98,    99,     0,     0,     0,    85,    84,    72,
      80,    81,    82,     0,    18,     0,    71,     0,    10,     0,
       0,    83,     0,    85,    84,    94,    95,    97,    96,     0,
     109,     0,     0,     0,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,    20,
      46,    67,     0,     0,    88,   100,   105,   101,   102,   103,
     104,    89,    90,    91,    92,    93,   107,   108,   110,   112,
     111,   115,     0,    19,     0,    66,     0,     0,     0,     0,
       0,     0,    27,    37,    38,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,     0,     0,    74,
       0,     0,     0,     0,    15,    28,    34,    30,    31,     0,
       0,     0,    35,    36,    29,    32,    33,    55,    57,    59,
      61,    64,    65,     0,    47,    48,    49,    50,    51,     0,
       0,     0,     0,     0,     0,    44,    53,    68,    78,     0,
      76,    79,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    77,    54,    56,    58,    60,    62,
      63,    75,    73,     0,     0,     0,     0,     0,     0,    40,
      42,     0,     0,     0,     0,     0,     0,     0,    41,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -152,  -152,  -152,   365,  -152,  -152,   357,    41,  -152,  -152,
     292,   141,  -152,  -128,  -152,  -152,  -152,  -151,    30,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,   -42,   -38,  -152,  -152,
      59,   124,  -112,  -152,   211,   -98,   -23,   -47,   -44,   293
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    31,    32,    10,    22,    63,
      64,    65,   131,   132,   133,   134,   135,   136,   137,   173,
     138,   174,   175,   176,   177,   178,    73,    74,   141,   142,
     143,   144,   145,   149,   189,   190,   191,    60,    61,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,   184,    57,   155,    58,    14,    58,    75,    79,    81,
      26,    80,    82,    77,    77,    94,    95,    78,    78,    59,
       2,    66,     4,   126,   127,   103,   128,   129,     3,     4,
      11,    28,   105,    29,     5,   130,   106,    11,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    79,    79,   188,
     116,   117,    77,    77,   119,    33,    78,    78,   120,    12,
     153,    94,    95,    97,   154,    30,    12,   221,   188,    98,
      69,    39,    33,    34,   -95,   -95,    70,   188,    94,    95,
     139,   218,    69,   147,   140,   216,   217,   188,    70,   139,
      34,   204,    69,   140,    35,   201,   226,   227,    70,   148,
      36,   204,   160,    37,    79,     3,     4,   182,    57,    77,
     161,    57,    58,    78,    38,    58,    41,    57,    57,    57,
      42,    58,    58,    58,    13,   118,    44,   181,    50,    51,
     185,    13,   198,    71,    48,    49,   186,   187,    57,    91,
      92,    93,    58,    20,    23,    24,    25,    57,   -97,   -97,
      54,    58,   -96,   -96,    43,    79,    72,    57,   215,    45,
      77,    58,    68,     1,    78,     2,     3,     4,    67,    94,
      95,   139,   139,   209,   210,   140,   140,   126,    46,     5,
      96,    99,   139,   139,   100,   126,   140,   140,   101,    47,
      48,    49,    50,    51,    52,    53,   102,    47,    48,    49,
      50,    51,    52,    53,   122,   124,    54,   125,    95,   150,
     126,    55,    56,   203,    54,   146,   151,   152,   156,    55,
      56,   212,    47,    48,    49,    50,    51,    52,    53,    47,
      48,    49,    50,    51,    52,    53,    76,    48,    49,    54,
     157,    52,    53,   158,    55,    56,    54,   159,   162,   179,
     163,    55,    56,    54,   164,   165,   180,   166,    55,    56,
     -83,   -83,   -83,   -83,   -83,   -83,   183,   -83,   -83,   -83,
     -83,   -83,   192,   200,   193,   -83,    69,    15,    16,    17,
      18,    19,    70,   -85,   -85,   -85,   -85,   -85,   -85,   194,
     -85,   -85,   -85,   -85,   -85,   195,   153,   196,   -85,   -84,
     -84,   -84,   -84,   -84,   -84,   197,   -84,   -84,   -84,   -84,
     -84,   205,   202,   206,   -84,    83,    84,    85,    86,    87,
      88,   207,    89,    90,    91,    92,    93,   208,   213,     2,
     104,     4,   126,   127,   219,   128,   129,    89,    90,    91,
      92,    93,   214,     5,   130,    83,    84,    85,    86,    87,
      88,   220,    89,    90,    91,    92,    93,    89,    90,    91,
      92,    93,   222,   223,   228,   104,    89,    90,    91,    92,
      93,   224,    27,   225,   211,    15,    16,    17,    18,    19,
      21,   167,   168,   169,   170,   171,   172,   229,    40,   121,
     123,   199
};

static const yytype_uint8 yycheck[] =
{
      42,   152,    44,   131,    42,    48,    44,    54,    55,    56,
       0,    55,    56,    55,    56,    27,    28,    55,    56,    42,
       5,    44,     7,     8,     9,    72,    11,    12,     6,     7,
       0,    47,    44,    47,    19,    20,    83,     7,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,   161,
      94,    95,    94,    95,    96,    14,    94,    95,    96,     0,
      35,    27,    28,    44,    49,    47,     7,   218,   180,    50,
      45,    49,    31,    14,    27,    28,    51,   189,    27,    28,
     122,    47,    45,     4,   122,   213,   214,   199,    51,   131,
      31,   189,    45,   131,    20,    44,   224,   225,    51,    20,
      20,   199,    35,    20,   151,     6,     7,   151,   150,   151,
      43,   153,   150,   151,    20,   153,    47,   159,   160,   161,
      35,   159,   160,   161,     0,    20,    35,   150,    23,    24,
     153,     7,   179,    20,    21,    22,   159,   160,   180,    38,
      39,    40,   180,     2,     3,     4,     5,   189,    27,    28,
      37,   189,    27,    28,    43,   202,    43,   199,   202,    51,
     202,   199,    47,     3,   202,     5,     6,     7,    21,    27,
      28,   213,   214,    25,    26,   213,   214,     8,    20,    19,
      36,    20,   224,   225,    52,     8,   224,   225,    20,    20,
      21,    22,    23,    24,    25,    26,    21,    20,    21,    22,
      23,    24,    25,    26,    48,    35,    37,    52,    28,    43,
       8,    42,    43,    44,    37,    48,    43,    43,    47,    42,
      43,    44,    20,    21,    22,    23,    24,    25,    26,    20,
      21,    22,    23,    24,    25,    26,    20,    21,    22,    37,
      47,    25,    26,    47,    42,    43,    37,    35,    47,    43,
      47,    42,    43,    37,    47,    47,    43,    47,    42,    43,
      29,    30,    31,    32,    33,    34,    20,    36,    37,    38,
      39,    40,    49,    44,    50,    44,    45,    13,    14,    15,
      16,    17,    51,    29,    30,    31,    32,    33,    34,    50,
      36,    37,    38,    39,    40,    50,    35,    50,    44,    29,
      30,    31,    32,    33,    34,    50,    36,    37,    38,    39,
      40,    21,    47,    22,    44,    29,    30,    31,    32,    33,
      34,    23,    36,    37,    38,    39,    40,    24,    48,     5,
      44,     7,     8,     9,    49,    11,    12,    36,    37,    38,
      39,    40,    48,    19,    20,    29,    30,    31,    32,    33,
      34,    49,    36,    37,    38,    39,    40,    36,    37,    38,
      39,    40,    10,    44,    49,    44,    36,    37,    38,    39,
      40,    48,     7,    48,    44,    13,    14,    15,    16,    17,
      18,    21,    22,    23,    24,    25,    26,    49,    31,    96,
      98,   180
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,    19,    54,    55,    56,    57,
      60,    71,    83,    84,    48,    13,    14,    15,    16,    17,
      64,    18,    61,    64,    64,    64,     0,    56,    47,    47,
      47,    58,    59,    60,    83,    20,    20,    20,    20,    49,
      59,    47,    35,    43,    35,    51,    20,    20,    21,    22,
      23,    24,    25,    26,    37,    42,    43,    79,    80,    89,
      90,    91,    92,    62,    63,    64,    89,    21,    47,    45,
      51,    20,    43,    79,    80,    90,    20,    79,    80,    90,
      91,    90,    91,    29,    30,    31,    32,    33,    34,    36,
      37,    38,    39,    40,    27,    28,    36,    44,    50,    20,
      52,    20,    21,    90,    44,    44,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    91,    91,    20,    79,
      80,    92,    48,    63,    35,    52,     8,     9,    11,    12,
      20,    65,    66,    67,    68,    69,    70,    71,    73,    79,
      80,    81,    82,    83,    84,    85,    48,     4,    20,    86,
      43,    43,    43,    35,    49,    66,    47,    47,    47,    35,
      35,    43,    47,    47,    47,    47,    47,    21,    22,    23,
      24,    25,    26,    72,    74,    75,    76,    77,    78,    43,
      43,    89,    91,    20,    70,    89,    89,    89,    85,    87,
      88,    89,    49,    50,    50,    50,    50,    50,    90,    87,
      44,    44,    47,    44,    88,    21,    22,    23,    24,    25,
      26,    44,    44,    48,    48,    91,    66,    66,    47,    49,
      49,    70,    10,    44,    48,    48,    66,    66,    49,    49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    56,    56,    56,
      57,    58,    58,    59,    59,    60,    61,    61,    62,    62,
      63,    63,    64,    64,    64,    64,    64,    65,    65,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      67,    67,    68,    69,    70,    71,    71,    72,    72,    72,
      72,    72,    72,    73,    74,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    78,    78,    79,    80,    81,    82,
      83,    83,    84,    85,    85,    86,    87,    87,    88,    88,
      89,    89,    89,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      92,    92,    92,    92,    92,    92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     2,     1,     1,
       6,     1,     2,     2,     1,     9,     1,     1,     1,     3,
       2,     0,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       7,    11,     7,    11,     3,    10,     6,     1,     1,     1,
       1,     1,     0,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     1,     4,     3,     3,     4,
       3,     5,     5,     5,     2,     4,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     2,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     2,
       1,     1,     1,     1,     1,     3
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
  YYUSE (yytype);
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
yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yytype_int16 **yybottom,
                      yytype_int16 *yybottom_no_free,
                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
{
  YYSIZE_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYSIZE_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYSIZE_T yyalloc = 2 * yysize_new;
      yytype_int16 *yybottom_new;
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
        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
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
yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  yytype_int16 *yyes_prev = yyssp;
  yytype_int16 *yyesp = yyes_prev;
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
  if (yytoken == YYUNDEFTOK)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          yyrule = yydefact[*yyesp];
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
        YYSIZE_T yylen = yyr2[yyrule];
        YYDPRINTF ((stderr, " R%d", yyrule - 1));
        if (yyesp != yyes_prev)
          {
            YYSIZE_T yysize = yyesp - *yyes + 1;
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
        int yystate;
        {
          int yylhs = yyr1[yyrule] - YYNTOKENS;
          yystate = yypgoto[yylhs] + *yyesp;
          if (yystate < 0 || YYLAST < yystate
              || yycheck[yystate] != *yyesp)
            yystate = yydefgoto[yylhs];
          else
            yystate = yytable[yystate];
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            *yyesp = yystate;
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
            *++yyesp = yystate;
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}


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
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store or if
   yy_lac returned 2.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyesa, yytype_int16 **yyes,
                YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
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
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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

    yytype_int16 yyesa[20];
    yytype_int16 *yyes;
    YYSIZE_T yyes_capacity;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  yyes = yyesa;
  yyes_capacity = sizeof yyesa / sizeof *yyes;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");

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
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
          case 4:
#line 43 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1685 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 44 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1691 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 45 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1697 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 46 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1703 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 47 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1709 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 48 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1715 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 51 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1721 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 54 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1727 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 55 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1733 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 58 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1739 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 59 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1745 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 62 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1751 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 65 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1757 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 66 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1763 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 70 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1769 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 73 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1775 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 74 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1781 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 77 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1787 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 78 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1793 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 79 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1799 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 80 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1805 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 81 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1811 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 84 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1817 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 85 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1823 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 88 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1829 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 89 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1835 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 90 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1841 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 91 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1847 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 92 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1853 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 93 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1859 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 94 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1865 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 95 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1871 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 96 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1877 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 97 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1883 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 98 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1889 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 101 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1895 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 102 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1901 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 105 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1907 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 108 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1913 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 111 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1919 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 114 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1925 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 115 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1931 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 117 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1937 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 118 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1943 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 119 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1949 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 120 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1955 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 121 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1961 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 124 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1967 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 127 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1973 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 128 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1979 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 130 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1985 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 131 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1991 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 133 "interpretor.y" /* yacc.c:1646  */
    {}
#line 1997 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 134 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2003 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 136 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2009 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 137 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2015 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 139 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2021 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 140 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2027 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 141 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2033 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 142 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2039 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 146 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2045 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 149 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2051 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 152 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2057 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 155 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2063 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 156 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2069 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 159 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2075 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 162 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2081 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 163 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2087 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 166 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2093 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 169 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2099 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 170 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2105 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 173 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2111 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 174 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2117 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 177 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2123 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 178 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2129 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 179 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2135 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 182 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2141 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 183 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2147 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 184 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2153 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 185 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2159 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 186 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2165 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 187 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2171 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 188 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2177 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 189 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2183 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 190 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2189 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 191 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2195 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 192 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2201 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 193 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2207 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 196 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2213 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 197 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2219 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 198 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2225 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 199 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2231 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 200 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2237 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 201 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2243 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 202 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2249 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 203 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2255 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 204 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2261 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 205 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2267 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 206 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2273 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 207 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2279 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 208 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2285 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 209 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2291 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 210 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2297 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 213 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2303 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 214 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2309 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 215 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2315 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 216 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2321 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 217 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2327 "interpretor.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 218 "interpretor.y" /* yacc.c:1646  */
    {}
#line 2333 "interpretor.tab.c" /* yacc.c:1646  */
    break;


#line 2337 "interpretor.tab.c" /* yacc.c:1646  */
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
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 221 "interpretor.y" /* yacc.c:1906  */

int check = 1;
void yyerror(char *s)
{
    printf ("%s la linia %d, cuvantul %d\n", s, nr_lines, nr_word);
    check = 0;
}

int main(int argc, char **argv){
  if(argc>0)
    yyin=fopen(argv[1],"r");
  yyparse();
  if (check == 1)
  {
    printf ("Programul este corect sintactic!\n\n");
  }
}
