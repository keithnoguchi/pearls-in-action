/* SPDX-License-Identifier: GPL-2.0 */

/* sizeof(x)/sizeof(int) == 1000 */
int find_first1000(int t, const int x[])
{
	int l, i, p;

	i = 512;
	l = -1;
	if (x[511] < t)
		l = 1000-512;
	while (i != 1) {
		i /= 2;
		if (x[l+i] < t)
			l += i;
	}
	p = l+1;
	if (p == 1000 || x[p] != t)
		p = -1;

	return p;
}
