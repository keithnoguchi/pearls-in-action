/* SPDX-License-Identifier: GPL-2.0 */

#ifndef _PEARLS_BSEARCH
#define _PEARLS_BSEARCH

int bsearch(int v, const int a[], int n);
int bsearch_with_try(int v, const int a[], int n, int *try);
int bsearch_recursive(int v, const int a[], int n);
int bsearch_recursive_with_try(int v, const int a[], int n, int *try);

#endif /* _PEARLS_BSEARCH */
