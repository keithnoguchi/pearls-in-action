/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "isort1.h"

static void swap(int x[], int a, int b)
{
	int tmp = x[a];
	x[a] = x[b];
	x[b] = tmp;
}

static void generate_array(int x[], int nr)
{
	int i;

	for (i = 0; i < nr; i++)
		x[i] = i;
}

static void generate_random_array(int x[], int nr)
{
	int i;

	generate_array(x, nr);

	srand(time(0));
	for (i = 0; i < nr/2; i++) {
		int j = rand()%nr;
		swap(x, i, j);
	}
}

static void dump_array(const int x[], int nr)
{
	int i;

	for (i = 0; i < nr; i++) {
		if (!(i&0x7))
			printf("\n"); /* every eight entries */
		printf("%7d ", x[i]);
	}
}

static bool is_sorted(const int x[], int nr)
{
	int i;
	for (i = 1; i < nr; i++)
		if (x[i-1] > x[i])
			return false;
	return true;
}

int test_isort1(int *i)
{
	const struct test {
		const char	*name;
		unsigned int	nr;
	} tests[] = {
		{
			.name	= "zero entry",
			.nr	= 0,
		},
		{
			.name	= "one entry",
			.nr	= 1,
		},
		{
			.name	= "two entries",
			.nr	= 2,
		},
		{
			.name	= "three entries",
			.nr	= 3,
		},
		{
			.name	= "four entries",
			.nr	= 4,
		},
		{
			.name	= "eight entries",
			.nr	= 8,
		},
		{
			.name	= "16 entries",
			.nr	= 16,
		},
		{
			.name	= "32 entries",
			.nr	= 32,
		},
		{
			.name	= "1024 entries",
			.nr	= 1024,
		},
		{
			.name	= "2048 entries",
			.nr	= 2048,
		},
		{
			.name	= "4096 entries",
			.nr	= 4096,
		},
		{
			.name	= "8192 entries",
			.nr	= 8192,
		},
		{
			.name	= "16384 entries",
			.nr	= 16384,
		},
		{
			.name	= "32768 entries",
			.nr	= 32768,
		},
		{
			.name	= "65536 entries",
			.nr	= 65536,
		},
		{
			.name	= "131072 entries",
			.nr	= 131072,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
#define MAX_NR_ENTRIES 1<<20
		int x[MAX_NR_ENTRIES];
#undef MAX_NR_ENTRIES
		double diff;
		clock_t c;

		printf("%3d) %-20s: %-36s", ++(*i), __FUNCTION__, t->name);

		generate_random_array(x, t->nr);
		c = clock();
		isort1(x, t->nr);
		c = clock() - c;
		diff = ((double)c/CLOCKS_PER_SEC);

		if (!is_sorted(x, t->nr)) {
			printf("FAIL: %9.6fsec\n", diff);
			fail++;
			dump_array(x, t->nr);
		} else
			printf("PASS: %9.6fsec\n", diff);
	}
	return fail;
}

int test_isort1_sorted(int *i)
{
	const struct test {
		const char	*name;
		unsigned int	nr;
	} tests[] = {
		{
			.name	= "zero entry",
			.nr	= 0,
		},
		{
			.name	= "one entry",
			.nr	= 1,
		},
		{
			.name	= "two entries",
			.nr	= 2,
		},
		{
			.name	= "three entries",
			.nr	= 3,
		},
		{
			.name	= "four entries",
			.nr	= 4,
		},
		{
			.name	= "eight entries",
			.nr	= 8,
		},
		{
			.name	= "16 entries",
			.nr	= 16,
		},
		{
			.name	= "32 entries",
			.nr	= 32,
		},
		{
			.name	= "1024 entries",
			.nr	= 1024,
		},
		{
			.name	= "2048 entries",
			.nr	= 2048,
		},
		{
			.name	= "4096 entries",
			.nr	= 4096,
		},
		{
			.name	= "8192 entries",
			.nr	= 8192,
		},
		{
			.name	= "16384 entries",
			.nr	= 16384,
		},
		{
			.name	= "32768 entries",
			.nr	= 32768,
		},
		{
			.name	= "65536 entries",
			.nr	= 65536,
		},
		{
			.name	= "131072 entries",
			.nr	= 131072,
		},
		{ /* sentry */ },
	};
	const struct test *t;
	int fail = 0;

	for (t = tests; t->name; t++) {
#define MAX_NR_ENTRIES 1<<20
		int x[MAX_NR_ENTRIES];
#undef MAX_NR_ENTRIES
		double diff;
		clock_t c;

		printf("%3d) %-20s: %-36s", ++(*i), __FUNCTION__, t->name);

		generate_array(x, t->nr);
		c = clock();
		isort1(x, t->nr);
		c = clock() - c;
		diff = ((double)c/CLOCKS_PER_SEC);

		if (!is_sorted(x, t->nr)) {
			printf("FAIL: %9.6fsec\n", diff);
			fail++;
			dump_array(x, t->nr);
		} else
			printf("PASS: %9.6fsec\n", diff);
	}
	return fail;
}
