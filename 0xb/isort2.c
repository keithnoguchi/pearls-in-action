/* SPDX-License-Identifier: GPL-2.0 */

void isort2(int x[], unsigned int nr)
{
	unsigned int i, j;

	for (i = 1; i < nr; i++)
		for (j = i; j && x[j-1] > x[j]; j--) {
			/* see how much we can get from swap() call */
			int tmp = x[j-1];
			x[j-1] = x[j];
			x[j] = tmp;
		}
}
