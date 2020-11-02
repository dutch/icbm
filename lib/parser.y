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
%token LINK SPACE NEWLINE
%token <sval> STRING
%%
lines: | lines line;
line: link NEWLINE;
link: LINK maybe_space STRING maybe_strings;
maybe_space: | SPACE;
maybe_strings: | strings;
strings: STRING | STRING strings;
