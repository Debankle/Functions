CXX=g++-8
COMPILE_FLAGS := -DGCC=\"$(shell which gcc)\"
CXXFLAGS := -Wall -O2 --pedantic-errors -std=c++17

TARGET=bin/func
SRCS=src/*.cpp
TEST=tests/Test.cpp

.PHONY: make install test clean

make: $(SRCS)
	@echo "Compiling"
	$(CXX) $(COMPILE_FLAGS) -o $(TARGET) $(SRCS)
	chmod +x $(TARGET)
	@echo ""

install: $(TARGET)
	@echo "Installing Functions to /usr/local/bin"
	cp $(TARGET) /usr/local/bin

concept: src/concept.c
	gcc -o src/$@ $^
	./src/$@

test: $(TEST)
	$(CXX) $(TEST) -o tests/Test
	./tests/Test

clean:
	rm -rf $(TARGET)
	find tests/ -not -name "*.func" -type f | xargs rm -rf
