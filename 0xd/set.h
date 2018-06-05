/* SPDX-License-Identifier: GPL-2.0 */

#ifndef _PEARLS_SET_H
#define _PEARLS_SET_H

#include <stddef.h>

/* generic set type */
struct set {
	const struct set_ops	*ops;
};
#define container_of(_p, _t, _m) (_t *)((char *)(_p)-offsetof(_t, _m))

/* set operations */
struct set_ops {
	void (*dtor)(struct set *s);
};
static inline void free_set(struct set *s) { s->ops->dtor(s); }

#endif /* _PEARLS_SET_H */
