/* SPDX-License-Identifier: GPL-2.0 */

#ifndef _PEARLS_SET1_H
#define _PEARLS_SET1_H

/* array based set */
struct set1 {
	int	current;
	int	x[];
};

struct set1 *alloc_set1(int mr, int max);
void free_set1(struct set1 *s);

#endif /* _PEARLS_SET1_H */
