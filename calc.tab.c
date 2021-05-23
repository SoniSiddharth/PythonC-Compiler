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
#line 2 "calc.y" /* yacc.c:339  */

	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>  
	#include "calc.h"  /* Contains definition of `symrec'*/
	int  yylex(void);
	void yyerror (char  *);

	// variables to define different states which statements are executing or flags
	int whileStart=0,nextJump=0,forStart=0,nextJumpfor=0,ifelseStart=0,nextJumpIfElse=0;
	int count=0;
	int lenfunc=0;
	int labelCount=0;
	int inForloop=0;     
	int inWhileloop=0;
	int msg_flag=0;
	FILE *fp;
	struct StmtsNode *final;
	void StmtsTrav(stmtsptr ptr);
	void StmtTrav(stmtptr ptr);

#line 88 "calc.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "calc.tab.h".  */
#ifndef YY_YY_CALC_TAB_H_INCLUDED
# define YY_YY_CALC_TAB_H_INCLUDED
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
    NUM = 258,
    STR = 259,
    WHILE = 260,
    FOR = 261,
    SEMIC = 262,
    IF = 263,
    ELSE = 264,
    BREAK = 265,
    CONTINUE = 266,
    END = 267,
    RETURN = 268,
    INPUT = 269,
    OUTPUT = 270,
    LENGTH = 271,
    DECL = 272,
    GT = 273,
    LT = 274,
    VAR = 275,
    FUNC = 276,
    FUNC_CALL = 277
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "calc.y" /* yacc.c:355  */

	int   val;  /* For returning numbers.                   */
	struct symrec  *tptr;   /* For returning symbol-table pointers      */
	char fun_name[1000]; // character array for function name
	char c[1000];		
	char nData[100];
	char string[1000];
	// statements as nodes of parse tree 
	struct StmtNode *stmtptr;
	struct StmtsNode *stmtsptr;

#line 163 "calc.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CALC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 180 "calc.tab.c" /* yacc.c:358  */

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
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   161

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  37
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      29,    31,    26,    25,    30,    24,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    23,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    58,    58,    59,    62,    69,    70,    91,   102,   122,
     135,   144,   153,   164,   172,   176,   193,   198,   214,   228,
     243,   258,   267,   275,   283,   293,   294,   300,   306,   313,
     317,   320,   321,   322,   323,   324,   327,   328
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "STR", "WHILE", "FOR", "SEMIC",
  "IF", "ELSE", "BREAK", "CONTINUE", "END", "RETURN", "INPUT", "OUTPUT",
  "LENGTH", "DECL", "GT", "LT", "VAR", "FUNC", "FUNC_CALL", "'='", "'-'",
  "'+'", "'*'", "'/'", "'\\n'", "'('", "','", "')'", "'{'", "'}'", "'['",
  "']'", "$accept", "prog", "stmts", "stmt", "RELOP", "a_stat", "exp", "x", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    61,    45,    43,    42,    47,    10,    40,
      44,    41,   123,   125,    91,    93
};
# endif

#define YYPACT_NINF -38

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-38)))

#define YYTABLE_NINF -4

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,    -9,    21,    27,    30,    44,    37,    48,    58,    24,
      50,   -38,    80,   -38,     3,   -38,   -38,    61,     9,    62,
     -38,    63,    12,    51,    35,    40,    64,   -38,   -38,    57,
      65,    79,    57,    56,    59,    18,    41,   -38,   -38,    60,
     -22,    67,   -38,    47,    66,    69,    68,   -38,   -38,    71,
      10,    73,    74,    72,    77,    78,    87,    75,    76,     2,
      88,    42,    89,    42,    42,    42,    42,    90,    91,    92,
      84,    82,    57,    86,   -38,   -38,   -38,    83,   -38,    93,
      94,    95,    97,   -38,    85,    98,   -38,   -38,   -38,   -38,
      43,    43,    99,   100,   104,    -5,   102,   -38,   101,   103,
     114,   -38,   115,   108,   109,   106,    20,   112,   111,    20,
     113,   -38,   -38,   116,   117,   -38,   -38,    20,   107,     9,
     -38,   110,   -38,   118,   121,   119,   122,   120,   133,   -38,
     -38,   125,   -38,   123,   124,   132,    20,    20,   126,   127,
     128,   -38,   129,   130,   -38,   -38
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     0,     2,     0,    14,    29,     0,     0,     0,
       7,     0,     0,     0,     0,     0,     0,     1,     4,     0,
       0,     0,     0,     0,     0,     0,     0,    36,    28,     0,
      37,     0,    27,    31,     0,     0,     0,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,     0,     0,    19,    21,    20,     0,    15,     0,
       0,     0,     0,    37,     0,     0,    33,    32,    34,    35,
       0,     0,     0,     0,     0,     0,     0,    16,     0,     0,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    24,    23,     0,     0,    18,    17,     0,     0,     0,
      11,     0,    22,     0,     0,     0,     0,     0,     0,     9,
       8,     0,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     6,     0,     0,    13,    12
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,   -38,   -14,   -38,   -30,   -17,   -37,     4
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    12,    13,    14,    49,    15,    42,    43
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    31,    52,    -3,     1,   108,    80,    60,     2,     3,
       1,     4,    61,    37,    38,    34,     5,     6,     7,    16,
       8,     1,    81,     9,    10,     2,     3,   109,     4,    30,
      71,    11,    35,     5,     6,     7,    -3,     8,    37,    38,
       9,    10,    94,    44,    57,    37,    37,    24,    11,    55,
      17,    39,    56,   103,   104,    40,    18,    41,    25,    19,
      45,    58,    83,    71,    20,    84,    21,    86,    87,    88,
      89,    63,    64,    65,    66,    47,    48,    22,    23,    26,
      27,    29,    32,    33,    46,    36,    51,    53,    50,    59,
      54,    70,   118,    72,    73,   121,    62,     0,    69,     0,
      74,    67,   127,   125,    68,    75,    76,    77,    82,    85,
      78,    79,    92,    90,    91,    93,    61,    95,    96,   119,
     101,    97,   139,   140,   107,    98,    99,   100,   102,   111,
     105,   112,   106,   110,   113,   114,   115,   116,   117,   120,
     126,   122,   134,   128,   138,     0,   129,   123,   124,   130,
     132,   133,   131,   135,   141,   136,   137,   144,   145,     0,
     142,   143
};

static const yytype_int16 yycheck[] =
{
      14,    18,    32,     0,     1,    10,     4,    29,     5,     6,
       1,     8,    34,     3,     4,     3,    13,    14,    15,    28,
      17,     1,    20,    20,    21,     5,     6,    32,     8,    20,
      20,    28,    20,    13,    14,    15,    33,    17,     3,     4,
      20,    21,    72,     3,     3,     3,     3,    23,    28,    31,
      29,    16,    34,    90,    91,    20,    29,    22,    34,    29,
      20,    20,    20,    20,    20,    61,    29,    63,    64,    65,
      66,    24,    25,    26,    27,    18,    19,    29,    20,    29,
       0,    20,    20,    20,    20,    34,     7,    31,    23,    29,
      31,    20,   106,    20,    20,   109,    29,    -1,    30,    -1,
      28,    35,   119,   117,    35,    28,    28,    20,    20,    20,
      35,    35,    20,    23,    23,    31,    34,    31,    35,     7,
      35,    28,   136,   137,    20,    31,    31,    30,    30,    28,
      31,    28,    32,    31,    20,    20,    28,    28,    32,    28,
      33,    28,     9,    33,    12,    -1,    28,    31,    31,    28,
      28,    31,    33,    28,    28,    32,    32,    28,    28,    -1,
      33,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     5,     6,     8,    13,    14,    15,    17,    20,
      21,    28,    37,    38,    39,    41,    28,    29,    29,    29,
      20,    29,    29,    20,    23,    34,    29,     0,    38,    20,
      20,    41,    20,    20,     3,    20,    34,     3,     4,    16,
      20,    22,    42,    43,     3,    20,    20,    18,    19,    40,
      23,     7,    40,    31,    31,    31,    34,     3,    20,    29,
      29,    34,    29,    24,    25,    26,    27,    35,    35,    30,
      20,    20,    20,    20,    28,    28,    28,    20,    35,    35,
       4,    20,    20,    20,    43,    20,    43,    43,    43,    43,
      23,    23,    20,    31,    40,    31,    35,    28,    31,    31,
      30,    35,    30,    42,    42,    31,    32,    20,    10,    32,
      31,    28,    28,    20,    20,    28,    28,    32,    38,     7,
      28,    38,    28,    31,    31,    38,    33,    41,    33,    28,
      28,    33,    28,    31,     9,    28,    32,    32,    12,    38,
      38,    28,    33,    33,    28,    28
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    40,    40,    41,    41,    41,
      42,    42,    42,    42,    42,    42,    43,    43
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,    12,     2,     9,     9,
      10,     8,    14,    14,     1,     5,     6,     7,     7,     5,
       5,     5,     8,     7,     7,     1,     1,     3,     3,     2,
       4,     1,     3,     3,     3,     3,     1,     1
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
#line 58 "calc.y" /* yacc.c:1646  */
    {final=(yyvsp[0].stmtsptr);}
#line 1336 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 59 "calc.y" /* yacc.c:1646  */
    {	
					(yyval.stmtsptr)=(struct StmtsNode *) malloc(sizeof(struct StmtsNode)); // for multiple  statements
	 				(yyval.stmtsptr)->singl=1;(yyval.stmtsptr)->left=(yyvsp[0].stmtptr),(yyval.stmtsptr)->right=NULL;}
#line 1344 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 62 "calc.y" /* yacc.c:1646  */
    {
					(yyval.stmtsptr)=(struct StmtsNode *) malloc(sizeof(struct StmtsNode));
					(yyval.stmtsptr)->singl=0;(yyval.stmtsptr)->left=(yyvsp[-1].stmtptr),(yyval.stmtsptr)->right=(yyvsp[0].stmtsptr);}
#line 1352 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 69 "calc.y" /* yacc.c:1646  */
    {(yyval.stmtptr)=NULL;}
#line 1358 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 70 "calc.y" /* yacc.c:1646  */
    {
					(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					sprintf((yyval.stmtptr)->initCode,"jal m_%s\n.data\n%s : .space %d \n.text\nFunc_%s:\n subu $sp,$sp,4 \n sw $ra,($sp)\n\nla $t8,%s\nlw $t0, %s($t8)\nlw $t1, %s($t8)\n",(yyvsp[-11].tptr)->name,(yyvsp[-11].tptr)->name,5000,(yyvsp[-11].tptr)->name,(yyvsp[-11].tptr)->name,(yyvsp[-9].tptr)->addr,(yyvsp[-7].tptr)->addr);
					(yyval.stmtptr)->isFunDef=1;
					(yyval.stmtptr)->isString=0; // these are to ensure we put the given code at correct block just to skip over from unnecessary if blocks
					(yyval.stmtptr)->isFunCall=0;
					(yyval.stmtptr)->isReturn=0;
					(yyval.stmtptr)->isString=0;
					(yyval.stmtptr)->isReturn=0;
					(yyval.stmtptr)->isArray=0;
					(yyval.stmtptr)->isArrayOne=0;
					(yyval.stmtptr)->isArrayTwo=0;
					(yyval.stmtptr)->isOutputOne=0;
					(yyval.stmtptr)->isOutputTwo=0;
					(yyval.stmtptr)->isInput=0;					
					(yyval.stmtptr)->down=(yyvsp[-4].stmtsptr);
					(yyval.stmtptr)->FuncName=(yyvsp[-11].tptr)->name;
					// current_sym_table = $2->sym_func;
					}
#line 1382 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 91 "calc.y" /* yacc.c:1646  */
    {					
					(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					(yyval.stmtptr)->isFunDef=0;
					(yyval.stmtptr)->isFunCall=0;
					(yyval.stmtptr)->isString=0;
					(yyval.stmtptr)->isReturn=1;
					//storing the return value in $v0
					sprintf((yyval.stmtptr)->returnCode,"lw $v0, %s($t8)\nmove $t8,$t7\n",(yyvsp[0].tptr)->addr);
					}
#line 1396 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 102 "calc.y" /* yacc.c:1646  */
    { 					
					(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					sprintf((yyval.stmtptr)->initCode,"lw $t0, %s($t8)\nlw $t1, %s($t8)\n", (yyvsp[-4].tptr)->addr,(yyvsp[-2].tptr)->addr);
					// printf("\n\n%s\n",$3->type);
					(yyval.stmtptr)->isFunDef=0;
					(yyval.stmtptr)->isFunCall=1;
					(yyval.stmtptr)->isString=0;
					(yyval.stmtptr)->isReturn=0;
					(yyval.stmtptr)->isArray=0;
					(yyval.stmtptr)->isArrayOne=0;
					(yyval.stmtptr)->isArrayTwo=0;
					(yyval.stmtptr)->isOutputOne=0;
					(yyval.stmtptr)->isOutputTwo=0;
					(yyval.stmtptr)->isInput=0;		

					sprintf((yyval.stmtptr)->insertAttr,"la $t8,%s\nsw $t0,0($t8)\nsw $t1,4($t8)\n",(yyvsp[-6].fun_name));
					sprintf((yyval.stmtptr)->bodyCode,"jal Func_%s\n sw $v0,%s($t8)\n ",(yyvsp[-6].fun_name),(yyvsp[-8].tptr)->addr);
					}
#line 1419 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 122 "calc.y" /* yacc.c:1646  */
    {
					printf("\n\n%s\n",(yyvsp[-6].tptr)->type);
					if(strcmp("function",(yyvsp[-6].tptr)->type)==0){
						printf("\n**********\nSyntax Error!! missing \"call\" after \"=\"\n for function call\n*******\n");
						exit(0);
					}
					else{					
						printf("\n**********\nSyntax Error!! Function name %s is not defined\n*******\n",(yyvsp[-6].tptr)->name);
						exit(0);
					}
					}
#line 1435 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 135 "calc.y" /* yacc.c:1646  */
    {
					(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					(yyval.stmtptr)->isWhile=1;
					(yyval.stmtptr)->isString=0;
					sprintf((yyval.stmtptr)->initCode,"lw $t0, %s($t8)\nlw $t1, %s($t8)\n", (yyvsp[-7].tptr)->addr,(yyvsp[-5].tptr)->addr);
					sprintf((yyval.stmtptr)->initJumpCode,"%s",(yyvsp[-6].c));
					(yyval.stmtptr)->down=(yyvsp[-2].stmtsptr); }
#line 1447 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 144 "calc.y" /* yacc.c:1646  */
    {
					(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					(yyval.stmtptr)->isBreakorContinue = 1;
					(yyval.stmtptr)->isString=0;
					sprintf((yyval.stmtptr)->initCode,"lw $t3, %s($t8)\nlw $t4, %s($t8)\n", (yyvsp[-3].tptr)->addr,(yyvsp[-5].tptr)->addr);
					sprintf((yyval.stmtptr)->initJumpCode,"%s",(yyvsp[-4].c));
					}
#line 1459 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 153 "calc.y" /* yacc.c:1646  */
    {
					(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					(yyval.stmtptr)->isIfElse = 1;
					(yyval.stmtptr)->isString=0;
					sprintf((yyval.stmtptr)->initCode,"lw $t0, %s($t8)\nlw $t1, %s($t8)\n", (yyvsp[-11].tptr)->addr,(yyvsp[-9].tptr)->addr);
					sprintf((yyval.stmtptr)->initJumpCode,"%s",(yyvsp[-10].c));
					(yyval.stmtptr)->ifcode = (yyvsp[-6].stmtsptr);
					(yyval.stmtptr)->elsecode = (yyvsp[-2].stmtsptr);
					}
#line 1473 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 164 "calc.y" /* yacc.c:1646  */
    {
					(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					(yyval.stmtptr)->isFor=1;
					(yyval.stmtptr)->isString=0;
					sprintf((yyval.stmtptr)->initCode,"lw $t0, %s($t8)\nlw $t1, %s($t8)\n", (yyvsp[-9].tptr)->addr,(yyvsp[-7].tptr)->addr);
					sprintf((yyval.stmtptr)->initJumpCode,"%s",(yyvsp[-8].c));
					(yyval.stmtptr)->down=(yyvsp[-2].stmtsptr); (yyval.stmtptr)->forinit=(yyvsp[-11].stmtptr); (yyval.stmtptr)->forincre=(yyvsp[-5].stmtptr); 
					}
#line 1486 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 172 "calc.y" /* yacc.c:1646  */
    {(yyval.stmtptr)=(yyvsp[0].stmtptr);}
#line 1492 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 176 "calc.y" /* yacc.c:1646  */
    {			
					(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					(yyval.stmtptr)->isWhile=0;
					(yyval.stmtptr)->isArray=1;
					(yyval.stmtptr)->isString=0;
					(yyval.stmtptr)->isArrayOne=0;
					(yyval.stmtptr)->isArrayTwo=0;

					(yyval.stmtptr)->isFunDef=0;
					(yyval.stmtptr)->isFunCall=0;
					(yyval.stmtptr)->isReturn=0;
					(yyval.stmtptr)->isInput=0;
					(yyval.stmtptr)->isOutput=0;      
					sprintf((yyval.stmtptr)->bodyCode,".data\n%s : .space %d \n.text\n",(yyvsp[-3].tptr)->name,(yyvsp[-1].val)*4);
				}
#line 1512 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 193 "calc.y" /* yacc.c:1646  */
    {
					printf("\n**********\nSyntax Error!! invalid type in '['']', allowed format : decl %s[20]\n*******\n",(yyvsp[-4].tptr)->name);
					exit(0);          }
#line 1520 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 198 "calc.y" /* yacc.c:1646  */
    {
					(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					(yyval.stmtptr)->isArray=0;
					(yyval.stmtptr)->isArrayOne=1;
					(yyval.stmtptr)->isArrayTwo=0;
					(yyval.stmtptr)->isString=0;
					(yyval.stmtptr)->isWhile=0;
					(yyval.stmtptr)->isFunDef=0;
					(yyval.stmtptr)->isFunCall=0;
					(yyval.stmtptr)->isReturn=0;
					(yyval.stmtptr)->isInput=0;
					(yyval.stmtptr)->isOutput=0;	 
					sprintf((yyval.stmtptr)->bodyCode,"%s\nmove $s1,$t0\nlw $t0,%s($t8)\nli $t3,4\nmul $t0,$t0,$t3\nsw $s1,%s($t0)\n",(yyvsp[-1].c),(yyvsp[-4].tptr)->addr,(yyvsp[-6].tptr)->name);
					}
#line 1539 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 214 "calc.y" /* yacc.c:1646  */
    {
					(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					(yyval.stmtptr)->isArray=0;
					(yyval.stmtptr)->isArrayOne=0;
					(yyval.stmtptr)->isArrayTwo=1;
					(yyval.stmtptr)->isString=0;
					(yyval.stmtptr)->isWhile=0;(yyval.stmtptr)->isArray=0;(yyval.stmtptr)->isFunDef=0;(yyval.stmtptr)->isFunCall=0;(yyval.stmtptr)->isReturn=0;(yyval.stmtptr)->isInput=0;(yyval.stmtptr)->isOutput=0;
					(yyval.stmtptr)->isString=0;
					(yyval.stmtptr)->isReturn=0;
					(yyval.stmtptr)->isInput=0;
					sprintf((yyval.stmtptr)->bodyCode,"%s\nmove $s1,$t0\nlw $t0,%d($t8)\nli $t3,4\nmul $t0,$t0,$t3\nsw $s1,%s($t0)\n",(yyvsp[-1].c),(yyvsp[-4].val)*4,(yyvsp[-6].tptr)->name);
					}
#line 1556 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 228 "calc.y" /* yacc.c:1646  */
    {					
					(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					(yyval.stmtptr)->isFunDef=0;
					(yyval.stmtptr)->isFunCall=0;
					(yyval.stmtptr)->isReturn=0;
					(yyval.stmtptr)->isInput=1;
					(yyval.stmtptr)->isArray=0;
					(yyval.stmtptr)->isArrayOne=0;
					(yyval.stmtptr)->isArrayTwo=0;
					(yyval.stmtptr)->isString=0;
					(yyval.stmtptr)->isOutput=0;
					sprintf((yyval.stmtptr)->bodyCode,"li $v0,5\nsyscall\nmove $t0,$v0\nsw $t0,%s($t8)\n",(yyvsp[-2].tptr)->addr);
					}
#line 1574 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 243 "calc.y" /* yacc.c:1646  */
    {					
					(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					(yyval.stmtptr)->isString=0;
					(yyval.stmtptr)->isFunDef=0;(yyval.stmtptr)->isOutputOne=0;(yyval.stmtptr)->isOutputTwo=0;(yyval.stmtptr)->isFunCall=0;(yyval.stmtptr)->isReturn=0;(yyval.stmtptr)->isInput=0;(yyval.stmtptr)->isOutput=1;(yyval.stmtptr)->isArray=0;(yyval.stmtptr)->isArrayOne=0;(yyval.stmtptr)->isArrayTwo=0;
					// sprintf($$->initCode,".data\nmsg: .asciiz \"\\n\"\n");
					char* tp=(yyvsp[-2].tptr)->type;
					if(strcmp("string",tp)==0){
						sprintf((yyval.stmtptr)->bodyCode,"li $v0,4\nla $a0,%s\nsyscall\n",(yyvsp[-2].tptr)->name);
					}
					else{
						sprintf((yyval.stmtptr)->bodyCode,"lw $t0,%s($t8)\nli $v0,1\nmove $a0,$t0\nsyscall\n",(yyvsp[-2].tptr)->addr);
					}				 
				}
#line 1592 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 258 "calc.y" /* yacc.c:1646  */
    {
						(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
						(yyval.stmtptr)->isString=0;
						(yyval.stmtptr)->isFunDef=0;(yyval.stmtptr)->isOutputOne=1;(yyval.stmtptr)->isOutputTwo=0;(yyval.stmtptr)->isFunCall=0;(yyval.stmtptr)->isReturn=0;(yyval.stmtptr)->isInput=0;(yyval.stmtptr)->isOutput=0;(yyval.stmtptr)->isArray=0;(yyval.stmtptr)->isArrayOne=0;(yyval.stmtptr)->isArrayTwo=0;
						// sprintf($$->initCode,".data\nmsg: .asciiz \"\\n\"\n");
						sprintf((yyval.stmtptr)->bodyCode,"li $t0,%d\nli $v0,1\nmove $a0,$t0\nsyscall\n",(yyvsp[-2].val));				 
						}
#line 1604 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 267 "calc.y" /* yacc.c:1646  */
    {					
						(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
						(yyval.stmtptr)->isString=0;(yyval.stmtptr)->isFunDef=0;(yyval.stmtptr)->isOutputOne=0;(yyval.stmtptr)->isOutputTwo=1;(yyval.stmtptr)->isFunCall=0;(yyval.stmtptr)->isReturn=0;(yyval.stmtptr)->isInput=0;(yyval.stmtptr)->isOutput=0;(yyval.stmtptr)->isArray=0;(yyval.stmtptr)->isArrayOne=0;(yyval.stmtptr)->isArrayTwo=0;
						// sprintf($$->initCode,".data\nmsg: .asciiz \"\\n\"\n");
						sprintf((yyval.stmtptr)->bodyCode,"lw $t0,%s($t8)\nmove $t2,$t0\nli $t3,4\nmul $t2,$t2,$t3\nlw $t0,%s($t2)\nli $v0,1\nmove $a0,$t0\nsyscall\n",(yyvsp[-3].tptr)->addr,(yyvsp[-5].tptr)->name);			 
						}
#line 1615 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 275 "calc.y" /* yacc.c:1646  */
    {
						(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
						(yyval.stmtptr)->isLength=1;
						sprintf((yyval.stmtptr)->stringLen,"la $s0,%s\nlb $s1,($s0)\nli $t0,0\nsrchlp_%d: beq $s1, $zero, srchdn_%d \naddi $t0,$t0,1\naddi $s0,$s0,1\nlb $s1,($s0)\nb srchlp_%d\nsrchdn_%d: sw $t0,%s($t8)\n",(yyvsp[-2].tptr)->name,lenfunc,lenfunc,lenfunc,lenfunc,(yyvsp[-6].tptr)->addr);
						lenfunc++;
						}
#line 1626 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 283 "calc.y" /* yacc.c:1646  */
    {
					// char *s=$4;					
					(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					(yyval.stmtptr)->isLength=1;
					int l=strlen((yyvsp[-2].string))-2;
					sprintf((yyval.stmtptr)->stringLen,"li $t0,%d\nsw $t0,%s($t8)\n",l,(yyvsp[-6].tptr)->addr);
					}
#line 1638 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 293 "calc.y" /* yacc.c:1646  */
    {sprintf((yyval.c),"ble $t0,$t1,");}
#line 1644 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 294 "calc.y" /* yacc.c:1646  */
    {sprintf((yyval.c),"bge $t0,$t1,");}
#line 1650 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 300 "calc.y" /* yacc.c:1646  */
    {
					(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					(yyval.stmtptr)->isWhile = 0 ; (yyval.stmtptr)->isFor=0;(yyval.stmtptr)->isString=0;
					sprintf((yyval.stmtptr)->bodyCode,"%s\nsw $t0,%s($t8)\n", (yyvsp[0].c), (yyvsp[-2].tptr)->addr);
					(yyval.stmtptr)->down=NULL; }
#line 1660 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 306 "calc.y" /* yacc.c:1646  */
    {
					(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					char* tp=(yyvsp[-2].tptr)->type;
					if(strcmp("string",tp)==0){
					(yyval.stmtptr)->isString=1;
					sprintf((yyval.stmtptr)->stringCode,".data\n%s: .asciiz %s\n.text\n",(yyvsp[-2].tptr)->name,(yyvsp[0].string));}
					}
#line 1672 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 313 "calc.y" /* yacc.c:1646  */
    { yyerrok; }
#line 1678 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 317 "calc.y" /* yacc.c:1646  */
    {
					sprintf((yyval.c),"%s\nli $t3,4\nmul $t0,$t0,$t3\nlw $t0,%s($t0)\n",(yyvsp[-1].nData),(yyvsp[-3].tptr)->name);}
#line 1685 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 320 "calc.y" /* yacc.c:1646  */
    { sprintf((yyval.c),"%s",(yyvsp[0].nData));count=(count+1)%2;}
#line 1691 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 321 "calc.y" /* yacc.c:1646  */
    { sprintf((yyval.c),"%s\n%s\nadd $t0, $t0, $t1",(yyvsp[-2].nData),(yyvsp[0].nData));}
#line 1697 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 322 "calc.y" /* yacc.c:1646  */
    { sprintf((yyval.c),"%s\n%s\nsub $t0, $t0, $t1",(yyvsp[-2].nData),(yyvsp[0].nData));}
#line 1703 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 323 "calc.y" /* yacc.c:1646  */
    { sprintf((yyval.c),"%s\n%s\nmul $t0, $t0, $t1",(yyvsp[-2].nData),(yyvsp[0].nData));}
#line 1709 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 324 "calc.y" /* yacc.c:1646  */
    { sprintf((yyval.c),"%s\n%s\ndiv $t0, $t0, $t1",(yyvsp[-2].nData),(yyvsp[0].nData));}
#line 1715 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 327 "calc.y" /* yacc.c:1646  */
    {sprintf((yyval.nData),"li $t%d, %d",count,(yyvsp[0].val));count=(count+1)%2; }
#line 1721 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 328 "calc.y" /* yacc.c:1646  */
    {sprintf((yyval.nData), "lw $t%d, %s($t8)",count,(yyvsp[0].tptr)->addr);count=(count+1)%2; }
#line 1727 "calc.tab.c" /* yacc.c:1646  */
    break;


#line 1731 "calc.tab.c" /* yacc.c:1646  */
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
#line 332 "calc.y" /* yacc.c:1906  */

// code for parse tree traversal
void StmtsTrav(stmtsptr ptr){
	if(ptr==NULL) return;
	if(ptr->singl==1){
		StmtTrav(ptr->left);
	}
	else{
		StmtTrav(ptr->left);
		StmtsTrav(ptr->right);
	}
}

void StmtTrav(stmtptr ptr){
	int ws,nj;
	 
	if(ptr==NULL) return;
	if(ptr->isString==1 && ptr->isWhile==0 
		&&ptr->isFor==0 && ptr->isIfElse==0 
		&&ptr->isBreakorContinue==0 && ptr->isFunCall==0 
		&& ptr->isFunDef==0 && ptr->isArray==0 
		&& ptr->isInput==0 && ptr->isOutput==0
		&&ptr->isOutputOne==0&&ptr->isOutputTwo==0
		&&ptr->isArrayOne==0 && ptr->isArrayTwo==0){
			fprintf(fp,"%s",ptr->stringCode);
	}
	if(ptr->isWhile==0 &&ptr->isFor==0 
		&& ptr->isIfElse==0 &&ptr->isBreakorContinue==0 
		&& ptr->isFunCall==0 && ptr->isFunDef==0 
		&& ptr->isArray==0 && ptr->isInput==0 
		&& ptr->isOutput==0&&ptr->isOutputOne==0
		&&ptr->isOutputTwo==0&&ptr->isArrayOne==0 
		&& ptr->isArrayTwo==0 ){
			fprintf(fp,"%s\n",ptr->bodyCode);
	}
	
	if(ptr->isOutputOne==0 && ptr->isOutputTwo==0 
		&& ptr->isArray==1 && ptr->isArrayOne==0 
		&& ptr->isArrayTwo==0  && ptr->isWhile==0 
		&& ptr->isReturn==0&& ptr->isFunCall==0 
		&& ptr->isFunDef==0 && ptr->isInput==0 
		&& ptr->isOutput==0) {
			fprintf(fp,"%s\n",ptr->bodyCode);
	}

	if(ptr->isArray==0&&ptr->isArrayOne==1 
		&& ptr->isArrayTwo==0  && ptr->isWhile==0 
		&& ptr->isReturn==0&& ptr->isFunCall==0 
        && ptr->isFunDef==0 && ptr->isInput==0 
        && ptr->isOutput==0) {
            printf("inside the is array");
            fprintf(fp,"%s\n",ptr->bodyCode);
    }
	
    if(ptr->isArray==0 && ptr->isArrayOne==0 
        && ptr->isArrayTwo==1 && ptr->isWhile==0 
        && ptr->isReturn==0 && ptr->isFunCall==0 
        && ptr->isFunDef==0 && ptr->isInput==0 
        && ptr->isOutput==0) {
            printf("inside the is array");
            fprintf(fp,"%s\n",ptr->bodyCode);
    }
	

    if(ptr->isLength==1 && ptr->isWhile==0 
        &&ptr->isFor==0 && ptr->isIfElse==0 
        &&ptr->isBreakorContinue==0 && ptr->isFunCall==0 
        && ptr->isFunDef==0 && ptr->isArray==0 
        && ptr->isInput==0 && ptr->isOutput==0
        &&ptr->isOutputOne==0&&ptr->isOutputTwo==0
        &&ptr->isArrayOne==0 && ptr->isArrayTwo==0){
            fprintf(fp,"%s",ptr->stringLen);
    }

    if(ptr->isFunDef==1 && ptr->isFunCall==0 
        && ptr->isReturn==0 && ptr->isArray==0 
        && ptr->isInput==0 && ptr->isOutput==0 
        && ptr->isWhile==0 &&ptr->isFor==0 
        && ptr->isIfElse==0 &&ptr->isBreakorContinue==0 
        && ptr->isFunCall==0 && ptr->isArray==0 
        && ptr->isInput==0 && ptr->isOutput==0
        &&ptr->isOutputOne==0&&ptr->isOutputTwo==0
        &&ptr->isArrayOne==0 && ptr->isArrayTwo==0){
            fprintf(fp,"%s\n",ptr->initCode);
            StmtsTrav(ptr->down);
            fprintf(fp,"lw $ra,($sp)\n addu $sp,$sp,4\n jr $ra\nm_%s:\n",ptr->FuncName);
	 }

    if(ptr->isFunCall==1 && ptr->isFunDef==0 
        && ptr->isReturn==0 && ptr->isArray==0 
        && ptr->isInput==0 && ptr->isOutput==0){
            fprintf(fp,"%s\n%s\n%s\n",ptr->initCode,ptr->insertAttr,ptr->bodyCode);
    }
	 
    if(ptr->isReturn==1&& ptr->isFunCall==0 
        && ptr->isFunDef==0 && ptr->isArray==0 
        && ptr->isInput==0 && ptr->isOutput==0){
        fprintf(fp,"%s\n",ptr->returnCode);
    }
		 
    if(ptr->isInput==1 && ptr->isFunDef==0 
        && ptr->isFunCall==0 && ptr->isReturn==0 
        && ptr->isOutput==0 && ptr->isArray==0){
            fprintf(fp,"%s\n",ptr->bodyCode);
    }
	
    if(ptr->isOutput==1 &&ptr->isOutputOne==0
        &&ptr->isOutputTwo==0&& ptr->isInput==0 
        && ptr->isFunDef==0 && ptr->isFunCall==0 
        && ptr->isReturn==0 && ptr->isArray==0){
        if(msg_flag==0){
            fprintf(fp,".data\nmsg: .asciiz \"\\n\"\n\n.text\n%s\nli $v0,4\nla $a0,msg\nsyscall\n",ptr->bodyCode);
            msg_flag=1;
        }
		else{
            fprintf(fp,"%s\nli $v0,4\nla $a0,msg\nsyscall\n",ptr->bodyCode);
        }		
    }
    if(ptr->isOutput==0 &&ptr->isOutputOne==1
        &&ptr->isOutputTwo==0&& ptr->isInput==0 
        && ptr->isFunDef==0 && ptr->isFunCall==0 
        && ptr->isReturn==0 && ptr->isArray==0){
        if(msg_flag==0){
            fprintf(fp,".data\nmsg: .asciiz \"\\n\"\n\n.text\n%s\nli $v0,4\nla $a0,msg\nsyscall\n",ptr->bodyCode);		
            msg_flag=1;
        }
        else{
            fprintf(fp,"%s\nli $v0,4\nla $a0,msg\nsyscall\n",ptr->bodyCode);
        }		
    }

    if(ptr->isOutput==0 &&ptr->isOutputOne==0
        &&ptr->isOutputTwo==1&& ptr->isInput==0 
        && ptr->isFunDef==0 && ptr->isFunCall==0 
        && ptr->isReturn==0 && ptr->isArray==0){
    		if(msg_flag==0){
			//  fprintf(fp,".data\nmsg: .asciiz \"\\n\"\n\n%s\nli $v0,4\nla $a0,msg\nsyscall\n",ptr->bodyCode);
                fprintf(fp,".data\nmsg: .asciiz \"\\n\"\n\n.text\n%s\nli $v0,4\nla $a0,msg\nsyscall\n",ptr->bodyCode);
                msg_flag=1;
            }
            else{
            fprintf(fp,"%s\nli $v0,4\nla $a0,msg\nsyscall\n",ptr->bodyCode);
        }
		
    }
	
	 
	if(ptr->isIfElse==1){ws=ifelseStart; ifelseStart++;nj=nextJumpIfElse;nextJumpIfElse++;
		fprintf(fp,"IfStart%d:%s\n%s CheckpointIfElse%d\n",ws,ptr->initCode,ptr->initJumpCode,nj);StmtsTrav(ptr->ifcode);
		fprintf(fp,"j ElseEnd%d\nCheckpointIfElse%d:\n",ws,nj);
		StmtsTrav(ptr->elsecode);
		fprintf(fp,"ElseEnd%d:\n",ws);
	}

	if(ptr->isWhile==1){ws=whileStart; whileStart++;nj=nextJump;nextJump++;inWhileloop=1;
		fprintf(fp,"WhileStart%d:%s\n%s CheckpointWhile%d\n",ws,ptr->initCode,ptr->initJumpCode,nj);StmtsTrav(ptr->down);
		fprintf(fp,"j WhileStart%d\nCheckpointWhile%d:\n",ws,nj); 
		inWhileloop=0;
	}
	
	if(ptr->isFor==1){ws=forStart; forStart++;nj=nextJumpfor;nextJumpfor++;inForloop=1;
		StmtTrav(ptr->forinit);
		fprintf(fp,"ForStart%d:%s\n%s CheckpointFor%d\n",ws,ptr->initCode,ptr->initJumpCode,nj);StmtsTrav(ptr->down);
		StmtTrav(ptr->forincre);
		fprintf(fp,"j ForStart%d\nCheckpointFor%d:\n",ws,nj);
		inForloop=0;
	}
		
	if(ptr->isBreakorContinue==1){			
		if(inForloop==1 && inWhileloop==0){
			printf("inForloop\n");
			ws = forStart;
			ws--;
			fprintf(fp,"%s\n%s CheckpointFor%d\n",ptr->initCode,ptr->initJumpCode,ws);
		}
		if(inWhileloop==1 && inForloop==0){
			printf("inWhileloop\n");
			ws = whileStart;
			ws--;
			fprintf(fp,"%s\n%s CheckpointWhile%d\n",ptr->initCode,ptr-> initJumpCode,ws);
		}
	}

}
	 


int main ()
{
	fp=fopen("errorfunc.asm","w");
	fprintf(fp,".data\nmain: .space 10000\n.text\nla $t8,main\nla $t7,main\n");
	yyparse ();
	StmtsTrav(final);
	fclose(fp);
}

void yyerror (char *s)  /* Called by yyparse on error */
{
	printf ("%s\n", s);
}
