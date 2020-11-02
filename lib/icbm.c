#include "config.h"
#include "parser.h"
#include <icbm.h>
#include <stdio.h>
#include <openssl/ssl.h>
#include <openssl/evp.h>
#include <openssl/x509.h>

void
yyerror(const char *s)
{
  fprintf(stderr, "%s\n", s);
}

static int
BIO_write_fingerprint(BIO *b, X509 *cert)
{
  int i;
  unsigned int buflen;
  unsigned char buf[EVP_MAX_MD_SIZE];

  if (X509_digest(cert, EVP_sha1(), buf, &buflen) == 0)
    return 1;

  for (i = 0; i < buflen; ++i)
    BIO_printf(b, "%02X%c", buf[i], (i + 1 == buflen) ? '\n' : ':');

  return 0;
}

int
icbm_get(const char *url)
{
  SSL_CTX *ctx;
  BIO *remote, *err;
  SSL *ssl;
  X509 *cert;

  SSL_library_init();
  SSL_load_error_strings();

  if (!(ctx = SSL_CTX_new(TLS_method()))) {
    fputs("SSL_CTX_new\n", stderr);
    return EXIT_FAILURE;
  }

  if (SSL_CTX_set_min_proto_version(ctx, TLS1_2_VERSION) == 0) {
    fputs("SSL_CTX_set_min_proto_version\n", stderr);
    return EXIT_FAILURE;
  }

  if (!(remote = BIO_new_ssl_connect(ctx))) {
    fputs("BIO_new_ssl_connect\n", stderr);
    return EXIT_FAILURE;
  }

  if (BIO_set_conn_hostname(remote, url) == 0) {
    fputs("BIO_set_conn_hostname\n", stderr);
    return EXIT_FAILURE;
  }

  BIO_get_ssl(remote, &ssl);
  if (!ssl) {
    fputs("BIO_get_ssl\n", stderr);
    return EXIT_FAILURE;
  }

  if (BIO_do_connect(remote) == 0) {
    fputs("BIO_do_connect\n", stderr);
    return EXIT_FAILURE;
  }

  if (BIO_do_handshake(remote) == 0) {
    fputs("BIO_do_handshake\n", stderr);
    return EXIT_FAILURE;
  }

  if (!(cert = SSL_get_peer_certificate(ssl))) {
    fputs("peer did not present a certificate\n", stderr);
    return EXIT_FAILURE;
  }

  err = BIO_new_fp(stderr, BIO_NOCLOSE);
  BIO_write_fingerprint(err, cert);

  X509_free(cert);
  BIO_free_all(remote);
  BIO_free_all(err);
  SSL_CTX_free(ctx);

  return EXIT_SUCCESS;
}
