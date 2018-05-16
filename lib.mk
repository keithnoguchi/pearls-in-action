# SPDX-License-Identifier: GPL-2.0
CFLAGS += -Wall -Werror
Q ?= @

all: $(TARGET)
check: all
	$(Q)./$(TARGET)
clean:
	$(RM) $(OBJS) $(TARGET)
$(TARGET): $(OBJS)
	$(Q)$(CC) $(CFLAGS) -o $@ $^
%.o: %.c
	$(Q)$(CC) $(CFLAGS) -c $<
