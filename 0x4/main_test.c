/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>

extern int test_bsearch_0(int *i);
extern int test_bsearch_2(int *i);
extern int test_bsearch_3(int *i);
extern int test_bsearch_10(int *i);
extern int test_bsearch_1024(int *i);
extern int test_bsearch_with_try_0(int *i);
extern int test_bsearch_with_try_2(int *i);
extern int test_bsearch_with_try_3(int *i);
extern int test_bsearch_with_try_10(int *i);
extern int test_bsearch_with_try_1024(int *i);
extern int test_bsearch_recursive_0(int *i);
extern int test_bsearch_recursive_2(int *i);
extern int test_bsearch_recursive_3(int *i);
extern int test_bsearch_recursive_10(int *i);
extern int test_bsearch_recursive_1024(int *i);
extern int test_bsearch_recursive_with_try_0(int *i);
extern int test_bsearch_recursive_with_try_2(int *i);
extern int test_bsearch_recursive_with_try_3(int *i);
extern int test_bsearch_recursive_with_try_10(int *i);
extern int test_bsearch_recursive_with_try_1024(int *i);

int main(void)
{
	int fail = 0;
	int i = 0;

	printf("===============================\n");
	printf("Programming Pearls, Chapter 0x4\n");
	printf("===============================\n");

	if (test_bsearch_0(&i))
		fail++;
	if (test_bsearch_2(&i))
		fail++;
	if (test_bsearch_3(&i))
		fail++;
	if (test_bsearch_10(&i))
		fail++;
	if (test_bsearch_1024(&i))
		fail++;
	if (test_bsearch_with_try_0(&i))
		fail++;
	if (test_bsearch_with_try_2(&i))
		fail++;
	if (test_bsearch_with_try_3(&i))
		fail++;
	if (test_bsearch_with_try_10(&i))
		fail++;
	if (test_bsearch_with_try_1024(&i))
		fail++;
	if (test_bsearch_recursive_0(&i))
		fail++;
	if (test_bsearch_recursive_2(&i))
		fail++;
	if (test_bsearch_recursive_3(&i))
		fail++;
	if (test_bsearch_recursive_10(&i))
		fail++;
	if (test_bsearch_recursive_1024(&i))
		fail++;
	if (test_bsearch_recursive_with_try_0(&i))
		fail++;
	if (test_bsearch_recursive_with_try_2(&i))
		fail++;
	if (test_bsearch_recursive_with_try_3(&i))
		fail++;
	if (test_bsearch_recursive_with_try_10(&i))
		fail++;
	if (test_bsearch_recursive_with_try_1024(&i))
		fail++;

	puts("");

	return fail;
}
