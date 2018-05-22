/* SPDX-License-Identifier: GPL-2.0 */

#include <assert.h>
#include <stdio.h>

/* 512 <= nr < 1024 */
int find_first1023(int t, const int x[], unsigned int nr)
{
	int l, i, p;

	assert(512 <= nr && nr < 1024);

	i = 512;
	l = -1;
	if (x[511] < t)
		l = nr-512;
	while (i != 1) {
		i /= 2;
		if (x[l+i] < t)
			l += i;
	}
	p = l+1;
	if (p >= nr || x[p] != t)
		p = -1;
	return p;
}
