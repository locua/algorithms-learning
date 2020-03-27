include ../../cpp.mk

SLListTest: SLList.o BasicSLListTest.o ExtendedSLListTest.o ../../00/cpp/RunTests.o
	$(CC) -o $@ $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS)

test: SLListTest
	./SLListTest

.PHONY: test all
