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

#ifndef container_of
#include <stddef.h>
#define container_of(P, T, M) (T *)((char *)(P)-offsetof(T, M))
#endif /* container_of */

static void dtor(struct set *b)
{
	struct set1 *s = container_of(b, struct set1, set);
	free(s);
}

static size_t size(const struct set *b)
{
	struct set1 *s = container_of(b, struct set1, set);
	return s->n;
}

static int insert(struct set *b, int x)
{
	struct set1 *s = container_of(b, struct set1, set);
	int i, j;

	assert(x < s->max);

	/* find the position */
	for (i = 0; s->x[i] != s->max; i++)
		if (s->x[i] > x)
			break;

	/* shift array */
	for (j = s->n+1; j > i; j--)
		s->x[j] = s->x[j-1];

	/* put the value */
	s->x[i] = x;
	s->n += 1;

	return i;
}

static void report(const struct set *b, int x[])
{
	struct set1 *s = container_of(b, struct set1, set);
	int i;

	for (i = 0; i < s->n; i++)
		x[i] = s->x[i];
	x[i] = s->x[i]; /* copy sentinel */
}

static const struct set set = {
	.free	= dtor,
	.size	= size,
	.insert	= insert,
	.report	= report,
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
