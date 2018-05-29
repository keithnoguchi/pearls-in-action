/* SPDX-License-Identifier: GPL-2.0 */

void isort3(int x[], unsigned int nr)
{
	unsigned int i, j;

	for (i = 1; i < nr; i++) {
		int tmp = x[i];
		for (j = i; j && x[j-1] > tmp; j--)
			x[j] = x[j-1];
		x[j] = tmp;
	}
}
