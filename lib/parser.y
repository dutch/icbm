%{
#include <stdio.h>
extern int yylex(void);
void yyerror(const char *);
%}
%union
{
  int ival;
  char *sval;
}
%token <ival> NUMBER
%token <sval> STRING
%%
numbers: | numbers number;
number: NUMBER { puts("got a number"); };
