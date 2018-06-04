/* SPDX-License-Identifier: GPL-2.0 */
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "genknuth.h"

static bool is_sorted(int n, int x[])
{
	int i;

	for (i = 1; i < n; i++)
		if (x[i-1] >= x[i])
			return false;
	return true;
}

int bench_genknuth(int *test_nr)
{
	const struct test {
		const char	*name;
		int		m;
		int		n;
	} tests[] = {
		{
			.name	= "m=1, n=1",
			.m	= 1,
			.n	= 1,
		},
		{
			.name	= "m=1, n=1024",
			.m	= 1,
			.n	= 1024,
		},
		{
			.name	= "m=2, n=1024",
			.m	= 2,
			.n	= 1024,
		},
		{
			.name	= "m=1, n=4096",
			.m	= 1,
			.n	= 4096,
		},
		{
			.name	= "m=2, n=4096",
			.m	= 2,
			.n	= 4096,
		},
		{
			.name	= "m=1, n=8192",
			.m	= 1,
			.n	= 8192,
		},
		{
			.name	= "m=2, n=8192",
			.m	= 2,
			.n	= 8192,
		},
		{
			.name	= "m=1, n=16384",
			.m	= 1,
			.n	= 16384,
		},
		{
			.name	= "m=2, n=16384",
			.m	= 2,
			.n	= 16384,
		},
		{
			.name	= "m=1, n=32768",
			.m	= 1,
			.n	= 32768,
		},
		{
			.name	= "m=2, n=32768",
			.m	= 2,
			.n	= 32768,
		},
		{ /* sentinel */ },
	};
	const struct test *t;
	int fail = 0;
	
	for (t = tests; t->name; t++) {
		double diff;
		clock_t c;
		int *got;

		printf("%3d) %-21s: %-35s", ++(*test_nr), __FUNCTION__,
		       t->name);

		got = malloc(sizeof(int)*t->m);
		if (!got) {
			printf("FAIL: malloc(): %s\n", strerror(errno));
			fail++;
			continue;
		}
		c = clock();
		genknuth(t->m, t->n, got);
		c = clock()-c;
		diff = ((double)c/CLOCKS_PER_SEC);
		if (!is_sorted(t->m, got)) {
			printf("FAIL: not sorted: %9.6fsec\n", diff);
			goto fail;
		}
		free(got);
		printf("PASS: %9.6fsec\n", diff);
		continue;
fail:
		free(got);
		fail++;
	}
	return fail;
}
