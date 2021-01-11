
typedef enum
{
    constInt,
    constFloat,
    constChar,
    constStr,
    constBool,
    typeName,
    arraylist,
    paramList,
    typeId,
    typeOper
} nodeEnum;
/* constante */

typedef struct
{
    union
    {
        short boolVal;
        int intVal;
        float floatVal;
        char charVal;
        char *strVal;
        int typeVal;
    }; /* valoarea constantei */
} conNodeType;

/* identificatori */
typedef struct
{
    int i; /* indice in tabela de simboluri */
} idNodeType;

/* operatori */
typedef struct
{
    int oper;                  /* operator */
    int nops;                  /* nr. operanzi */
    struct nodeTypeTag *op[1]; /* operanzi */
} oprNodeType;

typedef struct
{
    int arrSize;
    union
    {
        int *arrInt;
        char *arrChar;
        char **arrStr;
        short *arrBool;
        float *arrFloat;
    } vect;

} arrayNodeType;

typedef struct
{
    int type;
    char *name;
} parameter;

typedef struct
{
    int listSize;
    parameter *listParam;        //lista de parametri
    struct nodeTypeTag *code[1]; //codul functiei
} funcNodeType;

typedef struct nodeTypeTag
{
    nodeEnum type; /* tipul nodului */
    union
    {
        conNodeType con;   /* constante */
        idNodeType id;     /* identificatori */
        oprNodeType opr;   /* operatori */
        arrayNodeType arr; /* vectori */
    };
} nodeType;

static struct symbolTable
{
    char *name;
    int type;     //VAR = 262, ARR = 274, FUN = 261,
    int baseType; //INT = 268, FLOAT = 269, CHAR = 270, STRING = 271, BOOL = 272,
    int scope;    // 0 - global, 1 - local in main, 2 - local, 3 - inside container
    int isconst;  // 0 -variabil, 1 - constant
    union
    {
        arrayNodeType arr;
        conNodeType val;
        funcNodeType fun;
    };
} symbol[100];
extern int lastIndex;

static int getIndex(char *Var, int locScope)
{
    for (int i = lastIndex - 1; i >= 0; i--)
    {
        if (!strcmp(symbol[i].name, Var) && (symbol[i].scope == locScope || symbol[i].scope == 0))
        {
            return i;
        }
    }
    return -1;
}

static int addSymbol(char *name, int varType, int baseType, int scope, int iscon, int size)
{
    for (int i = lastIndex - 1; i >= 0; i--)
    {
        if (!strcmp(symbol[i].name, name) && symbol[i].scope == scope)
        {
            return -1;
        }
    }

    symbol[lastIndex].name = name;
    symbol[lastIndex].type = varType;
    symbol[lastIndex].baseType = baseType;
    symbol[lastIndex].scope = scope;
    symbol[lastIndex].isconst = iscon;
    if (size >= 0)
    {
        symbol[lastIndex].arr.arrSize = size;
    }
    lastIndex++;
    return 1;
}
extern int localScope;
extern int sym[30];
extern char strExpr[1000];
static char *inorderExpr(nodeType *nodExpr)
{
    if (nodExpr == NULL)
        return NULL;

    if (nodExpr->type == typeOper)
    {
        if (nodExpr->opr.oper < 283 || nodExpr->opr.oper > 290 || nodExpr->opr.oper == '[')
        {
            if (nodExpr->opr.oper == 291)
            {
                strcat(strExpr, "(");
                strcat(strExpr, "-");
                inorderExpr(nodExpr->opr.op[0]);
                strcat(strExpr, ")");
            }
            else if (nodExpr->opr.oper == '[')
            {
                if (symbol[nodExpr->opr.op[0]->id.i].baseType == 268)
                {
                    char integer[20];
                    sprintf(integer, "%d", symbol[nodExpr->opr.op[0]->id.i].arr.vect.arrInt[nodExpr->opr.op[1]->con.intVal]);
                    strcat(strExpr, integer);
                }
                else
                {
                    strcpy(strExpr, "fail");
                }
            }
            else
            {
                strcat(strExpr, "(");
                inorderExpr(nodExpr->opr.op[0]);
                strcat(strExpr, (char *)&(nodExpr->opr.oper));
                inorderExpr(nodExpr->opr.op[1]);
                strcat(strExpr, ")");
            }
        }
        else
        {
            strcpy(strExpr, "fail");
        }
    }
    else if (nodExpr->type == typeId)
    {
        char integer[20];
        sprintf(integer, "%d", symbol[nodExpr->id.i].val.intVal);
        strcat(strExpr, integer);
    }
    else
    {
        if (nodExpr->type == constInt)
        {
            char integer[20];
            sprintf(integer, "%d", nodExpr->con.intVal);
            strcat(strExpr, integer);
        }
        else
        {
            strcpy(strExpr, "fail");
        }
    }
}
