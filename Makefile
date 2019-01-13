CXX=g++-8
GCC_LOC = $(shell which gcc)
CXXINCLUDE=-I/usr/local/include
CXXLIBS=-L/usr/local/lib/gtest
CXXFLAGS=-Wall --pedantic-errors -std=c++17 -DGCC_LOC=\"$(GCC_LOC)\" #$(CXXINCLUDE) $(CXXLIBS)

TARGET=bin/func
SRCS=src/*

$(TARGET): $(SRCS)
	@echo "Compiling"
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)
	chmod +x $(TARGET)
	@echo ""

install: $(TARGET)
	@echo "Installing Functions to /usr/local/bin"
	cp $(TARGET) /usr/local/bin

test:
	# TODO: Write compile commands for the tests

clean:
	rm -rf $(TARGET)
	rm -rf tests/main_1 tests/main_2 tests/main_3 tests/main_4 tests/mul_test

.PHONY: $(TARGET)