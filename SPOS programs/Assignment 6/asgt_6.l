/*
 * Program : Lex syntax
 * Name    : PranaV Shimpi
 * Class   : TE A
 * RNo.    :62
 */

%{
	#include "y.tab.h"
	extern int yylval;
%}

%%
"for" {return (For);}
"(" {return (Open_br);}
")" {return (Close_br);}
"{" {return (Open_curly);}
"}" {return (Close_curly);}
";" {return (Semi);}
"=" {return (Equal);}
"<"|">"|"<="|">=" {return (Rel);}
"++"|"--" {return (inc_dec);}
[a-z|A-Z] {yylval=yytext[0]; return Id;}
[0-9]+ {yylval=atof(yytext); return Num;}
%%

/*
OUTPUT : 
Lenovo@Lenovo:~/Downloads$ lex asgt_9.l
Lenovo@Lenovo:~/Downloads$ yacc -d asgt_9.y
Lenovo@Lenovo:~/Downloads$ cc lex.yy.c y.tab.c -ll -ly
Lenovo@Lenovo:~/Downloads$ ./a.out text.txt

File content is : 
for(i=0;i<n;i++){}

Accepted

*/
