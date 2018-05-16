/* SPDX-License-Identifier: GPL-2.0 */

static void reverse(char *input, int i, int j)
{
	while (i < j) {
		char tmp = input[i];
		input[i] = input[j];
		input[j] = tmp;
		i++;
		j--;
	}
}

char *rotate(char *input, int n, int pos)
{
	reverse(input, 0, pos-1);
	reverse(input, pos, n-1);
	reverse(input, 0, n-1);
	return input;
}
