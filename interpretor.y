%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    extern int nr_lines;
    extern int nr_word;
    extern FILE* yyin;
    extern char* yytext;
%}
%union {
    short boolVal : 1;
    int intVal;
    float floatVal;
    char charVal;
    char* stringVal;
    char* varId;
}
%define parse.lac full
%define parse.error verbose

%token CONTAINER EVAL CONST FUN VAR CALL IF ELSE WHILE FOR INT FLOAT CHAR STRING BOOL VOID
%token <varId> IDENTIFIER
%token <intVal> INT_CONST
%token <floatVal> FLOAT_CONST
%token <charVal> CHAR_CONST
%token <stringVal> STR_CONST
%token <boolVal> TRUE FALSE
%type <boolVal> bool_constants

%left AND
%left OR
%left EQUALITY INEQUALITY
%left LT GT LTE GTE
%right '='
%left '+' '-'
%left '*' '/' '%'
%right NEG '!'
%left '(' ')' ACCES

%start start
%%
start : stmts ;
stmts : stmts stmt | stmt {}
stmt : var_declaration ';' {}
    | const_declaration ';' {}
    | function_declaration {}
    | container_declaration {}
    ;

container_declaration : CONTAINER '{' container_body '}' IDENTIFIER ';' {}
    ;

container_body : container_elements {}
    | container_body container_elements {}
    ;

container_elements : var_declaration ';' {}
    | function_declaration {}
    ;

function_declaration : FUN return_type IDENTIFIER '(' fun_params ')' '{' fun_body '}' {}
    ;

return_type : types {}
    | VOID {}
    ;

fun_params : parameter ;
    | fun_params ',' parameter {}
    ;

parameter : types IDENTIFIER {}
            | {}
            ;

types : INT {}
    | FLOAT {}
    | CHAR {}
    | STRING {}
    | BOOL {}
    ;

fun_body : code_block {}
    | fun_body code_block {}
    ;

code_block : var_declaration ';' {}
    | const_declaration ';' {}
    | call_function ';' {}
    | var_assignment ';' {}
    | container_assignment ';' {}
    | container_function ';' {}
    | if_statement {}
    | while_statement {}
    | for_statement {}
    ;

if_statement : IF '(' bool_exp ')' '{' code_block '}' {}
    | IF '(' bool_exp ')' '{' code_block '}' ELSE '{' code_block '}'{}
    ;

while_statement : WHILE '(' bool_exp ')' '{' code_block '}' {}
    ;

for_statement : FOR '(' var_assignment ';' bool_exp ';' var_assignment ')' '{' code_block '}' {}
    ;

var_assignment : IDENTIFIER '=' expression {}
    ;

get_container_elem : IDENTIFIER ACCES IDENTIFIER {}
    ;

container_assignment : get_container_elem '=' expression {}
    ;

container_function : get_container_elem '(' call_params ')' {}
    ;

var_declaration : VAR types IDENTIFIER {}
    | VAR types IDENTIFIER '=' expression {}
    ;

const_declaration : CONST types IDENTIFIER '=' expression {}
    ;

call_function : CALL IDENTIFIER '(' call_params ')' {}
    | CALL eval_function {}
    ;

eval_function : EVAL '(' nr_exp ')' {} 
    ;

call_params : call_param {}
    | call_params call_param {}
    ;

call_param : call_function {}
    | expression {}
    ;

constants : number_constants | string_constants | bool_constants {}
    ;

number_constants : INT_CONST {}
    | FLOAT_CONST {}
    ;

string_constants : CHAR_CONST {}
    | STR_CONST {}
    ;

bool_constants : TRUE {$$=$1;}
    | FALSE {$$=$1;}
    ;

expression : nr_exp {}
    | bool_exp {}
    ;

nr_exp: IDENTIFIER {}
    | constants {}
    | get_container_elem {}
    | '(' nr_exp ')' {}
    | nr_exp '+' nr_exp {}
    | nr_exp '-' nr_exp {}
    | nr_exp '*' nr_exp {}
    | nr_exp '/' nr_exp {}
    | nr_exp '%' nr_exp {}
    | '-' nr_exp %prec NEG {}
    ; 

bool_exp : IDENTIFIER {}
    | constants {}
    | get_container_elem {}
    | '(' bool_exp ')' {}
    | nr_exp LT nr_exp {}
    | nr_exp GT nr_exp {}
    | nr_exp LTE nr_exp {}
    | nr_exp GTE nr_exp {}
    | bool_exp AND bool_exp {}
    | bool_exp OR bool_exp {}
    | '!' bool_exp {}
    ;
%%
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
