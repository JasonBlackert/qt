CC := g++
CFLAGS := -std=c++11 -Wall
TARGET := build/main.out

.PHONY: all clean run

all: $(TARGET)

$(TARGET): main.cpp | build
	$(CC) $(CFLAGS) $< -o $@

run: $(TARGET)
	$<

build:
	mkdir -p build

clean:
	rm -rf build
