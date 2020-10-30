bin_PROGRAMS = %D%/icbm
%C%_icbm_CFLAGS = -I$(top_srcdir)/include
%C%_icbm_SOURCES = %D%/main.c
%C%_icbm_LDADD = $(top_builddir)/lib/libicbm.la
