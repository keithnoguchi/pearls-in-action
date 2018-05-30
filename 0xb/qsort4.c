/* SPDX-License-Identifier: GPL-2.0 */

static void swap(int x[], unsigned int a, unsigned int b)
{
	int tmp = x[a];
	x[a] = x[b];
	x[b] = tmp;
}

static void __qsort(int x[], unsigned int l, unsigned int u)
{
	int i, j;

	if (u-l <= 1)
		return;

	i = l+1, j = u-1;
	while (1) {
		while (i < u && x[i] < x[l])
			i++;
		while (j > l && x[j] > x[l])
			j--;
		if (i >= j)
			break;
		swap(x, i++, j--);
	}
	swap(x, l, j);
	__qsort(x, l, j);
	__qsort(x, j+1, u);
}

void qsort4(int x[], unsigned int nr)
{
	__qsort(x, 0, nr);
}
