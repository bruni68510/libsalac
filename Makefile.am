AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS} -I m4

lib_LTLIBRARIES = libsalac-@LIBSALAC_API_VERSION@.la
libsalac_@LIBSALAC_API_VERSION@_la_SOURCES = src/libsalac.cc \
                                             src/libsalac.h

libsalac_@LIBSALAC_API_VERSION@_la_LDFLAGS = -version-info $(LIBSALAC_SO_VERSION)
libsalac_includedir = $(includedir)/libsalac-$(LIBSALAC_API_VERSION)
nobase_libsalac_include_HEADERS = src/libsalac.h

libsalac_libincludedir = $(libdir)/libsalac-$(LIBSALAC_API_VERSION)/include
nodist_libsalac_libinclude_HEADERS = src/libsalacconfig.h
libsalac_@LIBSALAC_API_VERSION@_la_CPPFLAGS = $(DEPS_CFLAGS)
libsalac_@LIBSALAC_API_VERSION@_la_LIBADD = $(ALAC_LIBS)

pkconfigdir = $(libdir)/pkgconfig
pkconfig_DATA = libsalac-$(LIBSALAC_API_VERSION).pc

dist_noinst_SCRIPTS = autogen.sh
