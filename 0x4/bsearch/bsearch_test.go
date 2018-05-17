// SPDX-License-Identifier: GPL-2.0
package bsearch

import "testing"

func TestBSearchIntOn10(t *testing.T) {
	tests := []struct {
		name   string
		needle int
		want   int
	}{
		{
			name:   "first entry out of 10 elements",
			needle: 0,
			want:   0,
		},
		{
			name:   "last entry out of 10 elements",
			needle: 9,
			want:   9,
		},
		{
			name:   "middle entry out of 10 elements",
			needle: 4,
			want:   4,
		},
	}
	var haystack = []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

	for _, tc := range tests {
		tc := tc
		t.Run(tc.name, func(t *testing.T) {
			got := BSearchInt(tc.needle, haystack)
			if got != tc.want {
				t.Fatalf("wrong index:\n- want: %d\n-  got: %d\n",
					tc.want, got)
			}
		})
	}
}

func TestBSearchIntOn1024(t *testing.T) {
	tests := []struct {
		name   string
		needle int
		want   int
	}{
		{
			name:   "first entry out of 1024 elements",
			needle: 0,
			want:   0,
		},
		{
			name:   "last entry out of 1024 elements",
			needle: 1023,
			want:   1023,
		},
		{
			name:   "middle entry out of 1024 elements",
			needle: 511,
			want:   511,
		},
	}
	haystack := make([]int, 1024)
	for i := 0; i < 1024; i++ {
		haystack[i] = i
	}

	for _, tc := range tests {
		tc := tc
		t.Run(tc.name, func(t *testing.T) {
			got := BSearchInt(tc.needle, haystack)
			if got != tc.want {
				t.Fatalf("wrong index:\n- want: %d\n-  got: %d\n",
					tc.want, got)
			}
		})
	}
}

func TestBSearchIntWithTryOn10(t *testing.T) {
	tests := []struct {
		name   string
		needle int
		want   int
		try    int
	}{
		{
			name:   "first entry out of 10 elements",
			needle: 0,
			want:   0,
			try:    3,
		},
		{
			name:   "last entry out of 10 elements",
			needle: 9,
			want:   9,
			try:    4,
		},
		{
			name:   "middle entry out of 10 elements",
			needle: 4,
			want:   4,
			try:    1,
		},
	}
	var haystack = []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

	for _, tc := range tests {
		tc := tc
		t.Run(tc.name, func(t *testing.T) {
			got, try := BSearchIntWithTry(tc.needle, haystack)
			if got != tc.want {
				t.Fatalf("wrong index:\n- want: %d\n-  got: %d\n",
					tc.want, got)
			}
			if try != tc.try {
				t.Fatalf("wrong try:\n- want: %d\n-  got: %d\n",
					tc.try, try)
			}
		})
	}
}

func TestBSearchIntWithTryOn1024(t *testing.T) {
	tests := []struct {
		name   string
		needle int
		want   int
		try    int
	}{
		{
			name:   "first entry out of 1024 elements",
			needle: 0,
			want:   0,
			try:    10,
		},
		{
			name:   "last entry out of 1024 elements",
			needle: 1023,
			want:   1023,
			try:    10,
		},
		{
			name:   "middle entry out of 1024 elements",
			needle: 511,
			want:   511,
			try:    1,
		},
	}
	haystack := make([]int, 1024)
	for i := 0; i < 1024; i++ {
		haystack[i] = i
	}

	for _, tc := range tests {
		tc := tc
		t.Run(tc.name, func(t *testing.T) {
			got := BSearchInt(tc.needle, haystack)
			if got != tc.want {
				t.Fatalf("wrong index:\n- want: %d\n-  got: %d\n",
					tc.want, got)
			}
		})
	}
}
