AC_INIT([libsalac], [0.1], [pulseaudio@niafc.de], [libsalac], [https://bugs.freedesktop.org/show_bug.cgi?id=42804])
AC_PREREQ([2.59])
AM_INIT_AUTOMAKE([1.10 no-define])

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h libsalacconfig.h])
AC_PROG_CXX

PKG_CHECK_MODULES([ALAC], [alac >= 0.0])
LT_INIT([disable-static])

AC_SUBST([LIBSALAC_SO_VERSION], [1:0:0])
AC_SUBST([LIBSALAC_API_VERSION], [1.0])

AC_CONFIG_FILES([Makefile libsalac-${LIBSALAC_API_VERSION}.pc:libsalac.pc.in])
AC_OUTPUT
