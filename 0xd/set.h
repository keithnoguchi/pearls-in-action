/* SPDX-License-Identifier: GPL-2.0 */

#ifndef _PEARLS_SET_H
#define _PEARLS_SET_H

/* generic set type */
struct set {
	void (*free)(struct set *s);
	size_t (*size)(const struct set *s);
	int (*insert)(struct set *s, int x);
	void (*report)(const struct set *s, int x[]);
};
static inline void set_free(struct set *s) { s->free(s); }
static inline size_t set_size(const struct set *s) { return s->size(s); }
static inline int set_insert(struct set *s, int x) { return s->insert(s, x); }
static inline void set_report(const struct set *s, int x[]) { s->report(s, x); }

#ifndef container_of
#include <stddef.h>
#define container_of(_p, _t, _m) (_t *)((char *)(_p)-offsetof(_t, _m))
#endif /* container_of */

#endif /* _PEARLS_SET_H */
