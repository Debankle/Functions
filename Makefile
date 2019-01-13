CXX=g++-8
GCC_LOC = $(shell which gcc)
CXXINCLUDE=-I/usr/local/include
CXXLIBS=-L/usr/local/lib/gtest
CXXFLAGS=-Wall -O2 --pedantic-errors -std=c++17 -DGCC_LOC=\"$(GCC_LOC)\" #$(CXXINCLUDE) $(CXXLIBS)

TARGET=bin/func
SRCS=src/*

.PHONY: make install test clean

make: $(SRCS)
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
	find tests/ -not -name "*.func" -type f | xargs rm -rf
