%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdarg.h>
    #include "interpretor.h"
    extern int nr_lines;
    extern int nr_word;
    extern FILE* yyin;
    extern char* yytext;

    /* prototipurile functiilor */
    nodeType *nodOper(int oper, int nops, ...);
        /* nod operator in arbore */
    nodeType *nodId(char* i);
        /* nod frunza identificator */
    nodeType *nodCon(int type, void* value);
        /* nod frunza constanta */
    nodeType *nodArr(int type, int size, void* value);
    void freeNode(nodeType *p);
        /* eliberare memorie */
    int interpret(nodeType *p);
        /* functia de interpretare */
    int arrayInt[696969];
    short arrayBool[696969];
    char arrayChar[696969];
    char* arrayStr[696969];
    float arrayFloat[696969];
    int indx=0;
    int yylex();
    int yyerror(const char *s);
    int sym[100];

%}

%union {
    short boolVal : 1;
    int intVal;
    float floatVal;
    char charVal;
    char* strVal;
    char* varId;
    int Types;
    nodeType *nodPtr;
}
%define parse.lac full
%define parse.error verbose

%token CONTAINER EVAL CONST FUN VAR CALL IF ELSE WHILE FOR INT FLOAT CHAR STRING BOOL VOID ARR MAIN
%token <varId> IDENTIFIER
%token <intVal> INT_CONST
%token <floatVal> FLOAT_CONST
%token <charVal> CHAR_CONST
%token <strVal> STR_CONST
%token <boolVal> TRUE FALSE

%type <nodPtr> stmts stmt main_function expression fun_body code_block var_assignment var_declaration array_declaration
 array_assignment const_declaration call_function container_assignment container_function if_statement 
 while_statement  for_statement code_block_list array_list

%type <Types> types

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

start : stmts {interpret($1);};
stmts : stmts stmt {$$ = nodOper(';', 2, $1, $2);}
    | stmt {$$=$1;}
    ;

stmt : var_declaration ';' {}
    | array_declaration ';' {}
    | const_declaration ';' {}
    | function_declaration {}
    | container_declaration {}
    | main_function {}
    ;

main_function : VOID MAIN '(' ')' '{' fun_body '}' {$$=nodOper(MAIN,1,$6);}
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
    | FUN return_type IDENTIFIER '(' ')' '{' fun_body '}' {}
    ;

return_type : types {}
    | VOID {}
    ;

fun_params : parameter ;
    | fun_params ',' parameter {}
    ;

parameter : types IDENTIFIER {}
            ;

types : INT {$$=INT;}
    | FLOAT {$$=FLOAT;}
    | CHAR {$$=CHAR;}
    | STRING {$$=STRING;}
    | BOOL {$$=BOOL;}
    ;

fun_body : code_block {$$ = $1;}
    | fun_body code_block {$$ = nodOper(';', 2, $1, $2);}
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

code_block_list : code_block {$$ = $1;}
    | code_block_list code_block {$$ = nodOper(';', 2, $1, $2);}
    ;

if_statement : IF '(' expression ')' '{'  code_block_list  '}' %prec THEN {$$ = nodOper(IF, 2, $3, $6);}
    | IF '(' expression ')' '{' code_block_list '}' ELSE '{'  code_block_list  '}' {$$ = nodOper(IF, 3, $3, $6, $10);}
    ;

while_statement : WHILE '(' expression ')' '{'  code_block_list '}' {$$ = nodOper(WHILE, 2, $3, $6);}
    ;

for_statement : FOR '(' var_assignment ';'  expression ';' var_assignment ')' '{'  code_block_list  '}' { $$ = nodOper(FOR,4,$3,$5,$7,$10);}
    ;

var_assignment : IDENTIFIER '=' expression {$$ = nodOper('=', 2, nodId($1), $3);}
    ;

array_declaration : ARR types IDENTIFIER '[' INT_CONST ']' '=' '{' array_list '}' {indx=0;$$=nodOper(ARR, 4,nodCon(typeName,&$2),nodId($3),nodCon(constInt,&$5),$9);}
    | ARR types IDENTIFIER '[' INT_CONST ']' {$$=nodOper(ARR, 3,nodCon(typeName,&$2),nodId($3),nodCon(constInt,&$5));}
    ;

array_list : array_list_int {$$=nodArr(INT,100,arrayInt);printf("aaaaa");}
    | array_list_float {$$=nodArr(FLOAT, $<intVal>-3,arrayFloat);}
    | array_list_char {$$=nodArr(CHAR, $<intVal>-3,arrayChar);}
    | array_list_string {$$=nodArr(STRING, $<intVal>-3,arrayStr);}
    | array_list_bool {$$=nodArr(BOOL, $<intVal>-3,arrayBool);}
    ;
array_assignment : array_val'=' expression {}  
    ;

array_list_int : array_list_int ',' INT_CONST {arrayInt[indx]=$3; indx++;}
    | INT_CONST {arrayInt[indx]=$1; }
    ;
array_list_float : array_list_float ',' FLOAT_CONST {arrayFloat[indx]=$3; indx++;}
    | FLOAT_CONST {arrayFloat[indx]=$1; }
    ;    
array_list_char : array_list_char ',' CHAR_CONST {arrayChar[indx]=$3; indx++;}
    | CHAR_CONST {arrayChar[indx]=$1; }
    ;
array_list_string : array_list_string ',' STR_CONST {arrayStr[indx]=$3; indx++;}
    | STR_CONST {arrayStr[indx]=$1; } 
    ;
array_list_bool : array_list_bool ',' TRUE {arrayBool[indx]=1; indx++;}
    | array_list_bool ',' FALSE {arrayBool[indx]=0; indx++;}
    | TRUE {arrayBool[indx]=1; }
    | FALSE {arrayBool[indx]=0; }
    ;
array_val : IDENTIFIER '[' INT_CONST ']' {}
    ;

get_container_elem : IDENTIFIER ACCES IDENTIFIER {}
    ;

container_assignment : get_container_elem '=' expression {}
    ;

container_function : get_container_elem '(' call_params ')' {}
    ;

var_declaration : VAR types IDENTIFIER {$$ = nodOper(VAR,2,nodCon(typeName,&$2),nodId($3));}
    | VAR types IDENTIFIER '=' expression {$$ = nodOper(VAR,3,nodCon(typeName,&$2),nodId($3),$5);}
    ;

const_declaration : CONST types IDENTIFIER '=' expression {}
    ;

call_function : CALL IDENTIFIER '(' call_params ')' {}
    | CALL IDENTIFIER '(' ')' {}
    | CALL eval_function {}
    ;

eval_function : EVAL '(' expression ')' {} 
    ;

call_params : call_param {}
    | call_params ',' call_param {}
    ;

call_param : call_function {}
    | expression {}
    ;

expression:IDENTIFIER {$$ = nodId($1);}
    | get_container_elem {}
    | array_val {}
    | INT_CONST {$$ = nodCon(constInt, &$1);}
    | FLOAT_CONST {}
    | '(' expression ')' {$$ = $2;}
    | expression '+' expression {$$ = nodOper('+', 2, $1, $3);}
    | expression '-' expression {$$ = nodOper('-', 2, $1, $3);}
    | expression '*' expression {$$ = nodOper('*', 2, $1, $3);}
    | expression '/' expression {$$ = nodOper('/', 2, $1, $3);}
    | expression '%' expression {$$ = nodOper('%', 2, $1, $3);}
    | '-' expression %prec NEG {$$ = nodOper(NEG, 1, $2);}
    | TRUE {}
    | FALSE {}
    | expression LT expression {$$ = nodOper(LT, 2, $1, $3);}
    | expression GT expression {$$ = nodOper(GT, 2, $1, $3);}
    | expression LTE expression {$$ = nodOper(LTE, 2, $1, $3);}
    | expression GTE expression {$$ = nodOper(GTE, 2, $1, $3);}
    | expression EQUALITY expression {$$ = nodOper(EQUALITY, 2, $1, $3);}
    | expression INEQUALITY expression{$$ = nodOper(INEQUALITY, 2, $1, $3);}
    | expression AND expression {$$ = nodOper(AND, 2, $1, $3);}
    | expression OR expression {$$ = nodOper(OR, 2, $1, $3);}
    | '!' expression {$$ = nodOper('!', 1, $2);}
    | CHAR_CONST {}
    | STR_CONST {}
    ;

%%
int check = 1;

#define SIZEOF_NODETYPE ((char *)&p->con - (char *)p)
nodeType *nodCon(int type, void* value)
{
    nodeType *p;
    size_t nodeSize;
    /* alocare memorie pentru noul nod */
    nodeSize = SIZEOF_NODETYPE + sizeof(conNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");
    /* copiere valoare constanta */
    if (type == constInt){
        p->type = constInt;
        p->con.intVal = *((int*)value);
    }
    if (type == constBool){
        p->type = constBool;
        p->con.boolVal = *((short*)value);
    }
    if (type == constChar){
        p->type = constChar;
        p->con.charVal = *((char*)value);
    }
    if (type == constFloat){
        p->type = constFloat;
        p->con.floatVal = *((float*)value);
    }
    if (type == constStr){
        p->type = constStr;
        p->con.strVal = *((char**)value);
    }
    if(type==typeName){
        p->type =typeName;
        p->typ.type = *((int*)value);
    }
    return p;
}
nodeType *nodId(char* i)
{
    nodeType *p;
    size_t nodeSize;
    /* alocare memorie pentru noul nod */
    nodeSize = SIZEOF_NODETYPE + sizeof(idNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");
    /* copiere valoare indice */
    p->type = typeId;
    p->id.i = *i - 'a';
    return p;
}

nodeType *nodOper(int oper, int nops, ...)
{
    va_list ap;
    nodeType *p;
    size_t nodeSize;
    int i;
    /* allocare memorie pentru noul nod */
    nodeSize = SIZEOF_NODETYPE + sizeof(oprNodeType) +
               (nops - 1) * sizeof(nodeType *);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");
    /* copiere informatii functie de nops */
    p->type = typeOper;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType *);
    va_end(ap);
    return p;
}
nodeType *nodArr(int type, int size, void * value)
{
    printf("%d",size);
     nodeType *p;
    size_t nodeSize;
    /* alocare memorie pentru noul nod */
    nodeSize = SIZEOF_NODETYPE + sizeof(arrayNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");
    /* copiere valoare constanta */
    if (type == INT){
        p->type = arraylist;
        p->arr.arrInt=(int*)malloc(size*sizeof(int));
        printf("lasagna");
        for(int i=0; i<size;printf("sss"),i++){
            printf("%d\n",((int*)value)[i]);
            p->arr.arrInt[i] = ((int*)value)[i];
            printf("trololol\n");
        }
    }
    if (type == BOOL){
        p->type = arraylist;
        p->arr.arrBool=malloc(size*sizeof(short));
        p->arr.arrBool = ((short*)value);
    }
    if (type == CHAR){
        p->type = arraylist;
        p->arr.arrChar=malloc(size*sizeof(char));
        p->arr.arrChar = ((char*)value);
    }
    if (type == STRING){
        p->type = arraylist;
        p->arr.arrStr=malloc(size*sizeof(char*));
        p->arr.arrStr = ((char**)value);
    }
    if (type == FLOAT){
        p->type = arraylist;
        p->arr.arrFloat=malloc(size*sizeof(float));
        p->arr.arrFloat = ((float*)value);
    }
    return p;
}
void freeNode(nodeType *p)
{
    int i;
    if (!p)
        return;
    if (p->type == typeOper)
    {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    }
    free(p);
}

int interpret(nodeType *p)
{
    if (!p)
        return 0;
    switch (p->type)
    {
    case constInt:
        return p->con.intVal;
    case constFloat:
        return p->con.floatVal;
    case constBool:
        return p->con.boolVal;
    case constChar:
        return p->con.charVal;
    case constStr:
        return *p->con.strVal;
    case typeId:
        return sym[p->id.i];
    case typeOper:
        switch (p->opr.oper)
        {
        case MAIN: return interpret(p->opr.op[0]);
        case ';': interpret(p->opr.op[0]);
            return interpret(p->opr.op[1]);
        case WHILE:
            while (interpret(p->opr.op[0]))
                interpret(p->opr.op[1]);
            return 0;
        case IF:
            if (interpret(p->opr.op[0]))
                interpret(p->opr.op[1]);
            else if (p->opr.nops > 2)
                interpret(p->opr.op[2]);
            return 0;
        case FOR:
            for(interpret(p->opr.op[0]);interpret(p->opr.op[1]);interpret(p->opr.op[2]))
                interpret(p->opr.op[3]);
            return 0;
        case ARR:
            if(p->opr.nops == 3){
                if(p->opr.op[0]->typ.type==INT)
                    return sym[p->opr.op[1]->id.i] = 0;
            }
            else
                if(p->opr.op[0]->typ.type==INT)
                    return sym[p->opr.op[1]->id.i] = p->arr.arrInt[0];
        case VAR:
            if(p->opr.nops == 2){
                if(p->opr.op[0]->typ.type==INT)
                    return sym[p->opr.op[1]->id.i]=0;
            }
            else
                if(p->opr.op[0]->typ.type==INT)
                    return sym[p->opr.op[1]->id.i]=interpret(p->opr.op[2]);
        case '=':
            return sym[p->opr.op[0]->id.i] =
                       interpret(p->opr.op[1]);
        case NEG:
            return -interpret(p->opr.op[0]);
        case '+':
            return interpret(p->opr.op[0]) +
                   interpret(p->opr.op[1]);
        case '-':
            return interpret(p->opr.op[0]) - interpret(p->opr.op[1]);
        case '*':
            return interpret(p->opr.op[0]) * interpret(p->opr.op[1]);
        case '/':
            return interpret(p->opr.op[0]) /
                   interpret(p->opr.op[1]);
        case LT:
            return interpret(p->opr.op[0]) <
                   interpret(p->opr.op[1]);
        case GT:
            return interpret(p->opr.op[0]) >
                   interpret(p->opr.op[1]);
        case GTE:
            return interpret(p->opr.op[0]) >=
                   interpret(p->opr.op[1]);
        case LTE:
            return interpret(p->opr.op[0]) <=
                   interpret(p->opr.op[1]);
        case INEQUALITY:
            return interpret(p->opr.op[0]) !=
                   interpret(p->opr.op[1]);
        case EQUALITY:
            return interpret(p->opr.op[0]) ==
                   interpret(p->opr.op[1]);
        }
    }
    return 0;
}

int yyerror(const char *s)
{
    printf("%s la linia %d, cuvantul %d\n", s, nr_lines, nr_word);
    check = 0;
}

int main(int argc, char **argv)
{ 
    if (argc > 0)
        yyin = fopen(argv[1], "r");
    yyparse();
    if (check == 1)
    {
        printf("Programul este corect sintactic!\n\n");

        for (int i = 0; i < 100; i++)
        {
            printf("%d " , sym[i]);
        }
    }
}