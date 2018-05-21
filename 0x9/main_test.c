/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>

extern int test_find_first_10(int *i);
extern int test_find_first_1000(int *i);
extern int test_find_first1000(int *i);

int main(void)
{
	int fail = 0;
	int i = 0;

	printf("===============================\n");
	printf("Programming Pearls: Chapter 0x9\n");
	printf("===============================\n");

	if (test_find_first_10(&i))
		fail++;
	if (test_find_first_1000(&i))
		fail++;
	if (test_find_first1000(&i))
		fail++;

	return fail;
}
