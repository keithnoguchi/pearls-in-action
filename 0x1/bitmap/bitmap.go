// SPDX-License-Identifier: GPL-2.0
package bitmap

// default max bitmap to be supported.
const (
	defaultBitMask  = 0x1f
	defaultBitShift = 5
	defaultCapacity = 10000000
)

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
		mask:     defaultBitMask,
		shift:    defaultBitShift,
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
