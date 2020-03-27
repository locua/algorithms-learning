include ../../java.mk

TESTCLASSFILES = DynamicArrayTest.class
CLASSFILES = DynamicArray.class ../../00/java/OpCounter.class DynamicArrayCounter.class $(TESTCLASSFILES)

all: $(CLASSFILES)

test: all
	(((($(JAVA) -Xss10m $(CP) $(CLASSPATH) org.junit.runner.JUnitCore $(subst .class,,$(notdir $(TESTCLASSFILES))); echo $$? >&3) | egrep -v \(org.junit\|sun.reflect\|java.lang.reflect\) >&4) 3>&1) | (read xs; exit $$xs)) 4>&1

count: all
	$(JAVA) $(CP) $(CLASSPATH) DynamicArrayCounter

clean:
	-rm *.class

.PHONY: test all clean
