/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>
#include <assert.h>

#include "bitmap.h"

int main(void)
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
	int j;

	j = 0;
	for (t = tests; t->name; t++) {
		int i;

		printf("%2d) %-70s", ++j, t->name);
		init();
		set(t->pos);
		/* make sure it's set */
		assert(is_set(t->pos));
		/* make sure others are not set */
		for (i = min(); i < max(); i++)
			if (i != t->pos)
				assert(!is_set(i));
		puts("PASS");
	}
}
