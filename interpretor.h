
typedef enum
{
    constInt,
    constFloat,
    constChar,
    constStr,
    constBool,
    typeName,
    arraylist,
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
    union
    {
        int *arrInt;
        char *arrChar;
        char **arrStr;
        short *arrBool;
        float *arrFloat;
    };

} arrayNodeType;

typedef struct
{
    char *name;
    int type;
} parameter;

typedef struct
{
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

struct symbolTable
{
    char *name;
    int type;     //VAR = 262, ARR = 274, FUN = 261,
    int baseType; //INT = 268, FLOAT = 269, CHAR = 270, STRING = 271, BOOL = 272,
    int scope;    // 0 - global, 1 - local in main, 2 - local, 3 - inside container
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
        if (!strcmp(symbol[i].name, Var))
        {
            return i;
        }
    }
    return -1;
}

static int addSymbol(char *name, int varType, int baseType, int scope)
{
    for (int i = lastIndex - 1; i >= 0; i--)
    {
        if (!strcmp(symbol[i].name, name) && symbol[i].scope == scope)
        {
            return -1;
        }
    }

    if (varType == 262)
    {
        symbol[lastIndex].name = name;
        symbol[lastIndex].type = varType;
        symbol[lastIndex].baseType = baseType;
        symbol[lastIndex].scope = scope;
        lastIndex++;
    }
    if (varType == 272)
    {
        symbol[lastIndex].name = name;
        symbol[lastIndex].type = varType;
        symbol[lastIndex].baseType = baseType;
        symbol[lastIndex].scope = scope;
    }
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
        if (nodExpr->opr.oper < 283 || nodExpr->opr.oper > 290)
        {
            if (nodExpr->opr.oper == 291)
            {
                strcat(strExpr, "(");
                strcat(strExpr, "-");
                inorderExpr(nodExpr->opr.op[0]);
                strcat(strExpr, ")");
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
        sprintf(integer, "%d", sym[nodExpr->id.i]);
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
