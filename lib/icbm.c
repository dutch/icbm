#include "config.h"
#include "parser.h"
#include <icbm.h>
#include <stdio.h>

extern int yyparse(void);

const char *
getverstr(void)
{
  return PACKAGE_STRING;
}

void
parse(const char *src)
{
  yyparse();
}

void
yyerror(const char *s)
{
  fprintf(stderr, "%s\n", s);
}
