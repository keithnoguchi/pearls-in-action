/* SPDX-License-Identifier: GPL-2.0 */

static int __bsearch(int v, const int a[], int n, int *try)
{
	int l, h;

	l = 0, h = n-1;
	while (l <= h) {
		int m = (l+h)/2;

		if (try)
			(*try)++;
		if (v < a[m])
			h = m-1;
		else if (v > a[m])
			l = m+1;
		else
			return m;
	}
	return -1;
}

int bsearch(int v, const int a[], int n)
{
	return __bsearch(v, a, n, 0);
}

int bsearch_with_try(int v, const int a[], int n, int *try)
{
	if (try)
		*try = 0;
	return __bsearch(v, a, n, try);
}
