/* SPDX-License-Identifier: GPL-2.0 */

#include <time.h>
#include <stdlib.h>

/* returns the sorted m integers out of [0..n) in x */
void genknuth(int m, int n, int x[])
{
	int i, j;

	srandom(time(0));

	j = 0;
	for (i = 0; i < n; i++)
		if (random()%(n-i) < (m-j))
			x[j++] = i;
}
