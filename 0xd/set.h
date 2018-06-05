/* SPDX-License-Identifier: GPL-2.0 */

#ifndef _PEARLS_SET_H
#define _PEARLS_SET_H

#include <stddef.h>

/* generic set type */
struct set {
	void (*free)(struct set *s);
};
static inline void free_set(struct set *s) { s->free(s); }

#ifndef container_of
#define container_of(_p, _t, _m) (_t *)((char *)(_p)-offsetof(_t, _m))
#endif /* container_of */

#endif /* _PEARLS_SET_H */
