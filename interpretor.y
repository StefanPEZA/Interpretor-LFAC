%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
%}
%define parse.error verbose
%start s
%token SMB
%union {
    int intVal;
    float floatVal;
    char charVal;
    char* stringVal;
    short boolVal : 1;
}
%type <intVal> s
%type <intVal> e
%%
s : e {$$=$1; printf("regula s->e\n valoarea expresiei:%d\n",$$);}
    ;
e : SMB {$$=$<intVal>1;}
    ;
%%

void yyerror(char* s) {
 printf("error:%s\n",s);
}

int main(){
  yyparse();
}