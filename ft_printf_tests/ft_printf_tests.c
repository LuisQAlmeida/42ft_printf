
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	char	*str1;
	char	*str2;
	char	*str3;
	int     x1;
	int	i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15;
        
	str1 = NULL;
	str2 = "hello";
	str3 = 0;
	x1 = 42;

	// Instructions/intro:
	printf("\n############################################################\n\n");
	printf("Instructions/intro:\n");
	printf("----> First result corresponds to printf (the original);\n");
	printf("----> Second result corresponds to ft_printf (my function);\n");
	printf("\n############################################################\n");

	// Character test
	printf("\n____________________________________________________________\n");
	printf("Test 1: Character\n");
	i1 = printf("Character: %c\n", 'A');
	printf("%d\n", i1);
	i1 = ft_printf("Character: %c\n", 'A');
	printf("%d\n", i1);

	// Null string test
	printf("\n____________________________________________________________\n");
	printf("Test 2: Null string\n");
	i2 = printf("This is a null string: %s\n", str1);
	printf("%d\n", i2);
	i2 = ft_printf("This is a null string: %s\n", str1);
	printf("%d\n", i2);

	// Empty string test
	printf("\n____________________________________________________________\n");
	printf("Test 3: Empty string\n");
	i3 = printf("This is an empty string: %s\n", "");
	printf("%d\n", i3);
	i3 = ft_printf("This is an empty string: %s\n", "");
	printf("%d\n", i3);

	// Percent sign test
	printf("\n____________________________________________________________\n");
	printf("Test 4: Percent sign\n");
	i4 = printf("This is a percent sign: %%\n");
	printf("%d\n", i4);
	i4 = ft_printf("This is a percent sign: %%\n");
	printf("%d\n", i4);

	// Minimum integer test
	printf("\n____________________________________________________________\n");
	printf("Test 5: Minimum integer\n");
	i5 = printf("Minimum integer: %d\n", INT_MIN);
	printf("%d\n", i5);
	i5 = ft_printf("Minimum integer: %d\n", INT_MIN);
	printf("%d\n", i5);

	// Maximum integer test
	printf("\n____________________________________________________________\n");
	printf("Test 6: Maximum integer\n");
	i6 = printf("Maximum integer: %d\n", INT_MAX);
	printf("%d\n", i6);
	i6 = ft_printf("Maximum integer: %d\n", INT_MAX);
	printf("%d\n", i6);

	// Maximum unsigned integer test
	printf("\n____________________________________________________________\n");
	printf("Test 7: Maximum unsigned integer\n");
	i7 = printf("Maximum unsigned integer: %u\n", UINT_MAX);
	printf("%d\n", i7);
	i7 = ft_printf("Maximum unsigned integer: %u\n", UINT_MAX);
	printf("%d\n", i7);

	// Hexadecimal lowercase test
	printf("\n____________________________________________________________\n");
	printf("Test 8: Hexadecimal lowercase\n");
	i8 = printf("Hexadecimal lowercase: %x\n", 255);
	printf("%d\n", i8);
	i8 = ft_printf("Hexadecimal lowercase: %x\n", 255);
	printf("%d\n", i8);

	// Hexadecimal uppercase test
	printf("\n____________________________________________________________\n");
	printf("Test 9: Hexadecimal uppercase\n");
	i9 = printf("Hexadecimal uppercase: %X\n", 255);
	printf("%d\n", i9);
	i9 = ft_printf("Hexadecimal uppercase: %X\n", 255);
	printf("%d\n", i9);

	// Null pointer test
	printf("\n____________________________________________________________\n");
	printf("Test 10: Null pointer\n");
	i10 = printf("Null pointer: %p\n", NULL);
	printf("%d\n", i10);
	i10 = ft_printf("Null pointer: %p\n", NULL);
	printf("%d\n", i10);

	// Valid pointer test
	printf("\n____________________________________________________________\n");
	printf("Test 11: Valid pointer\n");
	i11 = printf("Valid pointer: %p\n", &x1);
	printf("%d\n", i11);
	i11 = ft_printf("Valid pointer: %p\n", &x1);
	printf("%d\n", i11);

	// Mixed format test
	printf("\n____________________________________________________________\n");
	printf("Test 12: Mixed format\n");
	i12 = printf("Mixed: %d, %s, %c, %x\n", x1, str2, 'A', 255);
	printf("%d\n", i12);
	i12 = ft_printf("Mixed: %d, %s, %c, %x\n", x1, str2, 'A', 255);
	printf("%d\n", i12);

	// Invalid format test 1
        printf("\n____________________________________________________________\n");
        printf("Test 13: Invalid format specifier (%%k)\n");
        i13 = ft_printf("%k");
        printf("\n%d\n", i13);

	// Invalid format test 2
        printf("\n____________________________________________________________\n");
        printf("Test 14: No format specifier (%%\\0)\n");
        i14 = ft_printf("%");
        printf("\n%d\n", i14);

	// NULL format test
        printf("\n____________________________________________________________\n");
        printf("Test 15: NULL format string\n");
        i15 = ft_printf(NULL);
        printf("\n%d\n", i15);

	printf("\n############################################################\n");
	return (0);
}
