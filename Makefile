# SPDX-License-Identifier: GPL-2.0

Q := @
TARGETS := 0x1
TARGETS += 0x2
TARGETS += 0x4

.PHONY: all check go-check clean
all check go-check clean:
	$(Q)for TARGET in $(TARGETS); do  \
		$(MAKE) TARGET=$${TARGET}_test -C $$TARGET $@; \
	done
