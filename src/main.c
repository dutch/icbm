#include <icbm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char **argv)
{
  char ch;

  while ((ch = getopt(argc, argv, ":v")) != -1) {
    switch (ch) {
    case 'v':
      fprintf(stderr, "%s\n", getverstr());
      break;
    }
  }

  parse("42 56\0\0");

  return EXIT_SUCCESS;
}
