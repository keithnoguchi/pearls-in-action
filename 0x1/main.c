/* SPDX-License-Identifier: GPL-2.0 */

extern int bitmap_test(int *i);

int main(void)
{
	int fail = 0;
	int i = 0;

	if (bitmap_test(&i)) {
		fail++;
		goto out;
	}

out:
	return fail;
}
