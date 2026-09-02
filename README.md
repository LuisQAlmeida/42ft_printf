# ft_printf

[![CI](https://github.com/LuisQAlmeida/42ft_printf/actions/workflows/ci.yml/badge.svg?branch=main)](https://github.com/LuisQAlmeida/42ft_printf/actions/workflows/ci.yml)

A C implementation of a focused subset of `printf()`, developed as part of the
42 curriculum and maintained with automated regression testing and continuous
integration.

## Overview

`ft_printf` reproduces the core formatting behaviour required by the 42
`ft_printf` project.

The implementation parses a format string, consumes variadic arguments, writes
the formatted result to standard output, and returns the number of characters
written for supported valid formats.

This project implements a deliberately limited subset of standard `printf()`.
It does **not** provide the complete formatting feature set of the C standard
library function.

In particular, this implementation does not support:

- formatting flags;
- field width;
- precision;
- length modifiers;
- floating-point conversions.

## Supported conversions

| Specifier | Behaviour |
| --- | --- |
| `%c` | Character |
| `%s` | String |
| `%p` | Pointer |
| `%d` | Signed decimal integer |
| `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Lowercase hexadecimal integer |
| `%X` | Uppercase hexadecimal integer |
| `%%` | Literal percent sign |

## Implementation

The implementation is intentionally small and divided by responsibility.

### `ft_printf/ft_printf.c`

Contains the public `ft_printf()` entry point.

It is responsible for:

- traversing the format string;
- distinguishing literal characters from conversions;
- validating conversion specifiers;
- dispatching supported conversions;
- maintaining the total number of written characters;
- finalizing the variadic argument list.

### `ft_printf/ft_printf_format.c`

Contains the conversion dispatch logic.

It handles argument extraction and formatting for:

- characters;
- strings;
- signed integers;
- unsigned integers;
- hexadecimal integers;
- pointers;
- literal percent signs.

### `ft_printf/ft_printf_utils.c`

Contains the low-level output helpers used by the formatter:

- character output;
- string output;
- recursive decimal and hexadecimal number output.

### `ft_printf/ft_printf.h`

Contains the shared declarations used by the implementation and consumers of
the library.

### `ft_printf/Makefile`

Builds the implementation as the static library:

`libftprintf.a`

The object-file rules track the shared header so changes to `ft_printf.h`
correctly invalidate dependent objects.

## Repository structure

```text
.
├── .github/
│   └── workflows/
│       └── ci.yml
├── ft_printf/
│   ├── ft_printf.c
│   ├── ft_printf_format.c
│   ├── ft_printf_utils.c
│   ├── ft_printf.h
│   └── Makefile
├── tester/
│   ├── tests.c
│   └── run_tests.sh
├── .gitignore
├── LICENSE
└── README.md
```

Generated object files, test executables, and static-library artefacts are not
part of the maintained repository tree.

## Build

From the repository root:

```sh
make -C ft_printf
```

This produces:

```text
ft_printf/libftprintf.a
```

The available cleanup targets are:

```sh
make -C ft_printf clean
make -C ft_printf fclean
make -C ft_printf re
```

Their roles are:

- `clean` removes compiled object files;
- `fclean` removes object files and `libftprintf.a`;
- `re` performs a complete rebuild.

## Usage

Include the public header and link against the generated static library.

Example:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Value: %d\n", 42);
	return (0);
}
```

After building the library:

```sh
cc -Wall -Wextra -Werror \
  main.c \
  -Ift_printf \
  ft_printf/libftprintf.a \
  -o example
```

Running the resulting program prints:

```text
Value: 42
```

## Testing

The canonical maintained validation interface is:

```sh
./tester/run_tests.sh
```

The runner:

1. removes previous build artefacts;
2. builds `libftprintf.a`;
3. compiles the automated tester with `-Wall -Wextra -Werror`;
4. executes the regression suite;
5. runs Valgrind when it is available;
6. propagates build and test failures, plus Valgrind failures when Valgrind runs;
7. removes generated test and library artefacts before exiting.

The maintained suite currently contains **36 automated regression tests**.

For valid supported formatting, the harness executes standard `printf()` and
`ft_printf()` independently and compares both:

- emitted output;
- return value.

Output is captured and compared using explicit byte lengths rather than only
NUL-terminated string semantics. This allows cases such as `%c` emitting an
embedded `'\0'` byte to be validated correctly.

The suite also covers integer boundaries, valid and NULL pointers, mixed
formats, adjacent conversions, and maintained project-specific error
behaviour.

### Compiler selection

The runner uses the environment's default `cc` unless `CC` is supplied.

Default compiler:

```sh
./tester/run_tests.sh
```

Clang:

```sh
CC=clang ./tester/run_tests.sh
```

Both compiler paths are part of the maintained validation workflow.

## Continuous integration

GitHub Actions runs the repository validation workflow for:

- pull requests targeting `main`;
- pushes to `main`.

The maintained CI reference environment is:

`ubuntu-24.04`

CI validates the canonical runner using both:

- GCC;
- Clang.

Valgrind is installed explicitly in CI, so memory validation is mandatory in
the GitHub-hosted environment.

The workflow delegates project validation to:

```sh
./tester/run_tests.sh
```

rather than duplicating build commands or regression cases in workflow YAML.

After validation, CI also verifies that the repository remains clean and that
no generated tracked, untracked, or ignored build artefacts remain.

Current maintained validation contract:

| Validation | Result |
| --- | --- |
| GCC | PASS |
| Clang | PASS |
| Automated regression tests | 36/36 |
| Valgrind errors | 0 |
| Memory leaks | 0 |

The CI badge at the top of this README reflects the latest workflow state for
`main`.

## Behaviour notes

For supported valid formats, the maintained regression suite compares
`ft_printf()` against the platform `printf()` implementation.

Some error behaviour is specific to this project implementation and should not
be interpreted as standard `printf()` behaviour.

### Invalid conversion

```c
ft_printf("%k");
```

The maintained implementation:

- writes `Error: Invalid Format\n`;
- returns `-2`.

### Dangling percent sign

```c
ft_printf("%");
```

The maintained implementation:

- writes `Error: Invalid Format\n`;
- returns `-2`.

### NULL format string

```c
ft_printf(NULL);
```

The maintained implementation:

- performs no formatting output;
- returns `-1`.

The implementation also emits `(null)` for a NULL `%s` argument and `(nil)` for
a NULL `%p` argument.

NULL representations used by standard-library implementations are
platform-dependent, so these textual representations should not be interpreted
as universal requirements of standard `printf()`.

## Historical baseline

The repository preserves its state before professional portfolio maintenance
at:

`portfolio-baseline-2026-09`

This tag points to:

`c7a61e409e17ef34284007495bd207f2d4115f75`

The baseline provides a stable reference for the original project state,
including the historical visual test infrastructure.

Subsequent Git history and merged pull requests document the maintained
correctness, testing, build, CI, and documentation improvements.

## License

This repository is distributed under the [MIT License](LICENSE).
