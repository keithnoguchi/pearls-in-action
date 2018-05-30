/* SPDX-License-Identifier: GPL-2.0 */

static void swap(int x[], unsigned int a, unsigned int b)
{
	int tmp = x[a];
	x[a] = x[b];
	x[b] = tmp;
}

static void __qsort(int x[], unsigned int l, unsigned int u)
{
	unsigned int m;
	int tmp;
	int i;

	if (u-l <= 1)
		return;

	m = l;
	for (i = l+1; i < u; i++)
		if (x[i] < x[l]) {
			/* see how much faster than swap() */
			tmp = x[++m]; x[m] = x[i]; x[i] = tmp;
		}
	swap(x, l, m);
	__qsort(x, l, m);
	__qsort(x, m+1, u);

}

void qsort2(int x[], unsigned int nr)
{
	__qsort(x, 0, nr);
}
