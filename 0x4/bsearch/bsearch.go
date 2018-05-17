// SPDX-License-Identifier: GPL-2.0
package bsearch

func BSearchInt(needle int, haystack []int) int {
	ret, _ := bSearchInt(needle, haystack)
	return ret
}

func BSearchIntWithTry(needle int, haystack []int) (int, int) {
	return bSearchInt(needle, haystack)
}

func bSearchInt(needle int, haystack []int) (int, int) {
	h := len(haystack) - 1
	l := 0

	var m int
	var try int
	for l <= h {
		try++
		m = (l + h) / 2
		switch {
		case needle < haystack[m]:
			h = m - 1
		case needle > haystack[m]:
			l = m + 1
		default:
			return m, try
		}
	}
	return -1, try
}
