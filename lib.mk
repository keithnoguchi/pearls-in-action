# SPDX-License-Identifier: GPL-2.0
CFLAGS += -g -Wall -Werror
Q ?=
CD ?= cd
GO ?= go

.PHONY: all check go-check clean
all: $(TARGET)
check: all
	$(Q)./$(TARGET)
go-check: $(GO_TARGETS)
clean:
	$(Q)$(RM) $(OBJS) $(TARGET) $(EXTRA_TARGETS)
$(TARGET): $(OBJS)
	$(Q)$(CC) $(CFLAGS) -o $@ $^
%.o: %.c
	$(Q)$(CC) $(CFLAGS) -c $<
.PHONY: $(GO_TARGETS)
$(GO_TARGETS):
	$(CD) ./$@ && $(GO) fmt && $(GO) test -v
