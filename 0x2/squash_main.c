/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>
#include <string.h>

int main(void)
{
#define WORDMAX	100
	char word[WORDMAX], sig[WORDMAX], oldsig[WORDMAX];
	int linenum = 0;

	strcpy(oldsig, "");
	while (scanf("%s %s", sig, word) != EOF) {
		if (strcmp(oldsig, sig)) {
			if (linenum > 0)
				puts("");
			strcpy(oldsig, sig);
		}
		linenum++;
		printf("%s ", word);
	}
	puts("");
	return 0;
}
