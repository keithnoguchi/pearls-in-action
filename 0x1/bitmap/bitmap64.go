// SPDX-License-Identifier: GPL-2.0
package bitmap

import "fmt"

// bitmap64 is a uint64 slice based bitmap.
type bitmap64 struct {
	mask     uint
	shift    uint
	capacity uint
	bitmap   []uint64
}

func newBitmap64(o *bitmapOpt) Bitmap {
	return &bitmap64{
		mask:     o.mask,
		shift:    o.shift,
		capacity: o.capacity,
		bitmap:   make([]uint64, o.capacity>>o.shift+1),
	}
}

// Set sets the bit.
func (b *bitmap64) Set(i uint) { b.bitmap[i>>b.shift] |= (1 << (i & b.mask)) }

// Unset unsets the bit.
func (b *bitmap64) Unset(i uint) { b.bitmap[i>>b.shift] ^= (1 << (i & b.mask)) }

// IsSet checks the bit.
func (b *bitmap64) IsSet(i uint) bool { return b.bitmap[i>>b.shift]&(1<<(i&b.mask)) != 0 }

// Reset resets all the bits.
func (b *bitmap64) Reset() {
	for i := range b.bitmap {
		b.bitmap[i] = 0
	}
}

// Cap returns the maximum bit handled.
func (b *bitmap64) Cap() uint { return b.capacity }

// Dump dumps all the internal bitmap fields.
func (b *bitmap64) Dump() {
	const wrap = 4 // wrap output
	for i := range b.bitmap {
		fmt.Printf("0x%016x ", b.bitmap[i])
		if i%wrap == wrap-1 {
			fmt.Println()
		}
	}
}
