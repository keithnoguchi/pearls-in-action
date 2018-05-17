/* SDPX-License-Identifier: GPL-2.0 */

#include <stdio.h>

#include "bsearch.h"

int test_bsearch0(int *i)
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

		printf("%2d) %-15s: %-55s", ++(*i), "bsearch0_test", t->name);
		got = bsearch(t->value, t->array, 0);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_bsearch2(int *i)
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

		printf("%2d) %-15s: %-55s", ++(*i), "bsearch2_test", t->name);
		got = bsearch(t->value, t->array, 2);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_bsearch3(int *i)
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

		printf("%2d) %-15s: %-55s", ++(*i), "bsearch3_test", t->name);
		got = bsearch(t->value, t->array, 3);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_bsearch10(int *i)
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

		printf("%2d) %-15s: %-55s", ++(*i), "bsearch10_test", t->name);
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

int test_bsearch1024(int *i)
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

		generate_array(array, 1024, t->multi);
		printf("%2d) %-15s: %-55s", ++(*i), "bsearch10_test", t->name);
		got = bsearch(t->value, array, 1024);
		if (got != t->want) {
			printf("FAIL: %d!=%d\n", got, t->want);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}
