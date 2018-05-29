/* SPDX-License-Identifier: GPL-2.0 */

static void swap(int x[], unsigned int a, unsigned int b)
{
	int tmp = x[a];
	x[a] = x[b];
	x[b] = tmp;
}

void isort1(int x[], unsigned int nr)
{
	unsigned int i, j;

	for (i = 1; i < nr; i++)
		for (j = i; j > 0 && x[j-1] > x[j]; j--)
			swap(x, j-1, j);
}
