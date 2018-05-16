// SPDL-License-Identifier: GPL-2.0
package bitmap

import (
	"fmt"
	"testing"
)

func TestBitmap32Set(t *testing.T) {
	tests := []struct {
		name     string
		capacity uint
		pos      uint
	}{
		{
			name: "set and check the min(0) bit",
			pos:  0,
		},
		{
			name: "set and check the max(10,000,000) bit",
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
			b := NewBitmap([]BitmapOpt{WithCap(tc.capacity)}...)
			b.Set(tc.pos)
			// Check the bits set.
			if !b.IsSet(tc.pos) {
				t.Fatalf("bit %d is not set\n", tc.pos)
				b.Dump()
			}
			// Check the other bits not set.
			for i := uint(0); i <= b.Cap(); i++ {
				if i == tc.pos {
					continue
				}
				if b.IsSet(i) {
					t.Fatalf("bit %d is set\n", tc.pos)
					b.Dump()
				}
			}
		})
	}
}
