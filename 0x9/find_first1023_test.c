/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>

#include "find_first1023.h"

#undef DEBUG

/* duplicate position */
enum dup_pos {
	DUPLICATE_FRONT,
	DUPLICATE_MIDDLE,
	DUPLICATE_BACK,
};

static void dump_array1023(const int x[], unsigned int nr)
{
#ifdef DEBUG
	int i, width = 20;
	for (i = 0; i < nr; i++) {
		printf("%d ", x[i]);
		if ((i % width) == 0)
			printf("\n");
	}
	printf("\n");
#endif /* DEBUG */
}

static void generate_array1023(int x[], unsigned int nr, enum dup_pos p, int count)
{
	int i, value, start;

	for (i = 0; i < nr; i++)
		x[i] = i;

	/* create duplicate */
	switch (p) {
	case DUPLICATE_FRONT:
		value = x[0];
		start = 0;
		break;
	case DUPLICATE_MIDDLE:
		value = x[(nr-1)/2];
		start = (nr-count)/2;
		break;
	case DUPLICATE_BACK:
		value = x[nr-1];
		start = nr-count;
		break;
	}
	for (i = 0; i < count; i++)
		x[start+i] = value;

	dump_array1023(x, nr);
}

int test_find_first1023_512(int *i)
{
	const struct test {
		const char	*name;
		enum dup_pos	dup_pos;
		int		dup_count;
		int		v;
		int		want;
	} tests[] = {
		{
			.name		= "single entry in the front",
			.dup_pos	= DUPLICATE_FRONT,
			.dup_count	= 1,
			.v		= 0,
			.want		= 0,
		},
		{
			.name		= "two entries in the front",
			.dup_pos	= DUPLICATE_FRONT,
			.dup_count	= 2,
			.v		= 0,
			.want		= 0,
		},
		{
			.name		= "three entries in the front",
			.dup_pos	= DUPLICATE_FRONT,
			.dup_count	= 3,
			.v		= 0,
			.want		= 0,
		},
		{
			.name		= "single entry in the back",
			.dup_pos	= DUPLICATE_BACK,
			.dup_count	= 1,
			.v		= 511,
			.want		= 511,
		},
		{
			.name		= "two entries in the back",
			.dup_pos	= DUPLICATE_BACK,
			.dup_count	= 2,
			.v		= 511,
			.want		= 510,
		},
		{
			.name		= "three entries in the back",
			.dup_pos	= DUPLICATE_BACK,
			.dup_count	= 3,
			.v		= 511,
			.want		= 509,
		},
		{
			.name		= "single entry in the middle",
			.dup_pos	= DUPLICATE_MIDDLE,
			.dup_count	= 1,
			.v		= 255,
			.want		= 255,
		},
		{
			.name		= "two entries in the middle",
			.dup_pos	= DUPLICATE_MIDDLE,
			.dup_count	= 2,
			.v		= 255,
			.want		= 255,
		},
		{
			.name		= "three entries in the middle",
			.dup_pos	= DUPLICATE_MIDDLE,
			.dup_count	= 3,
			.v		= 255,
			.want		= 254,
		},
		{ /* sentinel */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int x[512];
		int got;

		printf("%3d) %-25s: %-45s", ++(*i), "test_find_first1023_512",
		       t->name);

		generate_array1023(x, 512, t->dup_pos, t->dup_count);
		got = find_first1023(t->v, x, 512);
		if (got != t->want) {
			printf("FAIL: got(%d)!=want(%d)\n", got, t->want);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int test_find_first1023_1000(int *i)
{
	const struct test {
		const char	*name;
		enum dup_pos	dup_pos;
		int		dup_count;
		int		v;
		int		want;
	} tests[] = {
		{
			.name		= "single entry in the front",
			.dup_pos	= DUPLICATE_FRONT,
			.dup_count	= 1,
			.v		= 0,
			.want		= 0,
		},
		{
			.name		= "two entries in the front",
			.dup_pos	= DUPLICATE_FRONT,
			.dup_count	= 2,
			.v		= 0,
			.want		= 0,
		},
		{
			.name		= "three entries in the front",
			.dup_pos	= DUPLICATE_FRONT,
			.dup_count	= 3,
			.v		= 0,
			.want		= 0,
		},
		{
			.name		= "single entry in the back",
			.dup_pos	= DUPLICATE_BACK,
			.dup_count	= 1,
			.v		= 999,
			.want		= 999,
		},
		{
			.name		= "two entries in the back",
			.dup_pos	= DUPLICATE_BACK,
			.dup_count	= 2,
			.v		= 999,
			.want		= 998,
		},
		{
			.name		= "three entries in the back",
			.dup_pos	= DUPLICATE_BACK,
			.dup_count	= 3,
			.v		= 999,
			.want		= 997,
		},
		{
			.name		= "single entry in the middle",
			.dup_pos	= DUPLICATE_MIDDLE,
			.dup_count	= 1,
			.v		= 499,
			.want		= 499,
		},
		{
			.name		= "two entries in the middle",
			.dup_pos	= DUPLICATE_MIDDLE,
			.dup_count	= 2,
			.v		= 499,
			.want		= 499,
		},
		{
			.name		= "three entries in the middle",
			.dup_pos	= DUPLICATE_MIDDLE,
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

		printf("%3d) %-25s: %-45s", ++(*i), "test_find_first1023_1000",
		       t->name);

		generate_array1023(x, 1000, t->dup_pos, t->dup_count);
		got = find_first1023(t->v, x, 1000);
		if (got != t->want) {
			printf("FAIL: got(%d)!=want(%d)\n", got, t->want);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}
