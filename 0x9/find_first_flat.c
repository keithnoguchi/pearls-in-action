/* SDPX-License-Identifier: GPL-2.0 */

/* find the target t from array x of size nr, nr max 1023 */
int find_first_flat(int t, const int x[], int nr)
{
	int l = -1;

	if (x[l+512] < t) l  = nr-512;
	if (x[l+256] < t) l += 256;
	if (x[l+128] < t) l += 128;
	if (x[l+64]  < t) l += 64;
	if (x[l+32]  < t) l += 32;
	if (x[l+16]  < t) l += 16;
	if (x[l+8]   < t) l += 8;
	if (x[l+4]   < t) l += 4;
	if (x[l+2]   < t) l += 2;
	if (x[l+1]   < t) l += 1;

	if (l+1 >= nr || x[l+1] != t)
		return -1;
	return l+1;
}
