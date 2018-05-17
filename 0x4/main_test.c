/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>

extern int test_bsearch0(int *i);
extern int test_bsearch2(int *i);
extern int test_bsearch3(int *i);
extern int test_bsearch10(int *i);
extern int test_bsearch1024(int *i);
extern int test_bsearch0_with_try(int *i);
extern int test_bsearch2_with_try(int *i);
extern int test_bsearch3_with_try(int *i);
extern int test_bsearch10_with_try(int *i);
extern int test_bsearch1024_with_try(int *i);

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
	if (test_bsearch1024(&i))
		fail++;
	if (test_bsearch0_with_try(&i))
		fail++;
	if (test_bsearch2_with_try(&i))
		fail++;
	if (test_bsearch3_with_try(&i))
		fail++;
	if (test_bsearch10_with_try(&i))
		fail++;
	if (test_bsearch1024_with_try(&i))
		fail++;

	puts("");

	return fail;
}
