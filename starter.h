#ifndef _STARTER_
#define _STARTER_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef enum { INTEGER, DOUBLE } Type;

typedef struct variable {
  char id[20];
  Type type;
  void *val;
} variable;

extern FILE* yyin;
extern FILE* yyout;
extern int line_number;

int yylex();
char *yytext;

#endif