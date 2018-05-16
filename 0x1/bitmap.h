/* SPDX-License-Identifier: GPL-2.0 */

#ifndef __PEARL_BITMAP_H
#define __PEARL_BITMAP_H

void init();
void set(int i);
void reset(int i);
int is_set(int i);
int min();
int max();

#endif /* __PEARL_BITMAP_H */
