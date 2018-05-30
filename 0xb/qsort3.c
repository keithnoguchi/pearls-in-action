/* SPDX-License-Identifier: GPL-2.0 */

#include <time.h>
#include <stdlib.h>

static void swap(int x[], unsigned int a, unsigned int b)
{
	int tmp = x[a];
	x[a] = x[b];
	x[b] = tmp;
}

static void __qsort(int x[], unsigned int l, unsigned int u)
{
	unsigned int i, m;

	if (u-l <= 1)
		return;

	/* pick the random pivot */
	swap(x, l, l+rand()%(u-l));
	m = l;
	for (i = l+1; i < u; i++)
		if (x[i] < x[l]) {
			int tmp = x[++m]; x[m] = x[i]; x[i] = tmp;
		}
	swap(x, l, m);
	__qsort(x, l, m);
	__qsort(x, m+1, u);
}

void qsort3(int x[], unsigned int nr)
{
	srand(time(0));
	__qsort(x, 0, nr);
}
