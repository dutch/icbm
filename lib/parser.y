%{
#include <stdio.h>
extern int yylex(void);
void yyerror(const char *);
%}
%union
{
  int ival;
}
%token <ival> NUMBER
%%
numbers: | numbers number;

number: NUMBER { puts("got a number"); };
%%
void
yyerror(const char *str)
{
  fprintf(stderr, "%s\n", str);
}

int
yywrap()
{
  return 1;
}
