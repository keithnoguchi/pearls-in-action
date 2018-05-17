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

static int __bsearch_recursive(int v, const int a[], int l, int h, int *try)
{
	int m;

	if (l > h)
		return -1; /* base case */

	if (try)
		(*try)++;

	m = (l+h)/2;
	if (v < a[m])
		return __bsearch_recursive(v, a, l, m-1, try);
	else if (v > a[m])
		return __bsearch_recursive(v, a, m+1, h, try);
	else
		return m;
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

int bsearch_recursive(int v, const int a[], int n)
{
	return __bsearch_recursive(v, a, 0, n-1, 0);
}

int bsearch_recursive_with_try(int v, const int a[], int n, int *try)
{
	if (try)
		*try = 0;
	return __bsearch_recursive(v, a, 0, n-1, try);
}
