/* SPDX-License-Identifier: GPL-2.0 */
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

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
	int fail = 0;

	for (t = tests; t->name; t++) {
		struct set *s;

		printf("%3d) %-21s: %-35s", ++(*test_nr), __FUNCTION__,
		       t->name);

		s = alloc_set1(t->nr, t->max);
		if (!s) {
			printf("FAIL: alloc_set1(m=%d,n=%d): %s\n",
			       t->nr, t->max, strerror(errno));
			goto fail;
		}
		if (set_size(s) != 0) {
			printf("FAIL: %ld=set_size()!=0\n", set_size(s));
			goto fail;
		}
		set_free(s);
		puts("PASS");
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
			.name	= "insert([1])",
			.nr	= 1,
			.max	= 2,
			.insert	= {1},
			.want	= {1},
		},
		{ /* sentinel */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		struct set *s;
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
		for (i = 0; i < t->nr; i++)
			set_insert(s, t->insert[i]);
		if (set_size(s) != t->nr) {
			printf("FAIL: %ld=set_size()!=%d\n",
			       set_size(s), t->nr);
			goto fail;
		}
		got = malloc(sizeof(int)*t->nr);
		set_report(s, got);
		for (i = 0; i < t->nr; i++)
			if (got[i] != t->want[i]) {
				printf("FAIL: got[%d](%d)!=want[%d](%d)\n",
				       i, got[i], i, t->want[i]);
				goto fail;
			}
		free(got);
		set_free(s);
		puts("PASS");
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
