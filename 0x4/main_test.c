/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>

extern int test_bsearch0(int *i);
extern int test_bsearch2(int *i);
extern int test_bsearch3(int *i);
extern int test_bsearch10(int *i);

int main(void)
{
	int fail = 0;
	int i = 0;

	printf("===============================\n");
	printf("Programming Pearls, Chapter 0x4\n");
	printf("===============================\n");

	if (test_bsearch0(&i))
		fail++;
	if (test_bsearch2(&i))
		fail++;
	if (test_bsearch3(&i))
		fail++;
	if (test_bsearch10(&i))
		fail++;

	puts("");

	return fail;
}
