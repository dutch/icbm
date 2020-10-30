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

link: prelink STRING
    | prelink STRING SPACE strings
    ;

prelink: LINK
       | LINK SPACE
       ;

strings: STRING
       | strings SPACE STRING
       ;
