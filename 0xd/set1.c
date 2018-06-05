/* SPDX-License-Identifier: GPL-2.0 */
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "set.h"

struct set1 {
	int		n;
	int		max;
	struct set	set;
	int		x[];
};

static void dtor(struct set *b)
{
	struct set1 *s = container_of(b, struct set1, set);
	free(s);
}

static int insert(struct set *b, int x)
{
	struct set1 *s = container_of(b, struct set1, set);
	int i, j;

	assert(x < s->max);

	/* find the position */
	for (i = 0; s->x[i] != s->max; i++)
		if (x > s->x[i])
			break;

	/* shift array */
	for (j = s->n+1; j > i; j--)
		s->x[j] = s->x[j-1];

	/* put the value */
	s->x[i] = x;
	s->n += 1;

	return i;
}

static const struct set set = {
	.free	= dtor,
	.insert	= insert,
};

/* create m number of set with maxinum number of n */
struct set *alloc_set1(int nr, int max)
{
	struct set1 *s;
	int i;

	s = malloc(sizeof(struct set1)+sizeof(int)*(nr+1));
	if (!s)
		return NULL;

	s->n = 0;
	s->max = max;
	s->set = set;
	for (i = 0; i < nr; i++)
		s->x[i] = 0;
	s->x[0] = max; /* sentinel */
	return &s->set;
}
