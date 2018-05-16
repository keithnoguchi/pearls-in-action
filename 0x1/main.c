/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>

extern int bitmap_test(int *i);

int main(void)
{
	int fail = 0;
	int i = 0;

	printf("===============================\n");
	printf("Programming Pearls: Chapter 0x1\n");
	printf("===============================\n");

	if (bitmap_test(&i))
		fail++;

	puts("");

	return fail;
}
