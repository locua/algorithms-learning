include ../../java.mk

TESTCLASSFILES = HeapIndexFunctionsTest.class HeapConstructorsTest.class HeapInsertTest.class HeapMaximumTest.class
CLASSFILES = Heap.class $(TESTCLASSFILES)

CLASSPATHS += ../../00/java

all: $(CLASSFILES)

clean:
	-rm -f $(CLASSFILES) test.xml
test: all
	(((($(JAVA) $(CP) $(CLASSPATH) org.junit.runner.JUnitCore $(subst .class,,$(TESTCLASSFILES)); echo $$? >&3) | egrep -v \(org.junit\|sun.reflect\|java.lang.reflect\) >&4) 3>&1) | (read xs; exit $$xs)) 4>&1

.PHONY: test all clean
