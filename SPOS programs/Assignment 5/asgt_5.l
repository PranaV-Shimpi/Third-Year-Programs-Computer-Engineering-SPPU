/*
 * Program : Lex datatype syntax
 * Name    : PranaV Shimpi
 * Class   : TE A
 * RNo.    : 62
 */

%{
	#include "y.tab.h"
	extern int yylval;
%}

%%
"int" {return (Int);}
"float" {return (Float);}
"double" {return (Double);}
"char" {return (Char);}
"{" {return (COpen);}
"}" {return (CClose);}
"[" {return (Open_br);}
"]" {return (Close_br);}
";" {return (Semi);}
"=" {return (Equal);}
[0-9]+.[0-9]+ {return (dbl);}
[a-z|A-Z]+[a-z|A-Z|0-9]* {yylval=yytext[0]; return Id;}
[0-9]+ {yylval=atof(yytext); return Num;}
%%

/*
OUTPUT : 
unix@unix:~/Downloads$ lex asgt_8.l
unix@unix:~/Downloads$ yacc -d asgt_8.y
unix@unix:~/Downloads$ cc lex.yy.c y.tab.c -ll -ly
unix@unix:~/Downloads$ ./a.out text.txt

File content is : 
int a=10;
 


*/


