include ../../cpp.mk

RNGTest: LCG.o Xorshift.o LCG2935256Test.o Xorshift3520Test.o ../../00/cpp/RunTests.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

LCG.o LCG2935256Test.o: LCG.hpp
Xorshift.o Xorshift3520Test.o: Xorshift.hpp

test: RNGTest
	./RNGTest

.PHONY: test
