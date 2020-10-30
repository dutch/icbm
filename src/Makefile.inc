bin_PROGRAMS = %D%/icbm
%C%_icbm_CPPFLAGS = -I$(top_srcdir)/include -I$(top_builddir)/lib
%C%_icbm_SOURCES = %D%/main.c
%C%_icbm_LDADD = $(top_builddir)/lib/libicbm.la
