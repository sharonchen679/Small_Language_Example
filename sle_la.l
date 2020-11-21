%{

#include "starter.h"
#include "lps.tab.h"

int line_number = 0;
void print_new_line();

%}

%x		    comment

%%

"/*"		    {ECHO; BEGIN comment;}
<comment>"*/"	{ECHO; BEGIN INITIAL;}
<comment>.  	ECHO;
<comment>\n	    {ECHO; print_new_line();}
"\n"		    print_new_line();
[ \t]+	        ECHO;

start	{ECHO; return START;}
do	    {ECHO; return DO;}
else	{ECHO; return ELSE;}
if	    {ECHO; return IF;}
endi	{ECHO; return ENDI;}
int	    {ECHO; return INT;}
put	    {ECHO; return PUT;}
prog	{ECHO; return PROG;}
get	    {ECHO; return GET;}
real	{ECHO; return REAL;}
then	{ECHO; return THEN;}
var	    {ECHO; return VAR;}
loop	{ECHO; return LOOP;}
endl	{ECHO; return ENDL;}
until	{ECHO; return UNTIL;}
endp	{ECHO; return ENDP;}

"."		{ECHO; return DOT;}
";"		{ECHO; return SEMICOLON;}
":"		{ECHO; return COLON;}
","		{ECHO; return COMMA;}
")"		{ECHO; return RPAR;}
"("		{ECHO; return LPAR;}

[<>=]|<>		{ECHO; return RELOP;}
[&~!]			{ECHO; return LOGOP;}
[+-]			{ECHO; return ADDOP;}
[*/]|mod		{ECHO; return MULOP;}
"<""="				{ECHO; return ASSIGNOP;}

[a-zA-Z]([a-zA-Z]|[0-9])*		{ECHO; return ID;}
[0-9]+|[0-9]*"."[0-9]+			{ECHO; return NUM;}

%%

//error							{char s[30]; sprintf(s,"symbol %s" could not be resolved", yytext); yyerror(s);}

void print_new_line() {fprintf(yyout,"\n%d\t",++line_number);}

int yywrap() {return 1;}