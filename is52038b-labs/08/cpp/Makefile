include ../../cpp.mk

HashTableTest: ../../00/cpp/RunTests.o HashTable.o HashTableInsertTest.o HashTableFindTest.o HashTableLoadFactorTest.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

test: HashTableTest
	./HashTableTest

.PHONY: test
