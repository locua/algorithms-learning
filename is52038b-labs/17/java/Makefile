include ../../java.mk

TESTCLASSFILES = BigIntBasicsTest.class BigIntAddTest.class BigIntSubTest.class BigIntShiftTest.class BigIntMulByDigitTest.class BigIntMulTest.class
CLASSFILES = BigInt.class $(TESTCLASSFILES)

all: $(CLASSFILES)

clean:
	-rm -f $(CLASSFILES)

test: all
	(((($(JAVA) $(CP) $(CLASSPATH) org.junit.runner.JUnitCore $(subst .class,,$(TESTCLASSFILES)); echo $$? >&3) | egrep -v \(org.junit\|sun.reflect\|java.lang.reflect\) >&4) 3>&1) | (read xs; exit $$xs)) 4>&1

.PHONY: test all clean
