%{
#include "parser.h"
#include <stdio.h>
#include <string.h>
void scan_string(char *str);
%}
%%
[0-9]+ { yylval.ival = atoi(yytext); return NUMBER; }
\n
[ \t]+
%%
void
scan_string(char *str)
{
  yy_switch_to_buffer(yy_scan_buffer(str, strlen(str)));
  yylex();
}
