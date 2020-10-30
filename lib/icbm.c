#include "config.h"
#include "parser.h"
#include <icbm.h>

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
