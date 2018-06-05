/* SPDX-License-Identifier: GPL-2.0 */
#include <stdlib.h>
#include <string.h>

#include "set.h"

struct set1 {
	int		current;
	struct set	base;
	int		x[];
};

static void dtor(struct set *b)
{
	struct set1 *s = container_of(b, struct set1, base);
	free(s);
}

static const struct set_ops ops = {
	.dtor	= dtor,
};

/* create m number of set with maxinum number of n */
struct set *alloc_set1(int nr, int max)
{
	struct set1 *s;
	int i;

	s = malloc(sizeof(struct set1)+sizeof(int)*(nr+1));
	if (!s)
		return NULL;

	s->current = 0;
	s->base.ops = &ops;
	for (i = 0; i < nr; i++)
		s->x[i] = 0;
	s->x[0] = max; /* sentinel */
	return &s->base;
}
