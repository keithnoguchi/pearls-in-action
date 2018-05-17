/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>
#include <string.h>

#include "sign.h"

int main(void)
{
#define WORDMAX 100
	char word[WORDMAX], sig[WORDMAX];

	while (scanf("%s", word) != EOF) {
		sign(word, strlen(word), sig);
		printf("%s %s\n", sig, word);
	}
	return 0;
}



