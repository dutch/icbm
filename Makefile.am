ACLOCAL_AMFLAGS = -I m4
BUILT_SOURCES = $(top_srcdir)/.version
EXTRA_DIST = $(top_srcdir)/build-aux/git-version-gen $(top_srcdir)/.version

$(top_srcdir)/.version:
	echo $(VERSION) >$@-t && mv $@-t $@

dist-hook:
	echo $(VERSION) >$(distdir)/.tarball-version

include $(srcdir)/lib/Makefile.inc
include $(srcdir)/src/Makefile.inc
include $(srcdir)/include/Makefile.inc
include $(srcdir)/tests/Makefile.inc
