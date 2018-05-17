/* SPDX-License-Identifier: GPL-2.0 */

int bsearch(int v, const int a[], int n)
{
	int l, h;

	l = 0, h = n-1;
	while (l <= h) {
		int m = (l+h)/2;

		if (v < a[m])
			h = m-1;
		else if (v > a[m])
			l = m+1;
		else
			return m;
	}
	return -1;
}
