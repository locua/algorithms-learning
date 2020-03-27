include ../../cpp.mk

LDLIBS += -lm

DynamicArrayTest: DynamicArray.o DynamicArrayTest.o ../../00/cpp/OpCounter.o

DynamicArrayCounter: DynamicArray.o DynamicArrayCounter.o ../../00/cpp/OpCounter.o

test: DynamicArrayTest
	./DynamicArrayTest

count: DynamicArrayCounter
	./DynamicArrayCounter

.PHONY: test count
