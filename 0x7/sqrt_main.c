/* SPDX-License-Identifier: GPL-2.0 */

#include <math.h>
#include <stdio.h>

int main(void)
{
	double sum = 0.0;
	long i, n;

	printf("iteration: ");
	scanf("%ld", &n);

	for (i = 0; i < n; i++) 
		sum += sqrt(10.0);
	return 0;
}
