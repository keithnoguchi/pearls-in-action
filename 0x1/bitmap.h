/* SPDX-License-Identifier: GPL-2.0 */

#ifndef __PEARL_BITMAP_H
#define __PEARL_BITMAP_H

void reset();
void set(int i);
void unset(int i);
int  is_set(int i);
int  min();
int  max();

#endif /* __PEARL_BITMAP_H */
