// SPDX-License-Identifier: GPL-2.0
package bitmap

import "fmt"

// bitmap32 is a uint32 slice based bitmap.
type bitmap32 struct {
	mask     uint
	shift    uint
	capacity uint
	bitmap   []uint32
}

func newBitmap32(o *bitmapOpt) Bitmap {
	return &bitmap32{
		mask:     o.mask,
		shift:    o.shift,
		capacity: o.capacity,
		bitmap:   make([]uint32, o.capacity>>o.shift+1),
	}
}

// Set sets the bit.
func (b *bitmap32) Set(i uint) { b.bitmap[i>>b.shift] |= (1<<(i&b.mask)) }

// Unset unsets the bit.
func (b *bitmap32) Unset(i uint) { b.bitmap[i>>b.shift] ^= (1<<(i&b.mask)) }

// IsSet checks the bit.
func (b *bitmap32) IsSet(i uint) bool { return b.bitmap[i>>b.shift] & (1<<(i&b.mask)) != 0 }

// Reset resets all the bits.
func (b *bitmap32) Reset() { for i := range b.bitmap { b.bitmap[i] = 0 } }

// Cap returns the maximum bit handled.
func (b *bitmap32) Cap() uint { return b.capacity }

// Dump dumps all the internal bitmap fields.
func (b *bitmap32) Dump() {
	const wrap = 8 // wrap output
	for i := range b.bitmap {
		fmt.Printf("0x%08x ", b.bitmap[i])
		if i%wrap == wrap-1 {
			fmt.Println()
		}
	}
}
