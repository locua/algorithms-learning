include ../../cpp.mk

SLListTest: CPPFLAGS += -I ../../04/cpp
SLListTest: ../../04/cpp/SLList.o ../../00/cpp/RunTests.o LengthSLListTest.o RemoveSLListTest.o ReverseSLListTest.o 
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

test: SLListTest
	./SLListTest

all: SLListTest

.PHONY: test all
