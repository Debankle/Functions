CXX=g++-8
GCC_LOC = $(shell which gcc)
CXXINCLUDE=-I/usr/local/include
CXXLIBS=-L/usr/local/lib/gtest
CXXFLAGS=-Wall --pedantic-errors -std=c++17 -DGCC_LOC=\"$(GCC_LOC)\" #$(CXXINCLUDE) $(CXXLIBS)

TARGET=bin/main
SRCS=src/*

$(TARGET): $(SRCS)
	@echo "Compiling"
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)
	chmod +x $(TARGET)
	@echo ""

test:
	@echo "Test 1:"
	./bin/main -f tests/main_1.func -o tests/main_1
	./tests/main_1
	@echo "\n"
	@echo "Test 2:"
	./bin/main -f tests/main_2.func -o tests/main_2
	./tests/main_2
	@echo "\n"
	@echo "Test 3:"
	./bin/main -f tests/main_3.func -o tests/main_3
	./tests/main_3
	@echo "\n"
	@echo "Test 4:"
	./bin/main -f tests/main_4.func -o tests/main_4
	./tests/main_4
	@echo "\n"

clean:
	rm -rf $(TARGET)

.PHONY: $(TARGET)