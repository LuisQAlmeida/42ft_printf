#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

/**
 * @file ft_printf.h
 * @brief Public interface and support functions for the maintained ft_printf
 * implementation.
 *
 * The maintained implementation writes formatted output to standard output
 * and supports the conversion specifiers:
 *
 * @code
 * %c %s %p %d %i %u %x %X %%
 * @endcode
 *
 * Formatting flags, field width, precision, length modifiers, and
 * floating-point conversions are outside the maintained project scope.
 */

/**
 * @brief Writes formatted output to standard output.
 *
 * Traverses the format string and writes literal characters directly.
 * Supported conversion specifiers consume the corresponding variadic
 * arguments and are dispatched through ft_print_format().
 *
 * A NULL format string is rejected without producing formatted output.
 *
 * If an unsupported conversion specifier is encountered, the implementation
 * writes "Error: Invalid Format\n" to standard output and stops processing.
 *
 * @param format Format string containing literal text and supported
 * conversion specifiers.
 * @param ... Values consumed according to the conversion specifiers present
 * in format.
 *
 * @return Number of characters counted as written for a successfully
 * processed format.
 * @retval -1 If format is NULL.
 * @retval -2 If an unsupported conversion specifier is encountered.
 */
int	ft_printf(const char *format, ...);

/**
 * @brief Writes one character to standard output.
 *
 * @param c Character to write.
 * @return Result returned by write() for the single-byte output operation.
 */
int	ft_putchar_a(char c);

/**
 * @brief Writes a null-terminated string to standard output.
 *
 * A NULL pointer is represented by the literal string "(null)".
 *
 * For a non-NULL string, the implementation writes each character
 * individually and returns the string length counted by the function.
 *
 * @param s String to write, or NULL.
 * @return Number of characters counted as written. For a NULL string, returns
 * the result of writing the six-byte "(null)" representation.
 */
int	ft_putstr_a(const char *s);

/**
 * @brief Writes an unsigned numeric value using the requested numeric format.
 *
 * The maintained callers use:
 *
 * @code
 * 'd' or 'u'  decimal
 * 'x'         lowercase hexadecimal
 * 'X'         uppercase hexadecimal
 * @endcode
 *
 * @param num Unsigned value to format.
 * @param c Numeric format selector.
 * @return Number of characters counted as written.
 */
int	ft_putnum(unsigned long long num, char c);

/**
 * @brief Dispatches one supported conversion specifier.
 *
 * Supported specifiers are:
 *
 * @code
 * c s d i u x X p %
 * @endcode
 *
 * The function consumes an argument from arg_list when required by the
 * selected conversion. A NULL pointer passed to %p is rendered as "(nil)";
 * non-NULL pointers are rendered with a "0x" prefix and lowercase
 * hexadecimal digits.
 *
 * @param arg_list Active variadic argument list.
 * @param c Conversion specifier to process.
 * @return Number of characters counted as written for the conversion.
 * Returns 0 when c is not handled by this dispatcher.
 */
int	ft_print_format(va_list arg_list, char c);

#endif
