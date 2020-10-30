%{
#include "parser.h"
#include <string.h>
%}
%%
[0-9]+ { yylval.ival = atoi(yytext); return NUMBER; }
\n
[ \t]+
%%
int
yywrap(void)
{
  return 1;
}
