/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>

struct node { int i; struct node *p; };

int main(void)
{
	printf("sizeof(node)=%ld\n", sizeof(struct node));
	printf("sizeof(char)=%ld,sizeof(short)=%ld,sizeof(int)=%ld\n",
	       sizeof(char), sizeof(short), sizeof(int));
	printf("sizeof(float)=%ld,sizeof(long)=%ld,sizeof(double)=%ld\n",
	       sizeof(float), sizeof(long), sizeof(double));
	printf("sizeof(void*)=%ld\n", sizeof(void *));
	return 0;
}
