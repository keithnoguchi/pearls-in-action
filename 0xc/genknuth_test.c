/* SPDX-License-Identifier: GPL-2.0 */
#include <stdio.h>

#include "genknuth.h"

int test_genknuth(int *test_nr)
{
	const struct test {
		const char	*name;
		int		m;
		int		n;
		int		want[10];
	} tests[] = {
		{
			.name	= "m=1, n=1",
			.m	= 1,
			.n	= 1,
			.want	= {0},
		},
		{
			.name	= "m=2, n=2",
			.m	= 2,
			.n	= 2,
			.want	= {0, 1},
		},
		{
			.name	= "m=3, n=3",
			.m	= 3,
			.n	= 3,
			.want	= {0, 1, 2},
		},
		{
			.name	= "m=4, n=4",
			.m	= 4,
			.n	= 4,
			.want	= {0, 1, 2, 3},
		},
		{
			.name	= "m=5, n=5",
			.m	= 5,
			.n	= 5,
			.want	= {0, 1, 2, 3, 4},
		},
		{
			.name	= "m=6, n=6",
			.m	= 6,
			.n	= 6,
			.want	= {0, 1, 2, 3, 4, 5},
		},
		{
			.name	= "m=7, n=7",
			.m	= 7,
			.n	= 7,
			.want	= {0, 1, 2, 3, 4, 5, 6},
		},
		{
			.name	= "m=8, n=8",
			.m	= 8,
			.n	= 8,
			.want	= {0, 1, 2, 3, 4, 5, 6, 7},
		},
		{
			.name	= "m=9, n=9",
			.m	= 9,
			.n	= 9,
			.want	= {0, 1, 2, 3, 4, 5, 6, 7, 8},
		},
		{
			.name	= "m=10, n=10",
			.m	= 10,
			.n	= 10,
			.want	= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int got[10];
		int i;

		printf("%3d) %-21s: %-35s", ++(*test_nr), __FUNCTION__, t->name);

		genknuth(t->m, t->n, got);
		for (i = 0; i < t->m; i++)
			if (got[i] != t->want[i]) {
				printf("FAIL: got[%d]=%d, want[%d]=%d\n",
				       i, got[i], i, t->want[i]);
				fail++;
				continue;
			}
		puts("PASS");
	}
	return fail;
}
