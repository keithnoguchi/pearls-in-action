/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>

extern int test_isort1(int *i);
extern int test_isort2(int *i);
extern int test_isort3(int *i);
extern int test_isort1_sorted(int *i);
extern int test_isort2_sorted(int *i);
extern int test_isort3_sorted(int *i);

int main(void)
{
	int fail = 0;
	int i = 0;

	printf("==================\n");
	printf("Column 11: Sorting\n");
	printf("==================\n");

	if (test_isort1(&i))
		fail++;
	if (test_isort2(&i))
		fail++;
	if (test_isort3(&i))
		fail++;
	if (test_isort1_sorted(&i))
		fail++;
	if (test_isort2_sorted(&i))
		fail++;
	if (test_isort3_sorted(&i))
		fail++;

	return fail;
}
