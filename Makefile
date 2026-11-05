CC      = gcc
CFLAGS  = -std=c11 -Wall -Wextra -Wpedantic -O2 -Iinclude
LDFLAGS =

SRC     = src/matrix.c
BUILD   = build
TESTBIN = $(BUILD)/test_matrix
DEMOBIN = $(BUILD)/demo

.PHONY: all test run clean

all: $(TESTBIN) $(DEMOBIN)

$(BUILD):
	mkdir -p $(BUILD)

$(TESTBIN): tests/test_matrix.c $(SRC) | $(BUILD)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(DEMOBIN): examples/demo.c $(SRC) | $(BUILD)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

test: $(TESTBIN)
	./$(TESTBIN)

run: $(DEMOBIN)
	./$(DEMOBIN)

clean:
	rm -rf $(BUILD)
