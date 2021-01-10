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
    nodeType *nodId(char* i, int newId);
        /* nod frunza identificator */
    nodeType *nodCon(int type, void* value);
        /* nod frunza constanta */
    nodeType *nodArr(int type, int size);
    void freeNode(nodeType *p);
        /* eliberare memorie */
    void* interpret(nodeType *p);
    void evalError(const char*, int nre);
        /* functia de interpretare */
    int arrayInt[1000];
    short arrayBool[1000];
    char arrayChar[1000];
    char* arrayStr[1000];
    float arrayFloat[1000];
    char strExpr[1000] = "";
    int nreval = 1;
    int indx=0;
    int lastIndex = 0;
    int yylex();
    int yyerror(const char *s);
    int sym[30];

    int localScope = 0;

%}

%union {
    short boolVal;
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
 while_statement  for_statement code_block_list array_list eval_function array_val

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

start : stmts {interpret($1); };
stmts : stmts stmt {$$ = nodOper(';', 2, $1, $2);}
    | stmt {$$=$1;}
    ;

stmt : var_declaration ';' {}
    | array_declaration ';' {}
    | const_declaration ';' {}
    | function_declaration {}
    | container_declaration {}
    | main_function {localScope = 0;}
    ;

main_function : VOID MAIN '(' ')' '{' fun_body '}' {
    $$=nodOper(MAIN,1,$6);}
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

var_assignment : IDENTIFIER '=' expression {
    int x=getIndex($1,localScope);
    if(symbol[x].isconst==1)
        yyerror("Nu poti schimba valoarea unei constante - ");
    else{
        if(x==-1)
            yyerror("Variabila nu este declarata - ");
        else
            $$ = nodOper('=', 2, nodId($1, 0), $3);
    }
}
    ;

array_declaration : ARR types IDENTIFIER '[' INT_CONST ']' '=' '{' array_list '}' {
        if (addSymbol($3, ARR, $2, localScope, 0) == -1){
            yyerror("Variabila deja declarata - ");
        }
        $$=nodOper(ARR, 4,nodCon(typeName,&$2),nodId($3, 1),nodCon(constInt,&$5),nodArr($2, indx)); indx=0;}
    | ARR types IDENTIFIER '[' INT_CONST ']' {
        if (addSymbol($3, ARR, $2, localScope, 0) == -1){
            yyerror("Variabila deja declarata - ");
        }
        $$=nodOper(ARR, 3,nodCon(typeName,&$2),nodId($3, 1),nodCon(constInt,&$5));}
    ;

array_list : array_list_int {}
    | array_list_float {}
    | array_list_char {}
    | array_list_string {}
    | array_list_bool {}
    ;
array_list_int : array_list_int ',' INT_CONST { arrayInt[indx]=$3; indx++;}
    | INT_CONST {arrayInt[indx]=$1; indx++;}
    ;
array_list_float : array_list_float ',' FLOAT_CONST {arrayFloat[indx]=$3; indx++;}
    | FLOAT_CONST {arrayFloat[indx]=$1; indx++;}
    ;    
array_list_char : array_list_char ',' CHAR_CONST {arrayChar[indx]=$3; indx++;}
    | CHAR_CONST {arrayChar[indx]=$1; indx++;}
    ;
array_list_string : array_list_string ',' STR_CONST {arrayStr[indx]=$3; indx++;}
    | STR_CONST {arrayStr[indx]=$1; indx++;} 
    ;
array_list_bool : array_list_bool ',' TRUE {arrayBool[indx]=1; indx++;}
    | array_list_bool ',' FALSE {arrayBool[indx]=0; indx++;}
    | TRUE {arrayBool[indx]=1; indx++;}
    | FALSE {arrayBool[indx]=0; indx++;}
    ;
array_val : IDENTIFIER '[' INT_CONST ']' {
    int x=getIndex($1,localScope);
    if(x==-1)
        yyerror("Variabila nu este declarata - ");
    else{
        if(symbol[x].type==ARR){
            $$ = nodOper('[',2,nodId($1,0),nodCon(constInt,&$3));
        }
        else
            yyerror("Nu este vector - ");
    }
}
    ;
array_assignment : array_val '=' expression {
     $$ = nodOper('=', 3, $1, $3, NULL);
}  
    ;
get_container_elem : IDENTIFIER ACCES IDENTIFIER {}
    ;

container_assignment : get_container_elem '=' expression {}
    ;

container_function : get_container_elem '(' call_params ')' {}
    ;

var_declaration : VAR types IDENTIFIER {
        if (addSymbol($3, VAR, $2, localScope, 0) == -1){
            yyerror("Variabila deja declarata - ");
        }
        $$ = nodOper(VAR,2,nodCon(typeName,&$2),nodId($3, 1));}

    | VAR types IDENTIFIER '=' expression {

        if (addSymbol($3, VAR, $2, localScope, 0) == -1){
            yyerror("Variabila deja declarata - ");
        }
        $$ = nodOper(VAR,3,nodCon(typeName,&$2),nodId($3, 1),$5);}
    ;

const_declaration : CONST types IDENTIFIER '=' expression {
    if (addSymbol($3, VAR, $2, localScope, 1) == -1){
            yyerror("Variabila deja declarata - ");
        }
        $$ = nodOper(VAR,3,nodCon(typeName,&$2),nodId($3, 1),$5);
    }
    ;

call_function : CALL IDENTIFIER '(' call_params ')' {}
    | CALL IDENTIFIER '(' ')' {}
    | CALL eval_function {$$ = $2; }
    ;

eval_function : EVAL '(' expression ')' { $$ = nodOper(EVAL, 1, $3); } 
    ;

call_params : call_param {}
    | call_params ',' call_param {}
    ;

call_param : call_function {}
    | expression {}
    ;

expression:IDENTIFIER {$$ = nodId($1, 0);}
    | get_container_elem {}
    | array_val {$$=$1;}
    | INT_CONST {$$ = nodCon(constInt, &$1);}
    | FLOAT_CONST {$$ = nodCon(constFloat, &$1);}
    | '(' expression ')' {$$ = $2;}
    | expression '+' expression {$$ = nodOper('+', 2, $1, $3);}
    | expression '-' expression {$$ = nodOper('-', 2, $1, $3);}
    | expression '*' expression {$$ = nodOper('*', 2, $1, $3);}
    | expression '/' expression {$$ = nodOper('/', 2, $1, $3);}
    | expression '%' expression {$$ = nodOper('%', 2, $1, $3);}
    | '-' expression %prec NEG {$$ = nodOper(NEG, 1, $2);}
    | TRUE {short b = 1; $$ = nodCon(constBool, &b);}
    | FALSE {short b = 0; $$ = nodCon(constBool, &b);}
    | expression LT expression {$$ = nodOper(LT, 2, $1, $3);}
    | expression GT expression {$$ = nodOper(GT, 2, $1, $3);}
    | expression LTE expression {$$ = nodOper(LTE, 2, $1, $3);}
    | expression GTE expression {$$ = nodOper(GTE, 2, $1, $3);}
    | expression EQUALITY expression {$$ = nodOper(EQUALITY, 2, $1, $3);}
    | expression INEQUALITY expression{$$ = nodOper(INEQUALITY, 2, $1, $3);}
    | expression AND expression {$$ = nodOper(AND, 2, $1, $3);}
    | expression OR expression {$$ = nodOper(OR, 2, $1, $3);}
    | '!' expression {$$ = nodOper('!', 1, $2);}
    | CHAR_CONST {$$ = nodCon(constChar, &$1);}
    | STR_CONST {$$ = nodCon(constStr, &$1);}
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
    else if (type == constBool){
        p->type = constBool;
        p->con.boolVal = *((short*)value);
    }
    else if (type == constChar){
        p->type = constChar;
        p->con.charVal = *((char*)value);
    }
    else if (type == constFloat){
        p->type = constFloat;
        p->con.floatVal = *((float*)value);
    }
    else if (type == constStr){
        p->type = constStr;
        p->con.strVal = *((char**)value);
    }
    else if(type==typeName){
        p->type = typeName;
        p->con.typeVal = *((int*)value);
    }
    return p;
}
nodeType *nodId(char* i, int newId)
{
    
    nodeType *p;
    size_t nodeSize;
    /* alocare memorie pentru noul nod */
    nodeSize = SIZEOF_NODETYPE + sizeof(idNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");
    /* copiere valoare indice */
    p->type = typeId;
    p->id.i = getIndex(i, localScope);
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

nodeType *nodArr(int type, int size)
{
    nodeType *p;
    size_t nodeSize;
    /* alocare memorie pentru noul nod */
    nodeSize = SIZEOF_NODETYPE + sizeof(arrayNodeType) + size*sizeof(int);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");
    /* copiere valoare constanta */
    if (type == INT){
        p->type = arraylist;
        p->arr.vect.arrInt=(int*)malloc(size*sizeof(int));
        for(int i=0; i<size;i++){
            p->arr.vect.arrInt[i] = arrayInt[i];
        }
    }
    else if (type == BOOL){
        p->type = arraylist;
        p->arr.vect.arrBool=malloc(size*sizeof(short));
        for(int i=0; i<size;i++){
            p->arr.vect.arrBool[i] = arrayBool[i];
        }
    }
    else if (type == CHAR){
        p->type = arraylist;
        p->arr.vect.arrChar=malloc(size*sizeof(char));
        for(int i=0; i<size;i++){
            p->arr.vect.arrChar[i] = arrayChar[i];
        }
    }
    else if (type == STRING){
        p->type = arraylist;
        p->arr.vect.arrStr=malloc(size*sizeof(char*));
        for(int i=0; i<size;i++){
            p->arr.vect.arrStr[i] = arrayStr[i];
        }
    }
    else if (type == FLOAT){
        p->type = arraylist;
        p->arr.vect.arrFloat=malloc(size*sizeof(float));
        for(int i=0; i<size;i++){
            p->arr.vect.arrFloat[i] = arrayFloat[i];
        }
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


void* interpret(nodeType *p)
{
    int* result = (int*)malloc(sizeof(int));;
    if (!p)
        return 0;
    switch (p->type)
    {
    case constInt:
        return &p->con.intVal;
    case constFloat:
        return &p->con.floatVal;
    case constBool:
        return &p->con.boolVal;
    case constChar:
        return &p->con.charVal;
    case constStr:
        return &p->con.strVal;
    case typeId:
        return &symbol[p->id.i].val.intVal;
    case typeOper:
        switch (p->opr.oper)
        {
        case MAIN: return interpret(p->opr.op[0]);
        case EVAL:
            if(check == 1){
                inorderExpr(p->opr.op[0]);
                if (strstr(strExpr, "fail"))
                {
                    evalError("Parametrul nu este de tip int - la eval #", nreval);
                    return 0;
                }
                nreval++;
                result = (int*)interpret(p->opr.op[0]);
                printf("Eval[%s] = %d\n", strExpr, *result);
            }
            return 0;
        case ';': interpret(p->opr.op[0]);
            return interpret(p->opr.op[1]);
        case WHILE:
            while (interpret(p->opr.op[0]))
                interpret(p->opr.op[1]);
            return 0;
        case IF:
            if (*(short*)interpret(p->opr.op[0]))
                interpret(p->opr.op[1]);
            else if (p->opr.nops > 2)
                interpret(p->opr.op[2]);
            return 0;
        case FOR:
            for(interpret(p->opr.op[0]);*(short*)interpret(p->opr.op[1]);interpret(p->opr.op[2]))
                interpret(p->opr.op[3]);
            return 0;
        case ARR:
            if(p->opr.nops == 3){
                if(p->opr.op[0]->con.typeVal==INT){
                    symbol[p->opr.op[1]->id.i].arr.vect.arrInt = malloc(p->opr.op[2]->con.intVal*sizeof(int));
                    return 0;
                    }
                else if(p->opr.op[0]->con.typeVal==FLOAT){
                    symbol[p->opr.op[1]->id.i].arr.vect.arrFloat = malloc(p->opr.op[2]->con.intVal*sizeof(float));
                    return 0;
                }
                else if(p->opr.op[0]->con.typeVal==CHAR){
                    symbol[p->opr.op[1]->id.i].arr.vect.arrChar = malloc(p->opr.op[2]->con.intVal*sizeof(char));;
                    return 0;
                }
                else if(p->opr.op[0]->con.typeVal==STRING){
                    symbol[p->opr.op[1]->id.i].arr.vect.arrStr = malloc(p->opr.op[2]->con.intVal*sizeof(char*));
                    return 0;
                }
                else if(p->opr.op[0]->con.typeVal==BOOL){
                    symbol[p->opr.op[1]->id.i].arr.vect.arrBool = malloc(p->opr.op[2]->con.intVal*sizeof(short));
                    return 0;
                }
            }
            else{
                if(p->opr.op[0]->con.typeVal==INT){
                    symbol[p->opr.op[1]->id.i].arr.vect.arrInt = p->opr.op[3]->arr.vect.arrInt;
                    return 0;
                    }
                else if(p->opr.op[0]->con.typeVal==FLOAT){
                    symbol[p->opr.op[1]->id.i].arr.vect.arrFloat = p->opr.op[3]->arr.vect.arrFloat;
                    return 0;
                }
                else if(p->opr.op[0]->con.typeVal==CHAR){
                    symbol[p->opr.op[1]->id.i].arr.vect.arrChar = p->opr.op[3]->arr.vect.arrChar;
                    return 0;
                }
                else if(p->opr.op[0]->con.typeVal==STRING){
                    symbol[p->opr.op[1]->id.i].arr.vect.arrStr = p->opr.op[3]->arr.vect.arrStr;
                    return 0;
                }
                else if(p->opr.op[0]->con.typeVal==BOOL){
                    symbol[p->opr.op[1]->id.i].arr.vect.arrBool = p->opr.op[3]->arr.vect.arrBool;
                    return 0;
                }
            }
        case '[':
            if(symbol[p->opr.op[0]->id.i].baseType==INT)
                return &(symbol[p->opr.op[0]->id.i].arr.vect.arrInt[p->opr.op[1]->con.intVal]);
            else if(symbol[p->opr.op[0]->id.i].baseType==FLOAT){
                return &symbol[p->opr.op[1]->id.i].arr.vect.arrFloat[p->opr.op[1]->con.intVal];
            }
            else if(symbol[p->opr.op[0]->id.i].baseType==CHAR){
                return &symbol[p->opr.op[1]->id.i].arr.vect.arrChar[p->opr.op[1]->con.intVal];
            }
            else if(symbol[p->opr.op[0]->id.i].baseType==STRING){
                return &symbol[p->opr.op[1]->id.i].arr.vect.arrStr[p->opr.op[1]->con.intVal];
            }
            else if(symbol[p->opr.op[0]->id.i].baseType==BOOL){
                return &(symbol[p->opr.op[0]->id.i].arr.vect.arrBool[p->opr.op[1]->con.intVal]);
            }
        case VAR:
            if(p->opr.nops == 2){
                if(p->opr.op[0]->con.typeVal==INT)
                    symbol[p->opr.op[1]->id.i].val.intVal=0;
                else if(p->opr.op[0]->con.typeVal==FLOAT)
                    symbol[p->opr.op[1]->id.i].val.floatVal =0.0;
                else if(p->opr.op[0]->con.typeVal==CHAR)
                    symbol[p->opr.op[1]->id.i].val.charVal = '\0';
                else if(p->opr.op[0]->con.typeVal==STRING)
                    symbol[p->opr.op[1]->id.i].val.strVal = (char*)"";
                else if(p->opr.op[0]->con.typeVal==BOOL)
                    symbol[p->opr.op[1]->id.i].val.boolVal = 0;
            }
            else{
                if(p->opr.op[0]->con.typeVal==INT)
                    symbol[p->opr.op[1]->id.i].val.intVal=*(int*)interpret(p->opr.op[2]);
                else if(p->opr.op[0]->con.typeVal==FLOAT)
                    symbol[p->opr.op[1]->id.i].val.floatVal=*(float*)interpret(p->opr.op[2]);
                else if(p->opr.op[0]->con.typeVal==CHAR)
                    symbol[p->opr.op[1]->id.i].val.charVal=*(char*)interpret(p->opr.op[2]);
                else if(p->opr.op[0]->con.typeVal==STRING)
                    symbol[p->opr.op[1]->id.i].val.strVal=*(char**)interpret(p->opr.op[2]);
                else if(p->opr.op[0]->con.typeVal==BOOL)
                    symbol[p->opr.op[1]->id.i].val.boolVal=*(short*)interpret(p->opr.op[2]);
            }
            return 0;
        case '=':
        if(p->opr.nops == 2){
            if(symbol[p->opr.op[0]->id.i].baseType==INT)
                symbol[p->opr.op[0]->id.i].val.intVal = *(int*)interpret(p->opr.op[1]);
            else if(symbol[p->opr.op[0]->id.i].baseType==FLOAT)
                symbol[p->opr.op[0]->id.i].val.floatVal = *(float*)interpret(p->opr.op[1]);
            else if(symbol[p->opr.op[0]->id.i].baseType==CHAR)
                symbol[p->opr.op[0]->id.i].val.charVal = *(char*)interpret(p->opr.op[1]);
            else if(symbol[p->opr.op[0]->id.i].baseType==STRING)
                symbol[p->opr.op[0]->id.i].val.strVal = *(char**)interpret(p->opr.op[1]);
            else if(symbol[p->opr.op[0]->id.i].baseType==BOOL)
                symbol[p->opr.op[0]->id.i].val.boolVal = *(short*)interpret(p->opr.op[1]);
        }
        else if(p->opr.nops == 3){
            if(symbol[p->opr.op[0]->opr.op[0]->id.i].baseType==INT)
                *(int*)interpret(p->opr.op[0]) = *(int*)interpret(p->opr.op[1]);
            else if(symbol[p->opr.op[0]->opr.op[0]->id.i].baseType==FLOAT)
                *(float*)interpret(p->opr.op[0]) = *(float*)interpret(p->opr.op[1]);
            else if(symbol[p->opr.op[0]->id.i].baseType==CHAR)
                *(char*)interpret(p->opr.op[0]) = *(char*)interpret(p->opr.op[1]);
            else if(symbol[p->opr.op[0]->id.i].baseType==STRING)
                *(char**)interpret(p->opr.op[0]) = *(char**)interpret(p->opr.op[1]);
            else if(symbol[p->opr.op[0]->id.i].baseType==BOOL)
                *(short*)interpret(p->opr.op[0]) = *(short*)interpret(p->opr.op[1]);
        }
        return 0;
        case NEG:{
            *result =-*(int*)interpret(p->opr.op[0]);
            return result;
        }
        case '+':{
            *result= (*(int*)interpret(p->opr.op[0]) + *(int*)interpret(p->opr.op[1]));
            return result;
        }
        case '-':{
            *result = *(int*)interpret(p->opr.op[0]) - *(int*)interpret(p->opr.op[1]);
            return result;
        }
        case '*':{
            *result = *(int*)interpret(p->opr.op[0]) * *(int*)interpret(p->opr.op[1]);
            return result;
        }
        case '/':{
            *result =*(int*)interpret(p->opr.op[0]) / *(int*)interpret(p->opr.op[1]);
            return result;
        }
        case '%':{
            *result = *(int*)interpret(p->opr.op[0]) % *(int*)interpret(p->opr.op[1]);
            return result;
        }
        case LT:{
            *result = *(int*)interpret(p->opr.op[0]) < *(int*)interpret(p->opr.op[1]);
            return result;
        }
        case GT:{
            *result= *(int*)interpret(p->opr.op[0]) > *(int*)interpret(p->opr.op[1]);
            return result;
        }
        case GTE:{
            *result= *(int*)interpret(p->opr.op[0]) >= *(int*)interpret(p->opr.op[1]);
            return result;
        }
        case LTE:{
            *result = *(int*)interpret(p->opr.op[0]) <= *(int*)interpret(p->opr.op[1]);
            return result;
        }
        case INEQUALITY:{
            *result = *(int*)interpret(p->opr.op[0]) != *(int*)interpret(p->opr.op[1]);
            return result;
        }
        case EQUALITY:{
            *result = *(int*)interpret(p->opr.op[0]) == *(int*)interpret(p->opr.op[1]);
            return result;
        }
        }
    }
    return 0;
}

void evalError(const char* s, int nre){
    printf("%s%d\n", s, nre);
}

int yyerror(const char *s)
{
    printf("%s la linia %d, cuvantul %d\n", s, nr_lines, nr_word);
    check = 0;
}

void printTable();
int main(int argc, char **argv)
{   
    printf("\n");
    if (argc > 0)
        yyin = fopen(argv[1], "r");
    yyparse();
    if (check == 1)
    {
        printTable();
    }

}

void printTable(){
    FILE* out = fopen("symbol_table.txt", "w");
    char symStr[10000] = "";
    char temp[1000];
    int funIDS[10];
    int idf = 0;
    
    sprintf(temp, "name\t\t\tscope\t\t\ttype\t\tbase_type\tvalue\n");
    strcat(symStr, temp);
    sprintf(temp, "---------------------------------------------------------------------------------\n");
    strcat(symStr, temp);
    for (int i = 0; i < lastIndex; i++)
    {
        sprintf(temp, "%-12s\t", symbol[i].name);
        strcat(symStr, temp);
        sprintf(temp, "%-12s\t", (symbol[i].scope==0)?"global":((symbol[i].scope==1||symbol[i].scope==2)?"local":"in-container"));
        strcat(symStr, temp);
        if (symbol[i].type == FUN)
        {
            funIDS[idf] = i;
            idf++;
        }
        else if (symbol[i].type == VAR)
        {
            if (symbol[i].baseType == INT)
                sprintf(temp, "%-8s\t%-6s\t\t%d", "Variable", "INT", symbol[i].val.intVal);
            else if (symbol[i].baseType == FLOAT)
                sprintf(temp, "%-8s\t%-6s\t\t%f", "Variable", "FLOAT", symbol[i].val.floatVal);
            else if (symbol[i].baseType == CHAR)
                sprintf(temp, "%-8s\t%-6s\t\t'%c'", "Variable", "CHAR", symbol[i].val.charVal);
            else if (symbol[i].baseType == STRING)
                sprintf(temp, "%-8s\t%-6s\t\t\"%s\"", "Variable", "STRING", symbol[i].val.strVal);
            else if (symbol[i].baseType == BOOL)
                sprintf(temp, "%-8s\t%-6s\t\t%s", "Variable", "BOOL", (symbol[i].val.boolVal)?"true":"false");
        }
        else if (symbol[i].type == ARR)
        {
            if (symbol[i].baseType == INT)
                sprintf(temp, "%-8s\t%-6s\t\t[%d, ...]", "Array", "INT" , *symbol[i].arr.vect.arrInt);
            else if (symbol[i].baseType == FLOAT)
                sprintf(temp, "%-8s\t%-6s\t\t[%f, ...]", "Array", "FLOAT" , *symbol[i].arr.vect.arrFloat);
            else if (symbol[i].baseType == CHAR)
                sprintf(temp, "%-8s\t%-6s\t\t[%c, ...]", "Array", "CHAR" , *symbol[i].arr.vect.arrChar);
            else if (symbol[i].baseType == STRING)
                sprintf(temp, "%-8s\t%-6s\t\t[%s, ...]", "Array", "STRING", *symbol[i].arr.vect.arrStr);
            else if (symbol[i].baseType == BOOL)
                sprintf(temp, "%-8s\t%-6s\t\t[%s, ...]", "Array", "BOOL", (*symbol[i].arr.vect.arrBool)?"true":"false");
        }
        strcat(symStr, temp);
        strcat(symStr, "\n");
    }

    if (idf > 0){
        strcat(symStr, "\nFunctions:\n");
        for (int i = 0; i < idf; i++)
        {
            int inx = funIDS[i];
            sprintf(temp, "%-12s\t", symbol[i].name);
            strcat(symStr, temp);
            sprintf(temp, "%-12s\t", (symbol[i].scope==0)?"global":((symbol[i].scope==1||symbol[i].scope==2)?"local":"in-container"));


            strcat(symStr, temp);
            strcat(symStr, "\n");
        }
    }
    fprintf(out, "%s", symStr);
}