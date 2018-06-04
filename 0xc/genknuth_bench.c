/* SPDX-License-Identifier: GPL-2.0 */
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "genknuth.h"

static bool debug = false;

static bool is_sorted(int n, const int x[])
{
	int i;

	for (i = 1; i < n; i++)
		if (x[i-1] >= x[i])
			return false;
	return true;
}

static void dump(int n, const int x[])
{
	int i;

	if (!debug)
		return;

	for (i = 0; i < n; i++) {
		printf("%8d", x[i]);
		if ((i&0x7)==0x7 && i+1 != n)
			puts("");
	}
	puts("");
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
			.name	= "m=4, n=1024",
			.m	= 4,
			.n	= 1024,
		},
		{
			.name	= "m=16, n=1024",
			.m	= 16,
			.n	= 1024,
		},
		{
			.name	= "m=1024, n=1024",
			.m	= 1024,
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
			.name	= "m=4, n=4096",
			.m	= 4,
			.n	= 4096,
		},
		{
			.name	= "m=16, n=4096",
			.m	= 16,
			.n	= 4096,
		},
		{
			.name	= "m=4096, n=4096",
			.m	= 4096,
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
			.name	= "m=4, n=8192",
			.m	= 4,
			.n	= 8192,
		},
		{
			.name	= "m=16, n=8192",
			.m	= 16,
			.n	= 8192,
		},
		{
			.name	= "m=8192, n=8192",
			.m	= 8192,
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
			.name	= "m=4, n=16384",
			.m	= 4,
			.n	= 16384,
		},
		{
			.name	= "m=16, n=16384",
			.m	= 16,
			.n	= 16384,
		},
		{
			.name	= "m=16384, n=16384",
			.m	= 16384,
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
		{
			.name	= "m=4, n=32768",
			.m	= 4,
			.n	= 32768,
		},
		{
			.name	= "m=16, n=32768",
			.m	= 16,
			.n	= 32768,
		},
		{
			.name	= "m=32768, n=32768",
			.m	= 32768,
			.n	= 32768,
		},
		{
			.name	= "m=32768, n=32768",
			.m	= 32768,
			.n	= 32768,
		},
		{
			.name	= "m=1, n=1048575",
			.m	= 1,
			.n	= 1048575,
		},
		{
			.name	= "m=8192, n=1048575",
			.m	= 8192,
			.n	= 1048575,
		},
		{
			.name	= "m=16384, n=1048575",
			.m	= 16384,
			.n	= 1048575,
		},
		{
			.name	= "m=32768, n=1048575",
			.m	= 32768,
			.n	= 1048575,
		},
		{
			.name	= "m=1048575, n=1048575",
			.m	= 1048575,
			.n	= 1048575,
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
		if (got[0] < 0) {
			printf("FAIL: invalid min(%d<0): %9.6fsec\n",
			       got[0], diff);
			goto fail;
		}
		if (got[t->m-1] >= t->n) {
			printf("FAIL: invalid max(%d>=%d): %9.6fsec\n",
			       got[t->m-1], t->n, diff);
			goto fail;
		}
		if (!is_sorted(t->m, got)) {
			printf("FAIL: not sorted: %9.6fsec\n", diff);
			goto fail;
		}
		printf("PASS: %9.6fsec\n", diff);
		dump(t->m, got);
		free(got);
		continue;
fail:
		dump(t->m, got);
		free(got);
		fail++;
	}
	return fail;
}
