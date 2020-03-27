include ../../cpp.mk

SLListTest: CPPFLAGS += -I ../../04/cpp
SLListTest: ../../04/cpp/SLList.o ../../00/cpp/RunTests.o SublistTest.o MergeTest.o MergesortTest.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

test: SLListTest
	./SLListTest

all: SLListTest

StackQueue: CPPFLAGS += -I ../../04/cpp
StackQueue: ../../04/cpp/SLList.o Stack.o Queue.o StackQueue.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

sq: StackQueue
	./StackQueue

.PHONY: test all
