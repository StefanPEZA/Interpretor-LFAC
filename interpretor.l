%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
int nr_lines = 1;
int nr_word = 0;
%}
integer ([1-9][0-9]*)|0
id [a-zA-Z_][0-9a-zA-Z_]*
float (([1-9][0-9]*)|0)?\.([0-9]+)
char '.'
string \".*\"
%option noyywrap
%%
= {nr_word++;return EQUAL;}
if {nr_word++;return IF;}
else {nr_word++;return ELSE;}
for {nr_word++;return FOR;}
while {nr_word++;return WHILE;}
then {nr_word++;return THEN;}
do {nr_word++;return DO;}
container {nr_word++; return CONTAINER;}
const {nr_word++; return CONST;}
int {nr_word++; return INT;}
float {nr_word++; return FLOAT;}
char {nr_word++; return CHAR;}
string {nr_word++; return STRING;}
bool {nr_word++;return BOOL;}
void {nr_word++;return VOID;}
Fun: {nr_word++;return FUN;}
Call: {nr_word++; return CALL;}
Var: {nr_word++;return VAR;}
Eval {nr_word++;return EVAL;}
true {nr_word++;yylval.boolVal=1; return TRUE;}
false {nr_word++;yylval.boolVal=0; return FALSE;}
\; {nr_word++;return SEMICOLON;}
\( {nr_word++;return OPEN_P;}
\) {nr_word++;return CLOSE_P;}
\{ {nr_word++;return OPEN_BRACE;}
\} {nr_word++;return CLOSE_BRACE;}
, {nr_word++;return COMMA;}
{id} {nr_word++;return IDENTIFIER;}
{float} {nr_word++;yylval.floatVal=atof(yytext); return FLOAT_CONST;}
{integer} {nr_word++;yylval.intVal=atoi(yytext); return INT_CONST;}
{char} {nr_word++;yylval.charVal=yytext[1]; return CHAR_CONST;}
{string} {nr_word++;yylval.stringVal=strndup(yytext+1, strlen(yytext)-2); return STR_CONST;}
[ \r\t]+ ;
[\n] {nr_lines++; nr_word = 0;}
[-+*/] {nr_word++; return *yytext;}
. ;
%%