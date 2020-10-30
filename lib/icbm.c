#include "config.h"
#include <icbm.h>

const char *
getverstr(void)
{
  return PACKAGE_STRING;
}

void
parse(const char *src)
{
  scan_string(src);
}
