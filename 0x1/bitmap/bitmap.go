// SPDX-License-Identifier: GPL-2.0
package bitmap

import "fmt"

const (
	defaultMax = 10000000
	// 32bit based bitmap array/slice.
	mask  = 0x1f
	shift = 5
)

// Bitmap is a slice based bitmap.
type Bitmap struct {
	min    uint
	max    uint
	bitmap []uint32
}

// BitmapOpt updates the bitmap options.
type BitmapOpt func(b *Bitmap)

// NewBitmap creates a Bitmap instance.
func NewBitmap(opts ...BitmapOpt) *Bitmap {
	b := &Bitmap{max: defaultMax}

	for _, f := range opts {
		f(b)
	}
	b.bitmap = make([]uint32, (b.max>>shift)+1)

	return b
}

// WithMax changes the maximum bitmap position from the defaultMax constant.
func WithMax(max uint) BitmapOpt {
	return func(b *Bitmap) {
		if max > 0 {
			b.max = max
		}
	}
}

// Set sets the bit.
func (b *Bitmap) Set(i uint) { b.bitmap[i>>shift] |= (1<<(i&mask)) }

// IsSet checks the bit.
func (b *Bitmap) IsSet(i uint) bool { return b.bitmap[i>>shift] & (1<<(i&mask)) != 0 }

// Reset resets all the bits.
func (b *Bitmap) Reset() { for i := range b.bitmap { b.bitmap[i] = 0 } }

func (b *Bitmap) dump() {
	const wrap = 8 // wrap output
	for i := range b.bitmap {
		fmt.Printf("0x%08x ", b.bitmap[i])
		if i%wrap == wrap-1 {
			fmt.Println()
		}
	}
}
