/* SDPX-License-Identifier: GPL-2.0 */

#include <time.h>
#include <stdlib.h>
#include <string.h>

static void swap(char *word, int i, int j)
{
	char tmp = word[i];
	word[i] = word[j];
	word[j] = tmp;
}

/* quick sort */
static void quicksort(char word[], int len)
{
	int last;
	int i;

	if (len < 2)
		return;

	/* Put a pivot in array 0 */
	swap(word, 0, rand()%len);

	last = 0;
	for (i = 1; i < len; i++)
		if (word[i] < word[0])
			swap(word, ++last, i);
	swap(word, 0, last);

	quicksort(word, last);
	quicksort(&word[last+1], len-(last+1));
}

/* sort the word, as for the signature */
void sign(const char word[], int len, char sig[])
{
	srand(time(NULL));
	memcpy(sig, word, len+1); /* including the null terminate */
	quicksort(sig, len);
}
