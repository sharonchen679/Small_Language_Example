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
#line 1 "lps.y" /* yacc.c:339  */


#include "starter.h"

/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*////////////////////////////////////// USEFUL FUNCTIONS //////////////////////////////////////*/
void yyerror(char *message);
void error_and_exit(char *message);

void put(variable var);					// simple print
void get(char* var);					// instead of scanf, var is initialize with a const value (1 or 1.0)
char * create_id();						// allocating memory
variable create_num();					// define variable with no name
char* create_op(char* op);				// define operator as text

// calculations:
variable mul(variable v1, variable v2);
variable div_(variable v1, variable v2); // name "div" is already taken by system (therefore "_" was added to the function's name)
variable mod(variable v1, variable v2);
variable add(variable v1, variable v2);
variable sub(variable v1, variable v2);
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////// SYMBOL TABLE ////////////////////////////////////////*/
typedef struct node {
  variable var;
  struct node *next;
} node;

node* head = NULL;

variable get_var(char *id);						// get an existing var from symbol table
void add_var(char *id, Type type, void *val);	// basically private function, get called only by add_int() or add_double()
void add_int(char *name, int val);
void add_double(char *name, double val);
void assign(char *id, variable var);			// update value in symbole table
void print_symbol_table();						// just for check
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/

#line 106 "lps.tab.c" /* yacc.c:339  */

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
   by #include "lps.tab.h".  */
#ifndef YY_YY_LPS_TAB_H_INCLUDED
# define YY_YY_LPS_TAB_H_INCLUDED
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
    DOT = 258,
    START = 259,
    DO = 260,
    ELSE = 261,
    IF = 262,
    ENDI = 263,
    INT = 264,
    PUT = 265,
    PROG = 266,
    GET = 267,
    REAL = 268,
    THEN = 269,
    VAR = 270,
    LOOP = 271,
    ENDL = 272,
    UNTIL = 273,
    ENDP = 274,
    SEMICOLON = 275,
    COLON = 276,
    COMMA = 277,
    RPAR = 278,
    LPAR = 279,
    ID = 280,
    ASSIGNOP = 281,
    RELOP = 282,
    LOGOP = 283,
    ADDOP = 284,
    MULOP = 285,
    NUM = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 41 "lps.y" /* yacc.c:355  */

  variable var;
  int bool;
  Type type;
  char* text;

#line 185 "lps.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LPS_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 202 "lps.tab.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   245

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  91

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    79,    79,    80,    81,    83,    84,    85,    86,    87,
      89,    90,    91,    93,    97,    98,   102,   103,   104,   106,
     107,   108,   110,   111,   112,   114,   115,   116,   117,   118,
     119,   120,   121,   123,   124,   125,   127,   128,   129,   130,
     132,   133,   134,   135,   136,   137,   141,   151,   152,   153,
     155,   156,   157,   160,   162,   164,   166,   171,   172,   174,
     175,   176,   177,   178,   180,   181,   182,   183,   184
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DOT", "START", "DO", "ELSE", "IF",
  "ENDI", "INT", "PUT", "PROG", "GET", "REAL", "THEN", "VAR", "LOOP",
  "ENDL", "UNTIL", "ENDP", "SEMICOLON", "COLON", "COMMA", "RPAR", "LPAR",
  "ID", "ASSIGNOP", "RELOP", "LOGOP", "ADDOP", "MULOP", "NUM", "$accept",
  "Program", "Declarations", "DeclList", "Type", "StmtList", "Statement",
  "BoolExp", "Case", "Expression", "Term", "Factor", "ID_wrap",
  "RELOP_wrap", "LOGOP_wrap", "ADDOP_wrap", "MULOP_wrap", YY_NULLPTR
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
     285,   286
};
# endif

#define YYPACT_NINF -28

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-28)))

#define YYTABLE_NINF -53

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,   -28,   -21,     8,   -28,   -11,   -28,    57,   -28,    85,
      11,   -28,    81,     2,    92,   -28,    97,   -28,   161,   -28,
     180,   -28,    -9,   -28,   -28,   -28,   -28,   120,     5,    23,
     104,    15,   165,     1,    25,     4,   196,   -28,    31,   -28,
      17,    51,    -8,   -28,   -28,   -28,    21,   -28,   -28,    58,
     -28,   -28,   -28,   -28,    40,   -28,    18,   -28,    59,   108,
      44,   -28,   -28,   -28,    52,   -28,   -28,    60,   -28,    65,
     134,   -28,    21,    50,   -28,   -28,   170,   -28,    21,   -28,
      -8,   -28,   -28,   206,   -28,   148,   -28,   -28,    53,   220,
     -28
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,     8,     0,    64,     7,     1,     0,    12,     0,
       5,    18,    11,     0,     0,    10,     0,    17,     0,    24,
       4,    14,     0,    21,    19,    20,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,    49,     0,    60,
      36,     0,    55,    58,    59,    29,    28,    31,    30,    40,
       3,     2,    22,    27,     0,    13,     0,    63,     0,     0,
      48,    65,    66,    67,     0,    50,    51,     0,    68,     0,
       0,    26,    25,    43,    62,    61,    35,    47,    46,    54,
      53,    57,    56,    39,    42,     0,    34,    38,    24,     0,
      32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -28,   -28,   -28,   -28,    71,   -26,   -28,    39,   -28,   -27,
      27,    38,    -2,   -28,   -28,   -28,   -28
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,    10,    12,    26,    20,    33,    40,    64,    41,
      42,    43,    44,    65,    66,    67,    69
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       5,    36,    46,    17,     4,    23,    37,    13,     6,     7,
       1,    58,    35,    24,    22,    14,    37,    25,    34,    37,
       2,    52,    68,    18,    45,   -37,    53,    72,    48,    38,
       4,    59,    57,    76,    34,   -41,    39,    78,   -44,    38,
       4,    71,    38,     4,    83,   -52,    39,    38,     4,    39,
      63,    54,    60,    77,    39,    38,     4,    -6,     8,    89,
      74,    79,    39,    70,    38,     4,    81,    84,   -52,   -52,
      49,    39,     9,   -33,    34,   -52,    38,     4,    61,    62,
      63,    34,    75,    39,    38,     4,    11,    34,    63,    38,
       4,    39,   -23,    19,    80,    73,    39,   -23,    21,   -23,
       0,    15,   -23,    16,   -23,    47,    55,    82,   -23,    19,
       4,   -23,     0,   -23,   -23,   -23,   -23,   -23,   -23,     0,
     -23,    19,     4,     0,   -23,   -23,     0,   -23,   -23,     4,
     -23,     0,   -23,   -23,     0,    19,   -23,     0,   -23,   -23,
     -23,   -23,     0,     0,   -23,   -23,   -23,     0,     0,    88,
     -23,   -23,     0,   -23,   -23,   -23,   -23,     0,   -23,   -23,
     -23,   -16,    23,     0,   -23,   -16,    50,     0,    51,     0,
      24,     0,     0,   -23,    25,    27,    85,    28,    86,     0,
      29,   -16,    30,   -16,     0,    27,    31,    28,     0,     0,
      29,     0,    30,     0,     0,     4,    31,     0,     0,    32,
       0,    27,     0,    28,     0,     4,    29,     0,    30,     0,
       0,    27,    31,    28,    56,     0,    29,     0,    30,     0,
       0,     4,    31,    87,     0,    27,     0,    28,    90,     0,
      29,     4,    30,     0,     0,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     4
};

static const yytype_int8 yycheck[] =
{
       2,    27,    29,     1,    25,     1,     1,     9,     0,    20,
       1,    38,    21,     9,    16,     4,     1,    13,    20,     1,
      11,    20,    30,    21,     1,    20,     1,    54,    30,    24,
      25,    14,     1,    59,    36,    20,    31,    64,    20,    24,
      25,     1,    24,    25,    70,     1,    31,    24,    25,    31,
      29,    26,     1,     1,    31,    24,    25,     0,     1,    85,
       1,     1,    31,     5,    24,    25,     1,    17,    24,    25,
      31,    31,    15,    20,    76,    31,    24,    25,    27,    28,
      29,    83,    23,    31,    24,    25,     1,    89,    29,    24,
      25,    31,     0,     1,    67,    56,    31,     5,     1,     7,
      -1,    20,    10,    22,    12,     1,    35,    69,    16,     1,
      25,    19,    -1,     5,     6,     7,     8,    25,    10,    -1,
      12,     1,    25,    -1,    16,     5,    -1,     7,    20,    25,
      10,    -1,    12,    25,    -1,     1,    16,    -1,    18,     5,
      20,     7,    -1,    -1,    10,    25,    12,    -1,    -1,     1,
      16,    17,    -1,     5,    20,     7,     8,    -1,    10,    25,
      12,     0,     1,    -1,    16,     4,     1,    -1,     3,    -1,
       9,    -1,    -1,    25,    13,     5,     6,     7,     8,    -1,
      10,    20,    12,    22,    -1,     5,    16,     7,    -1,    -1,
      10,    -1,    12,    -1,    -1,    25,    16,    -1,    -1,    19,
      -1,     5,    -1,     7,    -1,    25,    10,    -1,    12,    -1,
      -1,     5,    16,     7,    18,    -1,    10,    -1,    12,    -1,
      -1,    25,    16,    17,    -1,     5,    -1,     7,     8,    -1,
      10,    25,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    11,    33,    25,    44,     0,    20,     1,    15,
      34,     1,    35,    44,     4,    20,    22,     1,    21,     1,
      37,     1,    44,     1,     9,    13,    36,     5,     7,    10,
      12,    16,    19,    38,    44,    21,    37,     1,    24,    31,
      39,    41,    42,    43,    44,     1,    41,     1,    44,    39,
       1,     3,    20,     1,    26,    36,    18,     1,    41,    14,
       1,    27,    28,    29,    40,    45,    46,    47,    30,    48,
       5,     1,    41,    39,     1,    23,    37,     1,    41,     1,
      42,     1,    43,    37,    17,     6,     8,    17,     1,    37,
       8
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    33,    33,    33,    33,    33,    33,    33,
      34,    34,    34,    35,    35,    35,    35,    35,    35,    36,
      36,    36,    37,    37,    37,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    39,    39,    39,    39,
      40,    40,    40,    41,    41,    41,    42,    42,    42,    43,
      43,    43,    43,    43,    44,    45,    46,    47,    48
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     8,     6,     4,     3,     2,     1,     1,
       3,     2,     1,     5,     3,     3,     2,     2,     1,     1,
       1,     1,     3,     0,     1,     3,     3,     2,     2,     2,
       2,     2,     7,     6,     5,     4,     2,     1,     5,     4,
       2,     1,     5,     4,     3,     2,     3,     3,     2,     1,
       1,     1,     1,     3,     3,     1,     3,     3,     1,     1,
       1,     3,     3,     2,     1,     1,     1,     1,     1
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
#line 79 "lps.y" /* yacc.c:1646  */
    {fprintf(stdout, "success\n"); exit(0);}
#line 1373 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 80 "lps.y" /* yacc.c:1646  */
    {yyerror("missing token .");}
#line 1379 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 81 "lps.y" /* yacc.c:1646  */
    {yyerror("expected token endp after StmtList");}
#line 1385 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 83 "lps.y" /* yacc.c:1646  */
    {yyerror("expected token start after Declarations");}
#line 1391 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 84 "lps.y" /* yacc.c:1646  */
    {yyerror("expected Declarations after token ;");}
#line 1397 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 85 "lps.y" /* yacc.c:1646  */
    {yyerror("missing token ;");}
#line 1403 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 86 "lps.y" /* yacc.c:1646  */
    {yyerror("expected id after token prog");}
#line 1409 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 87 "lps.y" /* yacc.c:1646  */
    {yyerror("failed: Program -> PROG ID SEMICOLON Declarations START StmtList ENDP DOT");}
#line 1415 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 89 "lps.y" /* yacc.c:1646  */
    {/*nothing to do*/}
#line 1421 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 90 "lps.y" /* yacc.c:1646  */
    {yyerror("missing token ;");}
#line 1427 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 91 "lps.y" /* yacc.c:1646  */
    {yyerror("failed: Declarations -> VAR DeclList SEMICOLON");}
#line 1433 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 93 "lps.y" /* yacc.c:1646  */
    {   /* ok : by definition */
                    if((yyvsp[0].type) == INTEGER) add_int((yyvsp[-2].text), 0);
                    else              add_double((yyvsp[-2].text),0.0);
                    }
#line 1442 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 97 "lps.y" /* yacc.c:1646  */
    {yyerror("expected another id after token ,");}
#line 1448 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 98 "lps.y" /* yacc.c:1646  */
    {   /* ok : by definition */
                    if((yyvsp[0].type) == INTEGER) add_int((yyvsp[-2].text), 0);
                    else              add_double((yyvsp[-2].text),0.0);
                    }
#line 1457 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 102 "lps.y" /* yacc.c:1646  */
    {yyerror("expected Type after token :");}
#line 1463 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 103 "lps.y" /* yacc.c:1646  */
    {yyerror("expected token : after id");}
#line 1469 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 104 "lps.y" /* yacc.c:1646  */
    {yyerror("failed: DeclList -> DeclList COMMA ID COLON Type | ID COLON Type");}
#line 1475 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 106 "lps.y" /* yacc.c:1646  */
    {(yyval.type) = INTEGER;}
#line 1481 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 107 "lps.y" /* yacc.c:1646  */
    {(yyval.type) = DOUBLE;}
#line 1487 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 108 "lps.y" /* yacc.c:1646  */
    {yyerror("failed: Type -> INT | REAL");}
#line 1493 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 110 "lps.y" /* yacc.c:1646  */
    {/*nothing to do*/}
#line 1499 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 111 "lps.y" /* yacc.c:1646  */
    {/*nothing to do*/}
#line 1505 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 112 "lps.y" /* yacc.c:1646  */
    {yyerror("failed: StmtList -> StmtList Statement SEMICOLON |  ");}
#line 1511 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 114 "lps.y" /* yacc.c:1646  */
    {assign((yyvsp[-2].text),(yyvsp[0].var));}
#line 1517 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 115 "lps.y" /* yacc.c:1646  */
    {yyerror("expected Expression after token <=");}
#line 1523 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 116 "lps.y" /* yacc.c:1646  */
    {yyerror("token id has no effect");}
#line 1529 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 117 "lps.y" /* yacc.c:1646  */
    {put((yyvsp[0].var));}
#line 1535 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 118 "lps.y" /* yacc.c:1646  */
    {yyerror("expected Expression after token put");}
#line 1541 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 119 "lps.y" /* yacc.c:1646  */
    {get((yyvsp[0].text));}
#line 1547 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 120 "lps.y" /* yacc.c:1646  */
    {yyerror("missing token id");}
#line 1553 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 121 "lps.y" /* yacc.c:1646  */
    {/*nothing to do - IF*/}
#line 1559 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 123 "lps.y" /* yacc.c:1646  */
    {yyerror("expected StmtList after token else");}
#line 1565 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 124 "lps.y" /* yacc.c:1646  */
    {/*nothing to do - IF*/}
#line 1571 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 125 "lps.y" /* yacc.c:1646  */
    {yyerror("missing token endi");}
#line 1577 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 127 "lps.y" /* yacc.c:1646  */
    {yyerror("missing token then");}
#line 1583 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 128 "lps.y" /* yacc.c:1646  */
    {yyerror("expected BoolExp after token if");}
#line 1589 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 129 "lps.y" /* yacc.c:1646  */
    {/*nothing to do - LOOP*/}
#line 1595 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 130 "lps.y" /* yacc.c:1646  */
    {yyerror("missing token endl");}
#line 1601 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 132 "lps.y" /* yacc.c:1646  */
    {yyerror("expected token do after BoolExp");}
#line 1607 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 133 "lps.y" /* yacc.c:1646  */
    {yyerror("expected BoolExp after token loop");}
#line 1613 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 134 "lps.y" /* yacc.c:1646  */
    {/*nothing to do - DO*/}
#line 1619 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 135 "lps.y" /* yacc.c:1646  */
    {yyerror("missing token endl");}
#line 1625 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 136 "lps.y" /* yacc.c:1646  */
    {yyerror("expected BoolExp after token until");}
#line 1631 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 137 "lps.y" /* yacc.c:1646  */
    {yyerror("expected token until");}
#line 1637 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 141 "lps.y" /* yacc.c:1646  */
    { /* ok : by definition */
                    (yyval.bool) =
                    strcmp((yyvsp[-1].text),"<")  == 0 ? (yyvsp[-2].var).val <  (yyvsp[0].var).val :
                    strcmp((yyvsp[-1].text),">")  == 0 ? (yyvsp[-2].var).val >  (yyvsp[0].var).val :
                    strcmp((yyvsp[-1].text),"=")  == 0 ? (yyvsp[-2].var).val == (yyvsp[0].var).val :
                    strcmp((yyvsp[-1].text),"<>") == 0 ? (yyvsp[-2].var).val != (yyvsp[0].var).val :
                    strcmp((yyvsp[-1].text),"&")  == 0 ? (yyvsp[-2].var).val && (yyvsp[0].var).val :
                    strcmp((yyvsp[-1].text),"~")  == 0 ? (yyvsp[-2].var).val || (yyvsp[0].var).val :
                    !((yyvsp[-2].var).val && (yyvsp[0].var).val); // no such thing "Expression NOT Expression"  (should be unary "NOT Expression") ??
                    }
#line 1652 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 151 "lps.y" /* yacc.c:1646  */
    {yyerror(strcat("expected Expression after token ",(yyvsp[-1].text)));}
#line 1658 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 152 "lps.y" /* yacc.c:1646  */
    {yyerror("expected Case after Expression");}
#line 1664 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 153 "lps.y" /* yacc.c:1646  */
    {yyerror("failed: BoolExp -> Expression Case Expression");}
#line 1670 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 155 "lps.y" /* yacc.c:1646  */
    {(yyval.text) = (yyvsp[0].text);}
#line 1676 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 156 "lps.y" /* yacc.c:1646  */
    {(yyval.text) = (yyvsp[0].text);}
#line 1682 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 157 "lps.y" /* yacc.c:1646  */
    {yyerror("failed: Case -> RELOP | LOGOP");}
#line 1688 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 160 "lps.y" /* yacc.c:1646  */
    {  /* ok : by definition */
                    (yyval.var) = strcmp((yyvsp[-1].text),"+") == 0 ? add((yyvsp[-2].var),(yyvsp[0].var)) : sub((yyvsp[-2].var),(yyvsp[0].var));}
#line 1695 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 162 "lps.y" /* yacc.c:1646  */
    {yyerror(strcat("expected Term after token ",(yyvsp[-1].text)));}
#line 1701 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 164 "lps.y" /* yacc.c:1646  */
    {(yyval.var) = (yyvsp[0].var);}
#line 1707 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 166 "lps.y" /* yacc.c:1646  */
    { /* ok : by definition */
                    (yyval.var) =
                    strcmp((yyvsp[-1].text),"*")   == 0 ? mul((yyvsp[-2].var),(yyvsp[0].var))  :
                    strcmp((yyvsp[-1].text),"/")   == 0 ? div_((yyvsp[-2].var),(yyvsp[0].var)) : mod((yyvsp[-2].var),(yyvsp[0].var));
                    }
#line 1717 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 171 "lps.y" /* yacc.c:1646  */
    {yyerror(strcat("expected Factor after token ",(yyvsp[-1].text)));}
#line 1723 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 172 "lps.y" /* yacc.c:1646  */
    {(yyval.var) = (yyvsp[0].var);}
#line 1729 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 174 "lps.y" /* yacc.c:1646  */
    {(yyval.var) = get_var((yyvsp[0].text));}
#line 1735 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 175 "lps.y" /* yacc.c:1646  */
    {(yyval.var) = create_num();}
#line 1741 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 176 "lps.y" /* yacc.c:1646  */
    {(yyval.var) = (yyvsp[-1].var);}
#line 1747 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 177 "lps.y" /* yacc.c:1646  */
    {yyerror("missing ) after Expression");}
#line 1753 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 178 "lps.y" /* yacc.c:1646  */
    {yyerror("expected Expression after (");}
#line 1759 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 180 "lps.y" /* yacc.c:1646  */
    {(yyval.text) = create_id();}
#line 1765 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 181 "lps.y" /* yacc.c:1646  */
    {(yyval.text) = create_op(yytext);}
#line 1771 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 182 "lps.y" /* yacc.c:1646  */
    {(yyval.text) = create_op(yytext);}
#line 1777 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 183 "lps.y" /* yacc.c:1646  */
    {(yyval.text) = create_op(yytext);}
#line 1783 "lps.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 184 "lps.y" /* yacc.c:1646  */
    {(yyval.text) = create_op(yytext);}
#line 1789 "lps.tab.c" /* yacc.c:1646  */
    break;


#line 1793 "lps.tab.c" /* yacc.c:1646  */
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
#line 186 "lps.y" /* yacc.c:1906  */

/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////// MAIN ////////////////////////////////////////////*/
int main(int argc, char** argv) {
    if(argc != 2)
        error_and_exit("no input file");
    char file_type[5];
    strcpy(file_type, argv[1]+strlen(argv[1])-4);
    if( !strcmp(file_type, ".sle") && !strcmp(file_type, ".SLE") )
       error_and_exit("invalid file format");
    yyin = fopen(argv[1],"r");
    if(yyin==NULL) error_and_exit("cannot open input file");

    char output_file_name[strlen(argv[1])+1];
    strcpy(output_file_name, argv[1]);
    strcpy(output_file_name+strlen(argv[1])-4, ".1st");
    yyout = fopen(output_file_name,"w");
    if(yyout==NULL) error_and_exit("cannot open output file .1st");
    fprintf(yyout,"%d\t",++line_number); // print first line
	yyparse();
    return 0;
}
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*////////////////////////////////////// USEFUL FUNCTIONS //////////////////////////////////////*/
void yyerror(char *message) {
    fprintf(yyout, "\nERROR: in line %d: %s\n",line_number, message);
    fprintf(stderr, "\nERROR: in line %d: %s\n",line_number, message);
}
void error_and_exit(char *message) {fprintf(stderr, "\nERROR: in line %d: %s\n",line_number, message); exit(1);}

void put(variable var) {
    if(var.type == INTEGER) printf("%d\n", *(int*)var.val);
    else                    printf("%f\n", *(double*)var.val);
}
void get(char* var) {
    variable rhs;
    strcpy(rhs.id,var);
    if(get_var(var).type == INTEGER) {
        rhs.type = INTEGER;
        rhs.val = (int*)malloc(sizeof(int));
        *((int*)rhs.val) = 1;
    }
    else {
        rhs.type = DOUBLE;
        rhs.val = (double*)malloc(sizeof(double));
        *((double*)rhs.val) = 1.0;
    }
    assign(var,rhs);
}


char * create_id() {
  char* id = malloc(sizeof(char) * 20);
  strcpy(id, yytext);
  return id;
}

variable create_num() {
  variable num;
  if(strstr(yytext, ".") != NULL) {
    num.type = DOUBLE;
    num.val  = (double*)malloc(sizeof(double));
    (*(double*)num.val) = atof(yytext);
  }
  else {
    num.type = INTEGER;
    num.val = (int*)malloc(sizeof(int));
    (*(int*)num.val) = atoi(yytext);
  }
  return num;
}

char* create_op(char * op) {
  char* text = malloc(sizeof(char) * strlen(op));
  strcpy(text, op);
  return text;
}

variable mul(variable v1, variable v2) {
  variable res;
  if(v1.type == DOUBLE || v2.type == DOUBLE) {
    res.type = DOUBLE;
    res.val = (double*)malloc(sizeof(double));
    *((double*)res.val) =
        v1.type == v2.type?     (*((double*)v1.val)) * (*((double*)v2.val)) :
        v1.type == DOUBLE?      (*((double*)v1.val)) * (*((int*)v2.val))    :
                                (*((int*)v1.val)) * (*((double*)v2.val));
  }
  else {
    res.type = INTEGER;
    res.val = (int*)malloc(sizeof(int));
    *((int*)res.val) = (*((int*)v1.val)) * (*((int*)v2.val));
  }
  return res;
}


variable div_(variable v1, variable v2) { // name "div" is already taken by system (so "_" is added to the function's name)
  if(v2.val == 0) error_and_exit("cannot divide by zero");
  variable res;
  if(v1.type == DOUBLE || v2.type == DOUBLE) {
    res.type = DOUBLE;
    res.val = (double*)malloc(sizeof(double));
    *((double*)res.val) =
      v1.type == v2.type?     (*((double*)v1.val)) / (*((double*)v2.val)) :
      v1.type == DOUBLE?      (*((double*)v1.val)) / (*((int*)v2.val))    :
                              (*((int*)v1.val)) / (*((double*)v2.val));
  }
  else {
    res.type = INTEGER;
    res.val = (int*)malloc(sizeof(int));
    *((int*)res.val) = (*((int*)v1.val)) / (*((int*)v2.val));
  }
  return res;
}


variable mod(variable v1, variable v2) {
  if (v1.type == DOUBLE || v2.type == DOUBLE)
    error_and_exit("cannot mod variable of type double");
  variable res;
  res.type = INTEGER;
  res.val = (int*)malloc(sizeof(int));
  *((int*)res.val) = (*((int*)v1.val)) % (*((int*)v2.val));
  return res;
}

variable add(variable v1, variable v2) {
  variable res;
  if(v1.type == DOUBLE || v2.type == DOUBLE) {
    res.type = DOUBLE;
    res.val = (double*)malloc(sizeof(double));
    *((double*)res.val) =
      v1.type == v2.type?     (*((double*)v1.val)) + (*((double*)v2.val)) :
      v1.type == DOUBLE ?     (*((double*)v1.val)) + (*((int*)v2.val))    :
                              (*((int*)v1.val)) + (*((double*)v2.val));
  }
  else {
    res.type = INTEGER;
    res.val = (int*)malloc(sizeof(int));
    *((int*)res.val) = (*((int*)v1.val)) + (*((int*)v2.val));
  }
  return res;
}

variable sub(variable v1, variable v2) {
  variable res;
  if(v1.type == DOUBLE || v2.type == DOUBLE) {
    res.type = DOUBLE;
    res.val = (double*)malloc(sizeof(double));
    *((double*)res.val) =
      v1.type == v2.type?     (*((double*)v1.val)) - (*((double*)v2.val)) :
      v1.type == DOUBLE ?     (*((double*)v1.val)) - (*((int*)v2.val))    :
                              (*((int*)v1.val)) - (*((double*)v2.val));
  }
  else {
    res.type = INTEGER;
    res.val = (int*)malloc(sizeof(int));
    *((int*)res.val) = (*((int*)v1.val)) - (*((int*)v2.val));
  }
  return res;
}
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////// SYMBOL TABLE ////////////////////////////////////////*/


variable get_var(char *id) {
  node* tmp = head;
  while(tmp) {
    if (strcmp(tmp->var.id, id) == 0) return tmp->var;
    tmp = tmp->next;
  }
  error_and_exit(strcat(id, " doesn't exist on symbol table"));
}

void add_var(char *id, Type type, void *val) {
  if (head == NULL) {
    head = (node*)malloc(sizeof(node));
    strcpy(head->var.id, id);
    head->var.val = val;
    head->var.type = type;
    head->next = NULL;
    return;
  }
  node* newNode = (node*)malloc(sizeof(node));
  strcpy(newNode->var.id, id);
  newNode->var.val = val;
  newNode->var.type = type;
  newNode->next = head->next;
  head->next = newNode;
}

void add_int(char *id, int val) {
  void *var_val = (int*)malloc(sizeof(int));
  add_var(id, INTEGER, var_val);
}

void add_double(char *id, double val) {
  void *var_val = (double*)malloc(sizeof(double));
  add_var(id, DOUBLE, var_val);
}

void assign(char *id, variable var) {
  node *tmp = head;
  while(tmp) {
    if (strcmp(tmp->var.id, id) == 0) {
      if (tmp->var.type != var.type)
        error_and_exit("cannot assign different types of variables");
      tmp->var.val = var.val;
      return;
    }
    tmp = tmp->next;
  }
  error_and_exit(strcat(id, " doesn't exist on symbol table"));
}

void print_symbol_table() {
  printf("Symbol Table:\n");
  printf("-------------\n");
  node* tmp = head;
  while(tmp) {
    if (tmp->var.type == INTEGER) printf("%s = %d\n", tmp->var.id, *((int*)tmp->var.val));
    else printf("%s = %f\n", tmp->var.id, *((double*)tmp->var.val));
    tmp = tmp->next;
  }
}
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
