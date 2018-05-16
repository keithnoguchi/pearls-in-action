// SPDL-License-Identifier: GPL-2.0
package bitmap

import (
	"fmt"
	"testing"
)

func TestBitmapSet(t *testing.T) {
	tests := []struct {
		name string
		max  uint
		pos  uint
	}{
		{
			name: "set and check the min(0) bit",
			max:  10000000,
			pos:  0,
		},
		{
			name: "set and check the max(10,000,000) bit",
			max:  10000000,
			pos:  10000000,
		},
		{
			name: fmt.Sprintf("set and check the middle(%d) bit",
				(0+10000000)/2),
			pos:  (0+10000000)/2,
		},
	}

	for _, tc := range tests {
		tc := tc
		t.Run(tc.name, func(t *testing.T) {
			b := NewBitmap([]BitmapOpt{WithMax(tc.max)}...)
			b.Set(tc.pos)
			// Check the bits set.
			if !b.IsSet(tc.pos) {
				t.Fatalf("bit %d is not set\n", tc.pos)
				b.dump()
			}
			// Check the other bits not set.
			for i := b.min; i <= b.max; i++ {
				if i == tc.pos {
					continue
				}
				if b.IsSet(i) {
					t.Fatalf("bit %d is set\n", tc.pos)
					b.dump()
				}
			}
		})
	}
}
