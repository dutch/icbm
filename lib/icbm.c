#include "config.h"
#include "parser.h"
#include <icbm.h>
#include <stdio.h>
#include <openssl/ssl.h>
#include <openssl/evp.h>
#include <openssl/x509.h>

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

int
icbm_get(const char *url)
{
  const SSL_METHOD *method;
  const EVP_MD *digest;
  SSL_CTX *ctx;
  BIO *space;
  SSL *ssl;
  X509 *cert;
  unsigned char buf[EVP_MAX_MD_SIZE];
  unsigned int buflen;

  SSL_library_init();
  SSL_load_error_strings();

  if (!(method = TLS_method())) {
    fputs("TLS_method\n", stderr);
    return EXIT_FAILURE;
  }

  if (!(ctx = SSL_CTX_new(method))) {
    fputs("SSL_CTX_new\n", stderr);
    return EXIT_FAILURE;
  }

  if (SSL_CTX_set_min_proto_version(ctx, TLS1_2_VERSION) == 0) {
    fputs("SSL_CTX_set_min_proto_version\n", stderr);
    return EXIT_FAILURE;
  }

  if (!(space = BIO_new_ssl_connect(ctx))) {
    fputs("BIO_new_ssl_connect\n", stderr);
    return EXIT_FAILURE;
  }

  if (BIO_set_conn_hostname(space, url) == 0) {
    fputs("BIO_set_conn_hostname\n", stderr);
    return EXIT_FAILURE;
  }

  BIO_get_ssl(space, &ssl);
  if (!ssl) {
    fputs("BIO_get_ssl\n", stderr);
    return EXIT_FAILURE;
  }

  if (BIO_do_connect(space) == 0) {
    fputs("BIO_do_connect\n", stderr);
    return EXIT_FAILURE;
  }

  if (BIO_do_handshake(space) == 0) {
    fputs("BIO_do_handshake\n", stderr);
    return EXIT_FAILURE;
  }

  if (!(cert = SSL_get_peer_certificate(ssl))) {
    fputs("peer did not present a certificate\n", stderr);
    return EXIT_FAILURE;
  }

  X509_digest(cert, EVP_sha1(), buf, &buflen);
  X509_free(cert);

  fprintf(stderr, "fingerprint: %.*s\n", buflen, buf);

  BIO_free_all(space);
  SSL_CTX_free(ctx);

  return EXIT_SUCCESS;
}
