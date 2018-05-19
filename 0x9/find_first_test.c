/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>

#include "find_first.h"

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
