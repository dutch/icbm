BUILT_SOURCES += %D%/parser.h
AM_YFLAGS = -d
lib_LTLIBRARIES = %D%/libicbm.la
%C%_libicbm_la_CPPFLAGS = -I$(top_srcdir)/include -I$(top_builddir)/lib $(OPENSSL_CFLAGS)
%C%_libicbm_la_LDFLAGS = -version 0:0:0
%C%_libicbm_la_SOURCES = %D%/icbm.c %D%/parser.y %D%/scanner.l
%C%_libicbm_la_LIBADD = $(OPENSSL_LIBS)
