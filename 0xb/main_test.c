/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>

extern int test_isort1_random(int *i);
extern int test_isort2_random(int *i);
extern int test_isort3_random(int *i);
extern int test_qsort1_random(int *i);
extern int test_qsort2_random(int *i);
extern int test_qsort3_random(int *i);
extern int test_qsort4_random(int *i);
extern int test_qsort6_random(int *i);
extern int test_isort1_identical(int *i);
extern int test_isort2_identical(int *i);
extern int test_isort3_identical(int *i);
extern int test_qsort1_identical(int *i);
extern int test_qsort2_identical(int *i);
extern int test_qsort3_identical(int *i);
extern int test_qsort4_identical(int *i);
extern int test_qsort6_identical(int *i);
extern int test_isort1_sorted(int *i);
extern int test_isort2_sorted(int *i);
extern int test_isort3_sorted(int *i);
extern int test_qsort1_sorted(int *i);
extern int test_qsort2_sorted(int *i);
extern int test_qsort3_sorted(int *i);
extern int test_qsort4_sorted(int *i);
extern int test_qsort6_sorted(int *i);

int main(void)
{
	int fail = 0;
	int i = 0;

	printf("===================\n");
	printf("Column 0xb: Sorting\n");
	printf("===================\n");

	if (test_isort1_random(&i))
		fail++;
	if (test_isort2_random(&i))
		fail++;
	if (test_isort3_random(&i))
		fail++;
	if (test_qsort1_random(&i))
		fail++;
	if (test_qsort2_random(&i))
		fail++;
	if (test_qsort3_random(&i))
		fail++;
	if (test_qsort4_random(&i))
		fail++;
	if (test_qsort6_random(&i))
		fail++;
	if (test_isort1_identical(&i))
		fail++;
	if (test_isort2_identical(&i))
		fail++;
	if (test_isort3_identical(&i))
		fail++;
	if (test_qsort1_identical(&i))
		fail++;
	if (test_qsort2_identical(&i))
		fail++;
	if (test_qsort3_identical(&i))
		fail++;
	if (test_qsort4_identical(&i))
		fail++;
	if (test_qsort6_identical(&i))
		fail++;
	if (test_isort1_sorted(&i))
		fail++;
	if (test_isort2_sorted(&i))
		fail++;
	if (test_isort3_sorted(&i))
		fail++;
	if (test_qsort1_sorted(&i))
		fail++;
	if (test_qsort2_sorted(&i))
		fail++;
	if (test_qsort3_sorted(&i))
		fail++;
	if (test_qsort4_sorted(&i))
		fail++;
	if (test_qsort6_sorted(&i))
		fail++;

	return fail;
}
