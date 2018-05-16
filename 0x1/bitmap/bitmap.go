// SPDX-License-Identifier: GPL-2.0
package bitmap

import "fmt"

const (
	mask       = 0x1f
	shift      = 5
	defaultMax = 10000000
)

// Bitmap is a slice based bitmap.
type Bitmap struct {
	min    uint
	max    uint
	bitmap []uint32
}

// NewBitmap creates a Bitmap instance.
func NewBitmap(max uint) *Bitmap {
	if max == 0 { max = defaultMax }
	return &Bitmap{
		max:    max,
		bitmap: make([]uint32, (max>>shift)+1),
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
