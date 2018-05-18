/* SPDX-License-Identifier: GPL-2.0 */

static int max(int a, int b)
{
	return a > b ? a : b;
}

static int max3(int l, int m, int u)
{
	return max(max(l, m), u);
}

static int __max_subtree_logn(const int a[], int l, int u)
{
	int left, right, sum;
	int m;
	int i;

	if (l > u)
		return -1;
	else if (l == u)
		return a[l];

	/* get the middle max */
	m = (l+u)/2;
	left = sum = 0;
	for (i = m; i >= l; i--) {
		sum += a[i];
		left = max(left, sum);
	}
	right = sum = 0;
	for (i = m+1; i <= u; i++) {
		sum += a[i];
		right = max(right, sum);
	}

	return max3(left+right, __max_subtree_logn(a, l, m), __max_subtree_logn(a, m+1, u));
}

int max_subtree_logn(const int a[], int n)
{
	return __max_subtree_logn(a, 0, n-1);
}
