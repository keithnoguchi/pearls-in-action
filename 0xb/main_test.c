/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>

extern int test_isort1(int *i);

int main(void)
{
	int fail = 0;
	int i = 0;

	printf("==================\n");
	printf("Column 11: Sorting\n");
	printf("==================\n");

	if (test_isort1(&i))
		fail++;

	return fail;
}
