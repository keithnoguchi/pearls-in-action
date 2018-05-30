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
	int i, j, m;

	if (u-l <= 1)
		return;

	m = l+rand()%(u-l);
	swap(x, l, m);
	i = l+1, j = u-1;
	while (1) {
		int tmp;
		while (i < u && x[i] < x[l])
			i++;
		while (j > l && x[j] > x[l])
			j--;
		if (i >= j)
			break;
		tmp = x[i];
		x[i++] = x[j];
		x[j--] = tmp;
	}
	swap(x, l, j);
	__qsort(x, l, j);
	__qsort(x, j+1, u);
}

void qsort6(int x[], unsigned int nr)
{
	srand(time(0));
	__qsort(x, 0, nr);
}
