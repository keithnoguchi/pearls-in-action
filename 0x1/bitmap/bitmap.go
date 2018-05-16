// SPDX-License-Identifier: GPL-2.0
package bitmap

import "fmt"

// default max bitmap to be supported.
const defaultCapacity = 10000000

// Bitmap is the interface of the bitmap.
type Bitmap interface {
	// Set sets the bit.
	Set(bit uint)
	// Unset unsets the bit.
	Unset(bit uint)
	// IsSet to check the bit.
	IsSet(bit uint) bool
	// Reset resets all the bits.
	Reset()
	// Cap returns the maximum bit to be handled.
	Cap() uint
	// Dump to dump the bitmap.
	Dump()
}

// BitmapOpt updates the bitmap options.
type BitmapOpt func(b *bitmapOpt)

// bitmapOpt carries the option values.
type bitmapOpt struct {
	shift    uint
	mask     uint
	capacity uint
}

// NewBitmap creates a Bitmap instance.
func NewBitmap(opts ...BitmapOpt) Bitmap {
	// 32bit slice bitmap by default.
	o := &bitmapOpt{
		mask:     0x1f,
		shift:    5,
		capacity: defaultCapacity,
	}
	for _, f := range opts {
		f(o)
	}
	return newBitmap32(o)
}

// WithCap changes the maximum bitmap bit can be handled.
func WithCap(capacity uint) BitmapOpt {
	return func(b *bitmapOpt) {
		if capacity > 0 {
			b.capacity = capacity
		}
	}
}

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
