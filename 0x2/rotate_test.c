/* SDPX-License-Identifier: GPL-2.0 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "rotate.h"

int rotate_test(int *i)
{
	const struct test {
		const char	*name;
		char		*input;
		int		len;
		int		pos;
		const char	*want;
	} tests[] = {
		{
			.name	= "string 'abcdefgh' -> 'abcdefgh'",
			.input	= "abcdefgh",
			.len	= strlen("abcdefgh"),
			.pos	= 0,
			.want	= "abcdefgh",
		},
		{
			.name	= "string 'abcdefgh' -> 'bcdefgha'",
			.input	= "abcdefgh",
			.len	= strlen("abcdefgh"),
			.pos	= 1,
			.want	= "bcdefgha",
		},
		{
			.name	= "string 'abcdefgh' -> 'defghabc'",
			.input	= "abcdefgh",
			.len	= strlen("abcdefgh"),
			.pos	= 3,
			.want	= "defghabc",
		},
		{
			.name	= "string 'abcdefgh' -> 'efghabcd'",
			.input	= "abcdefgh",
			.len	= strlen("abcdefgh"),
			.pos	= 4,
			.want	= "efghabcd",
		},
		{
			.name	= "string 'abcdefgh' -> 'habcdefg'",
			.input	= "abcdefgh",
			.len	= strlen("abcdefgh"),
			.pos	= 7,
			.want	= "habcdefg",
		},
		{
			.name	= "string 'abcdefgh' -> 'abcdefgh'",
			.input	= "abcdefgh",
			.len	= strlen("abcdefgh"),
			.pos	= 8,
			.want	= "abcdefgh",
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		char *input;
		char *got;

		input = malloc(t->len);
		strncpy(input, t->input, t->len);
		printf("%2d) %-70s", ++(*i), t->name);
		got = rotate(input, t->len, t->pos);
		if (!strcmp(got, t->want)) {
			puts("PASS");
		} else {
			printf("FAIL: '%s'!='%s'\n", got, t->want);
			fail++;
		}
	}
	return fail;
}
