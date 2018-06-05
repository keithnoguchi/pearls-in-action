/* SPDX-License-Identifier: GPL-2.0 */
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "set1.h"

int test_set1(int *test_nr)
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
		free_set(s);
		puts("PASS");
		continue;
fail:
		if (s)
			free_set(s);
		fail++;
	}
	return fail;
}
