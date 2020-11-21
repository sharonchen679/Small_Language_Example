%{

#include "starter.h"

/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*////////////////////////////////////// USEFUL FUNCTIONS //////////////////////////////////////*/
void yyerror(char *message);
void error_and_exit(char *message);

void put(variable var);					// simple print
void get(char* var);					// instead of scanf, var is initialize with a const value (1 or 1.0)
char * create_id();					// allocating memory
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

variable get_var(char *id);			// get an existing var from symbol table
void add_var(char *id, Type type, void *val);	// basically private function, get called only by add_int() or add_double()
void add_int(char *name, int val);
void add_double(char *name, double val);
void assign(char *id, variable var);		// update value in symbole table
void print_symbol_table();			// just for check
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
%}

%union {
  variable var;
  int bool;
  Type type;
  char* text;
}

%token DOT
%token START DO ELSE IF ENDI INT PUT PROG GET REAL THEN VAR LOOP ENDL UNTIL ENDP
%token SEMICOLON COLON COMMA RPAR LPAR ID ASSIGNOP

%token <text> RELOP LOGOP ADDOP MULOP
%token <var> NUM


%type <var> Factor
%type <var> Expression
%type <bool> BoolExp
%type <var> Term
%type <var> Statement
%type <text> Case
%type <type> Type
%type <type> DeclList

%type <text> RELOP_wrap
%type <text> LOGOP_wrap
%type <text> ADDOP_wrap
%type <text> MULOP_wrap
%type <text> ID_wrap

%left ADDOP
%left MULOP
%right ASSIGNOP

%start Program

%%

Program:		PROG ID_wrap SEMICOLON Declarations START StmtList ENDP DOT		{fprintf(stdout, "success\n"); exit(0);}
			|	PROG ID_wrap SEMICOLON Declarations START StmtList ENDP error	{yyerror("missing token .");}
			|	PROG ID_wrap SEMICOLON Declarations START StmtList	{yyerror("expected token endp after StmtList");}
/*			|	PROG ID_wrap SEMICOLON Declarations START error		{yyerror("expected StmtList after token start");}*/ //makes a reduce/reduce conflict
			|	PROG ID_wrap SEMICOLON Declarations			{yyerror("expected token start after Declarations");}
			|	PROG ID_wrap SEMICOLON					{yyerror("expected Declarations after token ;");}
			|	PROG ID_wrap						{yyerror("missing token ;");}
			|	PROG							{yyerror("expected id after token prog");}
			|	error							{yyerror("failed: Program -> PROG ID SEMICOLON Declarations START StmtList ENDP DOT");}
			;
Declarations:	VAR DeclList SEMICOLON							{/*nothing to do*/}  /* ok : by definition */
			|	VAR DeclList						{yyerror("missing token ;");}
			|	error							{yyerror("failed: Declarations -> VAR DeclList SEMICOLON");}
			;
DeclList:		DeclList COMMA ID_wrap COLON Type				{   /* ok : by definition */
                    if($5 == INTEGER) add_int($3, 0);
                    else              add_double($3,0.0);
                    }
			|	DeclList COMMA error					{yyerror("expected another id after token ,");}
			|	ID_wrap COLON Type					{   /* ok : by definition */
                    if($3 == INTEGER) add_int($1, 0);
                    else              add_double($1,0.0);
                    }
			|	ID_wrap COLON						{yyerror("expected Type after token :");}
			|	ID_wrap error						{yyerror("expected token : after id");}
			|	error							{yyerror("failed: DeclList -> DeclList COMMA ID COLON Type | ID COLON Type");}
			;
Type:			INT													{$$ = INTEGER;}  /* ok : by definition */
			|	REAL							{$$ = DOUBLE;}  /* ok : by definition */
			|	error							{yyerror("failed: Type -> INT | REAL");}
			;
StmtList:		StmtList Statement SEMICOLON					{/*nothing to do*/}  /* ok : by definition */
			|								{/*nothing to do*/}  /* ok : by definition */
			|	error							{yyerror("failed: StmtList -> StmtList Statement SEMICOLON |  ");}
			;
Statement:		ID_wrap ASSIGNOP Expression					{assign($1,$3);}  /* ok : by definition */
			|	ID_wrap ASSIGNOP error					{yyerror("expected Expression after token <=");}
			|	ID_wrap error						{yyerror("token id has no effect");}
			|	PUT Expression						{put($2);}  /* ok : by definition */
			|	PUT error						{yyerror("expected Expression after token put");}
			|	GET ID_wrap						{get($2);} /* ok : by definition */
			|	GET error											{yyerror("missing token id");}
			|	IF BoolExp THEN StmtList ELSE StmtList ENDI		{/*nothing to do - IF*/}  /* ok : by definition */
/*			|	IF BoolExp THEN StmtList ELSE StmtList			{yyerror("missing token endi");}*/ //makes shift/reduce conflict
			|	IF BoolExp THEN StmtList ELSE error			{yyerror("expected StmtList after token else");}
			|	IF BoolExp THEN StmtList ENDI				{/*nothing to do - IF*/}  /* ok : by definition */
			|	IF BoolExp THEN StmtList				{yyerror("missing token endi");}
/*			|	IF BoolExp THEN error					{yyerror("expected StmtList after token then");} */ //makes reduce/reduce conflict
			|	IF BoolExp						{yyerror("missing token then");}
			|	IF							{yyerror("expected BoolExp after token if");}
			|	LOOP BoolExp DO StmtList ENDL				{/*nothing to do - LOOP*/}  /* ok : by definition */
			|	LOOP BoolExp DO StmtLis					{yyerror("missing token endl");}
/*			|	LOOP BoolExp DO error					{yyerror("expected StmtList after token do");} */ //makes reduce/reduce conflict
			|	LOOP BoolExp						{yyerror("expected token do after BoolExp");}
			|	LOOP							{yyerror("expected BoolExp after token loop");}
			|	DO StmtList UNTIL BoolExp ENDL				{/*nothing to do - DO*/}  /* ok : by definition */
			|	DO StmtList UNTIL BoolExp				{yyerror("missing token endl");}
			|	DO StmtList UNTIL					{yyerror("expected BoolExp after token until");}
			|	DO StmtList						{yyerror("expected token until");}
/*			|	DO error						{yyerror("expected StmtList after token do");} */ //makes reduce/reduce conflict
/*			|	error							{yyerror("failed: Statement -> ");}*/ // makes a reduce/reduce conflict
			;
BoolExp:		Expression Case Expression					{ /* ok : by definition */
                    $$ =
                    strcmp($2,"<")  == 0 ? $1.val <  $3.val :
                    strcmp($2,">")  == 0 ? $1.val >  $3.val :
                    strcmp($2,"=")  == 0 ? $1.val == $3.val :
                    strcmp($2,"<>") == 0 ? $1.val != $3.val :
                    strcmp($2,"&")  == 0 ? $1.val && $3.val :
                    strcmp($2,"~")  == 0 ? $1.val || $3.val :
                    !($1.val && $3.val); // no such thing "Expression NOT Expression"  (should be unary "NOT Expression") ??
                    }
			|	Expression Case error					{yyerror(strcat("expected Expression after token ",$2));}
			|	Expression error					{yyerror("expected Case after Expression");}
			|	error							{yyerror("failed: BoolExp -> Expression Case Expression");}
			;
Case:			RELOP_wrap							{$$ = $1;}  /* ok : by definition */
			|	LOGOP_wrap						{$$ = $1;}  /* ok : by definition */
			|	error							{yyerror("failed: Case -> RELOP | LOGOP");}
			;

Expression:		Expression ADDOP_wrap Term					{  /* ok : by definition */
                    $$ = strcmp($2,"+") == 0 ? add($1,$3) : sub($1,$3);}
			|	Expression ADDOP_wrap error				{yyerror(strcat("expected Term after token ",$2));}
/*			|	Expression error					{yyerror("expected + or - after Expression");}*/ // makes a reduce/reduce conflict
			|	Term							{$$ = $1;}  /* ok : by definition */
			;
Term:			Term MULOP_wrap Factor						{ /* ok : by definition */
                    $$ =
                    strcmp($2,"*")   == 0 ? mul($1,$3)  :
                    strcmp($2,"/")   == 0 ? div_($1,$3) : mod($1,$3);
                    }
			|	Term MULOP_wrap error					{yyerror(strcat("expected Factor after token ",$2));}
			|	Factor							{$$ = $1;}       /* ok : by definition */
			;
Factor:			ID_wrap								{$$ = get_var($1);}  /* ok : by definition */
			|	NUM							{$$ = create_num();} /* ok : by definition */
			|	LPAR Expression RPAR					{$$ = $2;}           /* ok : by definition */
			|	LPAR Expression error					{yyerror("missing ) after Expression");}
			|	LPAR error						{yyerror("expected Expression after (");}
			;
ID_wrap:			ID							{$$ = create_id();}
RELOP_wrap:			RELOP							{$$ = create_op(yytext);}
LOGOP_wrap:			LOGOP							{$$ = create_op(yytext);}
ADDOP_wrap:			ADDOP							{$$ = create_op(yytext);}
MULOP_wrap:			MULOP							{$$ = create_op(yytext);}

%%
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