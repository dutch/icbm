lib_LTLIBRARIES = %D%/libicbm.la
%C%_libicbm_la_CFLAGS = -I$(top_srcdir)/include
%C%_libicbm_la_SOURCES = %D%/icbm.c
%C%_libicbm_la_LDFLAGS = -version 0:0:0
