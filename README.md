# ft_printf

[![CI](https://github.com/LuisQAlmeida/42ft_printf/actions/workflows/ci.yml/badge.svg?branch=main)](https://github.com/LuisQAlmeida/42ft_printf/actions/workflows/ci.yml)

> Part of my [42 Common Core portfolio](https://github.com/LuisQAlmeida/42Portfolio).

A C implementation of a focused subset of `printf()`, developed as part of the
42 curriculum and maintained with automated regression testing and continuous
integration.

## Table of Contents

- [Academic Context](#academic-context)
- [Overview](#overview)
- [Supported conversions](#supported-conversions)
- [Implementation](#implementation)
- [Repository structure](#repository-structure)
- [Build](#build)
- [Usage](#usage)
- [Testing](#testing)
- [Continuous integration](#continuous-integration)
- [Behaviour notes](#behaviour-notes)
- [Doxygen Documentation](#doxygen-documentation)
- [AI Usage](#ai-usage)
- [Historical baseline](#historical-baseline)
- [License](#license)

## Academic Context

| | |
| --- | --- |
| **Curriculum** | 42 Common Core |
| **Project** | `ft_printf` |
| **Subject reference** | Version 12.1 |
| **Final evaluation** | **100/100** |
| **Project type** | Individual |

<img src="docs/assets/42-evaluation.png" alt="42 ft_printf evaluation: 100/100" width="180">

The original academic project received a **100/100** evaluation.

The subject document supplied for this portfolio pass identifies itself as
**ft_printf version 12.1**. Because subject revisions may evolve over time,
v12.1 is recorded as the supplied documentary reference rather than asserted
as an independently verified evaluation-day revision.

The current `main` branch is a maintained portfolio edition. The immutable
`portfolio-baseline-2026-09` tag preserves the repository state immediately
before the structured professional modernization, while `v1.0.0` remains the
first maintained portfolio release.

See [Academic Project Context](docs/academic/README.md) for the detailed
evaluation record, subject provenance, repository history, and AI usage notes.

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

### `src/ft_printf.c`

Contains the public `ft_printf()` entry point.

It is responsible for:

- traversing the format string;
- distinguishing literal characters from conversions;
- validating conversion specifiers;
- dispatching supported conversions;
- maintaining the total number of written characters;
- finalizing the variadic argument list.

### `src/ft_printf_format.c`

Contains the conversion dispatch logic.

It handles argument extraction and formatting for:

- characters;
- strings;
- signed integers;
- unsigned integers;
- hexadecimal integers;
- pointers;
- literal percent signs.

### `src/ft_printf_utils.c`

Contains the low-level output helpers used by the formatter:

- character output;
- string output;
- recursive decimal and hexadecimal number output.

### `include/ft_printf.h`

Contains the shared declarations used by the implementation and consumers of
the library.

### `Makefile`

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
├── docs/
│   ├── academic/
│   │   └── README.md
│   └── assets/
│       └── 42-evaluation.png
├── include/
│   └── ft_printf.h
├── src/
│   ├── ft_printf.c
│   ├── ft_printf_format.c
│   └── ft_printf_utils.c
├── tests/
│   ├── run_tests.sh
│   └── tests.c
├── .gitignore
├── Doxyfile
├── LICENSE
├── Makefile
└── README.md
```

Generated object files, test executables, static-library artefacts, and
generated Doxygen HTML are not part of the maintained repository tree.

## Build

From the repository root:

```sh
make
```

This produces:

```text
libftprintf.a
```

The available cleanup targets are:

```sh
make clean
make fclean
make re
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
  -Iinclude \
  libftprintf.a \
  -o example
```

Running the resulting program prints:

```text
Value: 42
```

## Testing

The canonical maintained validation interface is:

```sh
./tests/run_tests.sh
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
./tests/run_tests.sh
```

Clang:

```sh
CC=clang ./tests/run_tests.sh
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
./tests/run_tests.sh
```

rather than duplicating build commands or regression cases in workflow YAML.

After validation, CI also verifies that the repository remains clean and that
no generated tracked, untracked, or ignored build artefacts remain.

A separate `CI / documentation` job validates the repository-controlled
Doxygen API documentation. It generates the HTML documentation from
`Doxyfile`, checks the expected output and representative maintained API
symbols, removes the generated files, and verifies repository cleanliness.

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

## Doxygen Documentation

The maintained interface in `include/ft_printf.h` is documented using
Doxygen-style comments.

The documentation covers:

- the maintained module scope;
- the public `ft_printf()` entry point;
- the format-string and variadic interface;
- supported conversion specifiers;
- return and error behaviour;
- output behaviour;
- the support functions exposed by the maintained header.

The documentation describes this project's actual maintained implementation,
not the complete behaviour of the C standard library `printf()` function.

The repository tracks a canonical `Doxyfile`, so documentation generation does
not depend on a locally generated configuration.

Install Doxygen on Ubuntu if required:

```sh
sudo apt install doxygen
```

Generate the documentation from the repository root with:

```sh
doxygen Doxyfile
```

Generated HTML is written to:

```text
docs/html/
```

The main entry point is:

```text
docs/html/index.html
```

Generated HTML is intentionally ignored by Git. The repository-controlled
`Doxyfile` remains tracked as part of the maintained documentation contract.

Doxygen warnings are treated as validation failures. The dedicated
`CI / documentation` job generates the documentation, verifies representative
API entries, removes the generated files, and checks repository cleanliness.


## AI Usage

AI assistance was used differently during the original academic project and
the later portfolio modernization.

### Original academic development

During the academic project, AI was used as a support tool for:

- understanding project concepts;
- designing and reviewing tests;
- reasoning about expected behaviour and edge cases.

Its role in this phase was focused on learning and testing support. The
documentation does not attribute the project implementation itself to AI.

### Portfolio modernization

AI was used more extensively later as an engineering assistant during the
professional modernization of the repository.

It supported activities such as:

- systematic repository and code audits;
- maintainability review;
- regression-test strategy;
- CI and GitHub workflow planning;
- documentation design and review;
- validation planning;
- portfolio-wide consistency work.

AI-assisted suggestions were reviewed against the actual implementation and
validated before integration.

This distinction is intentional: the role of AI during the original academic
project was narrower than its later role in the professional portfolio
workflow.

---

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
