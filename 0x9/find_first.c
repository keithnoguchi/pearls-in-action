/* SPDX-License-Identifier: GPL-2.0 */

int find_first(int v, const int x[], int n)
{
	int l, u;

	l = -1, u = n;
	while (l+1 != u) {
		int m = (l+u)/2;

		if (x[m] < v)
			l = m;
		else
			u = m;
	}

	if (u >= n || x[u] != v)
		return -1;
	return u;
}
