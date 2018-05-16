/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>

extern int rotate_test(int *i);

int main(void)
{
	int fail = 0;
	int i = 0;

	printf("===============================\n");
	printf("Programming Pearls: Chapter 0x2\n");
	printf("===============================\n");

	if (rotate_test(&i))
		fail++;

	puts("");

	return fail;
}
