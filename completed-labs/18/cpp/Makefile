include ../../cpp.mk

TrieTest: Trie.o TrieInsertTest.o TrieQueryTest.o CompressedTrie.o CompressTrieTest.o CompressedTrieQueryTest.o ../../00/cpp/RunTests.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

test: TrieTest
	./TrieTest

.PHONY: test
