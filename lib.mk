# SPDX-License-Identifier: GPL-2.0
CFLAGS += -g -Wall -Werror
Q ?=

all: $(TARGET)
check: all
	$(Q)./$(TARGET)
clean:
	$(Q)$(RM) $(OBJS) $(TARGET)
$(TARGET): $(OBJS)
	$(Q)$(CC) $(CFLAGS) -o $@ $^
%.o: %.c
	$(Q)$(CC) $(CFLAGS) -c $<
