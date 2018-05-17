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
