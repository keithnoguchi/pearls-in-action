/* SPDX-License-Identifier: GPL-2.0 */

#include <stdio.h>
#include <stdlib.h>

static void print_nodes(void)
{
	struct structc {char c;}			*cp[8];
	struct structi {int i;}				*ip[8];
	struct structip {int i; struct ip *p;}		*ipp[8];
	struct structdc {double d; char c;}		*dcp[8];
	struct structpp {struct pp *p1; struct pp *p2;}	*ppp[8];
	int i, ci, ii = 0, ipi = 0, dci = 0, ppi = 0;

	for (ci = 0; ci < 8; ci++) {
		cp[ci] = malloc(sizeof(struct structc));
		if (!cp[ci]) {
			perror("malloc");
			goto out;
		}
	}
	for (ii = 0; ii < 8; ii++) {
		ip[ii] = malloc(sizeof(struct structi));
		if (!ip[ii]) {
			perror("malloc");
			goto out;
		}
	}
	for (ipi = 0; ipi < 8; ipi++) {
		ipp[ipi] = malloc(sizeof(struct structi));
		if (!ipp[ipi]) {
			perror("malloc");
			goto out;
		}
	}
	for (dci = 0; dci < 8; dci++) {
		dcp[dci] = malloc(sizeof(struct structdc));
		if (!dcp[dci]) {
			perror("malloc");
			goto out;
		}
	}
	for (ppi = 0; ppi < 8; ppi++) {
		ppp[ppi] = malloc(sizeof(struct structpp));
		if (!ppp[ppi]) {
			perror("malloc");
			goto out;
		}
	}

	printf("%-25s%2ld\t", "sizeof(struct structc)=", sizeof(struct structc));
	printf("%-25s", "malloc(struct structc)=");
	for (i = 1; i < 8; i++)
		printf("%2lu ", (unsigned long)cp[i]-(unsigned long)cp[i-1]);
	printf("\n");
	printf("%-25s%2ld\t", "sizeof(struct structi)=", sizeof(struct structi));
	printf("%-25s", "malloc(struct structi)=");
	for (i = 1; i < 8; i++)
		printf("%2lu ", (unsigned long)ip[i]-(unsigned long)ip[i-1]);
	printf("\n");
	printf("%-25s%2ld\t", "sizeof(struct structip)=", sizeof(struct structip));
	printf("%-25s", "malloc(struct structip)=");
	for (i = 1; i < 8; i++)
		printf("%2lu ", (unsigned long)ipp[i]-(unsigned long)ipp[i-1]);
	printf("\n");
	printf("%-25s%2ld\t", "sizeof(struct structdc)=", sizeof(struct structdc));
	printf("%-25s", "malloc(struct structdc)=");
	for (i = 1; i < 8; i++)
		printf("%2lu ", (unsigned long)dcp[i]-(unsigned long)dcp[i-1]);
	printf("\n");
	printf("%-25s%2ld\t", "sizeof(struct structpp)=", sizeof(struct structpp));
	printf("%-25s", "malloc(struct structpp)=");
	for (i = 1; i < 8; i++)
		printf("%2lu ", (unsigned long)ppp[i]-(unsigned long)ppp[i-1]);
	printf("\n");
out:
	for (i = 0; i < ppi; i++)
		free(ppp[i]);
	for (i = 0; i < dci; i++)
		free(dcp[i]);
	for (i = 0; i < ipi; i++)
		free(ipp[i]);
	for (i = 0; i < ii; i++)
		free(ip[i]);
	for (i = 0; i < ci; i++)
		free(cp[i]);
}

static void print_basic_types(void)
{
	printf("sizeof(char)=%ld,sizeof(short)=%ld,sizeof(int)=%ld\n",
	       sizeof(char), sizeof(short), sizeof(int));
	printf("sizeof(float)=%ld,sizeof(long)=%ld,sizeof(double)=%ld\n",
	       sizeof(float), sizeof(long), sizeof(double));
	printf("sizeof(void*)=%ld\n", sizeof(void *));
}

int main(void)
{
	print_basic_types();
	print_nodes();
	return 0;
}
