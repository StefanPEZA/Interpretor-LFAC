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

%token CONTAINER EVAL CONST FUN VAR CALL IF ELSE WHILE FOR INT FLOAT CHAR STRING BOOL VOID ARR 
%token <varId> IDENTIFIER
%token <intVal> INT_CONST
%token <floatVal> FLOAT_CONST
%token <charVal> CHAR_CONST
%token <stringVal> STR_CONST
%token <boolVal> TRUE FALSE

%left AND
%left OR
%left EQUALITY INEQUALITY
%left LT GT LTE GTE
%right '='
%left '+' '-'
%left '*' '/' '%'
%right NEG '!'
%left '(' ')' ACCES
%nonassoc THEN
%nonassoc ELSE
%start start
%%

start : stmts ;
stmts : stmts stmt | stmt {}
stmt : var_declaration ';' {}
    | array_declaration ';' {}
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
    | array_declaration ';' {}
    | array_assignment ';' {}
    | const_declaration ';' {}
    | call_function ';' {}
    | var_assignment ';' {}
    | container_assignment ';' {}
    | container_function ';' {}
    | if_statement {}
    | while_statement {}
    | for_statement {}
    ;

if_statement : IF '(' expression ')' '{' code_block '}' %prec THEN {}
    | IF '(' expression ')' '{' code_block '}' ELSE '{' code_block '}' {}
    ;

while_statement : WHILE '(' expression ')' '{' code_block '}' {}
    ;

for_statement : FOR '(' var_assignment ';'  expression ';' var_assignment ')' '{' code_block '}' {}
    ;

var_assignment : IDENTIFIER '=' expression {}
    ;

array_declaration : ARR types IDENTIFIER '[' INT_CONST ']' '=' '{' array_list '}' {}
    | ARR types IDENTIFIER '[' INT_CONST ']' {}
    ;
array_list : array_list_int {}
    | array_list_float {}
    | array_list_char {}
    | array_list_string {}
    | array_list_bool {}
    | 
    ;
array_assignment : array_val'=' expression {}  
    ;

array_list_int : array_list_int ',' INT_CONST {}
    | INT_CONST {}
    ;
array_list_float : array_list_float ',' FLOAT_CONST {}
    | FLOAT_CONST {}
    ;    
array_list_char : array_list_char ',' CHAR_CONST {}
    | CHAR_CONST {}
    ;
array_list_string : array_list_string ',' STR_CONST {}
    | STR_CONST {} 
    ;
array_list_bool : array_list_bool ',' TRUE {}
    | array_list_bool ',' FALSE {}
    | TRUE {}
    | FALSE {}
    ;
array_val : IDENTIFIER '[' INT_CONST ']';

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

eval_function : EVAL '(' expression ')' {} 
    ;

call_params : call_param {}
    | call_params call_param {}
    ;

call_param : call_function {}
    | expression {}
    ;

expression:IDENTIFIER {}
    | get_container_elem {}
    | array_val {}
    | INT_CONST {}
    | FLOAT_CONST {}
    | '(' nr_exp ')' {}
    | nr_exp '+' nr_exp {}
    | nr_exp '-' nr_exp {}
    | nr_exp '*' nr_exp {}
    | nr_exp '/' nr_exp {}
    | nr_exp '%' nr_exp {}
    | '-' nr_exp %prec NEG {}
    | TRUE {}
    | FALSE {}
    | '(' bool_exp ')' {}
    | nr_exp LT nr_exp {}
    | nr_exp GT nr_exp {}
    | nr_exp LTE nr_exp {}
    | nr_exp GTE nr_exp {}
    | nr_exp EQUALITY nr_exp {}
    | nr_exp INEQUALITY {}
    | bool_exp AND bool_exp {}
    | bool_exp OR bool_exp {}
    | '!' bool_exp {}
    | CHAR_CONST {}
    | STR_CONST {}
    | string_exp '+' string_exp {}
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
