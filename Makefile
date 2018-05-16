# SPDX-License-Identifier: GPL-2.0

Q := @
TARGETS := 0x1
TARGETS += 0x2

all check clean:
	$(Q)for TARGET in $(TARGETS); do  \
		$(MAKE) TARGET=$${TARGET}_test -C $$TARGET $@; \
	done
