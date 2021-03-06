digit		[0-9]
letter		[a-zA-Z_]
delim		[ \t]
line		[\n]
ws			{delim}+

%{
#include "y.tab.h"
#include <string.h>
int line_no;
int checkidentifier();
%}

%%
{ws}			{ }
{line}			{line_no++;}
auto			{return(AUTO_SYM);}
break			{return(BREAK_SYM);}
case			{return(CASE_SYM);}
continue		{return(CASE_SYM);}
default			{return(DEFAULT_SYM);}
do				{return(DO_SYM);}
else			{return(ELSE_SYM);}
enum			{return(ENUM_SYM);}
for				{return(FOR_SYM);}
if				{return(IF_SYM);}
return			{return(RETURN_SYM);}
sizeof			{return(SIZEOF_SYM);}
static			{return(STATIC_SYM);}
struct			{return(STRUCT_SYM);}
switch			{return(SWITCH_SYM);}
typedef			{return(TYPEDEF_SYM);}
union			{return(UNION_SYM);}
while			{return(WHILE_SYM);}
"\+\+"			{return(PLUSPLUS);}
"\-\-"			{return(MINUSMINUS);}
"\->"			{return(ARROW);}
"<"				{return(RIGHTSIGN);}
">"				{return(LEFTSIGN);}
"<="			{return(RIGHTEQUALSIGN);}
">="			{return(LEFTEQUALSIGN);}
"=="			{return(EQUALEQUAL);}
"!="			{return(NOTEQUAL);}
"&&"			{return(ANDAND);}
"||"			{return(OROR);}
"\.\.\."		{return(DOTDOTDOT);}
"\("			{return(LP);}
"\)"			{return(RP);}
"\["			{return(LLLP);}
"\]"			{return(RRRP);}
"\{"			{return(LLP);}
"\}"			{return(RRP);}
"\:"			{return(COLON);}
"\."			{return(DOT);}
"\,"			{return(COMMA);}
"\!"			{return(EXCLAM);}
"\*"			{return(STAR);}
"\/"			{return(DIVID);}
"\%"			{return(MOD);}
"\&"			{return(AND);}
"\;"			{return(SEMI_COLON);}
"\+"			{return(PLUS);}
"\-"			{return(MINUS);}
"\="			{return(EQUAL);}
{digit}+					{return(INTEGER_CONSTANT);}
{digit}+\.{digit}+			{return(FLOAT_CONSTANT);}
{letter}({letter}|{digit})*	{return(checkidentifier(yytext));}
\"([^"\n]|\\["\n])*\"		{return(STRING_LITERAL);}
\'([^'\n]|\'\')\'			{return(CHARACTER_CONSTANT);}
%%

int checkidentifier(char *s){
		char *table[]={"int","float","char","void"};
		for(int i=0;i<4;i++){
				if(!strcmp(table[i],s)){//같으면
						return(TYPE_IDENTIFIER);
				}
		}
		return(IDENTIFIER);
}
