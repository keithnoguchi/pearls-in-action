/* SPDX-License-Identifier: GPL-2.0 */

static inline int max(int a, int b)
{
	return a > b ? a : b;
}

int max_subtree_n(const int a[], int n)
{
	int sofar;
	int curr;
	int i;

	/* assumes we have at least one positive entry */
	sofar = curr = 0;
	for (i = 0; i < n; i++) {
		curr = max(curr+a[i], 0);
		sofar = max(sofar, curr);
	}
	return sofar;
}
