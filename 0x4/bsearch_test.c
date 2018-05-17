/* SDPX-License-Identifier: GPL-2.0 */

#include <stdio.h>

#include "bsearch.h"

static void print_title(int *nr, const char *suite_name, const char *test_name)
{
	printf("%3d) %-40s: %-30s", ++(*nr), suite_name, test_name);
}

int test_bsearch_0(int *i)
{
	const struct test {
		const char	*name;
		const int	array[1];
		int		value;
		int		want;
	} tests[] = {
		{
			.name	= "no entry",
			.array	= {},
			.value	= 10,
			.want	= -1,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int got;

		print_title(i, "test_bsearch_0", t->name);
		got = bsearch(t->value, t->array, 0);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_bsearch_2(int *i)
{
	const struct test {
		const char	*name;
		const int	array[2];
		int		value;
		int		want;
	} tests[] = {
		{
			.name	= "first entry",
			.array	= {0, 1},
			.value	= 0,
			.want	= 0,
		},
		{
			.name	= "last entry",
			.array	= {0, 1},
			.value	= 1,
			.want	= 1,
		},
		{
			.name	= "no entry",
			.array	= {0, 1},
			.value	= 10,
			.want	= -1,
		},
		{
			.name	= "first entry",
			.array	= {0, 2},
			.value	= 0,
			.want	= 0,
		},
		{
			.name	= "last entry",
			.array	= {0, 2},
			.value	= 2,
			.want	= 1,
		},
		{
			.name	= "no entry",
			.array	= {0, 2},
			.value	= 20,
			.want	= -1,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int got;

		print_title(i, "test_bsearch_2", t->name);
		got = bsearch(t->value, t->array, 2);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_bsearch_3(int *i)
{
	const struct test {
		const char	*name;
		const int	array[3];
		int		value;
		int		want;
	} tests[] = {
		{
			.name	= "first entry",
			.array	= {0, 1, 2},
			.value	= 0,
			.want	= 0,
		},
		{
			.name	= "last entry",
			.array	= {0, 1, 2},
			.value	= 2,
			.want	= 2,
		},
		{
			.name	= "middle entry",
			.array	= {0, 1, 2},
			.value	= 1,
			.want	= 1,
		},
		{
			.name	= "no entry",
			.array	= {0, 1, 2},
			.value	= 10,
			.want	= -1,
		},
		{
			.name	= "first entry",
			.array	= {0, 2, 4},
			.value	= 0,
			.want	= 0,
		},
		{
			.name	= "last entry",
			.array	= {0, 2, 4},
			.value	= 4,
			.want	= 2,
		},
		{
			.name	= "middle entry",
			.array	= {0, 2, 4},
			.value	= 2,
			.want	= 1,
		},
		{
			.name	= "no entry",
			.array	= {0, 2, 4},
			.value	= 20,
			.want	= -1,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int got;

		print_title(i, "test_bsearch_3", t->name);
		got = bsearch(t->value, t->array, 3);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_bsearch_10(int *i)
{
	const struct test {
		const char	*name;
		const int	array[10];
		int		value;
		int		want;
	} tests[] = {
		{
			.name	= "first entry",
			.array	= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
			.value	= 0,
			.want	= 0,
		},
		{
			.name	= "last entry",
			.array	= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
			.value	= 9,
			.want	= 9,
		},
		{
			.name	= "middle entry",
			.array	= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
			.value	= 5,
			.want	= 5,
		},
		{
			.name	= "no entry",
			.array	= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
			.value	= 10,
			.want	= -1,
		},
		{
			.name	= "first entry",
			.array	= {0, 2, 4, 6, 8, 10, 12, 14, 16, 18},
			.value	= 0,
			.want	= 0,
		},
		{
			.name	= "last entry",
			.array	= {0, 2, 4, 6, 8, 10, 12, 14, 16, 18},
			.value	= 18,
			.want	= 9,
		},
		{
			.name	= "middle entry",
			.array	= {0, 2, 4, 6, 8, 10, 12, 14, 16, 18},
			.value	= 10,
			.want	= 5,
		},
		{
			.name	= "no entry",
			.array	= {0, 2, 4, 6, 8, 10, 12, 14, 16, 18},
			.value	= 20,
			.want	= -1,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int got;

		print_title(i, "test_bsearch_10", t->name);
		got = bsearch(t->value, t->array, 10);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

static void generate_array(int array[], int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
		array[i] = i*x;
}

int test_bsearch_1024(int *i)
{
	const struct test {
		const char	*name;
		int		multi;
		int		value;
		int		want;
	} tests[] = {
		{
			.name	= "first entry",
			.multi	= 1,
			.value	= 0,
			.want	= 0,
		},
		{
			.name	= "last entry",
			.multi	= 1,
			.value	= 1023,
			.want	= 1023,
		},
		{
			.name	= "middle entry",
			.multi	= 1,
			.value	= 511,
			.want	= 511,
		},
		{
			.name	= "no entry",
			.multi	= 1,
			.value	= 1024,
			.want	= -1,
		},
		{
			.name	= "first entry",
			.multi	= 2,
			.value	= 0,
			.want	= 0,
		},
		{
			.name	= "last entry",
			.multi	= 2,
			.value	= 2046,
			.want	= 1023,
		},
		{
			.name	= "middle entry",
			.multi	= 2,
			.value	= 1022,
			.want	= 511,
		},
		{
			.name	= "no entry",
			.multi	= 2,
			.value	= 2048,
			.want	= -1,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;
	int array[1024];

	for (t = tests; t->name; t++) {
		int got;

		print_title(i, "test_bsearch_1024", t->name);
		generate_array(array, 1024, t->multi);
		got = bsearch(t->value, array, 1024);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_bsearch_with_try_0(int *i)
{
	const struct test {
		const char	*name;
		const int	array[1];
		int		value;
		int		want;
		int		try;
	} tests[] = {
		{
			.name	= "no entry",
			.array	= {},
			.value	= 10,
			.want	= -1,
			.try	= 0,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int got;
		int try;

		print_title(i, "test_bsearch_with_try_0", t->name);
		got = bsearch_with_try(t->value, t->array, 0, &try);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else if (try != t->try) {
			printf("FAIL: try(%d)!=%d\n", try, t->try);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_bsearch_with_try_2(int *i)
{
	const struct test {
		const char	*name;
		const int	array[2];
		int		value;
		int		want;
		int		try;
	} tests[] = {
		{
			.name	= "first entry",
			.array	= {0, 1},
			.value	= 0,
			.want	= 0,
			.try	= 1,
		},
		{
			.name	= "last entry",
			.array	= {0, 1},
			.value	= 1,
			.want	= 1,
			.try	= 2,
		},
		{
			.name	= "no entry",
			.array	= {0, 1},
			.value	= 10,
			.want	= -1,
			.try	= 2,
		},
		{
			.name	= "first entry",
			.array	= {0, 2},
			.value	= 0,
			.want	= 0,
			.try	= 1,
		},
		{
			.name	= "last entry",
			.array	= {0, 2},
			.value	= 2,
			.want	= 1,
			.try	= 2,
		},
		{
			.name	= "no entry",
			.array	= {0, 2},
			.value	= 20,
			.want	= -1,
			.try	= 2,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int got;
		int try;

		print_title(i, "test_bsearch_with_try_2", t->name);
		got = bsearch_with_try(t->value, t->array, 2, &try);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else if (try != t->try) {
			printf("FAIL: try(%d)!=%d\n", try, t->try);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_bsearch_with_try_3(int *i)
{
	const struct test {
		const char	*name;
		const int	array[3];
		int		value;
		int		want;
		int		try;
	} tests[] = {
		{
			.name	= "first entry",
			.array	= {0, 1, 2},
			.value	= 0,
			.want	= 0,
			.try	= 2,
		},
		{
			.name	= "last entry",
			.array	= {0, 1, 2},
			.value	= 2,
			.want	= 2,
			.try	= 2,
		},
		{
			.name	= "middle entry",
			.array	= {0, 1, 2},
			.value	= 1,
			.want	= 1,
			.try	= 1,
		},
		{
			.name	= "no entry",
			.array	= {0, 1, 2},
			.value	= 10,
			.want	= -1,
			.try	= 2,
		},
		{
			.name	= "first entry",
			.array	= {0, 2, 4},
			.value	= 0,
			.want	= 0,
			.try	= 2,
		},
		{
			.name	= "last entry",
			.array	= {0, 2, 4},
			.value	= 4,
			.want	= 2,
			.try	= 2,
		},
		{
			.name	= "middle entry",
			.array	= {0, 2, 4},
			.value	= 2,
			.want	= 1,
			.try	= 1,
		},
		{
			.name	= "no entry",
			.array	= {0, 2, 4},
			.value	= 20,
			.want	= -1,
			.try	= 2,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int got;
		int try;

		print_title(i, "test_bsearch_with_try_3", t->name);
		got = bsearch_with_try(t->value, t->array, 3, &try);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else if (try != t->try) {
			printf("FAIL: try(%d)!=%d\n", try, t->try);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_bsearch_with_try_10(int *i)
{
	const struct test {
		const char	*name;
		const int	array[10];
		int		value;
		int		want;
		int		try;
	} tests[] = {
		{
			.name	= "first entry",
			.array	= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
			.value	= 0,
			.want	= 0,
			.try	= 3,
		},
		{
			.name	= "last entry",
			.array	= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
			.value	= 9,
			.want	= 9,
			.try	= 4,
		},
		{
			.name	= "middle entry",
			.array	= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
			.value	= 5,
			.want	= 5,
			.try	= 3,
		},
		{
			.name	= "no entry",
			.array	= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
			.value	= 10,
			.want	= -1,
			.try	= 4,
		},
		{
			.name	= "first entry",
			.array	= {0, 2, 4, 6, 8, 10, 12, 14, 16, 18},
			.value	= 0,
			.want	= 0,
			.try	= 3,
		},
		{
			.name	= "last entry",
			.array	= {0, 2, 4, 6, 8, 10, 12, 14, 16, 18},
			.value	= 18,
			.want	= 9,
			.try	= 4,
		},
		{
			.name	= "middle entry",
			.array	= {0, 2, 4, 6, 8, 10, 12, 14, 16, 18},
			.value	= 10,
			.want	= 5,
			.try	= 3,
		},
		{
			.name	= "no entry",
			.array	= {0, 2, 4, 6, 8, 10, 12, 14, 16, 18},
			.value	= 20,
			.want	= -1,
			.try	= 4,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int got;
		int try;

		print_title(i, "test_bsearch_with_try_10", t->name);
		got = bsearch_with_try(t->value, t->array, 10, &try);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else if (try != t->try) {
			printf("FAIL: try(%d)!=%d\n", try, t->try);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_bsearch_with_try_1024(int *i)
{
	const struct test {
		const char	*name;
		int		multi;
		int		value;
		int		want;
		int		try;
	} tests[] = {
		{
			.name	= "first entry",
			.multi	= 1,
			.value	= 0,
			.want	= 0,
			.try	= 10,
		},
		{
			.name	= "last entry",
			.multi	= 1,
			.value	= 1023,
			.want	= 1023,
			.try	= 11,
		},
		{
			.name	= "middle entry",
			.multi	= 1,
			.value	= 511,
			.want	= 511,
			.try	= 1,
		},
		{
			.name	= "no entry",
			.multi	= 1,
			.value	= 1024,
			.want	= -1,
			.try	= 11,
		},
		{
			.name	= "first entry",
			.multi	= 2,
			.value	= 0,
			.want	= 0,
			.try	= 10,
		},
		{
			.name	= "last entry",
			.multi	= 2,
			.value	= 2046,
			.want	= 1023,
			.try	= 11,
		},
		{
			.name	= "middle entry",
			.multi	= 2,
			.value	= 1022,
			.want	= 511,
			.try	= 1,
		},
		{
			.name	= "no entry",
			.multi	= 2,
			.value	= 2048,
			.want	= -1,
			.try	= 11,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;
	int array[1024];

	for (t = tests; t->name; t++) {
		int got;
		int try;

		print_title(i, "test_bsearch_with_try_1024", t->name);
		generate_array(array, 1024, t->multi);
		got = bsearch_with_try(t->value, array, 1024, &try);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else if (try != t->try) {
			printf("FAIL: try(%d)!=%d\n", try, t->try);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_bsearch_recursive_0(int *i)
{
	const struct test {
		const char	*name;
		const int	array[1];
		int		value;
		int		want;
	} tests[] = {
		{
			.name	= "no entry",
			.array	= {},
			.value	= 10,
			.want	= -1,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int got;

		print_title(i, "test_bsearch_recursive_0", t->name);
		got = bsearch_recursive(t->value, t->array, 0);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_bsearch_recursive_2(int *i)
{
	const struct test {
		const char	*name;
		const int	array[2];
		int		value;
		int		want;
	} tests[] = {
		{
			.name	= "first entry",
			.array	= {0, 1},
			.value	= 0,
			.want	= 0,
		},
		{
			.name	= "last entry",
			.array	= {0, 1},
			.value	= 1,
			.want	= 1,
		},
		{
			.name	= "no entry",
			.array	= {0, 1},
			.value	= 10,
			.want	= -1,
		},
		{
			.name	= "first entry",
			.array	= {0, 2},
			.value	= 0,
			.want	= 0,
		},
		{
			.name	= "last entry",
			.array	= {0, 2},
			.value	= 2,
			.want	= 1,
		},
		{
			.name	= "no entry",
			.array	= {0, 2},
			.value	= 20,
			.want	= -1,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int got;

		print_title(i, "test_bsearch_recursive_2", t->name);
		got = bsearch_recursive(t->value, t->array, 2);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_bsearch_recursive_3(int *i)
{
	const struct test {
		const char	*name;
		const int	array[3];
		int		value;
		int		want;
	} tests[] = {
		{
			.name	= "first entry",
			.array	= {0, 1, 2},
			.value	= 0,
			.want	= 0,
		},
		{
			.name	= "last entry",
			.array	= {0, 1, 2},
			.value	= 2,
			.want	= 2,
		},
		{
			.name	= "middle entry",
			.array	= {0, 1, 2},
			.value	= 1,
			.want	= 1,
		},
		{
			.name	= "no entry",
			.array	= {0, 1, 2},
			.value	= 10,
			.want	= -1,
		},
		{
			.name	= "first entry",
			.array	= {0, 2, 4},
			.value	= 0,
			.want	= 0,
		},
		{
			.name	= "last entry",
			.array	= {0, 2, 4},
			.value	= 4,
			.want	= 2,
		},
		{
			.name	= "middle entry",
			.array	= {0, 2, 4},
			.value	= 2,
			.want	= 1,
		},
		{
			.name	= "no entry",
			.array	= {0, 2, 4},
			.value	= 20,
			.want	= -1,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int got;

		print_title(i, "test_bsearch_recursive_3", t->name);
		got = bsearch_recursive(t->value, t->array, 3);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_bsearch_recursive_10(int *i)
{
	const struct test {
		const char	*name;
		const int	array[10];
		int		value;
		int		want;
	} tests[] = {
		{
			.name	= "first entry",
			.array	= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
			.value	= 0,
			.want	= 0,
		},
		{
			.name	= "last entry",
			.array	= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
			.value	= 9,
			.want	= 9,
		},
		{
			.name	= "middle entry",
			.array	= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
			.value	= 5,
			.want	= 5,
		},
		{
			.name	= "no entry",
			.array	= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
			.value	= 10,
			.want	= -1,
		},
		{
			.name	= "first entry",
			.array	= {0, 2, 4, 6, 8, 10, 12, 14, 16, 18},
			.value	= 0,
			.want	= 0,
		},
		{
			.name	= "last entry",
			.array	= {0, 2, 4, 6, 8, 10, 12, 14, 16, 18},
			.value	= 18,
			.want	= 9,
		},
		{
			.name	= "middle entry",
			.array	= {0, 2, 4, 6, 8, 10, 12, 14, 16, 18},
			.value	= 10,
			.want	= 5,
		},
		{
			.name	= "no entry",
			.array	= {0, 2, 4, 6, 8, 10, 12, 14, 16, 18},
			.value	= 20,
			.want	= -1,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int got;

		print_title(i, "test_bsearch_recursive_10", t->name);
		got = bsearch_recursive(t->value, t->array, 10);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_bsearch_recursive_1024(int *i)
{
	const struct test {
		const char	*name;
		int		multi;
		int		value;
		int		want;
	} tests[] = {
		{
			.name	= "first entry",
			.multi	= 1,
			.value	= 0,
			.want	= 0,
		},
		{
			.name	= "last entry",
			.multi	= 1,
			.value	= 1023,
			.want	= 1023,
		},
		{
			.name	= "middle entry",
			.multi	= 1,
			.value	= 511,
			.want	= 511,
		},
		{
			.name	= "no entry",
			.multi	= 1,
			.value	= 1024,
			.want	= -1,
		},
		{
			.name	= "first entry",
			.multi	= 2,
			.value	= 0,
			.want	= 0,
		},
		{
			.name	= "last entry",
			.multi	= 2,
			.value	= 2046,
			.want	= 1023,
		},
		{
			.name	= "middle entry",
			.multi	= 2,
			.value	= 1022,
			.want	= 511,
		},
		{
			.name	= "no entry",
			.multi	= 2,
			.value	= 2048,
			.want	= -1,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;
	int array[1024];

	for (t = tests; t->name; t++) {
		int got;

		print_title(i, "test_bsearch_recursive_1024", t->name);
		generate_array(array, 1024, t->multi);
		got = bsearch_recursive(t->value, array, 1024);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_bsearch_recursive_with_try_0(int *i)
{
	const struct test {
		const char	*name;
		const int	array[1];
		int		value;
		int		want;
		int		try;
	} tests[] = {
		{
			.name	= "no entry",
			.array	= {},
			.value	= 10,
			.want	= -1,
			.try	= 0,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int got;
		int try;

		print_title(i, "test_bsearch_recursive_with_try_0", t->name);
		got = bsearch_recursive_with_try(t->value, t->array, 0, &try);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else if (try != t->try) {
			printf("FAIL: try(%d)!=%d\n", try, t->try);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_bsearch_recursive_with_try_2(int *i)
{
	const struct test {
		const char	*name;
		const int	array[2];
		int		value;
		int		want;
		int		try;
	} tests[] = {
		{
			.name	= "first entry",
			.array	= {0, 1},
			.value	= 0,
			.want	= 0,
			.try	= 1,
		},
		{
			.name	= "last entry",
			.array	= {0, 1},
			.value	= 1,
			.want	= 1,
			.try	= 2,
		},
		{
			.name	= "no entry",
			.array	= {0, 1},
			.value	= 10,
			.want	= -1,
			.try	= 2,
		},
		{
			.name	= "first entry",
			.array	= {0, 2},
			.value	= 0,
			.want	= 0,
			.try	= 1,
		},
		{
			.name	= "last entry",
			.array	= {0, 2},
			.value	= 2,
			.want	= 1,
			.try	= 2,
		},
		{
			.name	= "no entry",
			.array	= {0, 2},
			.value	= 20,
			.want	= -1,
			.try	= 2,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int got;
		int try;

		print_title(i, "test_bsearch_recursive_with_try_2", t->name);
		got = bsearch_recursive_with_try(t->value, t->array, 2, &try);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else if (try != t->try) {
			printf("FAIL: try(%d)!=%d\n", try, t->try);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_bsearch_recursive_with_try_3(int *i)
{
	const struct test {
		const char	*name;
		const int	array[3];
		int		value;
		int		want;
		int		try;
	} tests[] = {
		{
			.name	= "first entry",
			.array	= {0, 1, 2},
			.value	= 0,
			.want	= 0,
			.try	= 2,
		},
		{
			.name	= "last entry",
			.array	= {0, 1, 2},
			.value	= 2,
			.want	= 2,
			.try	= 2,
		},
		{
			.name	= "middle entry",
			.array	= {0, 1, 2},
			.value	= 1,
			.want	= 1,
			.try	= 1,
		},
		{
			.name	= "no entry",
			.array	= {0, 1, 2},
			.value	= 10,
			.want	= -1,
			.try	= 2,
		},
		{
			.name	= "first entry",
			.array	= {0, 2, 4},
			.value	= 0,
			.want	= 0,
			.try	= 2,
		},
		{
			.name	= "last entry",
			.array	= {0, 2, 4},
			.value	= 4,
			.want	= 2,
			.try	= 2,
		},
		{
			.name	= "middle entry",
			.array	= {0, 2, 4},
			.value	= 2,
			.want	= 1,
			.try	= 1,
		},
		{
			.name	= "no entry",
			.array	= {0, 2, 4},
			.value	= 20,
			.want	= -1,
			.try	= 2,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int got;
		int try;

		print_title(i, "test_bsearch_recursive_with_try_3", t->name);
		got = bsearch_recursive_with_try(t->value, t->array, 3, &try);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else if (try != t->try) {
			printf("FAIL: try(%d)!=%d\n", try, t->try);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_bsearch_recursive_with_try_10(int *i)
{
	const struct test {
		const char	*name;
		const int	array[10];
		int		value;
		int		want;
		int		try;
	} tests[] = {
		{
			.name	= "first entry",
			.array	= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
			.value	= 0,
			.want	= 0,
			.try	= 3,
		},
		{
			.name	= "last entry",
			.array	= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
			.value	= 9,
			.want	= 9,
			.try	= 4,
		},
		{
			.name	= "middle entry",
			.array	= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
			.value	= 5,
			.want	= 5,
			.try	= 3,
		},
		{
			.name	= "no entry",
			.array	= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
			.value	= 10,
			.want	= -1,
			.try	= 4,
		},
		{
			.name	= "first entry",
			.array	= {0, 2, 4, 6, 8, 10, 12, 14, 16, 18},
			.value	= 0,
			.want	= 0,
			.try	= 3,
		},
		{
			.name	= "last entry",
			.array	= {0, 2, 4, 6, 8, 10, 12, 14, 16, 18},
			.value	= 18,
			.want	= 9,
			.try	= 4,
		},
		{
			.name	= "middle entry",
			.array	= {0, 2, 4, 6, 8, 10, 12, 14, 16, 18},
			.value	= 10,
			.want	= 5,
			.try	= 3,
		},
		{
			.name	= "no entry",
			.array	= {0, 2, 4, 6, 8, 10, 12, 14, 16, 18},
			.value	= 20,
			.want	= -1,
			.try	= 4,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int got;
		int try;

		print_title(i, "test_bsearch_recursive_with_try_10", t->name);
		got = bsearch_recursive_with_try(t->value, t->array, 10, &try);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else if (try != t->try) {
			printf("FAIL: try(%d)!=%d\n", try, t->try);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_bsearch_recursive_with_try_1024(int *i)
{
	const struct test {
		const char	*name;
		int		multi;
		int		value;
		int		want;
		int		try;
	} tests[] = {
		{
			.name	= "first entry",
			.multi	= 1,
			.value	= 0,
			.want	= 0,
			.try	= 10,
		},
		{
			.name	= "last entry",
			.multi	= 1,
			.value	= 1023,
			.want	= 1023,
			.try	= 11,
		},
		{
			.name	= "middle entry",
			.multi	= 1,
			.value	= 511,
			.want	= 511,
			.try	= 1,
		},
		{
			.name	= "no entry",
			.multi	= 1,
			.value	= 1024,
			.want	= -1,
			.try	= 11,
		},
		{
			.name	= "first entry",
			.multi	= 2,
			.value	= 0,
			.want	= 0,
			.try	= 10,
		},
		{
			.name	= "last entry",
			.multi	= 2,
			.value	= 2046,
			.want	= 1023,
			.try	= 11,
		},
		{
			.name	= "middle entry",
			.multi	= 2,
			.value	= 1022,
			.want	= 511,
			.try	= 1,
		},
		{
			.name	= "no entry",
			.multi	= 2,
			.value	= 2048,
			.want	= -1,
			.try	= 11,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;
	int array[1024];

	for (t = tests; t->name; t++) {
		int got;
		int try;

		print_title(i, "test_bsearch_recursive_with_try_1024", t->name);
		generate_array(array, 1024, t->multi);
		got = bsearch_recursive_with_try(t->value, array, 1024, &try);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else if (try != t->try) {
			printf("FAIL: try(%d)!=%d\n", try, t->try);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}
