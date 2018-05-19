/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>

#include "find_first.h"

#undef DEBUG

enum dup_type {
	DUPLICATE_FRONT,
	DUPLICATE_MIDDLE,
	DUPLICATE_BACK,
};

static void dump_array(const int x[], int n)
{
#ifdef DEBUG
	int i, width = 20;
	for (i = 0; i < n; i++) {
		printf("%d ", x[i]);
		if ((i % width) == 0)
			printf("\n");
	}
	printf("\n");
#endif /* DEBUG */
}

static void generate_array(int x[], int n, enum dup_type t, int count)
{
	int i, value, start;

	for (i = 0; i < n; i++)
		x[i] = i;
	if (count == 1)
		return;

	switch (t) {
	case DUPLICATE_FRONT:
		value = x[0];
		start = 0;
		break;
	case DUPLICATE_MIDDLE:
		value = x[(n-1)/2];
		start = (n-count)/2;
		break;
	case DUPLICATE_BACK:
		value = x[n-1];
		start = n-count;
		break;
	}
	for (i = 0; i < count; i++)
		x[start+i] = value;
}

int test_find_first_10(int *i)
{
	const struct test {
		const char	*name;
		const int	x[10];
		int		v;
		int		want;
	} tests[] = {
		{
			.name	= "single entry in the front",
			.x	= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
			.v	= 0,
			.want	= 0,
		},
		{
			.name	= "two entries in the front",
			.x	= {0, 0, 2, 3, 4, 5, 6, 7, 8, 9},
			.v	= 0,
			.want	= 0,
		},
		{
			.name	= "three entries in the front",
			.x	= {0, 0, 0, 3, 4, 5, 6, 7, 8, 9},
			.v	= 0,
			.want	= 0,
		},
		{
			.name	= "single entry in the back",
			.x	= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
			.v	= 9,
			.want	= 9,
		},
		{
			.name	= "two entries in the back",
			.x	= {0, 1, 2, 3, 4, 5, 6, 7, 9, 9},
			.v	= 9,
			.want	= 8,
		},
		{
			.name	= "three entries in the back",
			.x	= {0, 1, 2, 3, 4, 5, 6, 9, 9, 9},
			.v	= 9,
			.want	= 7,
		},
		{
			.name	= "single entry in the middle",
			.x	= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
			.v	= 5,
			.want	= 5,
		},
		{
			.name	= "two entries in the middle",
			.x	= {0, 1, 2, 3, 4, 5, 5, 7, 8, 9},
			.v	= 5,
			.want	= 5,
		},
		{
			.name	= "three entries in the middle",
			.x	= {0, 1, 2, 3, 5, 5, 5, 7, 8, 9},
			.v	= 5,
			.want	= 4,
		},
		{ /* sentinel */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int got;

		printf("%3d) %-25s: %-45s", ++(*i), "test_find_first_10",
		       t->name);

		got = find_first(t->v, t->x, 10);
		if (got != t->want) {
			printf("FAIL: got(%d)!=want(%d)\n", got, t->want);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_find_first_1000(int *i)
{
	const struct test {
		const char	*name;
		enum dup_type	dup_type;
		int		dup_count;
		int		v;
		int		want;
	} tests[] = {
		{
			.name		= "single entry in the front",
			.dup_type	= DUPLICATE_FRONT,
			.dup_count	= 1,
			.v		= 0,
			.want		= 0,
		},
		{
			.name		= "two entries in the front",
			.dup_type	= DUPLICATE_FRONT,
			.dup_count	= 2,
			.v		= 0,
			.want		= 0,
		},
		{
			.name		= "three entries in the front",
			.dup_type	= DUPLICATE_FRONT,
			.dup_count	= 3,
			.v		= 0,
			.want		= 0,
		},
		{
			.name	= "single entry in the back",
			.dup_type	= DUPLICATE_BACK,
			.dup_count	= 1,
			.v		= 999,
			.want		= 999,
		},
		{
			.name		= "two entries in the back",
			.dup_type	= DUPLICATE_BACK,
			.dup_count	= 2,
			.v		= 999,
			.want		= 998,
		},
		{
			.name		= "three entries in the back",
			.dup_type	= DUPLICATE_BACK,
			.dup_count	= 3,
			.v		= 999,
			.want		= 997,
		},
		{
			.name		= "single entry in the middle",
			.dup_type	= DUPLICATE_MIDDLE,
			.dup_count	= 1,
			.v		= 499,
			.want		= 499,
		},
		{
			.name		= "two entries in the middle",
			.dup_type	= DUPLICATE_MIDDLE,
			.dup_count	= 2,
			.v		= 499,
			.want		= 499,
		},
		{
			.name		= "three entries in the middle",
			.dup_type	= DUPLICATE_MIDDLE,
			.dup_count	= 3,
			.v		= 499,
			.want		= 498,
		},
		{ /* sentinel */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int x[1000];
		int got;

		printf("%3d) %-25s: %-45s", ++(*i), "test_find_first_1000",
		       t->name);

		generate_array(x, 1000, t->dup_type, t->dup_count);
		dump_array(x, 1000);
		got = find_first(t->v, x, 1000);
		if (got != t->want) {
			printf("FAIL: got(%d)!=want(%d)\n", got, t->want);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}
