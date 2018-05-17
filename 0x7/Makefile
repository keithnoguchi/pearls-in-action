# SPDX-License-Identifier: GPL-2.0
EXTRA_TARGETS := sizeof
EXTRA_TARGETS += sqrt
include ../lib.mk

# Extra targets.
sizeof: sizeof_main.o
	$(CC) -o $@ $^
sqrt: sqrt_main.o
	$(CC) -o $@ $^
