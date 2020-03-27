include ../../java.mk

TESTCLASSFILES = SetupTest.class
CLASSFILES = $(TESTCLASSFILES)

all: $(CLASSFILES)

test: all
	@echo "Running test of JUnit4"
	@(((($(JAVA) $(CP) $(CLASSPATH) org.junit.runner.JUnitCore $(subst .class,,$(TESTCLASSFILES)); echo $$? >&3) | egrep -v \(org.junit\|sun.reflect\|java.lang.reflect\) >&4) 3>&1) | (read xs; exit $$xs)) 4>&1
	@echo "Tests passed: Java setup apparently OK"

clean:
	-rm *.class

.PHONY: test clean all
