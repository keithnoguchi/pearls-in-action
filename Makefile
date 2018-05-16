# SPDX-License-Identifier: GPL-2.0

Q := @
TARGETS := 0x1

all check clean:
	$(Q)for TARGET in $(TARGETS); do  \
		$(MAKE) TARGET=$$TARGET -C $$TARGET $@; \
	done
