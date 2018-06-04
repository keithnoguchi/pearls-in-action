/* SPDX-License-Identifier: GPL-2.0 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set1.h"

/* create m number of set with maxinum number of n */
struct set1 *alloc_set1(int nr, int max)
{
	struct set1 *s;
	int i;

	s = malloc(sizeof(struct set1)+sizeof(int)*(nr+1));
	if (!s)
		goto out;

	for (i = 0; i < nr+1; i++)
		s->x[i] = 0;
	s->x[nr] = max;
	s->current = 0;
out:
	return s;
}

void free_set1(struct set1 *s)
{
	free(s);
}
