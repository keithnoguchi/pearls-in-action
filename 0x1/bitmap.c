/* SPDX-License-Identifier: GPL-2.0 */

#include <linux/types.h>

#define MASK		0x1f
#define SHIFT		5
#define MAX		10000000

static __u32 bitmap[MAX>>SHIFT];

void init(void)
{
	int i;

	for (i = 0; i < (MAX>>SHIFT); i++)
		bitmap[i] = 0;
}
int min(void)      { return 0; }
int max(void)      { return MAX; }
void set(int i)    { bitmap[i>>SHIFT] |= 1<<(i&MASK); }
void unset(int i)  { bitmap[i>>SHIFT] ^= 1<<(i&MASK); }
int  is_set(int i) { return bitmap[i>>SHIFT] & (1<<(i&MASK)); }
