/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>

extern int test_max_subtree_n(int *i);
extern int test_max_subtree_logn(int *i);

int main(void)
{
	int fail = 0;
	int i = 0;

	printf("===============================\n");
	printf("Programming Pearls, Chapter 0x8\n");
	printf("===============================\n");

	if (test_max_subtree_n(&i))
		fail++;
	if (test_max_subtree_logn(&i))
		fail++;

	return fail;
}
