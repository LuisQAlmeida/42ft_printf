#!/bin/sh

set -eu

SCRIPT_DIR="$(
	cd -- "$(dirname -- "$0")"
	pwd
)"

ROOT_DIR="$(
	cd -- "$SCRIPT_DIR/.."
	pwd
)"

LIB_DIR="$ROOT_DIR/ft_printf"
TEST_SOURCE="$SCRIPT_DIR/tests.c"
TEST_BINARY="$SCRIPT_DIR/.ft_printf_tests"

CC_BIN="${CC:-cc}"
CFLAGS="-Wall -Wextra -Werror"

cleanup()
{
	rm -f "$TEST_BINARY"
	make -C "$LIB_DIR" fclean >/dev/null 2>&1 || true
}

trap cleanup EXIT HUP INT TERM

printf '\n=== CLEAN ===\n'
make -C "$LIB_DIR" fclean

printf '\n=== BUILD LIBRARY ===\n'
make -C "$LIB_DIR" CC="$CC_BIN"

printf '\n=== BUILD TESTER ===\n'
"$CC_BIN" \
	$CFLAGS \
	-I"$LIB_DIR" \
	"$TEST_SOURCE" \
	"$LIB_DIR/libftprintf.a" \
	-o "$TEST_BINARY"

printf '\n=== REGRESSION TESTS ===\n'
"$TEST_BINARY"

if command -v valgrind >/dev/null 2>&1
then
	printf '\n=== VALGRIND ===\n'
	valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--error-exitcode=42 \
		"$TEST_BINARY"
else
	printf '\n=== VALGRIND ===\n'
	echo 'SKIP: Valgrind is not installed'
fi

printf '\n=== RESULT ===\n'
echo 'PASS: automated regression validation completed'
