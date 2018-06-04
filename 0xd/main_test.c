/* SPDX-License-Identifier: GPL-2.0 */
#include <stdio.h>

extern int test_set1(int *test_nr);

int main(void)
{
	int fail = 0;
	int i = 0;

	printf("=====================\n");
	printf("Column 0xd: Searching\n");
	printf("=====================\n");

	if (test_set1(&i))
		fail++;

	return fail;
}
