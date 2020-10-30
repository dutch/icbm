%{
#include "parser.h"
#include <string.h>
%}
%%
=> { return LINK; }
[A-Za-z]+ { yylval.sval = strdup(yytext); return STRING; }
\n { return NEWLINE; }
[ \t]+ { return SPACE; }
%%
int yywrap(void) { return 1; }
