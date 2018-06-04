/* SPDX-License-Identifier: GPL-2.0 */
#include <stdio.h>

extern int test_genknuth(int *i);

int main(void)
{
	int fail = 0;
	int i = 0;

	printf("============================\n");
	printf("Column 0xc: A Sample Problem\n");
	printf("============================\n");

	if (test_genknuth(&i))
		fail++;

	return fail;
}
