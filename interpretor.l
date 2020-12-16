%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%
[0-9]+ {yylval.intVal=atoi(yytext); return SMB;}
[ \t] ;
\n {return 0;}
. {return yytext[0];}
%%
int yywrap()
{
    return 1;
}