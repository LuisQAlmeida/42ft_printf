
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	// Character test
	printf("Test: Character\n");
	printf("Character: %c\n", 'A');
	ft_printf("Character: %c\n", 'A');

	// Null string test
	char	*str;
	str = NULL;
	printf("Test: Null string\n");
	printf("This is a null string: %s\n", str);
	ft_printf("This is a null string: %s\n", str);

	// Empty string test
	printf("Test: Empty string\n");
	printf("This is an empty string: %s\n", "");
	ft_printf("This is an empty string: %s\n", "");

	// Percent sign test
	printf("Test: Percent sign\n");
	printf("This is a percent sign: %%\n");
	ft_printf("This is a percent sign: %%\n");

	// Minimum integer test
	printf("Test: Minimum integer\n");
	printf("Minimum integer: %d\n", INT_MIN);
	ft_printf("Minimum integer: %d\n", INT_MIN);

	// Maximum integer test
	printf("Test: Maximum integer\n");
	printf("Maximum integer: %d\n", 2147483647);
	ft_printf("Maximum integer: %d\n", 2147483647);

	// Maximum unsigned integer test
	printf("Test: Maximum unsigned integer\n");
	printf("Maximum unsigned integer: %u\n", 4294967295U);
	ft_printf("Maximum unsigned integer: %u\n", 4294967295U);

	// Hexadecimal lowercase test
	printf("Test: Hexadecimal lowercase\n");
	printf("Hexadecimal lowercase: %x\n", 255);
	ft_printf("Hexadecimal lowercase: %x\n", 255);

	// Hexadecimal uppercase test
	printf("Test: Hexadecimal uppercase\n");
	printf("Hexadecimal uppercase: %X\n", 255);
	ft_printf("Hexadecimal uppercase: %X\n", 255);

	// Null pointer test
	printf("Test: Null pointer\n");
	printf("Null pointer: %p\n", NULL);
	ft_printf("Null pointer: %p\n", NULL);

	// Valid pointer test
	printf("Test: Valid pointer\n");
	int x = 42;
	printf("Valid pointer: %p\n", &x);
	ft_printf("Valid pointer: %p\n", &x);

	// Mixed format test
	printf("Test: Mixed format\n");
	printf("Mixed: %d, %s, %c, %x\n", 42, "hello", 'A', 255);
	ft_printf("Mixed: %d, %s, %c, %x\n", 42, "hello", 'A', 255);

	/*
	// Edge cases with invalid specifiers
	printf("Test: Invalid specifier\n");
	printf("Invalid specifier: %q\n");
	ft_printf("Invalid specifier: %q\n");
	*/

	/*
	printf("Test: Missing specifier\n");
	printf("Missing specifier: %\n");
	ft_printf("Missing specifier: %\n");
	*/

	return (0);
}
