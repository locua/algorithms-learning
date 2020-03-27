include ../../cpp.mk

BinarySearchTest: BinarySearch.o BinarySearchSearchTest.o ../../00/cpp/RunTests.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

test: BinarySearchTest
	./BinarySearchTest

.PHONY: test
