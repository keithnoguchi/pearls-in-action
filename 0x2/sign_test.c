/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>
#include <string.h>

#include "sign.h"

int sign_test(int *i)
{
	const struct test {
		const char	*name;
		const char	*word;
		const char	*want;
	} tests[] = {
		{
			.name	= "pans -> anps",
			.word	= "pans",
			.want	= "anps",
		},
		{
			.name	= "pots -> opst",
			.word	= "pots",
			.want	= "opst",
		},
		{
			.name	= "opt -> opt",
			.word	= "opt",
			.want	= "opt",
		},
		{
			.name	= "snap -> anps",
			.word	= "snap",
			.want	= "anps",
		},
		{
			.name	= "stop -> opst",
			.word	= "stop",
			.want	= "opst",
		},
		{
			.name	= "tops -> opst",
			.word	= "tops",
			.want	= "opst",
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
#define WORDSIZE	100
		char got[WORDSIZE];

		printf("%2d) %-15s: %-55s", ++(*i), "sign_test", t->name);
		sign(t->word, strlen(t->word), got);
		if (strcmp(got, t->want)) {
			fail++;
			puts("FAIL");
		} else
			puts("PASS");
	}
	return fail;
}
