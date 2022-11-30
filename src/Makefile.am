AM_CFLAGS = $(VARNISHAPI_CFLAGS) -Wall -Werror
AM_LDFLAGS = $(VARNISHAPI_LIBS) $(VMOD_LDFLAGS)

vmod_LTLIBRARIES = libvmod_flagship.la

libvmod_flagship_la_LDFLAGS = -module -export-dynamic -avoid-version -shared -lflagship

libvmod_flagship_la_SOURCES = \
	vmod_flagship.c

nodist_libvmod_flagship_la_SOURCES = \
	vcc_flagship_if.c \
	vcc_flagship_if.h

dist_man_MANS = vmod_flagship.3

@BUILD_VMOD_FLAGSHIP@

AM_TESTS_ENVIRONMENT = \
	PATH="$(VMOD_TEST_PATH)" \
	LD_LIBRARY_PATH="$(VARNISH_LIBRARY_PATH)"
TEST_EXTENSIONS = .vtc
VTC_LOG_COMPILER = varnishtest -v
AM_VTC_LOG_FLAGS = -Dvmod_flagship="$(VMOD_FLAGSHIP)"

TESTS = @VMOD_TESTS@

EXTRA_DIST = \
	vmod_flagship.vcc \
	$(VMOD_TESTS)
