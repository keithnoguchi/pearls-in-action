# SPDX-License-Identifier: GPL-2.0
TARGET ?= $(shell basename $(shell pwd))_test
OBJS := main.o
OBJS += rotate.o rotate_test.o
OBJS += sign.o sign_test.o
include ../lib.mk

# Extra targets.
EXTRA_TARGETS := sig
EXTRA_TARGETS += squash
all: $(EXTRA_TARGETS)
sig: sign.o sign_main.o
	$(CC) -o $@ $^
squash: squash_main.o
	$(CC) -o $@ $^
