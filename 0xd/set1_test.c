/* SPDX-License-Identifier: GPL-2.0 */
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "set1.h"

static int test_set1_alloc(int *test_nr)
{
	const struct test {
		const char	*name;
		int		nr;
		int		max;
	} tests[] = {
		{
			.name	= "nr=1, max=1",
			.nr	= 1,
			.max	= 1,
		},
		{
			.name	= "nr=1024, max=1024",
			.nr	= 1024,
			.max	= 1024,
		},
		{
			.name	= "nr=4096, max=4096",
			.nr	= 4096,
			.max	= 4096,
		},
		{
			.name	= "nr=8192, max=8192",
			.nr	= 8192,
			.max	= 8192,
		},
		{
			.name	= "nr=16384, max=16384",
			.nr	= 16384,
			.max	= 16384,
		},
		{
			.name	= "nr=32768, max=32768",
			.nr	= 32768,
			.max	= 32768,
		},
		{
			.name	= "nr=1048575, max=1048575",
			.nr	= 1048575,
			.max	= 1048575,
		},
		{ /* sentinel */ },
	};
	const struct test *t;
	double diff;
	clock_t c;
	int fail = 0;

	for (t = tests; t->name; t++) {
		struct set *s;

		printf("%3d) %-21s: %-35s", ++(*test_nr), __FUNCTION__,
		       t->name);

		c = clock();
		s = alloc_set1(t->nr, t->max);
		c = clock()-c;
		diff = (double)c/CLOCKS_PER_SEC;
		if (!s) {
			printf("FAIL: alloc_set1(m=%d,n=%d): %s: %9.6fsec\n",
			       t->nr, t->max, strerror(errno), diff);
			goto fail;
		}
		if (set_size(s) != 0) {
			printf("FAIL: %ld=set_size()!=0: %9.6fsec\n",
			       set_size(s), diff);
			goto fail;
		}
		set_free(s);
		printf("PASS: %9.6fsec\n", diff);
		continue;
fail:
		if (s)
			set_free(s);
		fail++;
	}
	return fail;
}

static int test_set1_insert(int *test_nr)
{
	const struct test {
		const char	*name;
		int		nr;
		int		max;
		int		insert[128];
		int		want[128];
	} tests[] = {
		{
			.name	= "insert([0, 1))",
			.nr	= 1,
			.max	= 1,
			.insert	= {0},
			.want	= {0},
		},
		{
			.name	= "insert([0, 2))",
			.nr	= 2,
			.max	= 2,
			.insert	= {0, 1},
			.want	= {0, 1},
		},
		{
			.name	= "insert([0, 2)) reverse",
			.nr	= 2,
			.max	= 2,
			.insert	= {1, 0},
			.want	= {0, 1},
		},
		{
			.name	= "insert([0, 3))",
			.nr	= 3,
			.max	= 3,
			.insert	= {0, 1, 2},
			.want	= {0, 1, 2},
		},
		{
			.name	= "insert([0, 3)) reverse",
			.nr	= 3,
			.max	= 3,
			.insert	= {2, 1, 0},
			.want	= {0, 1, 2},
		},
		{ /* sentinel */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		struct set *s;
		double diff;
		clock_t c;
		int *got = NULL;
		int i;

		printf("%3d) %-21s: %-35s", ++(*test_nr), __FUNCTION__,
		       t->name);

		s = alloc_set1(t->nr, t->max);
		if (!s) {
			printf("FAIL: alloc_set1(m=%d,n=%d): %s\n",
			       t->nr, t->max, strerror(errno));
			goto fail;
		}
		c = clock();
		for (i = 0; i < t->nr; i++)
			set_insert(s, t->insert[i]);
		c = clock()-c;
		diff = (double)c/CLOCKS_PER_SEC;
		if (set_size(s) != t->nr) {
			printf("FAIL: %ld=set_size()!=%d\n: %9.6fsec",
			       set_size(s), t->nr, diff);
			goto fail;
		}
		got = malloc(sizeof(int)*(t->nr+1)); /* +1 for sentinel */
		set_report(s, got);
		for (i = 0; got[i] != t->max; i++)
			if (got[i] != t->want[i]) {
				printf("FAIL: got[%d](%d)!=want[%d](%d): %9.6fsec\n",
				       i, got[i], i, t->want[i], diff);
				goto fail;
			}
		free(got);
		set_free(s);
		printf("PASS: %9.6fsec\n", diff);
		continue;
fail:
		if (got)
			free(got);
		if (s)
			set_free(s);
		fail++;
	}
	return fail;
}

int test_set1(int *i)
{
	int fail = 0;

	if (test_set1_alloc(i))
		fail++;
	if (test_set1_insert(i))
		fail++;

	return fail;
}
