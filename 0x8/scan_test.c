/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>

#include "scan.h"

static int test_max_subtree_n(int *i)
{
	const struct test {
		const char	*name;
		const int	array[10];
		int		want;
	} tests[] = {
		{
			.name	= "31,-41,59,26,-53,58,97,-93,-23,84",
			.array	= {31, -41, 59, 26, -53, 58, 97, -93, -23, 84},
			.want	= 187,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
		int got;

		printf("%3d) %-20s: %-50s", ++(*i), "test_max_subtree_n", t->name);
		got = max_subtree_n(t->array, 10);
		if (got != t->want) {
			printf("FAIL, got(%d)!=want(%d)\n", got, t->want);
			fail++;
		} else
			puts("PASS");
	}
	return fail;
}

int main(void)
{
	int fail = 0;
	int i = 0;
	printf("===============================\n");
	printf("Programming Pearls, Chapter 0x8\n");
	printf("===============================\n");

	if (test_max_subtree_n(&i))
		fail++;

	return fail;
}
