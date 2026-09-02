#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "ft_printf.h"

#define CAPTURE_MAX 4096

typedef enum e_test_id
{
	TEST_EMPTY,
	TEST_LITERAL,
	TEST_CHAR_A,
	TEST_CHAR_NUMERIC,
	TEST_CHAR_NUL,
	TEST_STRING,
	TEST_STRING_EMPTY,
	TEST_STRING_SURROUNDED,
	TEST_PERCENT,
	TEST_PERCENT_SURROUNDED,
	TEST_D_ZERO,
	TEST_D_POSITIVE,
	TEST_D_NEGATIVE,
	TEST_D_MIN,
	TEST_D_MAX,
	TEST_I_ZERO,
	TEST_I_POSITIVE,
	TEST_I_NEGATIVE,
	TEST_I_MIN,
	TEST_I_MAX,
	TEST_U_ZERO,
	TEST_U_VALUE,
	TEST_U_MAX,
	TEST_X_ZERO,
	TEST_X_VALUE,
	TEST_X_MAX,
	TEST_UPPER_X_ZERO,
	TEST_UPPER_X_VALUE,
	TEST_UPPER_X_MAX,
	TEST_POINTER_VALID,
	TEST_POINTER_NULL,
	TEST_MIXED,
	TEST_MIXED_ADJACENT,
	TEST_INVALID,
	TEST_DANGLING,
	TEST_NULL_FORMAT
}	t_test_id;

typedef struct s_capture
{
	unsigned char	bytes[CAPTURE_MAX];
	size_t			length;
	int				return_value;
}	t_capture;

typedef struct s_compare_test
{
	const char	*name;
	t_test_id	id;
}	t_compare_test;

static int	g_pointer_value = 42;

static int	reference_call(t_test_id test)
{
	if (test == TEST_EMPTY)
		return (printf("%s", ""));
	if (test == TEST_LITERAL)
		return (printf("literal text"));
	if (test == TEST_CHAR_A)
		return (printf("[%c]", 'A'));
	if (test == TEST_CHAR_NUMERIC)
		return (printf("[%c]", 42));
	if (test == TEST_CHAR_NUL)
		return (printf("A%cB", '\0'));
	if (test == TEST_STRING)
		return (printf("%s", "hello"));
	if (test == TEST_STRING_EMPTY)
		return (printf("[%s]", ""));
	if (test == TEST_STRING_SURROUNDED)
		return (printf("before:%s:after", "hello"));
	if (test == TEST_PERCENT)
		return (printf("%%"));
	if (test == TEST_PERCENT_SURROUNDED)
		return (printf("before:%%:after"));
	if (test == TEST_D_ZERO)
		return (printf("%d", 0));
	if (test == TEST_D_POSITIVE)
		return (printf("%d", 42));
	if (test == TEST_D_NEGATIVE)
		return (printf("%d", -42));
	if (test == TEST_D_MIN)
		return (printf("%d", INT_MIN));
	if (test == TEST_D_MAX)
		return (printf("%d", INT_MAX));
	if (test == TEST_I_ZERO)
		return (printf("%i", 0));
	if (test == TEST_I_POSITIVE)
		return (printf("%i", 42));
	if (test == TEST_I_NEGATIVE)
		return (printf("%i", -42));
	if (test == TEST_I_MIN)
		return (printf("%i", INT_MIN));
	if (test == TEST_I_MAX)
		return (printf("%i", INT_MAX));
	if (test == TEST_U_ZERO)
		return (printf("%u", 0U));
	if (test == TEST_U_VALUE)
		return (printf("%u", 42U));
	if (test == TEST_U_MAX)
		return (printf("%u", UINT_MAX));
	if (test == TEST_X_ZERO)
		return (printf("%x", 0U));
	if (test == TEST_X_VALUE)
		return (printf("%x", 255U));
	if (test == TEST_X_MAX)
		return (printf("%x", UINT_MAX));
	if (test == TEST_UPPER_X_ZERO)
		return (printf("%X", 0U));
	if (test == TEST_UPPER_X_VALUE)
		return (printf("%X", 255U));
	if (test == TEST_UPPER_X_MAX)
		return (printf("%X", UINT_MAX));
	if (test == TEST_POINTER_VALID)
		return (printf("%p", (void *)&g_pointer_value));
	if (test == TEST_POINTER_NULL)
		return (printf("%p", (void *)0));
	if (test == TEST_MIXED)
		return (printf("Mix:%d:%s:%c:%x:%u:%%",
				-42, "hello", 'A', 255U, UINT_MAX));
	if (test == TEST_MIXED_ADJACENT)
		return (printf("%d%s%c%x", 42, "abc", 'Z', 255U));
	return (-1);
}

static int	implementation_call(t_test_id test)
{
	if (test == TEST_EMPTY)
		return (ft_printf(""));
	if (test == TEST_LITERAL)
		return (ft_printf("literal text"));
	if (test == TEST_CHAR_A)
		return (ft_printf("[%c]", 'A'));
	if (test == TEST_CHAR_NUMERIC)
		return (ft_printf("[%c]", 42));
	if (test == TEST_CHAR_NUL)
		return (ft_printf("A%cB", '\0'));
	if (test == TEST_STRING)
		return (ft_printf("%s", "hello"));
	if (test == TEST_STRING_EMPTY)
		return (ft_printf("[%s]", ""));
	if (test == TEST_STRING_SURROUNDED)
		return (ft_printf("before:%s:after", "hello"));
	if (test == TEST_PERCENT)
		return (ft_printf("%%"));
	if (test == TEST_PERCENT_SURROUNDED)
		return (ft_printf("before:%%:after"));
	if (test == TEST_D_ZERO)
		return (ft_printf("%d", 0));
	if (test == TEST_D_POSITIVE)
		return (ft_printf("%d", 42));
	if (test == TEST_D_NEGATIVE)
		return (ft_printf("%d", -42));
	if (test == TEST_D_MIN)
		return (ft_printf("%d", INT_MIN));
	if (test == TEST_D_MAX)
		return (ft_printf("%d", INT_MAX));
	if (test == TEST_I_ZERO)
		return (ft_printf("%i", 0));
	if (test == TEST_I_POSITIVE)
		return (ft_printf("%i", 42));
	if (test == TEST_I_NEGATIVE)
		return (ft_printf("%i", -42));
	if (test == TEST_I_MIN)
		return (ft_printf("%i", INT_MIN));
	if (test == TEST_I_MAX)
		return (ft_printf("%i", INT_MAX));
	if (test == TEST_U_ZERO)
		return (ft_printf("%u", 0U));
	if (test == TEST_U_VALUE)
		return (ft_printf("%u", 42U));
	if (test == TEST_U_MAX)
		return (ft_printf("%u", UINT_MAX));
	if (test == TEST_X_ZERO)
		return (ft_printf("%x", 0U));
	if (test == TEST_X_VALUE)
		return (ft_printf("%x", 255U));
	if (test == TEST_X_MAX)
		return (ft_printf("%x", UINT_MAX));
	if (test == TEST_UPPER_X_ZERO)
		return (ft_printf("%X", 0U));
	if (test == TEST_UPPER_X_VALUE)
		return (ft_printf("%X", 255U));
	if (test == TEST_UPPER_X_MAX)
		return (ft_printf("%X", UINT_MAX));
	if (test == TEST_POINTER_VALID)
		return (ft_printf("%p", (void *)&g_pointer_value));
	if (test == TEST_POINTER_NULL)
		return (ft_printf("%p", (void *)0));
	if (test == TEST_MIXED)
		return (ft_printf("Mix:%d:%s:%c:%x:%u:%%",
				-42, "hello", 'A', 255U, UINT_MAX));
	if (test == TEST_MIXED_ADJACENT)
		return (ft_printf("%d%s%c%x", 42, "abc", 'Z', 255U));
	if (test == TEST_INVALID)
		return (ft_printf("%k"));
	if (test == TEST_DANGLING)
		return (ft_printf("%"));
	if (test == TEST_NULL_FORMAT)
		return (ft_printf(NULL));
	return (-1);
}

static int	read_capture(FILE *stream, t_capture *capture)
{
	long	size;

	if (fseek(stream, 0, SEEK_END) != 0)
		return (-1);
	size = ftell(stream);
	if (size < 0 || size > CAPTURE_MAX)
		return (-1);
	if (fseek(stream, 0, SEEK_SET) != 0)
		return (-1);
	capture->length = (size_t)size;
	if (capture->length == 0)
		return (0);
	if (fread(capture->bytes, 1, capture->length, stream)
		!= capture->length)
		return (-1);
	return (0);
}

static int	capture_stdout(
	int (*call)(t_test_id),
	t_test_id test,
	t_capture *capture)
{
	FILE	*stream;
	int		saved_stdout;
	int		status;

	memset(capture, 0, sizeof(*capture));
	if (fflush(stdout) != 0)
		return (-1);
	stream = tmpfile();
	if (!stream)
		return (-1);
	saved_stdout = dup(STDOUT_FILENO);
	if (saved_stdout < 0)
	{
		fclose(stream);
		return (-1);
	}
	status = -1;
	if (dup2(fileno(stream), STDOUT_FILENO) < 0)
		goto cleanup;
	capture->return_value = call(test);
	if (fflush(stdout) != 0)
		goto restore;
	if (dup2(saved_stdout, STDOUT_FILENO) < 0)
		goto cleanup;
	status = read_capture(stream, capture);
	close(saved_stdout);
	fclose(stream);
	return (status);

restore:
	dup2(saved_stdout, STDOUT_FILENO);
cleanup:
	close(saved_stdout);
	fclose(stream);
	return (-1);
}

static void	print_bytes(const unsigned char *bytes, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		printf("%02x", bytes[i]);
		if (i + 1 < length)
			printf(" ");
		i++;
	}
	printf("\n");
}

static int	report_failure(
	const char *name,
	const t_capture *expected,
	const t_capture *actual)
{
	printf("[FAIL] %s\n", name);
	printf("       expected return: %d\n", expected->return_value);
	printf("       actual return:   %d\n", actual->return_value);
	printf("       expected bytes:  %zu\n", expected->length);
	printf("       actual bytes:    %zu\n", actual->length);
	printf("       expected output: ");
	print_bytes(expected->bytes, expected->length);
	printf("       actual output:   ");
	print_bytes(actual->bytes, actual->length);
	return (1);
}

static int	captures_match(
	const t_capture *expected,
	const t_capture *actual)
{
	if (expected->return_value != actual->return_value)
		return (0);
	if (expected->length != actual->length)
		return (0);
	if (memcmp(expected->bytes, actual->bytes, expected->length) != 0)
		return (0);
	return (1);
}

static int	run_compare_test(const char *name, t_test_id test)
{
	t_capture	expected;
	t_capture	actual;

	if (capture_stdout(reference_call, test, &expected) != 0)
	{
		printf("[FAIL] %s: reference capture failed\n", name);
		return (1);
	}
	if (capture_stdout(implementation_call, test, &actual) != 0)
	{
		printf("[FAIL] %s: ft_printf capture failed\n", name);
		return (1);
	}
	if (!captures_match(&expected, &actual))
		return (report_failure(name, &expected, &actual));
	printf("[PASS] %s\n", name);
	return (0);
}

static int	run_expected_test(
	const char *name,
	t_test_id test,
	const unsigned char *expected_bytes,
	size_t expected_length,
	int expected_return)
{
	t_capture	expected;
	t_capture	actual;

	memset(&expected, 0, sizeof(expected));
	if (expected_length > CAPTURE_MAX)
	{
		printf("[FAIL] %s: expected output exceeds capture capacity\n", name);
		return (1);
	}
	expected.length = expected_length;
	expected.return_value = expected_return;
	if (expected_length > 0)
		memcpy(expected.bytes, expected_bytes, expected_length);
	if (capture_stdout(implementation_call, test, &actual) != 0)
	{
		printf("[FAIL] %s: ft_printf capture failed\n", name);
		return (1);
	}
	if (!captures_match(&expected, &actual))
		return (report_failure(name, &expected, &actual));
	printf("[PASS] %s\n", name);
	return (0);
}

static int	run_reference_tests(void)
{
	static const t_compare_test	tests[] = {
		{"empty format", TEST_EMPTY},
		{"literal text", TEST_LITERAL},
		{"character printable", TEST_CHAR_A},
		{"character numeric value", TEST_CHAR_NUMERIC},
		{"character embedded NUL", TEST_CHAR_NUL},
		{"string", TEST_STRING},
		{"empty string", TEST_STRING_EMPTY},
		{"string with literals", TEST_STRING_SURROUNDED},
		{"percent", TEST_PERCENT},
		{"percent with literals", TEST_PERCENT_SURROUNDED},
		{"%d zero", TEST_D_ZERO},
		{"%d positive", TEST_D_POSITIVE},
		{"%d negative", TEST_D_NEGATIVE},
		{"%d INT_MIN", TEST_D_MIN},
		{"%d INT_MAX", TEST_D_MAX},
		{"%i zero", TEST_I_ZERO},
		{"%i positive", TEST_I_POSITIVE},
		{"%i negative", TEST_I_NEGATIVE},
		{"%i INT_MIN", TEST_I_MIN},
		{"%i INT_MAX", TEST_I_MAX},
		{"%u zero", TEST_U_ZERO},
		{"%u value", TEST_U_VALUE},
		{"%u UINT_MAX", TEST_U_MAX},
		{"%x zero", TEST_X_ZERO},
		{"%x value", TEST_X_VALUE},
		{"%x UINT_MAX", TEST_X_MAX},
		{"%X zero", TEST_UPPER_X_ZERO},
		{"%X value", TEST_UPPER_X_VALUE},
		{"%X UINT_MAX", TEST_UPPER_X_MAX},
		{"valid pointer", TEST_POINTER_VALID},
		{"NULL pointer", TEST_POINTER_NULL},
		{"mixed formatting", TEST_MIXED},
		{"adjacent conversions", TEST_MIXED_ADJACENT}
	};
	size_t	i;
	int		failures;

	i = 0;
	failures = 0;
	while (i < sizeof(tests) / sizeof(tests[0]))
	{
		failures += run_compare_test(tests[i].name, tests[i].id);
		i++;
	}
	return (failures);
}

static int	run_project_specific_tests(void)
{
	static const unsigned char	error_output[] = "Error: Invalid Format\n";
	int							failures;

	failures = 0;
	failures += run_expected_test(
			"invalid conversion",
			TEST_INVALID,
			error_output,
			sizeof(error_output) - 1,
			-2);
	failures += run_expected_test(
			"dangling percent",
			TEST_DANGLING,
			error_output,
			sizeof(error_output) - 1,
			-2);
	failures += run_expected_test(
			"NULL format",
			TEST_NULL_FORMAT,
			NULL,
			0,
			-1);
	return (failures);
}

int	main(void)
{
	int	failures;
	int	total;

	total = 36;
	failures = run_reference_tests();
	failures += run_project_specific_tests();
	printf("\n%d/%d tests passed\n", total - failures, total);
	if (failures != 0)
		return (1);
	return (0);
}
