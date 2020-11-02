#include <icbm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int
main(int argc, char **argv)
{
  char ch, *port, *url;

  if (!(port = getenv("ICBM_PORT")))
    port = strdup("1965");

  while ((ch = getopt(argc, argv, ":p:")) != -1) {
    switch (ch) {
    case 'p':
      port = strdup(optarg);
      break;
    }
  }

  url = malloc(strlen(argv[optind]) + strlen(port) + 2);
  sprintf(url, "%s:%s", argv[optind], port);

  icbm_get(url);

  return EXIT_SUCCESS;
}
