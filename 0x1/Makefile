# SPDX-License-Identifier: GPL-2.0
CFLAGS += -Wall -Werror
Q ?= @

TARGET := bitmap_test
OBJS := bitmap.o bitmap_test.o

all: $(TARGET)
check: all
	$(Q)./$(TARGET)
$(TARGET): $(OBJS)
	$(Q)$(CC) $(CFLAGS) -o $@ $^
%.o: %.c
	$(Q)$(CC) $(CFLAGS) -c $<
