include ../../cpp.mk

BigIntTest: BigInt.o BigIntBasicsTest.o BigIntAddTest.o BigIntSubTest.o BigIntShiftTest.o BigIntMulByDigitTest.o BigIntMulTest.o ../../00/cpp/RunTests.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

test: BigIntTest
	./BigIntTest

.PHONY: test
