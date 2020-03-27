include ../../java.mk

TESTCLASSFILES = SublistTest.class MergeTest.class MergesortTest.class
CLASSFILES = ../../04/java/SLList.class $(TESTCLASSFILES)

CLASSPATHS += ../../04/java

all: $(CLASSFILES)

test: all
	(((($(JAVA) $(CP) $(CLASSPATH) org.junit.runner.JUnitCore $(subst .class,,$(TESTCLASSFILES)); echo $$? >&3) | egrep -v \(org.junit\|sun.reflect\|java.lang.reflect\) >&4) 3>&1) | (read xs; exit $$xs)) 4>&1

clean:
	-rm -f $(TESTCLASSFILES) test.xml

sq: Stack.class Queue.class StackQueue.class
	$(JAVA) $(CP) $(CLASSPATH) StackQueue

.PHONY: test all clean
