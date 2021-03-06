# Author: Alexander Rykovanov 2009
#
#
# Distributed under the GNU LGPL License
# (See accompanying file LICENSE or copy at 
# http://www.gnu.org/licenses/lgpl.html)
#

AC_PREREQ([2.59])
AC_INIT([opcuaserver], [0.1.3], [rykovanov.as@gmail.com])
AC_CONFIG_AUX_DIR([.])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src/serverapp/server_main.cpp])
AM_INIT_AUTOMAKE([-Wall -Werror])

CXXFLAGS="-O0 -g -std=c++11"

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADER([config.h])

AC_PROG_CXX
AM_PROG_AR
PKG_PROG_PKG_CONFIG
#AM_PROG_LIBTOOL
LT_INIT

AC_ARG_ENABLE([gcov],
              [AS_HELP_STRING([--enable-gcov],[Enable support of coverage analize with gcov.])],
              [
                AC_SUBST([GCOV_FLAGS], ["-fprofile-arcs -ftest-coverage"])
                AC_SUBST([GCOV_LIBS], [-lgcov])
                AC_MSG_NOTICE([Enabled support of code coverage analize.])
              ],
              [
              ])

AC_ARG_ENABLE([python-bindings],
              [AS_HELP_STRING([--disable-python-bindings],[Disable building of python bindings.])],
              [
                AC_SUBST([PYTHON_BINDINGS], [])
                enable_python_bindings=no
                AC_MSG_NOTICE([Disabled support of python bindings.])
              ],
              [
                AC_SUBST([PYTHON_BINDINGS], [python])
                enable_python_bindings=yes
              ])

AC_ARG_ENABLE([unit-tests],
              [AS_HELP_STRING([--disable-unit-tests],[Disable building of unit tests. Library gtest wont be built.])],
              [
                enable_unit_tests=no
                AC_MSG_NOTICE([Disabled unit tests.])
                AC_SUBST([GTEST_PATH], [])
              ],
              [
                enable_unit_tests=yes
                AC_SUBST([GTEST_PATH], [tests/gtest])
                AC_SUBST([GTEST_LIB], [-Wl,--whole-archive,./tests/gtest/lib/.libs/libgtest_main.a,--no-whole-archive])
                AC_SUBST([GTEST_INCLUDES], [-I$srcdir/tests/gtest/include])
              ])


AM_CONDITIONAL([ENABLE_UNIT_TESTS], [test "x$enable_unit_tests" = xyes])
AM_CONDITIONAL([ENABLE_PYTHON], [test "x$enable_python_bindings" = xyes])

AC_SUBST([RELEASE_DATE], [$(date -R)])

#check headers
AC_CHECK_HEADERS([unistd.h])

#################################################################

AC_CONFIG_SUBDIRS([tests/gtest])

AS_IF([test "x$enable_python_bindings" = xyes], [
	ac_configure_args="$ac_configure_args --with-opcuaserver"
	AC_CONFIG_SUBDIRS([python])
])

#################################################################
AC_CONFIG_FILES([debian/changelog])
AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([libopcuacore.pc])
AC_CONFIG_FILES([libopcuaprotocol.pc])
AC_CONFIG_FILES([libopcuaserver.pc])
AC_CONFIG_FILES([libopcuaclient.pc])
AC_OUTPUT

