BUILT_SOURCES += %D%/parser.h
AM_YFLAGS = -d
lib_LTLIBRARIES = %D%/libicbm.la
%C%_libicbm_la_CFLAGS = -I$(top_srcdir)/include
%C%_libicbm_la_SOURCES = %D%/icbm.c %D%/parser.y %D%/scanner.l
%C%_libicbm_la_LDFLAGS = -version 0:0:0
