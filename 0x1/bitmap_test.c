/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>
#include <assert.h>

#include "bitmap.h"

int bitmap_test(int *i)
{
	const struct test {
		const char	*name;
		int		pos;
	} tests[] = {
		{
			.name	= "min value in the range",
			.pos	= min(),
		},
		{
			.name	= "max value in the range",
			.pos	= max()-1,
		},
		{
			.name	= "middle value set in the range",
			.pos	= (min()+max()-1)/2,
		},
		{ /* sentry */ },
	};
	const struct test *t;

	for (t = tests; t->name; t++) {
		int j;

		printf("%2d) %-70s", ++(*i), t->name);
		init();
		set(t->pos);
		/* make sure it's set */
		assert(is_set(t->pos));
		/* make sure others are not set */
		for (j = min(); j < max(); j++)
			if (j != t->pos)
				assert(!is_set(j));
		puts("PASS");
	}
	return 0;
}
