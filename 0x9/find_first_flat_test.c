/* SPDX-License-Identify: GPL-2.0 */

#include <stdio.h>

#include "find_first_flat.h"

#undef DEBUG

/* duplicate position */
enum dup_pos {
	DUPLICATE_FRONT,
	DUPLICATE_MIDDLE,
	DUPLICATE_BACK,
};

static void dump_array(const int x[], unsigned int nr)
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

static void generate_array(int x[], unsigned int nr, enum dup_pos p, int count)
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

	dump_array(x, nr);
}

int test_find_first_flat_1023(int *i)
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
			.name		= "double entries in the front",
			.dup_pos	= DUPLICATE_FRONT,
			.dup_count	= 2,
			.v		= 0,
			.want		= 0,
		},
		{
			.name		= "triple entries in the front",
			.dup_pos	= DUPLICATE_FRONT,
			.dup_count	= 3,
			.v		= 0,
			.want		= 0,
		},
		{
			.name		= "quad entries in the front",
			.dup_pos	= DUPLICATE_FRONT,
			.dup_count	= 4,
			.v		= 0,
			.want		= 0,
		},
		{
			.name		= "five entries in the front",
			.dup_pos	= DUPLICATE_FRONT,
			.dup_count	= 5,
			.v		= 0,
			.want		= 0,
		},
		{
			.name		= "single entry in the back",
			.dup_pos	= DUPLICATE_BACK,
			.dup_count	= 1,
			.v		= 1023,
			.want		= 1023,
		},
		{
			.name		= "double entries in the back",
			.dup_pos	= DUPLICATE_BACK,
			.dup_count	= 2,
			.v		= 1023,
			.want		= 1022,
		},
		{
			.name		= "triple entries in the back",
			.dup_pos	= DUPLICATE_BACK,
			.dup_count	= 3,
			.v		= 1023,
			.want		= 1021,
		},
		{
			.name		= "quad entries in the back",
			.dup_pos	= DUPLICATE_BACK,
			.dup_count	= 4,
			.v		= 1023,
			.want		= 1020,
		},
		{
			.name		= "five entries in the back",
			.dup_pos	= DUPLICATE_BACK,
			.dup_count	= 5,
			.v		= 1023,
			.want		= 1019,
		},
		{
			.name		= "single entry in the middle",
			.dup_pos	= DUPLICATE_MIDDLE,
			.dup_count	= 1,
			.v		= 511,
			.want		= 511,
		},
		{
			.name		= "double entries in the middle",
			.dup_pos	= DUPLICATE_MIDDLE,
			.dup_count	= 2,
			.v		= 511,
			.want		= 511,
		},
		{
			.name		= "triple entries in the middle",
			.dup_pos	= DUPLICATE_MIDDLE,
			.dup_count	= 3,
			.v		= 511,
			.want		= 510,
		},
		{
			.name		= "quad entries in the middle",
			.dup_pos	= DUPLICATE_MIDDLE,
			.dup_count	= 4,
			.v		= 511,
			.want		= 510,
		},
		{
			.name		= "five entries in the middle",
			.dup_pos	= DUPLICATE_MIDDLE,
			.dup_count	= 5,
			.v		= 511,
			.want		= 509,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int x[1024];
		int nr = sizeof(x)/sizeof(int);
		int got;

		printf("%3d) %-25s: %-45s", ++(*i), "test_find_first_flat",
		       t->name);

		generate_array(x, nr, t->dup_pos, t->dup_count);
		got = find_first_flat(t->v, x, nr);
		if (got != t->want) {
			printf("FAIL: got(%d)!=want(%d)\n", got, t->want);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}
