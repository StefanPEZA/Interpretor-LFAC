%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    extern int nr_lines;
    extern int nr_word;
    extern FILE* yyin;
    extern char* yytext;
%}
%define parse.lac full
%define parse.error verbose
%start start
%token SEMICOLON CONTAINER IDENTIFIER OPEN_BRACE CLOSE_BRACE OPEN_P CLOSE_P INT FLOAT CHAR STRING BOOL VOID EQUAL
INT_CONST FLOAT_CONST CHAR_CONST STR_CONST TRUE FALSE EVAL CONST COMMA FUN VAR PLUS MINUS TIMES DIV

%left TIMES DIV
%left PLUS MINUS
%union {
    int intVal;
    float floatVal;
    char charVal;
    char* dataType;
    char* stringVal;
    short boolVal : 1;
}
%%
start : stmts ;
stmts : stmts stmt | stmt {}
stmt : var_declaration SEMICOLON {}
    | const_declaration SEMICOLON {}
    | function_declaration {}
    | container_declaration {}
    ;

container_declaration : CONTAINER IDENTIFIER OPEN_BRACE container_body CLOSE_BRACE {}
    ;

container_body : container_elements {}
    | container_body container_elements {}
    ;

container_elements : var_declaration SEMICOLON {}
    | function_declaration {}
    ;

function_declaration : FUN return_type IDENTIFIER OPEN_P fun_params CLOSE_P OPEN_BRACE fun_body CLOSE_BRACE {}
    ;

return_type : types {}
    | VOID {}
    ;

fun_params : parameter ;
    | fun_params COMMA parameter {}
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

code_block : var_declaration SEMICOLON {}
    | const_declaration SEMICOLON {}
    | call_function {}
    | var_assignment {}
    | container_assignment {}
    | container_function {}
    | eval_function SEMICOLON {}
    ;

var_assignment : VAR IDENTIFIER EQUAL expression {}
    ;

get_container_elem : IDENTIFIER'.'IDENTIFIER {}
    ;

container_assignment : get_container_elem EQUAL expression {}
    ;

container_function : get_container_elem OPEN_P call_params CLOSE_P {}
    ;

eval_function : EVAL OPEN_P expression CLOSE_P {} 
    ;

var_declaration : VAR types IDENTIFIER {}
    | VAR types IDENTIFIER EQUAL expression {}
    ;

const_declaration : CONST types IDENTIFIER EQUAL expression {}
    ;

call_function : IDENTIFIER OPEN_P call_params CLOSE_P {}
    ;

call_params : call_param {}
    | call_params call_param {}
    ;

call_param :call_function {}
    | expression {}
    ;
 
constants : INT_CONST {$<intVal>$=$<intVal>1;}
    | FLOAT_CONST {$<floatVal>$=$<floatVal>1;}
    | CHAR_CONST {$<charVal>$=$<charVal>1;}
    | STR_CONST {$<stringVal>$=$<stringVal>1;}
    | bool_const {$<boolVal>$=$<boolVal>1;}
    ;

bool_const : TRUE {$<boolVal>$=$<boolVal>1;}
    | FALSE {$<boolVal>$=$<boolVal>1;}
    ;

expression : expression PLUS expression {}
    | expression MINUS expression {}
    | expression TIMES expression {}
    | expression DIV expression {}
    | IDENTIFIER {}
    | constants {}
    | get_container_elem {}
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
