AC_INIT([icbm],
[m4_esyscmd([build-aux/git-version-gen .tarball-version])],
[chris@lamberson.online])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_TESTDIR([tests])
AM_INIT_AUTOMAKE([foreign tar-pax dist-xz no-dist-gzip subdir-objects])
AM_PROG_AR
LT_INIT
ICBM_INIT
AC_PROG_CC
AM_PROG_LEX
AC_PROG_YACC
PKG_CHECK_MODULES([OPENSSL], [openssl >= 1.1.0])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
