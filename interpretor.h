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
        short boolVal : 1;
        int intVal;
        float floatVal;
        char charVal;
        char *strVal;
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
   int type;
} typeNodeType;

typedef struct 
{
    union 
    {
        int* arrInt;
        char* arrChar;
        char** arrStr;
        short* arrBool;
        float* arrFloat;
    };
    
}arrayNodeType;

typedef struct nodeTypeTag
{
    nodeEnum type; /* tipul nodului */
    union
    {
        conNodeType con; /* constante */
        idNodeType id;   /* identificatori */
        oprNodeType opr; /* operatori */
        typeNodeType typ;
        arrayNodeType arr;
    };
} nodeType;